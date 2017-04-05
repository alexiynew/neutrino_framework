/**
 * @file linux_canvas.hpp
 * @brief Canvas implementation for linux.
 * @author Fedorov Alexey
 * @date 05.04.2017
 */

#ifndef FRAMEWORK_CANVAS_LINUX_LINUX_CANVAS_HPP
#define FRAMEWORK_CANVAS_LINUX_LINUX_CANVAS_HPP

#include <X11/Xlib.h>
#include <canvas/canvas_implementation.hpp>

namespace framework {

class linux_canvas final : public canvas_implementation
{
public:
    linux_canvas(unsigned int width, unsigned int height);
    ~linux_canvas() override;

    void show() override;
    void hide() override;

private:
    unsigned int m_width;
    unsigned int m_height;

    Display* m_display;
    XID m_window;
};
}

#endif
