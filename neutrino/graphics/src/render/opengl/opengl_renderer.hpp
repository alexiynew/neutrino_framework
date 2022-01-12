#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_RENDERER_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_RENDERER_HPP

#include <unordered_map>

#include <graphics/renderer.hpp>
#include <system/context.hpp>

#include <graphics/src/render/renderer_impl.hpp>

namespace framework::graphics
{
struct Uniforms;
class OpenglMesh;
class OpenglShader;
class OpenglTexture;

class OpenglRenderer final : public RendererImpl
{
public:
    explicit OpenglRenderer(const system::Context& context);

    OpenglRenderer(const OpenglRenderer& other) = default;
    OpenglRenderer& operator=(const OpenglRenderer& other) = default;

    OpenglRenderer(OpenglRenderer&& other) = default;
    OpenglRenderer& operator=(OpenglRenderer&& other) = default;

    ~OpenglRenderer() override;

    void set_clear_color(const Color& color) override;
    void set_viewport(Size size) override;

    bool load(const Mesh& mesh) override;
    bool load(const Shader& shader) override;
    bool load(const Texture& texture) override;

    void start_frame() override;
    void render(const Renderer::Command& command) override;
    void end_frame() override;

private:
    using MeshMap    = std::unordered_map<InstanceId, OpenglMesh>;
    using ShaderMap  = std::unordered_map<InstanceId, OpenglShader>;
    using TextureMap = std::unordered_map<InstanceId, OpenglTexture>;

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
};

} // namespace framework::graphics

#endif
