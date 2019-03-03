/// @file
/// @brief Event handler, hold window event callbacks.
/// @author Fedorov Alexey
/// @date 01.03.2019

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

#ifndef FRAMEWORK_WINDOW_DETAILS_EVENT_HANDLER_HPP
#define FRAMEWORK_WINDOW_DETAILS_EVENT_HANDLER_HPP

#include <string>

#include <window/keyboard.hpp>
#include <window/window_callback_types.hpp>
#include <window/window_position.hpp>
#include <window/window_size.hpp>

namespace framework::system
{
class window;
}

namespace framework::system::details
{
class event_handler final
{
public:
    event_handler(window*);

    ~event_handler() = default;

    event_handler(const event_handler&) = delete;
    event_handler& operator=(const event_handler&) = delete;

    event_handler(event_handler&&) = default;
    event_handler& operator=(event_handler&&) = default;

    void on_show() const;
    void on_hide() const;
    void on_close() const;

    void on_focus() const;
    void on_focus_lost() const;

    void on_size(window_size) const;
    void on_position(window_position) const;

    void on_key_press(key_code, modifiers_state) const;
    void on_key_release(key_code, modifiers_state) const;

    void on_character(std::string) const;

    void on_mouse_press(mouse_button, modifiers_state) const;
    void on_mouse_release(mouse_button, modifiers_state) const;

    void on_mouse_enter() const;
    void on_mouse_leave() const;

private:
    friend class framework::system::window;

    window_event_callback m_on_show_callback  = nullptr;
    window_event_callback m_on_hide_callback  = nullptr;
    window_event_callback m_on_close_callback = nullptr;

    window_event_callback m_on_focus_callback      = nullptr;
    window_event_callback m_on_focus_lost_callback = nullptr;

    window_size_event_callback m_on_size_callback         = nullptr;
    window_position_event_callback m_on_position_callback = nullptr;

    window_key_event_callback m_on_key_press_callback   = nullptr;
    window_key_event_callback m_on_key_release_callback = nullptr;

    window_character_event_callback m_on_character_callback = nullptr;

    window_mouse_button_event_callback m_on_mouse_press_callback   = nullptr;
    window_mouse_button_event_callback m_on_mouse_release_callback = nullptr;

    window_event_callback m_on_mouse_enter_callback = nullptr;
    window_event_callback m_on_mouse_leave_callback = nullptr;

    const window* const m_window = nullptr;
};

} // namespace framework::system::details

#endif
