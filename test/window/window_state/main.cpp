#include <chrono>
#include <thread>

#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_state_test : public framework::unit_test::suite
{
public:
    window_state_test() : suite("window_state_test")
    {
        add_test([this]() { fullscreen_window(); }, "fullscreen_window");
        add_test([this]() { iconify_window(); }, "iconify_window");
        add_test([this]() { maximize_window(); }, "maximize_window");
        add_test([this]() { state_before_show(); }, "state_before_show");
    }

private:
    void fullscreen_window()
    {
        constexpr std::chrono::milliseconds timespan(50);
        const ::framework::window::size_t size640{640, 480};

        framework::window window(size640);

        window.show();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.switch_to_fullscreen();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.hide();
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.restore();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void iconify_window()
    {
        constexpr std::chrono::milliseconds timespan(50);
        const ::framework::window::size_t size640{640, 480};

        framework::window window(size640);

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.iconify();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(!window.visible(), "Invalid window state.");
        TEST_ASSERT(!window.focused(), "Invalid window state.");

        window.hide();
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(!window.visible(), "Invalid window state.");
        TEST_ASSERT(!window.focused(), "Invalid window state.");

        window.restore();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void maximize_window()
    {
        constexpr std::chrono::milliseconds timespan(50);
        const ::framework::window::size_t size640{640, 480};

        framework::window window(size640);

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.maximize();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.hide();
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.restore();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void state_before_show()
    {
        constexpr std::chrono::milliseconds timespan(50);
        const ::framework::window::size_t size640{640, 480};

        ::framework::window window(size640);

        window.switch_to_fullscreen();
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.hide();
        window.maximize();
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
    }
};

int main()
{
    return run_tests(window_state_test());
}
