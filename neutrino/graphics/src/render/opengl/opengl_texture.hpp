#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_TEXTURE_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_TEXTURE_HPP

#include <cstdint>

namespace framework::graphics
{
class Texture;

class OpenglTexture
{
public:
    OpenglTexture() = default;

    OpenglTexture(const OpenglTexture&) = delete;
    OpenglTexture& operator=(const OpenglTexture&) = delete;

    OpenglTexture(OpenglTexture&&) = default;
    OpenglTexture& operator=(OpenglTexture&&) = default;

    ~OpenglTexture();

    bool load(const Texture& texture);

    void clear();

    void bind(std::uint32_t texture_unit) const;

    std::uint32_t texture_id() const;

private:
    std::uint32_t m_texture = 0;
};

} // namespace framework::graphics

#endif
