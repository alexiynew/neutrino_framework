/// @file
/// @brief OpenGL shader.
/// @author Fedorov Alexey
/// @date 03.04.2020

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

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_SHADER_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_SHADER_HPP

#include <cstdint>

namespace framework::graphics
{
class Shader;

class OpenglShader
{
public:
    OpenglShader() = default;

    OpenglShader(const OpenglShader&) = delete;
    OpenglShader& operator=(const OpenglShader&) = delete;

    OpenglShader(OpenglShader&&) = default;
    OpenglShader& operator=(OpenglShader&&) = default;

    ~OpenglShader();

    bool load(const Shader& shader);
    void clear();

    void use() const;

private:

    std::uint32_t vertex_shader   = 0;
    std::uint32_t fragment_shader = 0;
    std::uint32_t shader_program  = 0;
};

} // namespace framework::graphics

#endif
