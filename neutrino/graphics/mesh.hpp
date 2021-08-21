////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Mesh.
/// @author Fedorov Alexey
/// @date 21.04.2019
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

#ifndef FRAMEWORK_GRAPHICS_MESH_HPP
#define FRAMEWORK_GRAPHICS_MESH_HPP

#include <array>
#include <vector>

#include <common/instance_id.hpp>
#include <graphics/color.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Mesh.
///
/// Meshes contain vertex data (positions, normals, texture coordinates etc.)
/// and triangles vertex indices.
/// All vertex data must be in arrays of the same size.
/// For example, if you have a mesh of 100 vertices then positions, normals and
/// other arrays must be 100 in size.
/// Data for i-th vertex is at index "i" in each array.
///
/// For every vertex there can be a position, normal, tangent, color
/// and up to 8 texture coordinates.
///
/// The triangles are vertex indices of vertices the triangle made from.
/// First three indices form a triangle, next three the other one and so on.
/// So the indices array size must be divided by three.
////////////////////////////////////////////////////////////////////////////////
class Mesh
{
public:
    using VertexData             = std::vector<math::Vector3f>;
    using TextureCoordinatesData = std::vector<math::Vector2f>;
    using ColorData              = std::vector<Color>;
    using IndicesData            = std::vector<std::uint16_t>;

    static constexpr int max_texture_coordinates = 8;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates Mesh instance.
    ////////////////////////////////////////////////////////////////////////////
    Mesh();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    ////////////////////////////////////////////////////////////////////////////
    ~Mesh();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Copy Mesh.
    ///
    /// Creates new Mesh with new InstanceId.
    ///
    /// @param other Mesh to copy from.
    ////////////////////////////////////////////////////////////////////////////
    Mesh(const Mesh& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Copy Mesh.
    ///
    /// Creates new Mesh with new InstanceId.
    ///
    /// @param other Mesh to copy from.
    ///
    /// @return Copyed mesh instance.
    ////////////////////////////////////////////////////////////////////////////
    Mesh& operator=(const Mesh& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Move Mesh.
    ///
    /// @param other Mesh to move from.
    ////////////////////////////////////////////////////////////////////////////
    Mesh(Mesh&& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Move Mesh.
    ///
    /// @param other Mesh to move from.
    ///
    /// @return Moved mesh instance.
    ////////////////////////////////////////////////////////////////////////////
    Mesh& operator=(Mesh&& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex positions to Mesh.
    ///
    /// @param vertices New vertex data.
    ////////////////////////////////////////////////////////////////////////////
    void set_vertices(const VertexData& vertices);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex positions to Mesh.
    ///
    /// @param vertices New vertex data.
    ////////////////////////////////////////////////////////////////////////////
    void set_vertices(VertexData&& vertices) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex normals to Mesh.
    ///
    /// @param normals New normals data.
    ////////////////////////////////////////////////////////////////////////////
    void set_normals(const VertexData& normals);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex normals to Mesh.
    ///
    /// @param normals New normals data.
    ////////////////////////////////////////////////////////////////////////////
    void set_normals(VertexData&& normals) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex tangents to Mesh.
    ///
    /// @param tangents New tangents data.
    ////////////////////////////////////////////////////////////////////////////
    void set_tangents(const VertexData& tangents);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex tangents to Mesh.
    ///
    /// @param tangents New tangents data.
    ////////////////////////////////////////////////////////////////////////////
    void set_tangents(VertexData&& tangents) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex colors to Mesh.
    ///
    /// @param colors New colors data.
    ////////////////////////////////////////////////////////////////////////////
    void set_colors(const ColorData& colors);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new vertex colors to Mesh.
    ///
    /// @param colors New colors data.
    ////////////////////////////////////////////////////////////////////////////
    void set_colors(ColorData&& colors) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new texture coordinates to Mesh.
    ///
    /// Mesh can have up to `max_texture_coordinates` texture coordinates.
    ///
    /// @param index Texture coordinates array index.
    /// @param coordinates New texture coordinates data.
    ////////////////////////////////////////////////////////////////////////////
    void set_texture_coordinates(std::size_t index, const TextureCoordinatesData& coordinates);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new texture coordinates to Mesh.
    ///
    /// Mesh can have up to `max_texture_coordinates` texture coordinates.
    ///
    /// @param index Texture coordinates array index.
    /// @param coordinates New texture coordinates data.
    ////////////////////////////////////////////////////////////////////////////
    void set_texture_coordinates(std::size_t index, TextureCoordinatesData&& coordinates) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Assign new indices data to Mesh.
    ///
    /// @param indices New indices.
    ////////////////////////////////////////////////////////////////////////////
    void set_indices(const IndicesData& indices);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Sets new indices data to Mesh.
    ///
    /// @param indices New indices.
    ////////////////////////////////////////////////////////////////////////////
    void set_indices(IndicesData&& indices) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Automatically generates indices.
    ///
    /// Basically iterate over vertices and assign every vertex new index.
    ////////////////////////////////////////////////////////////////////////////
    void generate_indices();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Remove all data from Mesh.
    ///
    /// If Mesh loaded to Renderer, it's can be freely cleaned.
    ///
    /// @see Renderer::load.
    ////////////////////////////////////////////////////////////////////////////
    void clear();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get Mesh instance id. Guaranted to be unique.
    ///
    /// @return Mesh instance id.
    ////////////////////////////////////////////////////////////////////////////
    InstanceId instance_id() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get vertex positions.
    ///
    /// @return Vertex positions.
    ////////////////////////////////////////////////////////////////////////////
    const VertexData& vertices() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get vertex normals.
    ///
    /// @return Vertex normals.
    ////////////////////////////////////////////////////////////////////////////
    const VertexData& normals() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get vertex tangents.
    ///
    /// @return Vertex tangents.
    ////////////////////////////////////////////////////////////////////////////
    const VertexData& tangents() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get vertex colors.
    ///
    /// @return Vertex colors.
    ////////////////////////////////////////////////////////////////////////////
    const ColorData& colors() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get vertex texture coordinates.
    ///
    /// @param index Texture coordinates array.
    ///
    /// @return Texture coordinates.
    ////////////////////////////////////////////////////////////////////////////
    const TextureCoordinatesData& texture_coordinates(std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Get indices data.
    ///
    /// @return Indices.
    ////////////////////////////////////////////////////////////////////////////
    const IndicesData& indices() const;

private:
    friend void swap(Mesh& lhs, Mesh& rhs) noexcept;

    InstanceId m_instance_id;
    VertexData m_vertices;
    VertexData m_normals;
    VertexData m_tanegents;
    ColorData m_colors;
    std::array<TextureCoordinatesData, max_texture_coordinates> m_texture_coordinates;
    IndicesData m_indexes;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Swaps two Meshes.
///
/// @param lhs Mesh to swap.
/// @param rhs Mesh to swap.
////////////////////////////////////////////////////////////////////////////////
void swap(Mesh& lhs, Mesh& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////
} // namespace framework::graphics

#endif
