#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_UTILS_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_UTILS_HPP

#include <cstdint>
#include <string>
#include <vector>

#include <common/position.hpp>

#include <system/src/linux/x11_server.hpp>
#include <system/src/linux/x11_types.hpp>

#include <X11/Xlib.h>
#include <X11/Xmd.h>

namespace framework::system::details::utils
{

struct FrameExtents
{
    long left   = 0;
    long right  = 0;
    long top    = 0;
    long bottom = 0;
};

void focus_window(const X11Server* server, XLibWindow window, Time last_input_time);

void set_window_name(const X11Server* server, XLibWindow window, const std::string& title);
std::string get_window_name(const X11Server* server, XLibWindow window);

FrameExtents get_frame_extents(const X11Server* server, XLibWindow window);

void iconify_window(const X11Server* server, XLibWindow window);
void switch_maximize_state(const X11Server* server, XLibWindow window, bool enabled);
void switch_fullscreen_state(const X11Server* server, XLibWindow window, bool enabled);

bool is_iconifyed(const X11Server* server, XLibWindow window);
bool is_maximized(const X11Server* server, XLibWindow window);
bool is_fullscreen(const X11Server* server, XLibWindow window);
} // namespace framework::system::details::utils

#endif
