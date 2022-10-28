#include <cassert>
#include <stdexcept>

#include <graphics/color.hpp>
#include <graphics/font.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>

#include <graphics/src/render/opengl/opengl_renderer.hpp>
#include <graphics/src/render/renderer_impl.hpp>

using namespace framework;
using namespace framework::graphics;

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

namespace framework::graphics
{

Renderer::Command::Command(ResourceId mesh,
                           ResourceId shader,
                           const UniformsMap& global_uniforms,
                           const UniformsList& uniforms)
    : m_mesh(mesh)
    , m_shader(shader)
    , m_global_uniforms(std::cref(global_uniforms))
    , m_uniforms(uniforms)
{}

Renderer::Command::Command(Command&& other)
    : m_mesh(other.m_mesh)
    , m_shader(other.m_shader)
    , m_global_uniforms(std::move(other.m_global_uniforms))
    , m_uniforms(std::move(other.m_uniforms))
{}

Renderer::Command& Renderer::Command::operator=(Command&& other)
{
    using std::swap;

    Command tmp(std::move(other));

    swap(tmp.m_mesh, m_mesh);
    swap(tmp.m_shader, m_shader);
    swap(tmp.m_global_uniforms, m_global_uniforms);
    swap(tmp.m_uniforms, m_uniforms);

    return *this;
}

Renderer::ResourceId Renderer::Command::mesh() const
{
    return m_mesh;
}

Renderer::ResourceId Renderer::Command::shader() const
{
    return m_shader;
}

const Renderer::UniformsMap& Renderer::Command::global_uniforms() const
{
    return m_global_uniforms.get();
}

const Renderer::UniformsList& Renderer::Command::uniforms() const
{
    return m_uniforms;
}

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
    render(mesh_id, shader_id, {});
}

void Renderer::render(const ResourceId& mesh_id, const ResourceId& shader_id, const UniformsList& uniforms)
{
    m_render_commands.push_back(Command(mesh_id, shader_id, m_global_uniforms, uniforms));
}

void Renderer::display()
{
    m_context.get().make_current();

    start_frame();

    for (const auto& command : m_render_commands) {
        m_impl->render(command);
    }

    end_frame();

    m_context.get().swap_buffers();
}

void Renderer::start_frame()
{
    m_impl->start_frame();
}

void Renderer::end_frame()
{
    m_render_commands.clear();

    m_impl->end_frame();
}

} // namespace framework::graphics
