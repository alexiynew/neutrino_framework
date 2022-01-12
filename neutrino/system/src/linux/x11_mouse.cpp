#include <system/src/linux/x11_mouse.hpp>

#include <X11/Xlib.h>

namespace framework::system::details
{
mouse_button map_mouse_button(uint32 button)
{
    switch (button) {
        case Button1: return mouse_button::button_left;
        case Button2: return mouse_button::button_middle;
        case Button3: return mouse_button::button_right;
        case Button4: return mouse_button::button_unknown; // whell up
        case Button5: return mouse_button::button_unknown; // whell down
    }

    return mouse_button::button_unknown;
}

} // namespace framework::system::details
