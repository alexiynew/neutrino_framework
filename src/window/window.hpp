/**
 * @file
 * @brief Window interface class.
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
    window();
    ~window();

    void show();
    void hide();

private:
    std::unique_ptr<window_implementation> m_implementation;
};
}

#endif
