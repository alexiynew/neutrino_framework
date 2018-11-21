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

#include <stdexcept>

#include <common/types.hpp>
#include <opengl/details/linux/glx_context.hpp>

namespace
{
using framework::int32;
using framework::opengl::context_settings;

constexpr int32 glx_min_major_version = 1;
constexpr int32 glx_min_minor_version = 4;

bool check_glx_version(Display* display)
{
    int32 glx_major = 0;
    int32 glx_minor = 0;

    glXQueryVersion(display, &glx_major, &glx_minor);

    return glx_major >= glx_min_major_version && glx_minor >= glx_min_minor_version;
}

GLXFBConfig find_best_config(Display* display,
                             context_settings::samples samples_count,
                             GLXFBConfig* configs,
                             int32 count)
{
    if (samples_count == context_settings::samples::dont_care && count > 0) {
        return configs[0];
    }

    int32 best         = -1;
    int32 best_samples = -1;

    for (int32 i = 0; i < count; ++i) {
        int32 sample_buffer;
        int32 samples;
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLE_BUFFERS, &sample_buffer);
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLES, &samples);

        if (best < 0 || (sample_buffer != 0 && samples > best_samples)) {
            best         = i;
            best_samples = samples;
        }
    }

    return configs[best];
}

GLXFBConfig choose_framebuffer_config(Display* display, const context_settings& settings)
{
    const auto render_type = [](context_settings::color color) {
        switch (color) {
            case context_settings::color::rgba: return GLX_RGBA_BIT;
            case context_settings::color::index: return GLX_COLOR_INDEX_BIT;
        }
        return GLX_RGBA_BIT;
    }(settings.color_type());

    // clang-format off
    static int32 visual_attribs[] = {
        GLX_X_RENDERABLE,  True,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_RENDER_TYPE,   render_type,
        GLX_X_VISUAL_TYPE, static_cast<int32>((render_type == GLX_RGBA_BIT) ? GLX_TRUE_COLOR : GLX_DONT_CARE),
        GLX_RED_SIZE,      8,
        GLX_GREEN_SIZE,    8,
        GLX_BLUE_SIZE,     8,
        GLX_ALPHA_SIZE,    8,
        GLX_DEPTH_SIZE,    settings.depth_bits(),
        GLX_STENCIL_SIZE,  settings.stencil_bits(),
        GLX_DOUBLEBUFFER,  settings.double_buffered() ? True : False,
        None};
    // clang-format on

    int32 count;
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
    GLXFBConfig* configs = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &count);
    if (configs == nullptr) {
        return nullptr;
    }

    GLXFBConfig best_config = find_best_config(display, settings.samples_count(), configs, count);

    XFree(configs);

    return best_config;
}

GLXContext create_glx_context(Display* display, GLXFBConfig framebuffer_config, const context_settings& settings)
{
    if (!framework::opengl::glx_arb_create_context_supported ||
        (framework::opengl::glXCreateContextAttribsARB == nullptr)) {
        return nullptr;
    }

    // clang-format off
    int32 context_attribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, settings.version().major,
        GLX_CONTEXT_MINOR_VERSION_ARB, settings.version().minor,
        GLX_CONTEXT_FLAGS_ARB        , GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
        None};
    // clang-format on

    return framework::opengl::glXCreateContextAttribsARB(display, framebuffer_config, nullptr, True, context_attribs);
}

} // namespace

namespace framework::system
{
glx_context::glx_context(Display* display, opengl::context_settings settings)
    : context(std::move(settings)), m_display(display)
{
    if (!check_glx_version(m_display)) {
        throw std::runtime_error("Invalid GLX version.");
    }

    opengl::init_glx();

    m_framebuffer_config = choose_framebuffer_config(m_display, settings);

    if (m_framebuffer_config == nullptr) {
        throw std::runtime_error("Can't get framebuffer config.");
    }

    m_visual_info = glXGetVisualFromFBConfig(m_display, m_framebuffer_config);
    if (m_visual_info == nullptr) {
        throw std::runtime_error("Can't get visual info.");
    }

    m_colormap = XCreateColormap(m_display, DefaultRootWindow(m_display), m_visual_info->visual, AllocNone);
    if (m_colormap == None) {
        clear();
        throw std::runtime_error("Can't create colormap.");
    }

    m_glx_context = create_glx_context(m_display, m_framebuffer_config, settings);
    if (m_glx_context == nullptr) {
        clear();
        throw std::runtime_error("Can't create opengl context.");
    }
}

glx_context::~glx_context()
{
    clear();
}

bool glx_context::valid() const
{
    return m_display != nullptr && m_framebuffer_config != nullptr && m_glx_context != nullptr && m_colormap != None &&
           m_visual_info != nullptr;
}

bool glx_context::is_current() const
{
    return valid() && glXGetCurrentContext() == m_glx_context;
}

void glx_context::make_current() const
{
    if (!is_current()) {
        glXMakeCurrent(m_display, m_window, m_glx_context);
    }
}

void glx_context::swap_buffers() const
{
    glXSwapBuffers(m_display, m_window);
}

Colormap glx_context::colormap() const
{
    return m_colormap;
}

XVisualInfo* glx_context::visual_info() const
{
    return m_visual_info;
}

void glx_context::attach_window(Window window)
{
    m_window = window;
}

void glx_context::clear()
{
    if (m_display && m_glx_context != nullptr) {
        glXDestroyContext(m_display, m_glx_context);
    }

    if (m_display && m_colormap != 0u) {
        XFreeColormap(m_display, m_colormap);
    }

    if (m_visual_info) {
        XFree(m_visual_info);
    }
}

} // namespace framework::system
