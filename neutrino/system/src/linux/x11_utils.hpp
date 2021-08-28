// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

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
