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

#include <string>
#include <memory>

#include <opengl/shader.hpp>
#include <opengl/gl.hpp>
#include <common/types.hpp>

namespace framework::opengl
{

shader::shader() = default;

shader::~shader()
{
    glDeleteShader(m_shader_id);
}

void shader::set_source(const std::string& src)
{
    if (!glIsShader(m_shader_id)) {
        return;
    }

    const char* src_pointer = src.c_str();
    glShaderSource(m_shader_id, 1, &src_pointer, NULL);
}

void shader::set_source(std::ifstream& src_stream)
{
    if (!glIsShader(m_shader_id)) {
        return;
    }

    std::string src;
    std::string line;
    while (getline(src_stream, line)) {
        src += line;
    }

    set_source(src);
}

void shader::compile()
{
    if (!glIsShader(m_shader_id)) {
        return;
    }

    glCompileShader(m_shader_id);
}

void shader::mark_for_deletion()
{
    glDeleteShader(m_shader_id);
}

framework::int32 shader::shader_type() const
{
    framework::int32 type = 0;
    glGetShaderiv(m_shader_id, GL_SHADER_TYPE, &type);
    return type;
}

bool shader::compiled() const
{
    framework::int32 status = 0;
    glGetShaderiv(m_shader_id, GL_COMPILE_STATUS, &status);
    return status;
}

bool shader::marked_for_deletion() const
{
    framework::int32 status = 0;
    glGetShaderiv(m_shader_id, GL_DELETE_STATUS, &status);
    return status;
}

framework::int32 shader::source_length() const
{
    framework::int32 length = 0;
    glGetShaderiv(m_shader_id, GL_SHADER_SOURCE_LENGTH, &length);

    return length;
}

std::string shader::source() const
{
    const framework::int32 length = source_length();

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[length]);

    glGetShaderSource(m_shader_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}


std::string shader::info_log() const
{
    framework::int32 length = 0;
    glGetShaderiv(m_shader_id, GL_INFO_LOG_LENGTH, &length);

    if (length <= 0) {
        return std::string();
    }

    std::unique_ptr<char[]> buffer(new char[length]);

    glGetShaderInfoLog(m_shader_id, length, nullptr, buffer.get());

    return std::string(buffer.get());
}

framework::int32 shader::shader_id() const
{
    return m_shader_id;
}

vertex_shader::vertex_shader()
{
    m_shader_id = glCreateShader(GL_VERTEX_SHADER);
}

fragment_shader::fragment_shader()
{
    m_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
}

/*
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Проверяем шейдерную программу
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        framework::log::error("shader") << "program: " << ProgramErrorMessage.data() << std::endl;
    }



*/

}
