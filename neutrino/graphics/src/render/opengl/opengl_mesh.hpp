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
    struct VertexBufferInfo
    {
        std::uint32_t buffer = 0;
        int type             = 0;
        int component_size   = 0;
        int components_count = 0;
    };

    struct SubMeshInfo
    {
        int indices_count           = 0;
        unsigned int primitive_type = 0;
    };

    struct IndexBufferInfo
    {
        std::uint32_t buffer = 0;
        int type             = 0;
        std::vector<SubMeshInfo> sub_meshes;
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

    std::uint32_t m_vertex_array = 0;
    IndexBufferInfo m_index_buffer;

    std::array<VertexBufferInfo, attributes_count> m_vertex_buffers = {};

    Mesh::PrimitiveType m_primitive_type;
};

} // namespace framework::graphics

#endif
