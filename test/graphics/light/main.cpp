
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

namespace
{

using namespace framework::graphics;
using namespace framework::math;

namespace cube
{

const std::string vertex_shader =
"#version 330 core\n\
\n\
layout(location = 0) in vec3 position;\n\
layout(location = 1) in vec3 normal;\n\
layout(location = 3) in vec4 color;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 viewMatrix;\n\
uniform mat4 projectionMatrix;\n\
uniform mat3 normalMatrix;\n\
\n\
vec3 lightPos = vec3(1.5, 0.0, 1.0);\n\
\n\
out vec4 fragColor;\n\
out vec3 fragPosition;\n\
out vec3 fragNormal;\n\
\n\
out vec3 lightPosition;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n\
\n\
    lightPosition = vec3(viewMatrix * modelMatrix * vec4(lightPos, 1.0));\n\
\n\
    fragPosition = vec3(viewMatrix * modelMatrix * vec4(position, 1.0));\n\
    fragNormal = normalize(normalMatrix * normal);\n\
    fragColor = color / 256.0;\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
\n\
in vec4 fragColor;\n\
in vec3 fragPosition;\n\
in vec3 fragNormal;\n\
\n\
in vec3 lightPosition;\n\
\n\
out vec4 color;\n\
\n\
float ambientStrength = 0.1f;\n\
vec3 lightColor = vec3(1.0, 1.0, 1.0);\n\
\n\
\n\
float specularStrength = 0.5f;\n\
\n\
void main()\n\
{\n\
    vec3 ambient = ambientStrength * lightColor;\n\
\n\
    vec3 lightDir = normalize(lightPosition - fragPosition);\n\
    float diff = max(dot(fragNormal, lightDir), 0.0);\n\
    vec3 diffuse = diff * lightColor;\n\
\n\
    vec3 viewDir = -fragPosition;\n\
    vec3 reflectDir = reflect(-lightDir, fragNormal);\n\
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 2);\n\
    vec3 specular = specularStrength * spec * lightColor;\n\
\n\
    color = vec4(ambient + diffuse + specular, 1.0) * fragColor;\n\
}\n\
";

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

const Mesh::VertexData normals = {
// clang-format off
        // front
        {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0},
        // back
        {0.0, 0.0, -1.0}, {0.0, 0.0, -1.0}, {0.0, 0.0, -1.0}, {0.0, 0.0, -1.0},
        // left
        {-1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0},
        // right
        {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
        // top
        {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 
        // bottom
        {0.0, -1.0, 0.0}, {0.0, -1.0, 0.0}, {0.0, -1.0, 0.0}, {0.0, -1.0, 0.0},
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

} // namespace cube

namespace light_cube
{

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
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
    fragColor = vec4(1.0);\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
in vec4 fragColor;\n\
out vec4 color;\n\
void main(){\n\
    color = fragColor;\n\
}";

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

} // namespace light_cube

using MeshPtr   = std::unique_ptr<Mesh>;
using ShaderPtr = std::unique_ptr<Shader>;

struct Object
{
    MeshPtr mesh;
    ShaderPtr shader;
    Vector3f position;
};

Object create_cube()
{
    MeshPtr mesh = std::make_unique<Mesh>();
    mesh->set_vertices(cube::vertices);
    mesh->set_normals(cube::normals);
    mesh->set_colors(cube::colors);
    mesh->set_indices(cube::indices);

    ShaderPtr shader = std::make_unique<Shader>();
    shader->set_vertex_source(cube::vertex_shader);
    shader->set_fragment_source(cube::fragment_shader);

    return {std::move(mesh), std::move(shader), {0, 0, 0}};
}

Object create_light_cube()
{
    MeshPtr mesh = std::make_unique<Mesh>();
    mesh->set_vertices(light_cube::vertices);
    mesh->set_indices(light_cube::indices);

    ShaderPtr shader = std::make_unique<Shader>();
    shader->set_vertex_source(light_cube::vertex_shader);
    shader->set_fragment_source(light_cube::fragment_shader);

    return {std::move(mesh), std::move(shader), {0, 0, 0}};
}

} // namespace

class LightTest : public framework::unit_test::Suite
{
public:
    LightTest()
        : Suite("LightTest")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        using namespace framework;
        using namespace framework::graphics;
        using namespace framework::system;

        Window::set_application_name("GL light Test");

        Window main_window({640, 480}, "GL light test");
        Renderer renderer(main_window);

        main_window.show();

        renderer.set_clear_color(Color(0x000000FFu));
        renderer.set_view(math::look_at(math::Vector3f{0.0f, 0.0f, 2.0f},
                                        math::Vector3f{0.0f, 0.0f, 0.0f},
                                        math::Vector3f{0.0f, 1.0f, 0.0f}));
        renderer.set_projection(math::perspective(math::half_pi<float>, 640.0f / 480.0f, 0.001f, 10.0f));

        Object cube       = create_cube();
        Object light_cube = create_light_cube();

        TEST_ASSERT(renderer.load(*cube.mesh), "Can't load mesh.");
        TEST_ASSERT(renderer.load(*cube.shader), "Can't load shader.");

        TEST_ASSERT(renderer.load(*light_cube.mesh), "Can't load mesh.");
        TEST_ASSERT(renderer.load(*light_cube.shader), "Can't load shader.");

        cube.mesh->clear();
        cube.shader->clear();

        light_cube.mesh->clear();
        light_cube.shader->clear();

        std::chrono::microseconds max_total_time = std::chrono::seconds(30);
        std::chrono::microseconds total_time(0);

        const float angle   = 0.05f;
        const Vector3f axis = math::normalize(math::Vector3f{1.0, 1.0, 1.0});

        Matrix4f cube_rotation;

        light_cube.position = {1.5f, 0.0f, 1.0f};
        while (!main_window.should_close() && total_time < max_total_time) {
            main_window.process_events();

            cube_rotation           = rotate(cube_rotation, axis, angle);
            Matrix4f cube_transform = scale(cube_rotation, Vector3f(1, 1, 1));
            cube_transform          = translate(cube_transform, cube.position);
            renderer.render(*cube.mesh, *cube.shader, cube_transform);

            Matrix4f light_cube_transform = scale(Matrix4f(), Vector3f(0.1f, 0.1f, 0.1f));
            light_cube_transform          = translate(light_cube_transform, light_cube.position);
            renderer.render(*light_cube.mesh, *light_cube.shader, light_cube_transform);

            renderer.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            total_time += std::chrono::milliseconds(20);
        }
    }
};

int main()
{
    return run_tests(LightTest());
}
