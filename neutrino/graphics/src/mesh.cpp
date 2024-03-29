#include <limits>
#include <stdexcept>

#include <graphics/mesh.hpp>

namespace
{
const framework::graphics::Mesh::TextureCoordinatesData empty_texture_coordiantes;
}

namespace framework::graphics
{
Mesh::Mesh() = default;

Mesh::Mesh(const Mesh& other)
    : m_vertices(other.m_vertices)
    , m_normals(other.m_normals)
    , m_tanegents(other.m_tanegents)
    , m_colors(other.m_colors)
    , m_texture_coordinates(other.m_texture_coordinates)
    , m_submeshes(other.m_submeshes)
    , m_last_submesh_index(other.m_last_submesh_index)
{}

Mesh::Mesh(Mesh&& other) noexcept
{
    swap(*this, other);
}

Mesh::~Mesh() = default;

Mesh& Mesh::operator=(const Mesh& other)
{
    using std::swap;

    Mesh tmp(other);
    swap(*this, tmp);
    return *this;
}

Mesh& Mesh::operator=(Mesh&& other) noexcept
{
    swap(*this, other);
    return *this;
}

void Mesh::set_vertices(const VertexData& data)
{
    if (data.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_vertices: Trying to add to many vertices to mesh.");
    }

    m_vertices = data;
}

void Mesh::set_vertices(VertexData&& data)
{
    if (data.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_vertices: Trying to add to many vertices to mesh.");
    }

    using std::swap;
    swap(m_vertices, data);
}

void Mesh::set_normals(const VertexData& normals)
{
    if (normals.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_normals: Trying to add to many normals to mesh.");
    }

    m_normals = normals;
}

void Mesh::set_normals(VertexData&& normals)
{
    if (normals.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_normals: Trying to add to many normals to mesh.");
    }

    using std::swap;
    swap(m_normals, normals);
}

void Mesh::set_tangents(const VertexData& tangents)
{
    if (tangents.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_tangents: Trying to add to many tangents to mesh.");
    }

    m_tanegents = tangents;
}

void Mesh::set_tangents(VertexData&& tangents)
{
    if (tangents.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_tangents: Trying to add to many tangents to mesh.");
    }

    using std::swap;
    swap(m_tanegents, tangents);
}

void Mesh::set_colors(const ColorData& colors)
{
    if (colors.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_colors: Trying to add to many colors to mesh.");
    }

    m_colors = colors;
}

void Mesh::set_colors(ColorData&& colors)
{
    if (colors.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_colors: Trying to add to many colors to mesh.");
    }

    using std::swap;
    swap(m_colors, colors);
}

void Mesh::set_texture_coordinates(std::size_t index, const TextureCoordinatesData& coordinates)
{
    if (index >= max_texture_coordinates) {
        return;
    }

    if (coordinates.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_texture_coordinates: Trying to add to many texutre coordinates to mesh.");
    }

    m_texture_coordinates[index] = coordinates;
}

void Mesh::set_texture_coordinates(std::size_t index, TextureCoordinatesData&& coordinates)
{
    if (index >= max_texture_coordinates) {
        return;
    }

    if (coordinates.size() > std::numeric_limits<IndicesData::value_type>::max()) {
        throw std::runtime_error("Mesh::set_texture_coordinates: Trying to add to many texutre coordinates to mesh.");
    }

    using std::swap;
    swap(m_texture_coordinates[index], coordinates);
}

Mesh::SubMeshIndexType Mesh::add_submesh(const IndicesData& indices, PrimitiveType type)
{
    std::size_t index = ++m_last_submesh_index;
    m_submeshes.emplace(index, SubMesh{std::move(indices), type});

    return index;
}

Mesh::SubMeshIndexType Mesh::add_submesh(IndicesData&& indices, PrimitiveType type)
{
    std::size_t index = ++m_last_submesh_index;
    m_submeshes.emplace(index, SubMesh{std::move(indices), type});

    return index;
}

void Mesh::remove_submesh(Mesh::SubMeshIndexType index)
{
    if (auto it = m_submeshes.find(index); it != m_submeshes.end()) {
        m_submeshes.erase(it);
    }
}

void Mesh::clear()
{
    m_vertices.clear();
    m_normals.clear();
    m_tanegents.clear();
    m_colors.clear();

    for (TextureCoordinatesData& coordinates : m_texture_coordinates) {
        coordinates.clear();
    }

    m_submeshes.clear();
    m_last_submesh_index = 0;
}

const Mesh::VertexData& Mesh::vertices() const
{
    return m_vertices;
}

const Mesh::VertexData& Mesh::normals() const
{
    return m_normals;
}

const Mesh::VertexData& Mesh::tangents() const
{
    return m_tanegents;
}

const Mesh::ColorData& Mesh::colors() const
{
    return m_colors;
}

const Mesh::TextureCoordinatesData& Mesh::texture_coordinates(std::size_t index) const
{
    if (index >= max_texture_coordinates) {
        return empty_texture_coordiantes;
    }

    return m_texture_coordinates[index];
}

bool Mesh::has_submesh(Mesh::SubMeshIndexType index) const
{
    return m_submeshes.count(index) > 0;
}

const Mesh::SubMeshMap& Mesh::submeshes() const
{
    return m_submeshes;
}

void swap(Mesh& lhs, Mesh& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_vertices, rhs.m_vertices);
    swap(lhs.m_normals, rhs.m_normals);
    swap(lhs.m_tanegents, rhs.m_tanegents);
    swap(lhs.m_colors, rhs.m_colors);
    swap(lhs.m_texture_coordinates, rhs.m_texture_coordinates);
    swap(lhs.m_submeshes, rhs.m_submeshes);
    swap(lhs.m_last_submesh_index, rhs.m_last_submesh_index);
}

} // namespace framework::graphics
