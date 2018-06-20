/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#include <set>
#include <string>

#include <graphic/opengl/canvas/linux/x11_opengl_canvas.hpp>
#include <graphic/window/linux/x11_server.hpp>

namespace
{
using namespace framework;

const int32 glx_min_major_version = 1;
const int32 glx_min_minor_version = 4;

bool check_glx_version(Display* display)
{
    int32 glx_major = 0;
    int32 glx_minor = 0;

    glXQueryVersion(display, &glx_major, &glx_minor);

    return glx_major >= glx_min_major_version && glx_minor >= glx_min_minor_version;
}

GLXFBConfig choose_framebuffer_config(Display* display)
{
    // clang-format off
    static int32 visual_attribs[] = {
        GLX_X_RENDERABLE,  True,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_RENDER_TYPE,   GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
        GLX_RED_SIZE,      8,
        GLX_GREEN_SIZE,    8,
        GLX_BLUE_SIZE,     8,
        GLX_ALPHA_SIZE,    8,
        GLX_DEPTH_SIZE,    24,
        GLX_STENCIL_SIZE,  8,
        GLX_DOUBLEBUFFER,  True,
        None};
    // clang-format on

    int32 count;
    GLXFBConfig* configs = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &count);
    if (!configs) {
        return nullptr;
    }

    int32 best         = -1;
    int32 best_samples = -1;

    for (int32 i = 0; i < count; ++i) {
        int32 sample_buffer;
        int32 samples;
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLE_BUFFERS, &sample_buffer);
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLES, &samples);

        if (best < 0 || (sample_buffer && samples > best_samples)) {
            best         = i;
            best_samples = samples;
        }
    }

    GLXFBConfig best_config = configs[best];

    XFree(configs);

    return best_config;
}

bool set_colormap(Display* display, Window& window, GLXFBConfig framebuffer_config)
{
    XVisualInfo* visual_info = glXGetVisualFromFBConfig(display, framebuffer_config);

    if (!visual_info) {
        return false;
    }

    Colormap colormap = XCreateColormap(display, window, visual_info->visual, AllocNone);
    XSetWindowColormap(display, window, colormap);

    XFree(visual_info);

    return true;
}

template <typename F>
F get_function(const char* function_name)
{
    return reinterpret_cast<F>(glXGetProcAddressARB(reinterpret_cast<const GLubyte*>(function_name)));
}

std::set<std::string> split(const std::string& string, const std::string& delimeter)
{
    std::set<std::string> values;

    size_t begin = 0;
    size_t end   = string.find(delimeter, begin);

    while (end != std::string::npos && end > begin) {
        values.insert(string.substr(begin, end - begin));

        begin = end + delimeter.size();
        end   = string.find(delimeter, begin);
    }

    if (begin < string.size()) {
        values.insert(string.substr(begin, string.size() - begin));
    }

    return values;
}

std::set<std::string> get_glx_extensions(Display* display)
{
    const char* extensions = glXQueryExtensionsString(display, DefaultScreen(display));

    if (!extensions) {
        return std::set<std::string>();
    }

    return split(extensions, " ");
}

bool is_glx_extension_supported(Display* display, const std::string& extension)
{
    static std::set<std::string> extensions = get_glx_extensions(display);

    return extensions.count(extension) > 0;
}

GLXContext create_context(Display* display, GLXFBConfig framebuffer_config)
{
    auto glXCreateContextAttribsARB = get_function<PFNGLXCREATECONTEXTATTRIBSARBPROC>("glXCreateContextAttribsARB");

    if (!is_glx_extension_supported(display, "GLX_ARB_create_context") || !glXCreateContextAttribsARB) {
        return nullptr;
    }

    // clang-format off
    int32 context_attribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
        GLX_CONTEXT_MINOR_VERSION_ARB, 0,
        GLX_CONTEXT_FLAGS_ARB        , GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
        None};
    // clang-format on

    return glXCreateContextAttribsARB(display, framebuffer_config, 0, True, context_attribs);
}

} // namespace

namespace framework
{
namespace graphic
{
std::unique_ptr<opengl_canvas::implementation> opengl_canvas::implementation::create(
const ::framework::graphic::window& window)
{
    Display* display      = x11_server::connect()->display();
    Window window_handler = static_cast<Window>(window.native_handler());

    return std::make_unique<x11_opengl_canvas>(display, window_handler);
}

x11_opengl_canvas::x11_opengl_canvas(Display* display, const Window& window) : m_display(display), m_window(window)
{
    if (!check_glx_version(m_display)) {
        throw std::runtime_error("Invalid GLX version.");
    }

    GLXFBConfig framebuffer_config = choose_framebuffer_config(display);

    if (!framebuffer_config) {
        throw std::runtime_error("Can't get framebuffer config.");
    }

    if (!set_colormap(m_display, m_window, framebuffer_config)) {
        throw std::runtime_error("Can't get visual info for framebuffer config.");
    }

    m_context = create_context(m_display, framebuffer_config);

    if (!m_context) {
        throw std::runtime_error("Can't create OpenGL context.");
    }

    // init gl
    /*

        // Sync to ensure any errors generated are processed.
        XSync(display, False);

        // Verifying that context is a direct context
        if (!glXIsDirect(display, ctx)) {
            printf("Indirect GLX rendering context obtained\n");
        } else {
            printf("Direct GLX rendering context obtained\n");
        }

        printf("Making context current\n");
        glXMakeCurrent(display, win, ctx);

        glClearColor(0, 0.5, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glXSwapBuffers(display, win);

        sleep(1);

        glClearColor(1, 0.5, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glXSwapBuffers(display, win);

        sleep(1);

        glXDestroyContext(display, ctx);

        XDestroyWindow(display, win);
        XFreeColormap(display, cmap);
        XCloseDisplay(display);
    */
}

x11_opengl_canvas::~x11_opengl_canvas() = default;

void x11_opengl_canvas::make_current()
{
    glXMakeCurrent(m_display, m_window, m_context);
}

void x11_opengl_canvas::swap_buffers()
{}

} // namespace graphic

} // namespace framework
