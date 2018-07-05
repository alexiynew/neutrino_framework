/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#include <X11/Xutil.h>
#include <chrono>
#include <exception>
#include <string>
#include <thread>

#include <common/types.hpp>
#include <common/utils.hpp>
#include <log/log.hpp>
#include <window/linux/x11_utils.hpp>
#include <window/linux/x11_window.hpp>

namespace {

const char* const log_tag = "x11_window";

const char* const net_wm_state_maximized_vert_atom_name = u8"_NET_WM_STATE_MAXIMIZED_VERT";
const char* const net_wm_state_maximized_horz_atom_name = u8"_NET_WM_STATE_MAXIMIZED_HORZ";
const char* const net_wm_state_fullscreen_atom_name     = u8"_NET_WM_STATE_FULLSCREEN";
const char* const net_wm_state_hidden_atom_name         = u8"_NET_WM_STATE_HIDDEN";
const char* const net_active_window_atom_name           = u8"_NET_ACTIVE_WINDOW";
const char* const wm_delete_window_atom_name            = u8"WM_DELETE_WINDOW";

const ::framework::int64 event_mask = VisibilityChangeMask     // Any change in visibility wanted
                                      | FocusChangeMask        // Any change in input focus wanted
                                      | StructureNotifyMask    // Any change in window structure wanted
                                      | PropertyChangeMask     // Any change in property wanted
                                      | ExposureMask           // Any exposure wanted
                                      | KeyPressMask           // Keyboard down events wanted
                                      | KeyReleaseMask         // Keyboard up events wanted
                                      | ButtonPressMask        // Pointer button down events wanted
                                      | ButtonReleaseMask      // Pointer button up events wanted
                                      | EnterWindowMask        // Pointer window entry events wanted
                                      | LeaveWindowMask        // Pointer window leave events wanted
                                      | PointerMotionMask      // Pointer motion events wanted
                                      | PointerMotionHintMask; // Pointer motion hints wanted

// | Button1MotionMask        // Pointer motion while button 1 down
// | Button2MotionMask        // Pointer motion while button 2 down
// | Button3MotionMask        // Pointer motion while button 3 down
// | Button4MotionMask        // Pointer motion while button 4 down
// | Button5MotionMask        // Pointer motion while button 5 down
// | ButtonMotionMask         // Pointer motion while any button down
// | KeymapStateMask          // Keyboard state wanted at window entry and focus in
// | ResizeRedirectMask       // Redirect resize of this window
// | SubstructureNotifyMask   // Substructure notification wanted
// | SubstructureRedirectMask // Redirect structure requests on children
// | ColormapChangeMask       // Any change in colormap wanted
// | OwnerGrabButtonMask;     // Automatic grabs should activate with owner_events set to True

// NOLINTNEXTLINE(readability-non-const-parameter)
Bool event_predicate(Display* /*unused*/, XEvent* event, XPointer arg)
{
    return static_cast<Bool>(event->xany.window == *(reinterpret_cast<Window*>(arg)));
}

std::string event_type_string(const XAnyEvent& event)
{
    switch (event.type) {
        case KeyPress: return "KeyPress";
        case KeyRelease: return "KeyRelease";
        case ButtonPress: return "ButtonPress";
        case ButtonRelease: return "ButtonRelease";
        case MotionNotify: return "MotionNotify";
        case EnterNotify: return "EnterNotify";
        case LeaveNotify: return "LeaveNotify";
        case FocusIn: return "FocusIn";
        case FocusOut: return "FocusOut";
        case KeymapNotify: return "KeymapNotify";
        case Expose: return "Expose";
        case GraphicsExpose: return "GraphicsExpose";
        case NoExpose: return "NoExpose";
        case VisibilityNotify: return "VisibilityNotify";
        case CreateNotify: return "CreateNotify";
        case DestroyNotify: return "DestroyNotify";
        case UnmapNotify: return "UnmapNotify";
        case MapNotify: return "MapNotify";
        case MapRequest: return "MapRequest";
        case ReparentNotify: return "ReparentNotify";
        case ConfigureNotify: return "ConfigureNotify";
        case ConfigureRequest: return "ConfigureRequest";
        case GravityNotify: return "GravityNotify";
        case ResizeRequest: return "ResizeRequest";
        case CirculateNotify: return "CirculateNotify";
        case CirculateRequest: return "CirculateRequest";
        case PropertyNotify: return "PropertyNotify";
        case SelectionClear: return "SelectionClear";
        case SelectionRequest: return "SelectionRequest";
        case SelectionNotify: return "SelectionNotify";
        case ColormapNotify: return "ColormapNotify";
        case ClientMessage: return "ClientMessage";
        case MappingNotify: return "MappingNotify";
        case GenericEvent: return "GenericEvent";
        default: return "UNKNOWN";
    }
}

} // namespace

namespace framework {

std::unique_ptr<window::implementation> window::implementation::get_implementation(window::size_t size,
                                                                                   const std::string& title)
{
    return std::make_unique<x11_window>(size, title);
}

x11_window::x11_window(window::size_t size, const std::string& title) : m_server(x11_server::connect()), m_size(size)
{
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
    auto color = static_cast<XID>(WhitePixel(m_server->display(), m_server->default_screen()));

    uint32 border_width = 0;
    int32 depth         = 24;
    uint32 window_class = InputOutput;
    uint64 valuemask    = CWBackPixel | CWEventMask;

    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
    Visual* visual = DefaultVisual(m_server->display(), m_server->default_screen());

    XSetWindowAttributes attributes = {};

    attributes.background_pixel = color;
    attributes.event_mask       = event_mask;

    //  attributes.background_pixmap;     // background, None, or ParentRelative      >> CWBackPixmap
    //  attributes.border_pixmap;         // border of the window or CopyFromParent   >> CWBorderPixmap
    //  attributes.border_pixel;          // border pixel value                       >> CWBorderPixel
    //  attributes.bit_gravity;           // one of bit gravity values                >> CWBitGravity
    //  attributes.win_gravity;           // one of the window gravity values         >> CWWinGravity
    //  attributes.backing_store;         // NotUseful, WhenMapped, Always            >> CWBackingStore
    //  attributes.backing_planes;        // planes to be preserved if possible       >> CWBackingPlanes
    //  attributes.backing_pixel;         // value to use in restoring planes         >> CWBackingPixel
    //  attributes.save_under;            // should bits under be saved? (popups)     >> CWSaveUnder
    //  attributes.do_not_propagate_mask; // set of events that should not propagate  >> CWDontPropagate
    //  attributes.override_redirect;     // boolean value for override_redirect      >> CWOverrideRedirect
    //  attributes.colormap;              // color map to be associated with window   >> CWColormap
    //  attributes.cursor;                // cursor to be displayed (or None)         >> CWCursor

    m_window = XCreateWindow(m_server->display(),
                             m_server->default_root_window(),
                             m_position.x,
                             m_position.y,
                             static_cast<uint32>(m_size.width),
                             static_cast<uint32>(m_size.height),
                             border_width,
                             depth,
                             window_class,
                             visual,
                             valuemask,
                             &attributes);
    XSync(m_server->display(), False);

    if (m_window == None) {
        throw std::runtime_error("Failed to create X Window.");
    }

    XSelectInput(m_server->display(), m_window, event_mask);

    set_wm_hints();
    set_class_hints();

    add_protocols({wm_delete_window_atom_name});

    create_input_context();

    set_title(title);
}

x11_window::~x11_window()
{
    if (m_server->display() != nullptr && m_window != None) {
        XDestroyWindow(m_server->display(), m_window);
        XSync(m_server->display(), False);
    }

    if (input_context != nullptr) {
        XDestroyIC(input_context);
        input_context = nullptr;
    }
}

#pragma region actions

void x11_window::show()
{
    if (m_mapped) {
        return;
    }

    XMapWindow(m_server->display(), m_window);
    XFlush(m_server->display());

    process_events_while([this]() { return !m_mapped; });

    if (m_fullscreen) {
        restore();
        switch_to_fullscreen_impl();
        process_events_while([this]() { return !fullscreen(); });
    } else if (m_maximized) {
        restore();
        maximize_impl();
        process_events_while([this]() { return !maximized(); });
    }
}

void x11_window::hide()
{
    if (!m_mapped) {
        return;
    }

    XUnmapWindow(m_server->display(), m_window);
    XFlush(m_server->display());

    process_events_while([this]() { return m_mapped; });
}

void x11_window::focus()
{
    XWindowAttributes attributes;
    XGetWindowAttributes(m_server->display(), m_window, &attributes);
    if (attributes.map_state == IsUnmapped) {
        return;
    }

    Atom net_active_window = m_server->get_atom(net_active_window_atom_name, false);
    if (utils::ewmh_supported() && net_active_window != None) {
        utils::send_client_message(m_server.get(),
                                   m_window,
                                   net_active_window,
                                   utils::message_source_application,
                                   m_lastInputTime,
                                   m_server->currently_active_window());
    } else {
        XRaiseWindow(m_server->display(), m_window);
        XSetInputFocus(m_server->display(), m_window, RevertToPointerRoot, CurrentTime);
    }

    XFlush(m_server->display());

    process_events_while([this]() { return !focused(); });
}

void x11_window::process_events()
{
    XEvent event = {0};
    while (XCheckIfEvent(m_server->display(), &event, event_predicate, reinterpret_cast<XPointer>(&m_window)) != 0) {
        if (utils::is_debug()) {
            process(event.xany);
        }

        switch (event.xany.type) {
                // case KeyPress: return "KeyPress";
                // case KeyRelease: return "KeyRelease";
                // case ButtonPress: return "ButtonPress";
                // case ButtonRelease: return "ButtonRelease";
                // case MotionNotify: return "MotionNotify";
                // case EnterNotify: return "EnterNotify";
                // case LeaveNotify: return "LeaveNotify";
                // case KeymapNotify: return "KeymapNotify"
                // case SelectionClear: return "SelectionClear";
                // case SelectionRequest: return "SelectionRequest";
                // case SelectionNotify: return "SelectionNotify";
                // case ClientMessage: return "ClientMessage";
                // case GenericEvent:  return "GenericEvent";

            case VisibilityNotify: process(event.xvisibility); break;
            case DestroyNotify: process(event.xdestroywindow); break;
            case UnmapNotify: process(event.xunmap); break;
            case ConfigureNotify: process(event.xconfigure); break;
            case FocusIn: process(event.xfocus); break;
            case FocusOut: process(event.xfocus); break;
            case PropertyNotify: process(event.xproperty); break;

            default: break;
        }
    }
}

void x11_window::iconify()
{
    if (XIconifyWindow(m_server->display(), m_window, static_cast<int>(m_server->default_screen())) == 0) {
        ::framework::log::warning(log_tag) << "Failed to iconify window." << std::endl;
        return;
    }

    XFlush(m_server->display());

    process_events_while([this]() { return !iconified(); });
}

void x11_window::maximize()
{
    if (!m_mapped) {
        m_maximized = true;
        return;
    }

    restore();

    m_saved_size = m_size;

    maximize_impl();

    m_maximized = true;

    XFlush(m_server->display());

    process_events_while([this]() { return !maximized(); });
}

void x11_window::switch_to_fullscreen()
{
    if (!m_mapped) {
        m_fullscreen = true;
        return;
    }

    restore();

    focus();

    m_saved_size = m_size;

    switch_to_fullscreen_impl();

    m_fullscreen = true;

    XFlush(m_server->display());

    process_events_while([this]() { return !fullscreen(); });
}

void x11_window::restore()
{
    if (utils::ewmh_supported() && fullscreen()) {
        utils::set_bypass_compositor_state(m_server.get(), m_window, utils::bypass_compositor_state::no_preferences);

        if (!utils::window_remove_state(m_server.get(), m_window, {net_wm_state_fullscreen_atom_name})) {
            ::framework::log::warning(log_tag) << "Failed to reset fullscreen mode." << std::endl;
            return;
        }

        set_size(m_saved_size);

        XFlush(m_server->display());

        m_fullscreen = false;

        process_events_while([this]() { return fullscreen(); });
    } else if (utils::ewmh_supported() && maximized()) {
        if (!utils::window_remove_state(m_server.get(),
                                        m_window,
                                        {net_wm_state_maximized_vert_atom_name,
                                         net_wm_state_maximized_horz_atom_name})) {
            ::framework::log::warning(log_tag) << "Failed to reset maximized state." << std::endl;
            return;
        }

        set_size(m_saved_size);

        XFlush(m_server->display());

        m_maximized = false;

        process_events_while([this]() { return maximized(); });
    } else if (iconified()) {
        XMapWindow(m_server->display(), m_window);
        XFlush(m_server->display());

        process_events_while([this]() { return !m_mapped || iconified(); });

        focus();
    }
}

#pragma endregion

#pragma region setters

void x11_window::set_size(window::size_t size)
{
    if (size.width <= 0 || size.height <= 0) {
        return;
    }

    if (m_min_size.width > 0) {
        size.width = std::max(size.width, m_min_size.width);
    }

    if (m_min_size.height > 0) {
        size.height = std::max(size.height, m_min_size.height);
    }

    if (m_max_size.width > 0) {
        size.width = std::min(size.width, m_max_size.width);
    }

    if (m_max_size.height > 0) {
        size.height = std::min(size.height, m_max_size.height);
    }

    if (!m_resizable) {
        update_size_limits(size, size);
    }

    XResizeWindow(m_server->display(), m_window, static_cast<uint32>(size.width), static_cast<uint32>(size.height));
    XFlush(m_server->display());

    process_events_while([this, size]() { return m_size != size; });
}

void x11_window::set_position(window::position_t position)
{
    XMoveWindow(m_server->display(), m_window, position.x, position.y);
    XFlush(m_server->display());
    process_events();
}

void x11_window::set_max_size(window::size_t max_size)
{
    m_max_size = max_size;

    if (m_resizable) {
        update_size_limits(m_min_size, m_max_size);
    }
}

void x11_window::set_min_size(window::size_t min_size)
{
    m_min_size = min_size;

    if (m_resizable) {
        update_size_limits(m_min_size, m_max_size);
    }
}

void x11_window::set_resizable(bool value)
{
    m_resizable = value;

    if (!m_mapped) {
        return;
    }

    if (m_resizable) {
        update_size_limits(m_min_size, m_max_size);
    } else {
        update_size_limits(m_size, m_size);
    }

    XFlush(m_server->display());
    process_events_while([this, value]() { return resizable() == value; });

    m_resizable = value;
}

void x11_window::set_title(const std::string& title)
{
    utils::set_window_name(m_server.get(), m_window, title);
    XFlush(m_server->display());
    process_events();
}

#pragma endregion

#pragma region getters

window::position_t x11_window::position() const
{
    int32 x_return, y_return;
    Window child_return;

    XTranslateCoordinates(m_server->display(),
                          m_window,
                          m_server->default_root_window(),
                          0,
                          0,
                          &x_return,
                          &y_return,
                          &child_return);

    return {x_return, y_return};
}

window::size_t x11_window::size() const
{
    XWindowAttributes attributes = {};
    XGetWindowAttributes(m_server->display(), m_window, &attributes);

    return {attributes.width, attributes.height};
}

window::size_t x11_window::max_size() const
{
    if (!m_resizable) {
        return m_max_size;
    }

    XSizeHints size_hints = {};
    int64 supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_max_size_hints = (size_hints.flags &= PMaxSize) != 0;

    if (!got_size_hints || !has_max_size_hints) {
        m_max_size = window::size_t{0, 0};
    } else {
        m_max_size = window::size_t{size_hints.max_width, size_hints.max_height};
    }

    return m_max_size;
}

window::size_t x11_window::min_size() const
{
    if (!m_resizable) {
        return m_min_size;
    }

    XSizeHints size_hints = {};
    int64 supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_min_size_hints = (size_hints.flags &= PMinSize) != 0;

    if (!got_size_hints || !has_min_size_hints) {
        m_min_size = window::size_t{0, 0};
    } else {
        m_min_size = window::size_t{size_hints.min_width, size_hints.min_height};
    }

    return m_min_size;
}

std::string x11_window::title() const
{
    return utils::get_window_name(m_server.get(), m_window);
}

#pragma endregion

#pragma region state

bool x11_window::fullscreen() const
{
    const bool in_fullscreen_state = utils::ewmh_supported()
                                     ? utils::window_has_state(m_server.get(),
                                                               m_window,
                                                               net_wm_state_fullscreen_atom_name)
                                     : false;

    return in_fullscreen_state;
}

bool x11_window::iconified() const
{
    const auto window_state = utils::get_window_wm_state(m_server.get(), m_window);
    const bool hidden       = utils::window_has_state(m_server.get(), m_window, net_wm_state_hidden_atom_name);

    return window_state == IconicState || hidden;
}

bool x11_window::maximized() const
{
    if (utils::ewmh_supported()) {
        const bool maximized_vert = utils::window_has_state(m_server.get(),
                                                            m_window,
                                                            net_wm_state_maximized_vert_atom_name);
        const bool maximized_horz = utils::window_has_state(m_server.get(),
                                                            m_window,
                                                            net_wm_state_maximized_horz_atom_name);

        return maximized_vert || maximized_horz;
    }

    return false;
}

bool x11_window::resizable() const
{
    XSizeHints size_hints = {};
    int64 supplied;

    XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied);

    const bool non_resizable = ((size_hints.flags & (PMinSize | PMaxSize)) != 0) &&
                               size_hints.min_width == size_hints.max_width &&
                               size_hints.min_height == size_hints.max_height;

    return !non_resizable;
}

bool x11_window::visible() const
{
    if (!m_mapped) {
        return false;
    }

    XWindowAttributes attributes;
    if (XGetWindowAttributes(m_server->display(), m_window, &attributes) != 0) {
        return attributes.map_state == IsViewable || (m_mapped && iconified());
    }

    ::framework::log::warning(log_tag) << "Can't detect window visibility." << std::endl;

    return false;
}

bool x11_window::focused() const
{
    return m_window == m_server->currently_active_window();
}

#pragma endregion

#pragma region event processing

void x11_window::process(XDestroyWindowEvent /*unused*/)
{}

void x11_window::process(XUnmapEvent /*unused*/)
{
    m_mapped = false;
}

void x11_window::process(XVisibilityEvent event)
{
    if (event.state != VisibilityFullyObscured) {
        m_mapped = true;
    }
}

void x11_window::process(XConfigureEvent event)
{
    window::size_t new_size{event.width, event.height};
    window::position_t new_position{event.x, event.y};

    if (m_size != new_size) {
        m_size = new_size;
    }

    if (m_position != new_position) {
        m_position = new_position;
    }
}

void x11_window::process(XFocusChangeEvent event)
{
    switch (event.type) {
        case FocusIn:
            if (input_context != nullptr) {
                XSetICFocus(input_context);
            }

            // TODO(alex): Find out how to deal with cursor
            // if (!m_cursor_grabbed) {
            //     int result = XGrabPointer(m_server->display(),
            //                               m_window,
            //                               True,
            //                               ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
            //                               GrabModeAsync,
            //                               GrabModeAsync,
            //                               None,
            //                               None,
            //                               CurrentTime);

            //     m_cursor_grabbed = (result == GrabSuccess);

            //     if (!m_cursor_grabbed) {
            //         log::warning(log_tag) << "Failed to grab mouse cursor" << std::endl;
            //     }
            // }
            break;
        case FocusOut:
            if (input_context != nullptr) {
                XUnsetICFocus(input_context);
            }

            if (m_cursor_grabbed) {
                XUngrabPointer(m_server->display(), CurrentTime);
                m_cursor_grabbed = false;
            }
            break;
    }
}

void x11_window::process(XPropertyEvent event)
{
    m_lastInputTime = event.time;
}

void x11_window::process(XAnyEvent event)
{
    ::framework::log::debug(log_tag) << "Got event: " << event_type_string(event) << std::endl;
}

#pragma endregion

#pragma region helper_functions

void x11_window::maximize_impl()
{
    // We can't maximize window without EWMH.
    if (!utils::ewmh_supported()) {
        return;
    }

    if (!utils::window_add_state(m_server.get(),
                                 m_window,
                                 {net_wm_state_maximized_vert_atom_name, net_wm_state_maximized_horz_atom_name})) {
        ::framework::log::warning(log_tag) << "Failed to set maximized state." << std::endl;
        return;
    }
}

void x11_window::switch_to_fullscreen_impl()
{
    // We can't create fullscreen window without EWMH.
    if (!utils::ewmh_supported()) {
        return;
    }

    utils::set_bypass_compositor_state(m_server.get(), m_window, utils::bypass_compositor_state::disabled);

    if (!utils::window_add_state(m_server.get(), m_window, {net_wm_state_fullscreen_atom_name})) {
        ::framework::log::warning(log_tag) << "Failed to set maximized state." << std::endl;
        return;
    }
}

void x11_window::set_wm_hints()
{
    XWMHints wm_hints      = {};
    wm_hints.flags         = StateHint | InputHint;
    wm_hints.initial_state = NormalState;
    wm_hints.input         = True;

    XSetWMHints(m_server->display(), m_window, &wm_hints);
}

void x11_window::set_class_hints()
{
    char application_name[]  = u8"The_best_game_name";
    char application_class[] = u8"The_best_game_class";

    XClassHint class_hint = {};
    class_hint.res_name   = application_name;
    class_hint.res_class  = application_class;

    XSetClassHint(m_server->display(), m_window, &class_hint);
}

void x11_window::add_protocols(const std::vector<std::string>& protocol_names)
{
    std::vector<Atom> protocols;

    for (auto& name : protocol_names) {
        Atom protocol = m_server->get_atom(name);
        if (protocol != None) {
            protocols.push_back(protocol);
        }
    }

    if (!protocols.empty()) {
        XSetWMProtocols(m_server->display(), m_window, protocols.data(), static_cast<int32>(protocols.size()));
    }
}

void x11_window::create_input_context()
{
    if (m_server->input_method() != nullptr) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg,hicpp-vararg)
        input_context = XCreateIC(m_server->input_method(),
                                  XNInputStyle,
                                  XIMPreeditNothing | XIMStatusNothing,
                                  XNClientWindow,
                                  m_window,
                                  XNFocusWindow,
                                  m_window,
                                  nullptr);
    }
}

void x11_window::process_events_while(const std::function<bool()>& condition)
{
    std::chrono::milliseconds limit(1000);
    const std::chrono::milliseconds delay(10);

    while (condition() && limit.count() > 0) {
        process_events();
        limit -= delay;
        std::this_thread::sleep_for(delay);
    }
}

void x11_window::update_size_limits(window::size_t min_size, window::size_t max_size)
{
    XSizeHints size_hints = {};
    int64 supplied;

    XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied);

    if (min_size.width > 0 && min_size.height > 0) {
        size_hints.flags |= PMinSize;
        size_hints.min_width  = min_size.width;
        size_hints.min_height = min_size.height;
    } else {
        size_hints.flags &= ~PMinSize;
    }

    if (max_size.width > 0 && max_size.height > 0) {
        size_hints.flags |= PMaxSize;
        size_hints.max_width  = max_size.width;
        size_hints.max_height = max_size.height;
    } else {
        size_hints.flags &= ~PMaxSize;
    }

    XSetWMNormalHints(m_server->display(), m_window, &size_hints);
}

#pragma endregion

} // namespace framework
