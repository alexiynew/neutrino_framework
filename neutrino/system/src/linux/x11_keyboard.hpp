#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_X11_KEYBOARD_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_X11_KEYBOARD_HPP

#include <system/keyboard.hpp>

#include <system/src/linux/x11_server.hpp>

namespace framework::system::details
{
void init_key_code_map(const x11_server* server);

key_code map_system_key(uint32 key);
modifiers_state get_modifiers_state(uint32 state);

} // namespace framework::system::details

#endif
