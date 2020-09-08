////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief OpenGL render implementation.
/// @author Fedorov Alexey
/// @date 29.03.2020
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
    explicit OpenglRenderer(system::Context& context);

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
