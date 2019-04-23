/// @file
/// @brief OpenGL mesh.
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

#include <opengl/gl.hpp>
#include <opengl/mesh.hpp>

namespace
{
template <typename T>
framework::uint32 create_buffer(std::vector<T> data)
{
    using namespace framework::opengl;

    framework::uint32 buffer_id = 0;
    glGenBuffers(1, &buffer_id);

    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data[0].data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return buffer_id;
}

} // namespace

namespace framework::opengl
{
mesh::mesh()
{
    glGenVertexArrays(1, &m_vertex_array_id);
}

mesh::~mesh()
{
    glDeleteVertexArrays(1, &m_vertex_array_id);

    if (m_vertex_buffer_id != 0) {
        glDeleteBuffers(1, &m_vertex_buffer_id);
    }

    if (m_texture_buffer_id != 0) {
        glDeleteBuffers(1, &m_texture_buffer_id);
    }
}

mesh::mesh(mesh&& other)
{
    using std::swap;
    swap(other.m_vertex_array_id, m_vertex_array_id);
    swap(other.m_vertex_buffer_id, m_vertex_buffer_id);
    swap(other.m_texture_buffer_id, m_texture_buffer_id);
    swap(other.m_vertex_size, m_vertex_size);
}

mesh& mesh::operator=(mesh&& other)
{
    using std::swap;
    swap(other.m_vertex_array_id, m_vertex_array_id);
    swap(other.m_vertex_buffer_id, m_vertex_buffer_id);
    swap(other.m_texture_buffer_id, m_texture_buffer_id);
    swap(other.m_vertex_size, m_vertex_size);

    return *this;
}

void mesh::load(const std::vector<math::vector4f> vertices, const std::vector<math::vector2f> texture_coordinates)
{
    glBindVertexArray(m_vertex_array_id);

    if (!vertices.empty()) {
        m_vertex_buffer_id = create_buffer(vertices);
        m_vertex_size      = 4;
    }

    if (!texture_coordinates.empty()) {
        m_texture_buffer_id = create_buffer(texture_coordinates);
    }

    glBindVertexArray(0);
}

void mesh::load(const std::vector<math::vector3f> vertices, const std::vector<math::vector2f> texture_coordinates)
{
    glBindVertexArray(m_vertex_array_id);

    if (!vertices.empty()) {
        m_vertex_buffer_id = create_buffer(vertices);
        m_vertex_size      = 3;
    }

    if (!texture_coordinates.empty()) {
        m_texture_buffer_id = create_buffer(texture_coordinates);
    }

    glBindVertexArray(0);
}

void mesh::load(const std::vector<math::vector2f> vertices, const std::vector<math::vector2f> texture_coordinates)
{
    glBindVertexArray(m_vertex_array_id);

    if (!vertices.empty()) {
        m_vertex_buffer_id = create_buffer(vertices);
        m_vertex_size      = 2;
    }

    if (!texture_coordinates.empty()) {
        m_texture_buffer_id = create_buffer(texture_coordinates);
    }

    glBindVertexArray(0);
}

void mesh::bind_vertices_attrib(int32 index)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_id);
    glVertexAttribPointer(index, m_vertex_size, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void mesh::bind_texture_attrib(int32 index)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_texture_buffer_id);
    glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

uint32 mesh::vertex_array_id() const
{
    return m_vertex_array_id;
}

} // namespace framework::opengl
