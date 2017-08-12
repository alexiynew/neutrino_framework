/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X_SERVER_CONNECTION_HPP
#define FRAMEWORK_WINDOW_LINUX_X_SERVER_CONNECTION_HPP

#include <X11/Xlib.h>
#include <string>
#include <vector>
#include <memory>

namespace framework {

class x_server_connection;

std::shared_ptr<x_server_connection> connect_to_x_server();
int error_handler(Display* display, XErrorEvent* event);

class x_server_connection
{
public:
    enum class state
    {
        no_error,
        error
    };

    ~x_server_connection();

    x_server_connection(const x_server_connection&) = delete;
    x_server_connection& operator=(const x_server_connection&) = delete;

    Display* display() const;

    state error_state() const;
    std::string error_message() const;

    std::string pop_error();
    void clear_errors();

private:
    explicit x_server_connection(Display* display);

    state m_error_state;
    std::vector<std::string> m_error_messages;
    Display* m_display;

    friend std::shared_ptr<x_server_connection> connect_to_x_server();
    friend int error_handler(Display* display, XErrorEvent* event);
};

}

#endif
