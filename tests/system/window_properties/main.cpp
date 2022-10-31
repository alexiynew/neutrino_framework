#include <chrono>
#include <thread>

#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::system;

class WindowPropertiesTest : public framework::unit_test::Suite
{
public:
    WindowPropertiesTest()
        : Suite("WindowPropertiesTest")
    {
        add_test([this]() { window_size(); }, "window_size");
        add_test([this]() { window_size_limits(); }, "window_size_limits");
        add_test([this]() { window_position(); }, "window_position");
        add_test([this]() { window_title(); }, "window_title");
    }

private:
    void window_size()
    {
        Stats stats;

        const Size size480{480, 320};
        const Size size640{640, 480};

        Size size_in_callback{0, 0};

        Window window(name(), {480, 320});

        window.set_on_show_callback([&stats]() { stats.show_called++; });

        window.set_on_resize_callback([&window, &stats, this](Size w_size) {
            stats.size_called++;
            stats.last_size = w_size;

            TEST_ASSERT(window.is_visible(), "Window must be visible to send on_resize callbacks.");
        });

        // Check stats
        TEST_ASSERT(stats.size_called == 0, "Wrong stats.size_called count at the beginning.");
        TEST_ASSERT(stats.show_called == 0, "Wrong stats.show_called count at the beginning.");
        TEST_ASSERT(stats.last_size == Size(), "Wrong stats.last_size at the beginning.");

        // Window stats on creation
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        // Show window - must be 480
        window.show();

        TEST_ASSERT(stats.show_called == 1,
                    "On_show callback must be called once (" + std::to_string(stats.show_called) + ").");
        TEST_ASSERT(stats.size_called == 1,
                    "On_resize callback must be called once (" + std::to_string(stats.size_called) + ").");
        TEST_ASSERT(stats.last_size == size480, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.is_visible(), "Window must be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Resize window - must be 640
        window.set_size({640, 480});
        std::this_thread::sleep_for(std::chrono::seconds(1));

        TEST_ASSERT(stats.show_called == 1,
                    "On_show callback must be called once (" + std::to_string(stats.show_called) + ").");
        TEST_ASSERT(stats.size_called == 2,
                    "On_resize callback must be called twice (" + std::to_string(stats.size_called) + ").");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        // Hide and show window - must be still 640
        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window must not be visible.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(stats.show_called == 2,
                    "On_show callback must be called twice (" + std::to_string(stats.show_called) + ").");
        TEST_ASSERT(stats.size_called == 3,
                    "On_resize callback must be called 3 times (" + std::to_string(stats.size_called) + ").");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.is_visible(), "Window must be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Resize hidden window - no callbacks, size changed
        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window must not be visible.");

        window.set_size(size480);

        TEST_ASSERT(stats.show_called == 2, "On_show callback must not be called while size changed.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must not be called while window is not visible.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        window.set_size(size640);

        TEST_ASSERT(stats.show_called == 2, "On_show callback must not be called while size changed.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must not be called while window is not visible.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.set_size(size480);

        TEST_ASSERT(stats.show_called == 2, "On_show callback must not be called while size changed.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must not be called while window is not visible.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        // For some reason on macOS if to show window immediately after resizing it won't be shown.
        // Some time needs to pass and after that window.process_events() will force the window to appear on the screen.
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();

        TEST_ASSERT(stats.show_called == 3,
                    "On_show callback must be called 3 times (" + std::to_string(stats.show_called) + ").");
        TEST_ASSERT(stats.size_called == 4,
                    "On_resize callback must be called 4 times (" + std::to_string(stats.size_called) + ").");
        TEST_ASSERT(stats.last_size == size480, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.is_visible(), "Window must be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void window_size_limits()
    {
        const Size no_size{0, 0};

        const Size size640{640, 480};
        const Size size960{960, 640};

        const Size small_size{150, 150};
        const Size big_size{1000, 800};

        Window window(name(), {640, 480});

        // Base values
        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");

        window.set_min_size(size640);
        window.set_max_size(size960);

        window.show();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // All sizes setted up correctly
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size640, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        // Check size limits
        window.set_size(big_size);
        TEST_ASSERT(window.size() == size960, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_size(small_size);
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // No more limits. Can change size as we want
        window.set_min_size(no_size);
        window.set_max_size(no_size);

        window.set_size(small_size);
        TEST_ASSERT(window.size() == small_size, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_size(big_size);
        TEST_ASSERT(window.size() == big_size, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // TODO: Size limits should set_size the window if it does not fit
        // within the constraints.
        // Set size limits while the window is oversized.
        // window.set_max_size(size960);
        // TEST_ASSERT(window.size() == size960, "Window has wrong size.");
        // std::this_thread::sleep_for(std::chrono::seconds(1));

        //// Set size limits while the window is undersized
        // window.set_size(small_size);
        // window.set_min_size(size640);
        // TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        // std::this_thread::sleep_for(std::chrono::seconds(1));

        // TODO: Add test for partial set/unset size limits
    }

    void window_position()
    {
        Stats stats;
        const Size size640          = {640, 480};
        const Position position_100 = {100, 100};

        Window window(name(), size640);

        window.set_on_show_callback([&stats]() { stats.show_called++; });

        window.set_on_move_callback([&window, &stats, this](Position position) {
            stats.position_called++;
            stats.last_position = position;

            TEST_ASSERT(window.is_visible(), "Window must be visible to send on_move callbacks.");
        });

        window.show();

        TEST_ASSERT(stats.position_called == 1, "On position must be called.");
        TEST_ASSERT(window.size() == size640, "Window should save its size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_position({0, 0});

        // MacOS and some linux WM does not allow to set vertical window position less than window title bar height.
        // So we check the window is located at some reasonable point.
        TEST_ASSERT(window.position().x >= 0 && window.position().x < 10 && window.position().y >= 0 &&
                    window.position().y < 100,
                    "Wrong window position.");

        TEST_ASSERT(stats.last_position == window.position(), "Wrong position in callback.");
        TEST_ASSERT(stats.position_called == 2,
                    "On position must be called 2 times (" + std::to_string(stats.position_called) + ").");
        TEST_ASSERT(window.size() == size640, "Window should save its size.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_position({100, 100});

        TEST_ASSERT(window.position() == position_100, "Window must be in (100, 100) position.");
        TEST_ASSERT(stats.last_position == position_100, "Wrong position in callback.");
        TEST_ASSERT(stats.position_called == 3,
                    "On position must be called 3 times (" + std::to_string(stats.position_called) + ").");
        TEST_ASSERT(window.size() == size640, "Window should save its size.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_position({-100, 100});

        TEST_ASSERT(window.position() == Position(-100, 100), "Window must be in (-100, 100) position.");
        TEST_ASSERT(stats.last_position == Position(-100, 100), "Wrong position in callback.");
        TEST_ASSERT(stats.position_called == 4,
                    "On position must be called 4 times (" + std::to_string(stats.position_called) + ").");
        TEST_ASSERT(window.size() == size640, "Window should save its size.");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void window_title()
    {
        const std::string title      = "winodw_title";
        const std::string new_title  = "new_window_title";
        const std::string utf8_title = "\u0e1e\u16c1\u1262\u2817\u263a\u0077\u0020\u22a4\u0049\u03c4\u10e1\u0435";

        Window window(title, {640, 480});

        window.show();

        TEST_ASSERT(window.title() == title, "Window has wrong title");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_title(new_title);

        TEST_ASSERT(window.title() == new_title, "Window has wrong title");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_title(utf8_title);

        TEST_ASSERT(window.title() == utf8_title, "Window has wrong title");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    struct Stats
    {
        int show_called = 0;
        int size_called = 0;
        Size last_size;
        int position_called = 0;
        Position last_position;

        void reset()
        {
            show_called     = 0;
            size_called     = 0;
            last_size       = Size();
            position_called = 0;
            last_position   = Position();
        }
    };
};

int main()
{
    return run_tests(WindowPropertiesTest());
}
