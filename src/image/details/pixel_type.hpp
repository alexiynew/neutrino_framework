/// @file
/// @brief Image pixel types.
/// @author Fedorov Alexey
/// @date 07.04.2019

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

#ifndef FRAMEWORK_IMAGE_DETAILS_PIXEL_TYPE_HPP
#define FRAMEWORK_IMAGE_DETAILS_PIXEL_TYPE_HPP

#include <common/types.hpp>

namespace framework::image::details
{
enum class pixel_format
{
    rgb,
    bgr,
    rgba,
    bgra,
};

template <pixel_format>
struct pixel_type_traits;

template <>
struct pixel_type_traits<pixel_format::rgb>
{
    struct pixel_type_t 
    {
        uint8 r;
        uint8 g;
        uint8 b;
    };

    using internal_type = uint8;

    static constexpr pixel_type_t make_pixel(uint8 r, uint8 g, uint8 b, uint8 /*unused*/) noexcept
    {
        return pixel_type_t{r, g, b};
    }
};

template <>
struct pixel_type_traits<pixel_format::bgr>
{
    struct pixel_type_t
    {
        uint8 b;
        uint8 g;
        uint8 r;
    };

    using internal_type = uint8;

    static constexpr pixel_type_t make_pixel(uint8 r, uint8 g, uint8 b, uint8 /*unused*/) noexcept
    {
        return pixel_type_t{b, g, r};
    }
};

template <>
struct pixel_type_traits<pixel_format::rgba>
{
    struct pixel_type_t 
    {
        uint8 r;
        uint8 g;
        uint8 b;
        uint8 a;
    };

    using internal_type = uint8;

    static constexpr pixel_type_t make_pixel(uint8 r, uint8 g, uint8 b, uint8 a) noexcept
    {
        return pixel_type_t{r, g, b, a};
    }
};

template <>
struct pixel_type_traits<pixel_format::bgra>
{
    struct pixel_type_t
    {
        uint8 b;
        uint8 g;
        uint8 r;
        uint8 a;
    };

    using internal_type = uint8;

    static constexpr pixel_type_t make_pixel(uint8 r, uint8 g, uint8 b, uint8 a) noexcept
    {
        return pixel_type_t{b, g, r, a};
    }
};

template <pixel_format Format>
using pixel_t = typename pixel_type_traits<Format>::pixel_type_t;

template <pixel_format Format>
using pixel_internal_type = typename pixel_type_traits<Format>::internal_type;

template <pixel_format Format>
constexpr auto make_pixel(uint8 r, uint8 g, uint8 b, uint8 a) noexcept
{
    return pixel_type_traits<Format>::make_pixel(r, g, b, a);
}

} // namespace framework

#endif
