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

#include <algorithm>
#include <array>
#include <functional>
#include <map>
#include <numeric>

#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>
#include <graphics/uniform.hpp>
#include <log/log.hpp>

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_logger.hpp>
#include <graphics/src/render/opengl/opengl_mesh.hpp>
#include <graphics/src/render/opengl/opengl_renderer.hpp>
#include <graphics/src/render/opengl/opengl_shader.hpp>
#include <graphics/src/render/opengl/opengl_texture.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
const std::string tag = "OpenGL";

int get_int(int id)
{
    int value;
    glGetIntegerv(id, &value);
    return value;
}

std::string get_string(int id)
{
    const char* str = reinterpret_cast<const char*>(glGetString(id));
    return str ? std::string(str) : std::string();
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
OpenglRenderer::OpenglRenderer(const system::Context& context)
{
    init_opengl([&context](const char* function_name) { return context.get_function(function_name); });
    get_info();
    check_supported();

    init();
    LOG_OPENGL_ERRORS();
}

OpenglRenderer::~OpenglRenderer() = default;

void OpenglRenderer::init()
{
    glClearDepth(1.0);

    glEnable(GL_DEPTH_TEST);

    glFrontFace(GL_CCW);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glViewport(0, 0, 640, 480);
}

void OpenglRenderer::get_info()
{
    m_vendor               = get_string(GL_VENDOR);
    m_rendererer           = get_string(GL_RENDERER);
    m_gl_version           = get_string(GL_VERSION);
    m_shading_lang_version = get_string(GL_SHADING_LANGUAGE_VERSION);

    m_max_texture_units = static_cast<std::uint32_t>(get_int(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS));
}

void OpenglRenderer::set_clear_color(const Color& color)
{
    Colorf c = static_cast<Colorf>(color);
    glClearColor(c.r, c.g, c.b, c.a);
    LOG_OPENGL_ERRORS();
}

void OpenglRenderer::set_viewport(Size size)
{
    glViewport(0, 0, size.width, size.height);
}

bool OpenglRenderer::load(const Mesh& mesh)
{
    if (m_meshes.count(mesh.instance_id())) {
        m_meshes.at(mesh.instance_id()).clear();
    } else {
        m_meshes.try_emplace(mesh.instance_id());
    }

    const bool loaded = m_meshes.at(mesh.instance_id()).load(mesh);
    if (!loaded) {
        m_meshes.erase(mesh.instance_id());
        log::error(tag) << "Failed ot load Mesh: " << mesh.instance_id();
    }

    LOG_OPENGL_ERRORS();
    return loaded;
}

bool OpenglRenderer::load(const Shader& shader)
{
    if (m_shaders.count(shader.instance_id())) {
        m_shaders.at(shader.instance_id()).clear();
    } else {
        m_shaders.try_emplace(shader.instance_id());
    }

    const bool loaded = m_shaders.at(shader.instance_id()).load(shader);
    if (!loaded) {
        m_shaders.erase(shader.instance_id());
        log::error(tag) << "Failed ot load Shader: " << shader.instance_id();
    }

    LOG_OPENGL_ERRORS();
    return loaded;
}

bool OpenglRenderer::load(const Texture& texture)
{
    if (m_textures.count(texture.instance_id())) {
        m_textures.at(texture.instance_id()).clear();
    } else {
        m_textures.try_emplace(texture.instance_id());
    }

    OpenglTexture& opengl_texture = m_textures.at(texture.instance_id());

    const bool loaded = opengl_texture.load(texture);
    if (!loaded) {
        m_textures.erase(texture.instance_id());
        log::error(tag) << "Failed ot load Texture: " << texture.instance_id();
    }

    LOG_OPENGL_ERRORS();
    return loaded;
}

void OpenglRenderer::start_frame()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenglRenderer::render(const Renderer::Command& command)
{
    if (m_meshes.count(command.mesh()) == 0) {
        return;
    }

    if (m_shaders.count(command.shader()) == 0) {
        return;
    }

    const OpenglMesh& mesh     = m_meshes.at(command.mesh());
    const OpenglShader& shader = m_shaders.at(command.shader());

    shader.use();
    shader.set_uniforms(command);
    bind_textures(shader, command);

    mesh.draw();

    LOG_OPENGL_ERRORS();
}

void OpenglRenderer::end_frame()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}

void OpenglRenderer::bind_textures(const OpenglShader& shader, const Renderer::Command& command) const
{
    std::uint32_t texture_unit = 0;

    for (const auto& uniform : command.uniforms()) {
        if (std::holds_alternative<TextureBinding>(uniform.value())) {
            const TextureBinding& binding = std::get<TextureBinding>(uniform.value());
            if (m_textures.count(binding.texture()) != 0) {

                if (texture_unit >= m_max_texture_units) {
                    log::error(tag) << "To many texture bindings, max is: " << m_max_texture_units;
                    return;
                }

                const OpenglTexture& texture = m_textures.at(binding.texture());

                texture.bind(texture_unit);
                shader.set_texture(uniform.name(), texture_unit);
                texture_unit++;
            }
        }
    }
}

} // namespace framework::graphics
