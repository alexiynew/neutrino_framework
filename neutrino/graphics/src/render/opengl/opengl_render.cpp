/// @file
/// @brief OpenGL render implementation.
/// @author Fedorov Alexey
/// @date 29.03.2020

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

#include <array>
#include <map>

#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <log/log.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_mesh.hpp>
#include <graphics/src/render/opengl/opengl_render.hpp>
#include <graphics/src/render/opengl/opengl_shader.hpp>
#include <graphics/src/render/render_command.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
const std::string tag = "OpenGL";

void log_errors();

float map_to_float(Color::ValueType value)
{
    return static_cast<float>(value) / 255.0f;
}

void log_errors()
{
    struct ErrorDescription
    {
        std::string name;
        std::string description;
    };

    const std::map<GLenum, ErrorDescription> error_descriptions = {
    {GL_INVALID_ENUM,
     {"GL_INVALID_ENUM",
      "An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no "
      "other side effect than to set the error flag."}},
    {GL_INVALID_VALUE,
     {"GL_INVALID_VALUE",
      "A numeric argument is out of range. The offending command is ignored and has no other side effect than to set "
      "the error flag."}},
    {GL_INVALID_OPERATION,
     {"GL_INVALID_OPERATION",
      "The specified operation is not allowed in the current state. The offending command is ignored and has no other "
      "side effect than to set the error flag."}},
    {GL_INVALID_FRAMEBUFFER_OPERATION,
     {"GL_INVALID_FRAMEBUFFER_OPERATION",
      "The framebuffer object is not complete. The offending command is ignored and has no other side effect than to "
      "set the error flag."}},
    {GL_OUT_OF_MEMORY,
     {"GL_OUT_OF_MEMORY",
      "There is not enough memory left to execute the command. The state of the GL is undefined, except for the state "
      "of the error flags, after this error is recorded."}},
    };

    for (GLenum error = glGetError(); error != GL_NO_ERROR; error = glGetError()) {
        if (error_descriptions.count(error)) {
            const auto& desc = error_descriptions.at(error);
            log::error(tag) << desc.name << " " << desc.description;
        } else {
            log::error(tag) << "Unknown error: " << error;
        }
    }
}

std::string get_string(int id)
{
    const char* str = reinterpret_cast<const char*>(glGetString(id));
    return str ? std::string(str) : std::string();
}

void get_info()
{
    log::info(tag) << "Vendor: " << get_string(GL_VENDOR);
    log::info(tag) << "Renderer: " << get_string(GL_RENDERER);
    log::info(tag) << "Version: " << get_string(GL_VERSION);
    log::info(tag) << "Shading Lang Version: " << get_string(GL_SHADING_LANGUAGE_VERSION);
    log::info(tag) << "Extensions: " << get_string(GL_EXTENSIONS);
}

void check_supported()
{
    const std::array<Feature, 12> features = {
    Feature::GL_VERSION_1_0,
    Feature::GL_VERSION_1_1,
    Feature::GL_VERSION_1_2,
    Feature::GL_VERSION_1_3,
    Feature::GL_VERSION_1_4,
    Feature::GL_VERSION_1_5,
    Feature::GL_VERSION_2_0,
    Feature::GL_VERSION_2_1,
    Feature::GL_VERSION_3_0,
    };

    for (const auto& f : features) {
        if (!is_supported(f)) {
            throw std::runtime_error(std::string("Feature ") + std::to_string(static_cast<int>(f)) + " not supported.");
        }
    }
}

} // namespace

namespace framework::graphics
{
OpenglRender::OpenglRender(system::Context& context)
{
    context.make_current();
    init_opengl([&context](const char* function_name) { return context.get_function(function_name); });
    get_info();
    check_supported();
    log_errors();
}

OpenglRender::~OpenglRender() = default;

void OpenglRender::set_clear_color(Color color)
{
    glClearColor(map_to_float(color.r), map_to_float(color.g), map_to_float(color.b), map_to_float(color.a));
}

bool OpenglRender::load(const Mesh& mesh)
{
    if (m_meshes.count(mesh.instance_id())) {
        // TODO: reload mesh
    } else {
        const auto& [_, inserted] = m_meshes.emplace(mesh.instance_id(), mesh);
        return inserted;
    }

    return false;
}

bool OpenglRender::load(const Shader& shader)
{
    if (m_shaders.count(shader.instance_id())) {
        // TODO: realod shader
    } else {
        const auto& [_, inserted] = m_shaders.emplace(shader.instance_id(), shader);
        return inserted;
    }

    return false;
}

void OpenglRender::start_frame()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenglRender::perform(const RenderCommand& command)
{
    if (m_meshes.count(command.mesh_id()) == 0) {
        return;
    }

    if (m_shaders.count(command.shader_id()) == 0) {
        return;
    }

    const OpenglMesh& mesh     = m_meshes.at(command.mesh_id());
    const OpenglShader& shader = m_shaders.at(command.shader_id());

    shader.use();
    mesh.draw();

    set_uniforms();

    log_errors();
}

void OpenglRender::end_frame()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}

void OpenglRender::set_uniforms() const
{
    // void shader_program::uniform(const std::string& name, int value)
    //{
    //    const int32 uniform_id = glGetUniformLocation(m_program_id, name.c_str());
    //    glUniform1i(uniform_id, value);
    //}
    //
    // void shader_program::uniform(const std::string& name, float value)
    //{
    //    const int32 uniform_id = glGetUniformLocation(m_program_id, name.c_str());
    //    glUniform1f(uniform_id, value);
    //}
    //
    // void shader_program::uniform(const std::string& name, math::matrix4f value, bool transpose)
    //{
    //    const int32 uniform_id = glGetUniformLocation(m_program_id, name.c_str());
    //    glUniformMatrix4fv(uniform_id, 1, transpose, value.data());
    //}
    /*
     // Set the world matrix in the vertex shader.
     location = OpenGL->glGetUniformLocation(m_shaderProgram, "worldMatrix");
     if(location == -1)
     {
         return false;
     }
     OpenGL->glUniformMatrix4fv(location, 1, false, worldMatrix);

     // Set the view matrix in the vertex shader.
     location = OpenGL->glGetUniformLocation(m_shaderProgram, "viewMatrix");
     if(location == -1)
     {
         return false;
     }
     OpenGL->glUniformMatrix4fv(location, 1, false, viewMatrix);

     // Set the projection matrix in the vertex shader.
     location = OpenGL->glGetUniformLocation(m_shaderProgram, "projectionMatrix");
     if(location == -1)
     {
         return false;
     }
     OpenGL->glUniformMatrix4fv(location, 1, false, projectionMatrix);
     //
    */
}

} // namespace framework::graphics
