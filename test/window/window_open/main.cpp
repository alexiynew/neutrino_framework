#include <chrono>
#include <iostream>
#include <thread>

#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_open_test : public framework::unit_test::suite
{
public:
    window_open_test() : suite("window_open_test")
    {
        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
    }

private:
    void open_window()
    {
        constexpr std::chrono::milliseconds timespan(50);

        ::framework::window window({640, 480});
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.visible(), "Window is not visible.");

        std::this_thread::sleep_for(timespan);
        window.process_events();

        window.hide();

        TEST_ASSERT(!window.visible(), "Window is still visible.");
    }

    void open_several_windows()
    {
        constexpr std::chrono::milliseconds timespan(50);

        ::framework::window windows[5] = {
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        };

        for (auto& window : windows) {
            window.show();
        }

        std::this_thread::sleep_for(timespan);
        for (auto& window : windows) {
            window.process_events();
        }

        for (auto& window : windows) {
            window.hide();
        }

        std::this_thread::sleep_for(timespan);
        for (auto& window : windows) {
            window.process_events();
        }

        for (auto& window : windows) {
            window.show();
        }
    }
};

int main()
{
    return run_tests(window_open_test());
}
