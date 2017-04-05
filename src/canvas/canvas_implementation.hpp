/**
 * @file canvas_implementation.hpp
 * @brief Describes interface for all canvas implementations.
 * @author Fedorov Alexey
 * @date 05.04.2017
 */

#ifndef FRAMEWORK_CANVAS_CANVAS_IMPLEMENTATION_HPP
#define FRAMEWORK_CANVAS_CANVAS_IMPLEMENTATION_HPP

namespace framework {

class canvas_implementation
{
public:
    virtual ~canvas_implementation() = default;

    virtual void show() = 0;
    virtual void hide() = 0;
};
}

#endif
