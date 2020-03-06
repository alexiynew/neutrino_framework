/// @file
/// @brief Event handler, hold window event callbacks.
/// @author Fedorov Alexey
/// @date 01.03.2019

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

#include <system/src/event_handler.hpp>

namespace framework::system::details
{
event_handler::event_handler(window* w) : m_window(w)
{}

void event_handler::on_show()
{
    if (m_on_show_callback) {
        m_on_show_callback(*m_window);
    }
}

void event_handler::on_hide()
{
    if (m_on_hide_callback) {
        m_on_hide_callback(*m_window);
    }
}

void event_handler::on_close()
{
    if (m_on_close_callback) {
        m_on_close_callback(*m_window);
    }
}

void event_handler::on_focus()
{
    if (m_on_focus_callback) {
        m_on_focus_callback(*m_window);
    }
}

void event_handler::on_focus_lost()
{
    if (m_on_focus_lost_callback) {
        m_on_focus_lost_callback(*m_window);
    }
}

void event_handler::on_size(window_size size)
{
    if (m_on_size_callback) {
        m_on_size_callback(*m_window, size);
    }
}

void event_handler::on_position(window_position position)
{
    if (m_on_position_callback) {
        m_on_position_callback(*m_window, position);
    }
}

void event_handler::on_key_press(key_code key, modifiers_state state)
{
    if (m_on_key_press_callback) {
        m_on_key_press_callback(*m_window, key, state);
    }
}

void event_handler::on_key_release(key_code key, modifiers_state state)
{
    if (m_on_key_release_callback) {
        m_on_key_release_callback(*m_window, key, state);
    }
}

void event_handler::on_character(std::string ch)
{
    if (m_on_character_callback) {
        m_on_character_callback(*m_window, ch);
    }
}

void event_handler::on_mouse_move(cursor_position position)
{
    if (m_on_mouse_move_callback) {
        m_on_mouse_move_callback(*m_window, position);
    }
}

void event_handler::on_mouse_press(mouse_button button, cursor_position position, modifiers_state state)
{
    if (m_on_mouse_press_callback) {
        m_on_mouse_press_callback(*m_window, button, position, state);
    }
}

void event_handler::on_mouse_release(mouse_button button, cursor_position position, modifiers_state state)
{
    if (m_on_mouse_release_callback) {
        m_on_mouse_release_callback(*m_window, button, position, state);
    }
}

void event_handler::on_mouse_enter()
{
    if (m_on_mouse_enter_callback) {
        m_on_mouse_enter_callback(*m_window);
    }
}

void event_handler::on_mouse_leave()
{
    if (m_on_mouse_leave_callback) {
        m_on_mouse_leave_callback(*m_window);
    }
}

} // namespace framework::system::details
