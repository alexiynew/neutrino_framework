#include <chrono>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_state_test : public framework::unit_test::suite
{
public:
    window_state_test()
        : suite("window_state_test")
    {
        add_test([this]() { minimize_window(); }, "minimize_window");
        add_test([this]() { maximize_window(); }, "maximize_window");
    }

private:
    void minimize_window()
    {
        constexpr std::chrono::milliseconds timespan(50);

        framework::window window;

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.minimized(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.minimize();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(window.minimized(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(!window.visible(), "Invalid window state.");
        TEST_ASSERT(!window.focused(), "Invalid window state.");

        window.restore();
        window.focus();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.minimized(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
    }

    void maximize_window()
    {
        constexpr std::chrono::milliseconds timespan(50);

        framework::window window;

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.minimized(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.maximize();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.minimized(), "Invalid window state.");
        TEST_ASSERT(window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.restore();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.minimized(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
    }
};

int main()
{
    return run_tests(window_state_test());
}
