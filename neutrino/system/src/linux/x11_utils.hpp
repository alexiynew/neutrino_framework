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
enum class BypassCompositorState
{
    no_preferences = 0,
    disabled       = 1,
    enabled        = 2,
};

struct FrameExtents
{
    long left   = 0;
    long right  = 0;
    long top    = 0;
    long bottom = 0;
};

struct WindowStateFlags
{
    bool hidden         = false;
    bool fullscreen     = false;
    bool horz_maximized = false;
    bool vert_maximized = false;
};

bool ewmh_supported(const X11Server* server);

void focus_window(const X11Server* server, XLibWindow window, Time last_input_time);

void set_window_name(const X11Server* server, XLibWindow window, const std::string& title);
std::string get_window_name(const X11Server* server, XLibWindow window);

void set_pid(const X11Server* server, XLibWindow window, std::int32_t pid);

FrameExtents get_frame_extents(const X11Server* server, XLibWindow window);

void iconify_window(const X11Server* server, XLibWindow window);
void switch_maximize_state(const X11Server* server, XLibWindow window, bool enabled);
void switch_fullscreen_state(const X11Server* server, XLibWindow window, bool enabled);

CARD32 get_window_wm_state(const X11Server* server, XLibWindow window);
std::vector<Atom> get_window_new_wm_state(const X11Server* server, XLibWindow window);

WindowStateFlags get_window_state(const X11Server* server, XLibWindow window);

void set_bypass_compositor_state(const X11Server* server, XLibWindow window, BypassCompositorState state);
BypassCompositorState get_bypass_compositor_state(const X11Server* server, XLibWindow window);

} // namespace framework::system::details::utils

#endif
