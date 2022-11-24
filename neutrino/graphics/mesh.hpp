#ifndef GRAPHICS_MESH_HPP
#define GRAPHICS_MESH_HPP

#include <array>
#include <unordered_map>
#include <vector>

#include <common/global_defines.hpp>
#include <graphics/color.hpp>
#include <math/math.hpp>

namespace neutrino::graphics
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Mesh.
///
/// Meshes contain vertex data (positions, normals, texture coordinates etc.)
/// and vertex indices, which forms some kind of primitive to render.
/// All vertex data must be in arrays of the same size.
/// Data for i-th vertex is at index "i" in each array.
///
/// For every vertex there can be a position, normal, tangent, color and up to 8 texture coordinates.
///
/// Each mesh consist of group of vertex indices, called Submesh.
/// At least one submesh must be defined to render something.
class Mesh final
{
public:
    /// @brief Represents what kind of primitive a submesh is describe.
    enum class PrimitiveType
    {
        points,         ///< Each index is individual point.
        lines,          ///< Vertices 0 and 1 are considered a line. Vertices 2 and 3 are considered a line. And so on.
        line_strip,     ///< The adjacent vertices are considered lines. If you pass n vertices, you will get n-1 lines.
        line_loop,      ///< As line strips, except that the first and last vertices are also used as a line.
        triangles,      ///< Vertices 0, 1, and 2 form a triangle. Vertices 3, 4, and 5 form a triangle. And so on.
        triangle_strip, ///<  Every group of 3 adjacent vertices forms a triangle. The face direction of the strip is
                        ///<  determined by the winding of the first triangle. Each successive triangle will have its
                        ///<  effective face order reversed, so the system compensates for that by testing it in the
                        ///<  opposite way. A vertex stream of n length will generate n-2 triangles.

        triangle_fan, ///< The first vertex is always held fixed. From there on, every group of 2 adjacent vertices form
                      ///< a triangle with the first. So with a vertex stream, you get a list of triangles like so:
                      ///< (0, 1, 2) (0, 2, 3), (0, 3, 4), etc. A vertex stream of n length will generate n-2 triangles.
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

    using SubMeshIndexType = std::size_t;
    using SubMeshMap       = std::unordered_map<SubMeshIndexType, SubMesh>;

    static constexpr size_t max_texture_coordinates = 8;

    LIBRARY_API Mesh();
    LIBRARY_API Mesh(const Mesh& other);
    LIBRARY_API Mesh(Mesh&& other) noexcept;

    LIBRARY_API ~Mesh();

    LIBRARY_API Mesh& operator=(const Mesh& other);
    LIBRARY_API Mesh& operator=(Mesh&& other) noexcept;

    /// @brief Assign new vertex positions to Mesh.
    ///
    /// @param vertices New vertex data.
    LIBRARY_API void set_vertices(const VertexData& vertices);

    /// @brief Assign new vertex positions to Mesh.
    ///
    /// @param vertices New vertex data.
    LIBRARY_API void set_vertices(VertexData&& vertices);

    /// @brief Assign new vertex normals to Mesh.
    ///
    /// @param normals New normals data.
    LIBRARY_API void set_normals(const VertexData& normals);

    /// @brief Assign new vertex normals to Mesh.
    ///
    /// @param normals New normals data.
    LIBRARY_API void set_normals(VertexData&& normals);

    /// @brief Assign new vertex tangents to Mesh.
    ///
    /// @param tangents New tangents data.
    LIBRARY_API void set_tangents(const VertexData& tangents);

    /// @brief Assign new vertex tangents to Mesh.
    ///
    /// @param tangents New tangents data.
    LIBRARY_API void set_tangents(VertexData&& tangents);

    /// @brief Assign new vertex colors to Mesh.
    ///
    /// @param colors New colors data.
    LIBRARY_API void set_colors(const ColorData& colors);

    /// @brief Assign new vertex colors to Mesh.
    ///
    /// @param colors New colors data.
    LIBRARY_API void set_colors(ColorData&& colors);

    /// @brief Assign new texture coordinates to Mesh.
    ///
    /// Mesh can have up to `max_texture_coordinates` texture coordinates.
    ///
    /// @param index Texture coordinates array index.
    /// @param coordinates New texture coordinates data.
    LIBRARY_API void set_texture_coordinates(std::size_t index, const TextureCoordinatesData& coordinates);

    /// @brief Assign new texture coordinates to Mesh.
    ///
    /// Mesh can have up to `max_texture_coordinates` texture coordinates.
    ///
    /// @param index Texture coordinates array index.
    /// @param coordinates New texture coordinates data.
    LIBRARY_API void set_texture_coordinates(std::size_t index, TextureCoordinatesData&& coordinates);

    /// @brief Set indices data for Mesh.
    ///
    /// @param indices New indices.
    /// @param type Kind of primitives for sub mesh.
    ///
    /// @return Index of new sub mesh.
    LIBRARY_API SubMeshIndexType add_submesh(const IndicesData& indices, PrimitiveType type = PrimitiveType::triangles);

    /// @brief Set indices data for Mesh.
    ///
    /// @param indices New indices.
    /// @param type Kind of primitives for sub mesh.
    ///
    /// @return Index of new sub mesh.
    LIBRARY_API SubMeshIndexType add_submesh(IndicesData&& indices, PrimitiveType type = PrimitiveType::triangles);

    /// @brief Remove previously created sub mesh.
    ///
    /// @param index Sub mesh to delete.
    LIBRARY_API void remove_submesh(SubMeshIndexType index);

    /// @brief Remove all data from Mesh.
    ///
    /// If Mesh loaded to Renderer, it's can be freely cleaned.
    ///
    /// @see Renderer::load.
    LIBRARY_API void clear();

    /// @brief Get vertex positions.
    ///
    /// @return Vertex positions.
    LIBRARY_API const VertexData& vertices() const;

    /// @brief Get vertex normals.
    ///
    /// @return Vertex normals.
    LIBRARY_API const VertexData& normals() const;

    /// @brief Get vertex tangents.
    ///
    /// @return Vertex tangents.
    LIBRARY_API const VertexData& tangents() const;

    /// @brief Get vertex colors.
    ///
    /// @return Vertex colors.
    LIBRARY_API const ColorData& colors() const;

    /// @brief Get vertex texture coordinates.
    ///
    /// @param index Texture coordinates array.
    ///
    /// @return Texture coordinates.
    LIBRARY_API const TextureCoordinatesData& texture_coordinates(std::size_t index) const;

    /// @brief Checks if sub mesh with index exists in Mesh.
    ///
    /// @param index Sub mesh index to check.
    ///
    /// @return `true` if mesh with index exists in the Mesh.
    LIBRARY_API bool has_submesh(SubMeshIndexType index) const;

    /// @brief Get all sub meshes of the Mesh.
    ///
    /// @return Sub meshes.
    LIBRARY_API const SubMeshMap& submeshes() const;

private:
    LIBRARY_API friend void swap(Mesh& lhs, Mesh& rhs) noexcept;

    VertexData m_vertices;
    VertexData m_normals;
    VertexData m_tanegents;
    ColorData m_colors;
    std::array<TextureCoordinatesData, max_texture_coordinates> m_texture_coordinates;
    SubMeshMap m_submeshes;
    std::size_t m_last_submesh_index = 0;
};

/// @brief Swaps two Meshes.
///
/// @param lhs Mesh to swap.
/// @param rhs Mesh to swap.
LIBRARY_API void swap(Mesh& lhs, Mesh& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace neutrino::graphics

#endif
