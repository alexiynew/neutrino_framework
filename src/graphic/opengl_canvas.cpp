/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#include <graphic/gl/gl.hpp>
#include <graphic/opengl_canvas.hpp>
#include <log/log.hpp>

namespace framework
{
namespace graphic
{
const char* log_tag = "opengl_canvas";

opengl_canvas::opengl_canvas(std::unique_ptr<window::graphic_context> context) : m_context(std::move(context))
{
    if (m_context->valid()) {
        if (!gl::init()) {
            throw std::runtime_error("Can't init OpenGL functions.");
        }
    }
}

opengl_canvas::~opengl_canvas() = default;

void opengl_canvas::clear(float red, float green, float blue, float alpha)
{
    m_context->make_current();

    gl::glClearColor(red, green, blue, alpha);
    gl::glClear(gl::gl_color_buffer_bit);

    auto error = gl::glGetError();

    if (error != gl::gl_no_error) {
        log::error(log_tag) << error << std::endl;
    }
}

void opengl_canvas::swap_buffers()
{
    m_context->swap_buffers();
}

} // namespace graphic

} // namespace framework
