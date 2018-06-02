/// @file
/// @brief Renderer.
/// @author Fedorov Alexey
/// @date 02.06.2018

#ifndef FRAMEWORK_GRAPHIC_RENDERER_HPP
#define FRAMEWORK_GRAPHIC_RENDERER_HPP

#include <memory>

#include <graphic/canvas_base.hpp>
#include <graphic/window.hpp>

namespace framework
{
namespace graphic
{
class renderer
{
public:
    explicit renderer(std::unique_ptr<canvas_base> canvas);

    void draw();

    void swap_buffers();

private:
    std::unique_ptr<canvas_base> m_canvas;
};

} // namespace graphic

} // namespace framework

#endif
