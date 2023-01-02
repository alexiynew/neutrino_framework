#ifndef GRAPHICS_SRC_RENDER_RENDERER_IMPL_HPP
#define GRAPHICS_SRC_RENDER_RENDERER_IMPL_HPP

#include <vector>

#include <graphics/color.hpp>
#include <graphics/renderer.hpp>
#include <math/math.hpp>

namespace neutrino::graphics
{
class Mesh;
class Shader;
class Texture;
class RenderCommand;

class RendererImpl
{
public:
    using VertexData  = std::vector<math::Vector4f>;
    using IndicesData = std::vector<int>;

    virtual ~RendererImpl() = default;

    virtual void set_clear_color(const Color& color)          = 0;
    virtual void set_polygon_mode(Renderer::PolygonMode mode) = 0;
    virtual void set_viewport(Size size)                      = 0;

    virtual bool load(ResourceId res_id, const Mesh& mesh)       = 0;
    virtual bool load(ResourceId res_id, const Shader& shader)   = 0;
    virtual bool load(ResourceId res_id, const Texture& texture) = 0;

    virtual void start_frame()                        = 0;
    virtual void render(const RenderCommand& command) = 0;
    virtual void end_frame()                          = 0;
};

} // namespace neutrino::graphics

#endif
