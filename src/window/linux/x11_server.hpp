/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X11_SERVER_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_SERVER_HPP

#include <X11/Xlib.h>
#include <X11/Xmd.h>
#include <map>
#include <memory>
#include <vector>

namespace framework {

class x11_server final
{
public:
    x11_server(const x11_server&) = delete;
    x11_server& operator=(const x11_server&) = delete;

    ~x11_server();

    Display* display() const;
    XID default_root_window() const;
    XID default_screen() const;

    Window currently_active_window() const;

    bool ewmh_supported() const;

    Atom get_atom(const std::string& name, bool only_if_exists) const;
    std::vector<Atom> get_window_state_properties(Window window) const;
    CARD32 get_window_state(Window window) const;

    XIM input_method() const;

    static std::shared_ptr<x11_server> connect();

private:
    x11_server();

    Display* m_display    = nullptr;
    bool m_ewmh_supported = false;
    XIM m_input_method    = nullptr;

    mutable std::map<std::string, Atom> m_atoms;
};

} // namespace framework

#endif
