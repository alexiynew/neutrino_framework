/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 11.09.2018

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

#include <graphics/opengl/details/windows/wgl_context.hpp>
#include <graphics/opengl/details/windows/wglext.hpp>
#include <stdexcept>

namespace framework::system
{
win32_context::win32_context(HWND window, opengl::context_settings settings)
    : opengl::context(settings), m_window(window)
{
    m_hdc = GetDC(m_window);

    if (m_hdc == nullptr) {
        throw std::runtime_error("GetDC failed!");
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;

    int pixelFormat = ChoosePixelFormat(m_hdc, &pfd);

    if (pixelFormat == 0) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't choose pixelformat");
    }

    if (!SetPixelFormat(m_hdc, pixelFormat, &pfd)) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't set pixelformat");
    }

    HGLRC hglrc = wglCreateContext(m_hdc);
    if (hglrc == nullptr) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't create temporary graphic context");
    }

    wglMakeCurrent(m_hdc, hglrc);

    opengl::init_wgl();

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hglrc);

    if (!opengl::wgl_arb_create_context_supported) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("wglCreateContextAttribsARB not supported");
    }

    auto version = settings.version();
    // clang-format off
    int attribs[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, version.major,
        WGL_CONTEXT_MINOR_VERSION_ARB, version.minor,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        WGL_CONTEXT_FLAGS_ARB, 0,
        0
    };
    // clang-format on

    m_hglrc = opengl::wglCreateContextAttribsARB(m_hdc, 0, attribs);
    if (m_hglrc == nullptr) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't create HRC");
    }
}

win32_context::~win32_context()
{
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(m_hglrc);
    ReleaseDC(m_window, m_hdc);
}

bool win32_context::valid() const
{
    // TODO(alex) add more robust checks
    return m_hdc != nullptr && m_hglrc != nullptr;
}

bool win32_context::is_current() const
{
    return valid() && wglGetCurrentContext() == m_hglrc;
}

void win32_context::make_current() const
{
    if (!is_current()) {
        wglMakeCurrent(m_hdc, m_hglrc);
    }
}

void win32_context::swap_buffers() const
{
    SwapBuffers(m_hdc);
}

} // namespace framework::system
