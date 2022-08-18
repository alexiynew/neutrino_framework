#include <chrono>
#include <thread>

#include <common/utils.hpp>
#include <common/version.hpp>
#include <graphics/color.hpp>
#include <graphics/renderer.hpp>
#include <system/application.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

class ContextTest : public framework::unit_test::Suite
{
public:
    ContextTest()
        : Suite("ContextTest")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        using namespace framework;
        using namespace framework::graphics;
        using namespace framework::system;

        Application::set_name("GL Test");

        Window main_window(name(), {640, 480});
        Renderer render(main_window.context());

        main_window.show();

        render.set_clear_color(Color(0xFF00FFFFU));

        const float max_total_time = 1000;
        float total_time           = 0;

        while (main_window.is_visible() && total_time < max_total_time) {
            main_window.process_events();

            render.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            total_time += 16;
        }
    }
};

int main()
{
    return run_tests(ContextTest());
}
