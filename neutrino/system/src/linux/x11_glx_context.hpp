#ifndef FRAMEWORK_SYSTEM_DETAILS_LINUX_X11_GLX_CONTEXT_HPP
#define FRAMEWORK_SYSTEM_DETAILS_LINUX_X11_GLX_CONTEXT_HPP

#include <system/src/context.hpp>

#include <X11/Xlib.h>
#include <gl/glxext.hpp>

namespace framework::system::details
{
class x11_glx_context : public context
{
public:
    x11_glx_context(const context_settings& settings, Display* display);
    ~x11_glx_context() override;

    x11_glx_context(const x11_glx_context&) = default;
    x11_glx_context(x11_glx_context&&)      = default;

    x11_glx_context& operator=(const x11_glx_context&) = default;
    x11_glx_context& operator=(x11_glx_context&&) = default;

    bool valid() const override;
    bool is_current() const override;

    void make_current() const override;
    void swap_buffers() const override;

    Colormap colormap() const;
    XVisualInfo* visual_info() const;

    void attach_window(Window window);

private:
    Display* m_display               = nullptr;
    GLXFBConfig m_framebuffer_config = nullptr;
    GLXContext m_glx_context         = nullptr;
    Colormap m_colormap              = None;
    XVisualInfo* m_visual_info       = nullptr;
    Window m_window                  = None;

    void clear();
};

} // namespace framework::system::details

#endif
