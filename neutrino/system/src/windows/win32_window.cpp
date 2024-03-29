#include <functional>
#include <stdexcept>

#include <common/utf.hpp>

#include <system/src/windows/win32_application.hpp>
#include <system/src/windows/win32_keyboard.hpp>
#include <system/src/windows/win32_wgl_context.hpp>
#include <system/src/windows/win32_window.hpp>

#include <hidusage.h>
#include <windowsx.h>

namespace
{

const DWORD window_style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_SIZEBOX | WS_MINIMIZEBOX | WS_CLIPCHILDREN |
                           WS_CLIPSIBLINGS;
const DWORD window_ex_style = WS_EX_OVERLAPPEDWINDOW | WS_EX_APPWINDOW;

framework::system::MouseButton get_mouse_button(UINT message, WPARAM w_param)
{
    using framework::system::MouseButton;

    switch (message) {
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP: return MouseButton::button_left;

        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP: return MouseButton::button_middle;

        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP: return MouseButton::button_right;

        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP: (GET_XBUTTON_WPARAM(w_param) == XBUTTON1 ? MouseButton::button_4 : MouseButton::button_5);
    }

    return MouseButton::unknown;
}

void set_cursor_cliping(HWND window, bool enable)
{
    if (enable) {
        RECT rect;
        GetClientRect(window, &rect);

        POINT left_top{rect.left, rect.top};
        ClientToScreen(window, &left_top);

        POINT right_bottom{rect.right, rect.bottom};
        ClientToScreen(window, &right_bottom);

        rect = {left_top.x, left_top.y, right_bottom.x, right_bottom.y};

        ClipCursor(&rect);
    } else {
        ClipCursor(nullptr);
    }
}

} // namespace

namespace framework::system::details
{

Win32Window::Win32Window(const std::string& title, Size size, const ContextSettings& settings)
    : PlatformWindow()
{
    using namespace std::placeholders;

    m_normal_size = size;

    const Size window_size = adjust_size(m_normal_size);

    m_window = CreateWindowEx(window_ex_style,
                              Win32Application::get_window_class(),
                              utf::to_wstring(title).c_str(),
                              window_style,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              window_size.width,
                              window_size.height,
                              nullptr,
                              nullptr,
                              Win32Application::handle(),
                              nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window, error: " + std::to_string(GetLastError()));
    }

    m_context = std::make_unique<Win32WglContext>(m_window, settings);

    Win32Application::add_window(m_window, this);

    // The first call ignores its parameters
    ShowWindow(m_window, SW_HIDE);
}

Win32Window::~Win32Window()
{
    DestroyWindow(m_window);
    Win32Application::remove_window(m_window);
}

#pragma region actions

void Win32Window::show(Window::State state)
{
    ShowWindow(m_window, SW_SHOW);
    UpdateWindow(m_window);
    switch_state(this->state(), state);
}

void Win32Window::hide()
{
    ShowWindow(m_window, SW_HIDE);
}

void Win32Window::request_input_focus()
{
    BringWindowToTop(m_window);
    SetForegroundWindow(m_window);
}

void Win32Window::capture_cursor()
{
    if (m_cursor_actually_captured) {
        return;
    }
    m_cursor_actually_captured = true;

    update_cursor_clipping();

    const RAWINPUTDEVICE rid = {HID_USAGE_PAGE_GENERIC, HID_USAGE_GENERIC_MOUSE, 0, m_window};
    RegisterRawInputDevices(&rid, 1, sizeof(rid));
}

void Win32Window::release_cursor()
{
    if (!m_cursor_actually_captured) {
        return;
    }
    m_cursor_actually_captured = false;

    update_cursor_clipping();

    const RAWINPUTDEVICE rid = {HID_USAGE_PAGE_GENERIC, HID_USAGE_GENERIC_MOUSE, RIDEV_REMOVE, nullptr};
    RegisterRawInputDevices(&rid, 1, sizeof(rid));
}

void Win32Window::show_cursor()
{
    if (m_cursor_actually_visible) {
        return;
    }
    m_cursor_actually_visible = true;

    SetCursor(LoadCursor(nullptr, IDC_ARROW));
}

void Win32Window::hide_cursor()
{
    if (!m_cursor_actually_visible) {
        return;
    }
    m_cursor_actually_visible = false;

    SetCursor(nullptr);
}

void Win32Window::switch_state(Window::State old_state, Window::State new_state)
{
    switch (old_state) {
        case Window::State::fullscreen: exit_fullscreen(); break;
        case Window::State::iconified: ShowWindow(m_window, SW_RESTORE); break;
        case Window::State::maximized: ShowWindow(m_window, SW_RESTORE); break;
        case Window::State::normal: break;
    }

    switch (new_state) {
        case Window::State::fullscreen: enter_fullscreen(); break;
        case Window::State::iconified: ShowWindow(m_window, SW_MINIMIZE); break;
        case Window::State::maximized: ShowWindow(m_window, SW_MAXIMIZE); break;
        case Window::State::normal: break;
    }
}

void Win32Window::process_events()
{
    MSG message = {};

    while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
        if (message.message == WM_QUIT) {
            on_close();
        } else {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }
}

#pragma endregion

#pragma region setters

void Win32Window::set_size(Size size)
{
    m_normal_size = size;

    const Size window_size = adjust_size(m_normal_size);
    SetWindowPos(m_window,
                 HWND_TOP,
                 0,
                 0,
                 window_size.width,
                 window_size.height,
                 SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
}

void Win32Window::set_max_size(Size max_size)
{
    m_max_size = max_size;
}

void Win32Window::set_min_size(Size min_size)
{
    m_min_size = min_size;
}

void Win32Window::set_resizable(bool value)
{
    m_resizable = value;

    auto style = GetWindowLong(m_window, GWL_STYLE);

    if (!m_resizable) {
        style &= ~(WS_SIZEBOX | WS_MAXIMIZEBOX);
    } else {
        style |= (WS_SIZEBOX | WS_MAXIMIZEBOX);
    }

    SetWindowLong(m_window, GWL_STYLE, style);

    const Size window_size = adjust_size(m_normal_size);
    SetWindowPos(m_window,
                 HWND_TOP,
                 0,
                 0,
                 window_size.width,
                 window_size.height,
                 SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void Win32Window::set_position(Position position)
{
    m_normal_position = position;

    const Position window_position = adjust_position(m_normal_position);
    SetWindowPos(m_window,
                 HWND_TOP,
                 window_position.x,
                 window_position.y,
                 0,
                 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
}

void Win32Window::set_title(const std::string& title)
{
    const auto whide_char_title = utf::to_wstring(title);
    SetWindowText(m_window, &whide_char_title[0]);
}

void Win32Window::set_cursor_position(CursorPosition position)
{
    POINT p = {position.x, position.y};
    ClientToScreen(m_window, &p);
    SetCursorPos(p.x, p.y);

    update_cursor_hover(position);
}

#pragma endregion

#pragma region getters

bool Win32Window::is_visible() const
{
    return IsWindowVisible(m_window);
}

bool Win32Window::has_input_focus() const
{
    return is_visible() && GetActiveWindow() == m_window && GetFocus() == m_window;
}

Position Win32Window::position() const
{
    POINT pos = {0, 0};
    ClientToScreen(m_window, &pos);

    return Position{pos.x, pos.y};
}

Window::State Win32Window::state() const
{
    using State = framework::system::Window::State;

    if (IsIconic(m_window) != 0) {
        return State::iconified;
    } else if (IsZoomed(m_window) != 0) {
        return State::maximized;
    } else {
        RECT window_rect;
        RECT desktop_rect;
        GetWindowRect(m_window, &window_rect);
        GetWindowRect(GetDesktopWindow(), &desktop_rect);

        const bool is_fullscreen_size = (window_rect.left == desktop_rect.left && window_rect.top == desktop_rect.top &&
                                         window_rect.right == desktop_rect.right &&
                                         window_rect.bottom == desktop_rect.bottom);

        /// TODO: Check window decorations
        // const bool has_window_decorations = true;

        if (is_fullscreen_size) {
            return State::fullscreen;
        }
    }

    return State::normal;
}

Size Win32Window::size() const
{
    RECT area;
    GetClientRect(m_window, &area);

    return Size{area.right, area.bottom};
}

Size Win32Window::max_size() const
{
    return m_max_size;
}

Size Win32Window::min_size() const
{
    return m_min_size;
}

bool Win32Window::is_resizable() const
{
    return m_resizable;
}

std::string Win32Window::title() const
{
    const int title_length = GetWindowTextLength(m_window) + 1;

    if (title_length == 1) {
        return std::string();
    }

    std::unique_ptr<wchar_t[]> buffer(new wchar_t[static_cast<std::size_t>(title_length)]);
    GetWindowText(m_window, buffer.get(), title_length);

    return utf::to_utf8(buffer.get());
}

CursorPosition Win32Window::cursor_position() const
{
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(m_window, &p);

    return {p.x, p.y};
}

const Context& Win32Window::context() const
{
    if (m_context == nullptr) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *m_context;
}

Context& Win32Window::context()
{
    if (m_context == nullptr) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *m_context;
}

#pragma endregion

#pragma region message processing

LRESULT Win32Window::process_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    switch (message) {
        case WM_SETFOCUS: return on_set_focus_message(message, w_param, l_param);
        case WM_KILLFOCUS: return on_kill_focus_message(message, w_param, l_param);
        case WM_CLOSE: return on_close_message(message, w_param, l_param);
        case WM_MOVE: return on_move_message(message, w_param, l_param);
        case WM_SIZE: return on_size_message(message, w_param, l_param);
        case WM_GETMINMAXINFO: return on_get_min_max_info_message(message, w_param, l_param);

        case WM_MOUSELEAVE: return on_mouse_leave_message(message, w_param, l_param);
        case WM_MOUSEHOVER: return on_mouse_hover_message(message, w_param, l_param);
        case WM_MOUSEMOVE: return on_mouse_move_message(message, w_param, l_param);

        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MBUTTONUP:
        case WM_RBUTTONUP:
        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP: return on_mouse_button_message(message, w_param, l_param);

        case WM_MOUSEHWHEEL:
        case WM_MOUSEWHEEL: return on_mouse_wheel_message(message, w_param, l_param);

        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
            on_key_message(message, w_param, l_param);
            break; // Just break, to pass event to DefWindowProc

        case WM_UNICHAR: return on_unichar_message(message, w_param, l_param);

        case WM_CHAR:
        case WM_SYSCHAR: return on_char_message(message, w_param, l_param);

        case WM_INPUT: on_input_message(message, w_param, l_param); break; // Just break, to pass event to DefWindowProc

        case WM_SYSCOMMAND: {
            switch (w_param & 0xfff0) {
                case SC_SCREENSAVE:
                case SC_MONITORPOWER: {
                    // We are running in full screen mode, so disallow screen saver and screen blanking
                    if (state_data().state == Window::State::fullscreen) {
                        return 0;
                    } else
                        break;
                }

                // Don't forward the menu system command, so that pressing ALT or F10 doesn't steal the focus
                case SC_KEYMENU: return 0;
            }
            break;
        }
    }

    return DefWindowProc(m_window, message, w_param, l_param);
}

LRESULT Win32Window::on_set_focus_message(UINT, WPARAM, LPARAM)
{
    on_focus();
    return 0;
}

LRESULT Win32Window::on_kill_focus_message(UINT, WPARAM, LPARAM)
{
    on_lost_focus();
    return 0;
}

LRESULT Win32Window::on_close_message(UINT, WPARAM, LPARAM)
{
    on_close();
    return 0;
}

LRESULT Win32Window::on_move_message(UINT, WPARAM, LPARAM)
{
    if (is_visible()) {
        update_cursor_clipping();
        on_move(position());
    }

    return 0;
}

LRESULT Win32Window::on_size_message(UINT, WPARAM, LPARAM)
{
    if (is_visible()) {
        update_cursor_clipping();
        on_resize(size());
    }

    return 0;
}

LRESULT Win32Window::on_get_min_max_info_message(UINT, WPARAM, LPARAM l_param)
{
    auto minmaxinfo = reinterpret_cast<MINMAXINFO*>(l_param);

    if (m_min_size.width != 0 && m_min_size.height != 0) {
        const Size window_size       = adjust_size(m_min_size);
        minmaxinfo->ptMinTrackSize.x = window_size.width;
        minmaxinfo->ptMinTrackSize.y = window_size.height;
    }

    if (m_max_size.width != 0 && m_max_size.height != 0) {
        const Size window_size       = adjust_size(m_max_size);
        minmaxinfo->ptMaxTrackSize.x = window_size.width;
        minmaxinfo->ptMaxTrackSize.y = window_size.height;
    }

    return 0;
}

LRESULT Win32Window::on_mouse_leave_message(UINT, WPARAM, LPARAM)
{
    on_mouse_leave();
    return 0;
}

LRESULT Win32Window::on_mouse_hover_message(UINT, WPARAM, LPARAM)
{
    on_mouse_enter();
    return 0;
}

LRESULT Win32Window::on_mouse_move_message(UINT, WPARAM, LPARAM l_param)
{
    if (m_cursor_actually_captured) {
        return 0;
    }

    track_mouse();

    m_last_cursor_position.x = GET_X_LPARAM(l_param);
    m_last_cursor_position.y = GET_Y_LPARAM(l_param);

    update_cursor_hover(m_last_cursor_position);

    on_mouse_move(m_last_cursor_position);

    return 0;
}

LRESULT Win32Window::on_mouse_button_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    const MouseButton button = get_mouse_button(message, w_param);
    const CursorPosition position{GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)};
    const Modifiers mod_state = get_modifiers_state();

    const bool down = (message == WM_LBUTTONDOWN || message == WM_MBUTTONDOWN || message == WM_RBUTTONDOWN ||
                       message == WM_XBUTTONDOWN);

    if (button != MouseButton::unknown) {
        if (down) {
            callbacks().on_mouse_button_down(button, position, mod_state);
        } else {
            callbacks().on_mouse_button_up(button, position, mod_state);
        }
    }

    if (message == WM_XBUTTONDOWN || message == WM_XBUTTONUP) {
        return TRUE;
    }

    return 0;
}

LRESULT Win32Window::on_mouse_wheel_message(UINT message, WPARAM w_param, LPARAM)
{
    const short delta = GET_WHEEL_DELTA_WPARAM(w_param);

    switch (message) {
        case WM_MOUSEWHEEL:
            // A positive value indicates that the wheel was rotated forward, away from the user; a negative value
            // indicates that the wheel was rotated backward, toward the user.
            callbacks().on_mouse_scroll(ScrollOffset{0, delta});
            break;
        case WM_MOUSEHWHEEL:
            // A positive value indicates that the wheel was rotated to the right; a negative value indicates that
            // the wheel was rotated to the left.
            callbacks().on_mouse_scroll(ScrollOffset{delta, 0});
            break;
    }

    return 0;
}

LRESULT Win32Window::on_key_message(UINT, WPARAM w_param, LPARAM l_param)
{
    switch (w_param) {
        case VK_SHIFT: process_shift_key(l_param); return 0;
        case VK_CONTROL: process_control_key(l_param); return 0;
        case VK_MENU: process_alt_key(l_param); return 0;
        default: break;
    }

    const KeyCode key         = details::map_system_key(static_cast<std::uint32_t>(w_param));
    const Modifiers mod_state = details::get_modifiers_state();
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;

    if (key == KeyCode::unknown) {
        return 0;
    }

    // Print screen does not emmit key down event.
    if (key == KeyCode::key_print_screen) {
        callbacks().on_key_down(key, mod_state);
        callbacks().on_key_up(key, mod_state);
        return 0;
    }

    if (key_is_down) {
        callbacks().on_key_down(key, mod_state);
    } else {
        callbacks().on_key_up(key, mod_state);
    }

    return 0;
}

LRESULT Win32Window::on_unichar_message(UINT, WPARAM w_param, LPARAM)
{
    if (w_param == UNICODE_NOCHAR) {
        // The WM_UNICHAR message can be used by an application to post input to other windows
        // Returning TRUE here announces support for this message
        return TRUE;
    }
    wchar_t wchar = static_cast<wchar_t>(w_param);
    std::wstring s;
    s += wchar;
    callbacks().on_character(utf::to_utf8(s));

    return 0;
}

LRESULT Win32Window::on_char_message(UINT, WPARAM w_param, LPARAM)
{
    wchar_t wchar = static_cast<wchar_t>(w_param);
    std::wstring s;
    s += wchar;
    callbacks().on_character(utf::to_utf8(s));

    return 0;
}

LRESULT Win32Window::on_input_message(UINT, WPARAM, LPARAM l_param)
{
    if (!m_cursor_actually_captured) {
        return 0;
    }

    HRAWINPUT handle = reinterpret_cast<HRAWINPUT>(l_param);

    UINT size = 0;
    GetRawInputData(handle, RID_INPUT, nullptr, &size, sizeof(RAWINPUTHEADER));

    RAWINPUT raw_input = RAWINPUT();
    if (GetRawInputData(handle, RID_INPUT, &raw_input, &size, sizeof(RAWINPUTHEADER)) == static_cast<UINT>(-1)) {
        return 0;
    }

    int dx = 0;
    int dy = 0;
    if ((raw_input.data.mouse.usFlags & MOUSE_MOVE_ABSOLUTE) == MOUSE_MOVE_ABSOLUTE) {
        const bool is_virtual_desktop = (raw_input.data.mouse.usFlags & MOUSE_VIRTUAL_DESKTOP) == MOUSE_VIRTUAL_DESKTOP;

        const int width  = GetSystemMetrics(is_virtual_desktop ? SM_CXVIRTUALSCREEN : SM_CXSCREEN);
        const int height = GetSystemMetrics(is_virtual_desktop ? SM_CYVIRTUALSCREEN : SM_CYSCREEN);

        const int absolute_x = int((raw_input.data.mouse.lLastX / 65535.0f) * width);
        const int absolute_y = int((raw_input.data.mouse.lLastY / 65535.0f) * height);

        dx = absolute_x - m_last_cursor_position.x;
        dy = absolute_y - m_last_cursor_position.y;

        m_last_cursor_position.x = absolute_x;
        m_last_cursor_position.y = absolute_y;
    } else {
        dx = raw_input.data.mouse.lLastX;
        dy = raw_input.data.mouse.lLastY;
    }

    on_mouse_move({dx, dy});

    return 0;
}

#pragma endregion

#pragma region keyboard processing

void Win32Window::process_shift_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_shift  = ((GetKeyState(VK_LSHIFT) & 0x8000));
    const bool right_shift = ((GetKeyState(VK_RSHIFT) & 0x8000));

    if (key_is_down) {
        if (left_shift != m_modifiers_flags.left_shift) {
            callbacks().on_key_down(KeyCode::key_left_shift, mod_state);
        } else if (right_shift != m_modifiers_flags.right_shift) {
            callbacks().on_key_down(KeyCode::key_right_shift, mod_state);
        }
    } else {
        if (m_modifiers_flags.left_shift) {
            callbacks().on_key_up(KeyCode::key_left_shift, mod_state);
        }
        if (m_modifiers_flags.right_shift) {
            callbacks().on_key_up(KeyCode::key_right_shift, mod_state);
        }
    }

    m_modifiers_flags.left_shift  = left_shift;
    m_modifiers_flags.right_shift = right_shift;
}

void Win32Window::process_control_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_control  = ((GetKeyState(VK_LCONTROL) & 0x8000));
    const bool right_control = ((GetKeyState(VK_RCONTROL) & 0x8000));

    KeyCode key = KeyCode::unknown;
    if (left_control != m_modifiers_flags.left_control) {
        key = KeyCode::key_left_control;
    } else if (right_control != m_modifiers_flags.right_control) {
        key = KeyCode::key_right_control;
    } else {
        return;
    }

    if (key_is_down) {
        callbacks().on_key_down(key, mod_state);
    } else {
        callbacks().on_key_up(key, mod_state);
    }

    m_modifiers_flags.left_control  = left_control;
    m_modifiers_flags.right_control = right_control;
}

void Win32Window::process_alt_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_alt  = ((GetKeyState(VK_LMENU) & 0x8000));
    const bool right_alt = ((GetKeyState(VK_RMENU) & 0x8000));

    KeyCode key = KeyCode::unknown;
    if (left_alt != m_modifiers_flags.left_alt) {
        key = KeyCode::key_left_alt;
    } else if (right_alt != m_modifiers_flags.right_alt) {
        key = KeyCode::key_right_alt;
    } else {
        return;
    }

    if (key_is_down) {
        callbacks().on_key_down(key, mod_state);
    } else {
        callbacks().on_key_up(key, mod_state);
    }

    m_modifiers_flags.left_alt  = left_alt;
    m_modifiers_flags.right_alt = right_alt;
}

#pragma endregion

#pragma region mouse handling

void Win32Window::track_mouse()
{
    TRACKMOUSEEVENT track_info;
    track_info.cbSize      = sizeof(track_info);
    track_info.dwFlags     = state_data().cursor_hover ? TME_LEAVE : TME_HOVER;
    track_info.hwndTrack   = m_window;
    track_info.dwHoverTime = 1;

    TrackMouseEvent(&track_info);
}

void Win32Window::update_cursor_clipping()
{
    if (m_cursor_actually_captured) {
        set_cursor_cliping(m_window, true);
    } else {
        set_cursor_cliping(m_window, false);
    }
}

void Win32Window::update_cursor_hover(CursorPosition pos)
{
    const Size s     = size();
    const bool hover = pos.x >= 0 && pos.x <= s.width && pos.y >= 0 && pos.y <= s.height;

    if (hover && !state_data().cursor_hover) {
        on_mouse_enter();
    } else if (!hover && state_data().cursor_hover) {
        on_mouse_leave();
    }
}

#pragma endregion

void Win32Window::enter_fullscreen()
{
    if (state() == Window::State::fullscreen) {
        return;
    }

    const LONG style    = GetWindowLong(m_window, GWL_STYLE);
    const LONG ex_style = GetWindowLong(m_window, GWL_EXSTYLE);

    m_normal_size     = size();
    m_normal_position = position();

    SetWindowLong(m_window, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
    SetWindowLong(m_window,
                  GWL_EXSTYLE,
                  ex_style & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

    MONITORINFO monitor_info = {};
    monitor_info.cbSize      = sizeof(monitor_info);
    GetMonitorInfo(MonitorFromWindow(m_window, MONITOR_DEFAULTTONEAREST), &monitor_info);

    SetWindowPos(m_window,
                 HWND_TOP,
                 monitor_info.rcMonitor.left,
                 monitor_info.rcMonitor.top,
                 monitor_info.rcMonitor.right,
                 monitor_info.rcMonitor.bottom,
                 SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);

    SetForegroundWindow(m_window);
}

void Win32Window::exit_fullscreen()
{
    if (state() != Window::State::fullscreen) {
        return;
    }

    const LONG style    = GetWindowLong(m_window, GWL_STYLE);
    const LONG ex_style = GetWindowLong(m_window, GWL_EXSTYLE);

    SetWindowLong(m_window, GWL_STYLE, style | WS_CAPTION | WS_THICKFRAME);
    SetWindowLong(m_window,
                  GWL_EXSTYLE,
                  ex_style | WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);

    const Size window_size         = adjust_size(m_normal_size);
    const Position window_position = adjust_position(m_normal_position);
    SetWindowPos(m_window,
                 HWND_TOP,
                 window_position.x,
                 window_position.y,
                 window_size.width,
                 window_size.height,
                 SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}

Size Win32Window::adjust_size(Size size) const
{
    const auto style    = m_window ? GetWindowLong(m_window, GWL_STYLE) : window_style;
    const auto ex_style = m_window ? GetWindowLong(m_window, GWL_EXSTYLE) : window_ex_style;

    RECT rect = {0, 0, size.width, size.height};
    AdjustWindowRectEx(&rect, style, false, ex_style);

    return {rect.right - rect.left, rect.bottom - rect.top};
}

Position Win32Window::adjust_position(Position position) const
{
    const auto style    = m_window ? GetWindowLong(m_window, GWL_STYLE) : window_style;
    const auto ex_style = m_window ? GetWindowLong(m_window, GWL_EXSTYLE) : window_ex_style;

    RECT rect = {position.x, position.y, 0, 0};
    AdjustWindowRectEx(&rect, style, false, ex_style);

    return {rect.left, rect.top};
}

} // namespace framework::system::details
