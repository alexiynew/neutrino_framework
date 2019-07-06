/// @file
/// @brief OpenGL texture.
/// @author Fedorov Alexey
/// @date 16.04.2019

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

#include <common/types.hpp>
#include <gl/gl.hpp>
#include <graphics/texture.hpp>

namespace framework::graphics
{
// GL_ACTIVE_TEXTURE or GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
texture::texture(min_filter minf, mag_filter magf, wrap_s ws, wrap_t wt)
{
    using framework::int32;

    gl::glActiveTexture(GL_TEXTURE0);

    gl::glGenTextures(1, &m_texture_id);

    gl::glBindTexture(GL_TEXTURE_2D, m_texture_id);

    gl::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<int32>(minf));
    gl::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<int32>(magf));
    gl::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<int32>(ws));
    gl::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<int32>(wt));

    gl::glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::load(int32 width, int32 height, const void* data)
{
    gl::glActiveTexture(GL_TEXTURE0);
    gl::glBindTexture(GL_TEXTURE_2D, m_texture_id);

    gl::glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    gl::glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::bind()
{
    gl::glActiveTexture(GL_TEXTURE0);
    gl::glBindTexture(GL_TEXTURE_2D, m_texture_id);
}

void texture::unbind()
{
    gl::glActiveTexture(GL_TEXTURE0);
    gl::glBindTexture(GL_TEXTURE_2D, 0);
}

framework::uint32 texture::texture_id() const
{
    return m_texture_id;
}

framework::int32 texture::texture_unit() const
{
    return 0;
}

} // namespace framework::graphics
