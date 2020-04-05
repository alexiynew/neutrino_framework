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

#include <stdexcept>

#include <system/src/windows/wglext.hpp>
#include <system/src/windows/win32_wgl_context.hpp>

namespace
{
void init_wgl(HWND window, const framework::system::details::wgl::GetFunction& get_function)
{
    HDC hdc = GetDC(window);

    if (hdc == nullptr) {
        throw std::runtime_error("GetDC failed!");
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);

    if (pixelFormat == 0) {
        ReleaseDC(window, hdc);
        throw std::runtime_error("Can't choose pixel format");
    }

    if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
        ReleaseDC(window, hdc);
        throw std::runtime_error("Can't set pixel format");
    }

    HGLRC hglrc = wglCreateContext(hdc);
    if (hglrc == nullptr) {
        ReleaseDC(window, hdc);
        throw std::runtime_error("Can't create temporary graphic context");
    }

    wglMakeCurrent(hdc, hglrc);

    framework::system::details::wgl::init_wgl(get_function);

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hglrc);
    ReleaseDC(window, hdc);
}
} // namespace

namespace framework::system::details
{
Win32WglContext::Win32WglContext(const ContextSettings& settings, HWND window)
    : Context(settings)
    , m_window(window)
{
    init_wgl(m_window, [this](const char* function_name) { return get_function(function_name); });

    if (!wgl::is_supported(wgl::Extension::WGL_ARB_create_context)) {
        throw std::runtime_error("WGL_ARB_create_context not supported");
    }
    if (!wgl::is_supported(wgl::Extension::WGL_ARB_pixel_format)) {
        throw std::runtime_error("WGL_ARB_pixel_format not supported");
    }

    m_hdc = GetDC(m_window);

    // clang-format off
    int pixel_format_attribs [] = {
        wgl::WGL_SUPPORT_OPENGL_ARB, TRUE,                          // Support for OpenGL rendering.
        wgl::WGL_DRAW_TO_WINDOW_ARB, TRUE,                          // Support for rendering to a window.
        wgl::WGL_ACCELERATION_ARB, wgl::WGL_FULL_ACCELERATION_ARB,  // Support for hardware acceleration.
        wgl::WGL_COLOR_BITS_ARB, 24,                                // Support for 24 bit color.
        wgl::WGL_DEPTH_BITS_ARB, 24,                                // Support for 24 bit depth buffer.
        wgl::WGL_DOUBLE_BUFFER_ARB, TRUE,                           // Support for double buffer.
        wgl::WGL_SWAP_METHOD_ARB, wgl::WGL_SWAP_EXCHANGE_ARB,       // Support for swapping front and back buffer.
        wgl::WGL_PIXEL_TYPE_ARB, wgl::WGL_TYPE_RGBA_ARB,            // Support for the RGBA pixel type.
        wgl::WGL_STENCIL_BITS_ARB, 8,                               // Support for a 8 bit stencil buffer.
	    0
    };
    // clang-format on

    int pixelFormat;
    unsigned int formatCount;
    bool pixel_format_found = wgl::wglChoosePixelFormatARB(m_hdc,
                                                           pixel_format_attribs,
                                                           nullptr,
                                                           1,
                                                           &pixelFormat,
                                                           &formatCount);
    if (!pixel_format_found) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't choose pixel format");
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);

    if (!SetPixelFormat(m_hdc, pixelFormat, &pfd)) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't set pixel format");
    }

    auto version = settings.version();
    // clang-format off
    int attribs[] = {
        wgl::WGL_CONTEXT_MAJOR_VERSION_ARB, version.major_version,
        wgl::WGL_CONTEXT_MINOR_VERSION_ARB, version.minor_version,
        wgl::WGL_CONTEXT_PROFILE_MASK_ARB, wgl::WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        wgl::WGL_CONTEXT_FLAGS_ARB, 0,
        0
    };
    // clang-format on

    m_hglrc = wgl::wglCreateContextAttribsARB(m_hdc, 0, attribs);
    if (m_hglrc == nullptr) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't create HRC");
    }
}

Win32WglContext::~Win32WglContext()
{
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(m_hglrc);
    ReleaseDC(m_window, m_hdc);
}

bool Win32WglContext::valid() const
{
    // TODO(alex) add more robust checks
    return m_hdc != nullptr && m_hglrc != nullptr;
}

bool Win32WglContext::is_current() const
{
    return valid() && wglGetCurrentContext() == m_hglrc;
}

void Win32WglContext::make_current() const
{
    if (!is_current()) {
        wglMakeCurrent(m_hdc, m_hglrc);
    }
}

void Win32WglContext::swap_buffers() const
{
    SwapBuffers(m_hdc);
}

Context::Api Win32WglContext::api_type() const
{
    return Context::Api::opengl;
}

Context::VoidFunctionPtr Win32WglContext::get_function(const char* function_name) const
{
    auto function = reinterpret_cast<VoidFunctionPtr>(wglGetProcAddress(function_name));
    if (function == nullptr || (function == reinterpret_cast<VoidFunctionPtr>(0x1)) ||
        (function == reinterpret_cast<VoidFunctionPtr>(0x2)) || (function == reinterpret_cast<VoidFunctionPtr>(0x3)) ||
        (function == reinterpret_cast<VoidFunctionPtr>(-1))) {
        HMODULE module = LoadLibrary(L"opengl32.dll");
        if (module != nullptr) {
            function = reinterpret_cast<VoidFunctionPtr>(GetProcAddress(module, function_name));
        } else {
            function = nullptr;
        }
    }

    return function;
}

} // namespace framework::system::details
