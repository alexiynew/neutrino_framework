/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#include <window/linux/x_server_connection.hpp>
#include <common/common_types.hpp>
#include <log/log.hpp>

using namespace framework;
using log = ::framework::logging::log;

namespace
{
const char* const log_tag = "x_server_connection";

x_server_connection* global_connection = nullptr;

[[noreturn]] int fatal_error_handler(Display*)
{
    ::framework::logging::log::fatal(log_tag, "Fatal error occurred.");
    std::terminate();
}

void set_error_handlers(x_server_connection* connection) {
    global_connection = connection;

    XSetIOErrorHandler(fatal_error_handler);
    XSetErrorHandler(error_handler);
}

void release_error_handlers()
{
    XSetIOErrorHandler(nullptr);
    XSetErrorHandler(nullptr);

    global_connection = nullptr;
}
}

namespace framework
{

int error_handler(Display* display, XErrorEvent* event)
{
    constexpr uint32 length = 8 * 1024;
    char description[length];
    XGetErrorText(display, event->error_code, description, length);

    if (global_connection && display == global_connection->m_display) {
        global_connection->m_error_state = x_server_connection::state::error;
        global_connection->m_error_messages.push_back(std::string{description});
    }

    return 0;
}

std::shared_ptr<x_server_connection> connect_to_x_server()
{
    static std::weak_ptr<x_server_connection> temp_connection;

    if (temp_connection.expired()) {
        std::shared_ptr<x_server_connection> connection{new x_server_connection(XOpenDisplay(nullptr))};

        temp_connection = connection;

        return connection;
    } else {
        return temp_connection.lock();
    }
}

x_server_connection::x_server_connection(Display* display)
    : m_error_state{state::no_error}
    , m_error_messages{}
    , m_display{display}
{
    if (!m_display) {
        m_error_state = state::error;
        m_error_messages.push_back("Failed to open connection to X server, there is no display.");
    }

    set_error_handlers(this);
}

x_server_connection::~x_server_connection()
{
    if (m_display) {
        XCloseDisplay(m_display);
    }
    m_display = nullptr;

    release_error_handlers();
}

Display* x_server_connection::display() const
{
    return m_display;
}

x_server_connection::state x_server_connection::error_state() const
{
    return !m_error_messages.empty() ? state::error : state::no_error;
}

std::string x_server_connection::error_message() const
{
    return !m_error_messages.empty() ? m_error_messages.back() : std::string{};
}

std::string x_server_connection::pop_error()
{
    const std::string message = error_message();
    m_error_messages.pop_back();
    return message;
}

void x_server_connection::clear_errors()
{
    m_error_messages.clear();
}
} // namespace framework
