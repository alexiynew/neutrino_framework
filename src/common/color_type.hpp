/// @file
/// @brief Definition color type.
/// @author Fedorov Alexey
/// @date 26.04.2019

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

#ifndef FRAMEWORK_COMMON_COLOR_TYPE_HPP
#define FRAMEWORK_COMMON_COLOR_TYPE_HPP

#include <common/types.hpp>

namespace framework
{
/// @details
/// Color type definition.
///
/// @addtogroup common_types_module Common types
/// @{

struct color_t 
{
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;

    static constexpr uint16 red_565 = 0xF800;
    static constexpr uint16 green_565 = 0x7E0;
    static constexpr uint16 blue_565 = 0x1F;

    static constexpr uint32 red_rgba8 = 0xFF000000;
    static constexpr uint32 green_rgba8 = 0xFF0000;
    static constexpr uint32 blue_rgba8 = 0xFF00;
    static constexpr uint32 alpha_rgba8 = 0xFF;

    color_t(uint8 r, uint8 g, uint8 b, uint8 a);
    color_t(float32 r, float32 g, float32 b, float32 a);

    color_t(uint16 value, uint16 red_mask = red_565, uint16 green_mask = green_565, uint16 blue_mask = blue_565, uint16 alpha_mask = 0);
    color_t(uint32 value, uint32 red_mask= red_rgba8, uint32 green_mask = green_rgba8, uint32 blue_mask = blue_rgba8, uint32 alpha_mask = alpha_rgba8);
};

/// @}
}
#endif
