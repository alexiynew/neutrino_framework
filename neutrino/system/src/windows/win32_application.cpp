// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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
#include <system/src/windows/win32_window.hpp>

namespace
{
const std::wstring main_class_name = L"main_window_class";

void unregister_window_class(LPCWSTR class_atom)
{
    using framework::system::details::Win32Application;

    if (!UnregisterClass(class_atom, Win32Application::handle())) {
        throw std::runtime_error("Failed to unregister window class, error: " + std::to_string(GetLastError()));
    }
}

LPCWSTR register_window_class()
{
    using framework::system::details::Win32Application;

    WNDCLASSEX window_class = {};

    window_class.cbSize        = sizeof(WNDCLASSEX);
    window_class.style         = CS_OWNDC;
    window_class.lpfnWndProc   = Win32Application::main_window_procedure;
    window_class.cbClsExtra    = 0;
    window_class.cbWndExtra    = 0;
    window_class.hInstance     = Win32Application::handle();
    window_class.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    window_class.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    window_class.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    window_class.lpszMenuName  = nullptr;
    window_class.lpszClassName = main_class_name.c_str();
    window_class.hIconSm       = LoadIcon(nullptr, IDI_APPLICATION);

    const ATOM class_atom = RegisterClassEx(&window_class);
    if (!class_atom) {
        throw std::runtime_error("Failed to register window class, error: " + std::to_string(GetLastError()));
    }

    LPCWSTR class_pointer = reinterpret_cast<LPCWSTR>(static_cast<std::uint64_t>(MAKELONG(class_atom, 0)));
    return class_pointer;
}

} // namespace

namespace framework::system::details
{
Win32Application::container Win32Application::m_windows;
HMODULE Win32Application::m_handle       = nullptr;
LPCWSTR Win32Application::m_window_class = nullptr;

void Win32Application::add_window(HANDLE handle, Win32Window* window)
{
    m_windows.insert({handle, window});
}

Win32Window* Win32Application::get_window(HANDLE handle)
{
    if (m_windows.count(handle)) {
        return m_windows[handle];
    }

    return nullptr;
}

void Win32Application::remove_window(HANDLE handle)
{
    m_windows.erase(handle);
}

HMODULE Win32Application::handle()
{
    if (m_handle == nullptr) {
        m_handle = GetModuleHandle(nullptr);
    }

    if (m_handle == nullptr) {
        throw std::runtime_error("Failed to get application instance handle, error: " + std::to_string(GetLastError()));
    }

    return m_handle;
}

LPCWSTR Win32Application::get_window_class()
{
    if (!m_window_class) {
        m_window_class = register_window_class();
    }

    return m_window_class;
}

LRESULT CALLBACK Win32Application::main_window_procedure(HWND window_handle,
                                                         UINT message,
                                                         WPARAM w_param,
                                                         LPARAM l_param)
{
    if (auto window = get_window(window_handle); window != nullptr) {
        return window->process_message(message, w_param, l_param);
    }

    return DefWindowProc(window_handle, message, w_param, l_param);
}

} // namespace framework::system::details
