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

#include <system/context.hpp>
#include <system/context_settings.hpp>
#include <system/src/platform_window.hpp>

namespace framework::system::details
{
class Win32Window final : public PlatformWindow
{
public:
    Win32Window(const Window& window_interface, Size size, const std::string& title, const ContextSettings& settings);
    ~Win32Window() override;

    Win32Window(const Win32Window&) = delete;
    Win32Window& operator=(const Win32Window&) = delete;

    /// @name actions
    /// @{
    void show() override;
    void hide() override;
    void focus() override;
    void iconify() override;
    void maximize() override;
    void fullscreen() override;
    void restore() override;
    void resize(Size size) override;
    void move(Position position) override;
    void process_events() override;
    /// @}

    /// @name setters
    /// @{
    void set_max_size(Size max_size) override;
    void set_min_size(Size min_size) override;
    void set_resizable(bool value) override;
    void set_title(const std::string& title) override;
    /// @}

    /// @name getters
    /// @{
    Position position() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    std::string title() const override;
    Context& context() const override;
    /// @}

    /// @name state
    /// @{
    bool should_close() const override;
    bool is_fullscreen() const override;
    bool is_iconified() const override;
    bool is_maximized() const override;
    bool is_resizable() const override;
    bool is_visible() const override;
    bool has_input_focus() const override;
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

    friend class Win32Application;

    HWND m_window = nullptr;
    HDC m_hdc     = nullptr;
    HGLRC m_hglrc = nullptr;
    std::shared_ptr<ATOM> m_window_class;

    Size m_min_size = {0, 0};
    Size m_max_size = {0, 0};

    bool m_resizable    = true;
    bool m_mouse_hover  = false;
    bool m_should_close = false;

    window_info m_saved_info = {0, 0, {0, 0, 0, 0}};

    std::unique_ptr<Context> m_context = nullptr;

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
