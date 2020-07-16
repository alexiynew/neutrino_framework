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
#include <math/math.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_shader.hpp>
#include <graphics/src/render/opengl/opengl_texture.hpp>
#include <graphics/src/render/render_command.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
const std::string tag = "OpenGL";

namespace uniform_name
{
const std::string model_martix      = "modelMatrix";
const std::string view_martix       = "viewMatrix";
const std::string projection_martix = "projectionMatrix";
const std::string texture0          = "texture0";
} // namespace uniform_name

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

void set_uniform(int location, const math::Matrix4f& matrix)
{
    if (location == -1) {
        return;
    }

    glUniformMatrix4fv(location, 1, false, matrix.data());
}

void set_uniform(int location, int value)
{
    if (location == -1) {
        return;
    }

    glUniform1i(location, value);
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
    glDeleteShader(m_vertex_shader);
    glDeleteShader(m_fragment_shader);
    glDeleteProgram(m_shader_program);

    m_vertex_shader   = 0;
    m_fragment_shader = 0;
    m_shader_program  = 0;

    m_model_matrix      = -1;
    m_view_matrix       = -1;
    m_projection_matrix = -1;
}

bool OpenglShader::load(const Shader& shader)
{
    m_vertex_shader   = create_shader(GL_VERTEX_SHADER, shader.vertex_source());
    m_fragment_shader = create_shader(GL_FRAGMENT_SHADER, shader.fragment_source());
    m_shader_program  = create_shader_program(m_vertex_shader, m_fragment_shader);

    m_model_matrix      = glGetUniformLocation(m_shader_program, uniform_name::model_martix.c_str());
    m_view_matrix       = glGetUniformLocation(m_shader_program, uniform_name::view_martix.c_str());
    m_projection_matrix = glGetUniformLocation(m_shader_program, uniform_name::projection_martix.c_str());

    m_texture = glGetUniformLocation(m_shader_program, uniform_name::texture0.c_str());

    return m_shader_program != 0;
}

void OpenglShader::use() const
{
    glUseProgram(m_shader_program);
}

void OpenglShader::set_uniforms(const Uniforms& uniforms) const
{
    set_uniform(m_model_matrix, uniforms.model_matrix);
    set_uniform(m_view_matrix, uniforms.view_matrix.get());
    set_uniform(m_projection_matrix, uniforms.projection_matrix.get());
}

void OpenglShader::set_texture(int index) const
{
    set_uniform(m_texture, index);
}

} // namespace framework::graphics
