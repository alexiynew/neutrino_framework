#include <common/types.hpp>

#include <gl/details/gl_get_function.hpp>
#include <gl/glxext.hpp>

namespace framework::gl::details
{
gl_function_ptr get_function_implementation(const char* function_name)
{
    return glXGetProcAddressARB(reinterpret_cast<const uint8*>(function_name));
}

} // namespace framework::gl::details
