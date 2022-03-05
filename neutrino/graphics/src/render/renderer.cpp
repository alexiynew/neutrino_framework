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
    if (!context.valid()) {
        throw std::runtime_error("Context is not valid.");
    }
    context.make_current();

    switch (context.api_type()) {
        case system::Context::Api::opengl: return std::make_unique<OpenglRenderer>(context);
    }

    throw std::runtime_error("Unsupported graphic api.");
}

} // namespace

namespace framework::graphics
{

Renderer::Command::Command(InstanceId mesh,
                           InstanceId shader,
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

InstanceId Renderer::Command::mesh() const
{
    return m_mesh;
}

InstanceId Renderer::Command::shader() const
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

Renderer::Renderer(system::Window& window)
    : m_impl(create_impl(window.context()))
    , m_window(std::ref(window))
{
    m_on_resize_slot_id = m_window.get().on_resize.connect(
    [this](const system::Window&, Size size) { m_impl->set_viewport(size); });
}

Renderer::Renderer(Renderer&& other) noexcept
    : m_impl(std::move(other.m_impl))
    , m_window(std::move(other.m_window))
    , m_on_resize_slot_id(std::move(other.m_on_resize_slot_id))
    , m_render_commands(std::move(other.m_render_commands))
    , m_global_uniforms(std::move(other.m_global_uniforms))
{}

Renderer& Renderer::operator=(Renderer&& other) noexcept = default;

Renderer::~Renderer() = default;

void Renderer::set_clear_color(const Color& color)
{
    m_window.get().context().make_current();
    m_impl->set_clear_color(color);
}

void Renderer::enable_vertical_sync(bool)
{
    throw std::runtime_error("Renderer::enable_vertical_sync not implemented");
}

void Renderer::set_polygon_mode(PolygonMode mode)
{
    m_impl->set_polygon_mode(mode);
}

bool Renderer::load(const Font& font)
{
    return load(font.mesh());
}

bool Renderer::load(const Mesh& mesh)
{
    m_window.get().context().make_current();
    return m_impl->load(mesh);
}

bool Renderer::load(const Shader& shader)
{
    m_window.get().context().make_current();
    return m_impl->load(shader);
}

bool Renderer::load(const Texture& texture)
{
    m_window.get().context().make_current();
    return m_impl->load(texture);
}

void Renderer::render(const Mesh& mesh, const Shader& shader)
{
    render(mesh, shader, {});
}

void Renderer::render(const Mesh& mesh, const Shader& shader, const UniformsList& uniforms)
{
    m_render_commands.push_back(Command(mesh.instance_id(), shader.instance_id(), m_global_uniforms, uniforms));
}

void Renderer::display()
{
    m_window.get().context().make_current();

    start_frame();

    for (const auto& command : m_render_commands) {
        m_impl->render(command);
    }

    end_frame();

    m_window.get().context().swap_buffers();
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
