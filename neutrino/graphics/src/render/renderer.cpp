#include <cassert>
#include <stdexcept>

#include <graphics/color.hpp>
#include <graphics/font.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>

#include <graphics/src/render/opengl/opengl_renderer.hpp>
#include <graphics/src/render/render_command.hpp>
#include <graphics/src/render/renderer_impl.hpp>

using namespace neutrino;
using namespace neutrino::graphics;

namespace
{
std::unique_ptr<RendererImpl> create_impl(system::Context& context)
{
    if (!context.is_valid()) {
        throw std::runtime_error("Context is not valid.");
    }
    context.make_current();

    switch (context.api_type()) {
        case system::Context::Api::opengl: return std::make_unique<OpenglRenderer>();
    }

    throw std::runtime_error("Unsupported graphic api.");
}

} // namespace

namespace neutrino::graphics
{

Renderer::Renderer(system::Context& context)
    : m_impl(create_impl(context))
    , m_context(std::ref(context))
{}

Renderer::Renderer(Renderer&& other) noexcept = default;

Renderer& Renderer::operator=(Renderer&& other) noexcept = default;

Renderer::~Renderer() = default;

void Renderer::set_clear_color(const Color& color)
{
    m_context.get().make_current();
    m_impl->set_clear_color(color);
}

void Renderer::set_viewport(Size size)
{
    m_context.get().make_current();
    m_impl->set_viewport(size);
}

void Renderer::set_polygon_mode(PolygonMode mode)
{
    m_impl->set_polygon_mode(mode);
}

bool Renderer::load(ResourceId res_id, const Mesh& mesh)
{
    if (mesh.submeshes().empty()) {
        // Can't load mesh without sub meshes.
        return false;
    }

    m_context.get().make_current();
    return m_impl->load(res_id, mesh);
}

bool Renderer::load(ResourceId res_id, const Shader& shader)
{
    m_context.get().make_current();
    return m_impl->load(res_id, shader);
}

bool Renderer::load(ResourceId res_id, const Texture& texture)
{
    m_context.get().make_current();
    return m_impl->load(res_id, texture);
}

void Renderer::render(const ResourceId& mesh_id, const ResourceId& shader_id)
{
    render(mesh_id, shader_id, 1, {});
}

void Renderer::render(const ResourceId& mesh_id, const ResourceId& shader_id, const UniformsList& uniforms)
{
    m_render_commands.push_back(RenderCommand(mesh_id, shader_id, 1, m_global_uniforms, uniforms));
}

void Renderer::render(const ResourceId& mesh_id,
                      const ResourceId& shader_id,
                      std::size_t count,
                      const UniformsList& uniforms)
{
    m_render_commands.push_back(RenderCommand(mesh_id, shader_id, count, m_global_uniforms, uniforms));
}

void Renderer::display()
{
    m_context.get().make_current();

    m_impl->start_frame();

    for (const auto& command : m_render_commands) {
        m_impl->render(command);
    }

    m_render_commands.clear();
    m_impl->end_frame();

    m_context.get().swap_buffers();
}

} // namespace neutrino::graphics
