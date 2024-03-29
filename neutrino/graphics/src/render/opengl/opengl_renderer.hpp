#ifndef GRAPHICS_SRC_RENDER_OPENGL_OPENGL_RENDERER_HPP
#define GRAPHICS_SRC_RENDER_OPENGL_OPENGL_RENDERER_HPP

#include <unordered_map>

#include <graphics/renderer.hpp>
#include <system/context.hpp>

#include <graphics/src/render/opengl/opengl_mesh.hpp>
#include <graphics/src/render/opengl/opengl_shader.hpp>
#include <graphics/src/render/opengl/opengl_texture.hpp>
#include <graphics/src/render/renderer_impl.hpp>

namespace framework::graphics
{
class OpenglRenderer final : public RendererImpl
{
public:
    using ResourceId = Renderer::ResourceId;

    explicit OpenglRenderer();

    OpenglRenderer(const OpenglRenderer& other)            = default;
    OpenglRenderer& operator=(const OpenglRenderer& other) = default;

    OpenglRenderer(OpenglRenderer&& other)            = default;
    OpenglRenderer& operator=(OpenglRenderer&& other) = default;

    ~OpenglRenderer() override;

    void set_clear_color(const Color& color) override;
    void set_polygon_mode(Renderer::PolygonMode mode) override;
    void set_viewport(Size size) override;

    bool load(ResourceId res_id, const Mesh& mesh) override;
    bool load(ResourceId res_id, const Shader& shader) override;
    bool load(ResourceId res_id, const Texture& texture) override;

    void start_frame() override;
    void render(const Renderer::Command& command) override;
    void end_frame() override;

private:
    using MeshMap    = std::unordered_map<ResourceId, OpenglMesh>;
    using ShaderMap  = std::unordered_map<ResourceId, OpenglShader>;
    using TextureMap = std::unordered_map<ResourceId, OpenglTexture>;

    void init();

    void get_info();
    void bind_textures(const OpenglShader& shader, const Renderer::Command& command) const;

    MeshMap m_meshes;
    ShaderMap m_shaders;
    TextureMap m_textures;

    std::string m_vendor;
    std::string m_rendererer;
    std::string m_gl_version;
    std::string m_shading_lang_version;

    std::uint32_t m_max_texture_units = 48;

    Renderer::PolygonMode m_polygon_mode = Renderer::PolygonMode::fill;
};

} // namespace framework::graphics

#endif
