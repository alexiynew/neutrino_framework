#include <chrono>
#include <thread>

#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::system;

class WindowStateTest : public framework::unit_test::Suite
{
public:
    WindowStateTest()
        : Suite("WindowStateTest")
    {
        add_test([this]() { fullscreen_window(); }, "fullscreen_window");
        add_test([this]() { fullscreen_before_show(); }, "fullscreen_before_show");

        add_test([this]() { maximize_window(); }, "maximize_window");
        add_test([this]() { maximized_before_show(); }, "maximized_before_show");

        add_test([this]() { iconify_window(); }, "iconify_window");

        add_test([this]() { fullscreen_iconify_fullscreen_normal(); }, "fullscreen_iconify_fullscreen_normal");
        add_test([this]() { maximized_iconify_maximized_normal(); }, "maximized_iconify_maximized_normal");
        add_test([this]() { maximized_fullscreen_maximized_normal(); }, "maximized_fullscreen_maximized_normal");
        add_test([this]() { normal_fullscreen_maximized_iconify(); }, "normal_fullscreen_maximized_iconify");
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

    void fullscreen_window()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};
        m_stats.reset();

        {
            Window w("fullscreen_window", size640);
            subscribe_for_events(w);

            TEST_ASSERT(m_stats.on_show_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            w.set_position(position100);
            w.show();

            // Check stats
            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
            TEST_ASSERT(w.size() == size640, "Window has wrong size.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Switch to fullscreen
            w.set_state(Window::State::fullscreen);
            w.set_state(Window::State::fullscreen);
            w.set_state(Window::State::fullscreen);
            w.set_state(Window::State::fullscreen);

            TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size != size640, "Invalid size in callback.");
            TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Hide and show again - must be still fullscreen
            w.hide();

            TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            w.show();

            TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 3, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size != size640, "Invalid size in callback.");
            TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Return to normal state
            w.set_state(Window::State::normal);

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
            TEST_ASSERT(w.size() == size640, "Window has wrong size.");

            TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 4, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 4, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 4, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 4, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == size640, "Invalid size in callback.");
        TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");
    }

    void fullscreen_before_show()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};
        m_stats.reset();

        {
            Window w("fullscreen_before_show", size640);
            subscribe_for_events(w);

            w.set_position(position100);
            w.set_state(Window::State::fullscreen);

            TEST_ASSERT(m_stats.on_show_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");

            w.show();

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size != size640, "Invalid size in callback.");
            TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

            TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            w.set_state(Window::State::normal);

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");
    }

    void maximize_window()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};

        m_stats.reset();

        {
            Window w("maximize_window", size640);
            subscribe_for_events(w);

            w.set_position(position100);
            w.show();

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
            TEST_ASSERT(w.size() == size640, "Window has wrong size.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            // On macOS maximization of the window cause several on_resize callbacks.
            m_stats.on_resize_called = 0;
            w.set_state(Window::State::maximized);
            w.set_state(Window::State::maximized);
            w.set_state(Window::State::maximized);
            w.set_state(Window::State::maximized);

            TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(w.size() != size640, "Window has wrong size.");
            TEST_ASSERT(w.size() == m_stats.last_size, "Wrong window size in callback.");
            TEST_ASSERT(m_stats.last_position != position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            w.hide();

            TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
            TEST_ASSERT(!w.is_visible(), "Invalid window state.");
            TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            std::this_thread::sleep_for(std::chrono::seconds(1));
            m_stats.on_resize_called = 0;
            w.show();

            TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(w.size() != size640, "Window has wrong size.");
            TEST_ASSERT(w.size() == m_stats.last_size, "Wrong window size in callback.");
            TEST_ASSERT(m_stats.last_position != position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            m_stats.on_resize_called = 0;
            w.set_state(Window::State::normal);

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
            TEST_ASSERT(w.size() == size640, "Window has wrong size.");

            TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 4, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            m_stats.on_resize_called = 0;
        }

        TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 4, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");
    }

    void maximized_before_show()
    {
        const Size size640{640, 480};

        m_stats.reset();

        Window w("maximized_before_show", size640);
        subscribe_for_events(w);

        w.set_state(Window::State::maximized);

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(!w.is_visible(), "Invalid window state.");
        TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == Size(0, 0), "Invalid last size in callback.");

        w.show();

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");

        // On macOS maximization of the window cause several on_resize callbacks.
        TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size != size640, "Invalid last size in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void iconify_window()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};
        m_stats.reset();

        {
            Window w("iconify_window", size640);
            subscribe_for_events(w);

            w.set_position(position100);
            w.show();

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
            TEST_ASSERT(w.size() == size640, "Window has wrong size.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            w.set_state(Window::State::iconified);
            w.set_state(Window::State::iconified);
            w.set_state(Window::State::iconified);
            w.set_state(Window::State::iconified);

            TEST_ASSERT(w.state() == Window::State::iconified, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Show does nothing
            w.show();

            TEST_ASSERT(w.state() == Window::State::iconified, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            w.set_state(Window::State::normal);

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            w.set_state(Window::State::iconified);
            w.hide();

            TEST_ASSERT(w.state() == Window::State::iconified, "Invalid window state.");
            TEST_ASSERT(!w.is_visible(), "Invalid window state.");
            TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 2, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));

            w.show();

            TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
            TEST_ASSERT(w.is_visible(), "Invalid window state.");
            TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

            TEST_ASSERT(m_stats.on_show_called == 2, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_hide_called == 1, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_resize_called == 3, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_focus_called == 3, "Invalid callback call.");
            TEST_ASSERT(m_stats.on_lost_focus_called == 2, "Invalid callback call.");

            TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
            TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    void fullscreen_iconify_fullscreen_normal()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};

        m_stats.reset();

        Window w("fullscreen_iconify_fullscreen_normal", size640);
        subscribe_for_events(w);

        w.set_position(position100);
        w.set_state(Window::State::fullscreen);
        w.show();

        const Size fullscreen_size = w.size();

        TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == fullscreen_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::iconified);

        TEST_ASSERT(w.state() == Window::State::iconified, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == fullscreen_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::fullscreen);

        TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == fullscreen_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::normal);

        TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 3, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void maximized_iconify_maximized_normal()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};

        m_stats.reset();

        Window w("maximized_iconify_maximized_normal", size640);
        subscribe_for_events(w);

        w.set_position(position100);
        w.set_state(Window::State::maximized);
        w.show();

        const Size maximized_size         = w.size();
        const Position maximized_position = w.position();

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == maximized_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == maximized_position, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        m_stats.on_resize_called = 0;
        w.set_state(Window::State::iconified);

        TEST_ASSERT(w.state() == Window::State::iconified, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == maximized_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == maximized_position, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::maximized);

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == maximized_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == maximized_position, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        m_stats.on_resize_called = 0;
        w.set_state(Window::State::normal);

        TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void maximized_fullscreen_maximized_normal()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};

        m_stats.reset();

        Window w("maximized_fullscreen_maximized_normal", size640);
        subscribe_for_events(w);

        w.set_position(position100);
        w.set_state(Window::State::maximized);
        w.show();

        const Size maximized_size         = w.size();
        const Position maximized_position = w.position();

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == maximized_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == maximized_position, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        m_stats.on_resize_called = 0;
        w.set_state(Window::State::fullscreen);

        TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size != maximized_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::maximized);

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == maximized_size, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == maximized_position, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        m_stats.on_resize_called = 0;
        w.set_state(Window::State::normal);

        TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called > 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 4, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void normal_fullscreen_maximized_iconify()
    {
        const Size size640{640, 480};
        const Position position100{100, 100};

        m_stats.reset();

        Window w("normal_fullscreen_maximized_iconify", size640);
        subscribe_for_events(w);

        w.set_position(position100);
        w.set_state(Window::State::normal);
        w.show();

        TEST_ASSERT(w.state() == Window::State::normal, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size == size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == position100, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::fullscreen);

        TEST_ASSERT(w.state() == Window::State::fullscreen, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size != size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position == Position(0, 0), "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        w.set_state(Window::State::maximized);

        TEST_ASSERT(w.state() == Window::State::maximized, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called > 2, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 0, "Invalid callback call.");

        TEST_ASSERT(m_stats.last_size != size640, "Invalid last size in callback.");
        TEST_ASSERT(m_stats.last_position != position100, "Invalid position in callback.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        m_stats.on_resize_called = 0;
        w.set_state(Window::State::iconified);

        TEST_ASSERT(w.state() == Window::State::iconified, "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

        TEST_ASSERT(m_stats.on_show_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_hide_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_resize_called == 0, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_move_called == 3, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_focus_called == 1, "Invalid callback call.");
        TEST_ASSERT(m_stats.on_lost_focus_called == 1, "Invalid callback call.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void subscribe_for_events(Window& window)
    {
        window.on_show.connect([this](const Window& w) {
            TEST_ASSERT(w.is_visible(), "The on_show callback was received for non visible window.");
            m_stats.on_show_called++;
        });
        window.on_hide.connect([this](const Window& w) {
            TEST_ASSERT(!w.is_visible(), "The on_hide callback was received for visible window.");
            m_stats.on_hide_called++;
        });
        window.on_resize.connect([this](const Window& w, Size size) {
            TEST_ASSERT(w.is_visible(), "The on_resize callback was received for non visible window.");
            m_stats.on_resize_called++;
            m_stats.last_size = size;
        });
        window.on_move.connect([this](const Window& w, Position position) {
            TEST_ASSERT(w.is_visible(), "The on_move callback was received for non visible window.");
            m_stats.on_move_called++;
            m_stats.last_position = position;
        });
        window.on_focus.connect([this](const Window& w) {
            TEST_ASSERT(w.is_visible(), "The on_focus callback was received for non visible window.");
            m_stats.on_focus_called++;
        });
        window.on_lost_focus.connect([this](const Window& w) {
            TEST_ASSERT(w.is_visible(), "The on_lost_focus callback was received for non visible window.");
            m_stats.on_lost_focus_called++;
        });
    }

    Stats m_stats;
};

int main()
{
    return run_tests(WindowStateTest());
}