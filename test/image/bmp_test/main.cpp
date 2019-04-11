
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
#include <string>
#include <thread>
#include <vector>

#include <image/image.hpp>
#include <math/math.hpp>
#include <opengl/gl.hpp>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

using image_rgb = framework::image::image<framework::image::pixel_format::rgb>;

const std::string vertex_shader = "#version 330 core\n\
layout(location = 0) in vec3 vertexPosition_modelspace;\n\
void main(){\n\
    gl_Position.xyz = vertexPosition_modelspace;\n\
    gl_Position.w = 1.0;\n\
}";

const std::string fragment_shader = "#version 330 core\n\
out vec3 color;\n\
void main(){\n\
    color = vec3(1,0,0);\n\
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

framework::uint32 load_shader(const std::string& VertexShaderCode, const std::string& FragmentShaderCode)
{
    using namespace framework::opengl;

    GLuint VertexShaderID   = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Компилируем Вершинный шейдер
    char const* VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);

    // Выполняем проверку Вершинного шейдера
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        //        fprintf(stdout, "%sn", &VertexShaderErrorMessage[0]);
    }

    // Компилируем Фрагментный шейдер
    char const* FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);

    // Проверяем Фрагментный шейдер
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        //       fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    }

    // Создаем шейдерную программу и привязываем шейдеры к ней
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Проверяем шейдерную программу
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        //        fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    }

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
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
    using framework::math::vector3f;

    window::set_application_name("BMP Test");

    framework::opengl::init();

    window main_window({640, 480}, "BMP test");
    auto context = main_window.context();
    context->make_current();

    const float32 max_total_time = 10000;
    float32 total_time           = 0;

    main_window.set_on_close_callback([&main_window](const window&) { main_window.hide(); });

    // load all images
    std::vector<image_rgb> images;
    const int32 result = run_tests(bmp_image_test(images));

    uint32 vertex_array_id;
    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);

    static const vector3f vertex_buffer_data[] = {vector3f(-1.0f, -1.0f, 0.0f),
                                                  vector3f(1.0f, -1.0f, 0.0f),
                                                  vector3f(0.0f, 1.0f, 0.0f)};

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data[0].data(), GL_STATIC_DRAW);

    uint32 shader = load_shader(vertex_shader, fragment_shader);

    load(images);

    main_window.show();

    while (main_window.visible() && total_time < max_total_time) {
        main_window.process_events();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDisableVertexAttribArray(0);

        draw(images);

        context->swap_buffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        total_time += 16;
    }

    return result;
}
