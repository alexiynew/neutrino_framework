#ifndef SYSTEM_SRC_OSX_OSX_KEYBOARD_HPP
#define SYSTEM_SRC_OSX_OSX_KEYBOARD_HPP

#include <cstdint>

#include <system/keyboard.hpp>

namespace framework::system::details
{

KeyCode map_system_key(std::uint32_t key);
Modifiers get_modifiers_state(std::uint32_t flags);

} // namespace framework::system::details

#endif
