#ifndef FRAMEWORK_WINDOW_DETAILS_X11_MOUSE_HPP
#define FRAMEWORK_WINDOW_DETAILS_X11_MOUSE_HPP

#include <cstdint>

#include <system/mouse.hpp>

namespace neutrino::system::details
{
MouseButton map_mouse_button(std::uint32_t button);

} // namespace neutrino::system::details

#endif
