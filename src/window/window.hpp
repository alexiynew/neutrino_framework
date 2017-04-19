/**
 * @file window.hpp
 * @brief Window class.
 * @author Fedorov Alexey
 * @date 04.04.2017
 */

#ifndef FRAMEWORK_WINDOW_HPP
#define FRAMEWORK_WINDOW_HPP

#include <memory>

namespace framework {

class window_implementation;

class window
{
public:
    window(unsigned int width, unsigned int height);
    ~window();

    void show();
    void hide();

private:
    std::unique_ptr<window_implementation> m_implementation;
};
}

#endif
