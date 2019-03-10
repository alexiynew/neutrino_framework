/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

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

#include <memory>

#include <window/details/event_handler.hpp>
#include <window/details/implementation.hpp>
#include <window/window.hpp>

namespace framework::system
{
void window::set_application_name(const std::string& name)
{
    details::implementation::set_application_name(name);
}

window::window(window_size size, const std::string& title, opengl::context_settings settings)
    : m_implementation(details::create_implementation(size, title, std::move(settings))),
      m_event_handler(std::make_unique<details::event_handler>(this))
{
    m_implementation->set_event_handler(m_event_handler.get());
}

window::~window() = default;

window::window(window&& other) noexcept : m_implementation(std::move(other.m_implementation))
{}

window& window::operator=(window&& other) noexcept
{
    m_implementation = std::move(other.m_implementation);
    return *this;
}

#pragma region actions

void window::show()
{
    m_implementation->show();
}

void window::hide()
{
    m_implementation->hide();
}

void window::focus()
{
    m_implementation->focus();
}

void window::process_events()
{
    m_implementation->process_events();
}

void window::iconify()
{
    m_implementation->iconify();
}

void window::maximize()
{
    m_implementation->maximize();
}

void window::switch_to_fullscreen()
{
    m_implementation->switch_to_fullscreen();
}

void window::restore()
{
    m_implementation->restore();
}

#pragma endregion

#pragma region setters

void window::set_size(window_size size)
{
    m_implementation->set_size(size);
}

void window::set_position(window_position position)
{
    m_implementation->set_position(position);
}

void window::set_max_size(window_size max_size)
{
    m_implementation->set_max_size(max_size);
}

void window::set_min_size(window_size min_size)
{
    m_implementation->set_min_size(min_size);
}

void window::set_resizable(bool value)
{
    m_implementation->set_resizable(value);
}

void window::set_title(const std::string& title)
{
    m_implementation->set_title(title);
}

#pragma endregion

#pragma region getters

window_position window::position() const
{
    return m_implementation->position();
}

window_size window::size() const
{
    return m_implementation->size();
}

window_size window::max_size() const
{
    return m_implementation->max_size();
}

window_size window::min_size() const
{
    return m_implementation->min_size();
}

std::string window::title() const
{
    return m_implementation->title();
}

framework::opengl::context* window::context() const
{
    return m_implementation->context();
}

#pragma endregion

#pragma region state

bool window::fullscreen() const
{
    return m_implementation->fullscreen();
}

bool window::iconified() const
{
    return m_implementation->iconified();
}

bool window::maximized() const
{
    return m_implementation->maximized();
}

bool window::resizable() const
{
    return m_implementation->resizable();
}

bool window::visible() const
{
    return m_implementation->visible();
}

bool window::focused() const
{
    return m_implementation->focused();
}

#pragma endregion

#pragma region events

void window::set_on_show_callback(window_event_callback callback)
{
    m_event_handler->m_on_show_callback = std::move(callback);
}

void window::set_on_hide_callback(window_event_callback callback)
{
    m_event_handler->m_on_hide_callback = std::move(callback);
}

void window::set_on_close_callback(window_event_callback callback)
{
    m_event_handler->m_on_close_callback = std::move(callback);
}

void window::set_on_focus_callback(window_event_callback callback)
{
    m_event_handler->m_on_focus_callback = std::move(callback);
}

void window::set_on_focus_lost_callback(window_event_callback callback)
{
    m_event_handler->m_on_focus_lost_callback = std::move(callback);
}

void window::set_on_size_callback(window_size_event_callback callback)
{
    m_event_handler->m_on_size_callback = std::move(callback);
}

void window::set_on_position_callback(window_position_event_callback callback)
{
    m_event_handler->m_on_position_callback = std::move(callback);
}

void window::set_on_key_press_callback(window_key_event_callback callback)
{
    m_event_handler->m_on_key_press_callback = std::move(callback);
}

void window::set_on_key_release_callback(window_key_event_callback callback)
{
    m_event_handler->m_on_key_release_callback = std::move(callback);
}

void window::set_on_character_callback(window_character_event_callback callback)
{
    m_event_handler->m_on_character_callback = std::move(callback);
}

void window::set_on_mouse_move_callback(window_mouse_move_callback callback)
{
    m_event_handler->m_on_mouse_move_callback = std::move(callback);
}

void window::set_on_mouse_button_press_callback(window_mouse_button_event_callback callback)
{
    m_event_handler->m_on_mouse_press_callback = std::move(callback);
}

void window::set_on_mouse_button_release_callback(window_mouse_button_event_callback callback)
{
    m_event_handler->m_on_mouse_release_callback = std::move(callback);
}

void window::set_on_mouse_enter_callback(window_event_callback callback)
{
    m_event_handler->m_on_mouse_enter_callback = std::move(callback);
}

void window::set_on_mouse_leave_callback(window_event_callback callback)
{
    m_event_handler->m_on_mouse_leave_callback = std::move(callback);
}

#pragma endregion

} // namespace framework::system
