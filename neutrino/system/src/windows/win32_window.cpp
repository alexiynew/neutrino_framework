/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 19.04.2017

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

#include <stdexcept>

#include <system/src/windows/win32_application.hpp>
#include <system/src/windows/win32_keyboard.hpp>
#include <system/src/windows/win32_wgl_context.hpp>
#include <system/src/windows/win32_window.hpp>

#include <windowsx.h>

namespace
{
const char* const log_tag  = "Win32Window";
const wchar_t class_name[] = L"my_window_class";

const DWORD window_style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_SIZEBOX | WS_MINIMIZEBOX | WS_CLIPCHILDREN |
                           WS_CLIPSIBLINGS;
const DWORD window_ex_style = WS_EX_OVERLAPPEDWINDOW | WS_EX_APPWINDOW;

std::wstring utf8_to_utf16(const std::string& string)
{
    if (string.empty()) {
        return std::wstring();
    }

    const auto size = MultiByteToWideChar(CP_UTF8, 0, &string[0], -1, nullptr, 0);

    if (size == 0) {
        return std::wstring();
    }

    std::unique_ptr<wchar_t[]> buffer(new wchar_t[size]);
    MultiByteToWideChar(CP_UTF8, 0, &string[0], -1, buffer.get(), size);

    return std::wstring(buffer.get());
}

std::string utf16_to_utf8(const std::wstring& string)
{
    if (string.empty()) {
        return std::string();
    }

    const auto size = WideCharToMultiByte(CP_UTF8, 0, &string[0], -1, nullptr, 0, nullptr, nullptr);

    if (size == 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[size]);
    WideCharToMultiByte(CP_UTF8, 0, &string[0], -1, buffer.get(), size, nullptr, nullptr);

    return std::string(buffer.get());
}

std::string utf32_to_utf8(const std::wstring& string)
{
    if (string.empty()) {
        return std::string();
    }

    const auto size = WideCharToMultiByte(CP_UTF8, 0, &string[0], -1, nullptr, 0, nullptr, nullptr);

    if (size == 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[size]);
    WideCharToMultiByte(CP_UTF8, 0, &string[0], -1, buffer.get(), size, nullptr, nullptr);

    return std::string(buffer.get());
}

void unregister_window_class(ATOM*)
{
    using framework::system::details::Win32Application;

    UnregisterClass(class_name, Win32Application::handle());
}

std::shared_ptr<ATOM> register_window_class_details()
{
    using framework::system::details::Win32Application;

    WNDCLASSEX window_class = {};

    window_class.cbSize        = sizeof(WNDCLASSEX);
    window_class.style         = CS_OWNDC;
    window_class.lpfnWndProc   = Win32Application::window_procedure;
    window_class.cbClsExtra    = 0;
    window_class.cbWndExtra    = 0;
    window_class.hInstance     = Win32Application::handle();
    window_class.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    window_class.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    window_class.lpszMenuName  = nullptr;
    window_class.lpszClassName = class_name;
    window_class.hIconSm       = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassEx(&window_class)) {
        throw std::runtime_error("Failed to register window class.");
    }

    return std::shared_ptr<ATOM>(nullptr, unregister_window_class);
}

std::shared_ptr<ATOM> register_window_class()
{
    static std::weak_ptr<ATOM> pointer;

    if (pointer.expired()) {
        std::shared_ptr<ATOM> temp = ::register_window_class_details();

        pointer = temp;
        return temp;
    }

    return pointer.lock();
}

framework::system::MouseButton get_mouse_button(UINT message)
{
    using framework::system::MouseButton;

    switch (message) {
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP: return MouseButton::button_left;

        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP: return MouseButton::button_middle;

        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP: return MouseButton::button_right;
    }

    return MouseButton::unknown;
}

framework::Size adjust_size(framework::Size size, DWORD style)
{
    RECT rect{0, 0, size.width, size.height};
    AdjustWindowRectEx(&rect, window_style, false, window_ex_style);

    if ((style & WS_SIZEBOX) == 0) {
        // TODO (alex): fix size without size box.
    }

    return {rect.right - rect.left, rect.bottom - rect.top};
}

} // namespace

namespace framework::system::details
{
Win32Window::Win32Window(const Window& window_interface,
                         Size size,
                         const std::string& title,
                         const ContextSettings& settings)
    : PlatformWindow(window_interface)
{
    m_window_class = ::register_window_class();

    size = adjust_size(size, window_style);

    m_window = CreateWindowEx(window_ex_style,
                              class_name,
                              utf8_to_utf16(title).c_str(),
                              window_style,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              size.width,
                              size.height,
                              nullptr,
                              nullptr,
                              Win32Application::handle(),
                              nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window.");
    }

    m_context = std::make_unique<Win32WglContext>(settings, m_window);

    Win32Application::add_window(m_window, this);

    // The first call ignores its parameters
    ShowWindow(m_window, SW_HIDE);
}

Win32Window::~Win32Window()
{
    Win32Application::remove_window(m_window);

    DestroyWindow(m_window);
}

#pragma region actions

void Win32Window::show()
{
    if (is_iconified()) {
        ShowWindow(m_window, SW_RESTORE);
    } else {
        ShowWindow(m_window, SW_SHOW);
    }
    UpdateWindow(m_window);

    // TODO: Get mouse position and set m_mouse_hover correctly.
    // m_mouse_hover = cursor inside window?
}

void Win32Window::hide()
{
    ShowWindow(m_window, SW_HIDE);
}

void Win32Window::focus()
{
    BringWindowToTop(m_window);
    SetForegroundWindow(m_window);
}

void Win32Window::iconify()
{
    ShowWindow(m_window, SW_MINIMIZE);
}

void Win32Window::maximize()
{
    ShowWindow(m_window, SW_MAXIMIZE);
}

void Win32Window::fullscreen()
{
    if (is_fullscreen()) {
        return;
    }

    if (is_maximized()) {
        SendMessage(m_window, WM_SYSCOMMAND, SC_RESTORE, 0);
    }

    m_saved_info.style    = GetWindowLong(m_window, GWL_STYLE);
    m_saved_info.ex_style = GetWindowLong(m_window, GWL_EXSTYLE);
    GetWindowRect(m_window, &m_saved_info.rect);

    SetWindowLong(m_window, GWL_STYLE, m_saved_info.style & ~(WS_CAPTION | WS_THICKFRAME));
    SetWindowLong(m_window,
                  GWL_EXSTYLE,
                  m_saved_info.ex_style &
                  ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

    MONITORINFO monitor_info;
    monitor_info.cbSize = sizeof(monitor_info);
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

void Win32Window::restore()
{
    if (is_fullscreen()) {
        SetWindowLong(m_window, GWL_STYLE, m_saved_info.style);
        SetWindowLong(m_window, GWL_EXSTYLE, m_saved_info.ex_style);

        SetWindowPos(m_window,
                     HWND_TOP,
                     m_saved_info.rect.left,
                     m_saved_info.rect.top,
                     m_saved_info.rect.right - m_saved_info.rect.left,
                     m_saved_info.rect.bottom - m_saved_info.rect.top,
                     SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
    } else if (is_iconified()) {
        ShowWindow(m_window, SW_RESTORE);
    } else if (is_maximized()) {
        ShowWindow(m_window, SW_RESTORE);
    }
}

void Win32Window::resize(Size size)
{
    auto style = GetWindowLong(m_window, GWL_STYLE);
    size       = adjust_size(size, style);
    SetWindowPos(m_window,
                 HWND_TOP,
                 0,
                 0,
                 size.width,
                 size.height,
                 SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}

void Win32Window::move(Position position)
{
    SetWindowPos(m_window,
                 HWND_TOP,
                 position.x,
                 position.y,
                 0,
                 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
}

void Win32Window::process_events()
{
    MSG message = {};

    while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
        if (message.message == WM_QUIT) {
            m_should_close = true;
            on_close();
        } else {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }
}

#pragma endregion

#pragma region setters

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

    Size sz = adjust_size(size(), style);
    SetWindowPos(m_window, HWND_TOP, 0, 0, sz.width, sz.height, SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void Win32Window::set_title(const std::string& title)
{
    const auto whide_char_title = utf8_to_utf16(title);
    SetWindowText(m_window, &whide_char_title[0]);
}

#pragma endregion

#pragma region getters

Position Win32Window::position() const
{
    RECT rect;
    GetWindowRect(m_window, &rect);

    return Position{rect.left, rect.top};
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

std::string Win32Window::title() const
{
    const int32 title_length = GetWindowTextLength(m_window) + 1;

    if (title_length == 1) {
        return std::string();
    }

    std::unique_ptr<wchar_t[]> buffer(new wchar_t[title_length]);
    GetWindowText(m_window, buffer.get(), title_length);

    return utf16_to_utf8(buffer.get());
}

Context& Win32Window::context() const
{
    if (m_context == nullptr) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *(m_context.get());
}

#pragma endregion

#pragma region state

bool Win32Window::should_close() const
{
    return m_should_close;
}

bool Win32Window::is_fullscreen() const
{
    RECT window_rect;
    RECT desktop_rect;
    GetWindowRect(m_window, &window_rect);
    GetWindowRect(GetDesktopWindow(), &desktop_rect);

    return (window_rect.left == desktop_rect.left && window_rect.top == desktop_rect.top &&
            window_rect.right == desktop_rect.right && window_rect.bottom == desktop_rect.bottom);
}

bool Win32Window::is_iconified() const
{
    return IsIconic(m_window) != 0;
}

bool Win32Window::is_maximized() const
{
    return IsZoomed(m_window) != 0;
}

bool Win32Window::is_resizable() const
{
    return m_resizable;
}

bool Win32Window::is_visible() const
{
    return IsWindowVisible(m_window);
}

bool Win32Window::has_input_focus() const
{
    return GetActiveWindow() == m_window && GetFocus() == m_window;
}

#pragma endregion

#pragma region message processing

LRESULT Win32Window::process_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    switch (message) {
        case WM_SETFOCUS: {
            on_focus();
            return 0;
        }

        case WM_KILLFOCUS: {
            on_lost_focus();
            return 0;
        }

        case WM_CLOSE: {
            on_close();
            return 0;
        }

        case WM_SHOWWINDOW: {
            if (l_param == 0) {
                if (w_param == TRUE) {
                    on_show();
                } else {
                    on_hide();
                }
            }

            return 0;
        }

        case WM_SIZE: {
            on_resize(size());
            return 0;
        }

        case WM_MOVE: {
            on_move(position());
            return 0;
        }

        case WM_GETMINMAXINFO: {
            auto minmaxinfo = reinterpret_cast<MINMAXINFO*>(l_param);
            auto style      = GetWindowLong(m_window, GWL_STYLE);

            if (m_min_size.width != 0 && m_min_size.height != 0) {
                Size size = adjust_size(m_min_size, style);

                minmaxinfo->ptMinTrackSize.x = size.width;
                minmaxinfo->ptMinTrackSize.y = size.height;
            }

            if (m_max_size.width != 0 && m_max_size.height != 0) {
                Size size = adjust_size(m_max_size, style);

                minmaxinfo->ptMaxTrackSize.x = size.width;
                minmaxinfo->ptMaxTrackSize.y = size.height;
            }

            return 0;
        }

        case WM_MOUSELEAVE: {
            on_mouse_leave();
            m_mouse_hover = false;

            return 0;
        }

        case WM_MOUSEHOVER: {
            on_mouse_enter();
            m_mouse_hover = true;

            return 0;
        }

        case WM_MOUSEMOVE: {
            track_mouse();

            const CursorPosition position{LOWORD(l_param), HIWORD(l_param)};
            on_mouse_move(position);

            return 0;
        }

        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP: {
            process_key_event(w_param, l_param);
            return DefWindowProc(m_window, message, w_param, l_param);
        }

        case WM_KEYDOWN:
        case WM_KEYUP: {
            return process_key_event(w_param, l_param);
        }

        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MBUTTONUP:
        case WM_RBUTTONUP: {
            const MouseButton button = get_mouse_button(message);
            const CursorPosition position{GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)};
            const Modifiers mod_state = get_modifiers_state();
            const bool down = (message == WM_LBUTTONDOWN || message == WM_MBUTTONDOWN || message == WM_RBUTTONDOWN);

            if (button != MouseButton::unknown) {
                if (down) {
                    on_button_down(button, position, mod_state);
                } else {
                    on_button_up(button, position, mod_state);
                }
            }

            return 0;
        }

        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP: {
            const MouseButton button = (GET_XBUTTON_WPARAM(w_param) == XBUTTON1 ? MouseButton::button_4 :
                                                                                  MouseButton::button_5);
            const CursorPosition position{GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)};
            const Modifiers mod_state = get_modifiers_state();
            const bool down           = message == WM_XBUTTONDOWN;

            if (down) {
                on_button_down(button, position, mod_state);
            } else {
                on_button_up(button, position, mod_state);
            }

            return TRUE;
        }

        case WM_UNICHAR: {
            if (w_param == UNICODE_NOCHAR) {
                // The WM_UNICHAR message can be used by an application to post input to other windows
                // Returning TRUE here announces support for this message
                return TRUE;
            }
            // TODO (alex): Do the correct unicode casting
            wchar_t wchar = static_cast<wchar_t>(w_param);
            std::wstring s;
            s += wchar;
            on_character(utf32_to_utf8(s));

            return 0;
        }

        case WM_CHAR:
        case WM_SYSCHAR: {
            // TODO (alex): Do the correct unicode casting
            wchar_t wchar = static_cast<wchar_t>(w_param);
            std::wstring s;
            s += wchar;
            on_character(utf16_to_utf8(s));

            return 0;
        }

        case WM_SYSCOMMAND: {
            switch (w_param & 0xfff0) {
                case SC_SCREENSAVE:
                case SC_MONITORPOWER: {
                    if (is_fullscreen()) {
                        return 0;
                    } else
                        break;
                }

                case SC_KEYMENU: return 0;
            }
            break;
        }
    }

    return DefWindowProc(m_window, message, w_param, l_param);
}

LRESULT Win32Window::process_key_event(WPARAM w_param, LPARAM l_param)
{
    switch (w_param) {
        case VK_SHIFT: process_shift_key(l_param); return 0;
        case VK_CONTROL: process_control_key(l_param); return 0;
        case VK_MENU: process_alt_key(l_param); return 0;
        default: break;
    }

    const KeyCode key         = details::map_system_key(static_cast<uint32>(w_param));
    const Modifiers mod_state = details::get_modifiers_state();
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;

    if (key == KeyCode::unknown) {
        return 0;
    }

    // Print screen does not emmit key down event.
    if (key == KeyCode::key_print_screen) {
        on_key_down(key, mod_state);
        on_key_up(key, mod_state);
        return 0;
    }

    if (key_is_down) {
        on_key_down(key, mod_state);
    } else {
        on_key_up(key, mod_state);
    }

    return 0;
}

void Win32Window::process_shift_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_shift  = ((GetKeyState(VK_LSHIFT) & 0x8000));
    const bool right_shift = ((GetKeyState(VK_RSHIFT) & 0x8000));

    if (key_is_down) {
        if (left_shift != m_modifiers_flags.left_shift) {
            on_key_down(KeyCode::key_left_shift, mod_state);
        } else if (right_shift != m_modifiers_flags.right_shift) {
            on_key_down(KeyCode::key_right_shift, mod_state);
        }
    } else {
        if (m_modifiers_flags.left_shift) {
            on_key_up(KeyCode::key_left_shift, mod_state);
        }
        if (m_modifiers_flags.right_shift) {
            on_key_up(KeyCode::key_right_shift, mod_state);
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
        on_key_down(key, mod_state);
    } else {
        on_key_up(key, mod_state);
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
        on_key_down(key, mod_state);
    } else {
        on_key_up(key, mod_state);
    }

    m_modifiers_flags.left_alt  = left_alt;
    m_modifiers_flags.right_alt = right_alt;
}

#pragma endregion

#pragma region helper functions

void Win32Window::track_mouse()
{
    TRACKMOUSEEVENT track_info;
    track_info.cbSize      = sizeof(track_info);
    track_info.dwFlags     = m_mouse_hover ? TME_LEAVE : TME_HOVER;
    track_info.hwndTrack   = m_window;
    track_info.dwHoverTime = 1;

    TrackMouseEvent(&track_info);
}

#pragma endregion

} // namespace framework::system::details
