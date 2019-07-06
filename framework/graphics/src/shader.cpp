/// @file
/// @brief OpenGL shader.
/// @author Fedorov Alexey
/// @date 12.04.2019

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

#include <memory>
#include <string>

#include <common/types.hpp>
#include <gl/gl.hpp>
#include <graphics/shader.hpp>

namespace framework::graphics
{
#pragma region shader_base

shader_base::shader_base(int32 shader_type)
{
    m_shader_id = gl::glCreateShader(shader_type);
}

shader_base::~shader_base()
{
    mark_for_deletion();
}

shader_base::shader_base(shader_base&& other)
{
    std::swap(other.m_shader_id, m_shader_id);
}

shader_base& shader_base::operator=(shader_base&& other)
{
    std::swap(other.m_shader_id, m_shader_id);
    return *this;
}

void shader_base::set_source(const std::string& src)
{
    const char* src_pointer = src.c_str();
    gl::glShaderSource(m_shader_id, 1, &src_pointer, NULL);
}

void shader_base::set_source(std::istream& src_stream)
{
    std::string src;
    std::string line;
    while (getline(src_stream, line)) {
        src += line;
    }

    set_source(src);
}

void shader_base::compile()
{
    gl::glCompileShader(m_shader_id);
}

void shader_base::mark_for_deletion()
{
    gl::glDeleteShader(m_shader_id);
}

framework::int32 shader_base::shader_type() const
{
    framework::int32 type = 0;
    gl::glGetShaderiv(m_shader_id, GL_SHADER_TYPE, &type);
    return type;
}

bool shader_base::valid() const
{
    return gl::glIsShader(m_shader_id);
}

bool shader_base::compiled() const
{
    framework::int32 status = 0;
    gl::glGetShaderiv(m_shader_id, GL_COMPILE_STATUS, &status);
    return status;
}

framework::int32 shader_base::source_length() const
{
    framework::int32 length = 0;
    gl::glGetShaderiv(m_shader_id, GL_SHADER_SOURCE_LENGTH, &length);

    return length;
}

std::string shader_base::source() const
{
    const framework::int32 length = source_length();

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[length]);

    gl::glGetShaderSource(m_shader_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}

std::string shader_base::info_log() const
{
    framework::int32 length = 0;
    gl::glGetShaderiv(m_shader_id, GL_INFO_LOG_LENGTH, &length);

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[length]);

    gl::glGetShaderInfoLog(m_shader_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}

framework::uint32 shader_base::shader_id() const
{
    return m_shader_id;
}

#pragma endregion

#pragma region concrete_shaders

vertex_shader::vertex_shader() : shader_base(GL_VERTEX_SHADER)
{}

fragment_shader::fragment_shader() : shader_base(GL_FRAGMENT_SHADER)
{}

#pragma endregion

#pragma region shader_program

shader_program::shader_program()
{
    m_program_id = gl::glCreateProgram();
}

shader_program::~shader_program()
{
    gl::glDeleteProgram(m_program_id);
}

void shader_program::arttach(const shader_base& shader)
{
    gl::glAttachShader(m_program_id, shader.shader_id());
}

void shader_program::link()
{
    gl::glLinkProgram(m_program_id);
}

void shader_program::use()
{
    gl::glUseProgram(m_program_id);
}

void shader_program::stop_using()
{
    gl::glUseProgram(0);
}

void shader_program::uniform(const std::string& name, int value)
{
    const uint32 uniform_id = gl::glGetUniformLocation(m_program_id, name.c_str());
    gl::glUniform1i(uniform_id, value);
}

void shader_program::uniform(const std::string& name, math::matrix4f value, bool transpose)
{
    const uint32 uniform_id = gl::glGetUniformLocation(m_program_id, name.c_str());
    gl::glUniformMatrix4fv(uniform_id, 1, transpose, value.data());
}

bool shader_program::linked() const
{
    framework::int32 status = 0;
    gl::glGetProgramiv(m_program_id, GL_LINK_STATUS, &status);
    return status;
}

std::string shader_program::info_log() const
{
    framework::int32 length = 0;
    gl::glGetProgramiv(m_program_id, GL_INFO_LOG_LENGTH, &length);

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[length]);

    gl::glGetProgramInfoLog(m_program_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}

framework::uint32 shader_program::program_id() const
{
    return m_program_id;
}

#pragma endregion

} // namespace framework::graphics
