/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#ifndef FRAMEWORK_GRAPHIC_OPENGL_CANVAS_HPP
#define FRAMEWORK_GRAPHIC_OPENGL_CANVAS_HPP

#include <graphic/canvas_base.hpp>
#include <graphic/window.hpp>

namespace framework
{
namespace graphic
{
class opengl_canvas final : public canvas_base
{
public:
    explicit opengl_canvas(const ::framework::graphic::window& window);

    void make_current() override;
    void swap_buffers() override;

private:
};

} // namespace graphic

} // namespace framework

#endif
