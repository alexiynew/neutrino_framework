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

#include <vector>

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
    using type = framework::uint32;

    static constexpr uint32 bits_per_pixel = 24;

    // TODO: Check bytes packing
    static constexpr type make_pixel(uint8 r, uint8 g, uint8 b, uint8 /*unused*/) noexcept
    {
        // return static_cast<type>((r << 16) + (g << 8) + (b));
        return static_cast<type>((r << 24) + (g << 16) + (b << 8) + 255);
    }
};

template <>
struct pixel_type_traits<pixel_format::bgr>
{
    using type = framework::uint32;

    static constexpr uint32 bits_per_pixel = 24;

    // TODO: Check bytes packing
    static constexpr type make_pixel(uint8 r, uint8 g, uint8 b, uint8 /*unused*/) noexcept
    {
        // return static_cast<type>((b << 16) + (g << 8) + (r));
        return static_cast<type>((r << 24) + (g << 16) + (b << 8) + 255);
    }
};

template <>
struct pixel_type_traits<pixel_format::rgba>
{
    using type = framework::uint32;

    static constexpr uint32 bits_per_pixel = 32;

    static constexpr type make_pixel(uint8 r, uint8 g, uint8 b, uint8 a) noexcept
    {
        return static_cast<type>((r << 24) + (g << 16) + (b << 8) + a);
    }
};

template <>
struct pixel_type_traits<pixel_format::bgra>
{
    using type = framework::uint32;

    static constexpr uint32 bits_per_pixel = 32;

    static constexpr type make_pixel(uint8 r, uint8 g, uint8 b, uint8 a) noexcept
    {
        return static_cast<type>((b << 24) + (g << 16) + (r << 8) + a);
    }
};

template <pixel_format Format>
using pixel_t = typename pixel_type_traits<Format>::type;

template <pixel_format Format>
constexpr auto make_pixel(uint8 r, uint8 g, uint8 b, uint8 a) noexcept
{
    return pixel_type_traits<Format>::make_pixel(r, g, b, a);
}

class pixel_storage_interface
{
public:
    virtual ~pixel_storage_interface() = default;

    virtual void set_pixel(uint32 index, uint8 red, uint8 green, uint8 blue, uint8 alpha = 0) = 0;
    virtual void reserve(uint32 size)                                                         = 0;
};

template <pixel_format Format>
class pixel_storage : public pixel_storage_interface
{
public:
    virtual void set_pixel(uint32 index, uint8 red, uint8 green, uint8 blue, uint8 alpha = 0) override
    {
        m_data[index] = make_pixel<Format>(red, green, blue, alpha);
    }

    virtual void reserve(uint32 size) override
    {
        m_data.resize(size);

        uint32 s = m_data.size();
        if (s == 0) {
        }
    }

    const std::vector<pixel_t<Format>>& data() const
    {
        return m_data;
    }

private:
    std::vector<pixel_t<Format>> m_data;
};

} // namespace framework::image::details

#endif
