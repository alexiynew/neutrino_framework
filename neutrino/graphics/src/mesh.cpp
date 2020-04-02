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

#include <graphics/mesh.hpp>

namespace framework::graphics
{
Mesh::Mesh() = default;

Mesh::~Mesh() = default;
//{
//}

Mesh::Mesh(const Mesh& other) : m_vertices(other.m_vertices), m_indexes(other.m_indexes)
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

void Mesh::set_indices(const IndicesData& indexes)
{
    m_indexes = indexes;
}

void Mesh::set_indices(IndicesData&& indexes) noexcept
{
    using std::swap;
    swap(m_indexes, indexes);
}

void Mesh::clear()
{
    m_vertices.clear();
    m_indexes.clear();
}

const InstanceId& Mesh::instance_id() const
{
    return m_instance_id;
}

const Mesh::VertexData& Mesh::vertices() const
{
    return m_vertices;
}

const Mesh::IndicesData& Mesh::indices() const
{
    return m_indexes;
}

void swap(Mesh& lhs, Mesh& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_vertices, rhs.m_vertices);
    swap(lhs.m_indexes, rhs.m_indexes);
}

} // namespace framework::graphics

