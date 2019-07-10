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
#include <windowsx.h>

#include <system/details/windows/win32_application.hpp>
#include <system/details/windows/win32_keyboard.hpp>
#include <system/details/windows/win32_wgl_context.hpp>
#include <system/details/windows/win32_window.hpp>

namespace
{
const char* const log_tag  = "win32_window";
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
    using framework::system::details::win32_application;

    UnregisterClass(class_name, win32_application::handle());
}

std::shared_ptr<ATOM> register_window_class_details()
{
    using framework::system::details::win32_application;

    WNDCLASSEX window_class = {};

    window_class.cbSize        = sizeof(WNDCLASSEX);
    window_class.style         = CS_OWNDC;
    window_class.lpfnWndProc   = win32_application::window_procedure;
    window_class.cbClsExtra    = 0;
    window_class.cbWndExtra    = 0;
    window_class.hInstance     = win32_application::handle();
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

framework::system::mouse_button get_mouse_button(UINT message)
{
    using framework::system::mouse_button;

    switch (message) {
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP: return mouse_button::button_left;

        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP: return mouse_button::button_middle;

        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP: return mouse_button::button_right;
    }

    return mouse_button::button_unknown;
}

framework::system::details::window_size adjust_size(framework::system::details::window_size size, DWORD style)
{
    framework::int32 height = GetSystemMetrics(SM_CYCAPTION);
    height += ((style & WS_SIZEBOX) ? GetSystemMetrics(SM_CYFRAME) : GetSystemMetrics(SM_CYFIXEDFRAME)) * 2;
    height += GetSystemMetrics(SM_CYEDGE) * 2;

    framework::int32 width = 0;
    width += ((style & WS_SIZEBOX) ? GetSystemMetrics(SM_CXFRAME) : GetSystemMetrics(SM_CXFIXEDFRAME)) * 2;
    width += GetSystemMetrics(SM_CXEDGE) * 2;

    return {size.width + width, size.height + height};
}

} // namespace

namespace framework::system::details
{
win32_window::win32_window(window_size size, const std::string& title, const context_settings& settings)
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
                              win32_application::handle(),
                              nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window.");
    }

    m_context = std::make_unique<win32_wgl_context>(settings, m_window);

    win32_application::add_window(m_window, this);

    // The first call ignores its parameters
    ShowWindow(m_window, SW_HIDE);
}

win32_window::~win32_window()
{
    win32_application::remove_window(m_window);

    DestroyWindow(m_window);
}

#pragma region actions

void win32_window::show()
{
    if (iconified()) {
        ShowWindow(m_window, SW_RESTORE);
    } else {
        ShowWindow(m_window, SW_SHOW);
    }
    UpdateWindow(m_window);

    // TODO: Get mouse position and set m_mouse_hover correctly.
    // m_mouse_hover = cursor inside window?
}

void win32_window::hide()
{
    ShowWindow(m_window, SW_HIDE);
}

void win32_window::focus()
{
    BringWindowToTop(m_window);
    SetForegroundWindow(m_window);
}

void win32_window::process_events()
{
    MSG message = {};

    while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
        if (message.message == WM_QUIT) {
            if (m_event_handler) {
                m_event_handler->on_close();
            }
        } else {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }
}

void win32_window::iconify()
{
    ShowWindow(m_window, SW_MINIMIZE);
}

void win32_window::maximize()
{
    ShowWindow(m_window, SW_MAXIMIZE);
}

void win32_window::switch_to_fullscreen()
{
    if (fullscreen()) {
        return;
    }

    if (maximized()) {
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

void win32_window::restore()
{
    if (fullscreen()) {
        SetWindowLong(m_window, GWL_STYLE, m_saved_info.style);
        SetWindowLong(m_window, GWL_EXSTYLE, m_saved_info.ex_style);

        SetWindowPos(m_window,
                     HWND_TOP,
                     m_saved_info.rect.left,
                     m_saved_info.rect.top,
                     m_saved_info.rect.right - m_saved_info.rect.left,
                     m_saved_info.rect.bottom - m_saved_info.rect.top,
                     SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
    } else if (iconified()) {
        ShowWindow(m_window, SW_RESTORE);
    } else if (maximized()) {
        ShowWindow(m_window, SW_RESTORE);
    }
}

void win32_window::make_current()
{
    m_context->make_current();
}

void win32_window::swap_buffers()
{
    m_context->swap_buffers();
}

#pragma endregion

#pragma region setters

void win32_window::set_size(window_size size)
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

void win32_window::set_position(window_position position)
{
    SetWindowPos(m_window,
                 HWND_TOP,
                 position.x,
                 position.y,
                 0,
                 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
}

void win32_window::set_max_size(window_size max_size)
{
    m_max_size = max_size;
}

void win32_window::set_min_size(window_size min_size)
{
    m_min_size = min_size;
}

void win32_window::set_resizable(bool value)
{
    m_resizable = value;

    auto style = GetWindowLong(m_window, GWL_STYLE);

    if (!m_resizable) {
        style &= ~(WS_SIZEBOX | WS_MAXIMIZEBOX);
    } else {
        style |= (WS_SIZEBOX | WS_MAXIMIZEBOX);
    }

    SetWindowLong(m_window, GWL_STYLE, style);

    window_size sz = adjust_size(size(), style);
    SetWindowPos(m_window, HWND_TOP, 0, 0, sz.width, sz.height, SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void win32_window::set_title(const std::string& title)
{
    const auto whide_char_title = utf8_to_utf16(title);
    SetWindowText(m_window, &whide_char_title[0]);
}

#pragma endregion

#pragma region getters

window_position win32_window::position() const
{
    RECT rect;
    GetWindowRect(m_window, &rect);

    return window_position{rect.left, rect.top};
}

window_size win32_window::size() const
{
    RECT area;
    GetClientRect(m_window, &area);

    return window_size{area.right, area.bottom};
}

window_size win32_window::max_size() const
{
    return m_max_size;
}

window_size win32_window::min_size() const
{
    return m_min_size;
}

std::string win32_window::title() const
{
    const int32 title_length = GetWindowTextLength(m_window) + 1;

    if (title_length == 1) {
        return std::string();
    }

    std::unique_ptr<wchar_t[]> buffer(new wchar_t[title_length]);
    GetWindowText(m_window, buffer.get(), title_length);

    return utf16_to_utf8(buffer.get());
}

#pragma endregion

#pragma region state

bool win32_window::fullscreen() const
{
    RECT window_rect;
    RECT desktop_rect;
    GetWindowRect(m_window, &window_rect);
    GetWindowRect(GetDesktopWindow(), &desktop_rect);

    return (window_rect.left == desktop_rect.left && window_rect.top == desktop_rect.top &&
            window_rect.right == desktop_rect.right && window_rect.bottom == desktop_rect.bottom);
}

bool win32_window::iconified() const
{
    return IsIconic(m_window) != 0;
}

bool win32_window::maximized() const
{
    return IsZoomed(m_window) != 0;
}

bool win32_window::resizable() const
{
    return m_resizable;
}

bool win32_window::visible() const
{
    return IsWindowVisible(m_window);
}

bool win32_window::focused() const
{
    return GetActiveWindow() == m_window && GetFocus() == m_window;
}

#pragma endregion

#pragma region message processing

LRESULT win32_window::process_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    switch (message) {
        case WM_SETFOCUS: {
            if (m_event_handler) {
                m_event_handler->on_focus();
            }

            return 0;
        }

        case WM_KILLFOCUS: {
            if (m_event_handler) {
                m_event_handler->on_focus_lost();
            }

            return 0;
        }

        case WM_CLOSE: {
            if (m_event_handler) {
                m_event_handler->on_close();
            }

            return 0;
        }

        case WM_SHOWWINDOW: {
            if (l_param == 0 && m_event_handler) {
                if (w_param == TRUE) {
                    m_event_handler->on_show();
                } else {
                    m_event_handler->on_hide();
                }
            }

            return 0;
        }

        case WM_SIZE: {
            if (m_event_handler) {
                m_event_handler->on_size(size());
            }

            return 0;
        }

        case WM_MOVE: {
            if (m_event_handler) {
                m_event_handler->on_position(position());
            }

            return 0;
        }

        case WM_GETMINMAXINFO: {
            auto minmaxinfo = reinterpret_cast<MINMAXINFO*>(l_param);
            auto style      = GetWindowLong(m_window, GWL_STYLE);

            if (m_min_size.width != 0 && m_min_size.height != 0) {
                window_size size = adjust_size(m_min_size, style);

                minmaxinfo->ptMinTrackSize.x = size.width;
                minmaxinfo->ptMinTrackSize.y = size.height;
            }

            if (m_max_size.width != 0 && m_max_size.height != 0) {
                window_size size = adjust_size(m_max_size, style);

                minmaxinfo->ptMaxTrackSize.x = size.width;
                minmaxinfo->ptMaxTrackSize.y = size.height;
            }

            return 0;
        }

        case WM_MOUSELEAVE: {
            if (m_event_handler) {
                m_event_handler->on_mouse_leave();
            }
            m_mouse_hover = false;

            return 0;
        }

        case WM_MOUSEHOVER: {
            if (m_event_handler) {
                m_event_handler->on_mouse_enter();
            }
            m_mouse_hover = true;

            return 0;
        }

        case WM_MOUSEMOVE: {
            track_mouse();

            if (m_event_handler) {
                const cursor_position position{LOWORD(l_param), HIWORD(l_param)};
                m_event_handler->on_mouse_move(position);
            }

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
            if (m_event_handler) {
                const mouse_button button = get_mouse_button(message);
                const cursor_position position{GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)};
                const modifiers_state mod_state = get_modifiers_state();
                auto action = (message == WM_LBUTTONDOWN || message == WM_MBUTTONDOWN || message == WM_RBUTTONDOWN
                               ? &event_handler::on_mouse_press
                               : &event_handler::on_mouse_release);

                if (button != mouse_button::button_unknown) {
                    (m_event_handler->*action)(button, position, mod_state);
                }
            }

            return 0;
        }

        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP: {
            const mouse_button button = (GET_XBUTTON_WPARAM(w_param) == XBUTTON1 ? mouse_button::button_4
                                                                                 : mouse_button::button_5);
            const cursor_position position{GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)};
            const modifiers_state mod_state = get_modifiers_state();
            auto action                     = (message == WM_XBUTTONDOWN ? &event_handler::on_mouse_press
                                                     : &event_handler::on_mouse_release);

            (m_event_handler->*action)(button, position, mod_state);

            return TRUE;
        }

        case WM_UNICHAR: {
            if (w_param == UNICODE_NOCHAR) {
                // The WM_UNICHAR message can be used by an application to post input to other windows
                // Returning TRUE here announces support for this message
                return TRUE;
            }
            if (m_event_handler) {
                // TODO (alex): Do the correct unicode casting
                wchar_t wchar = static_cast<wchar_t>(w_param);
                std::wstring s;
                s += wchar;
                m_event_handler->on_character(utf32_to_utf8(s));
            }

            return 0;
        }

        case WM_CHAR:
        case WM_SYSCHAR: {
            if (m_event_handler) {
                // TODO (alex): Do the correct unicode casting
                wchar_t wchar = static_cast<wchar_t>(w_param);
                std::wstring s;
                s += wchar;
                m_event_handler->on_character(utf16_to_utf8(s));
            }

            return 0;
        }

        case WM_SYSCOMMAND: {
            switch (w_param & 0xfff0) {
                case SC_SCREENSAVE:
                case SC_MONITORPOWER: {
                    if (fullscreen()) {
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

LRESULT win32_window::process_key_event(WPARAM w_param, LPARAM l_param)
{
    if (m_event_handler == nullptr) {
        return 0;
    }

    switch (w_param) {
        case VK_SHIFT: process_shift_key(l_param); return 0;

        case VK_CONTROL: process_control_key(l_param); return 0;

        case VK_MENU: process_alt_key(l_param); return 0;
        default: break;
    }

    const key_code key              = details::map_system_key(static_cast<uint32>(w_param));
    const modifiers_state mod_state = details::get_modifiers_state();
    const bool key_is_down          = ((l_param >> 31) & 1) == 0;

    if (key == key_code::key_unknown) {
        return 0;
    }

    // Print screen does not emmit press event.
    if (key == key_code::key_print_screen) {
        m_event_handler->on_key_press(key, mod_state);
        m_event_handler->on_key_release(key, mod_state);
        return 0;
    }

    if (key_is_down) {
        m_event_handler->on_key_press(key, mod_state);
    } else {
        m_event_handler->on_key_release(key, mod_state);
    }

    return 0;
}

void win32_window::process_shift_key(LPARAM l_param)
{
    const bool key_is_down          = ((l_param >> 31) & 1) == 0;
    const modifiers_state mod_state = details::get_modifiers_state();

    const bool left_shift  = ((GetKeyState(VK_LSHIFT) & 0x8000));
    const bool right_shift = ((GetKeyState(VK_RSHIFT) & 0x8000));

    if (key_is_down) {
        if (left_shift != m_modifiers_flags.left_shift) {
            m_event_handler->on_key_press(key_code::key_left_shift, mod_state);
        } else if (right_shift != m_modifiers_flags.right_shift) {
            m_event_handler->on_key_press(key_code::key_right_shift, mod_state);
        }
    } else {
        if (m_modifiers_flags.left_shift) {
            m_event_handler->on_key_release(key_code::key_left_shift, mod_state);
        }
        if (m_modifiers_flags.right_shift) {
            m_event_handler->on_key_release(key_code::key_right_shift, mod_state);
        }
    }

    m_modifiers_flags.left_shift  = left_shift;
    m_modifiers_flags.right_shift = right_shift;
}

void win32_window::process_control_key(LPARAM l_param)
{
    const bool key_is_down          = ((l_param >> 31) & 1) == 0;
    const modifiers_state mod_state = details::get_modifiers_state();

    const bool left_control  = ((GetKeyState(VK_LCONTROL) & 0x8000));
    const bool right_control = ((GetKeyState(VK_RCONTROL) & 0x8000));

    key_code key = key_code::key_unknown;
    if (left_control != m_modifiers_flags.left_control) {
        key = key_code::key_left_control;
    } else if (right_control != m_modifiers_flags.right_control) {
        key = key_code::key_right_control;
    } else {
        return;
    }

    if (key_is_down) {
        m_event_handler->on_key_press(key, mod_state);
    } else {
        m_event_handler->on_key_release(key, mod_state);
    }

    m_modifiers_flags.left_control  = left_control;
    m_modifiers_flags.right_control = right_control;
}

void win32_window::process_alt_key(LPARAM l_param)
{
    const bool key_is_down          = ((l_param >> 31) & 1) == 0;
    const modifiers_state mod_state = details::get_modifiers_state();

    const bool left_alt  = ((GetKeyState(VK_LMENU) & 0x8000));
    const bool right_alt = ((GetKeyState(VK_RMENU) & 0x8000));

    key_code key = key_code::key_unknown;
    if (left_alt != m_modifiers_flags.left_alt) {
        key = key_code::key_left_alt;
    } else if (right_alt != m_modifiers_flags.right_alt) {
        key = key_code::key_right_alt;
    } else {
        return;
    }

    if (key_is_down) {
        m_event_handler->on_key_press(key, mod_state);
    } else {
        m_event_handler->on_key_release(key, mod_state);
    }

    m_modifiers_flags.left_alt  = left_alt;
    m_modifiers_flags.right_alt = right_alt;
}

#pragma endregion

#pragma region helper functions

void win32_window::track_mouse()
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
