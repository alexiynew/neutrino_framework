
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

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <graphics/image.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <math/math.hpp>
#include <system/window.hpp>

namespace
{

using namespace framework;
using namespace framework::math;
using namespace framework::graphics;
using namespace framework::system;

const std::string vertex_shader =
"#version 330 core\n\
\n\
layout(location = 0) in vec3 position;\n\
layout(location = 4) in vec2 texCoord0;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 viewMatrix;\n\
uniform mat4 projectionMatrix;\n\
\n\
out vec2 texCoord;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n\
    texCoord = texCoord0;\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
\n\
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

enum class Mode
{
    bmp,
    png,
};

namespace images
{
const std::vector<std::vector<std::string>> bmp_names = {{
                                                         "./bmp/good/pal1.bmp",
                                                         "./bmp/good/pal1bg.bmp",
                                                         "./bmp/good/pal1wb.bmp",
                                                         "./bmp/good/pal4.bmp",
                                                         "./bmp/good/pal4gs.bmp",
                                                         "./bmp/good/pal4rle.bmp",
                                                         "./bmp/good/pal8.bmp",
                                                         "./bmp/good/pal8-0.bmp",
                                                         "./bmp/good/pal8gs.bmp",
                                                         "./bmp/good/pal8nonsquare.bmp",
                                                         "./bmp/good/pal8os2.bmp",
                                                         "./bmp/good/pal8rle.bmp",
                                                         "./bmp/good/pal8topdown.bmp",
                                                         "./bmp/good/pal8v4.bmp",
                                                         "./bmp/good/pal8v5.bmp",
                                                         "./bmp/good/pal8w124.bmp",
                                                         "./bmp/good/pal8w125.bmp",
                                                         "./bmp/good/pal8w126.bmp",
                                                         },
                                                         {
                                                         "./bmp/good/rgb16.bmp",
                                                         "./bmp/good/rgb16-565.bmp",
                                                         "./bmp/good/rgb16-565pal.bmp",
                                                         "./bmp/good/rgb16bfdef.bmp",
                                                         },
                                                         {
                                                         "./bmp/good/rgb24.bmp",
                                                         "./bmp/good/rgb24pal.bmp",
                                                         },
                                                         {
                                                         "./bmp/good/rgb32.bmp",
                                                         "./bmp/good/rgb32bf.bmp",
                                                         "./bmp/good/rgb32bfdef.bmp",
                                                         },
                                                         {
                                                         "./bmp/questionable/pal1p1.bmp",
                                                         "./bmp/questionable/pal2.bmp",
                                                         "./bmp/questionable/pal2color.bmp",
                                                         "./bmp/questionable/pal4rlecut.bmp",
                                                         "./bmp/questionable/pal4rletrns.bmp",
                                                         "./bmp/questionable/pal8offs.bmp",
                                                         "./bmp/questionable/pal8os2-hs.bmp",
                                                         "./bmp/questionable/pal8os2-sz.bmp",
                                                         "./bmp/questionable/pal8os2sp.bmp",
                                                         "./bmp/questionable/pal8os2v2-16.bmp",
                                                         "./bmp/questionable/pal8os2v2-40sz.bmp",
                                                         "./bmp/questionable/pal8os2v2-sz.bmp",
                                                         "./bmp/questionable/pal8os2v2.bmp",
                                                         "./bmp/questionable/pal8oversizepal.bmp",
                                                         "./bmp/questionable/pal8rlecut.bmp",
                                                         "./bmp/questionable/pal8rletrns.bmp",
                                                         },
                                                         {
                                                         "./bmp/questionable/rgb16-231.bmp",
                                                         "./bmp/questionable/rgb16-3103.bmp",
                                                         "./bmp/questionable/rgb16faketrns.bmp",
                                                         "./bmp/questionable/rgba16-4444.bmp",
                                                         "./bmp/questionable/rgba16-1924.bmp",
                                                         "./bmp/questionable/rgba16-5551.bmp",
                                                         },
                                                         {
                                                         "./bmp/questionable/rgb24largepal.bmp",
                                                         },
                                                         {
                                                         "./bmp/questionable/rgb32-111110.bmp",
                                                         "./bmp/questionable/rgb32-7187.bmp",
                                                         "./bmp/questionable/rgb32-xbgr.bmp",
                                                         "./bmp/questionable/rgb32fakealpha.bmp",
                                                         "./bmp/questionable/rgb32h52.bmp",
                                                         "./bmp/questionable/rgba32-1010102.bmp",
                                                         "./bmp/questionable/rgba32-61754.bmp",
                                                         "./bmp/questionable/rgba32-81284.bmp",
                                                         "./bmp/questionable/rgba32.bmp",
                                                         "./bmp/questionable/rgba32abf.bmp",
                                                         "./bmp/questionable/rgba32h56.bmp",
                                                         }};

const std::vector<std::vector<std::string>> png_names =
{{
 "png/basi0g01.png",
 "png/basi0g02.png",
 "png/basi0g04.png",
 "png/basi0g08.png",
 "png/basi0g16.png",
 "png/basi2c08.png",
 "png/basi2c16.png",
 },
 {
 "png/basi3p01.png",
 "png/basi3p02.png",
 "png/basi3p04.png",
 "png/basi3p08.png",
 },
 {
 "png/basi4a08.png",
 "png/basi4a16.png",
 "png/basi6a08.png",
 "png/basi6a16.png",
 },
 {
 "png/basn0g01.png",
 "png/basn0g02.png",
 "png/basn0g04.png",
 "png/basn0g08.png",
 "png/basn0g16.png",
 "png/basn2c08.png",
 "png/basn2c16.png",
 },
 {
 "png/basn3p01.png",
 "png/basn3p02.png",
 "png/basn3p04.png",
 "png/basn3p08.png",
 },
 {
 "png/basn4a08.png",
 "png/basn4a16.png",
 "png/basn6a08.png",
 "png/basn6a16.png",
 },
 {
 "png/bgai4a08.png",
 "png/bgai4a16.png",
 "png/bgan6a08.png",
 "png/bgan6a16.png",
 "png/bgbn4a08.png",
 "png/bggn4a16.png",
 "png/bgwn6a08.png",
 "png/bgyn6a16.png",
 },
 {
 "png/ccwn2c08.png", "png/ccwn3p08.png", "png/cdfn2c08.png", "png/cdhn2c08.png", "png/cdsn2c08.png", "png/cdun2c08.png",
 "png/ch1n3p04.png", "png/ch2n3p08.png", "png/cm0n0g04.png", "png/cm7n0g04.png", "png/cm9n0g04.png", "png/cs3n2c16.png",
 "png/cs3n3p08.png", "png/cs5n2c08.png", "png/cs5n3p08.png", "png/cs8n2c08.png", "png/cs8n3p08.png", "png/ct0n0g04.png",
 "png/ct1n0g04.png", "png/cten0g04.png", "png/ctfn0g04.png", "png/ctgn0g04.png", "png/cthn0g04.png", "png/ctjn0g04.png",
 "png/ctzn0g04.png", "png/exif2c08.png",
 },
 {
 "png/f00n0g08.png",
 "png/f00n2c08.png",
 "png/f01n0g08.png",
 "png/f01n2c08.png",
 "png/f02n0g08.png",
 "png/f02n2c08.png",
 "png/f03n0g08.png",
 "png/f03n2c08.png",
 "png/f04n0g08.png",
 "png/f04n2c08.png",
 "png/f99n0g04.png",
 },
 {
 "png/g03n0g16.png",
 "png/g04n0g16.png",
 "png/g05n0g16.png",
 "png/g07n0g16.png",
 "png/g10n0g16.png",
 "png/g25n0g16.png",
 "png/g03n2c08.png",
 "png/g04n2c08.png",
 "png/g05n2c08.png",
 "png/g07n2c08.png",
 "png/g10n2c08.png",
 "png/g25n2c08.png",
 "png/g03n3p04.png",
 "png/g04n3p04.png",
 "png/g05n3p04.png",
 "png/g07n3p04.png",
 "png/g10n3p04.png",
 "png/g25n3p04.png",
 },
 {
 "png/oi1n0g16.png",
 "png/oi1n2c16.png",
 "png/oi2n0g16.png",
 "png/oi2n2c16.png",
 "png/oi4n0g16.png",
 "png/oi4n2c16.png",
 "png/oi9n0g16.png",
 "png/oi9n2c16.png",
 },
 {
 "png/pp0n2c16.png",
 "png/pp0n6a08.png",
 "png/ps1n0g08.png",
 "png/ps1n2c16.png",
 "png/ps2n0g08.png",
 "png/ps2n2c16.png",
 },
 {
 "png/s01i3p01.png", "png/s01n3p01.png", "png/s02i3p01.png", "png/s02n3p01.png", "png/s03i3p01.png", "png/s03n3p01.png",
 "png/s04i3p01.png", "png/s04n3p01.png", "png/s05i3p02.png", "png/s05n3p02.png", "png/s06i3p02.png", "png/s06n3p02.png",
 "png/s07i3p02.png", "png/s07n3p02.png", "png/s08i3p02.png", "png/s08n3p02.png", "png/s09i3p02.png", "png/s09n3p02.png",
 "png/s32i3p04.png", "png/s32n3p04.png", "png/s33i3p04.png", "png/s33n3p04.png", "png/s34i3p04.png", "png/s34n3p04.png",
 "png/s35i3p04.png", "png/s35n3p04.png", "png/s36i3p04.png", "png/s36n3p04.png", "png/s37i3p04.png", "png/s37n3p04.png",
 "png/s38i3p04.png", "png/s38n3p04.png", "png/s39i3p04.png", "png/s39n3p04.png", "png/s40i3p04.png", "png/s40n3p04.png",
 },
 {
 "png/tbbn0g04.png",
 "png/tbbn2c16.png",
 "png/tbbn3p08.png",
 "png/tbgn2c16.png",
 "png/tbgn3p08.png",
 "png/tbrn2c08.png",
 "png/tbwn0g16.png",
 "png/tbwn3p08.png",
 "png/tbyn3p08.png",
 "png/tm3n3p02.png",
 "png/tp0n0g08.png",
 "png/tp0n2c08.png",
 "png/tp0n3p08.png",
 "png/tp1n3p08.png",
 },
 //{
 //"png/xc1n0g08.png",
 //"png/xc9n2c08.png",
 //"png/xcrn0g04.png",
 //"png/xcsn0g01.png",
 //"png/xd0n2c08.png",
 //"png/xd3n2c08.png",
 //"png/xd9n2c08.png",
 //"png/xdtn0g01.png",
 //"png/xhdn0g08.png",
 //"png/xlfn0g04.png",
 //"png/xs1n0g01.png",
 //"png/xs2n0g01.png",
 //"png/xs4n0g01.png",
 //"png/xs7n0g01.png",
 // },
 {
 "png/z00n2c08.png",
 "png/z03n2c08.png",
 "png/z06n2c08.png",
 "png/z09n2c08.png",
 }};
} // namespace images

namespace square_mesh
{

const Mesh::VertexData vertices              = {{-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}, {0.5, 0.5, 0.0}, {-0.5, 0.5, 0.0}};
const Mesh::TextureCoordinatesData tex_coord = {{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}};
Mesh::IndicesData indices                    = {0, 1, 2, 0, 2, 3};

} // namespace square_mesh

using MeshPtr    = std::unique_ptr<Mesh>;
using TexturePtr = std::unique_ptr<Texture>;
using ShaderPtr  = std::unique_ptr<Shader>;

struct Object
{
    int width   = 0;
    int height  = 0;
    int x       = 0;
    int y       = 0;
    float gamma = 2.2f;
    TexturePtr texture;
    MeshPtr mesh;
};

using ObjectsList = std::vector<std::vector<Object>>;
using ImagesList  = std::vector<std::vector<Image>>;

ImagesList load_images(Mode image_mode)
{
    ImagesList images;

    const auto& names = [](Mode m) {
        switch (m) {
            case Mode::bmp: return images::bmp_names;
            case Mode::png: return images::png_names;
        }

        return std::vector<std::vector<std::string>>();
    }(image_mode);

    std::transform(cbegin(names), cend(names), std::back_inserter(images), [](const std::vector<std::string>& group) {
        std::vector<Image> group_images;

        std::transform(group.begin(), group.end(), std::back_inserter(group_images), [](const std::string& name) {
            framework::graphics::Image img;
            if (!img.load(name)) {
                throw std::runtime_error("Can't load " + name);
            }

            return img;
        });

        return group_images;
    });

    return images;
}

MeshPtr create_mesh(int width, int height)
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
    m->set_texture_coordinates(0, square_mesh::tex_coord);
    m->set_indices(square_mesh::indices);

    return m;
}

TexturePtr create_texture(const Image& image)
{

    TexturePtr t = std::make_unique<Texture>();
    t->set_image(image);
    t->set_min_filter(MinFilter::nearest);
    t->set_mag_filter(MagFilter::nearest);

    return t;
}

ShaderPtr create_shader()
{
    ShaderPtr s = std::make_unique<Shader>();

    s->set_vertex_source(vertex_shader);
    s->set_fragment_source(fragment_shader);

    return s;
}

ObjectsList generate_objects(const ImagesList& images)
{
    ObjectsList res;

    std::transform(images.begin(), images.end(), std::back_inserter(res), [](const std::vector<Image>& group) {
        std::vector<Object> obj_group;

        std::transform(group.begin(), group.end(), std::back_inserter(obj_group), [](const Image& img) {
            int w = img.width();
            int h = img.height();
            return Object{w, h, 0, 0, img.gamma(), create_texture(img), create_mesh(w, h)};
        });

        return obj_group;
    });

    return res;
}

class Example
{
public:
    Example();

    void setup();
    void arrange();

    void run();

private:
    Mode current_mode = Mode::bmp;
    int image_scale   = 1;
    float gamma       = 0.0f;

    Vector2f position       = {0, 0};
    Vector2f drag_start_pos = {0, 0};
    bool drag               = false;

    ImagesList png_images;
    ImagesList bmp_images;

    ObjectsList png_objects;
    ObjectsList bmp_objects;

    ObjectsList* current_objects = nullptr;

    Window main_window;
    Renderer renderer;

    ShaderPtr shader;
};

Example::Example()
    : main_window({1024, 720}, "Image example")
    , renderer(main_window)
{}

void Example::setup()
{
    png_images = load_images(Mode::png);
    bmp_images = load_images(Mode::bmp);

    png_objects = generate_objects(png_images);
    bmp_objects = generate_objects(bmp_images);

    current_objects = current_mode == Mode::bmp ? &bmp_objects : &png_objects;

    renderer.set_clear_color(Color(0xFF00FFFF));
    renderer.set_uniform("viewMatrix", scale(Matrix4f(), {image_scale, image_scale, image_scale}));

    main_window.on_resize.connect([this](const Window&, Size size) {
        renderer.set_uniform("projectionMatrix",
                             ortho2d<float>(0, static_cast<float>(size.width), -static_cast<float>(size.height), 0));

        arrange();
    });

    main_window.on_key_down.connect([this](const Window&, KeyCode k, Modifiers) {
        switch (k) {
            case KeyCode::key_equal: gamma += 0.1f; break;
            case KeyCode::key_minus: gamma -= 0.1f; break;
            case KeyCode::key_1: current_mode = Mode::bmp; break;
            case KeyCode::key_2: current_mode = Mode::png; break;
            case KeyCode::key_s: image_scale = image_scale > 4 ? 1 : image_scale + 1; break;
            case KeyCode::key_0: position = {0, 0}; break;
            default: break;
        }
        gamma = framework::math::clamp(gamma, -4.0f, 4.0f);

        renderer.set_uniform("viewMatrix", scale(Matrix4f(), {image_scale, image_scale, image_scale}));

        current_objects = current_mode == Mode::bmp ? &bmp_objects : &png_objects;
        arrange();
    });

    main_window.on_button_down.connect([this](const Window&, MouseButton button, CursorPosition pos, Modifiers) {
        if (button == MouseButton::button_left) {
            drag_start_pos = Vector2f(pos.x, pos.y);
            drag           = true;
        }
    });

    main_window.on_button_up.connect([this](const Window&, MouseButton button, CursorPosition, Modifiers) {
        if (button == MouseButton::button_left) {
            drag = false;
        }
    });

    main_window.on_mouse_move.connect([this](const Window&, Position pos) {
        if (drag) {
            Vector2f mouse(pos.x, pos.y);
            Vector2f diff  = drag_start_pos - mouse;
            drag_start_pos = mouse;
            position += diff * Vector2f(-1, 1);
        }
    });

    shader = create_shader();

    renderer.load(*shader);

    for (const auto& g : png_objects) {
        for (const auto& o : g) {
            renderer.load(*o.texture.get());
            renderer.load(*o.mesh.get());
        }
    }

    for (const auto& g : bmp_objects) {
        for (const auto& o : g) {
            renderer.load(*o.texture.get());
            renderer.load(*o.mesh.get());
        }
    }
}

void Example::arrange()
{
    int height = 0;

    for (auto& group : *current_objects) {
        int width      = 0;
        int max_height = 0;

        for (auto& obj : group) {
            obj.x = width + 1;
            obj.y = height - 1;

            if (max_height < obj.height) {
                max_height = obj.height - 1;
            }

            width += obj.width + 1;
        }

        height -= max_height;
    }
}

void Example::run()
{
    main_window.show();

    while (!main_window.should_close()) {
        main_window.process_events();

        for (const auto& g : *current_objects) {
            for (const auto& o : g) {
                Matrix4f transform = translate(Matrix4f(),
                                               Vector3f(o.x, o.y, 0.0f) +
                                               Vector3f(0.5f * o.width, -0.5f * o.height, 0.0f) +
                                               Vector3f(position, 0.0f));
                renderer.render(*o.mesh, *shader, {Uniform{"texture0", *o.texture}, Uniform{"modelMatrix", transform}});
            }
        }

        renderer.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

} // namespace

int main()
{
    log::set_logger(std::make_unique<log::stream_logger>(std::cout));

    Window::set_application_name("Image example");

    Example ex;
    ex.setup();
    ex.run();

    return 0;
}
