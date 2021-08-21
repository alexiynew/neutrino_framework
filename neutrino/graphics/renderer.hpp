////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Renderer.
/// @author Fedorov Alexey
/// @date 29.03.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_GRAPHICS_RENDERER_HPP
#define FRAMEWORK_GRAPHICS_RENDERER_HPP

#include <memory>
#include <unordered_map>

#include <graphics/color.hpp>
#include <graphics/uniform.hpp>
#include <math/math.hpp>
#include <system/window.hpp>

namespace framework::graphics
{
class Mesh;
class RendererImpl;
class Shader;
class Texture;
struct Uniforms;

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Renderer
///
/// Provides an interface to display 3d objects on the screen.
/// Renderer attaches to the window. Several renderers can be attached to
/// one window, in that case, they all share the same context.
///
/// Meshes, Shaders, and Textures need to be loaded in renderer before usage.
/// Projection and view matrices saved for every render call, so the different
/// objects can be rendered with different transformations.
////////////////////////////////////////////////////////////////////////////////
class Renderer
{
public:
    using UniformsList = std::vector<Uniform>;
    using UniformsMap  = std::unordered_map<std::string, Uniform>;

    class Command
    {
    public:
        Command(InstanceId mesh, InstanceId shader, const UniformsMap& global_uniforms, const UniformsList& m_uniforms);

        Command(const Command& other) = delete;
        Command& operator=(const Command& other) = delete;

        Command(Command&& other);
        Command& operator=(Command&& other);

        InstanceId mesh() const;
        InstanceId shader() const;
        const UniformsMap& global_uniforms() const;
        const UniformsList& uniforms() const;

    private:
        InstanceId m_mesh;
        InstanceId m_shader;
        std::reference_wrapper<const UniformsMap> m_global_uniforms;
        UniformsList m_uniforms;
    };

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates Renderer and initialize graphic context for the window.
    ///
    /// @param window Window for rendering.
    ////////////////////////////////////////////////////////////////////////////
    explicit Renderer(system::Window& window);

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Move Renderer.
    ///
    /// @param other Renderer to move from.
    ////////////////////////////////////////////////////////////////////////////
    Renderer(Renderer&& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Move Renderer.
    ///
    /// @param other Renderer to move from.
    ////////////////////////////////////////////////////////////////////////////
    Renderer& operator=(Renderer&& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor.
    ////////////////////////////////////////////////////////////////////////////
    ~Renderer();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set color to paint window before every frame.
    ///
    /// @param color Clear Color.
    ////////////////////////////////////////////////////////////////////////////
    void set_clear_color(const Color& color);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Turn on or off the vertical sync.
    ///
    /// @param enable On or off vertical sync.
    ////////////////////////////////////////////////////////////////////////////
    void enable_vertical_sync(bool enable);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Loads Mesh to renderer.
    ///
    /// @param mesh Mesh to load.
    ///
    /// @return `true` if loading successful
    ////////////////////////////////////////////////////////////////////////////
    bool load(const Mesh& mesh);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Loads Shader to renderer.
    ///
    /// @param shader Shader to load.
    ///
    /// @return `true` if loading successful
    ////////////////////////////////////////////////////////////////////////////
    bool load(const Shader& shader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Loads Texture to renderer.
    ///
    /// @param texture Texture to load.
    ///
    /// @return `true` if loading successful
    ////////////////////////////////////////////////////////////////////////////
    bool load(const Texture& texture);

    template <typename T>
    void set_uniform(const std::string& name, const T& value);

    template <typename T>
    void set_uniform(const std::string& name, T&& value);

    void render(const Mesh& mesh, const Shader& shader);
    void render(const Mesh& mesh, const Shader& shader, const UniformsList& uniforms);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Display on a screen all that been rendered so far.
    ////////////////////////////////////////////////////////////////////////////
    void display();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get video card venor name.
    ///
    /// @return Vendor name.
    ////////////////////////////////////////////////////////////////////////////
    std::string vendor_name() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get video card device name.
    ///
    /// @return Device name.
    ////////////////////////////////////////////////////////////////////////////
    std::string device_name() const;

private:
    void start_frame();
    void end_frame();

    std::unique_ptr<RendererImpl> m_impl;
    std::reference_wrapper<system::Window> m_window;
    Signal<const system::Window&, Size>::SlotId m_on_resize_slot_id;

    std::vector<Command> m_render_commands;
    UniformsMap m_global_uniforms;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

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

} // namespace framework::graphics

#endif
