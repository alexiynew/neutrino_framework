#include <chrono>
#include <thread>

#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework::system;
using namespace framework::graphics;

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

        Font font;
        auto result = font.load("fonts/UbuntuMono-Regular.ttf");
        TEST_ASSERT(result == Font::LoadResult::Success,
                    "Can't load font, error: " + std::to_string(static_cast<int>(result)));

        font.precache("abcdef");
        renderer.load(font);

        window.show();

        std::chrono::microseconds max_total_time = std::chrono::seconds(3);
        std::chrono::microseconds total_time(0);
        std::chrono::milliseconds delta_time(16);

        while (!window.should_close() && total_time < max_total_time) {
            window.process_events();

            //            renderer.render();

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
