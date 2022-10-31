#include <system/src/linux/x11_glx_get_function.hpp>

#include <GL/glx.h>

namespace neutrino::system::details::glx
{

VoidFunctionPtr get_function(const char* name)
{
    return glXGetProcAddressARB(reinterpret_cast<const unsigned char*>(name));
}

} // namespace neutrino::system::details::glx
