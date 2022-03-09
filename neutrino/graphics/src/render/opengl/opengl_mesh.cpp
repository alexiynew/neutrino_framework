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
OpenglMesh::VertexBufferInfo create_vertex_buffer(int buffer_type, const std::vector<T>& data)
{
    if (data.empty() || data.size() >= max_size) {
        return OpenglMesh::VertexBufferInfo();
    }

    const GLsizeiptr data_size = static_cast<GLsizeiptr>(data.size() * sizeof(T));

    OpenglMesh::VertexBufferInfo info;

    glGenBuffers(1, &info.buffer);

    glBindBuffer(static_cast<GLenum>(buffer_type), info.buffer);
    glBufferData(static_cast<GLenum>(buffer_type), data_size, data.data(), GL_STATIC_DRAW);
    glBindBuffer(static_cast<GLenum>(buffer_type), 0);

    if constexpr (std::is_same_v<T, Mesh::VertexData::value_type>) {
        info.type             = GL_FLOAT;
        info.component_size   = T::components_count;
        info.components_count = static_cast<int>(data.size());
    } else if constexpr (std::is_same_v<T, Mesh::TextureCoordinatesData::value_type>) {
        info.type             = GL_FLOAT;
        info.component_size   = T::components_count;
        info.components_count = static_cast<int>(data.size());
    } else if constexpr (std::is_same_v<T, Mesh::ColorData::value_type>) {
        info.type             = GL_UNSIGNED_BYTE;
        info.component_size   = 4;
        info.components_count = static_cast<int>(data.size());
    }

    return info;
}

OpenglMesh::IndexBufferInfo create_index_buffer(int buffer_type, const Mesh::SubMesh& sub_mesh)
{
    if (sub_mesh.indices.empty() || sub_mesh.indices.size() >= max_size) {
        return OpenglMesh::IndexBufferInfo();
    }

    const GLsizeiptr data_size = static_cast<GLsizeiptr>(sub_mesh.indices.size() *
                                                         sizeof(Mesh::IndicesData::value_type));

    OpenglMesh::IndexBufferInfo info;

    glGenBuffers(1, &info.buffer);

    glBindBuffer(static_cast<GLenum>(buffer_type), info.buffer);
    glBufferData(static_cast<GLenum>(buffer_type), data_size, sub_mesh.indices.data(), GL_STATIC_DRAW);
    glBindBuffer(static_cast<GLenum>(buffer_type), 0);

    static_assert(std::is_same_v<std::uint32_t, Mesh::IndicesData::value_type>,
                  "Type of indices is changed, update the type field below.");
    info.type           = GL_UNSIGNED_INT;
    info.indices_count  = static_cast<int>(sub_mesh.indices.size());
    info.primitive_type = get_opengl_primitive_type(sub_mesh.primitive_type);

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

    for (const auto& buffer_info : m_index_buffers) {
        glDeleteBuffers(1, &buffer_info.buffer);
    }

    glDeleteVertexArrays(1, &m_vertex_array);

    m_vertex_array = 0;
    m_index_buffers.clear();
}

bool OpenglMesh::load(const Mesh& mesh)
{
    if (mesh.sub_meshes().empty()) {
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

    for (const auto& [_, sub_mesh] : mesh.sub_meshes()) {
        m_index_buffers.push_back(create_index_buffer(GL_ELEMENT_ARRAY_BUFFER, sub_mesh));
    }

    glBindVertexArray(0);

    return valid();
}

void OpenglMesh::draw() const
{
    glBindVertexArray(m_vertex_array);

    for (const Attribute attr : attributes_list) {
        enable_attribute(attr);
    }

    for (const IndexBufferInfo& info : m_index_buffers) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, info.buffer);
        glDrawElements(info.primitive_type, info.indices_count, static_cast<GLenum>(info.type), nullptr);
    }
}

bool OpenglMesh::valid() const
{
    return m_vertex_array != 0 && !m_index_buffers.empty();
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
    glVertexAttribPointer(attr_index, info.component_size, static_cast<GLenum>(info.type), GL_FALSE, 0, nullptr);
}

} // namespace framework::graphics
