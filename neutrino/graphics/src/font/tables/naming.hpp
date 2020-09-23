////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Naming table
/// @author Fedorov Alexey
/// @date 22.09.2020
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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_NAMING_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_NAMING_HPP

#include <graphics/src/font/types.hpp>
#include <vector>

namespace framework::graphics::details::font
{

struct Naming
{
    // Some name id's
    enum class NameId : std::uint16_t
    {
        Copyright         = 0,
        FontFamilyName    = 1,
        FontSubfamilyName = 2,
        FullFontName      = 4,
        VersionString     = 5,

        Undefined = 0xFFFF,
    };

    struct NameRecord
    {
        PlatformId platform_id    = PlatformId::Undefined;
        std::uint16_t encoding_id = 0;
        std::uint16_t language_id = 0;
        NameId name_id            = NameId::Undefined;
        std::uint16_t length      = 0;
        Offset16 offset           = 0;
    };

    struct LangTagRecord
    {
        std::uint16_t length = 0;
        Offset16 offset      = 0;
    };

    using NamesMap = std::unordered_map<NameId, std::string>;

    static Naming parse(const std::vector<std::uint8_t>& data);

    bool valid() const;
    std::string get_string(NameId name_id) const;

    std::uint16_t format   = 0;
    std::uint16_t count    = 0;
    Offset16 string_offset = 0;
    std::vector<NameRecord> name_records;

    // for format 1 only
    std::uint16_t lang_tag_count = 0;
    std::vector<LangTagRecord> lang_tag_records;

private:
    static std::string read_string(Naming table, NameId name_id, const std::vector<std::uint8_t>& data);

    NamesMap m_strings;
};

}

#endif

