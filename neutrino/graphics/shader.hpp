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

/*
/////////////////////
// INPUT VARIABLES //
/////////////////////
in vec3 inputPosition;
in vec3 inputColor;
This next section in the vertex shader is the output variables that will be sent into the pixel shader. The only output
variable that is defined is the color since we will be sending the color into the pixel shader. Note that the
transformed input vertex position will also be sent into the pixel shader, but it is sent inside a special predefined
variable called gl_Position.

//////////////////////
// OUTPUT VARIABLES //
//////////////////////
out vec3 color;
The next section in the vertex shader is the uniform variables. These are variables that we set once and do not change
for each vertex. For this tutorial we will just set the three important matrices which are world, view, and projection.

///////////////////////
// UNIFORM VARIABLES //
///////////////////////
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
The final section in the vertex shader is the code body. The code starts by multiplying the input vertex by the world,
view, and then projection matrices. This will place the vertex in the correct location for rendering in 3D space
according to our view and then onto the 2D screen. We store the result in the special gl_Position vector which will
automatically get passed into the pixel shader. Also note that I do set the W value of the input position to 1.0 so we
can do proper calculations using the 4x4 matrices. After that we set the output color from this vertex to be a copy of
the input color. This will allow the pixel shader to access the color.

////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
void main(void)
{
    // Calculate the position of the vertex against the world, view, and projection matrices.
    gl_Position = worldMatrix * vec4(inputPosition, 1.0f);
    gl_Position = viewMatrix * gl_Position;
    gl_Position = projectionMatrix * gl_Position;

    // Store the input color for the pixel shader to use.
    color = inputColor;
}


////////////////////////////////////////////////////////////////////////////////
// Filename: color.ps
////////////////////////////////////////////////////////////////////////////////
#version 400


/////////////////////
// INPUT VARIABLES //
/////////////////////
in vec3 color;


//////////////////////
// OUTPUT VARIABLES //
//////////////////////
out vec4 outputColor;


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
void main(void)
{
    outputColor = vec4(color, 1.0f);
}


*/
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
////////////////////////////////////////////////////////////////////////////////
class Shader
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates Shader instance.
    ///
    /// @param vertex_source Vertex shader source.
    /// @param fragment_source Fragment shader source.
    ////////////////////////////////////////////////////////////////////////////
    Shader(const std::string& vertex_source, const std::string& fragment_source);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    ////////////////////////////////////////////////////////////////////////////
    ~Shader();

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
    /// @brief Set vertex shader source.
    ///
    /// @param vertex_source Vertex shader source.
    ////////////////////////////////////////////////////////////////////////////
    void set_vertex_sounrce(const std::string& source);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set fragment shader source.
    ///
    /// @param vertex_source Fragment shader source.
    ////////////////////////////////////////////////////////////////////////////
    void set_fragment_sounrce(const std::string& source);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Remove all sources from Shader.
    ///
    /// If Shader loaded to Render, it's can be freely cleaned.
    ///
    /// @see Render::load.
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

    std::string m_vertex_sounrce;
    std::string m_fragment_sounrce;
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
