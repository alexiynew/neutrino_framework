/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X11_SERVER_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_SERVER_HPP

#include <X11/Xlib.h>
#include <map>
#include <memory>

namespace framework {

class x11_server
{
public:
    ~x11_server();

    x11_server(const x11_server&) = delete;
    x11_server& operator=(const x11_server&) = delete;

    Display* display() const;
    XID default_root_window() const;
    XID default_screen() const;

    bool ewmh_supported() const;

    Atom get_atom(const std::string& name, bool only_if_exists) const;

    static std::shared_ptr<x11_server> connect();

private:
    x11_server();

    Display* m_display    = nullptr;
    bool m_ewmh_supported = false;

    mutable std::map<std::string, Atom> m_atoms;
};

} // namespace framework

#endif