/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#include <common/utils.hpp>
#include <exception>
#include <log/log.hpp>
#include <string>
#include <window/linux/x11_window.hpp>

using namespace framework::log;

namespace {

const char* const log_tag = "x11_window";

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

std::unique_ptr<window::implementation> window::implementation::get_implementation()
{
    return std::make_unique<x11_window>();
}

x11_window::x11_window()
{
    m_server = x11_server::connect();

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

    Atom net_active_window = m_server->get_atom(u8"_NET_ACTIVE_WINDOW", false);
    if (m_server->ewmh_supported() && net_active_window != None) {

        XEvent event               = {0};
        event.type                 = ClientMessage;
        event.xclient.window       = m_window;
        event.xclient.message_type = net_active_window;
        event.xclient.format       = 32;

        event.xclient.data.l[0] = 1;                                                      // source -> from application
        event.xclient.data.l[1] = static_cast<long>(m_lastInputTime);                     // timestamp
        event.xclient.data.l[2] = static_cast<long>(m_server->currently_active_window()); // currently active window ID

        if (!XSendEvent(m_server->display(),
                        DefaultRootWindow(m_server->display()),
                        False,
                        SubstructureNotifyMask | SubstructureRedirectMask,
                        &event)) {
            log::error(log_tag) << "Failed to send the \"_NET_ACTIVE_WINDOW\" client message." << std::endl;
        }
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
    throw std::logic_error("Function is not implemented.");
}

void x11_window::maximize()
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::to_full_screen()
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::restore()
{
    throw std::logic_error("Function is not implemented.");
}

#pragma endregion

#pragma region setters

void x11_window::set_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_position(window::position_t)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_max_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_min_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_title(const std::string&)
{
    throw std::logic_error("Function is not implemented.");
}

#pragma endregion

#pragma region getters

window::position_t x11_window::position() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t x11_window::size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t x11_window::max_size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t x11_window::min_size() const
{
    throw std::logic_error("Function is not implemented.");
}

std::string x11_window::title() const
{
    throw std::logic_error("Function is not implemented.");
}

#pragma endregion

#pragma region state

bool x11_window::full_screen() const
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::minimized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::maximized() const
{
    throw std::logic_error("Function is not implemented.");
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
{
}

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

            if (!m_cursor_grabbed) {
                int result = XGrabPointer(m_server->display(),
                                          m_window,
                                          True,
                                          ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
                                          GrabModeAsync,
                                          GrabModeAsync,
                                          None,
                                          None,
                                          CurrentTime);

                m_cursor_grabbed = (result == GrabSuccess);

                if (!m_cursor_grabbed) {
                    log::warning(log_tag) << "Failed to grab mouse cursor" << std::endl;
                }
            }
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
