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
}

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
    , m_state(state_flags_count, false)
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
    uint64 valuemask    = CWBackPixel;
    Visual* visual      = DefaultVisual(m_connection->display(), screen);

    XSetWindowAttributes attributes = {};

    attributes.background_pixel = color; //          background pixel                         >> CWBackPixel
    //  attributes.background_pixmap;     // background, None, or ParentRelative      >> CWBackPixmap
    //  attributes.border_pixmap;         // border of the window or CopyFromParent   >> CWBorderPixmap
    //  attributes.border_pixel;          // border pixel value                       >> CWBorderPixel
    //  attributes.bit_gravity;           // one of bit gravity values                >> CWBitGravity
    //  attributes.win_gravity;           // one of the window gravity values         >> CWWinGravity
    //  attributes.backing_store;         // NotUseful, WhenMapped, Always            >> CWBackingStore
    //  attributes.backing_planes;        // planes to be preserved if possible       >> CWBackingPlanes
    //  attributes.backing_pixel;         // value to use in restoring planes         >> CWBackingPixel
    //  attributes.save_under;            // should bits under be saved? (popups)     >> CWOverrideRedirect
    //  attributes.event_mask;            // set of events that should be saved       >> CWSaveUnder
    //  attributes.do_not_propagate_mask; // set of events that should not propagate  >> CWEventMask
    //  attributes.override_redirect;     // boolean value for override_redirect      >> CWDontPropagate
    //  attributes.colormap;              // color map to be associated with window   >> CWColormap
    //  attributes.cursor;                // cursor to be displayed (or None)         >> CWCursor

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
    }
    m_window = 0;

    // TODO catch DestroyNotify event
}

void x11_window::focus()
{
    throw std::logic_error("Function is not implemented.");
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

std::vector<bool> x11_window::state()
{
    return m_state;
}
} // namespace framework
