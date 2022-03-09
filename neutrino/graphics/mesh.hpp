#ifndef FRAMEWORK_GRAPHICS_MESH_HPP
#define FRAMEWORK_GRAPHICS_MESH_HPP

#include <array>
#include <unordered_map>
#include <vector>

#include <common/instance_id.hpp>
#include <graphics/color.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
class Mesh
{
public:
    enum class PrimitiveType
    {
        points,
        lines,
        line_strip,
        line_loop,
        triangles,
        triangle_strip,
        triangle_fan,
    };

    using VertexData             = std::vector<math::Vector3f>;
    using TextureCoordinatesData = std::vector<math::Vector2f>;
    using ColorData              = std::vector<Color>;
    using IndicesData            = std::vector<std::uint32_t>;

    struct SubMesh
    {
        IndicesData indices;
        PrimitiveType primitive_type;
    };

    using SubMeshMap = std::unordered_map<std::size_t, SubMesh>;

    static constexpr int max_texture_coordinates = 8;

    Mesh();
    Mesh(const Mesh& other);
    Mesh(Mesh&& other) noexcept;

    ~Mesh();

    Mesh& operator=(const Mesh& other);
    Mesh& operator=(Mesh&& other) noexcept;

    /// @brief Assign new vertex positions to Mesh.
    ///
    /// @param vertices New vertex data.
    void set_vertices(const VertexData& vertices);

    /// @brief Assign new vertex positions to Mesh.
    ///
    /// @param vertices New vertex data.
    void set_vertices(VertexData&& vertices) noexcept;

    /// @brief Assign new vertex normals to Mesh.
    ///
    /// @param normals New normals data.
    void set_normals(const VertexData& normals);

    /// @brief Assign new vertex normals to Mesh.
    ///
    /// @param normals New normals data.
    void set_normals(VertexData&& normals) noexcept;

    /// @brief Assign new vertex tangents to Mesh.
    ///
    /// @param tangents New tangents data.
    void set_tangents(const VertexData& tangents);

    /// @brief Assign new vertex tangents to Mesh.
    ///
    /// @param tangents New tangents data.
    void set_tangents(VertexData&& tangents) noexcept;

    /// @brief Assign new vertex colors to Mesh.
    ///
    /// @param colors New colors data.
    void set_colors(const ColorData& colors);

    /// @brief Assign new vertex colors to Mesh.
    ///
    /// @param colors New colors data.
    void set_colors(ColorData&& colors) noexcept;

    /// @brief Assign new texture coordinates to Mesh.
    ///
    /// Mesh can have up to `max_texture_coordinates` texture coordinates.
    ///
    /// @param index Texture coordinates array index.
    /// @param coordinates New texture coordinates data.
    void set_texture_coordinates(std::size_t index, const TextureCoordinatesData& coordinates);

    /// @brief Assign new texture coordinates to Mesh.
    ///
    /// Mesh can have up to `max_texture_coordinates` texture coordinates.
    ///
    /// @param index Texture coordinates array index.
    /// @param coordinates New texture coordinates data.
    void set_texture_coordinates(std::size_t index, TextureCoordinatesData&& coordinates) noexcept;

    /// @brief Set indices data for Mesh.
    ///
    /// @param indices New indices.
    /// @param type Kind of primitives for sub mesh.
    ///
    /// @return Index of new sub mesh.
    std::size_t add_sub_mesh(const IndicesData& indices, PrimitiveType type = PrimitiveType::triangles);

    /// @brief Set indices data for Mesh.
    ///
    /// @param indices New indices.
    /// @param type Kind of primitives for sub mesh.
    ///
    /// @return Index of new sub mesh.
    std::size_t add_sub_mesh(IndicesData&& indices, PrimitiveType type = PrimitiveType::triangles) noexcept;

    /// @brief Remove previously created sub mesh.
    ///
    /// @param index Sub mesh to delete.
    void remove_sub_mesh(std::size_t index);

    /// @brief Remove all data from Mesh.
    ///
    /// If Mesh loaded to Renderer, it's can be freely cleaned.
    ///
    /// @see Renderer::load.
    void clear();

    /// @brief Get Mesh instance id. Guaranted to be unique.
    ///
    /// @return Mesh instance id.
    InstanceId instance_id() const;

    /// @brief Get vertex positions.
    ///
    /// @return Vertex positions.
    const VertexData& vertices() const;

    /// @brief Get vertex normals.
    ///
    /// @return Vertex normals.
    const VertexData& normals() const;

    /// @brief Get vertex tangents.
    ///
    /// @return Vertex tangents.
    const VertexData& tangents() const;

    /// @brief Get vertex colors.
    ///
    /// @return Vertex colors.
    const ColorData& colors() const;

    /// @brief Get vertex texture coordinates.
    ///
    /// @param index Texture coordinates array.
    ///
    /// @return Texture coordinates.
    const TextureCoordinatesData& texture_coordinates(std::size_t index) const;

    /// @brief Checks if sub mesh with index exists in Mesh.
    ///
    /// @param index Sub mesh index to check.
    ///
    /// @return `true` if mesh with index exists in the Mesh.
    bool has_sub_mesh(std::size_t index);

    /// @brief Get all sub meshes of the Mesh.
    ///
    /// @return Sub meshes.
    const SubMeshMap& sub_meshes() const;

private:
    friend void swap(Mesh& lhs, Mesh& rhs) noexcept;

    InstanceId m_instance_id;
    VertexData m_vertices;
    VertexData m_normals;
    VertexData m_tanegents;
    ColorData m_colors;
    std::array<TextureCoordinatesData, max_texture_coordinates> m_texture_coordinates;
    SubMeshMap m_sub_meshes;
    std::size_t m_last_sub_mesh_index = 0;
};

/// @brief Swaps two Meshes.
///
/// @param lhs Mesh to swap.
/// @param rhs Mesh to swap.
void swap(Mesh& lhs, Mesh& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace framework::graphics

#endif
