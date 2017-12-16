#include <chrono>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_test : public framework::unit_test::suite
{
public:
    window_test()
        : suite("window_test")
    {
        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
        add_test([this]() { focus_window(); }, "focus_window");
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

    void focus_window()
    {
        constexpr std::chrono::milliseconds timespan(100);

        framework::window alpha;
        framework::window betta;

        alpha.show();
        betta.show();

        std::this_thread::sleep_for(timespan);

        alpha.focus();

        std::this_thread::sleep_for(timespan);

        TEST_ASSERT(alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(!betta.focused(), "Focus function is not working.");

        betta.focus();

        std::this_thread::sleep_for(timespan);

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");
    }
};

int main()
{
    return run_tests(window_test());
}
