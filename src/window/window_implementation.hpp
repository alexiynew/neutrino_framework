/**
 * @file window_implementation.hpp
 * @brief Describes interface for all canvas implementations.
 * @author Fedorov Alexey
 * @date 05.04.2017
 */

#ifndef FRAMEWORK_WINDOW_WINDOW_IMPLEMENTATION_HPP
#define FRAMEWORK_WINDOW_WINDOW_IMPLEMENTATION_HPP

#include <memory>

namespace framework {

class window_implementation
{
public:
    virtual ~window_implementation() = default;

    virtual void show() = 0;
    virtual void hide() = 0;
};

std::unique_ptr<window_implementation> get_implementation();
}

#endif
