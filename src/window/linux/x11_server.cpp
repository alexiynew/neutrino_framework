/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

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

[[noreturn]] int32 fatal_error_handler(Display*) {
    log::fatal(log_tag) << "Fatal error occurred." << std::endl;
    std::terminate();
}

int error_handler(Display* display, XErrorEvent* event)
{
    auto x_server = server_instance().lock();
    if (x_server && display == x_server->display()) {
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

} // namespace

namespace framework {

std::shared_ptr<x11_server> x11_server::connect()
{
    if (server_instance().expired()) {
        std::shared_ptr<x11_server> temp{new x11_server()};
        server_instance() = temp;
        return temp;
    } else {
        return server_instance().lock();
    }
}

x11_server::x11_server() : m_display{XOpenDisplay(nullptr)}
{
    if (!m_display) {
        throw std::runtime_error("Failed to open connection to X server, there is no display.");
    }

    set_error_handlers();

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

Window x11_server::currently_active_window() const
{
    Window window;
    int state;

    XGetInputFocus(m_display, &window, &state);

    return window;
}

Atom x11_server::get_atom(const std::string& name, bool only_if_exists) const
{
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
