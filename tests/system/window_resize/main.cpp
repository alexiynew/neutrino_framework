#include <chrono>
#include <thread>

#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::system;

class WindowResizeTest : public framework::unit_test::Suite
{
public:
    WindowResizeTest()
        : Suite("WindowResizeTest")
    {
        add_test([this]() { window_resizability(); }, "window_resizability");
        add_test([this]() { window_resizability_before_show(); }, "window_resizability_before_show");
        add_test([this]() { window_resizability_and_size(); }, "window_resizability_and_size");
    }

private:
    struct Stats
    {
        int on_show_called       = 0;
        int on_hide_called       = 0;
        int on_resize_called     = 0;
        int on_move_called       = 0;
        int on_focus_called      = 0;
        int on_lost_focus_called = 0;
        Size last_size;
        Position last_position;

        void reset()
        {
            on_show_called       = 0;
            on_hide_called       = 0;
            on_resize_called     = 0;
            on_move_called       = 0;
            on_focus_called      = 0;
            on_lost_focus_called = 0;
            last_size            = Size();
            last_position        = Position();
        }
    };

    void window_resizability()
    {
        const Size size640{640, 480};
        const Size no_size{0, 0};
        const Position pos100{100, 100};

        Window window(name(), size640);

        window.show();
        window.set_position(pos100);

        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_resizable(false);

        // No other values were changed
        TEST_ASSERT(!window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");
        TEST_ASSERT(window.position() == pos100, "Window has wrong position.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void window_resizability_before_show()
    {
        const Size no_size{0, 0};
        const Size size640{640, 480};

        Window window(name(), size640);

        window.set_resizable(false);
        window.show();

        TEST_ASSERT(!window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");

        window.set_resizable(true);

        // No other values were changed
        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");
    }

    void window_resizability_and_size()
    {
        const Size size480{480, 320};
        const Size size640{640, 480};
        const Size size960{960, 640};

        Window window(name(), size640);

        window.set_resizable(false);

        window.set_size(size480);
        window.set_min_size(size480);
        window.set_max_size(size960);

        window.show();

        // Can change size limits, and window size
        TEST_ASSERT(!window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_resizable(true);

        // Size limits and window size still are the same
        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.set_size({1000, 1000});

        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size960, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void subscribe_for_events(Window& window)
    {
        window.set_on_show_callback([this, &window]() {
            TEST_ASSERT(window.is_visible(), "The on_show callback was received for non visible window.");
            m_stats.on_show_called++;
        });
        window.set_on_hide_callback([this, &window]() {
            TEST_ASSERT(!window.is_visible(), "The on_hide callback was received for visible window.");
            m_stats.on_hide_called++;
        });
        window.set_on_resize_callback([this, &window](Size size) {
            TEST_ASSERT(window.is_visible(), "The on_resize callback was received for non visible window.");
            m_stats.on_resize_called++;
            m_stats.last_size = size;
        });
        window.set_on_move_callback([this, &window](Position position) {
            TEST_ASSERT(window.is_visible(), "The on_move callback was received for non visible window.");
            m_stats.on_move_called++;
            m_stats.last_position = position;
        });
        window.set_on_focus_callback([this, &window]() {
            TEST_ASSERT(window.is_visible(), "The on_focus callback was received for non visible window.");
            m_stats.on_focus_called++;
        });
        window.set_on_lost_focus_callback([this, &window]() {
            TEST_ASSERT(window.is_visible(), "The on_lost_focus callback was received for non visible window.");
            m_stats.on_lost_focus_called++;
        });
    }

    Stats m_stats;
};

int main()
{
    return run_tests(WindowResizeTest());
}
