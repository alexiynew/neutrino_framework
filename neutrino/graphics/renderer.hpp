#ifndef GRAPHICS_RENDERER_HPP
#define GRAPHICS_RENDERER_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include <common/size.hpp>
#include <graphics/color.hpp>
#include <graphics/uniform.hpp>
#include <math/math.hpp>
#include <system/context.hpp>

namespace neutrino::graphics
{
class Font;
class Mesh;
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
    using UniformsList = std::vector<Uniform>;
    using UniformsMap  = std::unordered_map<std::string, Uniform>;
    using ResourceId   = std::uint32_t;

    /// @brief Polygon rasterization mode.
    enum class PolygonMode
    {
        point,
        line,
        fill,
    };

    /// @brief Internal representation of render call.
    class Command
    {
    public:
        Command(ResourceId mesh, ResourceId shader, const UniformsMap& global_uniforms, const UniformsList& m_uniforms);
        Command(const Command& other) = delete;
        Command(Command&& other);

        Command& operator=(const Command& other) = delete;

        Command& operator=(Command&& other);

        ResourceId mesh() const;
        ResourceId shader() const;
        const UniformsMap& global_uniforms() const;
        const UniformsList& uniforms() const;

    private:
        ResourceId m_mesh;
        ResourceId m_shader;
        std::reference_wrapper<const UniformsMap> m_global_uniforms;
        UniformsList m_uniforms;
    };

    /// @brief Creates Renderer and initialize graphic context.
    ///
    /// @param context Context for rendering.
    explicit Renderer(system::Context& context);

    Renderer(const Renderer&) = delete;
    Renderer(Renderer&& other) noexcept;

    ~Renderer();

    Renderer& operator=(const Renderer&) = delete;

    Renderer& operator=(Renderer&& other) noexcept;

    /// @brief Set color to paint window before every frame.
    ///
    /// @param color Clear Color.
    void set_clear_color(const Color& color);

    /// @brief Specify size of the viewport.
    ///
    /// @param size Viewport size.
    void set_viewport(Size size);

    /// @brief Set current polygon mode.
    ///
    /// @param mode New mode.
    void set_polygon_mode(PolygonMode mode);

    /// @brief Loads Mesh to renderer.
    ///
    /// @param res_id Id of mesh.
    /// @param mesh Mesh to load.
    ///
    /// @return `true` if loading successful
    bool load(ResourceId res_id, const Mesh& mesh);

    /// @brief Loads Shader to renderer.
    ///
    /// @param res_id Id of shader.
    /// @param shader Shader to load.
    ///
    /// @return `true` if loading successful
    bool load(ResourceId res_id, const Shader& shader);

    /// @brief Loads Texture to renderer.
    ///
    /// @param res_id Id of texture.
    /// @param texture Texture to load.
    ///
    /// @return `true` if loading successful
    bool load(ResourceId res_id, const Texture& texture);

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
    void render(const ResourceId& mesh_id, const ResourceId& shader);

    /// @brief Renders a mesh with a shader and unforms.
    ///
    /// Global uniforms would pass to the shader as well.
    /// TODO: Local uniforms must override global ones. Write test on it.
    ///
    /// @param mesh_id id of mesh to render.
    /// @param shader_id Id of shader ot use.
    /// @param uniforms Uniform values to current shader.
    void render(const ResourceId& mesh_id, const ResourceId& shader_id, const UniformsList& uniforms);

    /// @brief Display on a screen all that been rendered so far.
    void display();

    /// @brief Get video card venor name.
    ///
    /// @return Vendor name.
    std::string vendor_name() const;

    /// @brief Get video card device name.
    ///
    /// @return Device name.
    std::string device_name() const;

private:
    void start_frame();
    void end_frame();

    std::unique_ptr<RendererImpl> m_impl;
    std::reference_wrapper<system::Context> m_context;

    std::vector<Command> m_render_commands;
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
