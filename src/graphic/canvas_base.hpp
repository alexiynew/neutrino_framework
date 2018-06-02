/// @file
/// @brief Base class for canvas implementations.
/// @author Fedorov Alexey
/// @date 02.06.2018

#ifndef FRAMEWORK_GRAPHIC_CANVAS_BASE_HPP
#define FRAMEWORK_GRAPHIC_CANVAS_BASE_HPP

namespace framework
{
namespace graphic
{
class canvas_base
{
public:
    virtual ~canvas_base() = default;

    virtual void make_current() = 0;
    virtual void swap_buffers() = 0;
};

} // namespace graphic

} // namespace framework

#endif
