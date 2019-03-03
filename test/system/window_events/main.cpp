
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

#include <iostream>

#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_events_test : public framework::unit_test::suite
{
public:
    window_events_test() : suite("window_events_test")
    {
        add_test([this]() { run(); }, "run");
    }

private:
    void run()
    {
        using namespace framework;
        using ::framework::system::window;
        using ::framework::system::window_position;
        using ::framework::system::window_size;

        ::framework::log::set_logger(std::make_unique<::framework::log::stream_logger>(std::cout));

        const window_size size640{640, 480};

        window w(size640, "Test");

        bool should_close = false;

        w.set_on_show_callback([](const window&) { log::info("test") << "on_show" << std::endl; });

        w.set_on_hide_callback([](const window&) { log::info("test") << "on_hide" << std::endl; });

        w.set_on_close_callback([&should_close](const window&) {
            log::info("test") << "on_close" << std::endl;
            should_close = true;
        });

        w.set_on_focus_callback([](const window&) { log::info("test") << "on_focus" << std::endl; });

        w.set_on_focus_lost_callback([](const window&) { log::info("test") << "on_focus_lost" << std::endl; });

        w.set_on_size_callback(
        [](const window&, window_size size) { log::info("test") << "on_size: " << size << std::endl; });

        w.set_on_position_callback(
        [](const window&, window_position position) { log::info("test") << "on_position: " << position << std::endl; });

        w.set_on_key_press_callback([](const window&, system::key_code, system::modifiers_state) {
            log::info("test") << "on_key_press" << std::endl;
        });

        w.set_on_key_release_callback([](const window&, system::key_code, system::modifiers_state) {
            log::info("test") << "on_key_release" << std::endl;
        });

        w.set_on_mouse_enter_callback([](const window&) { log::info("test") << "on_mouse_enter" << std::endl; });

        w.set_on_mouse_leave_callback([](const window&) { log::info("test") << "on_mouse_leave" << std::endl; });

        w.show();

        while (w.visible() && !should_close) {
            w.process_events();
        }
    }
};

int main()
{
    return run_tests(window_events_test());
}
