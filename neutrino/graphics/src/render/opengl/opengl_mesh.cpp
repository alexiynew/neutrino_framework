#include <numeric>

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

constexpr std::size_t max_size = std::numeric_limits<Mesh::IndicesData::value_type>::max();

GLenum get_opengl_primitive_type(Mesh::PrimitiveType type)
{
    switch (type) {
        case Mesh::PrimitiveType::points: return GL_POINTS;
        case Mesh::PrimitiveType::lines: return GL_LINES;
        case Mesh::PrimitiveType::line_strip: return GL_LINE_STRIP;
        case Mesh::PrimitiveType::line_loop: return GL_LINE_LOOP;
        case Mesh::PrimitiveType::triangles: return GL_TRIANGLES;
        case Mesh::PrimitiveType::triangle_strip: return GL_TRIANGLE_STRIP;
        case Mesh::PrimitiveType::triangle_fan: return GL_TRIANGLE_FAN;
    }

    throw std::runtime_error("Unreachable");
}

template <typename T>
OpenglMesh::VertexBufferInfo create_vertex_buffer(GLenum buffer_type, const std::vector<T>& data)
{
    if (data.empty() || data.size() >= max_size) {
        return OpenglMesh::VertexBufferInfo();
    }

    const GLsizeiptr data_size = static_cast<GLsizeiptr>(data.size() * sizeof(T));

    OpenglMesh::VertexBufferInfo info;

    glGenBuffers(1, &info.buffer);

    glBindBuffer(buffer_type, info.buffer);
    glBufferData(buffer_type, data_size, data.data(), GL_STATIC_DRAW);
    glBindBuffer(buffer_type, 0);

    if constexpr (std::is_same_v<T, Mesh::VertexData::value_type>) {
        info.type             = static_cast<GLenum>(GL_FLOAT);
        info.component_size   = T::components_count;
        info.components_count = static_cast<int>(data.size());
    } else if constexpr (std::is_same_v<T, Mesh::TextureCoordinatesData::value_type>) {
        info.type             = static_cast<GLenum>(GL_FLOAT);
        info.component_size   = T::components_count;
        info.components_count = static_cast<int>(data.size());
    } else if constexpr (std::is_same_v<T, Mesh::ColorData::value_type>) {
        info.type             = static_cast<GLenum>(GL_UNSIGNED_BYTE);
        info.component_size   = 4;
        info.components_count = static_cast<int>(data.size());
    }

    return info;
}

OpenglMesh::IndexBufferInfo create_index_buffer(GLenum buffer_type, const Mesh::SubMeshMap& submeshes)
{
    if (submeshes.empty()) {
        return OpenglMesh::IndexBufferInfo();
    }

    const std::size_t data_size = std::accumulate(submeshes.begin(),
                                                  submeshes.end(),
                                                  std::size_t(0),
                                                  [](std::size_t acc, const auto& submesh) {
                                                      return acc + submesh.second.indices.size() *
                                                                   sizeof(Mesh::IndicesData::value_type);
                                                  });

    OpenglMesh::IndexBufferInfo info;

    glGenBuffers(1, &info.buffer);

    glBindBuffer(buffer_type, info.buffer);
    glBufferData(buffer_type, static_cast<GLsizeiptr>(data_size), nullptr, GL_STATIC_DRAW);

    GLintptr offset = 0;
    for (const auto& [_, submesh] : submeshes) {
        GLsizeiptr size = static_cast<GLsizeiptr>(submesh.indices.size() * sizeof(Mesh::IndicesData::value_type));
        glBufferSubData(buffer_type, offset, size, submesh.indices.data());
        offset += size;
        info.submeshes.push_back(
        {static_cast<GLsizei>(submesh.indices.size()), get_opengl_primitive_type(submesh.primitive_type)});
    }

    glBindBuffer(buffer_type, 0);

    static_assert(std::is_same_v<std::uint32_t, Mesh::IndicesData::value_type>,
                  "Type of indices is changed, update the type field below.");

    info.type = static_cast<GLenum>(GL_UNSIGNED_INT);

    return info;
}

} // namespace

namespace framework::graphics
{
OpenglMesh::~OpenglMesh()
{
    clear();
}

void OpenglMesh::clear()
{
    for (VertexBufferInfo& info : m_vertex_buffers) {
        glDeleteBuffers(1, &info.buffer);
        info.buffer = 0;
    }

    glDeleteBuffers(1, &m_index_buffer.buffer);
    m_index_buffer.buffer = 0;
    m_index_buffer.submeshes.clear();

    glDeleteVertexArrays(1, &m_vertex_array);
    m_vertex_array = 0;
}

bool OpenglMesh::load(const Mesh& mesh)
{
    if (mesh.submeshes().empty()) {
        throw std::runtime_error("Can't load mesh without indices.");
    }

    glGenVertexArrays(1, &m_vertex_array);
    glBindVertexArray(m_vertex_array);

    // clang-format off
    m_vertex_buffers[static_cast<std::size_t>(Attribute::position)]  = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.vertices());
    m_vertex_buffers[static_cast<std::size_t>(Attribute::normal)]    = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.normals());
    m_vertex_buffers[static_cast<std::size_t>(Attribute::tangent)]   = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.tangents());
    m_vertex_buffers[static_cast<std::size_t>(Attribute::color)]     = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.colors());
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord0)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(0));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord1)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(1));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord2)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(2));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord3)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(3));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord4)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(4));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord5)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(5));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord6)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(6));
    m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord7)] = create_vertex_buffer(GL_ARRAY_BUFFER, mesh.texture_coordinates(7));
    // clang-format on

    m_index_buffer = create_index_buffer(GL_ELEMENT_ARRAY_BUFFER, mesh.submeshes());

    glBindVertexArray(0);

    return valid();
}

void OpenglMesh::draw() const
{
    glBindVertexArray(m_vertex_array);

    for (const Attribute attr : attributes_list) {
        enable_attribute(attr);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer.buffer);

    std::uint8_t* offset = nullptr;
    for (const SubMeshInfo& info : m_index_buffer.submeshes) {
        glDrawElements(info.primitive_type, info.indices_count, m_index_buffer.type, offset);
        offset += info.indices_count * static_cast<int>(sizeof(Mesh::IndicesData::value_type));
    }
}

bool OpenglMesh::valid() const
{
    return m_vertex_array != 0 && m_index_buffer.buffer != 0 && !m_index_buffer.submeshes.empty();
}

void OpenglMesh::enable_attribute(Attribute attribute) const
{
    const GLuint attr_index      = static_cast<GLuint>(attribute);
    const VertexBufferInfo& info = m_vertex_buffers[attr_index];

    if (info.buffer == 0) {
        return;
    }

    glEnableVertexAttribArray(attr_index);
    glBindBuffer(GL_ARRAY_BUFFER, info.buffer);
    glVertexAttribPointer(attr_index, info.component_size, info.type, GL_FALSE, 0, nullptr);
}

} // namespace framework::graphics
