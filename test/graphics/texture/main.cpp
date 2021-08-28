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

#include <array>
#include <chrono>
#include <thread>

#include <common/utils.hpp>
#include <common/version.hpp>
#include <graphics/color.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>
#include <math/math.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;
using namespace framework::graphics;

namespace
{

const std::string vertex_shader =
"#version 330 core\n\
\n\
layout(location = 0) in vec3 position;\n\
layout(location = 3) in vec4 color;\n\
layout(location = 4) in vec2 texCoord0;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 projectionMatrix;\n\
\n\
out vec4 fragColor;\n\
out vec2 texCoord;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * modelMatrix * vec4(position, 1.0);\n\
    fragColor = color / 256.0;\n\
    texCoord = texCoord0;\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
\n\
in vec4 fragColor;\n\
in vec2 texCoord;\n\
\n\
out vec4 color;\n\
\n\
uniform sampler2D texture0;\n\
\n\
void main()\n\
{\n\
    color = texture(texture0, texCoord);\n\
}\n\
";

const std::string lena_png_32   = "texture_img/lena_32.png";
const std::string lena_png_1024 = "texture_img/lena_1024.png";

Image load_image(const std::string& file)
{
    Image img;
    if (!img.load(file)) {
        throw std::runtime_error(std::string("Can't load image: ") + file);
    }

    return img;
}

const Image& lena_32()
{
    static Image img = load_image(lena_png_32);

    return img;
}

const Image& lena_1024()
{
    static Image img = load_image(lena_png_1024);

    return img;
}

namespace square_mesh
{

const Mesh::VertexData vertices = {{-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}, {0.5, 0.5, 0.0}, {-0.5, 0.5, 0.0}};
const Mesh::ColorData colors    = {{0.7f, 0.1f, 0.1f}, {0.8f, 0.2f, 0.1f}, {0.9f, 0.3f, 0.1f}, {1.0f, 0.4f, 0.1f}};
const Mesh::TextureCoordinatesData tex_coord_x1 = {{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}};
const Mesh::TextureCoordinatesData tex_coord_x4 = {{0.0, 0.0}, {4.0, 0.0}, {4.0, 4.0}, {0.0, 4.0}};
Mesh::IndicesData indices                       = {0, 1, 2, 0, 2, 3};

} // namespace square_mesh

using MeshPtr    = std::unique_ptr<Mesh>;
using ShaderPtr  = std::unique_ptr<Shader>;
using TexturePtr = std::unique_ptr<Texture>;

struct Entity
{
    MeshPtr mesh;
    ShaderPtr shader;
    TexturePtr texture;
    Vector3f position;
};

TexturePtr create_texture(const Image& image)
{

    TexturePtr t = std::make_unique<Texture>();
    t->set_image(image);

    return t;
}

ShaderPtr create_shader()
{
    ShaderPtr s = std::make_unique<Shader>();

    s->set_vertex_source(vertex_shader);
    s->set_fragment_source(fragment_shader);

    return s;
}

MeshPtr create_mesh(int width, int height, const Mesh::TextureCoordinatesData tex_coord)
{
    Mesh::VertexData scaled_vertices;
    std::transform(square_mesh::vertices.begin(),
                   square_mesh::vertices.end(),
                   std::back_insert_iterator<Mesh::VertexData>(scaled_vertices),
                   [width, height](const Mesh::VertexData::value_type& v) {
                       return Vector3f{v.x * width, v.y * height, v.z};
                   });

    MeshPtr m = std::make_unique<Mesh>();
    m->set_vertices(scaled_vertices);
    m->set_texture_coordinates(0, tex_coord);
    m->set_indices(square_mesh::indices);

    return m;
}

Entity create_entity_1()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_32()),
                  {128, -128, 0}};

    entity.texture->set_mag_filter(MagFilter::nearest);
    return entity;
}

Entity create_entity_2()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_32()),
                  {128 + 256, -128, 0}};

    entity.texture->set_mag_filter(MagFilter::linear);
    return entity;
}

Entity create_entity_3()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_1024()),
                  {128 + 256 * 2, -128, 0}};

    entity.texture->set_min_filter(MinFilter::nearest);
    return entity;
}

Entity create_entity_4()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_1024()),
                  {128 + 256 * 3, -128, 0}};

    entity.texture->set_min_filter(MinFilter::linear);
    return entity;
}

Entity create_entity_5()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_1024()),
                  {128, -128 - 256, 0}};

    entity.texture->set_min_filter(MinFilter::nearest_mipmap_nearest);
    return entity;
}

Entity create_entity_6()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_1024()),
                  {128 + 256, -128 - 256, 0}};

    entity.texture->set_min_filter(MinFilter::nearest_mipmap_linear);
    return entity;
}

Entity create_entity_7()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_1024()),
                  {128 + 256 * 2, -128 - 256, 0}};

    entity.texture->set_min_filter(MinFilter::linear_mipmap_nearest);
    return entity;
}

Entity create_entity_8()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x1),
                  create_shader(),
                  create_texture(lena_1024()),
                  {128 + 256 * 3, -128 - 256, 0}};

    entity.texture->set_min_filter(MinFilter::linear_mipmap_linear);
    return entity;
}

Entity create_entity_9()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x4),
                  create_shader(),
                  create_texture(lena_32()),
                  {128, -128 - 256 - 256, 0}};

    entity.texture->set_wrap_s_parameter(Wrap::repeat);
    entity.texture->set_wrap_t_parameter(Wrap::repeat);
    return entity;
}

Entity create_entity_10()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x4),
                  create_shader(),
                  create_texture(lena_32()),
                  {128 + 256, -128 - 256 - 256, 0}};

    entity.texture->set_wrap_s_parameter(Wrap::mirrored_repeat);
    entity.texture->set_wrap_t_parameter(Wrap::mirrored_repeat);
    return entity;
}

Entity create_entity_11()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x4),
                  create_shader(),
                  create_texture(lena_32()),
                  {128 + 256 * 2, -128 - 256 - 256, 0}};

    entity.texture->set_wrap_s_parameter(Wrap::clamp_to_edge);
    entity.texture->set_wrap_t_parameter(Wrap::clamp_to_edge);
    return entity;
}

Entity create_entity_12()
{
    Entity entity{create_mesh(250, 250, square_mesh::tex_coord_x4),
                  create_shader(),
                  create_texture(lena_32()),
                  {128 + 256 * 3, -128 - 256 - 256, 0}};

    entity.texture->set_border_color(Color(0xCC8822FFu));
    entity.texture->set_wrap_s_parameter(Wrap::clamp_to_border);
    entity.texture->set_wrap_t_parameter(Wrap::clamp_to_border);
    return entity;
}
} // namespace

class TextureTest : public framework::unit_test::Suite
{
public:
    TextureTest()
        : Suite("TextureTest")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        using namespace framework;
        using namespace framework::graphics;
        using namespace framework::system;

        Window::set_application_name("GL shader Test");

        Window main_window(name(), {256 * 4, 256 * 3});
        Renderer renderer(main_window);

        renderer.set_clear_color(Color(0xFF00FFFF));
        main_window.on_resize.connect([&renderer](const Window&, Size size) {
            renderer.set_uniform("projectionMatrix",
                                 ortho2d<float>(0, static_cast<float>(size.width), -static_cast<float>(size.height), 0));
        });

        main_window.show();

        std::array<Entity, 12> entities = {create_entity_1(),
                                           create_entity_2(),
                                           create_entity_3(),
                                           create_entity_4(),
                                           create_entity_5(),
                                           create_entity_6(),
                                           create_entity_7(),
                                           create_entity_8(),
                                           create_entity_9(),
                                           create_entity_10(),
                                           create_entity_11(),
                                           create_entity_12()};

        for (Entity& entity : entities) {
            TEST_ASSERT(renderer.load(*entity.mesh), "Can't load mesh.");
            TEST_ASSERT(renderer.load(*entity.shader), "Can't load shader.");
            TEST_ASSERT(renderer.load(*entity.texture), "Can't load texture.");

            entity.mesh->clear();
            entity.shader->clear();
            entity.texture->clear();
            TEST_ASSERT(entity.texture->image().data() == nullptr, "Texture shuld be empty.");
        }

        std::chrono::microseconds max_total_time = std::chrono::seconds(3);
        std::chrono::microseconds total_time(0);

        while (!main_window.should_close() && total_time < max_total_time) {
            main_window.process_events();

            for (Entity& entity : entities) {
                Matrix4f transform = translate(Matrix4f(), entity.position);
                renderer.render(*entity.mesh,
                                *entity.shader,
                                {Uniform{"texture0", *entity.texture}, Uniform{"modelMatrix", transform}});
            }

            renderer.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            total_time += std::chrono::milliseconds(20);
        }
    }
};

int main()
{
    return run_tests(TextureTest());
}
