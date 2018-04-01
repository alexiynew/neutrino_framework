/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

#include <X11/Xatom.h>
#include <X11/Xutil.h>
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

template <typename ValueType, typename DataType>
std::vector<ValueType> get_values_from_array(const DataType* data, uint64 count)
{
    std::vector<ValueType> values(count);

    for (uint64 i = 0; i < count; ++i) {
        values[i] = *(reinterpret_cast<const ValueType*>(data + i));
    }

    return values;
}

template <typename PropertyType>
std::vector<PropertyType> get_window_property(Display* display, Window window, Atom property, Atom type)
{
    const int64 max_items_count = 1024;

    Atom actual_type    = None;
    int32 actual_format = 0;
    uint64 items_count  = 0;
    uint64 bytes_after  = 0;
    uint8* data         = nullptr;

    int32 result = XGetWindowProperty(
    display, window, property, 0, max_items_count, False, type, &actual_type, &actual_format, &items_count, &bytes_after, &data);

    if (result != Success || actual_type != type || items_count == 0 || data == nullptr) {
        if (data) {
            XFree(data);
        }
        return std::vector<PropertyType>();
    }

    std::vector<PropertyType> values;
    switch (actual_format) {
        case 8: values = get_values_from_array<PropertyType>(reinterpret_cast<uint8*>(data), items_count); break;
        case 16: values = get_values_from_array<PropertyType>(reinterpret_cast<uint16*>(data), items_count); break;
        case 32: values = get_values_from_array<PropertyType>(reinterpret_cast<uint32*>(data), items_count); break;
    };

    XFree(data);

    return values;
}

bool is_ewmh_compliant(const x11_server* x_server)
{
    const Atom net_supporting_wm_check = x_server->get_atom(u8"_NET_SUPPORTING_WM_CHECK", true);
    const Atom net_supported           = x_server->get_atom(u8"_NET_SUPPORTED", true);

    if (net_supported == None || net_supporting_wm_check == None) {
        return false;
    }

    const auto root_window = x_server->default_root_window();

    auto root = get_window_property<Window>(x_server->display(), root_window, net_supporting_wm_check, XA_WINDOW);

    if (root.empty() || root[0] == None) {
        return false;
    }

    auto child = get_window_property<Window>(x_server->display(), root[0], net_supporting_wm_check, XA_WINDOW);

    if (child.empty() || child[0] == None) {
        return false;
    }

    return root[0] == child[0];
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

Window x11_server::currently_active_window() const
{
    Window window;
    int state;

    XGetInputFocus(m_display, &window, &state);

    return window;
}

bool x11_server::ewmh_supported() const
{
    return m_ewmh_supported;
}

Atom x11_server::get_atom(const std::string& name, bool only_if_exists) const
{
    if (m_atoms.count(name) == 0) {
        Atom atom = XInternAtom(m_display, name.c_str(), only_if_exists ? True : False);
        m_atoms.insert({name, atom});
    }

    return m_atoms[name];
}

std::vector<Atom> x11_server::get_window_state_properties(Window window) const
{
    Atom net_wm_state = get_atom(u8"_NET_WM_STATE", true);
    if (net_wm_state == None) {
        log::warning(log_tag) << "Can't get window properies." << std::endl;
        return std::vector<Atom>();
    }

    return get_window_property<Atom>(m_display, window, net_wm_state, XA_ATOM);
}

CARD32 x11_server::get_window_state(Window window) const
{
    Atom net_wm_state = get_atom(u8"WM_STATE", true);

    auto state = get_window_property<CARD32>(m_display, window, net_wm_state, net_wm_state);

    if (state.empty()) {
        return WithdrawnState;
    }

    return state[0];
}

XIM x11_server::input_method() const
{
    return m_input_method;
}

} // namespace framework
