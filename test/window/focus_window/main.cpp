#include <chrono>
#include <iostream>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

using namespace framework::log;

class focus_window_test : public framework::unit_test::suite
{
public:
    focus_window_test()
        : suite("focus_window_test")
    {
        add_test([this]() { focus_window(); }, "focus_window");
    }

private:
    void focus_window()
    {
        constexpr std::chrono::milliseconds timespan(10);

        set_logger(std::make_unique<stream_logger>(std::cout));

        framework::window alpha;
        framework::window betta;

        alpha.show();
        betta.show();

        std::this_thread::sleep_for(timespan);
        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");

        alpha.focus();
        betta.focus();

        std::this_thread::sleep_for(timespan);
        alpha.process_events();
        betta.process_events();

        // TODO: Make test more complicated.
        //       For linux: check on different WM's.
    }
};

int main()
{
    return run_tests(focus_window_test());
}
