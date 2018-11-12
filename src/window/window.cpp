/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

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

#include <memory>

#include <window/details/implementation.hpp>
#include <window/window.hpp>

namespace framework::os
{
std::string window::implementation::application_name = "Application";

void window::set_application_name(const std::string& name)
{
    implementation::set_application_name(name);
}

void window::implementation::set_application_name(const std::string& name)
{
    application_name = name;
}

window::window(size_t size, const std::string& title, opengl::context_settings settings)
    : m_implementation(implementation::create(size, title, std::move(settings)))
{}

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

void window::set_size(size_t size)
{
    m_implementation->set_size(size);
}

void window::set_position(position_t position)
{
    m_implementation->set_position(position);
}

void window::set_max_size(size_t max_size)
{
    m_implementation->set_max_size(max_size);
}

void window::set_min_size(size_t min_size)
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

window::position_t window::position() const
{
    return m_implementation->position();
}

window::size_t window::size() const
{
    return m_implementation->size();
}

window::size_t window::max_size() const
{
    return m_implementation->max_size();
}

window::size_t window::min_size() const
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

#pragma region window::size_t

bool operator==(const window::size_t& lhs, const window::size_t& rhs)
{
    return lhs.width == rhs.width && lhs.height == rhs.height;
}

bool operator!=(const window::size_t& lhs, const window::size_t& rhs)
{
    return !(lhs == rhs);
}

#pragma endregion

#pragma region window::position_t

bool operator==(const window::position_t& lhs, const window::position_t& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const window::position_t& lhs, const window::position_t& rhs)
{
    return !(lhs == rhs);
}

#pragma endregion

} // namespace framework::os
