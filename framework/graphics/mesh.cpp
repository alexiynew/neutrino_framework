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

#include <graphics/mesh.hpp>
#include <graphics/opengl/gl.hpp>

namespace
{
template <typename T>
inline framework::uint32 create_buffer(const std::vector<T>& data)
{
    using namespace ::framework::graphics::opengl::details;

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
inline void load_buffer(framework::uint32* buffer_id, const std::vector<T>& data)
{
    using namespace ::framework::graphics::opengl::details;

    if (*buffer_id != 0) {
        glDeleteBuffers(1, buffer_id);
    }

    *buffer_id = create_buffer(data);
}

enum vbo_type
{
    vertices    = 0,
    normals     = 1,
    tex_coord_1 = 2,
    tex_coord_2 = 3,
    colors      = 4,
    tangents    = 5,
};

} // namespace

namespace framework::opengl
{
mesh::mesh()
{
    using namespace ::framework::graphics::opengl::details;
    glGenVertexArrays(1, &m_vertex_array_id);
}

mesh::~mesh()
{
    using namespace ::framework::graphics::opengl::details;
    const auto count = sizeof(m_buffer_ids) / sizeof(m_buffer_ids[0]);
    glDeleteBuffers(count, m_buffer_ids);
    glDeleteVertexArrays(1, &m_vertex_array_id);
}

mesh::mesh(mesh&& other)
{
    swap(*this, other);
}

mesh& mesh::operator=(mesh&& other)
{
    swap(*this, other);
    return *this;
}

void mesh::load_vertices(const std::vector<math::vector2f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::vertices], data);
    m_type_sizes[vbo_type::vertices] = 2;

    glBindVertexArray(0);
}

void mesh::load_vertices(const std::vector<math::vector3f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::vertices], data);
    m_type_sizes[vbo_type::vertices] = 3;

    glBindVertexArray(0);
}

void mesh::load_vertices(const std::vector<math::vector4f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::vertices], data);
    m_type_sizes[vbo_type::vertices] = 4;

    glBindVertexArray(0);
}

void mesh::load_normals(const std::vector<math::vector2f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::normals], data);
    m_type_sizes[vbo_type::normals] = 2;

    glBindVertexArray(0);
}

void mesh::load_normals(const std::vector<math::vector3f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::normals], data);
    m_type_sizes[vbo_type::normals] = 3;

    glBindVertexArray(0);
}

void mesh::load_texture_coord1(const std::vector<math::vector2f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::tex_coord_1], data);
    m_type_sizes[vbo_type::tex_coord_1] = 2;

    glBindVertexArray(0);
}

void mesh::load_texture_coord2(const std::vector<math::vector2f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::tex_coord_2], data);
    m_type_sizes[vbo_type::tex_coord_2] = 2;

    glBindVertexArray(0);
}

void mesh::load_colors(const std::vector<color_t>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::colors], data);
    m_type_sizes[vbo_type::colors] = 4;

    glBindVertexArray(0);
}

void mesh::load_tangents(const std::vector<math::vector3f>& data)
{
    using namespace ::framework::graphics::opengl::details;
    glBindVertexArray(m_vertex_array_id);

    load_buffer(&m_buffer_ids[vbo_type::tangents], data);
    m_type_sizes[vbo_type::tangents] = 3;

    glBindVertexArray(0);
}

void mesh::bind_vertices_attrib(int32 index)
{
    using namespace ::framework::graphics::opengl::details;
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer_ids[vbo_type::vertices]);
    glVertexAttribPointer(index, m_type_sizes[vbo_type::vertices], GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void mesh::bind_texture_attrib(int32 index)
{
    using namespace ::framework::graphics::opengl::details;
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer_ids[vbo_type::tex_coord_1]);
    glVertexAttribPointer(index, m_type_sizes[vbo_type::tex_coord_1], GL_FLOAT, GL_FALSE, 0, (void*)0);
}

uint32 mesh::vertex_array_id() const
{
    return m_vertex_array_id;
}

void swap(mesh& a, mesh& b)
{
    const auto count = sizeof(a.m_buffer_ids) / sizeof(a.m_buffer_ids[0]);
    for (uint32 i = 0; i < count; ++i) {
        std::swap(a.m_buffer_ids[i], b.m_buffer_ids[i]);
        std::swap(a.m_type_sizes[i], b.m_type_sizes[i]);
    }
    std::swap(a.m_vertex_array_id, b.m_vertex_array_id);
}

} // namespace framework::opengl
