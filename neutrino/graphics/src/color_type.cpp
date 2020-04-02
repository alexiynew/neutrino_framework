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

#include <graphics/color_type.hpp>

namespace
{

constexpr inline std::uint8_t map_to_int(float value) noexcept
{
    return static_cast<std::uint8_t>(value * 255);
}

constexpr std::uint16_t red_565   = 0xF800;
constexpr std::uint16_t green_565 = 0x7E0;
constexpr std::uint16_t blue_565  = 0x1F;

constexpr std::uint32_t red_rgba8   = 0xFF000000;
constexpr std::uint32_t green_rgba8 = 0xFF0000;
constexpr std::uint32_t blue_rgba8  = 0xFF00;
constexpr std::uint32_t alpha_rgba8 = 0xFF;

} // namespace

namespace framework::graphics
{
Color::Color(ValueType r_value, ValueType g_value, ValueType b_value, ValueType a_value)
    : r(r_value), g(g_value), b(b_value), a(a_value)
{}

Color::Color(float r_value, float g_value, float b_value, float a_value)
    : r(map_to_int(r_value)), g(map_to_int(g_value)), b(map_to_int(b_value)), a(map_to_int(a_value))
{}

Color::Color(std::uint16_t value)
    : r(static_cast<ValueType>((value & red_565) >> 11)),
      g(static_cast<ValueType>((value & green_565) >> 5)),
      b(static_cast<ValueType>(value & blue_565)),
      a(255)
{}

Color::Color(std::uint32_t value)
    : r(static_cast<ValueType>((value & red_rgba8) >> 24)),
      g(static_cast<ValueType>((value & green_rgba8) >> 16)),
      b(static_cast<ValueType>((value & blue_rgba8) >> 8)),
      a(static_cast<ValueType>(value & alpha_rgba8))
{}

Color::ValueType* Color::data()
{
    return &r;
}

const Color::ValueType* Color::data() const
{
    return &r;
}

} // namespace framework::graphics
