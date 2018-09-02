#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <thread>

#include <common/utils.hpp>
#include <graphic/opengl/gl.hpp>
#include <graphic/window.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <math/math.hpp>
#include <unit_test/suite.hpp>

namespace
{
const std::string vertex_shader_source = "#version 330 core\n"
                                         "\n"
                                         "layout(location = 0) in vec3 vertexPosition_modelspace;\n"
                                         "void main(){\n"
                                         "    gl_Position.xyz = vertexPosition_modelspace;\n"
                                         "    gl_Position.w = 1.0;\n"
                                         "};\n";

const std::string fragment_shader_source = "#version 330 core\n"
                                           "uniform vec3 my_color;\n"
                                           "out vec3 color;\n"
                                           "\n"
                                           "void main()\n"
                                           "{\n"
                                           "    color = my_color;\n"
                                           "};\n";

framework::uint32 compile_shader(const std::string& source, GLenum type)
{
    using namespace framework::graphic::gl;

    framework::uint32 shader = glCreateShader(type);

    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);

    glCompileShader(shader);

    framework::int32 is_compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);
    if (is_compiled == 0) {
        framework::int32 log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

        std::vector<char> error_log(log_length);
        glGetShaderInfoLog(shader, log_length, &log_length, &error_log[0]);

        framework::log::error("shader") << "Can't compile shader\n" << error_log.data() << std::endl;

        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

framework::uint32 link_shader_program(framework::uint32 vertex_shader, framework::uint32 fragment_shader)
{
    using namespace framework::graphic::gl;

    if (vertex_shader == 0 || fragment_shader == 0) {
        return 0;
    }

    framework::uint32 program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    framework::int32 is_linked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &is_linked);
    if (is_linked == 0) {
        framework::int32 log_length = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);

        std::vector<char> error_log(log_length);
        glGetProgramInfoLog(program, log_length, &log_length, &error_log[0]);

        framework::log::error("shader") << "Can't compile shader\n" << error_log.data() << std::endl;

        glDeleteProgram(program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        return 0;
    }

    glDetachShader(program, vertex_shader);
    glDetachShader(program, fragment_shader);

    return program;
}

} // namespace

class renderer_test : public framework::unit_test::suite
{
public:
    renderer_test() : suite("renderer_test")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        using framework::utils::random_numbers;

        using namespace ::framework::graphic;
        using namespace ::framework::graphic::gl;
        using namespace ::framework::log;
        using namespace ::framework::math;

        set_logger(std::make_unique<stream_logger>(std::cout));

        window main_window({640, 480}, "Game");
        auto context = main_window.context();

        if (!context->valid()) {
            TEST_FAIL("Graphic context is not valid.");
            return;
        }

        context->make_current();
        if (!gl::init()) {
            TEST_FAIL("Can't init OpenGL functions.");
            return;
        }

        framework::uint32 shader = link_shader_program(compile_shader(vertex_shader_source, GL_VERTEX_SHADER),
                                                       compile_shader(fragment_shader_source, GL_FRAGMENT_SHADER));

        glUseProgram(shader);

        auto color_location = glGetUniformLocation(shader, "my_color");

        main_window.show();

        vector3f triangle_color(random_numbers(0.0f, 1.0f, 3).data());
        vector3f back_color(random_numbers(0.0f, 1.0f, 3).data());
        vector3f new_color(random_numbers(0.0f, 1.0f, 3).data());

        framework::float32 total_time          = 0;
        framework::float32 step_time           = 0;
        const framework::float32 step_max_time = 2000;

        framework::uint32 VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        // clang-format off
        static const framework::float32 g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
             1.0f, -1.0f, 0.0f,
             0.0f,  1.0f, 0.0f 
        };
        // clang-format on

        // Это будет идентификатором нашего буфера вершин
        framework::uint32 vertexbuffer;

        // Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
        glGenBuffers(1, &vertexbuffer);

        // Сделаем только что созданный буфер текущим
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

        // Передадим информацию о вершинах в OpenGL
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        while (main_window.visible() && total_time < 10000) {
            if (step_time >= step_max_time) {
                step_time      = 0;
                triangle_color = back_color;
                back_color     = new_color;
                new_color      = vector3f(random_numbers(0.0f, 1.0f, 3).data());
            }

            main_window.process_events();

            vector3f clear_color = mix(back_color, new_color, step_time / step_max_time);

            glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            vector3f object_color = mix(triangle_color, back_color, step_time / step_max_time);

            glUniform3fv(color_location, 1, object_color.data());

            // Указываем, что первым буфером атрибутов будут вершины
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(0, // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
                                  3, // Размер
                                  GL_FLOAT, // Тип
                                  false, // Указывает, что значения не нормализованы
                                  0,     // Шаг
                                  (void*)0 // Смещение массива в буфере
            );

            // Вывести треугольник!
            glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

            glDisableVertexAttribArray(0);

            context->swap_buffers();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            step_time += 16;
            total_time += 16;
        }
    }
};

int main()
{
    return run_tests(renderer_test());
}
