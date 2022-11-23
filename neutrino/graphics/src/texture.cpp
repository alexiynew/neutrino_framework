#include <graphics/texture.hpp>

#include <graphics/src/opengl/opengl.hpp>

namespace neutrino::graphics
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

    m_wrap_s = Wrap::repeat;
    m_wrap_t = Wrap::repeat;

    m_border_color = Color(0x000000FFu);

    m_min_filter = MinFilter::nearest_mipmap_linear;
    m_mag_filter = MagFilter::linear;
}

const Image& Texture::image() const
{
    return m_image;
}

Texture::Wrap Texture::wrap_s_parameter() const
{
    return m_wrap_s;
}

Texture::Wrap Texture::wrap_t_parameter() const
{
    return m_wrap_t;
}

const Color& Texture::border_color() const
{
    return m_border_color;
}

Texture::MinFilter Texture::min_filter() const
{
    return m_min_filter;
}

Texture::MagFilter Texture::mag_filter() const
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

} // namespace neutrino::graphics
