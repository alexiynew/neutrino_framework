/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#include <memory>
#include <window/window.hpp>
#include <window/window_implementation.hpp>

namespace framework {

window::window()
    : m_implementation(get_implementation())
{
}

window::~window()
{
}

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
void window::set_size(int32 width, int32 height)
{
    m_implementation->set_size(width, height);
}

void window::set_position(int32 x, int32 y)
{
    m_implementation->set_position(x, y);
}

void window::set_max_size(int32 width, int32 height)
{
    m_implementation->set_max_size(width, height);
}

void window::set_min_size(int32 width, int32 height)
{
    m_implementation->set_min_size(width, height);
}

void window::set_title(const std::string& title)
{
    m_implementation->set_title(title);
}
/// @}

/// @name getters
/// @{
int window::x()
{
    return m_implementation->x();
}

int window::y()
{
    return m_implementation->y();
}

int window::width()
{
    return m_implementation->width();
}

int window::height()
{
    return m_implementation->height();
}

int window::max_height()
{
    return m_implementation->max_height();
}

int window::max_width()
{
    return m_implementation->max_width();
}

int window::min_height()
{
    return m_implementation->min_height();
}

int window::min_width()
{
    return m_implementation->min_width();
}

std::string window::title()
{
    return m_implementation->title();
}

bool window::full_screen()
{
    return m_implementation->state()[window_implementation::state_flags::full_screen];
}

bool window::minimized()
{
    return m_implementation->state()[window_implementation::state_flags::minimized];
}

bool window::maximized()
{
    return m_implementation->state()[window_implementation::state_flags::maximized];
}

bool window::resizable()
{
    return m_implementation->state()[window_implementation::state_flags::resizable];
}

bool window::visible()
{
    return m_implementation->state()[window_implementation::state_flags::visible];
}

bool window::focused()
{
    return m_implementation->state()[window_implementation::state_flags::focused];
}
/// @}
}
