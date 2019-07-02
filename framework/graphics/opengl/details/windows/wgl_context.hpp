/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 11.09.2018

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

#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_CONTEXT_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_CONTEXT_HPP

#include <graphics/context.hpp>
#include <windows.h>

namespace framework::system
{
class win32_context : public framework::opengl::context
{
public:
    win32_context(HWND window, opengl::context_settings settings);
    ~win32_context() override;

    win32_context(const win32_context&) = default;
    win32_context(win32_context&&)      = default;

    win32_context& operator=(const win32_context&) = default;
    win32_context& operator=(win32_context&&) = default;

    bool valid() const override;
    bool is_current() const override;

    void make_current() const override;
    void swap_buffers() const override;

private:
    HWND m_window = nullptr;
    HDC m_hdc     = nullptr;
    HGLRC m_hglrc = nullptr;
};

} // namespace framework::system

#endif
