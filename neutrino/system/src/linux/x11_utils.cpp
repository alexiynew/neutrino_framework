#include <cstring>

#include <common/utils.hpp>

#include <system/src/linux/x11_utils.hpp>

#include <X11/Xatom.h>
#include <X11/Xutil.h>

using framework::system::details::X11Server;
using framework::system::details::XLibWindow;

namespace
{
const char* const net_supported_atom_name            = u8"_NET_SUPPORTED";
const char* const net_supporting_wm_check_atom_name  = u8"_NET_SUPPORTING_WM_CHECK";
const char* const net_wm_bypass_compositor_atom_name = u8"_NET_WM_BYPASS_COMPOSITOR";
const char* const net_wm_icon_name_atom_name         = u8"_NET_WM_ICON_NAME";
const char* const net_wm_name_atom_name              = u8"_NET_WM_NAME";
const char* const net_wm_state_atom_name             = u8"_NET_WM_STATE";
const char* const utf8_string_atom_name              = u8"UTF8_STRING";
const char* const wm_state_atom_name                 = u8"WM_STATE";

inline bool have_utf8_support()
{
#ifdef X_HAVE_UTF8_STRING
    return true;
#else
    return false;
#endif
}

template <typename ValueType, typename DataType>
std::vector<ValueType> values_from_array(const DataType* data, std::size_t count)
{
    std::vector<ValueType> values(count);

    for (std::size_t i = 0; i < count; ++i) {
        values[i] = *(reinterpret_cast<const ValueType*>(data + i));
    }

    return values;
}

template <typename PropertyType>
std::vector<PropertyType> get_window_property(Display* display, XLibWindow window, Atom property, Atom type)
{
    static constexpr std::int64_t max_items_count = 1024;

    Atom actual_type          = None;
    int actual_format         = 0;
    unsigned long items_count = 0;
    unsigned long bytes_after = 0;
    std::uint8_t* data        = nullptr;

    const int result = XGetWindowProperty(display,
                                          window,
                                          property,
                                          0,
                                          max_items_count,
                                          False,
                                          type,
                                          &actual_type,
                                          &actual_format,
                                          &items_count,
                                          &bytes_after,
                                          &data);

    if (result != Success || actual_type != type || items_count == 0 || data == nullptr) {
        if (data) {
            XFree(data);
        }
        return std::vector<PropertyType>();
    }

    std::vector<PropertyType> values;
    switch (actual_format) {
        case 8: values = values_from_array<PropertyType>(reinterpret_cast<std::uint8_t*>(data), items_count); break;
        case 16: values = values_from_array<PropertyType>(reinterpret_cast<std::uint16_t*>(data), items_count); break;
        case 32: values = values_from_array<PropertyType>(reinterpret_cast<std::uint32_t*>(data), items_count); break;
    };

    XFree(data);

    return values;
}

bool is_ewmh_compliant(const X11Server* server)
{
    const Atom net_supporting_wm_check = server->get_atom(net_supporting_wm_check_atom_name);
    const Atom net_supported           = server->get_atom(net_supported_atom_name);

    if (net_supported == None || net_supporting_wm_check == None) {
        return false;
    }

    const auto root_window = server->default_root_window();

    const auto root = get_window_property<XLibWindow>(server->display(),
                                                      root_window,
                                                      net_supporting_wm_check,
                                                      XA_WINDOW);

    if (root.empty() || root[0] == None) {
        return false;
    }

    const auto child = get_window_property<XLibWindow>(server->display(), root[0], net_supporting_wm_check, XA_WINDOW);

    if (child.empty() || child[0] == None) {
        return false;
    }

    return root[0] == child[0];
}

std::vector<Atom> get_window_state(const X11Server* server, XLibWindow window)
{
    const Atom net_wm_state = server->get_atom(net_wm_state_atom_name);
    if (net_wm_state == None) {
        return std::vector<Atom>();
    }

    return get_window_property<Atom>(server->display(), window, net_wm_state, XA_ATOM);
}

XTextProperty create_text_property(Display* display, const std::string& string)
{
    XTextProperty text_property = {};

    std::unique_ptr<char[]> temp = std::make_unique<char[]>(string.size());
    std::strncpy(temp.get(), string.c_str(), string.size());
    char* data = temp.get();

    if (have_utf8_support()) {
        Xutf8TextListToTextProperty(display, &data, 1, XUTF8StringStyle, &text_property);
    } else {
        XmbTextListToTextProperty(display, &data, 1, XStdICCTextStyle, &text_property);
    }

    return text_property;
}

std::string create_string(Display* display, const XTextProperty& text_property)
{
    if (text_property.value == nullptr || text_property.format != 8) {
        return "";
    }

    char** list = nullptr;
    int count   = 0;
    if (have_utf8_support()) {
        Xutf8TextPropertyToTextList(display, &text_property, &list, &count);
    } else {
        XmbTextPropertyToTextList(display, &text_property, &list, &count);
    }

    if (list == nullptr) {
        return "";
    }

    std::string string(*list);

    XFreeStringList(list);

    return string;
}

} // namespace

namespace framework::system::details::utils
{
bool ewmh_supported()
{
    static bool supported = is_ewmh_compliant(X11Server::connect().get());
    return supported;
}

bool send_client_message(const X11Server* server,
                         XLibWindow window,
                         Atom message_type,
                         const std::vector<std::int64_t>& data)
{
    XEvent event               = {0};
    event.type                 = ClientMessage;
    event.xclient.window       = window;
    event.xclient.message_type = message_type;
    event.xclient.format       = 32;

    using DataType = std::remove_reference_t<decltype(event.xclient.data.l[0])>;

    const int count = ::framework::utils::size(event.xclient.data.l);

    for (size_t i = 0; i < data.size() && i < count; ++i) {
        event.xclient.data.l[i] = static_cast<DataType>(data[i]);
    }

    const Status result = XSendEvent(server->display(),
                                     server->default_root_window(),
                                     False,
                                     SubstructureNotifyMask | SubstructureRedirectMask,
                                     &event);

    return result != 0;
}

bool window_has_state(const X11Server* server, XLibWindow window, const std::string& atom_name)
{
    if (!ewmh_supported()) {
        return false;
    }

    const Atom net_wm_state_atom = server->get_atom(atom_name);

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

bool window_change_state(const X11Server* server,
                         XLibWindow window,
                         WindowStateAction action,
                         const std::vector<std::string>& atom_names)
{
    const Atom net_wm_state = server->get_atom(net_wm_state_atom_name);

    if (net_wm_state == None) {
        return false;
    }

    std::array<Atom, 2> state_atoms{};
    state_atoms[0] = (!atom_names.empty() ? server->get_atom(atom_names[0]) : None);
    state_atoms[1] = (atom_names.size() > 1 ? server->get_atom(atom_names[1]) : None);

    return send_client_message(server,
                               window,
                               net_wm_state,
                               static_cast<int>(action),
                               state_atoms[0],
                               state_atoms[1],
                               message_source_application);
}

void set_bypass_compositor_state(const X11Server* server, XLibWindow window, BypassCompositorState state)
{
    if (!ewmh_supported()) {
        return;
    }

    const Atom net_wm_bypass_compositor = server->get_atom(net_wm_bypass_compositor_atom_name);
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

CARD32 get_window_wm_state(const X11Server* server, XLibWindow window)
{
    const Atom net_wm_state = server->get_atom(wm_state_atom_name);

    if (net_wm_state == None) {
        return WithdrawnState;
    }

    const auto state = get_window_property<CARD32>(server->display(), window, net_wm_state, net_wm_state);

    if (state.empty()) {
        return WithdrawnState;
    }

    return state[0];
}

void set_window_name(const X11Server* server, XLibWindow window, const std::string& title)
{
    const Atom net_wm_name      = server->get_atom(net_wm_name_atom_name);
    const Atom net_wm_icon_name = server->get_atom(net_wm_icon_name_atom_name);
    const Atom utf8_string      = server->get_atom(utf8_string_atom_name);

    if (ewmh_supported() && net_wm_name != None && net_wm_icon_name != None && utf8_string != None) {
        XChangeProperty(server->display(),
                        window,
                        net_wm_name,
                        utf8_string,
                        8,
                        PropModeReplace,
                        reinterpret_cast<const std::uint8_t*>(title.c_str()),
                        static_cast<std::int32_t>(title.size()));

        XChangeProperty(server->display(),
                        window,
                        net_wm_icon_name,
                        utf8_string,
                        8,
                        PropModeReplace,
                        reinterpret_cast<const std::uint8_t*>(title.c_str()),
                        static_cast<std::int32_t>(title.size()));
    }

    XTextProperty text_property = create_text_property(server->display(), title);

    if (text_property.value != nullptr) {
        XSetWMName(server->display(), window, &text_property);
        XSetWMIconName(server->display(), window, &text_property);
        XFree(text_property.value);
    }
}

std::string get_window_name(const X11Server* server, XLibWindow window)
{
    const Atom net_wm_name      = server->get_atom(net_wm_name_atom_name);
    const Atom net_wm_icon_name = server->get_atom(net_wm_icon_name_atom_name);
    const Atom utf8_string      = server->get_atom(utf8_string_atom_name);

    if (ewmh_supported() && net_wm_name != None && net_wm_icon_name != None && utf8_string != None) {
        std::vector<std::uint8_t> data = get_window_property<std::uint8_t>(server->display(),
                                                                           window,
                                                                           net_wm_name,
                                                                           utf8_string);

        if (data.empty()) {
            data = get_window_property<std::uint8_t>(server->display(), window, net_wm_icon_name, utf8_string);
        }

        if (!data.empty()) {
            return std::string(reinterpret_cast<char*>(data.data()), data.size());
        }
    }

    XTextProperty text_property = {};

    if (XGetWMName(server->display(), window, &text_property) == 0) {
        XGetWMIconName(server->display(), window, &text_property);
    }

    if (text_property.value != nullptr) {
        std::string title = create_string(server->display(), text_property);
        XFree(text_property.value);
        return title;
    }

    return "";
}

FrameExtents get_frame_extents(const X11Server* server, XLibWindow window)
{
    // Get parent window, it's likely is the frame of our window.
    Window root;
    Window parent;
    Window* children_return;
    unsigned int nchildren_return;
    if (XQueryTree(server->display(), window, &root, &parent, &children_return, &nchildren_return) == 0) {

        return {0, 0, 0, 0};
    }

    // Get parent window size
    XWindowAttributes parent_attribs;
    if (XGetWindowAttributes(server->display(), parent, &parent_attribs) == 0) {
        return {0, 0, 0, 0};
    }
    // Get our window size
    XWindowAttributes window_attribs;
    if (XGetWindowAttributes(server->display(), window, &window_attribs) == 0) {
        return {0, 0, 0, 0};
    }

    // Get position of our window inside parent window
    const Position pos = translate_position(server, window, parent, {0, 0});

    FrameExtents extents;
    extents.left   = pos.x;
    extents.top    = pos.y;
    extents.right  = parent_attribs.width - (window_attribs.width + pos.x);
    extents.bottom = parent_attribs.height - (window_attribs.height + pos.y);

    return extents;
}

Position translate_position(const X11Server* server, XLibWindow src_window, XLibWindow dst_window, Position position)
{
    int x_return        = 0;
    int y_return        = 0;
    Window child_return = None;

    XTranslateCoordinates(server->display(),
                          src_window,
                          dst_window,
                          position.x,
                          position.y,
                          &x_return,
                          &y_return,
                          &child_return);

    return {x_return, y_return};
}

} // namespace framework::system::details::utils
