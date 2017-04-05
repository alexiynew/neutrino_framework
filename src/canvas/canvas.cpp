/**
 * @file canvas.cpp
 * @brief Canvas class.
 * @author Fedorov Alexey
 * @date 04.04.2017
 */

#include <canvas/canvas.hpp>
#include <canvas/linux/linux_canvas.hpp>

namespace framework {

canvas::canvas(unsigned int width, unsigned int height)
    : m_implementation(std::make_unique<linux_canvas>(width, height))
{
}

canvas::~canvas()
{
}

void canvas::show()
{
    m_implementation->show();
}

void canvas::hide()
{
    m_implementation->hide();
}
}
