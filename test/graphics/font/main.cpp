#include <chrono>
#include <thread>

#include <common/size.hpp>
#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <math/math.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::math;
using namespace framework::system;

namespace
{

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
layout(location = 3) in vec4 color;\n\
\n\
uniform mat4 projectionMatrix;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * vec4(position, 1.0);\n\
    fragColor = color / 256.0;\n\
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

        window.on_resize.connect([&renderer](const Window&, Size) {
            renderer.set_uniform("projectionMatrix", ortho2d<float>(-0.5, 1.5, -0.5, 1.5));
        });

        Font font;
        auto result = font.load("fonts/UbuntuMono-Regular.ttf");
        TEST_ASSERT(result == Font::LoadResult::Success,
                    "Can't load font, error: " + std::to_string(static_cast<int>(result)));

        const std::string str = "0123456789";
        // const std::string str = "abcdefghijklmnopqrstuvwzxy[]{};':\",./<>?`~!@#$%^&*()_+";
        // const std::string str = "ABCDEFGHIJKLMNOPQRSTUVWZXY[]{};':\",./<>?`~!@#$%^&*()_+";

        font.precache(str);
        Mesh text_mesh = font.create_text_mesh(str);
        TEST_ASSERT(text_mesh.vertices().size() > 0, "Text mesh is empty.");
        TEST_ASSERT(text_mesh.sub_meshes().size() > 0, "Text mesh is empty.");

        renderer.load(text_mesh);

        Shader shader;
        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);
        renderer.load(shader);
        shader.clear();

        window.show();

        std::chrono::microseconds max_total_time = std::chrono::seconds(300);
        std::chrono::microseconds total_time(0);
        std::chrono::milliseconds delta_time(16);

        while (!window.should_close() && total_time < max_total_time) {
            window.process_events();

            renderer.render(text_mesh, shader);
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
