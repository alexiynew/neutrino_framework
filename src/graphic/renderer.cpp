/// @file
/// @brief Renderer.
/// @author Fedorov Alexey
/// @date 02.06.2018

#include <graphic/renderer.hpp>

void perform_draw()
{}

namespace framework
{
namespace graphic
{
renderer::renderer(std::unique_ptr<canvas> canvas) : m_canvas(std::move(canvas))
{}

void renderer::draw()
{
    m_canvas->make_current();

    perform_draw();
}

void renderer::swap_buffers()
{
    m_canvas->swap_buffers();
}

} // namespace graphic

} // namespace framework
