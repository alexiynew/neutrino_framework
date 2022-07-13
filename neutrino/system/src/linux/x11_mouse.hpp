#ifndef FRAMEWORK_WINDOW_DETAILS_X11_MOUSE_HPP
#define FRAMEWORK_WINDOW_DETAILS_X11_MOUSE_HPP

#include <cstdint>

#include <system/mouse.hpp>

namespace framework::system::details
{
MouseButton map_mouse_button(std::uint32_t button);

} // namespace framework::system::details

#endif
