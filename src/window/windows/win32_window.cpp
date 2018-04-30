/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 19.04.2017

#include <window/windows/win32_window.hpp>

namespace framework {

std::unique_ptr<window::implementation> window::implementation::get_implementation(window::size_t size,
                                                                                   const std::string& title)
{
    return std::make_unique<win32_window>(size, title);
}

win32_window::win32_window(window::size_t, const std::string&)
{}

win32_window::~win32_window()
{}

/// @name actions
/// @{
void win32_window::show()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::hide()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::focus()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::process_events()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::minimize()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::maximize()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::switch_to_fullscreen()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::restore()
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

/// @name setters
/// @{
void win32_window::set_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_position(window::position_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_max_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_min_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_resizable(bool)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_title(const std::string&)
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

/// @name getters
/// @{
window::position_t win32_window::position() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t win32_window::size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t win32_window::max_size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t win32_window::min_size() const
{
    throw std::logic_error("Function is not implemented.");
}

std::string win32_window::title() const
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

/// @name state
/// @{
bool win32_window::fullscreen() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::minimized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::maximized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::resizable() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::visible() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::focused() const
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

} // namespace framework
