
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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
#include <random>
#include <sstream>
#include <thread>

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

        ::framework::float32 t          = 0;
        ::framework::float32 total_time = 0;

        while (main_window.visible() && total_time < 3000) {
            if (t >= 500) {
                t         = 0;
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

            t += 16;
            total_time += 16;
        }
    }
};

int main()
{
    return run_tests(renderer_test());
}
