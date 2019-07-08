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

#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_WINDOW_HPP

#include <memory>
#include <windows.h>

#include <system/details/context.hpp>
#include <system/details/window_implementation.hpp>

namespace framework::system::details
{
class win32_window final : public window_implementation
{
public:
    win32_window(window_size size, const std::string& title, const context_settings& settings);
    ~win32_window() override;

    win32_window(const win32_window&) = delete;
    win32_window& operator=(const win32_window&) = delete;

    /// @name actions
    /// @{
    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    void iconify() override;
    void maximize() override;
    void switch_to_fullscreen() override;
    void restore() override;
    void make_current() override;
    void swap_buffers() override;
    /// @}

    /// @name setters
    /// @{

    // The size() value will be updated after next event processing
    void set_size(window_size size) override;
    void set_position(window_position position) override;

    void set_max_size(window_size max_size) override;
    void set_min_size(window_size min_size) override;

    void set_resizable(bool value) override;

    void set_title(const std::string& title) override;
    /// @}

    /// @name getters
    /// @{
    window_position position() const override;
    window_size size() const override;

    window_size max_size() const override;
    window_size min_size() const override;

    std::string title() const override;

    /// @}

    /// @name state
    /// @{
    bool fullscreen() const override;
    bool iconified() const override;
    bool maximized() const override;
    bool resizable() const override;
    bool visible() const override;
    bool focused() const override;
    /// @}

private:
    struct window_info
    {
        LONG style;
        LONG ex_style;
        RECT rect;
    };

    struct modifiers_flags
    {
        bool left_shift;
        bool right_shift;
        bool left_control;
        bool right_control;
        bool left_alt;
        bool right_alt;
    };

    friend class win32_application;

    HWND m_window = nullptr;
    HDC m_hdc     = nullptr;
    HGLRC m_hglrc = nullptr;
    std::shared_ptr<ATOM> m_window_class;

    window_size m_min_size = {0, 0};
    window_size m_max_size = {0, 0};

    bool m_resizable   = true;
    bool m_mouse_hover = false;

    window_info m_saved_info = {0, 0, {0, 0, 0, 0}};

    std::unique_ptr<context> m_context = nullptr;

    modifiers_flags m_modifiers_flags = {false, false, false, false, false, false};

    LRESULT process_message(UINT message, WPARAM w_param, LPARAM l_param);

    void track_mouse();

    LRESULT process_key_event(WPARAM w_param, LPARAM l_param);
    void process_shift_key(LPARAM l_param);
    void process_control_key(LPARAM l_param);
    void process_alt_key(LPARAM l_param);
};

} // namespace framework::system::details

#endif
