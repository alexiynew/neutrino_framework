#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_LOGGER_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_LOGGER_HPP

#include <string>

namespace neutrino::graphics
{

bool has_opengl_errors(const std::string& file, int line);

////////////////////////////////////////////////////////////////////////////////
/// @brief Log OpenGL errors.
////////////////////////////////////////////////////////////////////////////////
#define HAS_OPENGL_ERRORS() has_opengl_errors(__FILE__, __LINE__)

} // namespace neutrino::graphics

#endif
