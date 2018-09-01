/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#include <graphic/opengl/gl.hpp>
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

std::string opengl_canvas::vendor_name()
{
    m_context->make_current();

    const char* value = reinterpret_cast<const char*>(gl::glGetString(GL_VENDOR));

    if (value != nullptr) {
        return std::string(value);
    }

    return std::string();
}

std::string opengl_canvas::renderer_name()
{
    m_context->make_current();

    const char* value = reinterpret_cast<const char*>(gl::glGetString(GL_RENDERER));

    if (value != nullptr) {
        return std::string(value);
    }

    return std::string();
}

std::string opengl_canvas::version()
{
    m_context->make_current();

    const char* value = reinterpret_cast<const char*>(gl::glGetString(GL_VERSION));

    if (value != nullptr) {
        return std::string(value);
    }

    return std::string();
}

std::string opengl_canvas::shading_language_version()
{
    m_context->make_current();

    const char* value = reinterpret_cast<const char*>(gl::glGetString(GL_SHADING_LANGUAGE_VERSION));

    if (value != nullptr) {
        return std::string(value);
    }

    return std::string();
}

void opengl_canvas::clear(float red, float green, float blue, float alpha)
{
    m_context->make_current();

    gl::glClearColor(red, green, blue, alpha);
    gl::glClear(GL_COLOR_BUFFER_BIT);

    auto error = gl::glGetError();

    if (error != GL_NO_ERROR) {
        log::error(log_tag) << error << std::endl;
    }
}

void opengl_canvas::swap_buffers()
{
    m_context->swap_buffers();
}

} // namespace graphic

} // namespace framework
