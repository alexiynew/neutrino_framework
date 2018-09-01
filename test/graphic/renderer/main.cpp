#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <thread>

#include <common/utils.hpp>
#include <graphic/opengl/gl.hpp>
#include <graphic/opengl_canvas.hpp>
#include <graphic/shader.hpp>
#include <graphic/window.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <math/math.hpp>
#include <unit_test/suite.hpp>

namespace
{
const std::string vertex_shader = "#version 330 core\n"
                                  "\n"
                                  //"layout(location = 0) in vec3 vertexPosition_modelspace;\n"
                                  "in vec3 vertexPosition_modelspace;\n"
                                  "void main(){\n"
                                  "    gl_Position.xyz = vertexPosition_modelspace;\n"
                                  "    gl_Position.w = 1.0;\n"
                                  "};\n";

const std::string fragment_shader = "#version 330 core\n"
                                    "uniform vec3 my_color;\n"
                                    "out vec3 color;\n"
                                    "\n"
                                    "void main()\n"
                                    "{\n"
                                    "    color = my_color;\n"
                                    "};\n";
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
        opengl_canvas gl_canvas(main_window.context());

        info(name()) << "GL:       " << gl_canvas.version() << std::endl;
        info(name()) << "GLSL:     " << gl_canvas.shading_language_version() << std::endl;
        info(name()) << "Vendor:   " << gl_canvas.vendor_name() << std::endl;
        info(name()) << "Renderer: " << gl_canvas.renderer_name() << std::endl;

        shader simple_shader;
        simple_shader.add_vertex_source(vertex_shader);
        simple_shader.add_fragment_source(fragment_shader);
        simple_shader.bind_attribute({1, "vertexPosition_modelspace"});

        simple_shader.compile();

        simple_shader.use();

        // float vcolor[] = {1.0f, 0.5f, 0.0f};

        gl::glUniform3f(0, 1.0f, 0.5f, 0.0f);

        main_window.show();

        vector3f old_color(0, 0, 0);
        vector3f new_color(random_numbers(0.0f, 1.0f, 3).data());

        framework::float32 t          = 0;
        framework::float32 total_time = 0;

        /// --------------
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
            if (t >= 5000) {
                t         = 0;
                old_color = new_color;
                new_color = vector3f(random_numbers(0.0f, 1.0f, 3).data());
            }

            main_window.process_events();

            vector3f color = mix(old_color, new_color, t / 1000.0f);

            gl_canvas.clear(color.x, color.y, color.z, 1.0f);

            // Указываем, что первым буфером атрибутов будут вершины
            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(1, // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
                                  3, // Размер
                                  GL_FLOAT, // Тип
                                  false, // Указывает, что значения не нормализованы
                                  0,     // Шаг
                                  (void*)0 // Смещение массива в буфере
            );

            // Вывести треугольник!
            glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

            glDisableVertexAttribArray(0);

            gl_canvas.swap_buffers();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            t += 16;
            total_time += 16;
        }
    }
};

int main()
{
    return run_tests(renderer_test());
}
