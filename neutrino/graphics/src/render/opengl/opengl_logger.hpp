#include <string>

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_LOGGER_HPP
    #define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_LOGGER_HPP

namespace framework::graphics
{

void log_opengl_errors(const std::string& file, int line);

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Log OpenGL errors.
    ////////////////////////////////////////////////////////////////////////////////
    #define LOG_OPENGL_ERRORS() log_opengl_errors(__FILE__, __LINE__) // NOLINT

} // namespace framework::graphics

#endif
