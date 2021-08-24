/// @file
/// @brief OpenGL shader.
/// @author Fedorov Alexey
/// @date 03.04.2020

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

constexpr std::array<GLenum, 1> texture_types = {GL_SAMPLER_2D};

std::string shader_type_string(int shader_type)
{
    switch (shader_type) {
        case GL_VERTEX_SHADER: return "GL_VERTEX_SHADER";
        case GL_FRAGMENT_SHADER: return "GL_FRAGMENT_SHADER";
    }

    return "UNKNOWN_SHADER";
}

std::string shader_info_log(std::uint32_t shader_id)
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

    std::uint32_t shader_id = glCreateShader(static_cast<GLenum>(shader_type));

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

        const int location            = glGetUniformLocation(shader_program, name_buffer);
        res[std::string(name_buffer)] = location;
    }

    return res;
}

class UniformSetter
{
public:
    explicit UniformSetter(int location)
        : m_location(location)
    {}

    void operator()(float value) const
    {
        glUniform1f(m_location, value);
    }

    void operator()(const math::Vector2f& value) const
    {
        glUniform2fv(m_location, 1, value.data());
    }

    void operator()(const math::Vector3f& value) const
    {
        glUniform3fv(m_location, 1, value.data());
    }

    void operator()(const math::Vector4f& value) const
    {
        glUniform4fv(m_location, 1, value.data());
    }

    void operator()(double value) const
    {
        glUniform1d(m_location, value);
    }

    void operator()(const math::Vector2d& value) const
    {
        glUniform2dv(m_location, 1, value.data());
    }

    void operator()(const math::Vector3d& value) const
    {
        glUniform3dv(m_location, 1, value.data());
    }

    void operator()(const math::Vector4d& value) const
    {
        glUniform4dv(m_location, 1, value.data());
    }

    void operator()(int value) const
    {
        glUniform1i(m_location, value);
    }

    void operator()(const math::Vector2i& value) const
    {
        glUniform2iv(m_location, 1, value.data());
    }

    void operator()(const math::Vector3i& value) const
    {
        glUniform3iv(m_location, 1, value.data());
    }

    void operator()(const math::Vector4i& value) const
    {
        glUniform4iv(m_location, 1, value.data());
    }

    void operator()(unsigned int value) const
    {
        glUniform1ui(m_location, value);
    }

    void operator()(const math::Vector2u& value) const
    {
        glUniform2uiv(m_location, 1, value.data());
    }

    void operator()(const math::Vector3u& value) const
    {
        glUniform3uiv(m_location, 1, value.data());
    }

    void operator()(const math::Vector4u& value) const
    {
        glUniform4uiv(m_location, 1, value.data());
    }

    void operator()(bool value) const
    {
        glUniform1i(m_location, value);
    }

    void operator()(const math::Vector2b& value) const
    {
        math::Vector2i tmp(value);
        glUniform2iv(m_location, 1, tmp.data());
    }

    void operator()(const math::Vector3b& value) const
    {
        math::Vector3i tmp(value);
        glUniform3iv(m_location, 1, tmp.data());
    }

    void operator()(const math::Vector4b& value) const
    {
        math::Vector4i tmp(value);
        glUniform4iv(m_location, 1, tmp.data());
    }

    void operator()(const math::Matrix2f& value) const
    {
        glUniformMatrix2fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix3f& value) const
    {
        glUniformMatrix3fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix4f& value) const
    {
        glUniformMatrix4fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix2x3f& value) const
    {
        glUniformMatrix2x3fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix2x4f& value) const
    {
        glUniformMatrix2x4fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix3x2f& value) const
    {
        glUniformMatrix3x2fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix3x4f& value) const
    {
        glUniformMatrix3x4fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix4x2f& value) const
    {
        glUniformMatrix4x2fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix4x3f& value) const
    {
        glUniformMatrix4x3fv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix2d& value) const
    {
        glUniformMatrix2dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix3d& value) const
    {
        glUniformMatrix3dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix4d& value) const
    {
        glUniformMatrix4dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix2x3d& value) const
    {
        glUniformMatrix2x3dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix2x4d& value) const
    {
        glUniformMatrix2x4dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix3x2d& value) const
    {
        glUniformMatrix3x2dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix3x4d& value) const
    {
        glUniformMatrix3x4dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix4x2d& value) const
    {
        glUniformMatrix4x2dv(m_location, 1, false, value.data());
    }

    void operator()(const math::Matrix4x3d& value) const
    {
        glUniformMatrix4x3dv(m_location, 1, false, value.data());
    }

    void operator()(const TextureBinding&) const
    {}

private:
    int m_location = 0;
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

int OpenglShader::get_attribute_location(const std::string& name) const
{
    return glGetAttribLocation(m_shader_program, name.c_str());
}

void OpenglShader::use() const
{
    glUseProgram(m_shader_program);
}

void OpenglShader::set_uniforms(const Renderer::Command& command) const
{
    for (const auto& uniform : command.global_uniforms()) {
        if (m_uniforms.count(uniform.first)) {
            std::visit(UniformSetter(m_uniforms.at(uniform.first)), uniform.second.value());
        }
    }

    for (const auto& uniform : command.uniforms()) {
        if (m_uniforms.count(uniform.name())) {
            std::visit(UniformSetter(m_uniforms.at(uniform.name())), uniform.value());
        }
    }
}

void OpenglShader::set_texture(const std::string& name, std::size_t index) const
{
    if (m_textures.count(name)) {
        glUniform1i(m_textures.at(name), static_cast<GLint>(index));
    }
}

} // namespace framework::graphics
