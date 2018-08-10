/// @file
/// @brief Helper functions.
/// @author Fedorov Alexey
/// @date 21.06.2018

#include <GL/glx.h>

#include <common/types.hpp>
#include <graphic/gl/gl_utils.hpp>

namespace framework
{
namespace graphic
{
namespace utils
{
gl_function_ptr get_function_address(const char* function_name)
{
    return glXGetProcAddressARB(reinterpret_cast<const uint8*>(function_name));
}

} // namespace utils

} // namespace graphic

} // namespace framework
