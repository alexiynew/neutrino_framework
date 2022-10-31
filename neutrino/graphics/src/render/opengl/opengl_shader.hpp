#ifndef GRAPHICS_SRC_RENDER_OPENGL_OPENGL_SHADER_HPP
#define GRAPHICS_SRC_RENDER_OPENGL_OPENGL_SHADER_HPP

#include <cstdint>
#include <unordered_map>

#include <graphics/renderer.hpp>

namespace neutrino::graphics
{
class Shader;
class OpenglTexture;

class OpenglShader
{
public:
    using UniformMap = std::unordered_map<std::string, int>;

    OpenglShader() = default;

    OpenglShader(const OpenglShader&)            = delete;
    OpenglShader& operator=(const OpenglShader&) = delete;

    OpenglShader(OpenglShader&&)            = default;
    OpenglShader& operator=(OpenglShader&&) = default;

    ~OpenglShader();

    bool load(const Shader& shader);
    void clear();

    void use() const;

    int get_attribute_location(const std::string& name) const;

    bool is_texture(const std::string& name) const;

    void set_uniforms(const Renderer::Command& command) const;
    void set_texture(const std::string& name, std::size_t index) const;

private:
    std::uint32_t m_vertex_shader   = 0;
    std::uint32_t m_fragment_shader = 0;
    std::uint32_t m_shader_program  = 0;

    UniformMap m_uniforms;
    UniformMap m_textures;
};

} // namespace neutrino::graphics

#endif
