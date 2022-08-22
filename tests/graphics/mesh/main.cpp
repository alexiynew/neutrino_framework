#include <graphics/mesh.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::graphics;

namespace
{

bool operator==(const Mesh::VertexData& a, const Mesh::VertexData& b)
{
    return std::equal(a.begin(), a.end(), b.begin());
}

bool operator==(const Mesh::ColorData& a, const Mesh::ColorData& b)
{
    return std::equal(a.begin(), a.end(), b.begin());
}

bool operator==(const Mesh::IndicesData& a, const Mesh::IndicesData& b)
{
    return std::equal(a.begin(), a.end(), b.begin());
}

bool operator==(const Mesh::TextureCoordinatesData& a, const Mesh::TextureCoordinatesData& b)
{
    return std::equal(a.begin(), a.end(), b.begin());
}

} // namespace

class MeshTest : public unit_test::Suite
{
public:
    MeshTest()
        : Suite("MeshTest")
    {
        add_test([this]() { mesh_data(); }, "mesh_data");
        add_test([this]() { mesh_copy(); }, "mesh_copy");
        add_test([this]() { mesh_move(); }, "mesh_move");
    }

private:
    void mesh_data()
    {
        const Mesh::VertexData vertices{{0.0f, 1.0f, 2.0f}};
        const Mesh::VertexData normals{{3.0f, 4.0f, 5.0f}};
        const Mesh::VertexData tangents{{6.0f, 7.0f, 8.0f}};
        const Mesh::ColorData colors{Color{0xFF00FF00u}};
        const Mesh::TextureCoordinatesData coordinates{{9.0f, 0.0f}};
        const Mesh::IndicesData indices{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

        Mesh mesh;

        mesh.set_vertices(vertices);
        mesh.set_normals(normals);
        mesh.set_tangents(tangents);
        mesh.set_colors(colors);

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            mesh.set_texture_coordinates(i, coordinates);
        }

        const Mesh::SubMeshIndexType submesh1 = mesh.add_submesh(indices, Mesh::PrimitiveType::line_loop);
        const Mesh::SubMeshIndexType submesh2 = mesh.add_submesh(indices, Mesh::PrimitiveType::line_strip);
        const Mesh::SubMeshIndexType submesh3 = mesh.add_submesh(indices, Mesh::PrimitiveType::lines);
        const Mesh::SubMeshIndexType submesh4 = mesh.add_submesh(indices, Mesh::PrimitiveType::points);
        const Mesh::SubMeshIndexType submesh5 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangle_fan);
        const Mesh::SubMeshIndexType submesh6 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangle_strip);
        const Mesh::SubMeshIndexType submesh7 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangles);

        TEST_ASSERT(mesh.vertices() == vertices, "Wrong vertices data.");
        TEST_ASSERT(mesh.normals() == normals, "Wrong normals data.");
        TEST_ASSERT(mesh.tangents() == tangents, "Wrong tangents data.");
        TEST_ASSERT(mesh.colors() == colors, "Wrong colors data.");

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(mesh.texture_coordinates(i) == coordinates, "Wrong texture_coordinates data.");
        }

        TEST_ASSERT(mesh.has_submesh(submesh1), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh1).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh1).primitive_type == Mesh::PrimitiveType::line_loop,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.has_submesh(submesh2), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh2).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh2).primitive_type == Mesh::PrimitiveType::line_strip,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.has_submesh(submesh3), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh3).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh3).primitive_type == Mesh::PrimitiveType::lines,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.has_submesh(submesh4), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh4).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh4).primitive_type == Mesh::PrimitiveType::points,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.has_submesh(submesh5), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh5).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh5).primitive_type == Mesh::PrimitiveType::triangle_fan,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.has_submesh(submesh6), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh6).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh6).primitive_type == Mesh::PrimitiveType::triangle_strip,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.has_submesh(submesh7), "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh7).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh.submeshes().at(submesh7).primitive_type == Mesh::PrimitiveType::triangles,
                    "Submesh index failure.");

        mesh.remove_submesh(submesh1);
        TEST_ASSERT(!mesh.has_submesh(submesh1), "Submesh remove failure.");

        mesh.clear();

        TEST_ASSERT(mesh.vertices().empty(), "Wrong vertices data.");
        TEST_ASSERT(mesh.normals().empty(), "Wrong normals data.");
        TEST_ASSERT(mesh.tangents().empty(), "Wrong tangents data.");
        TEST_ASSERT(mesh.colors().empty(), "Wrong colors data.");

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(mesh.texture_coordinates(i).empty(), "Wrong texture_coordinates data.");
        }

        TEST_ASSERT(mesh.submeshes().empty(), "Wrong submesh data.");
    }

    void mesh_copy()
    {
        const Mesh::VertexData vertices{{0.0f, 1.0f, 2.0f}};
        const Mesh::VertexData normals{{3.0f, 4.0f, 5.0f}};
        const Mesh::VertexData tangents{{6.0f, 7.0f, 8.0f}};
        const Mesh::ColorData colors{Color{0xFF00FF00u}};
        const Mesh::TextureCoordinatesData coordinates{{9.0f, 0.0f}};
        const Mesh::IndicesData indices{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

        Mesh mesh;

        mesh.set_vertices(vertices);
        mesh.set_normals(normals);
        mesh.set_tangents(tangents);
        mesh.set_colors(colors);

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            mesh.set_texture_coordinates(i, coordinates);
        }

        const Mesh::SubMeshIndexType submesh1 = mesh.add_submesh(indices, Mesh::PrimitiveType::line_loop);
        const Mesh::SubMeshIndexType submesh2 = mesh.add_submesh(indices, Mesh::PrimitiveType::line_strip);
        const Mesh::SubMeshIndexType submesh3 = mesh.add_submesh(indices, Mesh::PrimitiveType::lines);
        const Mesh::SubMeshIndexType submesh4 = mesh.add_submesh(indices, Mesh::PrimitiveType::points);
        const Mesh::SubMeshIndexType submesh5 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangle_fan);
        const Mesh::SubMeshIndexType submesh6 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangle_strip);
        const Mesh::SubMeshIndexType submesh7 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangles);

        // Copy
        Mesh mesh1;
        mesh1 = mesh;

        TEST_ASSERT(mesh1.vertices() == vertices, "Wrong vertices data.");
        TEST_ASSERT(mesh1.normals() == normals, "Wrong normals data.");
        TEST_ASSERT(mesh1.tangents() == tangents, "Wrong tangents data.");
        TEST_ASSERT(mesh1.colors() == colors, "Wrong colors data.");

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(mesh1.texture_coordinates(i) == coordinates, "Wrong texture_coordinates data.");
        }

        TEST_ASSERT(mesh1.has_submesh(submesh1), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh1).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh1).primitive_type == Mesh::PrimitiveType::line_loop,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh2), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh2).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh2).primitive_type == Mesh::PrimitiveType::line_strip,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh3), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh3).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh3).primitive_type == Mesh::PrimitiveType::lines,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh4), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh4).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh4).primitive_type == Mesh::PrimitiveType::points,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh5), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh5).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh5).primitive_type == Mesh::PrimitiveType::triangle_fan,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh6), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh6).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh6).primitive_type == Mesh::PrimitiveType::triangle_strip,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh7), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh7).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh7).primitive_type == Mesh::PrimitiveType::triangles,
                    "Submesh index failure.");

        mesh.remove_submesh(submesh1);
        TEST_ASSERT(mesh1.has_submesh(submesh1), "Submesh remove failure.");

        mesh.clear();

        TEST_ASSERT(!mesh1.vertices().empty(), "Wrong vertices data.");
        TEST_ASSERT(!mesh1.normals().empty(), "Wrong normals data.");
        TEST_ASSERT(!mesh1.tangents().empty(), "Wrong tangents data.");
        TEST_ASSERT(!mesh1.colors().empty(), "Wrong colors data.");

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(!mesh1.texture_coordinates(i).empty(), "Wrong texture_coordinates data.");
        }

        TEST_ASSERT(!mesh1.submeshes().empty(), "Wrong submesh data.");

        mesh1.clear();

        TEST_ASSERT(mesh1.vertices().empty(), "Wrong vertices data.");
        TEST_ASSERT(mesh1.normals().empty(), "Wrong normals data.");
        TEST_ASSERT(mesh1.tangents().empty(), "Wrong tangents data.");
        TEST_ASSERT(mesh1.colors().empty(), "Wrong colors data.");

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(mesh1.texture_coordinates(i).empty(), "Wrong texture_coordinates data.");
        }

        TEST_ASSERT(mesh1.submeshes().empty(), "Wrong submesh data.");
    }

    void mesh_move()
    {
        const Mesh::VertexData vertices{{0.0f, 1.0f, 2.0f}};
        const Mesh::VertexData normals{{3.0f, 4.0f, 5.0f}};
        const Mesh::VertexData tangents{{6.0f, 7.0f, 8.0f}};
        const Mesh::ColorData colors{Color{0xFF00FF00u}};
        const Mesh::TextureCoordinatesData coordinates{{9.0f, 0.0f}};
        const Mesh::IndicesData indices{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

        Mesh mesh;

        mesh.set_vertices(vertices);
        mesh.set_normals(normals);
        mesh.set_tangents(tangents);
        mesh.set_colors(colors);

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            mesh.set_texture_coordinates(i, coordinates);
        }

        const Mesh::SubMeshIndexType submesh1 = mesh.add_submesh(indices, Mesh::PrimitiveType::line_loop);
        const Mesh::SubMeshIndexType submesh2 = mesh.add_submesh(indices, Mesh::PrimitiveType::line_strip);
        const Mesh::SubMeshIndexType submesh3 = mesh.add_submesh(indices, Mesh::PrimitiveType::lines);
        const Mesh::SubMeshIndexType submesh4 = mesh.add_submesh(indices, Mesh::PrimitiveType::points);
        const Mesh::SubMeshIndexType submesh5 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangle_fan);
        const Mesh::SubMeshIndexType submesh6 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangle_strip);
        const Mesh::SubMeshIndexType submesh7 = mesh.add_submesh(indices, Mesh::PrimitiveType::triangles);

        // Move
        Mesh mesh1;
        mesh1 = std::move(mesh);

        TEST_ASSERT(mesh1.vertices() == vertices, "Wrong vertices data.");
        TEST_ASSERT(mesh1.normals() == normals, "Wrong normals data.");
        TEST_ASSERT(mesh1.tangents() == tangents, "Wrong tangents data.");
        TEST_ASSERT(mesh1.colors() == colors, "Wrong colors data.");

        TEST_ASSERT(mesh.vertices().empty(), "Wrong vertices data.");
        TEST_ASSERT(mesh.normals().empty(), "Wrong normals data.");
        TEST_ASSERT(mesh.tangents().empty(), "Wrong tangents data.");
        TEST_ASSERT(mesh.colors().empty(), "Wrong colors data.");

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(mesh1.texture_coordinates(i) == coordinates, "Wrong texture_coordinates data.");
        }

        for (size_t i = 0; i < Mesh::max_texture_coordinates; ++i) {
            TEST_ASSERT(mesh.texture_coordinates(i).empty(), "Wrong texture_coordinates data.");
        }

        TEST_ASSERT(mesh1.has_submesh(submesh1), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh1).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh1).primitive_type == Mesh::PrimitiveType::line_loop,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh2), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh2).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh2).primitive_type == Mesh::PrimitiveType::line_strip,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh3), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh3).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh3).primitive_type == Mesh::PrimitiveType::lines,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh4), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh4).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh4).primitive_type == Mesh::PrimitiveType::points,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh5), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh5).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh5).primitive_type == Mesh::PrimitiveType::triangle_fan,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh6), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh6).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh6).primitive_type == Mesh::PrimitiveType::triangle_strip,
                    "Submesh index failure.");

        TEST_ASSERT(mesh1.has_submesh(submesh7), "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh7).indices == indices, "Submesh index failure.");
        TEST_ASSERT(mesh1.submeshes().at(submesh7).primitive_type == Mesh::PrimitiveType::triangles,
                    "Submesh index failure.");

        TEST_ASSERT(mesh.submeshes().empty(), "Submesh index failure.");
    }
};

int main()
{
    return run_tests(MeshTest());
}
