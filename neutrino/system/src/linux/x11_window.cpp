#include <chrono>
#include <exception>
#include <set>
#include <string>
#include <thread>

#include <common/utils.hpp>
#include <system/application.hpp>

#include <system/src/linux/x11_glx_context.hpp>
#include <system/src/linux/x11_keyboard.hpp>
#include <system/src/linux/x11_mouse.hpp>
#include <system/src/linux/x11_utils.hpp>
#include <system/src/linux/x11_window.hpp>

#include <X11/XKBlib.h>
#include <X11/Xutil.h>

namespace
{
const char* const net_active_window_atom_name           = u8"_NET_ACTIVE_WINDOW";
const char* const net_frame_extents_atom_name           = u8"_NET_FRAME_EXTENTS";
const char* const net_wm_state_fullscreen_atom_name     = u8"_NET_WM_STATE_FULLSCREEN";
const char* const net_wm_state_hidden_atom_name         = u8"_NET_WM_STATE_HIDDEN";
const char* const net_wm_state_maximized_horz_atom_name = u8"_NET_WM_STATE_MAXIMIZED_HORZ";
const char* const net_wm_state_maximized_vert_atom_name = u8"_NET_WM_STATE_MAXIMIZED_VERT";
const char* const wm_delete_window_atom_name            = u8"WM_DELETE_WINDOW";

const std::int64_t event_mask = VisibilityChangeMask  // Any change in visibility wanted
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

Bool event_predicate(Display* /*unused*/, XEvent* event, XPointer arg)
{
    return static_cast<Bool>(event->xany.window == *(reinterpret_cast<Window*>(arg)));
}

} // namespace

namespace framework::system::details
{
X11Window::X11Window(const std::string& title, Size size, const ContextSettings& settings)
    : m_server(X11Server::connect())
    , m_size(size)
{
    auto context = std::make_unique<X11GlxContext>(settings, m_server->display());
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

    const std::uint32_t border_width = 0;
    const std::uint32_t window_class = InputOutput;
    const std::uint64_t valuemask    = CWBackPixel | CWEventMask | CWColormap;

    m_window = XCreateWindow(m_server->display(),
                             m_server->default_root_window(),
                             m_position.x,
                             m_position.y,
                             static_cast<std::uint32_t>(m_size.width),
                             static_cast<std::uint32_t>(m_size.height),
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

X11Window::~X11Window()
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

void X11Window::show()
{
    // Remember last position before showing window. In case if we want to set it again.
    const auto target_pos = m_position;

    // Map window on screen
    XMapWindow(m_server->display(), m_window);
    XFlush(m_server->display());
    process_events_while([this]() { return !m_mapped; });

    // Get window frame sizes
    m_frame_extents = utils::get_frame_extents(m_server.get(), m_window);

    // Set old window position if needed
    if (target_pos != Position{0, 0}) {
        m_position = {0, 0};
        move_window(target_pos);
    }

    // if (m_fullscreen) {
    //     maximize_toggle(false);
    //     fullscreen_toggle(true);
    //     XFlush(m_server->display());
    //     // process_events_while([this]() { return !is_fullscreen(); });
    // } else if (m_maximized) {
    //     maximize_toggle(true);
    //     XFlush(m_server->display());
    //     // process_events_while([this]() { return !is_maximized(); });
    // } else if (!m_resizable) {
    //     update_size_limits(m_size, m_size);
    //     XFlush(m_server->display());
    //     // process_events_while([this]() { return is_resizable(); });
    // }
}

void X11Window::hide()
{
    XUnmapWindow(m_server->display(), m_window);
    XFlush(m_server->display());

    process_events_while([this]() { return m_mapped || has_input_focus(); });
}

void X11Window::focus()
{
    if (!is_visible() || has_input_focus()) {
        return;
    }

    const Atom net_active_window = m_server->get_atom(net_active_window_atom_name, false);
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

    m_wait_focus = true;
    process_events_while([this]() { return m_wait_focus; });
}

void X11Window::enable_raw_input()
{}

void X11Window::disable_raw_input()
{}

void X11Window::process_events()
{
    XEvent event = {0};
    while (XCheckIfEvent(m_server->display(), &event, event_predicate, reinterpret_cast<XPointer>(&m_window)) != 0) {
        switch (event.xany.type) {
                // case KeymapNotify: return "KeymapNotify"
                // case GenericEvent:  return "GenericEvent";

                // TODO:: Pocess mouse scroll event

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

#pragma endregion

#pragma region setters

void X11Window::set_state(Window::State state)
{
    if (!m_mapped) {
        m_state = state;
        return;
    }

    // void X11Window::iconify()
    //{
    //     if (XIconifyWindow(m_server->display(), m_window, static_cast<int>(m_server->default_screen())) == 0) {
    //         return;
    //     }
    //
    //     XFlush(m_server->display());
    //
    //     process_events_while([this]() { return !is_iconified(); });
    // }

    // void X11Window::maximize()
    // {
    //     if (!m_mapped) {
    //         m_maximized = true;
    //         return;
    //     }
    //
    //     restore();
    //
    //     m_saved_size = m_size;
    //
    //     maximize_toggle(true);
    //
    //     m_maximized = true;
    //
    //     XFlush(m_server->display());
    //
    //     process_events_while([this]() { return !is_maximized(); });
    // }
    //
    // void X11Window::fullscreen()
    // {
    //     if (!m_mapped) {
    //         m_fullscreen = true;
    //         return;
    //     }
    //
    //     restore();
    //
    //     focus();
    //
    //     m_saved_size = m_size;
    //
    //     fullscreen_toggle(true);
    //
    //     m_fullscreen = true;
    //
    //     XFlush(m_server->display());
    //
    //     process_events_while([this]() { return !is_fullscreen(); });
    // }
    //
    // void X11Window::restore()
    // {
    //     if (is_fullscreen()) {
    //         fullscreen_toggle(false);
    //
    //         resize(m_saved_size);
    //
    //         XFlush(m_server->display());
    //
    //         process_events_while([this]() { return is_fullscreen(); });
    //
    //         m_fullscreen = false;
    //     } else if (utils::ewmh_supported() && is_maximized()) {
    //         maximize_toggle(false);
    //
    //         resize(m_saved_size);
    //
    //         XFlush(m_server->display());
    //
    //         process_events_while([this]() { return is_maximized(); });
    //
    //         m_maximized = false;
    //     } else if (is_iconified()) {
    //         XMapWindow(m_server->display(), m_window);
    //         XFlush(m_server->display());
    //
    //         process_events_while([this]() { return !m_mapped || is_iconified(); });
    //
    //         focus();
    //     }
    // }
}

void X11Window::set_size(Size size)
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

    XResizeWindow(m_server->display(),
                  m_window,
                  static_cast<std::uint32_t>(size.width),
                  static_cast<std::uint32_t>(size.height));
    XFlush(m_server->display());

    process_events_while([this, size]() { return m_size != size; });
}

void X11Window::set_max_size(Size max_size)
{
    m_max_size = max_size;

    if (m_resizable) {
        update_size_limits(m_min_size, m_max_size);
    }
}

void X11Window::set_min_size(Size min_size)
{
    m_min_size = min_size;

    if (m_resizable) {
        update_size_limits(m_min_size, m_max_size);
    }
}

void X11Window::set_resizable(bool value)
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
    process_events_while([this]() { return is_resizable() != m_resizable; });
}

void X11Window::set_position(Position new_position)
{
    if (!m_mapped) {
        m_position = new_position;
    } else {
        move_window(new_position);
    }
}

void X11Window::set_title(const std::string& title)
{
    utils::set_window_name(m_server.get(), m_window, title);
    XFlush(m_server->display());
    process_events();
}

void X11Window::set_cursor_visibility(bool /*visible*/)
{}

#pragma endregion

#pragma region getters

bool X11Window::is_visible() const
{
    if (!m_mapped) {
        return false;
    }

    XWindowAttributes attributes;
    if (XGetWindowAttributes(m_server->display(), m_window, &attributes) != 0) {
        return attributes.map_state == IsViewable; // || (m_mapped && is_iconified());
    }

    return false;
}

bool X11Window::has_input_focus() const
{
    return is_visible() && m_window == m_server->active_window();
}

bool X11Window::is_cursor_visible() const
{
    return false;
}

Window::State X11Window::state() const
{
    return m_state;

    // bool X11Window::is_fullscreen() const
    // {
    //     const bool in_fullscreen_state = utils::ewmh_supported() ?
    //                                      utils::window_has_state(m_server.get(),
    //                                                              m_window,
    //                                                              net_wm_state_fullscreen_atom_name) :
    //                                      false;
    //
    //     return in_fullscreen_state && m_fullscreen;
    // }
    //
    // bool X11Window::is_iconified() const
    // {
    //     const auto window_state = utils::get_window_wm_state(m_server.get(), m_window);
    //     const bool hidden       = utils::window_has_state(m_server.get(), m_window, net_wm_state_hidden_atom_name);
    //
    //     return window_state == IconicState || hidden;
    // }
    //
    // bool X11Window::is_maximized() const
    // {
    //     if (utils::ewmh_supported()) {
    //         const bool maximized_vert = utils::window_has_state(m_server.get(),
    //                                                             m_window,
    //                                                             net_wm_state_maximized_vert_atom_name);
    //         const bool maximized_horz = utils::window_has_state(m_server.get(),
    //                                                             m_window,
    //                                                             net_wm_state_maximized_horz_atom_name);
    //
    //         return (maximized_vert || maximized_horz);
    //     }
    //
    //     return false;
    // }
}

Size X11Window::size() const
{
    return m_size;
}

Size X11Window::max_size() const
{
    if (!m_resizable) {
        return m_max_size;
    }

    XSizeHints size_hints = {};
    std::int64_t supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_max_size_hints = (size_hints.flags &= PMaxSize) != 0;

    if (!got_size_hints || !has_max_size_hints) {
        m_max_size = Size{0, 0};
    } else {
        m_max_size = Size{size_hints.max_width, size_hints.max_height};
    }

    return m_max_size;
}

Size X11Window::min_size() const
{
    if (!m_resizable) {
        return m_min_size;
    }

    XSizeHints size_hints = {};
    std::int64_t supplied;

    const bool got_size_hints     = XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied) != 0;
    const bool has_min_size_hints = (size_hints.flags &= PMinSize) != 0;

    if (!got_size_hints || !has_min_size_hints) {
        m_min_size = Size{0, 0};
    } else {
        m_min_size = Size{size_hints.min_width, size_hints.min_height};
    }

    return m_min_size;
}

bool X11Window::is_resizable() const
{
    XSizeHints size_hints = {};
    std::int64_t supplied;

    XGetWMNormalHints(m_server->display(), m_window, &size_hints, &supplied);

    const bool not_resizable = ((size_hints.flags & (PMinSize | PMaxSize)) != 0) &&
                               size_hints.min_width == size_hints.max_width &&
                               size_hints.min_height == size_hints.max_height;

    return !not_resizable;
}

Position X11Window::position() const
{
    return m_position;
}

std::string X11Window::title() const
{
    return utils::get_window_name(m_server.get(), m_window);
}

const Context& X11Window::context() const
{
    if (!m_context) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *m_context;
}

Context& X11Window::context()
{
    if (!m_context) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *m_context;
}

#pragma endregion

#pragma region event_processing

void X11Window::process(XDestroyWindowEvent /*unused*/)
{}

void X11Window::process(XUnmapEvent /*unused*/)
{
    m_mapped = false;
    callbacks().on_hide();
}

void X11Window::process(XVisibilityEvent event)
{
    if (event.state == VisibilityFullyObscured) {
        return;
    }

    if (!m_mapped) {
        m_mapped = true;
    }
}

void X11Window::process(XConfigureEvent event)
{
    Size new_size{event.width, event.height};
    Position new_position{event.x, event.y};

    if (m_size != new_size) {
        m_size = new_size;
        if (is_visible()) {
            callbacks().on_resize(m_size);
        }
    }

    if (m_position != new_position) {
        m_position = new_position;
        if (is_visible()) {
            callbacks().on_move(m_position);
        }
    }
}

void X11Window::process(XFocusChangeEvent event)
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
            m_wait_focus = false;
            on_focus();
            break;
        case FocusOut:
            if (m_input_context != nullptr) {
                XUnsetICFocus(m_input_context);
            }

            // if (m_cursor_grabbed) {
            //     XUngrabPointer(m_server->display(), CurrentTime);
            //     m_cursor_grabbed = false;
            // }

            on_lost_focus();
            break;
    }
}

void X11Window::process(XPropertyEvent event)
{
    const Atom frame_extents_atom = m_server->get_atom(net_frame_extents_atom_name);
    if (event.atom == frame_extents_atom) {
        m_frame_extents = utils::get_frame_extents(m_server.get(), m_window);
    }

    m_lastInputTime = event.time;
}

void X11Window::process(XClientMessageEvent event)
{
    const Atom delete_window = m_server->get_atom(wm_delete_window_atom_name);
    const Atom event_atom    = static_cast<Atom>(event.data.l[0]);
    if (event_atom == delete_window) {
        on_close();
    }
}

void X11Window::process(XKeyEvent event)
{
    const KeyCode key     = details::map_system_key(event.keycode);
    const Modifiers state = details::get_modifiers_state(event.state);

    if (key == KeyCode::unknown) {
        return;
    }

    switch (event.type) {
        case KeyPress: {
            callbacks().on_key_down(key, state);

            if (X_HAVE_UTF8_STRING) {
                char buffer[64] = {0};
                KeySym sym;
                int count = Xutf8LookupString(m_input_context, &event, buffer, sizeof(buffer), &sym, nullptr);

                if (count > 0) {
                    callbacks().on_character(std::string(buffer));
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
                callbacks().on_key_up(key, state);
            }
        } break;
    }
}

void X11Window::process(XButtonEvent event)
{
    const MouseButton button      = details::map_mouse_button(event.button);
    const Modifiers state         = details::get_modifiers_state(event.state);
    const CursorPosition position = {event.x, event.y};

    if (button == MouseButton::unknown) {
        return;
    }

    switch (event.type) {
        case ButtonPress: callbacks().on_mouse_button_down(button, position, state); break;
        case ButtonRelease: callbacks().on_mouse_button_up(button, position, state); break;
    }
}

void X11Window::process(XCrossingEvent event)
{
    switch (event.type) {
        case EnterNotify: callbacks().on_mouse_enter(); break;
        case LeaveNotify: callbacks().on_mouse_leave(); break;
    }
}

void X11Window::process(XMotionEvent event)
{
    callbacks().on_mouse_move({event.x, event.y});
}

void X11Window::process(XMappingEvent event)
{
    XRefreshKeyboardMapping(&event);
}

#pragma endregion

#pragma region helper_functions

void X11Window::maximize_toggle(bool enable)
{
    // We can't maximize window without EWMH.
    if (!utils::ewmh_supported()) {
        return;
    }

    const std::vector<std::string> state = {net_wm_state_maximized_vert_atom_name,
                                            net_wm_state_maximized_horz_atom_name};

    auto action = enable ? utils::WindowStateAction::add : utils::WindowStateAction::remove;

    if (!utils::window_change_state(m_server.get(), m_window, action, state)) {
        // report error
        //        warning(log_tag) << "Failed to " << (enable ? "set" : "reset") << " maximized state." << std::endl;
    }
}

void X11Window::fullscreen_toggle(bool enable)
{
    // We can't create fullscreen window without EWMH.
    if (!utils::ewmh_supported()) {
        return;
    }

    auto bypass_state = enable ? utils::BypassCompositorState::disabled : utils::BypassCompositorState::no_preferences;
    utils::set_bypass_compositor_state(m_server.get(), m_window, bypass_state);

    const std::vector<std::string> state = {net_wm_state_fullscreen_atom_name};

    auto action = enable ? utils::WindowStateAction::add : utils::WindowStateAction::remove;

    if (!utils::window_change_state(m_server.get(), m_window, action, state)) {
        // report error
        // warning(log_tag) << "Failed to " << (enable ? "set" : "reset") << " fullscreen mode." << std::endl;
    }
}

void X11Window::set_wm_hints()
{
    XWMHints wm_hints      = {};
    wm_hints.flags         = StateHint | InputHint;
    wm_hints.initial_state = NormalState;
    wm_hints.input         = True;

    XSetWMHints(m_server->display(), m_window, &wm_hints);
}

void X11Window::set_class_hints()
{
    const auto application_name = Application::name();
    const auto class_name       = application_name + "winodw class";

    std::vector<char> res_name(application_name.begin(), application_name.end());
    std::vector<char> res_class(class_name.begin(), class_name.end());

    XClassHint class_hint = {};
    class_hint.res_name   = res_name.data();
    class_hint.res_class  = res_class.data();

    XSetClassHint(m_server->display(), m_window, &class_hint);
}

void X11Window::add_protocols(const std::vector<std::string>& protocol_names)
{
    std::vector<Atom> protocols;

    for (auto& name : protocol_names) {
        Atom protocol = m_server->get_atom(name);
        if (protocol != None) {
            protocols.push_back(protocol);
        }
    }

    if (!protocols.empty()) {
        XSetWMProtocols(m_server->display(), m_window, protocols.data(), static_cast<int>(protocols.size()));
    }
}

void X11Window::create_input_context()
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

void X11Window::process_events_while(const std::function<bool()>& condition)
{
    using std::chrono::milliseconds;

    milliseconds limit(1000);
    const milliseconds delay(50);

    do {
        process_events();
        limit -= delay;
        std::this_thread::sleep_for(delay);
    } while (condition() && limit.count() > 0);
}

void X11Window::update_size_limits(Size min_size, Size max_size)
{
    XSizeHints size_hints = {};
    std::int64_t supplied;

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

void X11Window::move_window(Position new_position)
{
    new_position.x -= m_frame_extents.left;
    new_position.y -= m_frame_extents.top;
    const auto old_position = position();
    XMoveWindow(m_server->display(), m_window, new_position.x, new_position.y);
    XFlush(m_server->display());

    process_events_while([this, &old_position]() { return position() == old_position; });
}

#pragma endregion

} // namespace framework::system::details
