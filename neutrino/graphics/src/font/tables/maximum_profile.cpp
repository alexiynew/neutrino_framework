////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Maximum profile table
/// @author Fedorov Alexey
/// @date 18.09.2020
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

#include <common/utils.hpp>

#include <graphics/src/font/tables/maximum_profile.hpp>

namespace framework::graphics::details::font
{

MaximumProfile MaximumProfile::parse(const std::vector<std::uint8_t>& data)
{
    MaximumProfile table;

    table.version    = utils::big_endian_value<Fixed>(data.begin(), data.end());
    table.num_glyphs = utils::big_endian_value<std::uint16_t>(data.begin() + 4, data.end());

    if (table.version == 0x00010000) {
        table.max_points               = utils::big_endian_value<std::uint16_t>(data.begin() + 6, data.end());
        table.max_contours             = utils::big_endian_value<std::uint16_t>(data.begin() + 8, data.end());
        table.max_composite_points     = utils::big_endian_value<std::uint16_t>(data.begin() + 10, data.end());
        table.max_composite_contours   = utils::big_endian_value<std::uint16_t>(data.begin() + 12, data.end());
        table.max_zones                = utils::big_endian_value<std::uint16_t>(data.begin() + 14, data.end());
        table.max_twilight_points      = utils::big_endian_value<std::uint16_t>(data.begin() + 16, data.end());
        table.max_storage              = utils::big_endian_value<std::uint16_t>(data.begin() + 18, data.end());
        table.max_function_defs        = utils::big_endian_value<std::uint16_t>(data.begin() + 20, data.end());
        table.max_instruction_defs     = utils::big_endian_value<std::uint16_t>(data.begin() + 22, data.end());
        table.max_stack_elements       = utils::big_endian_value<std::uint16_t>(data.begin() + 24, data.end());
        table.max_size_of_instructions = utils::big_endian_value<std::uint16_t>(data.begin() + 26, data.end());
        table.max_component_elements   = utils::big_endian_value<std::uint16_t>(data.begin() + 28, data.end());
        table.max_component_depth      = utils::big_endian_value<std::uint16_t>(data.begin() + 30, data.end());
    }

    return table;
}

bool MaximumProfile::valid() const
{
    bool valid = true;

    valid &= version == 0x00010000 || version == 0x00005000;
    valid &= num_glyphs != 0;

    return valid;
}

} // namespace framework::graphics::details::font
