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

#include <cstdint>

#include <graphics/shader.hpp>
#include <log/log.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_shader.hpp>

using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
const std::string tag = "OpenGL";

std::string shader_type_string(int shader_type)
{
    switch (shader_type) {
        case GL_VERTEX_SHADER: return "GL_VERTEX_SHADER";
        case GL_FRAGMENT_SHADER: return "GL_FRAGMENT_SHADER";
    }

    return "UNKNOWN_SHADER";
}

std::string shader_info_log(int shader_id)
{
    int length = 0;
    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[static_cast<std::size_t>(length)]);
    glGetShaderInfoLog(shader_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}

std::string shader_program_info_log(std::uint32_t program_id)
{
    int length = 0;
    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &length);

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[static_cast<std::size_t>(length)]);
    glGetProgramInfoLog(program_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}

std::uint32_t create_shader(int shader_type, const std::string& source)
{
    using namespace framework;

    std::uint32_t shader_id = glCreateShader(shader_type);

    const char* source_pointer = source.c_str();
    glShaderSource(shader_id, 1, &source_pointer, nullptr);

    glCompileShader(shader_id);

    int compiled = 0;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled);
    if (compiled == 0) {
        log::error(tag) << shader_type_string(shader_type) << " compilation error:\n" << shader_info_log(shader_id);

        glDeleteShader(shader_id);
        return 0;
    }

    return shader_id;
}

std::uint32_t create_shader_program(std::uint32_t vertex_shader_id, std::uint32_t fragment_shader_id)
{
    using namespace framework;

    if (vertex_shader_id == 0 || fragment_shader_id == 0) {
        return 0;
    }

    std::uint32_t program_id = glCreateProgram();

    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);

    glLinkProgram(program_id);

    // mark shader for deletion
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);

    int linked = 0;
    glGetProgramiv(program_id, GL_LINK_STATUS, &linked);
    if (linked == 0) {
        log::error(tag) << "Shader program link error:\n" << shader_program_info_log(program_id);

        glDeleteProgram(program_id);
        return 0;
    }

    return program_id;
}

} // namespace

namespace framework::graphics
{
OpenglShader::~OpenglShader()
{
    clear();
}

void OpenglShader::clear()
{
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    glDeleteProgram(shader_program);

    vertex_shader = 0;
    fragment_shader = 0;
    shader_program = 0;
}

bool OpenglShader::load(const Shader& shader)
{
    vertex_shader   = create_shader(GL_VERTEX_SHADER, shader.vertex_source());
    fragment_shader = create_shader(GL_FRAGMENT_SHADER, shader.fragment_source());
    shader_program  = create_shader_program(vertex_shader, fragment_shader);

    return shader_program != 0;
}

void OpenglShader::use() const
{
    glUseProgram(shader_program);
}

} // namespace framework::graphics
