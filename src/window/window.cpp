/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#include <memory>

#include <window/implementation.hpp>
#include <window/window.hpp>

namespace framework {

window::window(size_t size, const std::string& title)
    : m_implementation(implementation::get_implementation(size, title))
{}

window::~window()
{}

window::window(window&& other) : m_implementation(std::move(other.m_implementation))
{}

window& window::operator=(window&& other)
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

void window::minimize()
{
    m_implementation->minimize();
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

#pragma endregion

#pragma region state

bool window::fullscreen() const
{
    return m_implementation->fullscreen();
}

bool window::minimized() const
{
    return m_implementation->minimized();
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

} // namespace framework
