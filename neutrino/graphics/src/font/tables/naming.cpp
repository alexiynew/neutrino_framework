////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Naming table
/// @author Fedorov Alexey
/// @date 22.09.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <common/utf.hpp>
#include <common/utils.hpp>

#include <graphics/src/font/tables/naming.hpp>

namespace framework::graphics::details::font
{

Naming Naming::parse(const std::vector<std::uint8_t>& data)
{
    Naming table;

    table.format        = utils::big_endian_value<std::uint16_t>(data.begin(), data.end());
    table.count         = utils::big_endian_value<std::uint16_t>(data.begin() + 2, data.end());
    table.string_offset = utils::big_endian_value<Offset16>(data.begin() + 4, data.end());

    auto from = std::next(data.begin(), 6);

    table.name_records.reserve(table.count);

    for (size_t i = 0; i < table.count; ++i) {

        NameRecord record;

        record.platform_id = utils::big_endian_value<PlatformId>(from, data.end());
        record.encoding_id = utils::big_endian_value<std::uint16_t>(from + 2, data.end());
        record.language_id = utils::big_endian_value<std::uint16_t>(from + 4, data.end());
        record.name_id     = utils::big_endian_value<NameId>(from + 6, data.end());
        record.length      = utils::big_endian_value<std::uint16_t>(from + 8, data.end());
        record.offset      = utils::big_endian_value<Offset16>(from + 10, data.end());

        table.name_records.push_back(std::move(record));
        std::advance(from, 12);
    }

    if (table.format == 1) {
        table.lang_tag_count = utils::big_endian_value<std::uint16_t>(from, data.end());
        std::advance(from, 2);

        table.lang_tag_records.reserve(table.lang_tag_count);
        for (size_t i = 0; i < table.lang_tag_count; ++i) {

            LangTagRecord record;
            record.length = utils::big_endian_value<std::uint16_t>(from, data.end());
            record.offset = utils::big_endian_value<Offset16>(from + 2, data.end());

            table.lang_tag_records.push_back(std::move(record));
            std::advance(from, 4);
        }
    }

    for (auto name : {NameId::Copyright,
                      NameId::FontFamilyName,
                      NameId::FontSubfamilyName,
                      NameId::FullFontName,
                      NameId::VersionString}) {
        table.m_strings[name] = read_string(table, name, data);
    }

    return table;
}

bool Naming::valid() const
{
    bool valid = true;

    valid &= format == 0 || format == 1;

    return valid;
}

std::string Naming::get_string(NameId name_id) const
{
    if (m_strings.count(name_id)) {
        return m_strings.at(name_id);
    }

    return "";
}

std::string Naming::read_string(Naming table, Naming::NameId name_id, const std::vector<std::uint8_t>& data)
{
    auto unicode_platform = [name_id](const NameRecord& record) {
        constexpr std::uint16_t unicode_engiding_id = 3;

        return record.name_id == name_id && record.platform_id == PlatformId::Unicode &&
               record.encoding_id == unicode_engiding_id;
    };

    auto windows_platform = [name_id](const NameRecord& record) {
        constexpr std::uint16_t windows_engiding_id = 1;
        
        return record.name_id == name_id && record.platform_id == PlatformId::Windows &&
               record.encoding_id == windows_engiding_id;
    };

    auto it = std::find_if(table.name_records.begin(), table.name_records.end(), unicode_platform);

    if (it == table.name_records.end()) {
        it = std::find_if(table.name_records.begin(), table.name_records.end(), windows_platform);
    }

    if (it == table.name_records.end()) {
        return std::string();
    }

    const size_t offset = static_cast<size_t>(table.string_offset) + it->offset;
    if (data.size() < offset + it->length) {
        return std::string();
    }

    const size_t length = it->length / sizeof(char16_t);

    auto from      = data.begin() + static_cast<std::ptrdiff_t>(offset);
    const auto end = std::next(data.begin(), static_cast<std::ptrdiff_t>(offset + it->length));

    std::u16string str(length, '\0');
    for (size_t i = 0; i < length; i++) {
        str[i] = utils::big_endian_value<char16_t>(from, end);
        std::advance(from, sizeof(char16_t));
    }

    return utf::to_utf8(str);
}

} // namespace framework::graphics::details::font
