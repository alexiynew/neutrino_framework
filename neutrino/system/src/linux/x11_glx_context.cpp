#include <stdexcept>
#include <vector>

#include <graphics/src/opengl/opengl.hpp>
#include <system/src/linux/x11_glx_context.hpp>
#include <system/src/linux/x11_glx_get_function.hpp>

namespace glx = framework::system::details::glx;
namespace
{
using framework::system::ContextSettings;

static constexpr int glx_min_major_version = 1;
static constexpr int glx_min_minor_version = 4;

bool check_glx_version(Display* display)
{
    int glx_major = 0;
    int glx_minor = 0;

    glx::glXQueryVersion(display, &glx_major, &glx_minor);

    return glx_major >= glx_min_major_version && glx_minor >= glx_min_minor_version;
}

glx::GLXFBConfig find_best_config(Display* display,
                                  ContextSettings::Antialiasing antialasing_level,
                                  glx::GLXFBConfig* configs,
                                  int count)
{
    using namespace framework::system::details::glx;

    if (antialasing_level == ContextSettings::Antialiasing::dont_care && count > 0) {
        return configs[0];
    }

    int best         = -1;
    int best_samples = -1;

    for (int i = 0; i < count; ++i) {
        int sample_buffer;
        int samples;
        glx::glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLE_BUFFERS, &sample_buffer);
        glx::glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLES, &samples);

        if (best < 0 || (sample_buffer != 0 && samples > best_samples)) {
            best         = i;
            best_samples = samples;
        }
    }

    return configs[best];
}

glx::GLXFBConfig choose_framebuffer_config(Display* display, const ContextSettings& settings)
{
    std::vector<int> attribs;

    attribs.push_back(glx::GLX_X_RENDERABLE);
    attribs.push_back(True);

    attribs.push_back(glx::GLX_DRAWABLE_TYPE);
    attribs.push_back(glx::GLX_WINDOW_BIT);

    attribs.push_back(glx::GLX_RENDER_TYPE);
    attribs.push_back(glx::GLX_RGBA_BIT);

    attribs.push_back(glx::GLX_X_VISUAL_TYPE);
    attribs.push_back(glx::GLX_TRUE_COLOR);

    attribs.push_back(glx::GLX_RED_SIZE);
    attribs.push_back(8);

    attribs.push_back(glx::GLX_GREEN_SIZE);
    attribs.push_back(8);

    attribs.push_back(glx::GLX_BLUE_SIZE);
    attribs.push_back(8);

    attribs.push_back(glx::GLX_ALPHA_SIZE);
    attribs.push_back(8);

    attribs.push_back(glx::GLX_DEPTH_SIZE);
    attribs.push_back(settings.depth_bits());

    attribs.push_back(glx::GLX_STENCIL_SIZE);
    attribs.push_back(settings.stencil_bits());

    attribs.push_back(glx::GLX_DOUBLEBUFFER);
    attribs.push_back(True);

    attribs.push_back(None);

    int count = 0;

    glx::GLXFBConfig* configs = glx::glXChooseFBConfig(display, DefaultScreen(display), attribs.data(), &count);
    if (configs == nullptr) {
        return nullptr;
    }

    glx::GLXFBConfig best_config = find_best_config(display, settings.antialiasing_level(), configs, count);

    XFree(configs);

    return best_config;
}

glx::GLXContext create_glx_context(Display* display,
                                   glx::GLXFBConfig framebuffer_config,
                                   const ContextSettings& settings)
{
    if (!is_supported(glx::Extension::GLX_ARB_create_context)) {
        return nullptr;
    }

    std::vector<int> attribs;

    attribs.push_back(glx::GLX_CONTEXT_MAJOR_VERSION_ARB);
    attribs.push_back(settings.version().major());

    attribs.push_back(glx::GLX_CONTEXT_MINOR_VERSION_ARB);
    attribs.push_back(settings.version().minor());

    attribs.push_back(glx::GLX_CONTEXT_FLAGS_ARB);
    attribs.push_back(glx::GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB);

    attribs.push_back(None);

    return glx::glXCreateContextAttribsARB(display, framebuffer_config, nullptr, True, attribs.data());
}

} // namespace

namespace framework::system::details
{
X11GlxContext::X11GlxContext(const ContextSettings& settings, Display* display)
    : Context(settings)
    , m_display(display)
{
    glx::init_glx([this](const char* function_name) { return get_function(function_name); });

    if (!check_glx_version(m_display)) {
        throw std::runtime_error("Invalid GLX version.");
    }

    m_framebuffer_config = choose_framebuffer_config(m_display, settings);

    if (m_framebuffer_config == nullptr) {
        throw std::runtime_error("Can't get framebuffer config.");
    }

    m_visual_info = glx::glXGetVisualFromFBConfig(m_display, m_framebuffer_config);
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

    framework::graphics::details::opengl::init_opengl([this](const char* f) { return get_function(f); });

    // TODO: Update actual context settings
}

X11GlxContext::~X11GlxContext()
{
    clear();
}

bool X11GlxContext::valid() const
{
    return m_display != nullptr && m_framebuffer_config != nullptr && m_glx_context != nullptr && m_colormap != None &&
           m_visual_info != nullptr;
}

bool X11GlxContext::is_current() const
{
    return valid() && glx::glXGetCurrentContext() == m_glx_context;
}

Context::Api X11GlxContext::api_type() const
{
    return Context::Api::opengl;
}

void X11GlxContext::make_current()
{
    if (!is_current()) {
        glx::glXMakeCurrent(m_display, m_window, m_glx_context);
    }
}

void X11GlxContext::swap_buffers()
{
    glx::glXSwapBuffers(m_display, m_window);
}

Colormap X11GlxContext::colormap() const
{
    return m_colormap;
}

XVisualInfo* X11GlxContext::visual_info() const
{
    return m_visual_info;
}

void X11GlxContext::attach_window(Window window)
{
    m_window = window;
}

void X11GlxContext::clear()
{
    if (m_display && m_glx_context != nullptr) {
        glx::glXDestroyContext(m_display, m_glx_context);
    }

    if (m_display && m_colormap != 0u) {
        XFreeColormap(m_display, m_colormap);
    }

    if (m_visual_info) {
        XFree(m_visual_info);
    }
}

X11GlxContext::VoidFunctionPtr X11GlxContext::get_function(const char* function_name) const
{
    return glx::get_function(function_name);
}

} // namespace framework::system::details
