/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#include <exception>
#include <log/log.hpp>
#include <string>
#include <window/linux/x11_window.hpp>
#include <window/linux/x_server_connection.hpp>

using namespace framework;
using log = framework::logging::log;

namespace {

const char* const log_tag = "x11_window";

void log_x_server_errors(const std::shared_ptr<x_server_connection>& connection)
{
    while (connection->error_state() != x_server_connection::state::no_error) {
        log::error(log_tag, connection->pop_error());
    }
}

[[noreturn]] void throw_error(const std::string& message)
{
    log::error(log_tag, message);
    throw std::runtime_error(message);
}

int32 event_predicate(Display*, XEvent* event, XPointer arg)
{
    return event->xany.window == *(reinterpret_cast<Window*>(arg));
}

std::string event_type_string(const XEvent& event)
{
    switch (event.xany.type) {
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

std::unique_ptr<window_implementation> get_implementation()
{
    return std::make_unique<x11_window>();
}

x11_window::x11_window()
    : m_connection{x_server_connection::connect()}
    , m_width{640}
    , m_height{480}
    , m_window{0}
{
    if (m_connection->error_state() != x_server_connection::state::no_error) {
        throw_error(m_connection->error_message());
    }
}

x11_window::~x11_window()
{
    hide();
}

void x11_window::show()
{
    XID screen      = static_cast<XID>(DefaultScreen(m_connection->display()));
    XID root_window = static_cast<XID>(RootWindow(m_connection->display(), screen));
    XID color       = static_cast<XID>(WhitePixel(m_connection->display(), screen));

    int32 x             = 100;
    int32 y             = 100;
    uint32 border_width = 0;
    int32 depth         = 24;
    uint32 window_class = InputOutput;
    uint64 valuemask    = CWBackPixel | CWEventMask;
    Visual* visual      = DefaultVisual(m_connection->display(), screen);

    XSetWindowAttributes attributes = {};

    attributes.background_pixel = color;                // CWBackPixel
    attributes.event_mask       = VisibilityChangeMask; // CWEventMask

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


    // KeyPressMask		Keyboard down events wanted
    // KeyReleaseMask		Keyboard up events wanted
    // ButtonPressMask		Pointer button down events wanted
    // ButtonReleaseMask		Pointer button up events wanted
    // EnterWindowMask		Pointer window entry events wanted
    // LeaveWindowMask		Pointer window leave events wanted
    // PointerMotionMask		Pointer motion events wanted
    // PointerMotionHintMask		Pointer motion hints wanted
    // Button1MotionMask		Pointer motion while button 1 down
    // Button2MotionMask		Pointer motion while button 2 down
    // Button3MotionMask		Pointer motion while button 3 down
    // Button4MotionMask		Pointer motion while button 4 down
    // Button5MotionMask		Pointer motion while button 5 down
    // ButtonMotionMask		Pointer motion while any button down
    // KeymapStateMask		Keyboard state wanted at window entry and focus in
    // ExposureMask		Any exposure wanted
    // VisibilityChangeMask		Any change in visibility wanted
    // StructureNotifyMask		Any change in window structure wanted
    // ResizeRedirectMask		Redirect resize of this window
    // SubstructureNotifyMask		Substructure notification wanted
    // SubstructureRedirectMask		Redirect structure requests on children
    // FocusChangeMask		Any change in input focus wanted
    // PropertyChangeMask		Any change in property wanted
    // ColormapChangeMask		Any change in colormap wanted
    // OwnerGrabButtonMask		Automatic grabs should activate with owner_events set to True
    //
    m_connection->clear_errors();
    m_window = XCreateWindow(
    m_connection->display(), root_window, x, y, m_width, m_height, border_width, depth, window_class, visual, valuemask, &attributes);
    XSync(m_connection->display(), false);

    if (!m_window || m_connection->error_state() != x_server_connection::state::no_error) {
        log_x_server_errors(m_connection);
        throw_error("Failed to create X Window.");
    }

    // TODO catch CreateNotify event

    XMapWindow(m_connection->display(), m_window);

    XFlush(m_connection->display());
}

void x11_window::hide()
{
    if (m_connection->display() && m_window) {
        XDestroyWindow(m_connection->display(), m_window);
        XSync(m_connection->display(), false);
    }
    m_window = 0;

    // TODO catch DestroyNotify event
}

void x11_window::focus()
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::process_events()
{
    XEvent event;
    while (XCheckIfEvent(m_connection->display(), &event, event_predicate, reinterpret_cast<XPointer>(&m_window))) {
        log::info(log_tag, event_type_string(event));
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

void x11_window::set_size(int32, int32)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_position(int32, int32)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_max_size(int32, int32)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_min_size(int32, int32)
{
    throw std::logic_error("Function is not implemented.");
}

void x11_window::set_title(const std::string&)
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::x()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::y()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::width()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::height()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::max_height()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::max_width()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::min_height()
{
    throw std::logic_error("Function is not implemented.");
}

int x11_window::min_width()
{
    throw std::logic_error("Function is not implemented.");
}

std::string x11_window::title()
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::full_screen()
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::minimized()
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::maximized()
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::resizable()
{
    throw std::logic_error("Function is not implemented.");
}

bool x11_window::visible()
{
    XWindowAttributes attributes;
    if (XGetWindowAttributes(m_connection->display(), m_window, &attributes)) {
        return attributes.map_state == IsViewable;
    } else {
        log_x_server_errors(m_connection);
    }

    return false;
}

bool x11_window::focused()
{
    throw std::logic_error("Function is not implemented.");
}

} // namespace framework
