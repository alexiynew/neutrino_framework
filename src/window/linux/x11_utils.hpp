/// @file
/// @brief Contains several helper functions.
/// @author Fedorov Alexey
/// @date 05.04.2018

#ifndef FRAMEWORK_WINDOW_LINUX_X11_UTILS_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_UTILS_HPP

#include <X11/Xlib.h>
#include <common/types.hpp>
#include <vector>

namespace framework {

namespace utils {

Status send_client_message(Display* display, Window window, Atom message_type, const std::vector<int64>& data);

template <typename... Args>
inline Status send_client_message(Display* display, Window window, Atom message_type, Args... data)
{
    return send_client_message(display,
                               window,
                               message_type,
                               {
                               static_cast<int64>(data)...,
                               });
}

} // namespace utils

} // namespace framework

#endif
