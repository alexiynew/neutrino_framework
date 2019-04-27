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

#ifndef FRAMEWORK_OPENGL_MESH_HPP
#define FRAMEWORK_OPENGL_MESH_HPP

#include <vector>

#include <common/color_type.hpp>
#include <common/types.hpp>
#include <math/math.hpp>

namespace framework::opengl
{
/// @addtogroup opengl_module
/// @{

/// @brief OpenGL mesh.
///
/// Mesh contains vertices of triangle arrays.
/// For every vertex there can be a coordinates, normal, two texture coordinates, color and tangent.
/// All vertex information is stored in separate arrays.
///
/// @thread_safety All mesh operation should be in main thread.
///
class mesh
{
public:
    mesh();
    ~mesh();

    mesh(const mesh&) = delete;
    mesh& operator=(const mesh&) = delete;

    mesh(mesh&&);
    mesh& operator=(mesh&&);

    void load_vertices(const std::vector<math::vector2f>& vertices);
    void load_vertices(const std::vector<math::vector3f>& vertices);
    void load_vertices(const std::vector<math::vector4f>& vertices);

    void load_normals(const std::vector<math::vector2f>& normals);
    void load_normals(const std::vector<math::vector3f>& normals);

    void load_texture_coord1(const std::vector<math::vector2f>& t_coord);
    void load_texture_coord2(const std::vector<math::vector2f>& t_coord);

    void load_colors(const std::vector<color_t>& colors);

    void load_tangents(const std::vector<math::vector3f>& tangents);

    void bind_vertices_attrib(int32 index);
    void bind_texture_attrib(int32 index);

    uint32 vertex_array_id() const;

    friend void swap(mesh&, mesh&);

private:
    uint32 m_vertex_array_id = 0;

    uint32 m_buffer_ids[6] = {0, 0, 0, 0, 0, 0};
    uint32 m_type_sizes[6] = {0, 0, 0, 0, 0, 0};
};

void swap(mesh& a, mesh& b);

/// @}

} // namespace framework::opengl

#endif