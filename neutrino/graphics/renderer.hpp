////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Renderer.
/// @author Fedorov Alexey
/// @date 29.03.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <graphics/color.hpp>
#include <math/math.hpp>
#include <system/window.hpp>

namespace framework::graphics
{
class Mesh;
class RenderCommand;
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
    using TexturesList = std::vector<std::reference_wrapper<Texture>>;
    using MatrixCache  = std::vector<math::Matrix4f>;

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
    /// @brief Set projection matrix
    ///
    /// @param projection Projection matrix.
    ////////////////////////////////////////////////////////////////////////////
    void set_projection(const math::Matrix4f& projection);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set view transform matrix
    ///
    /// @param view View matrix.
    ////////////////////////////////////////////////////////////////////////////
    void set_view(const math::Matrix4f& view);

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

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Loads bunch of textures to renderer.
    ///
    /// @param textures Textures to load.
    ///
    /// @return `true` if loading successful
    ////////////////////////////////////////////////////////////////////////////
    bool load(const TexturesList& textures);

    void render(const Mesh& mesh, const Shader& shader);
    void render(const Mesh& mesh, const Shader& shader, const TexturesList& textures);
    void render(const Mesh& mesh, const Shader& shader, const math::Matrix4f& model_transform);
    void render(const Mesh& mesh,
                const Shader& shader,
                const TexturesList& textures,
                const math::Matrix4f& model_transform);

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

    std::vector<RenderCommand> m_render_commands;
    MatrixCache m_projection;
    MatrixCache m_view;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////
} // namespace framework::graphics

#endif
