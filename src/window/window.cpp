/// @file window.cpp
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

void window::show()
{
    m_implementation->show();
}

void window::hide()
{
    m_implementation->hide();
}
} // namespace framework
