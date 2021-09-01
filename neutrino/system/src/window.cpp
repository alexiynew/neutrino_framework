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

#include <memory>

#include <system/window.hpp>

#include <system/src/platform_window.hpp>

namespace framework::system
{
void Window::set_application_name(const std::string& name)
{
    details::PlatformWindow::set_application_name(name);
}

Window::Window(const std::string& title, Size size, ContextSettings settings)
    : m_platform_window(details::create_platform_window(title, size, std::move(settings)))
{
    m_platform_window->set_window_instance(this);
}

Window::~Window() = default;

Window::Window(Window&& other) noexcept
    : m_platform_window(nullptr)
{
    swap(*this, other);
}

Window& Window::operator=(Window&& other) noexcept
{
    swap(*this, other);
    return *this;
}

#pragma region actions

void Window::show()
{
    m_platform_window->show();
}

void Window::hide()
{
    m_platform_window->hide();
}

void Window::focus()
{
    m_platform_window->focus();
}

void Window::iconify()
{
    m_platform_window->iconify();
}

void Window::maximize()
{
    m_platform_window->maximize();
}

void Window::fullscreen()
{
    m_platform_window->fullscreen();
}

void Window::restore()
{
    m_platform_window->restore();
}

void Window::resize(Size size)
{
    m_platform_window->resize(size);
}

void Window::move(Position position)
{
    m_platform_window->move(position);
}

void Window::grab_cursor()
{
    m_platform_window->grab_cursor();
}

void Window::release_cursor()
{
    m_platform_window->release_cursor();
}

void Window::process_events()
{
    m_platform_window->process_events();
}

#pragma endregion

#pragma region setters

void Window::set_max_size(Size max_size)
{
    m_platform_window->set_max_size(max_size);
}

void Window::set_min_size(Size min_size)
{
    m_platform_window->set_min_size(min_size);
}

void Window::set_resizable(bool value)
{
    m_platform_window->set_resizable(value);
}

void Window::set_title(const std::string& title)
{
    m_platform_window->set_title(title);
}

void Window::set_cursor_visibility(bool visible)
{
    m_platform_window->set_cursor_visibility(visible);
}

#pragma endregion

#pragma region getters

Position Window::position() const
{
    return m_platform_window->position();
}

Size Window::size() const
{
    return m_platform_window->size();
}

Size Window::max_size() const
{
    return m_platform_window->max_size();
}

Size Window::min_size() const
{
    return m_platform_window->min_size();
}

std::string Window::title() const
{
    return m_platform_window->title();
}

const Context& Window::context() const
{
    return m_platform_window->context();
}

Context& Window::context()
{
    return m_platform_window->context();
}

#pragma endregion

#pragma region state
bool Window::should_close() const
{
    return m_platform_window->should_close();
}

bool Window::is_fullscreen() const
{
    return m_platform_window->is_fullscreen();
}

bool Window::is_iconified() const
{
    return m_platform_window->is_iconified();
}

bool Window::is_maximized() const
{
    return m_platform_window->is_maximized();
}

bool Window::is_resizable() const
{
    return m_platform_window->is_resizable();
}

bool Window::is_visible() const
{
    return m_platform_window->is_visible();
}

bool Window::has_input_focus() const
{
    return m_platform_window->has_input_focus();
}

bool Window::is_cursor_visible() const
{
    return m_platform_window->is_cursor_visible();
}

bool Window::is_cursor_grabbed() const
{
    return m_platform_window->is_cursor_grabbed();
}

#pragma endregion

void swap(Window& lhs, Window& rhs) noexcept
{
    using std::swap;
    if (lhs.m_platform_window) {
        lhs.m_platform_window->set_window_instance(&rhs);
    }
    if (rhs.m_platform_window) {
        rhs.m_platform_window->set_window_instance(&lhs);
    }
    swap(lhs.m_platform_window, rhs.m_platform_window);

    swap(lhs.on_show, rhs.on_show);
    swap(lhs.on_hide, rhs.on_hide);
    swap(lhs.on_close, rhs.on_close);
    swap(lhs.on_focus, rhs.on_focus);
    swap(lhs.on_lost_focus, rhs.on_lost_focus);
    swap(lhs.on_resize, rhs.on_resize);
    swap(lhs.on_move, rhs.on_move);
    swap(lhs.on_key_down, rhs.on_key_down);
    swap(lhs.on_key_up, rhs.on_key_up);
    swap(lhs.on_character, rhs.on_character);
    swap(lhs.on_mouse_move, rhs.on_mouse_move);
    swap(lhs.on_button_down, rhs.on_button_down);
    swap(lhs.on_button_up, rhs.on_button_up);
    swap(lhs.on_mouse_enter, rhs.on_mouse_enter);
    swap(lhs.on_mouse_leave, rhs.on_mouse_leave);
}

} // namespace framework::system
