/// @file
/// @brief OpenGL render implementation.
/// @author Fedorov Alexey
/// @date 29.03.2020

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

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_RENDER_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_RENDER_HPP

#include <unordered_map>

#include <system/context.hpp>

#include <graphics/src/render/render_impl.hpp>

namespace framework::graphics
{
class OpenglMesh;
class OpenglShader;

class OpenglRender final : public RenderImpl
{
public:
    explicit OpenglRender(system::Context& context);

    OpenglRender(const OpenglRender& other) = default;
    OpenglRender& operator=(const OpenglRender& other) = default;

    OpenglRender(OpenglRender&& other) = default;
    OpenglRender& operator=(OpenglRender&& other) = default;

    ~OpenglRender() override;

    void set_clear_color(Color color) override;

    bool load(const Mesh& mesh) override;
    bool load(const Shader& shader) override;

    void start_frame() override;
    void perform(const RenderCommand& command) override;
    void end_frame() override;

private:
    using MeshMap   = std::unordered_map<InstanceId, OpenglMesh>;
    using ShaderMap = std::unordered_map<InstanceId, OpenglShader>;

    void init() const;
    void set_uniforms() const;

    MeshMap m_meshes;
    ShaderMap m_shaders;
};

} // namespace framework::graphics

#endif
