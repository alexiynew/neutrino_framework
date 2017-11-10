/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#include <X11/Xatom.h>
#include <common/common_types.hpp>
#include <log/log.hpp>
#include <window/linux/x11_server.hpp>

using namespace framework;
using log = ::framework::logging::log;

// TODO All XServer method should be in the same (GUI) thread

namespace {

const char* const log_tag = "x11_server";

std::weak_ptr<x11_server> global_x11_server;

[[noreturn]] int32 fatal_error_handler(Display*)
{
    log::fatal(log_tag, "Fatal error occurred.");
    std::terminate();
}

int error_handler(Display* display, XErrorEvent* event)
{
    if (auto x_server = global_x11_server.lock(); display == x_server->display()) {
        constexpr uint32 length = 8 * 1024;
        char buffer[length];
        XGetErrorText(display, event->error_code, buffer, length);

        log::error(log_tag, buffer);
    }

    return 0;
}

void set_error_handlers()
{
    XSetIOErrorHandler(fatal_error_handler);
    XSetErrorHandler(error_handler);
}

void release_error_handlers()
{
    XSetIOErrorHandler(nullptr);
    XSetErrorHandler(nullptr);
}

uint8* get_window_property(Display* display, Window window, Atom property, Atom type)
{
    Atom actual_type_return    = None;
    int32 actual_format_return = 0;
    uint64 nitems_return       = 0;
    uint64 bytes_after_return  = 0;
    uint8* prop_return         = nullptr;

    int32 result = XGetWindowProperty(
    display, window, property, 0, 1, False, type, &actual_type_return, &actual_format_return, &nitems_return, &bytes_after_return, &prop_return);

    if (result != Success) {
        return nullptr;
    }

    return prop_return;
}

bool is_ewmh_compliant(const x11_server* x_server)
{
    const Atom net_supporting_wm_check = x_server->get_atom(u8"_NET_SUPPORTING_WM_CHECK", true);
    const Atom net_supported           = x_server->get_atom(u8"_NET_SUPPORTED", true);

    if (!net_supported || !net_supporting_wm_check) {
        return false;
    }

    Window* from_root  = nullptr;
    Window* from_child = nullptr;

    from_root = reinterpret_cast<Window*>(
    get_window_property(x_server->display(), x_server->default_root_window(), net_supporting_wm_check, XA_WINDOW));

    if (!from_root) {
        return false;
    }

    from_child =
    reinterpret_cast<Window*>(get_window_property(x_server->display(), *from_root, net_supporting_wm_check, XA_WINDOW));

    if (!from_child) {
        XFree(from_root);
        return false;
    }

    bool result = *from_root == *from_child;

    XFree(from_root);
    XFree(from_child);

    return result;
}

} // namespace

namespace framework {

std::shared_ptr<x11_server> x11_server::connect()
{
    // TODO make it thread safe
    if (global_x11_server.expired()) {
        std::shared_ptr<x11_server> temp{new x11_server()};
        global_x11_server = temp;
        return temp;
    } else {
        return global_x11_server.lock();
    }
}

x11_server::x11_server()
    : m_display{XOpenDisplay(nullptr)}
{
    if (!m_display) {
        throw std::runtime_error("Failed to open connection to X server, there is no display.");
    }

    set_error_handlers();

    m_ewmh_supported = ::is_ewmh_compliant(this);
}

x11_server::~x11_server()
{
    if (m_display) {
        XCloseDisplay(m_display);
    }
    m_display = nullptr;

    release_error_handlers();
}

Display* x11_server::display() const
{
    return m_display;
}

XID x11_server::default_root_window() const
{
    return DefaultRootWindow(display());
}

XID x11_server::default_screen() const
{
    return DefaultScreen(display());
}

Atom x11_server::get_atom(const std::string& name, bool only_if_exists) const
{
    // TODO make it thread safe
    if (m_atoms.count(name) == 0) {
        Atom atom = XInternAtom(m_display, name.c_str(), only_if_exists ? True : False);
        m_atoms.insert({name, atom});
    }

    return m_atoms[name];
}

bool x11_server::ewmh_supported() const
{
    return m_ewmh_supported;
}

} // namespace framework
