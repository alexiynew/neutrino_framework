
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

#include <gl/gl.hpp>
#include <graphics/image.hpp>
#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <math/math.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

const std::string vertex_shader_src = "#version 330 core\n\
layout(location = 0) in vec2 vertexPosition_modelspace;\n\
layout(location = 1) in vec2 vertexUV;\n\
uniform mat4 MVP;\n\
out vec2 UV;\n\
void main(){\n\
    gl_Position = MVP * vec4(vertexPosition_modelspace, 0.0, 1.0);\n\
    UV = vertexUV;\n\
}";

const std::string fragment_shader_src = "#version 330 core\n\
uniform sampler2D tex;\n\
out vec4 color;\n\
in vec2 UV;\n\
void main(){\n\
    color = texture(tex, UV);\n\
}";

enum mode
{
    bmp,
    png
};

const std::vector<std::string> bmp_names = {
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
"./bmp/good/rgb16.bmp",
"./bmp/good/rgb16-565.bmp",
"./bmp/good/rgb16-565pal.bmp",
"./bmp/good/rgb16bfdef.bmp",
"./bmp/good/rgb24.bmp",
"./bmp/good/rgb24pal.bmp",
"./bmp/good/rgb32.bmp",
"./bmp/good/rgb32bf.bmp",
"./bmp/good/rgb32bfdef.bmp",
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
"./bmp/questionable/rgb16-231.bmp",
"./bmp/questionable/rgb16-3103.bmp",
"./bmp/questionable/rgb16faketrns.bmp",
"./bmp/questionable/rgba16-4444.bmp",
"./bmp/questionable/rgba16-1924.bmp",
"./bmp/questionable/rgba16-5551.bmp",
"./bmp/questionable/rgb24largepal.bmp",
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
};

const std::vector<std::string> png_names = {
//"png/basi0g01.png",
//"png/basi0g02.png",
//"png/basi0g04.png",
//"png/basi0g08.png",
//"png/basi0g16.png",
//"png/basi2c08.png",
//"png/basi2c16.png",
//
//"png/basi3p01.png",
//"png/basi3p02.png",
//"png/basi3p04.png",
//"png/basi3p08.png",
//
//"png/basi4a08.png",
//"png/basi4a16.png",
//"png/basi6a08.png",
//"png/basi6a16.png",
//
//"png/basn0g01.png",
//"png/basn0g02.png",
//"png/basn0g04.png",
//"png/basn0g08.png",
//"png/basn0g16.png",
//"png/basn2c08.png",
//"png/basn2c16.png",
//
//"png/basn3p01.png",
//"png/basn3p02.png",
//"png/basn3p04.png",
//"png/basn3p08.png",
//
//"png/basn4a08.png",
//"png/basn4a16.png",
//"png/basn6a08.png",
//"png/basn6a16.png",

// test
//"png/bgai4a08.png", "png/bgai4a16.png", "png/bgan6a08.png", "png/bgan6a16.png", "png/bgbn4a08.png",
//"png/bggn4a16.png", "png/bgwn6a08.png", "png/bgyn6a16.png",

// test
//"png/ccwn2c08.png", "png/ccwn3p08.png",
//"png/cdfn2c08.png", "png/cdhn2c08.png", "png/cdsn2c08.png", "png/cdun2c08.png", "png/ch1n3p04.png",
//"png/ch2n3p08.png", "png/cm0n0g04.png", "png/cm7n0g04.png", "png/cm9n0g04.png", "png/cs3n2c16.png",
//"png/cs3n3p08.png", "png/cs5n2c08.png", "png/cs5n3p08.png", "png/cs8n2c08.png", "png/cs8n3p08.png",
//"png/ct0n0g04.png", "png/ct1n0g04.png", "png/cten0g04.png", "png/ctfn0g04.png", "png/ctgn0g04.png",
//"png/cthn0g04.png", "png/ctjn0g04.png", "png/ctzn0g04.png", "png/exif2c08.png",

//"png/f00n0g08.png",
//"png/f00n2c08.png",
//"png/f01n0g08.png",
//"png/f01n2c08.png",
//"png/f02n0g08.png",
//"png/f02n2c08.png",
//"png/f03n0g08.png",
//"png/f03n2c08.png",
//"png/f04n0g08.png",
//"png/f04n2c08.png",
//"png/f99n0g04.png",

// test
//"png/g03n0g16.png", "png/g03n2c08.png", "png/g03n3p04.png", "png/g04n0g16.png", "png/g04n2c08.png",
//"png/g04n3p04.png", "png/g05n0g16.png", "png/g05n2c08.png", "png/g05n3p04.png", "png/g07n0g16.png",
//"png/g07n2c08.png", "png/g07n3p04.png", "png/g10n0g16.png", "png/g10n2c08.png", "png/g10n3p04.png",
//"png/g25n0g16.png", "png/g25n2c08.png", "png/g25n3p04.png",

// test
//"png/oi1n0g16.png", "png/oi1n2c16.png", "png/oi2n0g16.png", "png/oi2n2c16.png", "png/oi4n0g16.png",
//"png/oi4n2c16.png", "png/oi9n0g16.png", "png/oi9n2c16.png",

// test
//"png/pp0n2c16.png", "png/pp0n6a08.png", "png/ps1n0g08.png", "png/ps1n2c16.png",
//"png/ps2n0g08.png", "png/ps2n2c16.png",

//"png/s01i3p01.png", "png/s01n3p01.png", "png/s02i3p01.png", "png/s02n3p01.png", "png/s03i3p01.png", "png/s03n3p01.png",
//"png/s04i3p01.png", "png/s04n3p01.png", "png/s05i3p02.png", "png/s05n3p02.png", "png/s06i3p02.png", "png/s06n3p02.png",
//"png/s07i3p02.png", "png/s07n3p02.png", "png/s08i3p02.png", "png/s08n3p02.png", "png/s09i3p02.png", "png/s09n3p02.png",
//"png/s32i3p04.png", "png/s32n3p04.png", "png/s33i3p04.png", "png/s33n3p04.png", "png/s34i3p04.png", "png/s34n3p04.png",
//"png/s35i3p04.png", "png/s35n3p04.png", "png/s36i3p04.png", "png/s36n3p04.png", "png/s37i3p04.png", "png/s37n3p04.png",
//"png/s38i3p04.png", "png/s38n3p04.png", "png/s39i3p04.png", "png/s39n3p04.png", "png/s40i3p04.png", "png/s40n3p04.png",

// test
//"png/tbbn0g04.png", "png/tbbn2c16.png", "png/tbbn3p08.png", "png/tbgn2c16.png", "png/tbgn3p08.png",
//"png/tbrn2c08.png", "png/tbwn0g16.png",
//"png/tbwn3p08.png", "png/tbyn3p08.png", "png/tm3n3p02.png", "png/tp0n0g08.png", "png/tp0n2c08.png",
//"png/tp0n3p08.png", "png/tp1n3p08.png",

// test
//"png/xc1n0g08.png", "png/xc9n2c08.png", "png/xcrn0g04.png", "png/xcsn0g01.png", "png/xd0n2c08.png",
//"png/xd3n2c08.png", "png/xd9n2c08.png", "png/xdtn0g01.png",
//"png/xhdn0g08.png", "png/xlfn0g04.png", "png/xs1n0g01.png", "png/xs2n0g01.png", "png/xs4n0g01.png",
//"png/xs7n0g01.png",

//"png/z00n2c08.png",
//"png/z03n2c08.png",
//"png/z06n2c08.png",
//"png/z09n2c08.png",
};

const framework::int32 image_scale = 10;

struct object
{
    framework::int32 width  = 0;
    framework::int32 height = 0;
    framework::int32 x      = 0;
    framework::int32 y      = 0;
    framework::graphics::texture texture;
    framework::graphics::mesh quad;
};

std::vector<framework::graphics::image> load_images(mode image_mode)
{
    std::vector<framework::graphics::image> images;

    const auto& names = [](mode m) {
        switch (m) {
            case mode::bmp: return bmp_names;
            case mode::png: return png_names;
        }

        return std::vector<std::string>();
    }(image_mode);

    std::transform(cbegin(names), cend(names), std::back_inserter(images), [](const std::string& name) {
        framework::graphics::image img;
        img.load(name);

        if (!img.is_bottom_up()) {
            img.flip_vertically();
        }

        return img;
    });

    return images;
}

void gl_error(const char* file, int line)
{
    using namespace framework::gl;
    GLenum err(glGetError());

    while (err != GL_NO_ERROR) {
        std::string error;

        switch (err) {
            case GL_INVALID_OPERATION: error = "INVALID_OPERATION"; break;
            case GL_INVALID_ENUM: error = "INVALID_ENUM"; break;
            case GL_INVALID_VALUE: error = "INVALID_VALUE"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
            case GL_OUT_OF_MEMORY: error = "OUT_OF_MEMORY"; break;
        }

        framework::log::error("GL") << file << ":" << line << " err: " << err << " " << error << std::endl;
        err = glGetError();
    }
}

framework::graphics::shader_program load_shader(const std::string& VertexShaderCode,
                                                const std::string& FragmentShaderCode)
{
    using namespace framework::graphics;
    using namespace framework::log;

    vertex_shader v_shader;
    fragment_shader f_shader;

    v_shader.set_source(VertexShaderCode);
    f_shader.set_source(FragmentShaderCode);

    v_shader.compile();
    f_shader.compile();

    if (!v_shader.compiled()) {
        framework::log::error("shader") << "vertex: " << v_shader.info_log() << std::endl;
    }

    if (!f_shader.compiled()) {
        framework::log::error("shader") << "fragment: " << f_shader.info_log() << std::endl;
    }

    shader_program program;

    program.arttach(v_shader);
    program.arttach(f_shader);
    program.link();

    if (!program.linked()) {
        framework::log::error("shader") << "program: " << program.info_log() << std::endl;
    }
    return program;
}

framework::graphics::mesh make_quad(framework::int32 width, framework::int32 height)
{
    using namespace framework::graphics;
    using framework::math::vector2f;

    const std::vector<vector2f> vertex_buffer_data = {
    vector2f(0.0f, 0.0f),
    vector2f(0.0f, height),
    vector2f(width, height),
    vector2f(width, 0.0f),
    };

    const std::vector<vector2f> texture_buffer_data = {
    vector2f(0.0f, 1.0f),
    vector2f(0.0f, 0.0f),
    vector2f(1.0f, 0.0f),
    vector2f(1.0f, 1.0f),
    };

    mesh m;
    m.load_vertices(vertex_buffer_data);
    m.load_texture_coord1(texture_buffer_data);

    return m;
}

std::vector<object> generate_objects(const std::vector<framework::graphics::image>& images)
{
    using namespace framework::graphics;

    std::vector<object> res;
    transform(begin(images), end(images), back_inserter(res), [](const image& img) {
        texture tex(min_filter::nearest, mag_filter::nearest, wrap_s::clamp_to_edge, wrap_t::clamp_to_edge);
        tex.load(img.width(), img.height(), img.data());

        auto quad = make_quad(img.width(), img.height());
        gl_error(__FILE__, __LINE__);

        return object{img.width(), img.height(), 0, 0, std::move(tex), std::move(quad)};
    });

    return res;
}

void arrange(std::vector<object>& objects, framework::int32 width, framework::int32 height)
{
    using framework::int32;

    width /= image_scale;
    height /= image_scale;

    int32 w          = 1;
    int32 h          = 1;
    int32 max_height = 1;
    for_each(begin(objects), end(objects), [&w, &h, &max_height, width, height](object& o) {
        if (w + o.width + 1 > width) {
            h += max_height + 1;
            w = 1;
        }

        o.x = w;
        o.y = h;

        w += o.width + 1;

        if (o.height > max_height) {
            max_height = o.height;
        }
    });
}

int main()
{
    using namespace framework::graphics;
    using namespace framework::system;
    using namespace framework::gl;
    using framework::float32;
    using framework::int32;
    using framework::uint32;
    using framework::math::matrix4f;

    framework::log::set_logger(std::make_unique<framework::log::stream_logger>(std::cout));

    // load all images
    std::vector<image> images = load_images(mode::png);

    if (images.empty()) {
        return 0;
    }

    window::set_application_name("Image example");

    window main_window({640, 480}, "Image example");
    main_window.make_current();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glViewport(0, 0, 640, 480);

    shader_program shader = load_shader(vertex_shader_src, fragment_shader_src);

    matrix4f mvp = framework::math::ortho2d<float32>(0, 640, 480, 0);
    mvp          = scale(mvp, {image_scale, image_scale, image_scale});

    std::vector<object> objects = generate_objects(images);
    arrange(objects, 640, 480);

    gl_error(__FILE__, __LINE__);

    main_window.set_on_close_callback([&main_window](const window&) { main_window.hide(); });
    main_window.set_on_size_callback(
    [&main_window, &objects, &mvp](const window&, ::framework::system::details::window_size size) {
        mvp = framework::math::ortho2d<float32>(0,
                                                static_cast<float32>(size.width),
                                                static_cast<float32>(size.height),
                                                0);
        mvp = scale(mvp, {image_scale, image_scale, image_scale});
        glViewport(0, 0, size.width, size.height);
        arrange(objects, size.width, size.height);
    });

    main_window.show();

    while (main_window.visible()) {
        main_window.process_events();

        glClearColor(0.5f, 0.2f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        for (auto& o : objects) {
            o.texture.bind();

            glBindVertexArray(o.quad.vertex_array_id());

            glEnableVertexAttribArray(0);
            o.quad.bind_vertices_attrib(0);

            glEnableVertexAttribArray(1);
            o.quad.bind_texture_attrib(1);

            shader.uniform("tex", o.texture.texture_unit());
            shader.uniform("MVP", translate(mvp, {o.x, o.y, 0}));

            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

            glBindVertexArray(0);

            o.texture.unbind();
        }

        shader.stop_using();

        main_window.swap_buffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
