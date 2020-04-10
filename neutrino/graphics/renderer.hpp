/// @file
/// @brief Renderer.
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

#ifndef FRAMEWORK_GRAPHICS_RENDERER_HPP
#define FRAMEWORK_GRAPHICS_RENDERER_HPP

#include <memory>

#include <math/math.hpp>
#include <system/context.hpp>

namespace framework::graphics
{
class Mesh;
class RenderCommand;
class RendererImpl;
class Shader;
struct Color;
struct Uniforms;

// TODO: Add documentation
// TODO: Add tests
// TODO: Add camera support
// TODO: Add texture support

class Renderer
{
public:
    using MatrixCache = std::vector<math::Matrix4f>;

    explicit Renderer(system::Context& context);

    Renderer(const Renderer& other) = delete;
    Renderer& operator=(const Renderer& other) = delete;

    Renderer(Renderer&& other) noexcept;
    Renderer& operator=(Renderer&& other) noexcept;

    ~Renderer();

    void set_clear_color(Color color);
    void set_projection(const math::Matrix4f& projection);

    // TODO: make it with camera
    void set_view(const math::Matrix4f& view);

    /*
            // Get the name of the video card.
            vendorString = (char*)glGetString(GL_VENDOR);
            rendererString = (char*)glGetString(GL_RENDERER);


            // Turn on or off the vertical sync depending on the input bool value.
            if(vsync)
            {
                result = wglSwapIntervalEXT(1);
            }
            else
            {
                result = wglSwapIntervalEXT(0);
            }


        */

    bool load(const Mesh& mesh);
    bool load(const Shader& shader);

    void render(const Mesh& mesh, const Shader& shader);
    void render(const Mesh& mesh, const Shader& shader, const math::Matrix4f& model_transform);

    void display();

private:
    Uniforms get_uniforms(const math::Matrix4f& model_transform) const;

    void start_frame();
    void end_frame();

    std::unique_ptr<RendererImpl> m_impl;
    system::Context& m_context;

    std::vector<RenderCommand> m_render_commands;
    MatrixCache m_projection;
    MatrixCache m_view;
};

} // namespace framework::graphics

#endif
