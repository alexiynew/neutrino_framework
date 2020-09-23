////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Character to glyph index mapping table
/// @author Fedorov Alexey
/// @date 18.09.2020
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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_GLYPH_MAP_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_GLYPH_MAP_HPP

#include <graphics/src/font/types.hpp>
#include <vector>

namespace framework::graphics::details::font
{

struct GlyphMap
{
    using GlyphIndexMap = std::unordered_map<std::string, std::uint32_t>;

    struct EncodingRecord
    {
        PlatformId platform_id    = PlatformId::Undefined;
        std::uint16_t encoding_id = 0;
        std::uint32_t offset      = 0; // Byte offset from beginning of table to the subtable for this encoding.
    };

    static GlyphMap parse(const std::vector<std::uint8_t>& data);

    std::uint16_t version    = 0;
    std::uint16_t num_tables = 0;
    std::vector<EncodingRecord> encoding_records;

    GlyphIndexMap glyphs;
};

}

#endif

