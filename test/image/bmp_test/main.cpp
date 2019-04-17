
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
#include <opengl/shader.hpp>
#include <opengl/texture.hpp>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

using image_rgb = framework::image::image<framework::image::pixel_format::rgb>;

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

class bmp_image_test : public framework::unit_test::suite
{
public:
    bmp_image_test(std::vector<image_rgb>& images) : suite("bmp_image_test"), m_images(images)
    {
        add_test([this]() { bmp_load(); }, "bmp_load");
    }

private:
    std::vector<image_rgb>& m_images;

    void bmp_load()
    {
        image_rgb img;
        TEST_ASSERT(img.load("good_pal1.bmp"), "Loading of good_pal1.bmp failed.");
        m_images.push_back(img);

        // TEST_ASSERT(img.load("good_pal1bg.bmp"), "Loading of good_pal1bg.bmp failed.");
        // TEST_ASSERT(img.load("good_pal1wb.bmp"), "Loading of good_pal1wb.bmp failed.");
        // TEST_ASSERT(img.load("good_pal4.bmp"), "Loading of good_pal4.bmp failed.");
        // TEST_ASSERT(img.load("good_pal4gs.bmp"), "Loading of good_pal4gs.bmp failed.");
        // TEST_ASSERT(img.load("good_pal4rle.bmp"), "Loading of good_pal4rle.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8-0"), "Loading of good_pal8-0 failed.");
        // TEST_ASSERT(img.load("good_pal8.bmp"), "Loading of good_pal8.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8gs.bmp"), "Loading of good_pal8gs.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8nonsquare.bmp"), "Loading of good_pal8nonsquare.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8os2.bmp"), "Loading of good_pal8os2.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8rle.bmp"), "Loading of good_pal8rle.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8topdown.bmp"), "Loading of good_pal8topdown.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8v4.bmp"), "Loading of good_pal8v4.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8v5.bmp"), "Loading of good_pal8v5.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8w124.bmp"), "Loading of good_pal8w124.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8w125.bmp"), "Loading of good_pal8w125.bmp failed.");
        // TEST_ASSERT(img.load("good_pal8w126.bmp"), "Loading of good_pal8w126.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb16-565.bmp"), "Loading of good_rgb16-565.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb16-565pal.bmp"), "Loading of good_rgb16-565pal.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb16.bmp"), "Loading of good_rgb16.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb16bfdef.bmp"), "Loading of good_rgb16bfdef.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb24.bmp"), "Loading of good_rgb24.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb24pal.bmp"), "Loading of good_rgb24pal.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb32.bmp"), "Loading of good_rgb32.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb32bf.bmp"), "Loading of good_rgb32bf.bmp failed.");
        // TEST_ASSERT(img.load("good_rgb32bfdef.bmp"), "Loading of good_rgb32bfdef.bmp failed.");
    }
};

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

void load(const std::vector<image_rgb>& images)
{
    if (images.empty()) {
        return;
    }
}

void draw(const std::vector<image_rgb>& images)
{
    if (images.empty()) {
        return;
    }
}

int main()
{
    using namespace framework::opengl;
    using namespace framework::system;
    using framework::float32;
    using framework::int32;
    using framework::uint32;
    using framework::math::matrix4f;
    using framework::math::vector2f;

    framework::log::set_logger(std::make_unique<framework::log::stream_logger>(std::cout));

    window::set_application_name("BMP Test");

    window main_window({640, 480}, "BMP test");
    auto context = main_window.context();
    context->make_current();

    framework::opengl::init();

    const float32 max_total_time = 1000000;
    float32 total_time           = 0;

    main_window.set_on_close_callback([&main_window](const window&) { main_window.hide(); });
    main_window.set_on_size_callback(
    [&main_window](const window&, window_size size) { glViewport(0, 0, size.width, size.height); });

    // load all images
    std::vector<image_rgb> images;
    const int32 result = run_tests(bmp_image_test(images));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    gl_error(__FILE__, __LINE__);

    uint32 vertex_array_id;
    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);

    gl_error(__FILE__, __LINE__);
    glViewport(0, 0, 640, 480);

    static const vector2f vertex_buffer_data[] = {
    vector2f(0.0f, 0.0f),
    vector2f(0.0f, 64.0f),
    vector2f(127.0f, 64.0f),
    vector2f(127.0f, 0.0f),
    };

    static const vector2f texture_buffer_data[] = {
    vector2f(0.0f, 0.0f),
    vector2f(0.0f, 1.0f),
    vector2f(1.0f, 1.0f),
    vector2f(1.0f, 0.0f),
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data[0].data(), GL_STATIC_DRAW);

    gl_error(__FILE__, __LINE__);
    GLuint texturebuffer;
    glGenBuffers(1, &texturebuffer);

    glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texture_buffer_data), texture_buffer_data[0].data(), GL_STATIC_DRAW);
    gl_error(__FILE__, __LINE__);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    gl_error(__FILE__, __LINE__);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0);

    shader_program shader = load_shader(vertex_shader_src, fragment_shader_src);

    gl_error(__FILE__, __LINE__);
    matrix4f mvp = framework::math::ortho2d<float32>(0, 640, 480, 0);
    mvp          = framework::math::scale(mvp, {4, 4, 4});

    
    texture tex(min_filter::nearest, mag_filter::nearest, wrap_s::clamp_to_edge, wrap_t::clamp_to_edge);
    tex.load(internal_format::rgba, 127, 64, format::rgb, images[0].data());

    gl_error(__FILE__, __LINE__);

    main_window.show();

    while (main_window.visible() && total_time < max_total_time) {
        main_window.process_events();

        glClearColor(0.5f, 0.2f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        tex.bind();
        shader.uniform("tex", tex.texture_unit());

        shader.uniform("MVP", mvp);

        glBindVertexArray(vertex_array_id);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        glBindVertexArray(0);

        tex.unbind();

        shader.stop_using();

        context->swap_buffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        total_time += 16;
    }

    return result;
}
