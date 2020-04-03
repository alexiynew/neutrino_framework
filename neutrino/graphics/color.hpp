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

#ifndef FRAMEWORK_GRAPHICS_COLOR_HPP
#define FRAMEWORK_GRAPHICS_COLOR_HPP

#include <cstdint>

namespace framework::graphics
{
/// @details
/// Color type definition.
///
/// @addtogroup graphics_module
/// @{

struct Color
{
    using ValueType = std::uint8_t;

    ValueType r = 0;
    ValueType g = 0;
    ValueType b = 0;
    ValueType a = 255;

    Color() = default;

    Color(ValueType r, ValueType g, ValueType b, ValueType a = 255);
    Color(float r, float g, float b, float a = 1.0f);

    Color(std::uint16_t value);
    Color(std::uint32_t value);

    Color(const Color&) = default;
    Color(Color&&)      = default;

    Color& operator=(const Color&) = default;
    Color& operator=(Color&&) = default;

    ValueType* data();
    const ValueType* data() const;
};

/// @}
} // namespace framework::graphics

#endif
