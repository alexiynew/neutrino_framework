////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief OpenGL texture.
/// @author Fedorov Alexey
/// @date 07.07.2020
////////////////////////////////////////////////////////////////////////////////

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

#include <cstdint>

#include <graphics/texture.hpp>
#include <log/log.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_logger.hpp>
#include <graphics/src/render/opengl/opengl_texture.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
int convert_min_filter(MinFilter filter) noexcept
{
    switch (filter) {
        case MinFilter::nearest: return GL_NEAREST; break;
        case MinFilter::linear: return GL_LINEAR; break;
        case MinFilter::nearest_mipmap_nearest: return GL_NEAREST_MIPMAP_NEAREST; break;
        case MinFilter::linear_mipmap_nearest: return GL_LINEAR_MIPMAP_NEAREST; break;
        case MinFilter::nearest_mipmap_linear: return GL_NEAREST_MIPMAP_LINEAR; break;
        case MinFilter::linear_mipmap_linear: return GL_LINEAR_MIPMAP_LINEAR; break;
    }

    return 0;
}

int convert_mag_filter(MagFilter filter) noexcept
{
    switch (filter) {
        case MagFilter::nearest: return GL_NEAREST; break;
        case MagFilter::linear: return GL_LINEAR; break;
    }

    return 0;
}

int convert_wrap_parameter(Wrap wrap) noexcept
{
    switch (wrap) {
        case Wrap::repeat: return GL_REPEAT; break;
        case Wrap::mirrored_repeat: return GL_MIRRORED_REPEAT; break;
        case Wrap::clamp_to_edge: return GL_CLAMP_TO_EDGE; break;
        case Wrap::clamp_to_border: return GL_CLAMP_TO_BORDER; break;
    }

    return 0;
}
} // namespace

namespace framework::graphics
{
OpenglTexture::~OpenglTexture()
{
    clear();
}

bool OpenglTexture::load(const Texture& texture)
{
    glGenTextures(1, &m_texture);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    if (m_texture <= 0) {
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, convert_min_filter(texture.min_filter()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, convert_mag_filter(texture.mag_filter()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, convert_wrap_parameter(texture.wrap_s_parameter()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, convert_wrap_parameter(texture.wrap_t_parameter()));

    Colorf c = static_cast<Colorf>(texture.border_color());
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, c.data());

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 texture.image().width(),
                 texture.image().height(),
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 texture.image().data());

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    LOG_OPENGL_ERRORS();
    return true;
}

void OpenglTexture::bind(size_t index) const
{
    glActiveTexture(static_cast<int>(GL_TEXTURE0 + index));
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

std::uint32_t OpenglTexture::texture_id() const
{
    return m_texture;
}

void OpenglTexture::clear()
{
    glDeleteTextures(1, &m_texture);
}

} // namespace framework::graphics
