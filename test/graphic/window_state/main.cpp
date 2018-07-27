#include <graphic/window.hpp>
#include <unit_test/suite.hpp>

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
        using ::framework::graphic::window;

        const window::size_t size640{640, 480};

        window w(size640, "Test");

        w.show();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.switch_to_fullscreen();

        TEST_ASSERT(w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");

        w.hide();
        w.show();

        TEST_ASSERT(w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");

        w.restore();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void iconify_window()
    {
        using ::framework::graphic::window;

        const window::size_t size640{640, 480};

        window w(size640, "Test");

        w.show();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.iconify();

        // Window is iconified, but still on screen (visible)
        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(!w.focused(), "Invalid window state.");

        w.hide();
        w.show();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.iconify();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(!w.focused(), "Invalid window state.");

        w.restore();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void maximize_window()
    {
        using ::framework::graphic::window;

        const window::size_t size640{640, 480};

        window w(size640, "Test");

        w.show();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.maximize();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");

        w.hide();
        w.show();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");

        w.restore();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void fullscreen_before_show()
    {
        using ::framework::graphic::window;

        const window::size_t size640{640, 480};

        window w(size640, "Test");

        w.switch_to_fullscreen();
        w.show();

        TEST_ASSERT(w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(!w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
    }

    void maximized_before_show()
    {
        using ::framework::graphic::window;

        const window::size_t size640{640, 480};

        window w(size640, "Test");

        w.maximize();
        w.show();

        TEST_ASSERT(!w.fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.iconified(), "Invalid window state.");
        TEST_ASSERT(w.maximized(), "Invalid window state.");
        TEST_ASSERT(w.visible(), "Invalid window state.");
        TEST_ASSERT(w.focused(), "Invalid window state.");
    }
};

int main()
{
    return run_tests(window_state_test());
}
