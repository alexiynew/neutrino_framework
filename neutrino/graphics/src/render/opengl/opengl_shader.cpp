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

#include <algorithm>
#include <array>
#include <cstdint>

#include <graphics/shader.hpp>
#include <log/log.hpp>
#include <math/math.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_logger.hpp>
#include <graphics/src/render/opengl/opengl_shader.hpp>
#include <graphics/src/render/opengl/opengl_texture.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
const std::string tag = "OpenGL";

constexpr std::array<GLenum, 38> uniform_types = {
GL_FLOAT,         GL_FLOAT_VEC2,        GL_FLOAT_VEC3,        GL_FLOAT_VEC4,
GL_DOUBLE,        GL_DOUBLE_VEC2,       GL_DOUBLE_VEC3,       GL_DOUBLE_VEC4,
GL_INT,           GL_INT_VEC2,          GL_INT_VEC3,          GL_INT_VEC4,
GL_UNSIGNED_INT,  GL_UNSIGNED_INT_VEC2, GL_UNSIGNED_INT_VEC3, GL_UNSIGNED_INT_VEC4,
GL_BOOL,          GL_BOOL_VEC2,         GL_BOOL_VEC3,         GL_BOOL_VEC4,
GL_FLOAT_MAT2,    GL_FLOAT_MAT3,        GL_FLOAT_MAT4,        GL_FLOAT_MAT2x3,
GL_FLOAT_MAT2x4,  GL_FLOAT_MAT3x2,      GL_FLOAT_MAT3x4,      GL_FLOAT_MAT4x2,
GL_FLOAT_MAT4x3,  GL_DOUBLE_MAT2,       GL_DOUBLE_MAT3,       GL_DOUBLE_MAT4,
GL_DOUBLE_MAT2x3, GL_DOUBLE_MAT2x4,     GL_DOUBLE_MAT3x2,     GL_DOUBLE_MAT3x4,
GL_DOUBLE_MAT4x2, GL_DOUBLE_MAT4x3,
};

constexpr std::array<GLenum, 1> texture_types = {
    GL_SAMPLER_2D
};

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

template <std::size_t N>
OpenglShader::UniformMap get_active_uniforms(std::uint32_t shader_program, const std::array<GLenum, N>& supported_types)
{
    constexpr int buffer_size = 512;

    int count = 0;
    glGetProgramiv(shader_program, GL_ACTIVE_UNIFORMS, &count);

    OpenglShader::UniformMap res;

    for (int i = 0; i < count; ++i) {
        char name_buffer[buffer_size] = {0};
        int size                      = 0;
        GLenum type                   = GL_NONE;
        glGetActiveUniform(shader_program, static_cast<GLuint>(i), buffer_size, nullptr, &size, &type, name_buffer);

        if (size != 1) {
            continue; // array uniforms is not supported
        }

        if (std::find(supported_types.begin(), supported_types.end(), type) == supported_types.end()) {
            continue;
        }

        const int location = glGetUniformLocation(shader_program, name_buffer);
        res[std::string(name_buffer)] = location;
    }

    return res;
}

class UniformSetterImpl : public UniformSetter
{
public:
    void set_uniform(int location, const Uniform<float>& uniform) const override
    {
        glUniform1f(location, uniform.value());
    }

    void set_uniform(int location, const Uniform<math::Vector2f>& uniform) const override
    {
        glUniform2fv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector3f>& uniform) const override
    {
        glUniform3fv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector4f>& uniform) const override
    {
        glUniform4fv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<double>& uniform) const override
    {
        glUniform1d(location, uniform.value());
    }

    void set_uniform(int location, const Uniform<math::Vector2d>& uniform) const override
    {
        glUniform2dv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector3d>& uniform) const override
    {
        glUniform3dv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector4d>& uniform) const override
    {
        glUniform4dv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<int>& uniform) const override
    {
        glUniform1i(location, uniform.value());
    }

    void set_uniform(int location, const Uniform<math::Vector2i>& uniform) const override
    {
        glUniform2iv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector3i>& uniform) const override
    {
        glUniform3iv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector4i>& uniform) const override
    {
        glUniform4iv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<unsigned int>& uniform) const override
    {
        glUniform1ui(location, uniform.value());
    }

    void set_uniform(int location, const Uniform<math::Vector2u>& uniform) const override
    {
        glUniform2uiv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector3u>& uniform) const override
    {
        glUniform3uiv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Vector4u>& uniform) const override
    {
        glUniform4uiv(location, 1, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<bool>& uniform) const override
    {
        glUniform1i(location, uniform.value());
    }

    void set_uniform(int location, const Uniform<math::Vector2b>& uniform) const override
    {
        glUniform2iv(location, 1, math::Vector2i(uniform.value()).data());
    }

    void set_uniform(int location, const Uniform<math::Vector3b>& uniform) const override
    {
        glUniform3iv(location, 1, math::Vector3i(uniform.value()).data());
    }

    void set_uniform(int location, const Uniform<math::Vector4b>& uniform) const override
    {
        glUniform4iv(location, 1, math::Vector4i(uniform.value()).data());
    }

    void set_uniform(int location, const Uniform<math::Matrix2f>& uniform) const override
    {
        glUniformMatrix2fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix3f>& uniform) const override
    {
        glUniformMatrix3fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix4f>& uniform) const override
    {
        glUniformMatrix4fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix2x3f>& uniform) const override
    {
        glUniformMatrix2x3fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix2x4f>& uniform) const override
    {
        glUniformMatrix2x4fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix3x2f>& uniform) const override
    {
        glUniformMatrix3x2fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix3x4f>& uniform) const override
    {
        glUniformMatrix3x4fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix4x2f>& uniform) const override
    {
        glUniformMatrix4x2fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix4x3f>& uniform) const override
    {
        glUniformMatrix4x3fv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix2d>& uniform) const override
    {
        glUniformMatrix2dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix3d>& uniform) const override
    {
        glUniformMatrix3dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix4d>& uniform) const override
    {
        glUniformMatrix4dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix2x3d>& uniform) const override
    {
        glUniformMatrix2x3dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix2x4d>& uniform) const override
    {
        glUniformMatrix2x4dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix3x2d>& uniform) const override
    {
        glUniformMatrix3x2dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix3x4d>& uniform) const override
    {
        glUniformMatrix3x4dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix4x2d>& uniform) const override
    {
        glUniformMatrix4x2dv(location, 1, false, uniform.value().data());
    }

    void set_uniform(int location, const Uniform<math::Matrix4x3d>& uniform) const override
    {
        glUniformMatrix4x3dv(location, 1, false, uniform.value().data());
    }
};

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

    m_uniforms.clear();
    m_textures.clear();
}

bool OpenglShader::load(const Shader& shader)
{
    m_vertex_shader   = create_shader(GL_VERTEX_SHADER, shader.vertex_source());
    m_fragment_shader = create_shader(GL_FRAGMENT_SHADER, shader.fragment_source());
    m_shader_program  = create_shader_program(m_vertex_shader, m_fragment_shader);

    m_uniforms = get_active_uniforms(m_shader_program, uniform_types);
    m_textures = get_active_uniforms(m_shader_program, texture_types);

    return m_shader_program != 0;
}

void OpenglShader::use() const
{
    glUseProgram(m_shader_program);
}

void OpenglShader::set_uniforms(const Renderer::Command& command) const
{
    UniformSetterImpl setter;

    for (const auto& uniform : command.global_uniforms()) {
        if (m_uniforms.count(uniform.first)) {
            uniform.second->set(m_uniforms.at(uniform.first), setter);
        }
    }

    for (const auto& uniform : command.uniforms()) {
        if (m_uniforms.count(uniform->name())) {
            uniform->set(m_uniforms.at(uniform->name()), setter);
        }
    }
}

void OpenglShader::set_texture(const std::string& name, std::size_t index) const
{
    UniformSetterImpl setter;

    if (m_textures.count(name)) {
        glUniform1ui(m_textures.at(name), static_cast<GLuint>(index));
    }
}

} // namespace framework::graphics
