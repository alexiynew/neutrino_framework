
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
#include <graphics/render.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

const std::string vertex_shader =
" \
#version 330 core\n\
layout(location = 0) in vec3 vertexPosition_modelspace;\n\
void main(){\n\
    gl_Position.xyz = vertexPosition_modelspace;\n\
    gl_Position.w = 1.0;\n\
}";

const std::string fragment_shader =
" \
#version 330 core\n\
out vec3 color;\n\
void main(){\n\
  color = vec3(1,0,0);\n\
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
        {-1.0f, -1.0f, 0.0f},
        {1.0f, -1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        };

        const Mesh::IndicesData indices = {0, 1, 2};

        Window::set_application_name("GL mesh Test");

        Window main_window({640, 480}, "GL mesh test");
        Render render(main_window.context());

        main_window.show();

        render.set_clear_color(0xFF00FFFF);

        Mesh triangle;
        triangle.set_vertices(vertices);
        triangle.set_indices(indices);

        Shader shader(vertex_shader, fragment_shader);

        const float32 max_total_time = 1000;
        float32 total_time           = 0;

        render.load(triangle);
        render.load(shader);

        triangle.clear();
        shader.clear();

        while (main_window.is_visible() && total_time < max_total_time) {
            main_window.process_events();

            render.render(triangle, shader);

            render.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            total_time += 16;
        }

        TEST_FAIL("Not implemented.");
    }
};

int main()
{
    return run_tests(mesh_test());
}
