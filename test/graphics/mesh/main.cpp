
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

#include <chrono>
#include <thread>

#include <common/utils.hpp>
#include <common/version.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
layout(location = 3) in vec4 color;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 viewMatrix;\n\
uniform mat4 projectionMatrix;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n\
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

class mesh_test : public framework::unit_test::Suite
{
public:
    mesh_test()
        : Suite("mesh_test")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        using namespace framework;
        using namespace framework::graphics;
        using namespace framework::system;

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

        Window::set_application_name("GL mesh Test");

        Window main_window({640, 480}, "GL mesh test");
        Renderer renderer(main_window.context());

        main_window.show();

        renderer.set_clear_color(0xFF00FFFF);

        Mesh cube;
        cube.set_vertices(vertices);
        cube.set_colors(colors);
        cube.set_indices(indices);

        Shader shader;
        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);

        const float max_total_time = 1000 * 10;

        float total_time = 0;
        float angle      = 0;

        renderer.load(cube);
        renderer.load(shader);

        const auto projection = math::perspective(static_cast<float>(math::radians(45.0f)),
                                                  640.0f / 480.0f,
                                                  0.01f,
                                                  6.0f);

        const auto view = math::look_at(math::Vector3f(0, 0, 3), math::Vector3f(0, 0, 0), math::Vector3f(0, 1, 0));
        renderer.set_projection(projection);
        renderer.set_view(view);

        cube.clear();
        shader.clear();

        while (!main_window.should_close() && total_time < max_total_time) {
            main_window.process_events();
            angle += 0.1f;

            math::Matrix4f model_transform = math::rotate(math::Matrix4f(),
                                                          math::normalize(math::Vector3f(1, 1, 0.5)),
                                                          math::radians(angle));
            renderer.render(cube, shader, model_transform);

            renderer.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            total_time += 1;
        }

        TEST_FAIL("Not implemented.");
    }
};

int main()
{
    return run_tests(mesh_test());
}
