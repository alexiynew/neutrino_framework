/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 11.09.2018

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

#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_APPLICATION_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_APPLICATION_HPP

#include <map>

#include <windows.h>

namespace framework::system::details
{
class Win32Window;

class Win32Application
{
public:
    static void add_window(HANDLE handle, Win32Window* window);
    static Win32Window* get_window(HANDLE handle);
    static void remove_window(HANDLE handle);

    static HMODULE handle();

    static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param);

private:
    using container = std::map<HANDLE, Win32Window*>;

    static container m_windows;
    static HMODULE m_handle;
};

} // namespace framework::system::details

#endif
