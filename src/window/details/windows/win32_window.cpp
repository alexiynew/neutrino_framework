/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 19.04.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#include <log/log.hpp>
#include <opengl/details/windows/wgl_context.hpp>
#include <window/details/windows/win32_application.hpp>
#include <window/details/windows/win32_window.hpp>

namespace
{
const char* const log_tag  = "win32_window";
const wchar_t class_name[] = L"my_window_class";

std::wstring to_utf16(const std::string& string)
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

std::string to_utf8(const std::wstring& string)
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
    using framework::system::win32_application;

    UnregisterClass(class_name, win32_application::handle());
}

std::shared_ptr<ATOM> register_window_class_details()
{
    using framework::system::win32_application;

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

} // namespace

namespace framework::system
{
std::unique_ptr<window::implementation> window::implementation::create(window_size size,
                                                                       const std::string& title,
                                                                       opengl::context_settings settings)
{
    return std::make_unique<win32_window>(size, title, std::move(settings));
}

win32_window::win32_window(window_size size, const std::string& title, opengl::context_settings settings)
{
    m_window_class = ::register_window_class();

    RECT rect{0, 0, size.width, size.height};
    AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_CLIENTEDGE);

    m_window = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW | WS_EX_APPWINDOW,
                              class_name,
                              to_utf16(title).c_str(),
                              WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              rect.right - rect.left,
                              rect.bottom - rect.top,
                              nullptr,
                              nullptr,
                              win32_application::handle(),
                              nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window.");
    }

    m_context = std::make_unique<win32_context>(m_window, std::move(settings));

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
            // TODO: process close requet
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

#pragma endregion

#pragma region setters

void win32_window::set_size(window_size size)
{
    RECT rect{0, 0, size.width, size.height};
    AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_CLIENTEDGE);

    SetWindowPos(m_window,
                 HWND_TOP,
                 0,
                 0,
                 rect.right - rect.left,
                 rect.bottom - rect.top,
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

    if (!SetWindowLong(m_window, GWL_STYLE, style)) {
        log::warning(log_tag) << "Can't change window style. Reason: " << GetLastError() << std::endl;
    }

    SetWindowPos(m_window, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void win32_window::set_title(const std::string& title)
{
    const auto whide_char_title = to_utf16(title);
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

    return to_utf8(buffer.get());
}

framework::opengl::context* win32_window::context() const
{
    return m_context.get();
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
        case WM_GETMINMAXINFO: {
            auto minmaxinfo = reinterpret_cast<MINMAXINFO*>(l_param);

            if (m_min_size.width != 0 && m_min_size.height != 0) {
                RECT rect{0, 0, m_min_size.width, m_min_size.height};
                AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_CLIENTEDGE);

                minmaxinfo->ptMinTrackSize.x = rect.right - rect.left;
                minmaxinfo->ptMinTrackSize.y = rect.bottom - rect.top;
            }

            if (m_max_size.width != 0 && m_max_size.height != 0) {
                RECT rect{0, 0, m_max_size.width, m_max_size.height};
                AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_CLIENTEDGE);

                minmaxinfo->ptMaxTrackSize.x = rect.right - rect.left;
                minmaxinfo->ptMaxTrackSize.y = rect.bottom - rect.top;
            }

            return 0;
        }
    }

    return DefWindowProc(m_window, message, w_param, l_param);
}

#pragma endregion

} // namespace framework::system
