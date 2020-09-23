////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Font header table
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

#include <common/utils.hpp>

#include <graphics/src/font/tables/font_header.hpp>

namespace framework::graphics::details::font
{

FontHeader FontHeader::parse(const std::vector<std::uint8_t>& data)
{
    FontHeader table;
    table.major_version        = utils::big_endian_value<std::uint16_t>(data.begin() + 0, data.end());
    table.minor_version        = utils::big_endian_value<std::uint16_t>(data.begin() + 2, data.end());
    table.font_revision        = utils::big_endian_value<Fixed>(data.begin() + 4, data.end());
    table.check_sum_adjustment = utils::big_endian_value<std::uint32_t>(data.begin() + 8, data.end());
    table.magic_number         = utils::big_endian_value<std::uint32_t>(data.begin() + 12, data.end());
    table.flags                = utils::big_endian_value<std::uint16_t>(data.begin() + 16, data.end());
    table.units_per_em         = utils::big_endian_value<std::uint16_t>(data.begin() + 18, data.end());
    table.created              = utils::big_endian_value<DateTime>(data.begin() + 20, data.end());
    table.modified             = utils::big_endian_value<DateTime>(data.begin() + 28, data.end());
    table.x_min                = utils::big_endian_value<std::int16_t>(data.begin() + 36, data.end());
    table.y_min                = utils::big_endian_value<std::int16_t>(data.begin() + 38, data.end());
    table.x_max                = utils::big_endian_value<std::int16_t>(data.begin() + 40, data.end());
    table.y_max                = utils::big_endian_value<std::int16_t>(data.begin() + 42, data.end());
    table.mac_style            = utils::big_endian_value<std::uint16_t>(data.begin() + 44, data.end());
    table.lowest_rec_ppem      = utils::big_endian_value<std::uint16_t>(data.begin() + 46, data.end());
    table.font_direction_hint  = utils::big_endian_value<std::int16_t>(data.begin() + 48, data.end());
    table.index_to_loc_format  = utils::big_endian_value<std::int16_t>(data.begin() + 50, data.end());
    table.glyph_data_format    = utils::big_endian_value<std::int16_t>(data.begin() + 52, data.end());

    return table;
}

bool FontHeader::valid() const
{
    bool valid = true;

    valid &= major_version == 1;
    valid &= minor_version == 0;
    valid &= magic_number == 0X5F0F3CF5;
    valid &= (units_per_em >= 16 && units_per_em <= 16364);
    valid &= x_min < x_max;
    valid &= y_min < y_max;
    valid &= index_to_loc_format == 0 || index_to_loc_format == 1;
    valid &= glyph_data_format == 0;

    return valid;
}

} // namespace framework::graphics::details::font
