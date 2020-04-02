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

#include <graphics/color_type.hpp>
#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <system/context.hpp>

namespace framework::graphics
{
class RenderImpl;
class RenderCommand;

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
