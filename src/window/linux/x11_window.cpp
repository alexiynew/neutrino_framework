/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#include <X11/Xutil.h>
#include <exception>
#include <string>

#include <common/types.hpp>
#include <common/utils.hpp>
#include <log/log.hpp>
#include <window/linux/x11_utils.hpp>
#include <window/linux/x11_window.hpp>

using namespace framework::log;

namespace {

const char* const log_tag = "x11_window";

const char* const net_wm_state_maximized_vert = u8"_NET_WM_STATE_MAXIMIZED_VERT";
const char* const net_wm_state_maximized_horz = u8"_NET_WM_STATE_MAXIMIZED_HORZ";
const char* const net_wm_state_fullscreen     = u8"_NET_WM_STATE_FULLSCREEN";
const char* const net_wm_state_hidden         = u8"_NET_WM_STATE_HIDDEN";

Bool event_predicate(Display*, XEvent* event, XPointer arg)
{
    return event->xany.window == *(reinterpret_cast<Window*>(arg));
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

std::unique_ptr<window::implementation> window::implementation::get_implementation(window::size_t size)
{
    return std::make_unique<x11_window>(size);
}

x11_window::x11_window(window::size_t size) : m_server(x11_server::connect()), m_size(size)
{
    XID color = static_cast<XID>(WhitePixel(m_server->display(), m_server->default_screen()));

    uint32 border_width = 0;
    int32 depth         = 24;
    uint32 window_class = InputOutput;
    uint64 valuemask    = CWBackPixel | CWEventMask;
    Visual* visual      = DefaultVisual(m_server->display(), m_server->default_screen());

    XSetWindowAttributes attributes = {};

    attributes.background_pixel = color;

    attributes.event_mask = VisibilityChangeMask  // Any change in visibility wanted
                            | FocusChangeMask     // Any change in input focus wanted
                            | StructureNotifyMask // Any change in window structure wanted
                            | PropertyChangeMask; // Any change in property wanted

    // | KeyPressMask             // Keyboard down events wanted
    // | KeyReleaseMask           // Keyboard up events wanted
    // | ButtonPressMask          // Pointer button down events wanted
    // | ButtonReleaseMask        // Pointer button up events wanted
    // | EnterWindowMask          // Pointer window entry events wanted
    // | LeaveWindowMask          // Pointer window leave events wanted
    // | PointerMotionMask        // Pointer motion events wanted
    // | PointerMotionHintMask    // Pointer motion hints wanted
    // | Button1MotionMask        // Pointer motion while button 1 down
    // | Button2MotionMask        // Pointer motion while button 2 down
    // | Button3MotionMask        // Pointer motion while button 3 down
    // | Button4MotionMask        // Pointer motion while button 4 down
    // | Button5MotionMask        // Pointer motion while button 5 down
    // | ButtonMotionMask         // Pointer motion while any button down
    // | KeymapStateMask          // Keyboard state wanted at window entry and focus in
    // | ExposureMask             // Any exposure wanted
    // | ResizeRedirectMask       // Redirect resize of this window
    // | SubstructureNotifyMask   // Substructure notification wanted
    // | SubstructureRedirectMask // Redirect structure requests on children
    // | ColormapChangeMask       // Any change in colormap wanted
    // | OwnerGrabButtonMask;     // Automatic grabs should activate with owner_events set to True

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

    if (!m_window) {
        throw std::runtime_error("Failed to create X Window.");
    }

    create_input_context();
}

x11_window::~x11_window()
{
    if (m_server->display() && m_window) {
        XDestroyWindow(m_server->display(), m_window);
        XSync(m_server->display(), False);
    }

    if (input_context) {
        XDestroyIC(input_context);
        input_context = nullptr;
    }
}

#pragma region actions

void x11_window::show()
{
    XMapWindow(m_server->display(), m_window);
    XFlush(m_server->display());

    while (!m_viewable) {
        process_events();
    }
}

void x11_window::hide()
{
    XUnmapWindow(m_server->display(), m_window);
    XFlush(m_server->display());

    while (m_viewable) {
        process_events();
    }
}

void x11_window::focus()
{
    XWindowAttributes attributes;
    XGetWindowAttributes(m_server->display(), m_window, &attributes);
    if (attributes.map_state == IsUnmapped) {
        return;
    }

    if (!utils::activate_window(m_server.get(), m_window, m_lastInputTime)) {
        log::error(log_tag) << "Failed to focus window." << std::endl;
    } else {
        XRaiseWindow(m_server->display(), m_window);
        XSetInputFocus(m_server->display(), m_window, RevertToPointerRoot, CurrentTime);
    }

    XFlush(m_server->display());
}

void x11_window::process_events()
{
    XEvent event = {0};
    while (XCheckIfEvent(m_server->display(), &event, event_predicate, reinterpret_cast<XPointer>(&m_window))) {
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

void x11_window::minimize()
{
    XIconifyWindow(m_server->display(), m_window, static_cast<int>(m_server->default_screen()));
    XFlush(m_server->display());
}

void x11_window::maximize()
{
    if (!utils::window_add_state(m_server.get(), m_window, {net_wm_state_maximized_vert, net_wm_state_maximized_horz})) {
        log::warning(log_tag) << "Failed to set maximized state." << std::endl;
        return;
    }

    XFlush(m_server->display());
}

void x11_window::switch_to_fullscreen()
{
    focus();

    utils::bypass_compositor_desable(m_server.get(), m_window);

    if (!utils::window_add_state(m_server.get(), m_window, {net_wm_state_fullscreen})) {
        log::warning(log_tag) << "Failed to set maximized state." << std::endl;
        return;
    }

    XFlush(m_server->display());
}

void x11_window::restore()
{
    if (minimized()) {
        XMapWindow(m_server->display(), m_window);
        XFlush(m_server->display());
        while (!m_viewable) {
            process_events();
        }
    } else if (maximized()) {
        if (!utils::window_remove_state(m_server.get(),
                                        m_window,
                                        {net_wm_state_maximized_vert, net_wm_state_maximized_horz})) {
            log::warning(log_tag) << "Failed to reset maximized state." << std::endl;
            return;
        }
        XFlush(m_server->display());
    } else if (fullscreen()) {
        utils::bypass_compositor_reset(m_server.get(), m_window);

        if (!utils::window_remove_state(m_server.get(), m_window, {net_wm_state_fullscreen})) {
            log::error(log_tag) << "Failed to reset fullscreen mode." << std::endl;
            return;
        }
        XFlush(m_server->display());
    }
}

#pragma endregion

#pragma region setters

void x11_window::set_size(window::size_t size)
{
    XResizeWindow(m_server->display(), m_window, size.width, size.height);
    XFlush(m_server->display());
}

void x11_window::set_position(window::position_t position)
{
    XMoveWindow(m_server->display(), m_window, position.x, position.y);
    XFlush(m_server->display());
}

void x11_window::set_max_size(window::size_t max_size)
{
    XSizeHints size_hints = {};
    long supplied;

    XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied);

    size_hints.flags |= PMaxSize;
    size_hints.max_width  = max_size.width;
    size_hints.max_height = max_size.height;
    XSetWMNormalHints(m_server->display(), m_window, &size_hints);
}

void x11_window::set_min_size(window::size_t min_size)
{
    XSizeHints size_hints = {};
    long supplied;

    XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied);

    size_hints.flags |= PMinSize;
    size_hints.min_width  = min_size.width;
    size_hints.min_height = min_size.height;
    XSetWMNormalHints(m_server->display(), m_window, &size_hints);
}

void x11_window::set_title(const std::string&)
{
    throw std::logic_error("Function is not implemented.");
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
    XSizeHints size_hints = {};
    long supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_max_size_hints = (size_hints.flags &= PMaxSize) != 0;

    if (!got_size_hints || !has_max_size_hints) {
        return {-1, -1};
    }

    return {size_hints.max_width, size_hints.max_height};
}

window::size_t x11_window::min_size() const
{
    XSizeHints size_hints = {};
    long supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_min_size_hints = (size_hints.flags &= PMinSize) != 0;

    if (!got_size_hints || !has_min_size_hints) {
        return {-1, -1};
    }

    return {size_hints.min_width, size_hints.min_height};
}

std::string x11_window::title() const
{
    throw std::logic_error("Function is not implemented.");
}

#pragma endregion

#pragma region state

bool x11_window::fullscreen() const
{
    return utils::window_has_state(m_server.get(), m_window, net_wm_state_fullscreen);
}

bool x11_window::minimized() const
{
    const auto state  = utils::get_window_wm_state(m_server.get(), m_window);
    const bool hidden = utils::window_has_state(m_server.get(), m_window, net_wm_state_hidden);

    return state == IconicState || hidden;
}

bool x11_window::maximized() const
{
    const bool maximized_vert = utils::window_has_state(m_server.get(), m_window, net_wm_state_maximized_vert);
    const bool maximized_horz = utils::window_has_state(m_server.get(), m_window, net_wm_state_maximized_horz);

    return maximized_vert || maximized_horz;
}

bool x11_window::resizable() const
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::visible() const
{
    if (!m_viewable) {
        return false;
    }

    XWindowAttributes attributes;
    if (XGetWindowAttributes(m_server->display(), m_window, &attributes)) {
        return attributes.map_state == IsViewable;
    } else {
        log::warning(log_tag) << "Can't detect window visibility." << std::endl;
    }

    return false;
}

bool x11_window::focused() const
{
    return m_window == m_server->currently_active_window();
}

#pragma endregion

#pragma region event processing

void x11_window::process(XDestroyWindowEvent)
{}

void x11_window::process(XUnmapEvent)
{
    m_viewable = false;
}

void x11_window::process(XVisibilityEvent event)
{
    if (event.state != VisibilityFullyObscured) {
        m_viewable = true;
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
            if (input_context) {
                XSetICFocus(input_context);
            }

            // TODO: Find out how to deal with cursor
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
            if (input_context) {
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
    log::debug(log_tag) << "Got event: " << event_type_string(event) << std::endl;
}

void x11_window::create_input_context()
{
    if (m_server->input_method()) {
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

#pragma endregion

} // namespace framework
