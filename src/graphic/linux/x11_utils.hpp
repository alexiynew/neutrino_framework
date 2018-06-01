/// @file
/// @brief Contains several helper functions.
/// @author Fedorov Alexey
/// @date 05.04.2018

#ifndef FRAMEWORK_GRAPHIC_LINUX_X11_UTILS_HPP
#define FRAMEWORK_GRAPHIC_LINUX_X11_UTILS_HPP

#include <X11/Xlib.h>
#include <X11/Xmd.h>
#include <string>
#include <vector>

#include <common/types.hpp>
#include <graphic/linux/x11_server.hpp>

namespace framework {

namespace graphic {

namespace utils {

constexpr int32 message_source_application = 1;

enum class bypass_compositor_state
{
    no_preferences = 0,
    disabled       = 1
};

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

void set_bypass_compositor_state(const x11_server* server, Window window, bypass_compositor_state state);

void set_window_name(const x11_server* server, Window window, const std::string& title);
std::string get_window_name(const x11_server* server, Window window);

} // namespace utils

} // namespace graphic

} // namespace framework

#endif
