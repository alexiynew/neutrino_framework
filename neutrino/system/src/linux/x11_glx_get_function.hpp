#ifndef FRAMEWORK_SYSTEM_SRC_LINUX_X11_GLX_GET_FUNCTION_HPP
#define FRAMEWORK_SYSTEM_SRC_LINUX_X11_GLX_GET_FUNCTION_HPP

#include <system/context.hpp>

namespace neutrino::system::details::glx
{

using VoidFunctionPtr = void (*)();

VoidFunctionPtr get_function(const char* name);

} // namespace neutrino::system::details::glx

#endif
