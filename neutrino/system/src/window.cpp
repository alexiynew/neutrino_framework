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

#include <system/src/platform_window.hpp>
#include <system/window.hpp>

namespace framework::system
{
void Window::set_application_name(const std::string& name)
{
    details::PlatformWindow::set_application_name(name);
}

Window::Window(Size size, const std::string& title, ContextSettings settings)
    : m_platform_window(details::create_platform_window(*this, size, title, std::move(settings)))
{}

Window::~Window() = default;

Window::Window(Window&& other) noexcept : m_platform_window(std::move(other.m_platform_window))
{}

Window& Window::operator=(Window&& other) noexcept
{
    m_platform_window = std::move(other.m_platform_window);
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

void Window::process_events()
{
    m_platform_window->process_events();
}

void Window::make_current()
{
    m_platform_window->make_current();
}

void Window::swap_buffers()
{
    m_platform_window->swap_buffers();
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

#pragma endregion

} // namespace framework::system
