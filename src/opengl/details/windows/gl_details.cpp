/// @file
/// @brief Helper functions.
/// @author Fedorov Alexey
/// @date 05.09.2018

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

#include <windows.h>

#include <common/types.hpp>
#include <opengl/details/gl_details.hpp>

namespace framework::opengl::opengl_details
{
gl_function_ptr get_function_implementation(const char* function_name)
{
    auto function = reinterpret_cast<gl_function_ptr>(wglGetProcAddress(function_name));
    if (function == nullptr || (function == reinterpret_cast<gl_function_ptr>(0x1)) ||
        (function == reinterpret_cast<gl_function_ptr>(0x2)) || (function == reinterpret_cast<gl_function_ptr>(0x3)) ||
        (function == reinterpret_cast<gl_function_ptr>(-1))) {
        HMODULE module = LoadLibrary(L"opengl32.dll");
        if (module != nullptr) {
            function = reinterpret_cast<gl_function_ptr>(GetProcAddress(module, function_name));
        } else {
            function = nullptr;
        }
    }

    return function;
}

} // namespace framework::opengl::opengl_details
