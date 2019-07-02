
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

#include <image/image.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <math/math.hpp>
#include <opengl/gl.hpp>
#include <opengl/mesh.hpp>
#include <opengl/shader.hpp>
#include <opengl/texture.hpp>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

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
"good_pal1.bmp",
"good_pal1bg.bmp",
"good_pal1wb.bmp",
"good_pal4.bmp",
"good_pal4gs.bmp",
"good_pal4rle.bmp",
"good_pal8.bmp",
"good_pal8-0.bmp",
"good_pal8gs.bmp",
"good_pal8nonsquare.bmp",
"good_pal8os2.bmp",
"good_pal8rle.bmp",
"good_pal8topdown.bmp",
"good_pal8v4.bmp",
"good_pal8v5.bmp",
"good_pal8w124.bmp",
"good_pal8w125.bmp",
"good_pal8w126.bmp",
"good_rgb16.bmp",
"good_rgb16-565.bmp",
"good_rgb16-565pal.bmp",
"good_rgb16bfdef.bmp",
"good_rgb24.bmp",
"good_rgb24pal.bmp",
"good_rgb32.bmp",
"good_rgb32bf.bmp",
"good_rgb32bfdef.bmp",
"questionable_pal1p1.bmp",
"questionable_pal2.bmp",
"questionable_pal2color.bmp",
"questionable_pal4rlecut.bmp",
"questionable_pal4rletrns.bmp",
"questionable_pal8offs.bmp",
"questionable_pal8os2-hs.bmp",
"questionable_pal8os2-sz.bmp",
"questionable_pal8os2sp.bmp",
"questionable_pal8os2v2-16.bmp",
"questionable_pal8os2v2-40sz.bmp",
"questionable_pal8os2v2-sz.bmp",
"questionable_pal8os2v2.bmp",
"questionable_pal8oversizepal.bmp",
"questionable_pal8rlecut.bmp",
"questionable_pal8rletrns.bmp",
"questionable_rgb16-231.bmp",
"questionable_rgb16-3103.bmp",
"questionable_rgb16faketrns.bmp",
"questionable_rgba16-4444.bmp",
"questionable_rgba16-1924.bmp",
"questionable_rgba16-5551.bmp",
"questionable_rgb24largepal.bmp",
"questionable_rgb32-111110.bmp",
"questionable_rgb32-7187.bmp",
"questionable_rgb32-xbgr.bmp",
"questionable_rgb32fakealpha.bmp",
"questionable_rgb32h52.bmp",
"questionable_rgba32-1010102.bmp",
"questionable_rgba32-61754.bmp",
"questionable_rgba32-81284.bmp",
"questionable_rgba32.bmp",
"questionable_rgba32abf.bmp",
"questionable_rgba32h56.bmp",
};

const std::vector<std::string> png_names = {
"png_basi0g01.png", "png_basi0g02.png", "png_basi0g04.png", "png_basi0g08.png", "png_basi0g16.png", "png_basi2c08.png",
"png_basi2c16.png", "png_basi3p01.png", "png_basi3p02.png", "png_basi3p04.png", "png_basi3p08.png", "png_basi4a08.png",
"png_basi4a16.png", "png_basi6a08.png", "png_basi6a16.png", "png_basn0g01.png", "png_basn0g02.png", "png_basn0g04.png",
"png_basn0g08.png", "png_basn0g16.png", "png_basn2c08.png", "png_basn2c16.png", "png_basn3p01.png", "png_basn3p02.png",
"png_basn3p04.png", "png_basn3p08.png", "png_basn4a08.png", "png_basn4a16.png", "png_basn6a08.png", "png_basn6a16.png",
"png_bgai4a08.png", "png_bgai4a16.png", "png_bgan6a08.png", "png_bgan6a16.png", "png_bgbn4a08.png", "png_bggn4a16.png",
"png_bgwn6a08.png", "png_bgyn6a16.png", "png_ccwn2c08.png", "png_ccwn3p08.png", "png_cdfn2c08.png", "png_cdhn2c08.png",
"png_cdsn2c08.png", "png_cdun2c08.png", "png_ch1n3p04.png", "png_ch2n3p08.png", "png_cm0n0g04.png", "png_cm7n0g04.png",
"png_cm9n0g04.png", "png_cs3n2c16.png", "png_cs3n3p08.png", "png_cs5n2c08.png", "png_cs5n3p08.png", "png_cs8n2c08.png",
"png_cs8n3p08.png", "png_ct0n0g04.png", "png_ct1n0g04.png", "png_cten0g04.png", "png_ctfn0g04.png", "png_ctgn0g04.png",
"png_cthn0g04.png", "png_ctjn0g04.png", "png_ctzn0g04.png", "png_exif2c08.png", "png_f00n0g08.png", "png_f00n2c08.png",
"png_f01n0g08.png", "png_f01n2c08.png", "png_f02n0g08.png", "png_f02n2c08.png", "png_f03n0g08.png", "png_f03n2c08.png",
"png_f04n0g08.png", "png_f04n2c08.png", "png_f99n0g04.png", "png_g03n0g16.png", "png_g03n2c08.png", "png_g03n3p04.png",
"png_g04n0g16.png", "png_g04n2c08.png", "png_g04n3p04.png", "png_g05n0g16.png", "png_g05n2c08.png", "png_g05n3p04.png",
"png_g07n0g16.png", "png_g07n2c08.png", "png_g07n3p04.png", "png_g10n0g16.png", "png_g10n2c08.png", "png_g10n3p04.png",
"png_g25n0g16.png", "png_g25n2c08.png", "png_g25n3p04.png", "png_oi1n0g16.png", "png_oi1n2c16.png", "png_oi2n0g16.png",
"png_oi2n2c16.png", "png_oi4n0g16.png", "png_oi4n2c16.png", "png_oi9n0g16.png", "png_oi9n2c16.png", "png_pp0n2c16.png",
"png_pp0n6a08.png", "png_ps1n0g08.png", "png_ps1n2c16.png", "png_ps2n0g08.png", "png_ps2n2c16.png", "png_s01i3p01.png",
"png_s01n3p01.png", "png_s02i3p01.png", "png_s02n3p01.png", "png_s03i3p01.png", "png_s03n3p01.png", "png_s04i3p01.png",
"png_s04n3p01.png", "png_s05i3p02.png", "png_s05n3p02.png", "png_s06i3p02.png", "png_s06n3p02.png", "png_s07i3p02.png",
"png_s07n3p02.png", "png_s08i3p02.png", "png_s08n3p02.png", "png_s09i3p02.png", "png_s09n3p02.png", "png_s32i3p04.png",
"png_s32n3p04.png", "png_s33i3p04.png", "png_s33n3p04.png", "png_s34i3p04.png", "png_s34n3p04.png", "png_s35i3p04.png",
"png_s35n3p04.png", "png_s36i3p04.png", "png_s36n3p04.png", "png_s37i3p04.png", "png_s37n3p04.png", "png_s38i3p04.png",
"png_s38n3p04.png", "png_s39i3p04.png", "png_s39n3p04.png", "png_s40i3p04.png", "png_s40n3p04.png", "png_tbbn0g04.png",
"png_tbbn2c16.png", "png_tbbn3p08.png", "png_tbgn2c16.png", "png_tbgn3p08.png", "png_tbrn2c08.png", "png_tbwn0g16.png",
"png_tbwn3p08.png", "png_tbyn3p08.png", "png_tm3n3p02.png", "png_tp0n0g08.png", "png_tp0n2c08.png", "png_tp0n3p08.png",
"png_tp1n3p08.png", "png_xc1n0g08.png", "png_xc9n2c08.png", "png_xcrn0g04.png", "png_xcsn0g01.png", "png_xd0n2c08.png",
"png_xd3n2c08.png", "png_xd9n2c08.png", "png_xdtn0g01.png", "png_xhdn0g08.png", "png_xlfn0g04.png", "png_xs1n0g01.png",
"png_xs2n0g01.png", "png_xs4n0g01.png", "png_xs7n0g01.png", "png_z00n2c08.png", "png_z03n2c08.png", "png_z06n2c08.png",
"png_z09n2c08.png",
};

struct object
{
    framework::int32 width  = 0;
    framework::int32 height = 0;
    framework::int32 x      = 0;
    framework::int32 y      = 0;
    framework::opengl::texture texture;
    framework::opengl::mesh quad;
};

std::vector<framework::image::image> load_images(mode m)
{
    std::vector<framework::image::image> images;

    const auto& names = [](mode m) {
        switch (m) {
            case mode::bmp: return bmp_names;
            case mode::png: return png_names;
        }

        return std::vector<std::string>();
    }(m);

    std::transform(cbegin(names), cend(names), std::back_inserter(images), [](const std::string& name) {
        framework::image::image img;
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
    using namespace framework::opengl;
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

framework::opengl::shader_program load_shader(const std::string& VertexShaderCode,
                                              const std::string& FragmentShaderCode)
{
    using namespace framework::opengl;
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

framework::opengl::mesh make_quad(framework::int32 width, framework::int32 height)
{
    using namespace framework::opengl;
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

std::vector<object> generate_objects(const std::vector<framework::image::image>& images)
{
    using framework::image::image;
    using namespace framework::opengl;

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

    int32 w          = 1;
    int32 h          = 1;
    int32 max_height = 1;
    for_each(begin(objects), end(objects), [&w, &h, &max_height, width, height](object& o) {
        if (w + o.width + 1 > width && w != 0) {
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
    using namespace framework::opengl;
    using namespace framework::window;
    using framework::float32;
    using framework::int32;
    using framework::uint32;
    using framework::math::matrix4f;

    framework::log::set_logger(std::make_unique<framework::log::stream_logger>(std::cout));

    // load all images
    std::vector<framework::image::image> images = load_images(mode::png);

    if (images.empty()) {
        return 0;
    }

    window::set_application_name("BMP Test");

    window main_window({640, 480}, "BMP test");
    auto context = main_window.context();
    context->make_current();

    framework::opengl::init();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glViewport(0, 0, 640, 480);

    shader_program shader = load_shader(vertex_shader_src, fragment_shader_src);

    matrix4f mvp = framework::math::ortho2d<float32>(0, 640, 480, 0);
    // mvp          = scale(mvp, {4, 4, 4});

    std::vector<object> objects = generate_objects(images);
    arrange(objects, 640, 480);

    gl_error(__FILE__, __LINE__);

    main_window.set_on_close_callback([&main_window](const window&) { main_window.hide(); });
    main_window.set_on_size_callback([&main_window, &objects, &mvp](const window&, window_size size) {
        mvp = framework::math::ortho2d<float32>(0, size.width, size.height, 0);
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

        context->swap_buffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
