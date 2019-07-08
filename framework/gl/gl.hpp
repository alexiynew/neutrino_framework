/// @file
/// @brief OpneGL functions.
/// @author Fedorov Alexey
/// @date 17.09.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_GL_GL_HPP
#define FRAMEWORK_GL_GL_HPP

#include <gl/inc/gl_wrapper.hpp>

/// @details
///
/// The @ref opengl_module module gives access to OpenGL functionality.
/// Module wraps functions up to OpenGL version 4.6 and other extensions.
///
/// @warning Only OpenGL core profile is supporteed.
///
/// Before using any functions the ::framework::opengl::init function must be called.
/// After initialization any supported functions will get their address and can be used.
/// Which of them will be available depends on the current user platform, video card, and video drivers.
///
/// Each extension has its related variable that is set if the extension is supported by the platform.
/// The variable is set only when all functions from that extension is supported.
/// It should be checked before using this extension. @n
/// The variable has name in format 'extension_name_supported', f.e. '`gl_arb_debug_output_supported`'.
///
/// Code example:
/// @code
/// using namespace framework::opengl;
///
/// ::framework::opengl::init();
///
/// // check if specific version supported
/// if (gl_version_3_2_supported) {
///     // use functions form OpenGL 3.2
/// }
/// // check if specific function is available.
/// if (glUseProgram) {
///     glUseProgram(shader);
/// }
///
/// @endcode

/// @defgroup opengl_module OpenGL API
/// @{

/// @brief Contails OpenGL functions.
namespace framework::gl
{
/// @addtogroup opengl_module
/// @{

/// @brief Initializes GL functions.
///
/// This function must be called before use OpenGL.
/// It is safe to call init several times, actual initialisation happens only once.
///
/// @note On some systems its required to set current context before calling this function.
///
/// @thread_safety This function may be called from any thread.
void init();

/// @}

} // namespace framework::gl

/// @}

#endif
