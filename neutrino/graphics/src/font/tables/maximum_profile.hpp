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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_MAXIMUM_PROFILE_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_MAXIMUM_PROFILE_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct MaximumProfile
{
    static MaximumProfile parse(const std::vector<std::uint8_t>& data);

    bool valid() const;

    Fixed version            = 0;
    std::uint16_t num_glyphs = 0;

    // for version 1.0 only
    std::uint16_t max_points               = 0;
    std::uint16_t max_contours             = 0;
    std::uint16_t max_composite_points     = 0;
    std::uint16_t max_composite_contours   = 0;
    std::uint16_t max_zones                = 0;
    std::uint16_t max_twilight_points      = 0;
    std::uint16_t max_storage              = 0;
    std::uint16_t max_function_defs        = 0;
    std::uint16_t max_instruction_defs     = 0;
    std::uint16_t max_stack_elements       = 0;
    std::uint16_t max_size_of_instructions = 0;
    std::uint16_t max_component_elements   = 0;
    std::uint16_t max_component_depth      = 0;
};

} // namespace framework::graphics::details::font

#endif
