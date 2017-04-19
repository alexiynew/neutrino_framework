/**
 * @file window.cpp
 * @brief Window class.
 * @author Fedorov Alexey
 * @date 04.04.2017
 */

#include <window/window.hpp>
#include <window/window_implementation.hpp>

namespace framework {

window::window(unsigned int width, unsigned int height)
    : m_implementation(std::make_unique<window_implementation>(width, height))
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
}
