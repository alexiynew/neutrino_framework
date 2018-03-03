/// @file cocoa_window.cpp
/// @brief Window implementation for osx.
/// @author Fedorov Alexey
/// @date 19.04.2017

#include <memory>
#include <window/osx/cocoa_window.hpp>

namespace framework {

std::unique_ptr<window_implementation> get_implementation()
{
    return std::make_unique<cocoa_window>();
}

cocoa_window::cocoa_window()
{
}

cocoa_window::~cocoa_window()
{
}

void cocoa_window::show()
{
}

void cocoa_window::hide()
{
}
} // namespace framework
