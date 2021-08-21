/// @file
/// @brief OpenGL texture.
/// @author Fedorov Alexey
/// @date 16.04.2019

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

#include <common/types.hpp>
#include <graphics/texture.hpp>

#include <graphics/src/opengl/opengl.hpp>

namespace framework::graphics
{

Texture::Texture(const Texture& other)
    : m_image(other.m_image)
    , m_wrap_s(other.m_wrap_s)
    , m_wrap_t(other.m_wrap_t)
    , m_border_color(other.m_border_color)
    , m_min_filter(other.m_min_filter)
    , m_mag_filter(other.m_mag_filter)
{}

Texture& Texture::operator=(const Texture& other)
{
    using std::swap;

    Texture tmp(other);
    swap(*this, tmp);
    return *this;
}

Texture::Texture(Texture&& other) noexcept
{
    swap(*this, other);
}

Texture& Texture::operator=(Texture&& other) noexcept
{
    swap(*this, other);
    return *this;
}

void Texture::set_image(const Image& image)
{
    m_image = image;
}

void Texture::set_image(Image&& image)
{
    using std::swap;
    swap(m_image, image);
}

void Texture::set_wrap_s_parameter(Wrap wrap)
{
    m_wrap_s = wrap;
}

void Texture::set_wrap_t_parameter(Wrap wrap)
{
    m_wrap_t = wrap;
}

void Texture::set_border_color(const Color& color)
{
    m_border_color = color;
}

void Texture::set_min_filter(MinFilter min_filter)
{
    m_min_filter = min_filter;
}

void Texture::set_mag_filter(MagFilter mag_filter)
{
    m_mag_filter = mag_filter;
}

void Texture::clear()
{
    using std::swap;

    Image tmp;
    swap(m_image, tmp);
}

InstanceId Texture::instance_id() const
{
    return m_instance_id;
}

const Image& Texture::image() const
{
    return m_image;
}

Wrap Texture::wrap_s_parameter() const
{
    return m_wrap_s;
}

Wrap Texture::wrap_t_parameter() const
{
    return m_wrap_t;
}

const Color& Texture::border_color() const
{
    return m_border_color;
}

MinFilter Texture::min_filter() const
{
    return m_min_filter;
}

MagFilter Texture::mag_filter() const
{
    return m_mag_filter;
}

void swap(Texture& lhs, Texture& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_image, rhs.m_image);

    swap(lhs.m_wrap_s, rhs.m_wrap_s);
    swap(lhs.m_wrap_t, rhs.m_wrap_t);

    swap(lhs.m_border_color, rhs.m_border_color);

    swap(lhs.m_min_filter, rhs.m_min_filter);
    swap(lhs.m_mag_filter, rhs.m_mag_filter);
}

} // namespace framework::graphics
