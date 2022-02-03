#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_RENDERER_IMPL_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_RENDERER_IMPL_HPP

#include <vector>

#include <graphics/color.hpp>
#include <graphics/renderer.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
class Mesh;
class Shader;
class Texture;

class RendererImpl
{
public:
    using VertexData  = std::vector<math::Vector4f>;
    using IndicesData = std::vector<int>;

    virtual ~RendererImpl() = default;

    virtual void set_clear_color(const Color& color) = 0;
    virtual void set_viewport(Size size)             = 0;

    virtual bool load(const Mesh& mesh)       = 0;
    virtual bool load(const Shader& shader)   = 0;
    virtual bool load(const Texture& texture) = 0;

    virtual void start_frame()                            = 0;
    virtual void render(const Renderer::Command& command) = 0;
    virtual void end_frame()                              = 0;
};

} // namespace framework::graphics

#endif
