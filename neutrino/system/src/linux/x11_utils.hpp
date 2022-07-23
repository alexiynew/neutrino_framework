#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_UTILS_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_UTILS_HPP

#include <cstdint>
#include <string>
#include <vector>

#include <system/src/linux/x11_server.hpp>

#include <X11/Xlib.h>
#include <X11/Xmd.h>

namespace framework::system::details::utils
{
constexpr int message_source_application = 1;

enum class BypassCompositorState
{
    no_preferences = 0,
    disabled       = 1
};

enum class WindowStateAction
{
    remove = 0,
    add    = 1
};

bool ewmh_supported();

bool send_client_message(const X11Server* server,
                         ::Window window,
                         Atom message_type,
                         const std::vector<std::int64_t>& data);

template <typename... Args>
inline bool send_client_message(const X11Server* server, ::Window window, Atom message_type, Args... data)
{
    const std::vector<std::int64_t> tmp{{
    static_cast<std::int64_t>(data)...,
    }};
    return send_client_message(server, window, message_type, tmp);
}

CARD32 get_window_wm_state(const X11Server* server, ::Window window);

bool window_has_state(const X11Server* server, ::Window window, const std::string& atom_name);
bool window_change_state(const X11Server* server,
                         ::Window window,
                         WindowStateAction action,
                         const std::vector<std::string>& atom_names);

void set_bypass_compositor_state(const X11Server* server, ::Window window, BypassCompositorState state);

void set_window_name(const X11Server* server, ::Window window, const std::string& title);
std::string get_window_name(const X11Server* server, ::Window window);

} // namespace framework::system::details::utils

#endif
