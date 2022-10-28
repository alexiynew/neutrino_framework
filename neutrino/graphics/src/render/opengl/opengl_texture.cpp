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
int convert_min_filter(Texture::MinFilter filter) noexcept
{
    switch (filter) {
        case Texture::MinFilter::nearest: return GL_NEAREST;
        case Texture::MinFilter::linear: return GL_LINEAR;
        case Texture::MinFilter::nearest_mipmap_nearest: return GL_NEAREST_MIPMAP_NEAREST;
        case Texture::MinFilter::linear_mipmap_nearest: return GL_LINEAR_MIPMAP_NEAREST;
        case Texture::MinFilter::nearest_mipmap_linear: return GL_NEAREST_MIPMAP_LINEAR;
        case Texture::MinFilter::linear_mipmap_linear: return GL_LINEAR_MIPMAP_LINEAR;
    }

    return 0;
}

int convert_mag_filter(Texture::MagFilter filter) noexcept
{
    switch (filter) {
        case Texture::MagFilter::nearest: return GL_NEAREST;
        case Texture::MagFilter::linear: return GL_LINEAR;
    }

    return 0;
}

int convert_wrap_parameter(Texture::Wrap wrap) noexcept
{
    switch (wrap) {
        case Texture::Wrap::repeat: return GL_REPEAT;
        case Texture::Wrap::mirrored_repeat: return GL_MIRRORED_REPEAT;
        case Texture::Wrap::clamp_to_edge: return GL_CLAMP_TO_EDGE;
        case Texture::Wrap::clamp_to_border: return GL_CLAMP_TO_BORDER;
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
    if (m_texture <= 0) {
        glGenTextures(1, &m_texture);
    }

    if (m_texture <= 0) {
        clear();
        return false;
    }

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, convert_min_filter(texture.min_filter()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, convert_mag_filter(texture.mag_filter()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, convert_wrap_parameter(texture.wrap_s_parameter()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, convert_wrap_parameter(texture.wrap_t_parameter()));

    if (HAS_OPENGL_ERRORS()) {
        clear();
        return false;
    }

    Colorf c = static_cast<Colorf>(texture.border_color());
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, c.data());

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 static_cast<GLsizei>(texture.image().width()),
                 static_cast<GLsizei>(texture.image().height()),
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 texture.image().data().data());

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (HAS_OPENGL_ERRORS()) {
        clear();
        return false;
    }

    return true;
}

void OpenglTexture::bind(std::uint32_t texture_unit) const
{
    glActiveTexture(static_cast<GLenum>(GL_TEXTURE0 + texture_unit));
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
