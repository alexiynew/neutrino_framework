/// @file
/// @brief Window implementation for linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP

#include <X11/Xlib.h>
#include <window/window_implementation.hpp>

namespace framework {

class x11_window final : public window_implementation
{
public:
    x11_window();
    ~x11_window() override;

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
