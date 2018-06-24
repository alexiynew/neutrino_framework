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
    explicit opengl_canvas(std::unique_ptr<window::graphic_context> context);

    ~opengl_canvas() override;

    void clear(float red, float green, float blue, float alpha) override;

    void swap_buffers() override;

private:
    std::unique_ptr<window::graphic_context> m_context;
};

} // namespace graphic

} // namespace framework

#endif
