#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_SERVER_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_SERVER_HPP

#include <map>
#include <memory>
#include <vector>

#include <X11/Xlib.h>

namespace framework::system::details
{
class x11_server final
{
public:
    x11_server(const x11_server&) = delete;
    x11_server& operator=(const x11_server&) = delete;

    ~x11_server();

    Display* display() const;
    XID default_root_window() const;
    XID default_screen() const;

    Window active_window() const;

    Atom get_atom(const std::string& name, bool only_if_exists = true) const;

    XIM input_method() const;

    static std::shared_ptr<x11_server> connect();

private:
    x11_server();

    Display* m_display = nullptr;
    XIM m_input_method = nullptr;

    mutable std::map<std::string, Atom> m_atoms;
};

} // namespace framework::system::details

#endif
