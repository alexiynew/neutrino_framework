/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#include <graphic/gl/gl.hpp>
#include <graphic/opengl_canvas.hpp>
#include <log/log.hpp>

namespace framework
{
namespace graphic
{
const char* log_tag = "opengl_canvas";

opengl_canvas::opengl_canvas(std::unique_ptr<window::graphic_context> context) : m_context(std::move(context))
{
    if (m_context->valid()) {
        if (!gl::init()) {
            throw std::runtime_error("Can't init OpenGL functions.");
        }
    }
}

opengl_canvas::~opengl_canvas() = default;

void opengl_canvas::clear(float red, float green, float blue, float alpha)
{
    m_context->make_current();

    gl::glClearColor(red, green, blue, alpha);
    gl::glClear(gl::gl_color_buffer_bit);

    auto error = gl::glGetError();

    if (error != gl::gl_no_error) {
        log::error(log_tag) << error << std::endl;
    }
}

void opengl_canvas::swap_buffers()
{
    m_context->swap_buffers();
}

} // namespace graphic

} // namespace framework
