////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Os2 table
/// @author Fedorov Alexey
/// @date 24.09.2020
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

#include <common/utils.hpp>

#include <graphics/src/font/tables/os2.hpp>

namespace framework::graphics::details::font
{

Os2 Os2::parse(const std::vector<std::uint8_t>& data)
{
    Os2 table;

    table.version              = utils::big_endian_value<std::uint16_t>(data.begin() + 0, data.end());
    table.avg_char_width       = utils::big_endian_value<std::int16_t>(data.begin() + 2, data.end());
    table.weight_class         = utils::big_endian_value<std::uint16_t>(data.begin() + 4, data.end());
    table.width_class          = utils::big_endian_value<std::uint16_t>(data.begin() + 6, data.end());
    table.type                 = utils::big_endian_value<std::uint16_t>(data.begin() + 8, data.end());
    table.subscript_x_size     = utils::big_endian_value<std::int16_t>(data.begin() + 10, data.end());
    table.subscript_y_size     = utils::big_endian_value<std::int16_t>(data.begin() + 12, data.end());
    table.subscript_x_offset   = utils::big_endian_value<std::int16_t>(data.begin() + 14, data.end());
    table.subscript_y_offset   = utils::big_endian_value<std::int16_t>(data.begin() + 16, data.end());
    table.superscript_x_size   = utils::big_endian_value<std::int16_t>(data.begin() + 18, data.end());
    table.superscript_y_size   = utils::big_endian_value<std::int16_t>(data.begin() + 20, data.end());
    table.superscript_x_offset = utils::big_endian_value<std::int16_t>(data.begin() + 22, data.end());
    table.superscript_y_offset = utils::big_endian_value<std::int16_t>(data.begin() + 24, data.end());
    table.strikeout_size       = utils::big_endian_value<std::int16_t>(data.begin() + 26, data.end());
    table.strikeout_position   = utils::big_endian_value<std::int16_t>(data.begin() + 28, data.end());
    table.family_class         = utils::big_endian_value<std::int16_t>(data.begin() + 30, data.end());

    std::reverse_copy(data.begin() + 32, data.begin() + 42, table.panose.begin());

    table.unicode_range1   = utils::big_endian_value<std::uint32_t>(data.begin() + 42, data.end());
    table.unicode_range2   = utils::big_endian_value<std::uint32_t>(data.begin() + 46, data.end());
    table.unicode_range3   = utils::big_endian_value<std::uint32_t>(data.begin() + 50, data.end());
    table.unicode_range4   = utils::big_endian_value<std::uint32_t>(data.begin() + 54, data.end());
    table.ach_vend_id      = utils::big_endian_value<Tag>(data.begin() + 58, data.end());
    table.selection        = utils::big_endian_value<std::uint16_t>(data.begin() + 62, data.end());
    table.first_char_index = utils::big_endian_value<std::uint16_t>(data.begin() + 64, data.end());
    table.last_char_index  = utils::big_endian_value<std::uint16_t>(data.begin() + 66, data.end());
    table.typo_ascender    = utils::big_endian_value<std::int16_t>(data.begin() + 68, data.end());
    table.typo_descender   = utils::big_endian_value<std::int16_t>(data.begin() + 70, data.end());
    table.typo_linegap     = utils::big_endian_value<std::int16_t>(data.begin() + 72, data.end());
    table.win_ascent       = utils::big_endian_value<std::uint16_t>(data.begin() + 74, data.end());
    table.win_descent      = utils::big_endian_value<std::uint16_t>(data.begin() + 76, data.end());

    if (table.version >= 1) {
        table.code_page_range1 = utils::big_endian_value<std::uint32_t>(data.begin() + 78, data.end());
        table.code_page_range2 = utils::big_endian_value<std::uint32_t>(data.begin() + 82, data.end());
    }

    if (table.version >= 2) {
        table.height       = utils::big_endian_value<std::int16_t>(data.begin() + 86, data.end());
        table.capheight    = utils::big_endian_value<std::int16_t>(data.begin() + 88, data.end());
        table.default_char = utils::big_endian_value<std::uint16_t>(data.begin() + 90, data.end());
        table.break_char   = utils::big_endian_value<std::uint16_t>(data.begin() + 92, data.end());
        table.max_context  = utils::big_endian_value<std::uint16_t>(data.begin() + 94, data.end());
    }

    if (table.version == 5) {
        table.lower_optical_point_size = utils::big_endian_value<std::uint16_t>(data.begin() + 96, data.end());
        table.upper_optical_point_size = utils::big_endian_value<std::uint16_t>(data.begin() + 98, data.end());
    }

    return table;
}

bool Os2::valid() const
{
    bool valid = true;

    valid &= version <= 5;
    valid &= weight_class >= 1 && weight_class <= 1000;
    valid &= width_class >= 1 && width_class <= 9;

    return valid;
}

} // namespace framework::graphics::details::font
