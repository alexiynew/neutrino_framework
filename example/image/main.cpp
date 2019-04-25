
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

struct object
{
    framework::int32 width  = 0;
    framework::int32 height = 0;
    framework::int32 x      = 0;
    framework::int32 y      = 0;
    framework::opengl::texture texture;
    framework::opengl::mesh quad;
};

std::vector<framework::image::image> load_bmp()
{
    std::string names[] = {
    //"pal1.bmp",
    //"pal1bg.bmp",
    //"pal1wb.bmp",
    //"pal4.bmp",
    //"pal4gs.bmp",
    //"pal4rle.bmp",
    // "pal8.bmp",
    //"pal8-0.bmp",
    //"pal8gs.bmp",
    //"pal8nonsquare.bmp",
    //"pal8os2.bmp",
    //  "pal8rle.bmp",
    //"pal8topdown.bmp",
    //"pal8v4.bmp",
    //"pal8v5.bmp",
    //    "pal8w124.bmp",
    //    "pal8w125.bmp",
    //    "pal8w126.bmp",

        "rgb16.bmp",
        "rgb16-565.bmp",
        "rgb16-565pal.bmp",
        "rgb16bfdef.bmp",
    //    "rgb24.bmp",
    //    "rgb24pal.bmp",
    //    "rgb32.bmp",
    //    "rgb32bf.bmp",
    // "rgb32bfdef.bmp"
    };

    std::vector<framework::image::image> images;
    std::transform(begin(names), end(names), std::back_inserter(images), [](const std::string& name) {
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
    m.load(vertex_buffer_data, texture_buffer_data);

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
    using namespace framework::system;
    using framework::float32;
    using framework::int32;
    using framework::uint32;
    using framework::math::matrix4f;

    framework::log::set_logger(std::make_unique<framework::log::stream_logger>(std::cout));

    // load all images
    std::vector<framework::image::image> images = load_bmp();

    if (images.empty()) {
        return 0;
    }

    window::set_application_name("BMP Test");

    window main_window({640, 480}, "BMP test");
    auto context = main_window.context();
    context->make_current();

    framework::opengl::init();

    const float32 max_total_time = 1000000;
    float32 total_time           = 0;

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

    while (main_window.visible() && total_time < max_total_time) {
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

        total_time += 16;
    }

    return 0;
}
