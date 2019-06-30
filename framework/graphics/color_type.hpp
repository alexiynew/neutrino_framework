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

#ifndef FRAMEWORK_GRAPHICS_COLOR_TYPE_HPP
#define FRAMEWORK_GRAPHICS_COLOR_TYPE_HPP

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
    uint8 r = 0;
    uint8 g = 0;
    uint8 b = 0;
    uint8 a = 255;

    color_t() = default;

    color_t(uint8 r, uint8 g, uint8 b, uint8 a);
    color_t(float32 r, float32 g, float32 b, float32 a);

    color_t(uint16 value);
    color_t(uint32 value);

    uint8* data();
    const uint8* data() const;
};

/// @}
} // namespace framework

#endif
