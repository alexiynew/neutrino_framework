#include <stdexcept>

#include <system/src/linux/x11_keyboard.hpp>
#include <system/src/linux/x11_server.hpp>

namespace
{
using ::framework::system::details::X11Server;

std::weak_ptr<X11Server>& server_instance()
{
    static std::weak_ptr<X11Server> instance;
    return instance;
}

[[noreturn]] int fatal_error_handler(Display* /*unused*/)
{
    std::terminate();
}

int error_handler(Display* display, XErrorEvent* event)
{
    auto x_server = server_instance().lock();
    if (x_server && display == x_server->display()) {
        constexpr std::uint32_t length = 8 * 1024;

        char buffer[length] = {};
        XGetErrorText(display, event->error_code, buffer, length);
        throw std::runtime_error(buffer);
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

namespace framework::system::details
{
std::shared_ptr<X11Server> X11Server::connect()
{
    if (server_instance().expired()) {
        std::shared_ptr<X11Server> temp{new X11Server()};
        server_instance() = temp;
        return temp;
    }

    return server_instance().lock();
}

X11Server::X11Server()
    : m_display{nullptr}
{
    m_display = XOpenDisplay(nullptr);

    if (m_display == nullptr) {
        throw std::runtime_error("Failed to open connection to X server, there is no display.");
    }

    set_error_handlers();

    m_input_method = XOpenIM(m_display, nullptr, nullptr, nullptr);

    init_key_code_map(this);
}

X11Server::~X11Server()
{
    if (m_input_method != nullptr) {
        XCloseIM(m_input_method);
    }

    if (m_display != nullptr) {
        XCloseDisplay(m_display);
    }

    release_error_handlers();
}

Display* X11Server::display() const
{
    return m_display;
}

XID X11Server::default_root_window() const
{
    return DefaultRootWindow(display());
}

XID X11Server::default_screen() const
{
    return static_cast<XID>(DefaultScreen(display()));
}

::Window X11Server::active_window() const
{
    ::Window window = None;
    int state       = 0;

    XGetInputFocus(m_display, &window, &state);

    return window;
}

Atom X11Server::get_atom(const std::string& name, bool only_if_exists) const
{
    if (m_atoms.count(name) == 0) {
        Atom atom = XInternAtom(m_display, name.c_str(), only_if_exists ? True : False);
        m_atoms.insert({name, atom});
    }

    return m_atoms[name];
}

XIM X11Server::input_method() const
{
    return m_input_method;
}

} // namespace framework::system::details
