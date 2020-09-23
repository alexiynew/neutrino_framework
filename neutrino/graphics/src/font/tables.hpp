////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Font tables
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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HPP

#include <cstdint>
#include <fstream>
#include <string>
#include <unordered_map>

#include <graphics/src/font/tags.hpp>

namespace framework::graphics::details::font
{

#pragma region Font Tables







struct Os2Table
{
    static Os2Table parse(const std::vector<std::uint8_t>& data);

    std::uint16_t version             = 0;
    std::int16_t avg_char_width       = 0;
    std::uint16_t weight_class        = 0;
    std::uint16_t width_class         = 0;
    std::uint16_t type                = 0;
    std::int16_t subscript_x_size     = 0;
    std::int16_t subscript_y_size     = 0;
    std::int16_t subscript_x_offset   = 0;
    std::int16_t subscript_y_offset   = 0;
    std::int16_t superscript_x_size   = 0;
    std::int16_t superscript_y_size   = 0;
    std::int16_t superscript_x_offset = 0;
    std::int16_t superscript_y_offset = 0;
    std::int16_t strikeout_size       = 0;
    std::int16_t strikeout_position   = 0;
    std::int16_t family_class         = 0;
    std::array<std::uint8_t, 10> panose;
    std::uint32_t unicode_range1   = 0; // Bits 0–31
    std::uint32_t unicode_range2   = 0; // Bits 32–63
    std::uint32_t unicode_range3   = 0; // Bits 64–95
    std::uint32_t unicode_range4   = 0; // Bits 96–127
    Tag ach_vend_id                = Tag::invalid;
    std::uint16_t selection        = 0;
    std::uint16_t first_char_index = 0;
    std::uint16_t last_char_index  = 0;
    std::int16_t typo_ascender     = 0;
    std::int16_t typo_descender    = 0;
    std::int16_t typo_linegap      = 0;
    std::uint16_t win_ascent       = 0;
    std::uint16_t win_descent      = 0;

    // for version 1
    std::uint32_t code_page_range1 = 0;
    std::uint32_t code_page_range2 = 0;

    // for version 2, 3, 4
    std::int16_t height        = 0;
    std::int16_t capheight     = 0;
    std::uint16_t default_char = 0;
    std::uint16_t break_char   = 0;
    std::uint16_t max_context  = 0;

    // for version 5 only
    std::uint16_t lower_optical_point_size = 0;
    std::uint16_t upper_optical_point_size = 0;
};

#pragma endregion

#pragma region Helper Functions

std::vector<TableRecord> read_table_records(std::ifstream& in, std::uint32_t num_tables);

bool has_required_tables(const std::vector<TableRecord>& records);

#pragma endregion

} // namespace framework::graphics::details::font

#endif
