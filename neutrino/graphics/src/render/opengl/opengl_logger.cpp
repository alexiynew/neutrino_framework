#include <map>
#include <string>

#include <log/log.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_logger.hpp>

using namespace framework::graphics::details::opengl;

namespace framework::graphics
{
const std::string tag = "OpenGL";

void log_opengl_errors(const std::string& file, int line)
{
    struct ErrorDescription
    {
        std::string name;
        std::string description;
    };

    static const std::map<GLenum, ErrorDescription> error_descriptions = {
    {GL_INVALID_ENUM,
     {"GL_INVALID_ENUM",
      "An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no "
      "other side effect than to set the error flag."}},
    {GL_INVALID_VALUE,
     {"GL_INVALID_VALUE",
      "A numeric argument is out of range. The offending command is ignored and has no other side effect than to set "
      "the error flag."}},
    {GL_INVALID_OPERATION,
     {"GL_INVALID_OPERATION",
      "The specified operation is not allowed in the current state. The offending command is ignored and has no other "
      "side effect than to set the error flag."}},
    {GL_INVALID_FRAMEBUFFER_OPERATION,
     {"GL_INVALID_FRAMEBUFFER_OPERATION",
      "The framebuffer object is not complete. The offending command is ignored and has no other side effect than to "
      "set the error flag."}},
    {GL_OUT_OF_MEMORY,
     {"GL_OUT_OF_MEMORY",
      "There is not enough memory left to execute the command. The state of the GL is undefined, except for the state "
      "of the error flags, after this error is recorded."}},
    };

    for (GLenum error = glGetError(); error != GL_NO_ERROR; error = glGetError()) {
        if (error_descriptions.count(error)) {
            const auto& desc = error_descriptions.at(error);
            log::error(tag) << file << ":" << line << "\n" << desc.name << " " << desc.description;
        } else {
            log::error(tag) << file << ":" << line << "\n"
                            << "Unknown error: " << error;
        }
    }
}
} // namespace framework::graphics
