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

glx::GLXFBConfig find_best_config(Display* display, std::uint32_t samples_count, glx::GLXFBConfig* configs, int count)
{
    using namespace glx;

    if (samples_count == ContextSettings::dont_care && count > 0) {
        return configs[0];
    }

    int best         = -1;
    int best_samples = -1;

    for (int i = 0; i < count; ++i) {
        int sample_buffer;
        int samples;
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLE_BUFFERS, &sample_buffer);
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLES, &samples);

        if (best < 0 || (sample_buffer != 0 && samples > best_samples)) {
            best         = i;
            best_samples = samples;
        }
    }

    return configs[best];
}

glx::GLXFBConfig choose_framebuffer_config(Display* display, const ContextSettings& settings)
{
    using namespace glx;

    std::vector<int> attribs;

    // Render to Windows and/or GLX pixmaps
    attribs.push_back(GLX_X_RENDERABLE);
    attribs.push_back(True);

    // Render to window
    attribs.push_back(GLX_DRAWABLE_TYPE);
    attribs.push_back(GLX_WINDOW_BIT);

    // RGBA context
    attribs.push_back(GLX_RENDER_TYPE);
    attribs.push_back(GLX_RGBA_BIT);

    // Double-buffered frame buffer
    attribs.push_back(GLX_DOUBLEBUFFER);
    attribs.push_back(True);

    // Truecolor support
    attribs.push_back(GLX_X_VISUAL_TYPE);
    attribs.push_back(GLX_TRUE_COLOR);

    // Red bits size
    attribs.push_back(GLX_RED_SIZE);
    attribs.push_back(8);

    // Green bits size
    attribs.push_back(GLX_GREEN_SIZE);
    attribs.push_back(8);

    // Blue bits size
    attribs.push_back(GLX_BLUE_SIZE);
    attribs.push_back(8);

    // Alpha bits size
    attribs.push_back(GLX_ALPHA_SIZE);
    attribs.push_back(8);

    // Depth buffer
    if (settings.depth_bits() != ContextSettings::dont_care) {
        attribs.push_back(GLX_DEPTH_SIZE);
        attribs.push_back(std::min(ContextSettings::default_max_depth_bits, settings.depth_bits()));
    }

    // Stencil buffer
    if (settings.stencil_bits() != ContextSettings::dont_care) {
        attribs.push_back(GLX_STENCIL_SIZE);
        attribs.push_back(std::min(ContextSettings::default_max_stencil_bits, settings.stencil_bits()));
    }

    attribs.push_back(None);

    int count = 0;

    GLXFBConfig* configs = glXChooseFBConfig(display, DefaultScreen(display), attribs.data(), &count);
    if (configs == nullptr) {
        return nullptr;
    }

    GLXFBConfig best_config = find_best_config(display, settings.samples_count(), configs, count);

    XFree(configs);

    return best_config;
}

glx::GLXContext create_glx_context(Display* display, glx::GLXFBConfig fb_config, const ContextSettings& settings)
{
    using namespace glx;

    if (!is_supported(Extension::GLX_ARB_create_context)) {
        return nullptr;
    }

    std::vector<int> attribs;

    attribs.push_back(GLX_CONTEXT_MAJOR_VERSION_ARB);
    attribs.push_back(settings.version().major());

    attribs.push_back(GLX_CONTEXT_MINOR_VERSION_ARB);
    attribs.push_back(settings.version().minor());

    attribs.push_back(GLX_CONTEXT_FLAGS_ARB);
    attribs.push_back(GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB);

    attribs.push_back(None);

    return glXCreateContextAttribsARB(display, fb_config, nullptr, True, attribs.data());
}

} // namespace

namespace framework::system::details
{
X11GlxContext::X11GlxContext(const ContextSettings& settings, Display* display)
    : Context(settings)
    , m_display(display)
{
    using namespace glx;
    using namespace framework::graphics::details::opengl;

    init_glx([this](const char* name) { return get_function(name); });

    if (!check_glx_version(m_display)) {
        throw std::runtime_error("Invalid GLX version.");
    }

    const GLXFBConfig fb_config = choose_framebuffer_config(m_display, settings);

    if (fb_config == nullptr) {
        throw std::runtime_error("Can't get framebuffer config.");
    }

    m_visual_info = glXGetVisualFromFBConfig(m_display, fb_config);
    if (m_visual_info == nullptr) {
        clear();
        throw std::runtime_error("Can't get visual info.");
    }

    m_glx_context = create_glx_context(m_display, fb_config, settings);
    if (m_glx_context == nullptr) {
        clear();
        throw std::runtime_error("Can't create opengl context.");
    }

    init_opengl([this](const char* name) { return get_function(name); });

    // TODO: Update actual context settings
}

X11GlxContext::~X11GlxContext()
{
    clear();
}

bool X11GlxContext::is_valid() const
{
    return m_display != nullptr && m_glx_context != nullptr && m_visual_info != nullptr && m_window != None;
}

bool X11GlxContext::is_current() const
{
    return glx::glXGetCurrentContext() == m_glx_context;
}

Context::Api X11GlxContext::api_type() const
{
    return Context::Api::opengl;
}

void X11GlxContext::make_current()
{
    if (!is_valid()) {
        return;
    }

    glx::glXMakeCurrent(m_display, m_window, m_glx_context);
}

void X11GlxContext::swap_buffers()
{
    if (!is_valid()) {
        return;
    }

    glx::glXSwapBuffers(m_display, m_window);
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

    if (m_visual_info) {
        XFree(m_visual_info);
    }

    m_window = None;
}

glx::VoidFunctionPtr X11GlxContext::get_function(const char* function_name) const
{
    return glx::get_function(function_name);
}

} // namespace framework::system::details
