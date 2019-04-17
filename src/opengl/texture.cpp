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

#include <opengl/texture.hpp>
#include <opengl/gl.hpp>
#include <common/types.hpp>

namespace framework::opengl
{

// GL_ACTIVE_TEXTURE or GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
texture::texture(min_filter minf, mag_filter magf, wrap_s ws, wrap_t wt)
{
    using framework::int32;

    glActiveTexture(GL_TEXTURE0);

    glGenTextures(1, &m_texture_id);

    glBindTexture(GL_TEXTURE_2D, m_texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<int32>(minf));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<int32>(magf));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<int32>(ws));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<int32>(wt));

    glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::load(internal_format ifmt, int32 width, int32 height, format fmt, const void* data)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture_id);

    glTexImage2D(GL_TEXTURE_2D, 0, static_cast<int32>(ifmt), width, height, 0, static_cast<int32>(fmt), GL_UNSIGNED_BYTE, data);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::bind()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture_id);
}

void texture::unbind()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

framework::uint32 texture::texture_id() const
{
    return m_texture_id;
}

framework::int32 texture::texture_unit() const
{
    return 0;
}

}
