/// @file
/// @brief GL context implementation for Linux.
/// @author Fedorov Alexey
/// @date 14.10.2018

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

#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_CONTEXT_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_CONTEXT_HPP

#include <X11/Xlib.h>

#include <opengl/context.hpp>
#include <opengl/extensions/linux/glxext.hpp>

namespace framework::os
{
class x11_context : public framework::opengl::context
{
public:
    x11_context(Display* display, opengl::context_settings settings);
    ~x11_context() override;

    x11_context(const x11_context&) = default;
    x11_context(x11_context&&)      = default;

    x11_context& operator=(const x11_context&) = default;
    x11_context& operator=(x11_context&&) = default;

    bool valid() const override;
    bool is_current() const override;

    void make_current() const override;
    void swap_buffers() const override;

    Colormap colormap() const;
    Visual* visual() const;

    void attach_window(Window window);

private:
    Display* m_display               = nullptr;
    GLXFBConfig m_framebuffer_config = nullptr;
    GLXContext m_glx_context         = nullptr;
    Colormap m_colormap              = None;
    Visual* m_visual                 = nullptr;
    Window m_window                  = None;
};

} // namespace framework::os

#endif
