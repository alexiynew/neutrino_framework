#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_X11_KEYBOARD_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_X11_KEYBOARD_HPP

#include <cstdint>

#include <system/keyboard.hpp>

#include <system/src/linux/x11_server.hpp>

namespace neutrino::system::details
{
void init_key_code_map(const X11Server* server);

KeyCode map_system_key(std::uint32_t key);
Modifiers get_modifiers_state(std::uint32_t state);

} // namespace neutrino::system::details

#endif
