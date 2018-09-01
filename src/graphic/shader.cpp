/// @file
/// @brief Shader class.
/// @author Fedorov Alexey
/// @date 16.08.2018

#include <common/types.hpp>
#include <graphic/opengl/gl.hpp>
#include <graphic/shader.hpp>
#include <log/log.hpp>

namespace
{
framework::uint32 compile_shader(const std::vector<std::string>& sources, GLenum type)
{
    using namespace framework::graphic::gl;

    framework::uint32 shader = glCreateShader(type);

    std::vector<const char*> pointers;
    pointers.reserve(sources.size());

    for (auto& string : sources) {
        pointers.push_back(string.c_str());
    }

    glShaderSource(shader, static_cast<framework::int32>(sources.size()), pointers.data(), nullptr);

    glCompileShader(shader);

    framework::int32 is_compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);
    if (is_compiled == 0) {
        framework::int32 log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

        std::vector<char> error_log(log_length);
        glGetShaderInfoLog(shader, log_length, &log_length, &error_log[0]);

        framework::log::error("shader") << "Can't compile shader\n" << error_log.data() << std::endl;

        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

} // namespace

namespace framework::graphic
{
shader::shader() = default;

shader::~shader()
{
    clear();
}

void shader::add_vertex_source(std::string source)
{
    m_vertex_sources.push_back(std::move(source));
}

void shader::add_fragment_source(std::string source)
{
    m_fragment_sources.push_back(std::move(source));
}

void shader::bind_attribute(shader::attribute attrib)
{
    m_attributes.push_back(attrib);
}

void shader::compile()
{
    m_vertex_shader   = compile_shader(m_vertex_sources, GL_VERTEX_SHADER);
    m_fragment_shader = compile_shader(m_fragment_sources, GL_FRAGMENT_SHADER);

    if (m_vertex_shader == 0 || m_fragment_shader == 0) {
        clear();
        return;
    }

    m_program = gl::glCreateProgram();

    gl::glAttachShader(m_program, m_vertex_shader);
    gl::glAttachShader(m_program, m_fragment_shader);

    for (auto& [location, name] : m_attributes) {
        gl::glBindAttribLocation(m_program, location, name.c_str());
    }

    gl::glLinkProgram(m_program);

    int32 is_linked = 0;
    gl::glGetProgramiv(m_program, GL_LINK_STATUS, &is_linked);
    if (is_linked == 0) {
        int32 log_length = 0;
        gl::glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &log_length);

        std::vector<char> error_log(log_length);
        gl::glGetProgramInfoLog(m_program, log_length, &log_length, &error_log[0]);

        log::error("shader") << "Can't compile shader\n" << error_log.data() << std::endl;

        clear();
        return;
    }

    gl::glDetachShader(m_program, m_vertex_shader);
    gl::glDetachShader(m_program, m_fragment_shader);
}

void shader::use()
{
    if (m_program != 0) {
        gl::glUseProgram(m_program);
    }
}

void shader::clear()
{
    gl::glDeleteProgram(m_program);
    gl::glDeleteShader(m_vertex_shader);
    gl::glDeleteShader(m_fragment_shader);

    m_program         = 0;
    m_vertex_shader   = 0;
    m_fragment_shader = 0;
}

} // namespace framework::graphic
