#include <graphics/src/render/render_command.hpp>

namespace neutrino::graphics
{

RenderCommand::RenderCommand(ResourceId mesh,
                             ResourceId shader,
                             std::size_t count,
                             const UniformsMap& global_uniforms,
                             const UniformsList& uniforms)
    : m_mesh(mesh)
    , m_shader(shader)
    , m_instances_count(count)
    , m_global_uniforms(std::cref(global_uniforms))
    , m_uniforms(uniforms)
{}

ResourceId RenderCommand::mesh() const
{
    return m_mesh;
}

ResourceId RenderCommand::shader() const
{
    return m_shader;
}

std::size_t RenderCommand::instances() const
{
    return m_instances_count;
}

const UniformsMap& RenderCommand::global_uniforms() const
{
    return m_global_uniforms.get();
}

const UniformsList& RenderCommand::uniforms() const
{
    return m_uniforms;
}

} // namespace neutrino::graphics
