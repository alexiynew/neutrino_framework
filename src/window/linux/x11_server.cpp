/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#include <X11/Xatom.h>
#include <common/types.hpp>
#include <log/log.hpp>
#include <window/linux/x11_server.hpp>

using namespace framework;
using namespace framework::log;

namespace {

const char* const log_tag = "x11_server";

std::weak_ptr<x11_server>& server_instance()
{
    static std::weak_ptr<x11_server> instance;
    return instance;
}

[[noreturn]] int32 fatal_error_handler(Display*)
{
    log::fatal(log_tag) << "Fatal error occurred." << std::endl;
    std::terminate();
}

int error_handler(Display* display, XErrorEvent* event)
{
    if (auto x_server = server_instance().lock(); display == x_server->display()) {
        constexpr uint32 length = 8 * 1024;
        char buffer[length];
        XGetErrorText(display, event->error_code, buffer, length);

        log::error(log_tag) << buffer << std::endl;
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
    if (server_instance().expired()) {
        std::shared_ptr<x11_server> temp{new x11_server()};
        server_instance() = temp;
        return temp;
    } else {
        return server_instance().lock();
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

    m_input_method = XOpenIM(m_display, nullptr, nullptr, nullptr);
}

x11_server::~x11_server()
{
    if (m_input_method) {
        XCloseIM(m_input_method);
    }

    if (m_display) {
        XCloseDisplay(m_display);
    }

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
    return static_cast<XID>(DefaultScreen(display()));
}

bool x11_server::ewmh_supported() const
{
    return m_ewmh_supported;
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

XIM x11_server::input_method() const
{
    return m_input_method;
}

} // namespace framework
