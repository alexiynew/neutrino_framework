/// @file
/// @brief OpneGL canvas implementation fot Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_GRAPHIC_OPENGL_CANVAS_LINUX_X11_OPENGL_CANVAS_HPP
#define FRAMEWORK_GRAPHIC_OPENGL_CANVAS_LINUX_X11_OPENGL_CANVAS_HPP

#include <GL/glx.h>
#include <X11/Xlib.h>

#include <graphic/opengl/canvas/implementation.hpp>
#include <graphic/window.hpp>
#include <graphic/window/linux/x11_server.hpp>

namespace framework
{
namespace graphic
{
class x11_opengl_canvas : public opengl_canvas::implementation
{
public:
    explicit x11_opengl_canvas(Display* display, const Window& window);
    ~x11_opengl_canvas() override;

    void make_current() override;
    void swap_buffers() override;

private:
    Display* m_display;
    Window m_window;
    GLXContext m_context;
};

} // namespace graphic

} // namespace framework

#endif
