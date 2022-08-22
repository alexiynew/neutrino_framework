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
    glGetIntegerv(static_cast<GLenum>(id), &value);
    return value;
}

std::string get_string(int id)
{
    const char* str = reinterpret_cast<const char*>(glGetString(static_cast<GLenum>(id)));
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

void OpenglRenderer::set_polygon_mode(Renderer::PolygonMode mode)
{
    m_polygon_mode = mode;
    switch (m_polygon_mode) {
        case Renderer::PolygonMode::fill: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
        case Renderer::PolygonMode::line: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
        case Renderer::PolygonMode::point: glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); break;
    }
    LOG_OPENGL_ERRORS();
}

void OpenglRenderer::set_viewport(Size size)
{
    glViewport(0, 0, size.width, size.height);
}

bool OpenglRenderer::load(ResourceId res_id, const Mesh& mesh)
{
    const bool loaded = m_meshes[res_id].load(mesh);
    if (!loaded) {
        m_meshes.erase(res_id);
        log::error(tag) << "Failed ot load Mesh: " << res_id;
    }

    LOG_OPENGL_ERRORS();
    return loaded;
}

bool OpenglRenderer::load(ResourceId res_id, const Shader& shader)
{
    const bool loaded = m_shaders[res_id].load(shader);
    if (!loaded) {
        m_shaders.erase(res_id);
        log::error(tag) << "Failed ot load Shader: " << res_id;
    }

    LOG_OPENGL_ERRORS();
    return loaded;
}

bool OpenglRenderer::load(ResourceId res_id, const Texture& texture)
{
    const bool loaded = m_textures[res_id].load(texture);
    if (!loaded) {
        m_textures.erase(res_id);
        log::error(tag) << "Failed ot load Texture: " << res_id;
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
        log::debug(tag) << "OpenglRenderer::render: Trying to render mesh that is not loaded. Mesh id: "
                        << command.mesh();
        return;
    }

    if (m_shaders.count(command.shader()) == 0) {
        log::debug(tag) << "OpenglRenderer::render: Trying to use shder that is not loaded. Shader id: "
                        << command.mesh();
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
        if (std::holds_alternative<ResourceId>(uniform.value())) {
            if (!shader.is_texture(uniform.name())) {
                continue;
            }

            const auto res_id      = std::get<ResourceId>(uniform.value());
            const auto& texture_it = m_textures.find(res_id);
            if (texture_it == m_textures.end()) {
                continue;
            }

            if (texture_unit >= m_max_texture_units) {
                log::error(tag) << "To many texture bindings, max is: " << m_max_texture_units;
                return;
            }

            texture_it->second.bind(texture_unit);
            shader.set_texture(uniform.name(), texture_unit);
            texture_unit++;
        }
    }
}

} // namespace framework::graphics
