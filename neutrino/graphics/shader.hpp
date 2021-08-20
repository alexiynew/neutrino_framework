////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Shader.
/// @author Fedorov Alexey
/// @date 12.04.2019
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

#ifndef FRAMEWORK_GRAPHICS_SHADER_HPP
#define FRAMEWORK_GRAPHICS_SHADER_HPP

#include <string>

#include <common/instance_id.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Shader.
///
/// Each Shader consists of two parts: vertex program and fragment program.
///
/// For OpenGL: @n
/// ===========
/// Shader has predefined vertex attribute locations listed below:
///  - position              - 0
///  - normal                - 1
///  - tangent               - 2
///  - color                 - 3
///  - texture coordinate0-7 - 4-11 @n
/// They can be used as follows:
/// @code
/// layout(location = 0) in vec3 vertexPosition;
/// @endcode
///
/// There are also several predefined uniforms passed to each shader:
/// @code
/// uniform mat4 madelMatrix;      - model transformations
/// uniform mat4 viewMatrix;       - view transformation
/// uniform mat4 projectionMatrix; - projection frustim
/// uniform mat3 normalMatrix;     - transpose inverse of 3x3 part
///                                  of (viewMatrix * modelMatrix)
/// @endcode
///
/// @see Mesh, Renderer
////////////////////////////////////////////////////////////////////////////////
class Shader
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates Shader instance.
    ////////////////////////////////////////////////////////////////////////////
    Shader() = default;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    ////////////////////////////////////////////////////////////////////////////
    ~Shader() = default;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Copy Shader.
    ///
    /// Creates new Shader with new InstanceId.
    ///
    /// @param other Shader to copy from.
    ////////////////////////////////////////////////////////////////////////////
    Shader(const Shader& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Copy Shader.
    ///
    /// Creates new Shader with new InstanceId.
    ///
    /// @param other Shader to copy from.
    ///
    /// @return Copyed mesh instance.
    ////////////////////////////////////////////////////////////////////////////
    Shader& operator=(const Shader& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Move Shader.
    ///
    /// @param other Shader to move from.
    ////////////////////////////////////////////////////////////////////////////
    Shader(Shader&& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Move Shader.
    ///
    /// @param other Shader to move from.
    ///
    /// @return Moved mesh instance.
    ////////////////////////////////////////////////////////////////////////////
    Shader& operator=(Shader&& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Load vertex shader source form file.
    ///
    /// @param filename Path to vertex shader source file.
    ///
    /// @return `true` if loadint successful.
    ////////////////////////////////////////////////////////////////////////////
    bool load_vertex_source(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set fragment shader source form file.
    ///
    /// @param filename Path to fragment shader source file.
    ///
    /// @return `true` if loadint successful.
    ////////////////////////////////////////////////////////////////////////////
    bool load_fragment_source(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set vertex shader source.
    ///
    /// @param source Vertex shader source.
    ////////////////////////////////////////////////////////////////////////////
    void set_vertex_source(const std::string& source);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set fragment shader source.
    ///
    /// @param source Fragment shader source.
    ////////////////////////////////////////////////////////////////////////////
    void set_fragment_source(const std::string& source);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Remove all sources from Shader.
    ///
    /// If Shader loaded to Renderer, it's can be freely cleaned.
    ///
    /// @see Renderer::load.
    ////////////////////////////////////////////////////////////////////////////
    void clear();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get Shader instance id. Guaranted to be unique.
    ///
    /// @return Shader instance id.
    ////////////////////////////////////////////////////////////////////////////
    InstanceId instance_id() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get vertex shader source.
    ///
    /// @return Vertex shader source.
    ////////////////////////////////////////////////////////////////////////////
    const std::string& vertex_source() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get fragment shader source.
    ///
    /// @return Fragment shader source.
    ////////////////////////////////////////////////////////////////////////////
    const std::string& fragment_source() const;

private:
    friend void swap(Shader& lhs, Shader& rhs) noexcept;

    InstanceId m_instance_id;

    std::string m_vertex_source;
    std::string m_fragment_source;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Swaps two Shaders.
///
/// @param lhs Shader to swap.
/// @param rhs Shader to swap.
////////////////////////////////////////////////////////////////////////////////
void swap(Shader& lhs, Shader& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////
} // namespace framework::graphics

#endif
