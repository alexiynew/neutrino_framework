/**
 * @file canvas.hpp
 * @brief Canvas class.
 * @author Fedorov Alexey
 * @date 08.03.2017
 */

#ifndef FRAMEWORK_CANVAS_HPP
#define FRAMEWORK_CANVAS_HPP

namespace framework {
class canvas
{
public:
    canvas(unsigned int widht, unsigned int height);

    void show();

private:
    unsigned int m_width;
    unsigned int m_height;
};
}

#endif
