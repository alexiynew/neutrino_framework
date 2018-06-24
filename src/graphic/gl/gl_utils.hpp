/// @file
/// @brief Helper functions.
/// @author Fedorov Alexey
/// @date 21.06.2018

#ifndef FRAMEWORK_GRAPHIC_GL_GL_UTILS_HPP
#define FRAMEWORK_GRAPHIC_GL_GL_UTILS_HPP

namespace framework
{
namespace graphic
{
namespace utils
{
using gl_function_ptr = void (*)();

gl_function_ptr get_function_address(const char* function_name);

template <typename F>
F get_function(const char* function_name)
{
    return reinterpret_cast<F>(get_function_address(function_name));
}

} // namespace utils

} // namespace graphic

} // namespace framework

#endif
