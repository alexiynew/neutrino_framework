////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Font.
/// @author Fedorov Alexey
/// @date 04.09.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <common/utils.hpp>
#include <graphics/font.hpp>

#include <graphics/src/font/tables/font_header.hpp>
#include <graphics/src/font/tables/glyph_map.hpp>
#include <graphics/src/font/tables/horizontal_header.hpp>
#include <graphics/src/font/tables/horizontal_metrics.hpp>
#include <graphics/src/font/tables/location.hpp>
#include <graphics/src/font/tables/maximum_profile.hpp>
#include <graphics/src/font/tables/naming.hpp>
#include <graphics/src/font/tables/os2.hpp>

using namespace framework;
using namespace framework::graphics::details::font;

namespace
{

#pragma region OffsetTable

struct OffsetTable
{
    inline static constexpr std::uint32_t true_type_tag = 0x00010000;
    inline static constexpr std::uint32_t open_type_tag = make_tag('O', 'T', 'T', 'O');

    static OffsetTable read(std::istream& in);

    bool valid() const;

    std::uint32_t sfnt_version   = 0;
    std::uint16_t num_tables     = 0;
    std::uint16_t search_range   = 0;
    std::uint16_t entry_selector = 0;
    std::uint16_t range_shift    = 0;
};

OffsetTable OffsetTable::read(std::istream& in)
{
    constexpr size_t size = 12;

    std::array<char, size> buffer = {0};
    in.read(buffer.data(), size);

    OffsetTable table;
    table.sfnt_version   = utils::big_endian_value<std::uint32_t>(buffer.begin(), buffer.end());
    table.num_tables     = utils::big_endian_value<std::uint16_t>(buffer.begin() + 4, buffer.end());
    table.search_range   = utils::big_endian_value<std::uint16_t>(buffer.begin() + 6, buffer.end());
    table.entry_selector = utils::big_endian_value<std::uint16_t>(buffer.begin() + 8, buffer.end());
    table.range_shift    = utils::big_endian_value<std::uint16_t>(buffer.begin() + 10, buffer.end());

    return table;
}

int max_power_of_2(int n)
{
    int max_pow2 = 0;

    while (n != 0) {
        n = n >> 1;
        max_pow2++;
    }

    return std::max(max_pow2 - 1, 0);
}

bool OffsetTable::valid() const
{
    const int max_pow2 = max_power_of_2(num_tables);

    const int check_search_range   = static_cast<int>(std::pow(2, max_pow2) * 16);
    const int check_entry_selector = max_pow2;
    const int check_range_shift    = std::max(0, num_tables * 16 - search_range);

    const bool is_valid_version    = (sfnt_version == OffsetTable::true_type_tag ||
                                   sfnt_version == OffsetTable::open_type_tag);
    const bool is_valid_num_tables = num_tables > 0 && num_tables <= 4096;

    return is_valid_version && is_valid_num_tables && search_range == check_search_range &&
           entry_selector == check_entry_selector && range_shift == check_range_shift;
}

#pragma endregion

#pragma region TableRecord

struct TableRecord
{
    static TableRecord read(std::istream& in);

    bool valid() const;

    Tag tag                 = Tag::Invalid;
    std::uint32_t check_sum = 0;
    std::uint32_t offset    = 0;
    std::uint32_t length    = 0;
};

TableRecord TableRecord::read(std::istream& in)
{
    constexpr size_t size = 16;

    std::array<char, size> buffer = {0};
    in.read(buffer.data(), size);

    TableRecord table;
    table.tag       = utils::big_endian_value<Tag>(buffer.begin(), buffer.end());
    table.check_sum = utils::big_endian_value<std::uint32_t>(buffer.begin() + 4, buffer.end());
    table.offset    = utils::big_endian_value<std::uint32_t>(buffer.begin() + 8, buffer.end());
    table.length    = utils::big_endian_value<std::uint32_t>(buffer.begin() + 12, buffer.end());

    return table;
}

bool is_ascii_tag(Tag tag)
{
    std::uint32_t value = static_cast<std::uint32_t>(tag);
    for (size_t i = 0; i < sizeof(Tag); ++i) {
        const std::uint8_t b = value & 0xff;
        if (b < 32 || b > 126) {
            return false;
        }
        value >>= 8;
    }

    return true;
}

bool TableRecord::valid() const
{
    const bool is_valid_tag    = is_ascii_tag(tag);
    const bool is_valid_offset = (offset & 3) == 0;                           // tables must be 4-byte aligned
    const bool is_valid_length = (length > 0) && (length < 30 * 1024 * 1024); // 0 < length < 30MB

    return is_valid_tag && is_valid_offset && is_valid_length;
}

#pragma endregion

#pragma region Table

struct Table
{
    bool read_data(std::ifstream& in);
    bool valid() const;

    TableRecord record;
    std::vector<std::uint8_t> data;
};

bool Table::read_data(std::ifstream& in)
{
    in.seekg(record.offset, in.beg);

    data.resize(record.length);
    in.read(reinterpret_cast<char*>(data.data()), record.length);

    return in.good();
}

std::uint32_t table_checksum(const std::vector<std::uint8_t>& data)
{
    std::uint32_t sum = 0;

    const size_t count = ((data.size() + 3) / 4) * 4;
    for (size_t i = 0; i < count; i += 4) {
        std::uint32_t value = 0;
        value += static_cast<std::uint32_t>((i + 0 < data.size() ? data[i + 0] : 0) << 24);
        value += static_cast<std::uint32_t>((i + 1 < data.size() ? data[i + 1] : 0) << 16);
        value += static_cast<std::uint32_t>((i + 2 < data.size() ? data[i + 2] : 0) << 8);
        value += static_cast<std::uint32_t>((i + 3 < data.size() ? data[i + 3] : 0) << 0);

        sum += value;
    }

    return sum;
}

bool Table::valid() const
{
    auto get_check_sum = [this](const auto& container) {
        std::uint32_t data_check_sum = table_checksum(data);

        if (record.tag == Tag::Head) {
            data_check_sum -= utils::big_endian_value<std::uint32_t>(container.data() + 8, container.data() + 12);
        }

        return data_check_sum;
    };

    const std::uint32_t data_check_sum = get_check_sum(data);
    return data_check_sum == record.check_sum;
}

#pragma endregion

#pragma region Helper Functions

std::vector<TableRecord> read_table_records(std::ifstream& in, std::uint32_t num_tables)
{
    std::vector<TableRecord> records;
    records.reserve(num_tables);

    for (std::uint32_t i = 0; i < num_tables; i++) {
        records.push_back(TableRecord::read(in));
        if (!in) {
            return std::vector<TableRecord>();
        }
    }

    std::sort(records.begin(), records.end(), [](const TableRecord& a, const TableRecord& b) {
        return a.offset < b.offset;
    });

    return records;
}

bool has_required_tables(const std::vector<TableRecord>& records)
{
    constexpr std::array<Tag, 8> common_required_tags =
    {Tag::Cmap, Tag::Head, Tag::Hhea, Tag::Hmtx, Tag::Maxp, Tag::Name, Tag::Os2, Tag::Post};

    for (const Tag tag : common_required_tags) {
        const auto it = std::find_if(records.begin(), records.end(), [tag](const TableRecord& record) {
            return record.tag == tag;
        });

        if (it == records.end()) {
            return false;
        }
    }

    return true;
}

#pragma endregion

} // namespace

namespace framework::graphics
{

Font::Font()
{}

Font::Font(const Font&) = default;
Font& Font::operator=(const Font&) = default;

Font::Font(Font&&) noexcept = default;
Font& Font::operator=(Font&&) noexcept = default;

bool Font::load(const std::string& filename)
{
    try {
        return parse(filename);
    } catch (std::exception&) {
        return false;
    }
}

bool Font::parse(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return false;
    }

    OffsetTable offset_table = OffsetTable::read(file);
    if (!file || !offset_table.valid()) {
        return false;
    }

    std::vector<TableRecord> records = read_table_records(file, offset_table.num_tables);

    const bool records_valid = std::all_of(records.begin(), records.end(), [](const TableRecord& record) {
        return record.valid();
    });

    const bool has_tables = has_required_tables(records);
    if (!file || !records_valid || records.size() != offset_table.num_tables || !has_tables) {
        return false;
    }

    std::unordered_map<Tag, Table> tables;

    std::transform(records.begin(), records.end(), std::inserter(tables, tables.end()), [](const TableRecord& record) {
        return std::pair{record.tag, Table{record, {}}};
    });

    for (auto& table : tables) {
        if (!table.second.read_data(file)) {
            return false;
        }

        if (!table.second.valid()) {
            return false;
        }
    }

    if (offset_table.sfnt_version == OffsetTable::true_type_tag) {
        if (!(tables.count(Tag::Glyf) && tables.count(Tag::Loca))) {
            return false;
        }
    }

    if (offset_table.sfnt_version == OffsetTable::open_type_tag) {
        if (!(tables.count(Tag::Cff) || tables.count(Tag::Cff2))) {
            return false;
        }
    }

    FontHeader head = FontHeader::parse(tables.at(Tag::Head).data);
    if (!head.valid()) {
        return false;
    }

    GlyphMap cmap = GlyphMap::parse(tables.at(Tag::Cmap).data);
    if (!cmap.valid()) {
        return false;
    }

    HorizontalHeader hhea = HorizontalHeader::parse(tables.at(Tag::Hhea).data);
    if (!hhea.valid()) {
        return false;
    }

    MaximumProfile maxp = MaximumProfile::parse(tables.at(Tag::Maxp).data);
    if (!maxp.valid()) {
        return false;
    }

    HorizontalMetrics hmtx = HorizontalMetrics::parse(hhea.number_of_h_metrics,
                                                      maxp.num_glyphs,
                                                      tables.at(Tag::Hmtx).data);
    if (!hmtx.valid()) {
        return false;
    }

    Naming name = Naming::parse(tables.at(Tag::Name).data);
    if (!name.valid()) {
        return false;
    }

    Os2 os2 = Os2::parse(tables.at(Tag::Os2).data);
    if (!os2.valid()) {
        return false;
    }

    if (offset_table.sfnt_version == OffsetTable::true_type_tag) {
        Location loca = Location::parse(head.index_to_loc_format, maxp.num_glyphs, tables.at(Tag::Loca).data);

        return true;
    }

    return true;
}

} // namespace framework::graphics
