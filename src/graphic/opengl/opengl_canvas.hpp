/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#ifndef FRAMEWORK_GRAPHIC_OPENGL_CANVAS_HPP
#define FRAMEWORK_GRAPHIC_OPENGL_CANVAS_HPP

#include <graphic/canvas.hpp>
#include <graphic/window.hpp>

namespace framework
{
namespace graphic
{
class opengl_canvas final : public canvas
{
public:
    class implementation;

    explicit opengl_canvas(const ::framework::graphic::window& window);

    ~opengl_canvas() override;

    void make_current() override;
    void swap_buffers() override;

private:
    std::unique_ptr<implementation> m_implementation;
};

} // namespace graphic

} // namespace framework

#endif
