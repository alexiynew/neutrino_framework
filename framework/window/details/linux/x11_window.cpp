/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <X11/XKBlib.h>
#include <X11/Xutil.h>
#include <chrono>
#include <exception>
#include <set>
#include <string>
#include <thread>

#include <common/types.hpp>
#include <common/utils.hpp>
#include <graphics/opengl/details/linux/glx_context.hpp>
#include <window/details/linux/x11_keyboard.hpp>
#include <window/details/linux/x11_mouse.hpp>
#include <window/details/linux/x11_utils.hpp>
#include <window/details/linux/x11_window.hpp>

namespace
{
using ::framework::int32;
using ::framework::int64;
using ::framework::uint8;

const char* const log_tag = "x11_window";

const char* const net_wm_state_maximized_vert_atom_name = u8"_NET_WM_STATE_MAXIMIZED_VERT";
const char* const net_wm_state_maximized_horz_atom_name = u8"_NET_WM_STATE_MAXIMIZED_HORZ";
const char* const net_wm_state_fullscreen_atom_name     = u8"_NET_WM_STATE_FULLSCREEN";
const char* const net_wm_state_hidden_atom_name         = u8"_NET_WM_STATE_HIDDEN";
const char* const net_active_window_atom_name           = u8"_NET_ACTIVE_WINDOW";
const char* const wm_delete_window_atom_name            = u8"WM_DELETE_WINDOW";

const int64 event_mask = VisibilityChangeMask  // Any change in visibility wanted
                         | FocusChangeMask     // Any change in input focus wanted
                         | StructureNotifyMask // Any change in window structure wanted
                         | PropertyChangeMask  // Any change in property wanted
                         | ExposureMask        // Any exposure wanted
                         | KeyPressMask        // Keyboard down events wanted
                         | KeyReleaseMask      // Keyboard up events wanted
                         | ButtonPressMask     // Pointer button down events wanted
                         | ButtonReleaseMask   // Pointer button up events wanted
                         | EnterWindowMask     // Pointer window entry events wanted
                         | LeaveWindowMask     // Pointer window leave events wanted
                         | PointerMotionMask   // Pointer motion events wanted
                         | ButtonMotionMask;   // Pointer motion while any button down

// | Button1MotionMask        // Pointer motion while button 1 down
// | Button2MotionMask        // Pointer motion while button 2 down
// | Button3MotionMask        // Pointer motion while button 3 down
// | Button4MotionMask        // Pointer motion while button 4 down
// | Button5MotionMask        // Pointer motion while button 5 down
// | KeymapStateMask          // Keyboard state wanted at window entry and focus in
// | ResizeRedirectMask       // Redirect resize of this window
// | SubstructureNotifyMask   // Substructure notification wanted
// | SubstructureRedirectMask // Redirect structure requests on children
// | ColormapChangeMask       // Any change in colormap wanted
// | OwnerGrabButtonMask;     // Automatic grabs should activate with owner_events set to True
// | PointerMotionHintMask    // Pointer motion hints wanted

// NOLINTNEXTLINE(readability-non-const-parameter)
Bool event_predicate(Display* /*unused*/, XEvent* event, XPointer arg)
{
    return static_cast<Bool>(event->xany.window == *(reinterpret_cast<Window*>(arg)));
}

} // namespace

namespace framework::system::details
{
x11_window::x11_window(window_size size, const std::string& title, opengl::context_settings settings)
    : m_server(x11_server::connect()), m_size(size)
{
    auto context = std::make_unique<glx_context>(m_server->display(), std::move(settings));
    if (!context->valid()) {
        throw std::runtime_error("Can't create graphic context.");
    }

    XSetWindowAttributes attributes = {};

    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
    attributes.background_pixel = static_cast<XID>(WhitePixel(m_server->display(), m_server->default_screen()));
    attributes.event_mask       = event_mask;
    attributes.colormap         = context->colormap();

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

    const uint32 border_width = 0;
    const uint32 window_class = InputOutput;
    const uint64 valuemask    = CWBackPixel | CWEventMask | CWColormap;

    m_window = XCreateWindow(m_server->display(),
                             m_server->default_root_window(),
                             m_position.x,
                             m_position.y,
                             static_cast<uint32>(m_size.width),
                             static_cast<uint32>(m_size.height),
                             border_width,
                             context->visual_info()->depth,
                             window_class,
                             context->visual_info()->visual,
                             valuemask,
                             &attributes);
    XSync(m_server->display(), False);

    if (m_window == None) {
        throw std::runtime_error("Failed to create X Window.");
    }

    context->attach_window(m_window);

    m_context = std::move(context);

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

    if (m_input_context != nullptr) {
        XDestroyIC(m_input_context);
        m_input_context = nullptr;
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
        maximize_toggle(false);
        fullscreen_toggle(true);
        XFlush(m_server->display());
        process_events_while([this]() { return !fullscreen(); });
    } else if (m_maximized) {
        maximize_toggle(true);
        XFlush(m_server->display());
        process_events_while([this]() { return !maximized(); });
    } else if (!m_resizable) {
        update_size_limits(m_size, m_size);
        XFlush(m_server->display());
        process_events_while([this]() { return resizable(); });
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
                                   m_server->active_window());
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
        switch (event.xany.type) {
                // case KeymapNotify: return "KeymapNotify"
                // case GenericEvent:  return "GenericEvent";

            case VisibilityNotify: process(event.xvisibility); break;
            case DestroyNotify: process(event.xdestroywindow); break;
            case UnmapNotify: process(event.xunmap); break;
            case ConfigureNotify: process(event.xconfigure); break;
            case FocusIn: process(event.xfocus); break;
            case FocusOut: process(event.xfocus); break;
            case PropertyNotify: process(event.xproperty); break;
            case ClientMessage: process(event.xclient); break;
            case KeyPress: process(event.xkey); break;
            case KeyRelease: process(event.xkey); break;
            case ButtonPress: process(event.xbutton); break;
            case ButtonRelease: process(event.xbutton); break;
            case EnterNotify: process(event.xcrossing); break;
            case LeaveNotify: process(event.xcrossing); break;
            case MotionNotify: process(event.xmotion); break;
            case MappingNotify: process(event.xmapping); break;

            default: break;
        }
    }
}

void x11_window::iconify()
{
    if (XIconifyWindow(m_server->display(), m_window, static_cast<int>(m_server->default_screen())) == 0) {
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

    maximize_toggle(true);

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

    fullscreen_toggle(true);

    m_fullscreen = true;

    XFlush(m_server->display());

    process_events_while([this]() { return !fullscreen(); });
}

void x11_window::restore()
{
    if (fullscreen()) {
        fullscreen_toggle(false);

        set_size(m_saved_size);

        XFlush(m_server->display());

        process_events_while([this]() { return fullscreen(); });

        m_fullscreen = false;
    } else if (utils::ewmh_supported() && maximized()) {
        maximize_toggle(false);

        set_size(m_saved_size);

        XFlush(m_server->display());

        process_events_while([this]() { return maximized(); });

        m_maximized = false;
    } else if (iconified()) {
        XMapWindow(m_server->display(), m_window);
        XFlush(m_server->display());

        process_events_while([this]() { return !m_mapped || iconified(); });

        focus();
    }
}

#pragma endregion

#pragma region setters

void x11_window::set_size(window_size size)
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

void x11_window::set_position(window_position position)
{
    XMoveWindow(m_server->display(), m_window, position.x, position.y);
    XFlush(m_server->display());
    process_events();
}

void x11_window::set_max_size(window_size max_size)
{
    m_max_size = max_size;

    if (m_resizable) {
        update_size_limits(m_min_size, m_max_size);
    }
}

void x11_window::set_min_size(window_size min_size)
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
    process_events_while([this]() { return resizable() != m_resizable; });
}

void x11_window::set_title(const std::string& title)
{
    utils::set_window_name(m_server.get(), m_window, title);
    XFlush(m_server->display());
    process_events();
}

#pragma endregion

#pragma region getters

window_position x11_window::position() const
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

window_size x11_window::size() const
{
    XWindowAttributes attributes = {};
    XGetWindowAttributes(m_server->display(), m_window, &attributes);

    return {attributes.width, attributes.height};
}

window_size x11_window::max_size() const
{
    if (!m_resizable) {
        return m_max_size;
    }

    XSizeHints size_hints = {};
    int64 supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_max_size_hints = (size_hints.flags &= PMaxSize) != 0;

    if (!got_size_hints || !has_max_size_hints) {
        m_max_size = window_size{0, 0};
    } else {
        m_max_size = window_size{size_hints.max_width, size_hints.max_height};
    }

    return m_max_size;
}

window_size x11_window::min_size() const
{
    if (!m_resizable) {
        return m_min_size;
    }

    XSizeHints size_hints = {};
    int64 supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_min_size_hints = (size_hints.flags &= PMinSize) != 0;

    if (!got_size_hints || !has_min_size_hints) {
        m_min_size = window_size{0, 0};
    } else {
        m_min_size = window_size{size_hints.min_width, size_hints.min_height};
    }

    return m_min_size;
}

std::string x11_window::title() const
{
    return utils::get_window_name(m_server.get(), m_window);
}

framework::opengl::context* x11_window::context() const
{
    return m_context.get();
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

    return in_fullscreen_state && m_fullscreen;
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

        return (maximized_vert || maximized_horz); // && m_maximized;
    }

    return false;
}

bool x11_window::resizable() const
{
    XSizeHints size_hints = {};
    int64 supplied;

    XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied);

    const bool not_resizable = ((size_hints.flags & (PMinSize | PMaxSize)) != 0) &&
                               size_hints.min_width == size_hints.max_width &&
                               size_hints.min_height == size_hints.max_height;

    return !not_resizable;
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

    return false;
}

bool x11_window::focused() const
{
    return m_window == m_server->active_window();
}

#pragma endregion

#pragma region event processing

void x11_window::process(XDestroyWindowEvent /*unused*/)
{}

void x11_window::process(XUnmapEvent /*unused*/)
{
    m_mapped = false;
    if (m_event_handler) {
        m_event_handler->on_hide();
    }
}

void x11_window::process(XVisibilityEvent event)
{
    if (event.state == VisibilityFullyObscured) {
        return;
    }

    if (!m_mapped) {
        m_mapped = true;

        if (m_event_handler) {
            m_event_handler->on_show();
        }
    }
}

void x11_window::process(XConfigureEvent event)
{
    window_size new_size{event.width, event.height};
    window_position new_position{event.x, event.y};

    if (m_size != new_size) {
        m_size = new_size;

        if (m_event_handler) {
            m_event_handler->on_size(m_size);
        }
    }

    if (m_position != new_position) {
        m_position = new_position;

        if (m_event_handler) {
            m_event_handler->on_position(m_position);
        }
    }
}

void x11_window::process(XFocusChangeEvent event)
{
    switch (event.type) {
        case FocusIn:
            if (m_input_context != nullptr) {
                XSetICFocus(m_input_context);
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

            if (m_event_handler) {
                m_event_handler->on_focus();
            }

            break;
        case FocusOut:
            if (m_input_context != nullptr) {
                XUnsetICFocus(m_input_context);
            }

            if (m_cursor_grabbed) {
                XUngrabPointer(m_server->display(), CurrentTime);
                m_cursor_grabbed = false;
            }

            if (m_event_handler) {
                m_event_handler->on_focus_lost();
            }
            break;
    }
}

void x11_window::process(XPropertyEvent event)
{
    m_lastInputTime = event.time;
}

void x11_window::process(XClientMessageEvent event)
{
    Atom delete_window = m_server->get_atom(wm_delete_window_atom_name);
    if (static_cast<Atom>(event.data.l[0]) == delete_window && m_event_handler) {
        m_event_handler->on_close();
    }
}

void x11_window::process(XKeyEvent event)
{
    if (!m_event_handler) {
        return;
    }

    const key_code key          = details::map_system_key(event.keycode);
    const modifiers_state state = details::get_modifiers_state(event.state);

    if (key == key_code::key_unknown) {
        return;
    }

    switch (event.type) {
        case KeyPress: {
            m_event_handler->on_key_press(key, state);

            if (X_HAVE_UTF8_STRING) {
                char buffer[64] = {0};
                KeySym sym;
                int32 count = Xutf8LookupString(m_input_context, &event, buffer, sizeof(buffer), &sym, nullptr);

                if (count > 0) {
                    m_event_handler->on_character(std::string(buffer));
                }
            }
        } break;

        case KeyRelease: {
            const bool is_retriggered = [this](XKeyEvent e) {
                if (XEventsQueued(m_server->display(), QueuedAfterReading)) {
                    XEvent next_event;
                    XPeekEvent(m_server->display(), &next_event);

                    return (next_event.type == KeyPress && next_event.xkey.time == e.time &&
                            next_event.xkey.keycode == e.keycode);
                }
                return false;
            }(event);

            if (!is_retriggered) {
                m_event_handler->on_key_release(key, state);
            }
        } break;
    }
}

void x11_window::process(XButtonEvent event)
{
    if (!m_event_handler) {
        return;
    }

    const mouse_button button      = details::map_mouse_button(event.button);
    const modifiers_state state    = details::get_modifiers_state(event.state);
    const cursor_position position = {event.x, event.y};

    if (button == mouse_button::button_unknown) {
        return;
    }

    switch (event.type) {
        case ButtonPress: m_event_handler->on_mouse_press(button, position, state); break;
        case ButtonRelease: m_event_handler->on_mouse_release(button, position, state); break;
    }
}

void x11_window::process(XCrossingEvent event)
{
    if (!m_event_handler) {
        return;
    }

    switch (event.type) {
        case EnterNotify: m_event_handler->on_mouse_enter(); break;
        case LeaveNotify: m_event_handler->on_mouse_leave(); break;
    }
}

void x11_window::process(XMotionEvent event)
{
    if (m_event_handler) {
        m_event_handler->on_mouse_move({event.x, event.y});
    }
}

void x11_window::process(XMappingEvent event)
{
    XRefreshKeyboardMapping(&event);
}

#pragma endregion

#pragma region helper_functions

void x11_window::maximize_toggle(bool enable)
{
    // We can't maximize window without EWMH.
    if (!utils::ewmh_supported()) {
        return;
    }

    const std::vector<std::string> state = {net_wm_state_maximized_vert_atom_name,
                                            net_wm_state_maximized_horz_atom_name};

    auto action = enable ? utils::window_state_action::add : utils::window_state_action::remove;

    if (!utils::window_change_state(m_server.get(), m_window, action, state)) {
        // report error
        //        warning(log_tag) << "Failed to " << (enable ? "set" : "reset") << " maximized state." << std::endl;
    }
}

void x11_window::fullscreen_toggle(bool enable)
{
    // We can't create fullscreen window without EWMH.
    if (!utils::ewmh_supported()) {
        return;
    }

    auto bypass_state = enable ? utils::bypass_compositor_state::disabled
                               : utils::bypass_compositor_state::no_preferences;
    utils::set_bypass_compositor_state(m_server.get(), m_window, bypass_state);

    const std::vector<std::string> state = {net_wm_state_fullscreen_atom_name};

    auto action = enable ? utils::window_state_action::add : utils::window_state_action::remove;

    if (!utils::window_change_state(m_server.get(), m_window, action, state)) {
        // report error
        // warning(log_tag) << "Failed to " << (enable ? "set" : "reset") << " fullscreen mode." << std::endl;
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
    std::string class_name = application_name + "_class";

    std::vector<char> res_name(application_name.begin(), application_name.end());
    std::vector<char> res_class(class_name.begin(), class_name.end());

    XClassHint class_hint = {};
    class_hint.res_name   = res_name.data();
    class_hint.res_class  = res_class.data();

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
        m_input_context = XCreateIC(m_server->input_method(),
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
    using std::chrono::milliseconds;

    milliseconds limit(1000);
    const milliseconds delay(50);

    while (condition() && limit.count() > 0) {
        process_events();
        limit -= delay;
        std::this_thread::sleep_for(delay);
    }
}

void x11_window::update_size_limits(window_size min_size, window_size max_size)
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

} // namespace framework::system::details
