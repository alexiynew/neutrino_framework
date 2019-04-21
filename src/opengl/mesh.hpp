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

#include <common/types.hpp>
#include <math/math.hpp>

namespace framework::opengl
{
class mesh
{
public:
    mesh();
    ~mesh();

    mesh(const mesh&) = delete;
    mesh& operator=(const mesh&) = delete;

    mesh(mesh&&);
    mesh& operator=(mesh&&);

    void load(const std::vector<math::vector4f> vertices, const std::vector<math::vector2f> texture_coordinates = {});
    void load(const std::vector<math::vector3f> vertices, const std::vector<math::vector2f> texture_coordinates = {});
    void load(const std::vector<math::vector2f> vertices, const std::vector<math::vector2f> texture_coordinates = {});

    void bind_vertices_attrib(int32 index);
    void bind_texture_attrib(int32 index);

    uint32 vertex_array_id() const;

private:
    uint32 m_vertex_array_id   = 0;
    uint32 m_vertex_buffer_id  = 0;
    uint32 m_texture_buffer_id = 0;

    uint32 m_vertex_size = 0;
};

} // namespace framework::opengl

#endif
