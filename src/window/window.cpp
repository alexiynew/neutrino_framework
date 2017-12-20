/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#include <memory>
#include <window/implementation.hpp>
#include <window/window.hpp>

namespace framework {

window::window()
    : m_implementation(implementation::get_implementation())
{}

window::~window()
{}

/// @name actions
/// @{
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

void window::to_full_screen()
{
    m_implementation->to_full_screen();
}

void window::restore()
{
    m_implementation->restore();
}
/// @}

/// @name setters
/// @{
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

void window::set_title(const std::string& title)
{
    m_implementation->set_title(title);
}
/// @}

/// @name getters
/// @{
window::position_t window::position()
{
    return m_implementation->position();
}

window::size_t window::size()
{
    return m_implementation->size();
}

window::size_t window::max_size()
{
    return m_implementation->max_size();
}

window::size_t window::min_size()
{
    return m_implementation->min_size();
}

std::string window::title()
{
    return m_implementation->title();
}
/// @}

/// @name state
/// @{
bool window::full_screen()
{
    return m_implementation->full_screen();
}

bool window::minimized()
{
    return m_implementation->minimized();
}

bool window::maximized()
{
    return m_implementation->maximized();
}

bool window::resizable()
{
    return m_implementation->resizable();
}

bool window::visible()
{
    return m_implementation->visible();
}

bool window::focused()
{
    return m_implementation->focused();
}
/// @}

} // namespace framework
