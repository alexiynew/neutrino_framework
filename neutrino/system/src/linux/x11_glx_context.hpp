#ifndef FRAMEWORK_SYSTEM_DETAILS_LINUX_X11_GLX_CONTEXT_HPP
#define FRAMEWORK_SYSTEM_DETAILS_LINUX_X11_GLX_CONTEXT_HPP

#include <system/context.hpp>

#include <system/src/linux/glxext.hpp>
#include <system/src/linux/x11_glx_get_function.hpp>

#include <X11/Xlib.h>

namespace framework::system::details
{
class X11GlxContext final : public Context
{
public:
    X11GlxContext(const ContextSettings& settings, Display* display);
    ~X11GlxContext() override;

    X11GlxContext(const X11GlxContext&) = default;
    X11GlxContext(X11GlxContext&&)      = default;

    X11GlxContext& operator=(const X11GlxContext&) = default;
    X11GlxContext& operator=(X11GlxContext&&)      = default;

    bool valid() const override;
    bool is_current() const override;
    Api api_type() const override;

    void make_current() override;
    void swap_buffers() override;

    Colormap colormap() const;
    XVisualInfo* visual_info() const;

    void attach_window(Window window);

private:
    void clear();

    glx::VoidFunctionPtr get_function(const char* function_name) const;

    Display* m_display         = nullptr;
    Colormap m_colormap        = None;
    XVisualInfo* m_visual_info = nullptr;
    Window m_window            = None;

    glx::GLXFBConfig m_framebuffer_config = nullptr;
    glx::GLXContext m_glx_context         = nullptr;
};

} // namespace framework::system::details

#endif
