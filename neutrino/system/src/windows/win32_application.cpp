/// @file ::system::
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 19.04.2017

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

namespace framework::system::details
{
Win32Application::container Win32Application::m_windows;
HMODULE Win32Application::m_handle = nullptr;

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
        throw std::runtime_error("Failed to get application instance handle.");
    }

    return m_handle;
}

LRESULT CALLBACK Win32Application::window_procedure(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param)
{
    if (auto window = get_window(window_handle); window != nullptr) {
        return window->process_message(message, w_param, l_param);
    }

    return DefWindowProc(window_handle, message, w_param, l_param);
}

} // namespace framework::system::details
