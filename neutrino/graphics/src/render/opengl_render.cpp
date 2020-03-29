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

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl_render.hpp>

using namespace framework;
using namespace framework::graphics::details::opengl;

namespace
{
float map_to_float(uint8 value)
{
    return static_cast<float>(value) / 255.0f;
}
} // namespace

namespace framework::graphics
{
OpenglRender::OpenglRender(system::Context& context) : m_context(context)
{
    init_opengl([&context](const char* function_name) { return context.get_function(function_name); });
}

OpenglRender::OpenglRender(const OpenglRender& other) = default;

OpenglRender& OpenglRender::operator=(const OpenglRender& other) = default;

OpenglRender::OpenglRender(OpenglRender&& other) = default;

OpenglRender& OpenglRender::operator=(OpenglRender&& other) = default;

OpenglRender::~OpenglRender() = default;

void OpenglRender::display()
{
    m_context.make_current();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_context.swap_buffers();
}

void OpenglRender::set_clear_color(Color color)
{
    m_context.make_current();
    glClearColor(map_to_float(color.r), map_to_float(color.g), map_to_float(color.b), map_to_float(color.a));
}

} // namespace framework::graphics
