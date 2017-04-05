/**
 * @file canvas.hpp
 * @brief Canvas class.
 * @author Fedorov Alexey
 * @date 04.04.2017
 */

#ifndef FRAMEWORK_CANVAS_HPP
#define FRAMEWORK_CANVAS_HPP

#include <canvas/canvas_implementation.hpp>
#include <memory>

namespace framework {

class canvas
{
public:
    canvas(unsigned int width, unsigned int height);
    ~canvas();

    void show();
    void hide();

private:
    std::unique_ptr<canvas_implementation> m_implementation;
};
}

#endif
