#include <system/src/linux/x11_mouse.hpp>

#include <X11/Xlib.h>

namespace neutrino::system::details
{
MouseButton map_mouse_button(std::uint32_t button)
{
    switch (button) {
        case Button1: return MouseButton::button_left;
        case Button2: return MouseButton::button_middle;
        case Button3: return MouseButton::button_right;
        case Button4: return MouseButton::unknown; // whell up
        case Button5: return MouseButton::unknown; // whell down
    }

    return MouseButton::unknown;
}

} // namespace neutrino::system::details
