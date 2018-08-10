/// @file
/// @brief Base class for all canvas implementations.
/// @author Fedorov Alexey
/// @date 02.06.2018

#ifndef FRAMEWORK_GRAPHIC_CANVAS_HPP
#define FRAMEWORK_GRAPHIC_CANVAS_HPP

namespace framework
{
namespace graphic
{
class canvas
{
public:
    virtual ~canvas() = default;

    virtual void clear(float red, float green, float blue, float alpha) = 0;

    virtual void swap_buffers() = 0;
};

} // namespace graphic

} // namespace framework

#endif
