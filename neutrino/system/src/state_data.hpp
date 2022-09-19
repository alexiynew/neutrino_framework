#ifndef SYSTEM_SRC_STATE_DATA_HPP
#define SYSTEM_SRC_STATE_DATA_HPP

#include <system/window.hpp>

namespace framework::system::details
{

struct StateData
{
    bool should_close = false;

    bool mouse_hover     = false;
    bool cursor_visible  = true;
    bool cursor_captured = false;

    Window::State state = Window::State::normal;
};

} // namespace framework::system::details

#endif