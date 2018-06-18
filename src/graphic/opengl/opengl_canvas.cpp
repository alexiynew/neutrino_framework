/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#include <graphic/opengl/canvas/implementation.hpp>
#include <graphic/opengl/opengl_canvas.hpp>

namespace framework
{
namespace graphic
{
opengl_canvas::opengl_canvas(const ::framework::graphic::window& window)
    : m_implementation(implementation::create(window))
{}

opengl_canvas::~opengl_canvas() = default;

void opengl_canvas::make_current()
{
    m_implementation->make_current();
}

void opengl_canvas::swap_buffers()
{
    m_implementation->swap_buffers();
}

} // namespace graphic

} // namespace framework
