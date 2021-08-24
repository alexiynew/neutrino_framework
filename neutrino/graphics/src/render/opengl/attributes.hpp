////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief OpenGL attributes.
/// @author Fedorov Alexey
/// @date 03.04.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_ATTRIBUTES_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_ATTRIBUTES_HPP

#include <array>

namespace framework::graphics
{
enum class Attribute
{
    position  = 0,
    normal    = 1,
    tangent   = 2,
    color     = 3,
    texcoord0 = 4,
    texcoord1 = 5,
    texcoord2 = 6,
    texcoord3 = 7,
    texcoord4 = 8,
    texcoord5 = 9,
    texcoord6 = 10,
    texcoord7 = 11,
};

static constexpr int attributes_count = 12;

} // namespace framework::graphics

#endif
