#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_KEYBOARD_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_KEYBOARD_HPP

#include <cstdint>

#include <system/keyboard.hpp>

namespace neutrino::system::details
{
KeyCode map_system_key(std::uint32_t key);
Modifiers get_modifiers_state();

} // namespace neutrino::system::details

#endif
