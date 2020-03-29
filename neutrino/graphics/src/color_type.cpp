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
using framework::float32;
using framework::uint16;
using framework::uint32;
using framework::uint8;

constexpr inline uint8 map_to_int(float32 value) noexcept
{
    return static_cast<uint8>(value * 255);
}

constexpr uint16 red_565   = 0xF800;
constexpr uint16 green_565 = 0x7E0;
constexpr uint16 blue_565  = 0x1F;

constexpr uint32 red_rgba8   = 0xFF000000;
constexpr uint32 green_rgba8 = 0xFF0000;
constexpr uint32 blue_rgba8  = 0xFF00;
constexpr uint32 alpha_rgba8 = 0xFF;

} // namespace

namespace framework::graphics
{
Color::Color(uint8 r_value, uint8 g_value, uint8 b_value, uint8 a_value)
    : r(r_value), g(g_value), b(b_value), a(a_value)
{}

Color::Color(float32 r_value, float32 g_value, float32 b_value, float32 a_value)
    : r(map_to_int(r_value)), g(map_to_int(g_value)), b(map_to_int(b_value)), a(map_to_int(a_value))
{}

Color::Color(uint16 value)
    : r(static_cast<uint8>((value & red_565) >> 11)),
      g(static_cast<uint8>((value & green_565) >> 5)),
      b(static_cast<uint8>(value & blue_565)),
      a(255)
{}

Color::Color(uint32 value)
    : r(static_cast<uint8>((value & red_rgba8) >> 24)),
      g(static_cast<uint8>((value & green_rgba8) >> 16)),
      b(static_cast<uint8>((value & blue_rgba8) >> 8)),
      a(static_cast<uint8>(value & alpha_rgba8))
{}

uint8* Color::data()
{
    return &r;
}

const uint8* Color::data() const
{
    return &r;
}

} // namespace framework::graphics
