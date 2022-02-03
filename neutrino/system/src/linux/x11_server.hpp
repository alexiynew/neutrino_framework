#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_SERVER_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_SERVER_HPP

#include <map>
#include <memory>

#include <X11/Xlib.h>

namespace framework::system::details
{
class X11Server final
{
public:
    static std::shared_ptr<X11Server> connect();

    X11Server(const X11Server&) = delete;
    X11Server& operator=(const X11Server&) = delete;

    ~X11Server();

    Display* display() const;
    XID default_root_window() const;
    XID default_screen() const;

    ::Window active_window() const;

    Atom get_atom(const std::string& name, bool only_if_exists = true) const;

    XIM input_method() const;

private:
    X11Server();

    Display* m_display = nullptr;
    XIM m_input_method = nullptr;

    mutable std::map<std::string, Atom> m_atoms;
};

} // namespace framework::system::details

#endif
