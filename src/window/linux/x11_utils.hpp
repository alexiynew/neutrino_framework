/// @file
/// @brief Contains several helper functions.
/// @author Fedorov Alexey
/// @date 05.04.2018

#ifndef FRAMEWORK_WINDOW_LINUX_X11_UTILS_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_UTILS_HPP

#include <X11/Xlib.h>
#include <X11/Xmd.h>
#include <string>
#include <vector>

#include <common/types.hpp>
#include <window/linux/x11_server.hpp>

namespace framework {

namespace utils {

bool ewmh_supported();

bool send_client_message(const x11_server* server, Window window, Atom message_type, const std::vector<int64>& data);

template <typename... Args>
inline bool send_client_message(const x11_server* server, Window window, Atom message_type, Args... data)
{
    return send_client_message(server,
                               window,
                               message_type,
                               {
                               static_cast<int64>(data)...,
                               });
}

CARD32 get_window_wm_state(const x11_server* server, Window window);

bool window_has_state(const x11_server* server, Window window, const std::string& state_atom_name);
bool window_add_state(const x11_server* server, Window window, const std::vector<std::string>& state_atom_names);
bool window_remove_state(const x11_server* server, Window window, const std::vector<std::string>& state_atom_names);

bool activate_window(const x11_server* server, Window window, Time lastInputTime);

void bypass_compositor_desable(const x11_server* server, Window window);
void bypass_compositor_reset(const x11_server* server, Window window);

} // namespace utils

} // namespace framework

#endif
