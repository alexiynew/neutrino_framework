
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#include <chrono>
#include <thread>

#include <common/utils.hpp>
#include <common/version.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::system;

namespace
{

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
layout(location = 3) in vec4 color;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = vec4(position, 1.0);\n\
    fragColor = color / 256.0;\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
in vec4 fragColor;\n\
out vec4 color;\n\
void main(){\n\
    color = fragColor;\n\
}";

namespace cube_mesh
{
const Mesh::VertexData vertices = {
// clang-format off
        // front
        {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
        // back
        {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
        // left
        {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, 0.5, -0.5},
        // right
        {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5},
        // top
        {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}, {-0.5, 0.5, 0.5},
        // bottom
        {0.5, -0.5, 0.5}, {0.5, -0.5, -0.5}, {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5},
// clang-format on
};

const Mesh::ColorData colors = {
// clang-format off
        // front
        {0.7f, 0.1f, 0.1f}, {0.8f, 0.2f, 0.1f}, {0.9f, 0.3f, 0.1f}, {1.0f, 0.4f, 0.1f},
        // back
        {0.1f, 0.7f, 0.1f}, {0.1f, 0.8f, 0.2f}, {0.1f, 0.9f, 0.3f}, {0.1f, 1.0f, 0.4f},
        // left
        {0.1f, 0.1f, 0.7f}, {0.1f, 0.2f, 0.8f}, {0.1f, 0.3f, 0.9f}, {0.1f, 0.4f, 1.0f},
        // right
        {0.7f, 1.0f, 0.1f}, {0.8f, 0.9f, 0.1f}, {0.9f, 0.8f, 0.1f}, {1.0f, 0.7f, 0.1f},
        // top
        {0.1f, 0.7f, 1.0f}, {0.1f, 0.8f, 0.9f}, {0.1f, 0.9f, 0.8f}, {0.1f, 1.0f, 0.7f},
        // bottom
        {1.0f, 0.1f, 0.7f}, {0.9f, 0.2f, 0.8f}, {0.8f, 0.3f, 0.9f}, {0.7f, 0.4f, 1.0f},
// clang-format on
};

Mesh::IndicesData indices = {
// clang-format off
        // front
        0, 1, 2, 0, 2, 3,
        // back
        4, 7, 6, 4, 6, 5,
        // felt
        8, 9, 10, 8, 10 ,11,
        // right
        12, 15, 14, 12, 14, 13,
        // top
        16, 17, 18, 16, 18, 19,
        // bottom
        20, 23, 22, 20, 22, 21,
// clang-format on
};
} // namespace cube_mesh

namespace triangle_mesh
{
const Mesh::VertexData vertices = {{-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}};

const Mesh::ColorData colors = {{0.1f, 0.1f, 0.7f}, {0.1f, 0.2f, 0.8f}, {0.1f, 0.3f, 0.9f}, {0.1f, 0.4f, 1.0f}};

const Mesh::IndicesData indices = {0, 1, 2};
} // namespace triangle_mesh
} // namespace

class MeshTest : public unit_test::Suite
{
public:
    MeshTest()
        : Suite("MeshTest")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        Window::set_application_name("GL mesh Test");

        Window main_window(name(), {640, 480});
        Renderer renderer(main_window);

        main_window.show();

        renderer.set_clear_color(Color(0xFF00FFFF));

        Mesh mesh;
        mesh.set_vertices(cube_mesh::vertices);
        mesh.set_colors(cube_mesh::colors);
        mesh.set_indices(cube_mesh::indices);

        Shader shader;
        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);

        TEST_ASSERT(renderer.load(mesh), "Can't load mesh.");
        TEST_ASSERT(renderer.load(shader), "Can't load shader.");

        mesh.clear();
        shader.clear();

        TEST_ASSERT(mesh.vertices().empty(), "Mesh clear failed.");
        TEST_ASSERT(mesh.colors().empty(), "Mesh clear failed.");
        TEST_ASSERT(mesh.indices().empty(), "Mesh clear failed.");

        loop(main_window, renderer, mesh, shader);

        TEST_ASSERT(!renderer.load(mesh), "Can't load empty mesh.");
        loop(main_window, renderer, mesh, shader);

        mesh.set_vertices(triangle_mesh::vertices);
        mesh.set_colors(triangle_mesh::colors);
        mesh.generate_indices();
        TEST_ASSERT(mesh.indices() == triangle_mesh::indices, "Indices generation failed.");
        TEST_ASSERT(renderer.load(mesh), "Can't load mesh.");
        loop(main_window, renderer, mesh, shader);
    }

    void loop(Window& main_window, Renderer& renderer, Mesh& mesh, Shader& shader)
    {
        std::chrono::microseconds max_total_time = std::chrono::seconds(1);
        std::chrono::microseconds total_time(0);

        while (!main_window.should_close() && total_time < max_total_time) {
            main_window.process_events();

            renderer.render(mesh, shader);
            renderer.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            total_time += std::chrono::milliseconds(20);
        }
    }
};

int main()
{
    return run_tests(MeshTest());
}
