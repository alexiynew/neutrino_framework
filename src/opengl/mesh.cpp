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
inline framework::uint32 create_buffer(const std::vector<T>& data)
{
    using namespace framework::opengl;

    if (data.empty()) {
        return 0;
    }

    framework::uint32 buffer_id = 0;
    glGenBuffers(1, &buffer_id);

    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data[0].data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return buffer_id;
}

template <typename T>
inline framework::uint32 load_buffer(uint32* buffer_id, const std::vector<T>& data)
{
    using namespace framework::opengl;

    if (*buffer_id != 0) {
        glDeleteBuffers(1, &buffer_id);
    }

    *buffer_id = create_buffer(data);
}

enum vbo_type 
{
    vertices = 0;
    normals = 1;
    tex_coord_1 = 2;
    tex_coord_2 = 3;
    colors = 4;
    tangents = 5;
};

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

void mesh::load_vertices(const std::vector<math::vector2f> vertices)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::vertices], vertices);
    m_type_sizes[vbo_type::vertices] = 2;

    glBindVertexArray(0);
}

void mesh::load_vertices(const std::vector<math::vector3f> vertices)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::vertices], vertices);
    m_type_sizes[vbo_type::vertices] = 3;

    glBindVertexArray(0);
}

void mesh::load_vertices(const std::vector<math::vector4f> vertices)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::vertices], vertices);
    m_type_sizes[vbo_type::vertices] = 4;

    glBindVertexArray(0);
}

void mesh::load_normals(const std::vector<math::vector2f>& normals)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::normals], vertices);
    m_type_sizes[vbo_type::normals] = 2;

    glBindVertexArray(0);
}

void mesh::load_normals(const std::vector<math::vector3f>& normals)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::normals], vertices);
    m_type_sizes[vbo_type::normals] = 3;

    glBindVertexArray(0);
}

void mesh::load_texture_coord1(const std::vector<math::vector2f>& t_coord)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::tex_coord_1], vertices);
    m_type_sizes[vbo_type::tex_coord_1] = 3;

    glBindVertexArray(0);
}

void mesh::load_texture_coord2(const std::vector<math::vector2f>& t_coord)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::tex_coord_2], vertices);
    m_type_sizes[vbo_type::tex_coord_2] = 3;

    glBindVertexArray(0);

}

void mesh::load_colors(const std::vector<color_t>& colors)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::colors], vertices);
    m_type_sizes[vbo_type::colors] = 4;

    glBindVertexArray(0);
}

void mesh::load_tangents(const std::vector<math::vector3f>& tangents)
{
    glBindVertexArray(m_vertex_array_id);

    load_buffer(m_bufferids[vbo_type::tangents], vertices);
    m_type_sizes[vbo_type::tangents] = 3;

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
