#include <chrono>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>
#include <log/stream_logger.hpp>
#include <iostream>

class window_test : public framework::unit_test::suite
{
public:
    window_test()
        : suite("window_test")
    {
//        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
    }

private:
    void open_window()
    {
        constexpr std::chrono::milliseconds timespan(100);

        framework::window window;
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
        using ::framework::logging::log;
        using ::framework::logging::stream_logger;
        log::set_logger(std::make_unique<stream_logger>(std::cout));

        constexpr std::chrono::milliseconds timespan(100);

        framework::window windows[5];

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
    return run_tests(window_test());
}
