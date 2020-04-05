/// @file
/// @brief Mesh.
/// @author Fedorov Alexey
/// @date 21.04.2019

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

#include <limits>

#include <graphics/mesh.hpp>

namespace
{
const framework::graphics::Mesh::TextureCoordinatesData empty_texture_coordiantes;
}

namespace framework::graphics
{
Mesh::Mesh() = default;

Mesh::~Mesh() = default;

Mesh::Mesh(const Mesh& other)
    : m_vertices(other.m_vertices)
    , m_indexes(other.m_indexes)
{}

Mesh& Mesh::operator=(const Mesh& other)
{
    using std::swap;

    Mesh tmp(other);
    swap(*this, tmp);
    return *this;
}

Mesh::Mesh(Mesh&& other) noexcept
{
    swap(*this, other);
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

void Mesh::set_texture_coordinates(int index, const TextureCoordinatesData& coordinates)
{
    if (index < 0 || index >= max_texture_coordinates) {
        return;
    }

    m_texture_coordinates[index] = coordinates;
}

void Mesh::set_texture_coordinates(int index, TextureCoordinatesData&& coordinates) noexcept
{
    using std::swap;

    if (index < 0 || index >= max_texture_coordinates) {
        return;
    }

    swap(m_texture_coordinates[index], coordinates);
}

void Mesh::set_indices(const IndicesData& indexes)
{
    m_indexes = indexes;
}

void Mesh::set_indices(IndicesData&& indexes) noexcept
{
    using std::swap;
    swap(m_indexes, indexes);
}

void Mesh::generate_indices()
{
    constexpr std::size_t max_size = std::numeric_limits<IndicesData::value_type>::max();

    m_indexes.resize(m_vertices.size());
    for (std::size_t i = 0; i < m_vertices.size() && i < max_size; ++i) {
        m_indexes[i] = static_cast<IndicesData::value_type>(i);
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

    m_indexes.clear();
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

const Mesh::TextureCoordinatesData& Mesh::texture_coordinates(int index) const
{
    if (index < 0 || index >= max_texture_coordinates) {
        return empty_texture_coordiantes;
    }

    return m_texture_coordinates[index];
}

const Mesh::IndicesData& Mesh::indices() const
{
    return m_indexes;
}

void swap(Mesh& lhs, Mesh& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_vertices, rhs.m_vertices);
    swap(lhs.m_normals, rhs.m_normals);
    swap(lhs.m_tanegents, rhs.m_tanegents);
    swap(lhs.m_colors, rhs.m_colors);
    swap(lhs.m_texture_coordinates, rhs.m_texture_coordinates);
    swap(lhs.m_indexes, rhs.m_indexes);
}

} // namespace framework::graphics
