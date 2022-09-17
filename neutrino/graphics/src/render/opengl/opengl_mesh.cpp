#include <numeric>
#include <stdexcept>

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

std::size_t get_data_size(Attribute attrib, const Mesh& mesh)
{
    switch (attrib) {
        case Attribute::position: return mesh.vertices().size();
        case Attribute::normal: return mesh.normals().size();
        case Attribute::tangent: return mesh.tangents().size();
        case Attribute::color: return mesh.colors().size();
        case Attribute::texcoord0: return mesh.texture_coordinates(0).size();
        case Attribute::texcoord1: return mesh.texture_coordinates(1).size();
        case Attribute::texcoord2: return mesh.texture_coordinates(2).size();
        case Attribute::texcoord3: return mesh.texture_coordinates(3).size();
        case Attribute::texcoord4: return mesh.texture_coordinates(4).size();
        case Attribute::texcoord5: return mesh.texture_coordinates(5).size();
        case Attribute::texcoord6: return mesh.texture_coordinates(6).size();
        case Attribute::texcoord7: return mesh.texture_coordinates(7).size();
    }

    return 0;
}

GLenum get_data_type(Attribute attrib)
{
    static_assert(std::is_same_v<Mesh::VertexData::value_type, framework::math::Vector3f>,
                  "Type of vertex data is changed, update vertex data processing.");

    static_assert(std::is_same_v<Mesh::TextureCoordinatesData::value_type, framework::math::Vector2f>,
                  "Type of vertex data is changed, update vertex data processing.");

    static_assert(sizeof(Mesh::ColorData::value_type) == 4,
                  "Type of color data is changed, update color data processing.");

    switch (attrib) {
        case Attribute::position: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::normal: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::tangent: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::color: return static_cast<GLenum>(GL_UNSIGNED_BYTE);
        case Attribute::texcoord0: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord1: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord2: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord3: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord4: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord5: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord6: return static_cast<GLenum>(GL_FLOAT);
        case Attribute::texcoord7: return static_cast<GLenum>(GL_FLOAT);
    }

    return 0;
}

int get_component_size(Attribute attrib)
{
    static_assert(std::is_same_v<Mesh::VertexData::value_type, framework::math::Vector3f>,
                  "Type of vertex data is changed, update vertex data processing.");

    static_assert(std::is_same_v<Mesh::TextureCoordinatesData::value_type, framework::math::Vector2f>,
                  "Type of texure coordinates data is changed, update texure coordinates  data processing.");

    static_assert(sizeof(Mesh::ColorData::value_type) == 4,
                  "Type of color data is changed, update color data processing.");

    switch (attrib) {
        case Attribute::position: return Mesh::VertexData::value_type::components_count;
        case Attribute::normal: return Mesh::VertexData::value_type::components_count;
        case Attribute::tangent: return Mesh::VertexData::value_type::components_count;
        case Attribute::color: return 4;
        case Attribute::texcoord0: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord1: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord2: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord3: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord4: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord5: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord6: return Mesh::TextureCoordinatesData::value_type::components_count;
        case Attribute::texcoord7: return Mesh::TextureCoordinatesData::value_type::components_count;
    }

    return 0;
}

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
void load_data_buffer(GLuint buffer, GLenum buffer_type, const std::vector<T>& data)
{
    if (buffer == 0 || data.empty() || data.size() > max_size) {
        return;
    }

    const GLsizeiptr data_size = static_cast<GLsizeiptr>(data.size() * sizeof(T));

    glBindBuffer(buffer_type, buffer);
    glBufferData(buffer_type, data_size, data.data(), GL_DYNAMIC_DRAW);
    glBindBuffer(buffer_type, 0);
}

void load_index_buffer(GLuint buffer, GLenum buffer_type, const Mesh::SubMeshMap& submeshes)
{
    if (submeshes.empty()) {
        return;
    }

    const std::size_t data_size = std::accumulate(submeshes.begin(),
                                                  submeshes.end(),
                                                  std::size_t(0),
                                                  [](std::size_t acc, const auto& submesh) {
                                                      return acc + submesh.second.indices.size() *
                                                                   sizeof(Mesh::IndicesData::value_type);
                                                  });

    glBindBuffer(buffer_type, buffer);
    glBufferData(buffer_type, static_cast<GLsizeiptr>(data_size), nullptr, GL_DYNAMIC_DRAW);

    GLintptr offset = 0;
    for (const auto& [_, submesh] : submeshes) {
        GLsizeiptr size = static_cast<GLsizeiptr>(submesh.indices.size() * sizeof(Mesh::IndicesData::value_type));
        glBufferSubData(buffer_type, offset, size, submesh.indices.data());
        offset += size;
    }

    glBindBuffer(buffer_type, 0);
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

    if (m_vertex_array == 0) {
        glGenVertexArrays(1, &m_vertex_array);
    }

    if (m_vertex_array == 0) {
        clear();
        return false;
    }

    glBindVertexArray(m_vertex_array);

    for (const auto& attrib : attributes_list) {
        const auto index = static_cast<std::size_t>(attrib);
        const auto size  = get_data_size(attrib, mesh);

        if (size == 0 || size >= max_size) {
            continue;
        }

        if (m_vertex_buffers[index].buffer == 0) {
            glGenBuffers(1, &m_vertex_buffers[index].buffer);
        }

        if (m_vertex_buffers[index].buffer == 0) {
            clear();
            return false;
        }

        m_vertex_buffers[index].type           = get_data_type(attrib);
        m_vertex_buffers[index].component_size = get_component_size(attrib);
    }

    // clang-format off
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::position)].buffer,  GL_ARRAY_BUFFER, mesh.vertices());
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::normal)].buffer,    GL_ARRAY_BUFFER, mesh.normals());
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::tangent)].buffer,   GL_ARRAY_BUFFER, mesh.tangents());
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::color)].buffer,     GL_ARRAY_BUFFER, mesh.colors());
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord0)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(0));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord1)].buffer,  GL_ARRAY_BUFFER, mesh.texture_coordinates(1));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord2)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(2));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord3)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(3));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord4)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(4));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord5)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(5));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord6)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(6));
    load_data_buffer(m_vertex_buffers[static_cast<std::size_t>(Attribute::texcoord7)].buffer, GL_ARRAY_BUFFER, mesh.texture_coordinates(7));
    // clang-format on

    if (m_index_buffer.buffer == 0) {
        glGenBuffers(1, &m_index_buffer.buffer);
    }

    if (m_index_buffer.buffer == 0) {
        clear();
        return false;
    }

    m_index_buffer.submeshes.clear();
    m_index_buffer.submeshes.reserve(mesh.submeshes().size());
    for (const auto& [_, submesh] : mesh.submeshes()) {
        m_index_buffer.submeshes.push_back(
        {static_cast<GLsizei>(submesh.indices.size()), get_opengl_primitive_type(submesh.primitive_type)});
    }

    static_assert(std::is_same_v<std::uint32_t, Mesh::IndicesData::value_type>,
                  "Type of indices is changed, update the type field below.");

    m_index_buffer.type = static_cast<GLenum>(GL_UNSIGNED_INT);

    load_index_buffer(m_index_buffer.buffer, GL_ELEMENT_ARRAY_BUFFER, mesh.submeshes());

    glBindVertexArray(0);

    return is_valid();
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

bool OpenglMesh::is_valid() const
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
