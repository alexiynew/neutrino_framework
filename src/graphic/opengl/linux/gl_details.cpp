/// @file
/// @brief Helper functions.
/// @author Fedorov Alexey
/// @date 21.06.2018

#include <GL/glx.h>

#include <common/types.hpp>
#include <graphic/opengl/gl_details.hpp>

namespace framework::graphic::gl::details
{
gl_function_ptr get_function(const char* function_name)
{
    return glXGetProcAddressARB(reinterpret_cast<const uint8*>(function_name));
}

} // namespace framework::graphic::gl::details
