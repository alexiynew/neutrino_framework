#ifndef FRAMEWORK_SYSTEM_DETAILS_LINUX_X11_GLX_CONTEXT_HPP
#define FRAMEWORK_SYSTEM_DETAILS_LINUX_X11_GLX_CONTEXT_HPP

#include <system/context.hpp>

#include <system/src/linux/glxext.hpp>

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
    X11GlxContext& operator=(X11GlxContext&&) = default;

    bool valid() const override;
    bool is_current() const override;
    Api api_type() const override;

    VoidFunctionPtr get_function(const char* function_name) const override;

    void make_current() override;
    void swap_buffers() override;

    Colormap colormap() const;
    XVisualInfo* visual_info() const;

    void attach_window(Window window);

private:
    Display* m_display         = nullptr;
    Colormap m_colormap        = None;
    XVisualInfo* m_visual_info = nullptr;
    Window m_window            = None;

    glx::GLXFBConfig m_framebuffer_config = nullptr;
    glx::GLXContext m_glx_context         = nullptr;

    void clear();
};

} // namespace framework::system::details

#endif
