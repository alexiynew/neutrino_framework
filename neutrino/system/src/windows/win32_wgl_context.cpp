#include <array>
#include <stdexcept>
#include <tuple>
#include <vector>

#include <graphics/src/opengl/opengl.hpp>
#include <system/src/windows/wglext.hpp>
#include <system/src/windows/win32_application.hpp>
#include <system/src/windows/win32_wgl_context.hpp>

namespace
{
using PixelFormatValues = std::tuple<int, int, int>; // <depth_bits, stencil_bits, samples>

HWND create_tmp_window()
{
    using framework::system::details::Win32Application;

    DWORD style     = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    HWND tmp_window = CreateWindowEx(WS_EX_APPWINDOW,
                                     Win32Application::get_window_class(),
                                     L"TmpOpenGLInitWIndow",
                                     style,
                                     0,
                                     0,
                                     100,
                                     100,
                                     NULL,
                                     NULL,
                                     Win32Application::handle(),
                                     NULL);

    if (tmp_window == nullptr) {
        throw std::runtime_error("Failed to create tmp window for OpenGL initialization, error" +
                                 std::to_string(GetLastError()));
    }

    return tmp_window;
}

void init_wgl(const framework::system::details::wgl::GetFunction& get_function)
{
    HWND tmp_window = create_tmp_window();
    HDC hdc         = GetDC(tmp_window);

    if (hdc == nullptr) {
        DestroyWindow(tmp_window);
        throw std::runtime_error("GetDC failed, error: " + std::to_string(GetLastError()));
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;

    const int pixelFormat = ChoosePixelFormat(hdc, &pfd);

    if (pixelFormat == 0) {
        ReleaseDC(tmp_window, hdc);
        DestroyWindow(tmp_window);
        throw std::runtime_error("Can't choose pixel format, error: " + std::to_string(GetLastError()));
    }

    if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
        ReleaseDC(tmp_window, hdc);
        DestroyWindow(tmp_window);
        throw std::runtime_error("Can't set pixel format, error: " + std::to_string(GetLastError()));
    }

    HGLRC hglrc = wglCreateContext(hdc);
    if (hglrc == nullptr) {
        ReleaseDC(tmp_window, hdc);
        DestroyWindow(tmp_window);
        throw std::runtime_error("Can't create temporary graphic context, error: " + std::to_string(GetLastError()));
    }

    wglMakeCurrent(hdc, hglrc);

    framework::system::details::wgl::init_wgl(get_function);

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hglrc);
    ReleaseDC(tmp_window, hdc);
    DestroyWindow(tmp_window);
}

PixelFormatValues get_pixel_format_values(HDC hdc, int pixel_format)
{
    using namespace framework::system::details::wgl;

    constexpr static std::size_t size = std::tuple_size_v<PixelFormatValues>;

    constexpr static std::array<int, size> attribs = {WGL_DEPTH_BITS_ARB, WGL_STENCIL_BITS_ARB, WGL_SAMPLES_ARB};

    std::array<int, size> values = {0, 0, 0};
    if (!wglGetPixelFormatAttribivARB(hdc, pixel_format, 0, static_cast<UINT>(size), &attribs[0], &values[0])) {
        return PixelFormatValues(0, 0, 0);
    }

    return PixelFormatValues(values[0], values[1], values[2]);
}

int get_pixel_format(const framework::system::ContextSettings& settings, HDC hdc)
{
    using namespace framework::system::details::wgl;
    using framework::system::ContextSettings;

    std::vector<int> attribs;

    // OpenGL rendering
    attribs.push_back(WGL_SUPPORT_OPENGL_ARB);
    attribs.push_back(1);

    // Rendering to a window
    attribs.push_back(WGL_DRAW_TO_WINDOW_ARB);
    attribs.push_back(1);

    // Double buffer
    attribs.push_back(WGL_DOUBLE_BUFFER_ARB);
    attribs.push_back(1);

    // Swapping method
    attribs.push_back(WGL_SWAP_METHOD_ARB);
    attribs.push_back(WGL_SWAP_EXCHANGE_ARB);

    // Hardware acceleration
    attribs.push_back(WGL_ACCELERATION_ARB);
    attribs.push_back(WGL_FULL_ACCELERATION_ARB);

    // RGBA pixel type
    attribs.push_back(WGL_PIXEL_TYPE_ARB);
    attribs.push_back(WGL_TYPE_RGBA_ARB);

    // Support for 24 bit color
    attribs.push_back(WGL_COLOR_BITS_ARB);
    attribs.push_back(24);

    // The number of alpha bitplanes in each RGBA color buffer
    attribs.push_back(WGL_ALPHA_BITS_ARB);
    attribs.push_back(8);

    // Depth buffer
    if (settings.depth_bits() != ContextSettings::dont_care) {
        attribs.push_back(WGL_DEPTH_BITS_ARB);
        attribs.push_back(static_cast<int>(settings.depth_bits()));
    }

    // Stencil buffer
    if (settings.stencil_bits() != ContextSettings::dont_care) {
        attribs.push_back(WGL_STENCIL_BITS_ARB);
        attribs.push_back(static_cast<int>(settings.stencil_bits()));
    }

    // Multisampling
    if (settings.samples_count() != ContextSettings::dont_care) {
        attribs.push_back(WGL_SAMPLE_BUFFERS_ARB);
        attribs.push_back(1);
    }

    // End of attributes
    attribs.push_back(0);

    std::array<int, 100> pixel_formats = {};
    unsigned int formats_count         = 0;

    const bool pixel_format_found = wglChoosePixelFormatARB(hdc,
                                                            attribs.data(),
                                                            nullptr,
                                                            static_cast<UINT>(pixel_formats.size()),
                                                            pixel_formats.data(),
                                                            &formats_count);
    if (!pixel_format_found || formats_count == 0) {
        return 0;
    }

    if (settings.samples_count() == ContextSettings::dont_care) {
        return pixel_formats[0];
    }

    int best_pixel_format = 0;
    auto best_values      = PixelFormatValues(0, 0, 0);

    for (int pf : pixel_formats) {
        if (pf != 0) {
            const auto values = get_pixel_format_values(hdc, pf);

            if (values > best_values) {
                best_values       = values;
                best_pixel_format = pf;
            }
        }
    }

    return (best_pixel_format != 0 ? best_pixel_format : pixel_formats[0]);
}

HGLRC create_gl_context(const framework::system::ContextSettings& settings, HDC hdc)
{
    using namespace framework::system::details::wgl;
    using framework::system::ContextSettings;

    std::vector<int> contextAttribs;

    contextAttribs.push_back(WGL_CONTEXT_MAJOR_VERSION_ARB);
    contextAttribs.push_back(settings.version().major());

    contextAttribs.push_back(WGL_CONTEXT_MINOR_VERSION_ARB);
    contextAttribs.push_back(settings.version().minor());

    contextAttribs.push_back(WGL_CONTEXT_PROFILE_MASK_ARB);
    contextAttribs.push_back(WGL_CONTEXT_CORE_PROFILE_BIT_ARB);

    // End of attributes
    contextAttribs.push_back(0);

    return wglCreateContextAttribsARB(hdc, nullptr, contextAttribs.data());
}

framework::system::ContextSettings get_actual_context_settings(HDC hdc, int pixel_format)
{
    using framework::system::ContextSettings;

    const auto& [depth_bits, stencil_bits, samples_count] = get_pixel_format_values(hdc, pixel_format);

    ContextSettings settings;
    settings.depth_bits(depth_bits);
    settings.stencil_bits(stencil_bits);
    settings.samples_count(samples_count);

    return settings;
}

} // namespace

namespace framework::system::details
{
Win32WglContext::Win32WglContext(HWND window, const ContextSettings& settings)
    : Context(settings)
    , m_window(window)
{
    init_wgl([this](const char* function_name) { return get_function(function_name); });

    if (!wgl::is_supported(wgl::Extension::WGL_ARB_create_context)) {
        throw std::runtime_error("WGL_ARB_create_context not supported");
    }
    if (!wgl::is_supported(wgl::Extension::WGL_ARB_pixel_format)) {
        throw std::runtime_error("WGL_ARB_pixel_format not supported");
    }

    m_hdc = GetDC(m_window);

    const int pixel_format = get_pixel_format(settings, m_hdc);

    if (pixel_format == 0) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't get a suitable pixel format, error: " + std::to_string(GetLastError()));
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);

    if (!SetPixelFormat(m_hdc, pixel_format, &pfd)) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Can't set pixel format, error: " + std::to_string(GetLastError()));
    }

    m_hglrc = create_gl_context(settings, m_hdc);
    if (m_hglrc == nullptr) {
        ReleaseDC(m_window, m_hdc);
        throw std::runtime_error("Failed to create OpenGL context, error: " + std::to_string(GetLastError()));
    }

    make_current();
    framework::graphics::details::opengl::init_opengl([this](const char* f) { return get_function(f); });

    ContextSettings actual_settings = get_actual_context_settings(m_hdc, pixel_format);
    actual_settings.version(settings.version()); // Can't get actual OpenGL version, so just copy requested one.
    update_settings(actual_settings);
}

Win32WglContext::~Win32WglContext()
{
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(m_hglrc);
    ReleaseDC(m_window, m_hdc);
}

bool Win32WglContext::valid() const
{
    return m_window != nullptr || m_hdc != nullptr || m_hglrc != nullptr;
}

bool Win32WglContext::is_current() const
{
    return valid() && wglGetCurrentContext() == m_hglrc;
}

Context::Api Win32WglContext::api_type() const
{
    return Context::Api::opengl;
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

Win32WglContext::VoidFunctionPtr Win32WglContext::get_function(const char* function_name) const
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
