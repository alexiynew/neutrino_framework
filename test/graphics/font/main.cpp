#include <chrono>
#include <thread>

#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework::system;
using namespace framework::graphics;

namespace
{

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = vec4(position, 1.0);\n\
    fragColor = vec4(1.0, 0.5, 0.3, 1.0);\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
in vec4 fragColor;\n\
out vec4 color;\n\
void main(){\n\
    color = fragColor;\n\
}";

} // namespace

class FontTest : public framework::unit_test::Suite
{
public:
    FontTest()
        : Suite("FontTest")
    {
        add_test([this]() { render_font(); }, "render_font");
    }

private:
    void render_font()
    {
        Window::set_application_name(name());

        Window window(name(), {800, 640});
        Renderer renderer(window);

        renderer.set_clear_color(Color(0x202020FFu));
        renderer.set_polygon_mode(Renderer::PolygonMode::line);

        Font font;
        auto result = font.load("fonts/UbuntuMono-Regular.ttf");
        TEST_ASSERT(result == Font::LoadResult::Success,
                    "Can't load font, error: " + std::to_string(static_cast<int>(result)));

        font.precache("abcdef");
        TEST_ASSERT(renderer.load(font), "Can't load font data to renderer.");

        Shader shader;
        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);
        renderer.load(shader);
        shader.clear();

        window.show();

        std::chrono::microseconds max_total_time = std::chrono::seconds(3);
        std::chrono::microseconds total_time(0);
        std::chrono::milliseconds delta_time(16);

        while (!window.should_close() && total_time < max_total_time) {
            window.process_events();

            renderer.render(font.mesh(), shader);
            renderer.display();

            std::this_thread::sleep_for(delta_time);
            total_time += delta_time;
        }
    }
};

int main()
{
    return run_tests(FontTest());
}
