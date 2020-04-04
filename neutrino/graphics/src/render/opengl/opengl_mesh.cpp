/// @file
/// @brief OpenGL mesh.
/// @author Fedorov Alexey
/// @date 03.04.2020

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

#include <graphics/src/opengl/opengl.hpp>
#include <graphics/src/render/opengl/opengl_mesh.hpp>

using namespace framework::graphics;
using namespace framework::graphics::details::opengl;

namespace
{
constexpr std::array<Attribute, attributes_count> attributes_list = {
Attribute::position,
Attribute::normal,
Attribute::tangent,
Attribute::color,
Attribute::texcoord0,
Attribute::texcoord1,
Attribute::texcoord2,
Attribute::texcoord3,
Attribute::texcoord4,
Attribute::texcoord5,
Attribute::texcoord6,
Attribute::texcoord7,
};

template <typename T>
OpenglMesh::BufferInfo create_buffer(int buffer_type, const std::vector<T>& data)
{
    if (data.empty()) {
        return OpenglMesh::BufferInfo();
    }

    const GLsizeiptr data_size = static_cast<GLsizeiptr>(data.size() * sizeof(T));

    OpenglMesh::BufferInfo info;

    glGenBuffers(1, &info.buffer);

    glBindBuffer(buffer_type, info.buffer);
    glBufferData(buffer_type, data_size, data.data(), GL_STATIC_DRAW);
    glBindBuffer(buffer_type, 0);

    if constexpr (std::is_same_v<T, Mesh::VertexData::value_type>) {
        info.type  = GL_FLOAT;
        info.count = T::components_count;
    } else if constexpr (std::is_same_v<T, Mesh::TextureCoordinatesData::value_type>) {
        info.type  = GL_FLOAT;
        info.count = T::components_count;
    } else if constexpr (std::is_same_v<T, Mesh::ColorData::value_type>) {
        info.type  = GL_UNSIGNED_BYTE;
        info.count = 4;
    } else if constexpr (std::is_same_v<T, Mesh::IndicesData::value_type>) {
        info.type  = GL_UNSIGNED_SHORT;
        info.count = 1;
    }

    return info;
}

} // namespace

namespace framework::graphics
{
OpenglMesh::OpenglMesh(const Mesh& mesh)
{
    load(mesh);
}

OpenglMesh::~OpenglMesh()
{
    for (const BufferInfo& info : vertex_buffers) {
        glDeleteBuffers(1, &info.buffer);
    }

    glDeleteBuffers(1, &index_buffer);
    glDeleteVertexArrays(1, &vertex_array);
}

void OpenglMesh::load(const Mesh& mesh)
{
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    // clang-format off
    vertex_buffers[static_cast<std::size_t>(Attribute::position)]  = create_buffer(GL_ARRAY_BUFFER, mesh.vertices());
    vertex_buffers[static_cast<std::size_t>(Attribute::normal)]    = create_buffer(GL_ARRAY_BUFFER, mesh.normals());
    vertex_buffers[static_cast<std::size_t>(Attribute::tangent)]   = create_buffer(GL_ARRAY_BUFFER, mesh.tangents());
    vertex_buffers[static_cast<std::size_t>(Attribute::color)]     = create_buffer(GL_ARRAY_BUFFER, mesh.colors());
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord0)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(0));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord1)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(1));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord2)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(2));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord3)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(3));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord4)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(4));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord5)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(5));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord6)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(6));
    vertex_buffers[static_cast<std::size_t>(Attribute::texcoord7)] = create_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(7));
    // clang-format on

    index_buffer = create_buffer(GL_ELEMENT_ARRAY_BUFFER, mesh.indices()).buffer;

    glBindVertexArray(0);
}

void OpenglMesh::draw() const
{
    glBindVertexArray(vertex_array);

    for (const Attribute attr : attributes_list) {
        enable_attribute(attr);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

void OpenglMesh::enable_attribute(Attribute attribute) const
{
    const GLuint attr_index = static_cast<GLuint>(attribute);
    const BufferInfo& info  = vertex_buffers[attr_index];

    if (info.buffer == 0) {
        return;
    }

    glEnableVertexAttribArray(attr_index);
    glBindBuffer(GL_ARRAY_BUFFER, info.buffer);
    glVertexAttribPointer(0, info.count, info.type, GL_FALSE, 0, 0);
}

} // namespace framework::graphics
