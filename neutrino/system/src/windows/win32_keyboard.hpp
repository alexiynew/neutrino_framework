#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_KEYBOARD_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_KEYBOARD_HPP

#include <system/keyboard.hpp>

namespace framework::system::details
{
KeyCode map_system_key(std::uint32_t key);
Modifiers get_modifiers_state();

} // namespace framework::system::details

#endif
