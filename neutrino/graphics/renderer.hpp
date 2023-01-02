#ifndef GRAPHICS_RENDERER_HPP
#define GRAPHICS_RENDERER_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include <common/global_defines.hpp>
#include <common/size.hpp>
#include <graphics/color.hpp>
#include <graphics/uniform.hpp>
#include <math/math.hpp>
#include <system/context.hpp>

#include <graphics/inc/types.hpp>

namespace neutrino::graphics
{
class Font;
class Mesh;
class RenderCommand;
class RendererImpl;
class Shader;
class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Renderer
///
/// Provides an interface to display 3d objects on the screen.
/// Renderer attaches to the window. Several renderers can be attached to
/// one window, in that case, they all share the same context.
/// TODO: Write test on it.
///
/// Meshes, Shaders, and Textures need to be loaded in renderer before usage.
class Renderer
{
public:
    /// @brief Polygon rasterization mode.
    enum class PolygonMode
    {
        point,
        line,
        fill,
    };

    /// @brief Creates Renderer and initialize graphic context.
    ///
    /// @param context Context for rendering.
    LIBRARY_API explicit Renderer(system::Context& context);

    Renderer(const Renderer&) = delete;
    LIBRARY_API Renderer(Renderer&& other) noexcept;

    LIBRARY_API ~Renderer();

    Renderer& operator=(const Renderer&) = delete;

    LIBRARY_API Renderer& operator=(Renderer&& other) noexcept;

    /// @brief Set color to paint window before every frame.
    ///
    /// @param color Clear Color.
    LIBRARY_API void set_clear_color(const Color& color);

    /// @brief Specify size of the viewport.
    ///
    /// @param size Viewport size.
    LIBRARY_API void set_viewport(Size size);

    /// @brief Set current polygon mode.
    ///
    /// @param mode New mode.
    LIBRARY_API void set_polygon_mode(PolygonMode mode);

    /// @brief Loads Mesh to renderer.
    ///
    /// @param res_id Id of mesh.
    /// @param mesh Mesh to load.
    ///
    /// @return `true` if loading successful
    LIBRARY_API bool load(ResourceId res_id, const Mesh& mesh);

    /// @brief Loads Shader to renderer.
    ///
    /// @param res_id Id of shader.
    /// @param shader Shader to load.
    ///
    /// @return `true` if loading successful
    LIBRARY_API bool load(ResourceId res_id, const Shader& shader);

    /// @brief Loads Texture to renderer.
    ///
    /// @param res_id Id of texture.
    /// @param texture Texture to load.
    ///
    /// @return `true` if loading successful
    LIBRARY_API bool load(ResourceId res_id, const Texture& texture);

    /// @brief Assigns a global uniform value for shaders.
    ///
    /// Useful when there is a need to pass the same uniform for all shaders.
    ///
    /// @param name Uniform name.
    /// @param value Uniform value.
    template <typename T>
    void set_uniform(const std::string& name, const T& value);

    /// @brief Assigns a global uniform value for shaders.
    ///
    /// Useful when there is a need to pass the same uniform for all shaders.
    ///
    /// @param name Uniform name.
    /// @param value Uniform value.
    template <typename T>
    void set_uniform(const std::string& name, T&& value);

    /// @brief Renders a mesh with a shader.
    ///
    /// Only global uniforms would pass to the shader.
    ///
    /// @param mesh_id Id of mesh to render.
    /// @param shader_id Id of shader ot use.
    LIBRARY_API void render(const ResourceId& mesh_id, const ResourceId& shader);

    /// @brief Renders a mesh with a shader and unforms.
    ///
    /// Global uniforms would pass to the shader as well.
    /// TODO: Local uniforms must override global ones. Write test on it.
    ///
    /// @param mesh_id id of mesh to render.
    /// @param shader_id Id of shader ot use.
    /// @param uniforms Uniform values to current shader.
    LIBRARY_API void render(const ResourceId& mesh_id, const ResourceId& shader_id, const UniformsList& uniforms);

    /// @brief Renders a number of instances of a mesh with a shader and unforms.
    ///
    /// Global uniforms would pass to the shader as well.
    /// TODO: Local uniforms must override global ones. Write test on it.
    ///
    /// @param mesh_id id of mesh to render.
    /// @param shader_id Id of shader ot use.
    /// @param count Number of instances.
    /// @param uniforms Uniform values to current shader.
    LIBRARY_API void render(const ResourceId& mesh_id,
                            const ResourceId& shader_id,
                            std::size_t count,
                            const UniformsList& uniforms);

    /// @brief Display on a screen all that been rendered so far.
    LIBRARY_API void display();

    /// @brief Get video card venor name.
    ///
    /// @return Vendor name.
    LIBRARY_API std::string vendor_name() const;

    /// @brief Get video card device name.
    ///
    /// @return Device name.
    LIBRARY_API std::string device_name() const;

private:
    std::unique_ptr<RendererImpl> m_impl;
    std::reference_wrapper<system::Context> m_context;

    std::vector<RenderCommand> m_render_commands;
    UniformsMap m_global_uniforms;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
inline void Renderer::set_uniform(const std::string& name, const T& value)
{
    m_global_uniforms[name] = Uniform(name, value);
}

template <typename T>
inline void Renderer::set_uniform(const std::string& name, T&& value)
{
    m_global_uniforms[name] = Uniform(name, std::forward<T>(value));
}

} // namespace neutrino::graphics

#endif
