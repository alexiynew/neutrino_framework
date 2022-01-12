#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_UTILS_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_UTILS_HPP

#include <string>
#include <vector>

#include <common/types.hpp>

#include <system/src/linux/x11_server.hpp>

#include <X11/Xlib.h>
#include <X11/Xmd.h>

namespace framework::system::details::utils
{
constexpr int32 message_source_application = 1;

enum class bypass_compositor_state
{
    no_preferences = 0,
    disabled       = 1
};

enum class window_state_action
{
    remove = 0,
    add    = 1
};

bool ewmh_supported();

bool send_client_message(const x11_server* server, Window window, Atom message_type, const std::vector<int64>& data);

template <typename... Args>
inline bool send_client_message(const x11_server* server, Window window, Atom message_type, Args... data)
{
    const std::vector<int64> tmp{{
    static_cast<int64>(data)...,
    }};
    return send_client_message(server, window, message_type, tmp);
}

CARD32 get_window_wm_state(const x11_server* server, Window window);

bool window_has_state(const x11_server* server, Window window, const std::string& atom_name);
bool window_change_state(const x11_server* server,
                         Window window,
                         window_state_action action,
                         const std::vector<std::string>& atom_names);

void set_bypass_compositor_state(const x11_server* server, Window window, bypass_compositor_state state);

void set_window_name(const x11_server* server, Window window, const std::string& title);
std::string get_window_name(const x11_server* server, Window window);

} // namespace framework::system::details::utils

#endif
