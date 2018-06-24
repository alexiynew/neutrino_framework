#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <sstream>

#include <graphic/opengl_canvas.hpp>
#include <graphic/window.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <math/math.hpp>
#include <unit_test/suite.hpp>

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
        using namespace ::framework::graphic;
        using namespace ::framework::log;
        using namespace ::framework::math;

        set_logger(std::make_unique<stream_logger>(std::cout));

        window main_window({640, 480}, "Game");
        opengl_canvas gl_canvas(main_window.context());

        main_window.show();

        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(0, 100);

        auto r_value = [&]() { return (dist(rd) / 100.0f); };

        vector3f old_color(0, 0, 0);
        vector3f new_color(r_value(), r_value(), r_value());

        ::framework::float32 t = 0;

        while (main_window.visible()) {

            if (t >= 1000) {
                t = 0;
                old_color = new_color;
                new_color = vector3f(r_value(), r_value(), r_value());
            }

            main_window.process_events();

            vector3f color = mix(old_color, new_color, t / 1000.0f);

            gl_canvas.clear(color.x, color.y, color.z, 1.0f);

            gl_canvas.swap_buffers();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            std::stringstream ss;
            ss << color;

            main_window.set_title(ss.str());

            t+= 16;
        }
    }
};

int main()
{
    return run_tests(renderer_test());
}
