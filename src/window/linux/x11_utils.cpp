#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <window/linux/x11_utils.hpp>

using namespace framework;

namespace {

/// Client message source
constexpr int32 message_source_application = 1;

enum net_wm_state_action
{
    remove = 0,
    add    = 1
};

enum bypass_compositor_state
{
    no_preferences = 0,
    disabled       = 1
};

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

bool is_ewmh_compliant(const x11_server* server)
{
    const Atom net_supporting_wm_check = server->get_atom(u8"_NET_SUPPORTING_WM_CHECK", true);
    const Atom net_supported           = server->get_atom(u8"_NET_SUPPORTED", true);

    if (net_supported == None || net_supporting_wm_check == None) {
        return false;
    }

    const auto root_window = server->default_root_window();

    auto root = get_window_property<Window>(server->display(), root_window, net_supporting_wm_check, XA_WINDOW);

    if (root.empty() || root[0] == None) {
        return false;
    }

    auto child = get_window_property<Window>(server->display(), root[0], net_supporting_wm_check, XA_WINDOW);

    if (child.empty() || child[0] == None) {
        return false;
    }

    return root[0] == child[0];
}

std::vector<Atom> get_window_state(const x11_server* server, Window window)
{
    Atom net_wm_state = server->get_atom(u8"_NET_WM_STATE", true);
    if (net_wm_state == None) {
        return std::vector<Atom>();
    }

    return get_window_property<Atom>(server->display(), window, net_wm_state, XA_ATOM);
}

bool window_change_state(const x11_server* server,
                         Window window,
                         net_wm_state_action action,
                         const std::vector<std::string>& state_atom_names)
{
    if (!utils::ewmh_supported() || state_atom_names.empty()) {
        return false;
    }

    Atom net_wm_state = server->get_atom(u8"_NET_WM_STATE", true);

    if (net_wm_state == None) {
        return false;
    }

    std::array<Atom, 2> state_atoms;
    state_atoms[0] = (state_atom_names.size() > 0 ? server->get_atom(state_atom_names[0], true) : None);
    state_atoms[1] = (state_atom_names.size() > 1 ? server->get_atom(state_atom_names[1], true) : None);

    return utils::send_client_message(
    server, window, net_wm_state, action, state_atoms[0], state_atoms[1], message_source_application);
}

void bypass_compositor_set_state(const x11_server* server, Window window, bypass_compositor_state state)
{
    if (!utils::ewmh_supported()) {
        return;
    }

    Atom net_wm_bypass_compositor = server->get_atom(u8"_NET_WM_BYPASS_COMPOSITOR", true);
    if (net_wm_bypass_compositor == None) {
        return;
    }

    XChangeProperty(server->display(),
                    window,
                    net_wm_bypass_compositor,
                    XA_CARDINAL,
                    32,
                    PropModeReplace,
                    reinterpret_cast<const unsigned char*>(&state),
                    1);
}

} // namespace



namespace framework {

namespace utils {

bool ewmh_supported()
{
    static bool supported = is_ewmh_compliant(x11_server::connect().get());
    return supported;
}

bool send_client_message(const x11_server* server, Window window, Atom message_type, const std::vector<int64>& data)
{
    XEvent event               = {0};
    event.type                 = ClientMessage;
    event.xclient.window       = window;
    event.xclient.message_type = message_type;
    event.xclient.format       = 32;

    const int max_size = sizeof(event.xclient.data.l) / sizeof(long);

    for (size_t i = 0; i < data.size() && i < max_size; ++i) {
        event.xclient.data.l[i] = data[i];
    }

    Status result = XSendEvent(
    server->display(), server->default_root_window(), False, SubstructureNotifyMask | SubstructureRedirectMask, &event);

    return result != 0;
}

bool window_has_state(const x11_server* server, Window window, const std::string& state_atom_name)
{
    if (!ewmh_supported()) {
        return false;
    }

    const Atom net_wm_state_atom = server->get_atom(state_atom_name, true);

    if (net_wm_state_atom == None) {
        return false;
    }

    const auto state = ::get_window_state(server, window);

    for (auto atom : state) {
        if (atom == net_wm_state_atom) {
            return true;
        }
    }

    return false;
}

bool window_add_state(const x11_server* server, Window window, const std::vector<std::string>& state_atom_names)
{
    return ::window_change_state(server, window, ::net_wm_state_action::add, state_atom_names);
}

bool window_remove_state(const framework::x11_server* server, Window window, const std::vector<std::string>& state_atom_names)
{
    return ::window_change_state(server, window, ::net_wm_state_action::remove, state_atom_names);
}

bool activate_window(const x11_server* server, Window window, Time lastInputTime)
{
    if (!ewmh_supported()) {
        return false;
    }

    Atom net_active_window = server->get_atom(u8"_NET_ACTIVE_WINDOW", false);
    if (net_active_window == None) {
        return false;
    }

    Window active_window = server->currently_active_window();
    if (window == active_window) {
        return true;
    }

    return send_client_message(server, window, net_active_window, message_source_application, lastInputTime, active_window);
}

void bypass_compositor_desable(const x11_server* server, Window window)
{
    ::bypass_compositor_set_state(server, window, bypass_compositor_state::disabled);
}

void bypass_compositor_reset(const x11_server* server, Window window)
{
    ::bypass_compositor_set_state(server, window, bypass_compositor_state::no_preferences);
}

CARD32 get_window_wm_state(const x11_server* server, Window window)
{
    Atom net_wm_state = server->get_atom(u8"WM_STATE", true);

    auto state = get_window_property<CARD32>(server->display(), window, net_wm_state, net_wm_state);

    if (state.empty()) {
        return WithdrawnState;
    }

    return state[0];
}

} // namespace utils

} // namespace framework
