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
        add_test([this]() { fullscreen_before_show(); }, "fullscreen_before_show");
        add_test([this]() { maximized_before_show(); }, "maximized_before_show");
    }

private:
    void fullscreen_window()
    {
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

        TEST_ASSERT(window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.hide();
        window.show();

        TEST_ASSERT(window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.restore();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void iconify_window()
    {
        const ::framework::window::size_t size640{640, 480};

        framework::window window(size640);

        window.show();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.iconify();

        // Window is iconified, but still on screen (visible)
        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(!window.focused(), "Invalid window state.");

        window.hide();
        window.show();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.iconify();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(!window.focused(), "Invalid window state.");

        window.restore();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void maximize_window()
    {
        const ::framework::window::size_t size640{640, 480};

        framework::window window(size640);

        window.show();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.maximize();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.hide();
        window.show();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");

        window.restore();

        TEST_ASSERT(!window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void fullscreen_before_show()
    {
        const ::framework::window::size_t size640{640, 480};

        ::framework::window window(size640);

        window.switch_to_fullscreen();
        window.show();

        TEST_ASSERT(window.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!window.iconified(), "Invalid window state.");
        TEST_ASSERT(!window.maximized(), "Invalid window state.");
        TEST_ASSERT(window.visible(), "Invalid window state.");
        TEST_ASSERT(window.focused(), "Invalid window state.");
    }

    void maximized_before_show()
    {
        const ::framework::window::size_t size640{640, 480};

        ::framework::window window(size640);

        window.maximize();
        window.show();

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
