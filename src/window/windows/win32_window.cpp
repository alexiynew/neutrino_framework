/**
 * @file win32_window.cpp
 * @brief Window implementation for osx.
 * @author Fedorov Alexey
 * @date 19.04.2017
 */

#include <window/windows/win32_window.hpp>

namespace framework {

std::unique_ptr<window_implementation> get_implementation()
{
    return std::make_unique<win32_window>();
}

win32_window::win32_window()
{
}

win32_window::~win32_window()
{
    hide();
}

void win32_window::show()
{
}

void win32_window::hide()
{
}
}
