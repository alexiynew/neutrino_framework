/**
 * @file win32_window.hpp
 * @brief Window implementation for windows.
 * @author Fedorov Alexey
 * @date 19.04.2017
 */

#ifndef FRAMEWORK_WINDOW_WINDOWS_WIN32_WINDOW_HPP
#define FRAMEWORK_WINDOW_WINDOWS_WIN32_WINDOW_HPP

#include <window/window_implementation.hpp>

namespace framework {

class win32_window final : public window_implementation
{
public:
    win32_window();
    ~win32_window() override;

    void show() override;
    void hide() override;
};
}

#endif
