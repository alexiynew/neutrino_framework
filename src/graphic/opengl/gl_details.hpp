/// @file
/// @brief OpneGL helper functions.
/// @author Fedorov Alexey
/// @date 01.09.2018

#ifndef FRAMEWORK_GRAPHIC_OPENGL_GL_DETAILS_HPP
#define FRAMEWORK_GRAPHIC_OPENGL_GL_DETAILS_HPP

namespace framework::graphic::gl::details
{
using gl_function_ptr = void (*)();
gl_function_ptr get_function(const char* function_name);

} // namespace framework::graphic::gl::details

#endif
