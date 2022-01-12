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
