////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief OpenGL mesh.
/// @author Fedorov Alexey
/// @date 03.04.2020
////////////////////////////////////////////////////////////////////////////////

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

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_MESH_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_OPENGL_OPENGL_MESH_HPP

#include <array>
#include <cstdint>

#include <graphics/src/render/opengl/attributes.hpp>

namespace framework::graphics
{
class Mesh;

class OpenglMesh
{
public:
    struct BufferInfo
    {
        std::uint32_t buffer = 0;
        int type             = 0;
        int component_size   = 0;
        int components_count = 0;
    };

    OpenglMesh() = default;

    OpenglMesh(const OpenglMesh&) = delete;
    OpenglMesh& operator=(const OpenglMesh&) = delete;

    OpenglMesh(OpenglMesh&&) = default;
    OpenglMesh& operator=(OpenglMesh&&) = default;

    ~OpenglMesh();

    bool load(const Mesh& mesh);
    void clear();

    void draw() const;
    bool valid() const;

private:
    void enable_attribute(Attribute attribute) const;

    std::uint32_t vertex_array = 0;
    BufferInfo index_buffer;

    std::array<BufferInfo, attributes_count> vertex_buffers = {};
};

} // namespace framework::graphics

#endif
