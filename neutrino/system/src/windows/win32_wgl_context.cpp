// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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
Win32WglContext::Win32WglContext(HWND window, const ContextSettings& settings)
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

    std::vector<int> attribs;

    // OpenGL rendering
    attribs.push_back(wgl::WGL_SUPPORT_OPENGL_ARB);
    attribs.push_back(1);

    // Rendering to a window
    attribs.push_back(wgl::WGL_DRAW_TO_WINDOW_ARB);
    attribs.push_back(1);

    // Double buffer
    attribs.push_back(wgl::WGL_DOUBLE_BUFFER_ARB);
    attribs.push_back(1);

    // Swapping method
    attribs.push_back(wgl::WGL_SWAP_METHOD_ARB);
    attribs.push_back(wgl::WGL_SWAP_EXCHANGE_ARB);

    // Hardware acceleration
    attribs.push_back(wgl::WGL_ACCELERATION_ARB);
    attribs.push_back(wgl::WGL_FULL_ACCELERATION_ARB);

    // RGBA pixel type
    attribs.push_back(wgl::WGL_PIXEL_TYPE_ARB);
    attribs.push_back(wgl::WGL_TYPE_RGBA_ARB);

    // Support for 24 bit color
    attribs.push_back(wgl::WGL_COLOR_BITS_ARB);
    attribs.push_back(24);

    // The number of alpha bitplanes in each RGBA color buffer
    attribs.push_back(wgl::WGL_ALPHA_BITS_ARB);
    attribs.push_back(8);

    // Depth buffer
    attribs.push_back(wgl::WGL_DEPTH_BITS_ARB);
    attribs.push_back(static_cast<int>(settings.depth_bits()));

    // Stencil buffer
    attribs.push_back(wgl::WGL_STENCIL_BITS_ARB);
    attribs.push_back(static_cast<int>(settings.stencil_bits()));

    // Antialiasing
    if (settings.antialiasing_level() == ContextSettings::Antialiasing::best) {
        attribs.push_back(wgl::WGL_SAMPLE_BUFFERS_ARB);
        attribs.push_back(1);

        attribs.push_back(wgl::WGL_SAMPLES_ARB);
        attribs.push_back(32);
    }

    // End of attributes
    attribs.push_back(0);

    m_hdc = GetDC(m_window);

    int pixelFormat               = 0;
    unsigned int formatCount      = 0;
    const bool pixel_format_found = wgl::wglChoosePixelFormatARB(m_hdc,
                                                                 attribs.data(),
                                                                 nullptr,
                                                                 1,
                                                                 &pixelFormat,
                                                                 &formatCount);
    if (!pixel_format_found) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't get a suitable pixel format");
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);

    if (!SetPixelFormat(m_hdc, pixelFormat, &pfd)) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't set pixel format");
    }

    std::vector<int> contextAttribs;

    contextAttribs.push_back(wgl::WGL_CONTEXT_MAJOR_VERSION_ARB);
    contextAttribs.push_back(settings.version().major());

    contextAttribs.push_back(wgl::WGL_CONTEXT_MINOR_VERSION_ARB);
    contextAttribs.push_back(settings.version().minor());

    contextAttribs.push_back(wgl::WGL_CONTEXT_PROFILE_MASK_ARB);
    contextAttribs.push_back(wgl::WGL_CONTEXT_CORE_PROFILE_BIT_ARB);

    if (settings.version().major() >= 3) {
        contextAttribs.push_back(wgl::WGL_CONTEXT_FLAGS_ARB);
        contextAttribs.push_back(wgl::WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB);
    }

    // End of attributes
    contextAttribs.push_back(0);

    // TODO: Update actual context settings

    m_hglrc = wgl::wglCreateContextAttribsARB(m_hdc, nullptr, contextAttribs.data());
    if (m_hglrc == nullptr) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Failed to create OpenGL context");
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

void Win32WglContext::make_current()
{
    if (!is_current()) {
        wglMakeCurrent(m_hdc, m_hglrc);
    }
}

void Win32WglContext::swap_buffers()
{
    SwapBuffers(m_hdc);
}

} // namespace framework::system::details
