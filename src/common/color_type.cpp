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

#include <common/color_type.hpp>

namespace framework
{


inline uint8 map(float32 value) noexcept
{
    return value * 255;
}


color_t::color_t(uint8 r, uint8 g, uint8 b, uint8 a)
    : r(r)
    , g(g)
    , b(b)
    , a(a)
{}

color_t::color_t(float32 r, float32 g, float32 b, float32 a)
    : r(map(r))
    , g(map(g))
    , b(map(b))
    , a(map(a))
{}

color_t::color_t(uint16 value, uint16 red_mask, uint16 green_mask, uint16 blue_mask, uint16 alpha_mask)
    : r(value & red_mask)
    , g(value & green_mask)
    , b(value & blue_mask)
    , a(value & alpha_mask)
{

}

color_t::color_t(uint32 value, uint32 red_mask, uint32 green_mask, uint32 blue_mask, uint32 alpha_mask)
    : r(value & red_mask)
    , g(value & green_mask)
    , b(value & blue_mask)
    , a(value & alpha_mask)
{

}

}
