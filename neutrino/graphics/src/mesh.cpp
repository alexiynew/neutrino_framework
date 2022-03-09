#include <limits>

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
    , m_sub_meshes(other.m_sub_meshes)
    , m_last_sub_mesh_index(other.m_last_sub_mesh_index)
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
    m_vertices = data;
}

void Mesh::set_vertices(VertexData&& data) noexcept
{
    using std::swap;
    swap(m_vertices, data);
}

void Mesh::set_normals(const VertexData& normals)
{
    m_normals = normals;
}

void Mesh::set_normals(VertexData&& normals) noexcept
{
    using std::swap;
    swap(m_normals, normals);
}

void Mesh::set_tangents(const VertexData& tangents)
{
    m_tanegents = tangents;
}

void Mesh::set_tangents(VertexData&& tangents) noexcept
{
    using std::swap;
    swap(m_tanegents, tangents);
}

void Mesh::set_colors(const ColorData& colors)
{
    m_colors = colors;
}

void Mesh::set_colors(ColorData&& colors) noexcept
{
    using std::swap;
    swap(m_colors, colors);
}

void Mesh::set_texture_coordinates(std::size_t index, const TextureCoordinatesData& coordinates)
{
    if (index >= max_texture_coordinates) {
        return;
    }

    m_texture_coordinates[index] = coordinates;
}

void Mesh::set_texture_coordinates(std::size_t index, TextureCoordinatesData&& coordinates) noexcept
{
    using std::swap;

    if (index >= max_texture_coordinates) {
        return;
    }

    swap(m_texture_coordinates[index], coordinates);
}

std::size_t Mesh::add_sub_mesh(const IndicesData& indices, PrimitiveType type)
{
    std::size_t index = ++m_last_sub_mesh_index;
    m_sub_meshes.emplace(index, SubMesh{std::move(indices), type});

    return index;
}

std::size_t Mesh::add_sub_mesh(IndicesData&& indices, PrimitiveType type) noexcept
{
    std::size_t index = ++m_last_sub_mesh_index;
    m_sub_meshes.emplace(index, SubMesh{std::move(indices), type});

    return index;
}

void Mesh::remove_sub_mesh(std::size_t index)
{
    if (auto it = m_sub_meshes.find(index); it != m_sub_meshes.end()) {
        m_sub_meshes.erase(it);
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

    m_sub_meshes.clear();
    m_last_sub_mesh_index = 0;
}

InstanceId Mesh::instance_id() const
{
    return m_instance_id;
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

bool Mesh::has_sub_mesh(std::size_t index)
{
    return m_sub_meshes.count(index) > 0;
}

const Mesh::SubMeshMap& Mesh::sub_meshes() const
{
    return m_sub_meshes;
}

void swap(Mesh& lhs, Mesh& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_vertices, rhs.m_vertices);
    swap(lhs.m_normals, rhs.m_normals);
    swap(lhs.m_tanegents, rhs.m_tanegents);
    swap(lhs.m_colors, rhs.m_colors);
    swap(lhs.m_texture_coordinates, rhs.m_texture_coordinates);
    swap(lhs.m_sub_meshes, rhs.m_sub_meshes);
    swap(lhs.m_last_sub_mesh_index, rhs.m_last_sub_mesh_index);
}

} // namespace framework::graphics
