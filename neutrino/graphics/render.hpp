/// @file
/// @brief Render.
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

#ifndef FRAMEWORK_GRAPHICS_RENDER_HPP
#define FRAMEWORK_GRAPHICS_RENDER_HPP

#include <memory>

#include <graphics/color.hpp>
#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <system/context.hpp>

namespace framework::graphics
{
class RenderImpl;
class RenderCommand;

// TODO: Add documentation
// TODO: Add tests
// TODO: Add camera support
// TODO: Add texture support

class Render
{
public:
    explicit Render(system::Context& context);

    Render(const Render& other) = delete;
    Render& operator=(const Render& other) = delete;

    Render(Render&& other) noexcept;
    Render& operator=(Render&& other) noexcept;

    ~Render();

    void set_clear_color(Color color);

    /*

        // Set the depth buffer to be entirely cleared to 1.0 values.
        glClearDepth(1.0f);

        // Enable depth testing.
        glEnable(GL_DEPTH_TEST);

        // Set the polygon winding to front facing for the left handed system.
        glFrontFace(GL_CW);

        // Enable back face culling.
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        // Initialize the world/model matrix to the identity matrix.
        BuildIdentityMatrix(m_worldMatrix);

        // Set the field of view and screen aspect ratio.
        fieldOfView = 3.14159265358979323846f / 4.0f;
        screenAspect = (float)screenWidth / (float)screenHeight;

        // Build the perspective projection matrix.
        BuildPerspectiveFovLHMatrix(m_projectionMatrix, fieldOfView, screenAspect, screenNear, screenDepth);

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

    void display();

private:
    std::unique_ptr<RenderImpl> m_impl;
    system::Context& m_context;

    std::vector<RenderCommand> m_render_commands;
};

} // namespace framework::graphics

#endif
