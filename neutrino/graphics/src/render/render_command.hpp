#ifndef GRAPHICS_SRC_RENDER_RENDER_COMMAND_HPP
#define GRAPHICS_SRC_RENDER_RENDER_COMMAND_HPP

#include <graphics/inc/types.hpp>

namespace neutrino::graphics
{

class RenderCommand
{
public:
    RenderCommand(ResourceId mesh,
                  ResourceId shader,
                  std::size_t count,
                  const UniformsMap& global_uniforms,
                  const UniformsList& m_uniforms);

    RenderCommand(const RenderCommand& other) = delete;
    RenderCommand(RenderCommand&& other)      = default;

    RenderCommand& operator=(const RenderCommand& other) = delete;
    RenderCommand& operator=(RenderCommand&& other)      = default;

    ResourceId mesh() const;
    ResourceId shader() const;
    std::size_t instances() const;
    const UniformsMap& global_uniforms() const;
    const UniformsList& uniforms() const;

private:
    ResourceId m_mesh             = 0;
    ResourceId m_shader           = 0;
    std::size_t m_instances_count = 0;
    std::reference_wrapper<const UniformsMap> m_global_uniforms;
    UniformsList m_uniforms;
};

} // namespace neutrino::graphics

#endif