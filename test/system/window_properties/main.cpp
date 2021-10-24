// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <chrono>
#include <thread>

#include <log/log.hpp>
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
        // add_test([this]() { window_resizability(); }, "window_resizability");
        // add_test([this]() { window_resizability_and_size(); }, "window_resizability_and_size");
        // add_test([this]() { window_resizability_before_show(); }, "window_resizability_before_show");
        // add_test([this]() { window_position(); }, "window_position");
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

        window.on_show.connect([&stats](const Window& /*unused*/) { stats.show_called++; });

        window.on_resize.connect([&stats, this](const Window& w, Size w_size) {
            stats.size_called++;
            stats.last_size = w_size;

            TEST_ASSERT(w.is_visible(), "Window must be visible to send on_resize callbacks.");
        });

        // Check stats
        TEST_ASSERT(stats.size_called == 0, "Wrong stats.size_called count in begining.");
        TEST_ASSERT(stats.show_called == 0, "Wrong stats.show_called count in begining.");
        TEST_ASSERT(stats.last_size == Size(), "Wrong stats.last_size in begining.");

        // Window stats on creation
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        // Show window - must be 480
        window.show();

        TEST_ASSERT(stats.show_called == 1, "On_show callback must be called once.");
        TEST_ASSERT(stats.size_called == 1, "On_resize callback must be called once.");
        TEST_ASSERT(stats.last_size == size480, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.is_visible(), "Window must be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Resize window - must be 640
        window.resize({640, 480});
        std::this_thread::sleep_for(std::chrono::seconds(1));

        TEST_ASSERT(stats.show_called == 1, "On_show callback must be called once.");
        TEST_ASSERT(stats.size_called == 2, "On_resize callback must be called twice.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        // Hide and show window - must be still 640
        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window must not be visible.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(stats.show_called == 2, "On_show callback must be called twice.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must be called 3 times.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.is_visible(), "Window must be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Resize hidden window - no callbacks, size changed
        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window must not be visible.");

        window.resize(size480);

        TEST_ASSERT(stats.show_called == 2, "On_show callback must not be called while size changed.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must not be called while window is not visible.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        window.resize(size640);

        TEST_ASSERT(stats.show_called == 2, "On_show callback must not be called while size changed.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must not be called while window is not visible.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.resize(size480);

        TEST_ASSERT(stats.show_called == 2, "On_show callback must not be called while size changed.");
        TEST_ASSERT(stats.size_called == 3, "On_resize callback must not be called while window is not visible.");
        TEST_ASSERT(stats.last_size == size640, "Wrong window size in callback.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        // For some reason on macOS if to show window immediately after resizing it won't be shown.
        // Some time needs to pass and after that window.process_events() will force the window to appear on the screen.
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();

        TEST_ASSERT(stats.show_called == 3, "On_show callback must be called 3 times.");
        TEST_ASSERT(stats.size_called == 4, "On_resize callback must be called 4 times.");
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
        window.resize(big_size);
        TEST_ASSERT(window.size() == size960, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.resize(small_size);
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // No more limits. Can change size as we want
        window.set_min_size(no_size);
        window.set_max_size(no_size);

        window.resize(small_size);
        TEST_ASSERT(window.size() == small_size, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.resize(big_size);
        TEST_ASSERT(window.size() == big_size, "Window has wrong size.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // TODO: Size limits should resize the window if it does not fit within the constraints
        //// Set size limits while the window is oversized
        // window.set_max_size(size960);
        // TEST_ASSERT(window.size() == size960, "Window has wrong size.");
        // std::this_thread::sleep_for(std::chrono::seconds(1));

        //// Set size limits while the window is undersized
        // window.resize(small_size);
        // window.set_min_size(size640);
        // TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        // std::this_thread::sleep_for(std::chrono::seconds(1));

        // TODO: Add test for partial set/unset size limits
    }

    void window_resizability()
    {
        const Size size640{640, 480};
        const Size no_size{0, 0};

        Window window(name(), size640);

        window.show();

        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");

        window.set_resizable(false);

        // No other values were changed
        TEST_ASSERT(!window.is_resizable(), "Window has wrong state.");
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

        window.show();

        window.set_resizable(false);

        window.resize(size480);
        window.set_min_size(size480);
        window.set_max_size(size960);

        // Can change size limits, and window size
        TEST_ASSERT(!window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        window.set_resizable(true);

        // Size limits and window size still are the same
        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        window.resize({1000, 1000});

        TEST_ASSERT(window.is_resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size960, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");
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

    void window_position()
    {
        bool on_position_called = false;
        Size size640            = {640, 480};

        Window window(name(), size640);

        window.on_move.connect(
        [&on_position_called](const Window& /*unused*/, Position /*unused*/) { on_position_called = true; });

        window.show();

        window.move({100, 100});

        auto position = window.position();

        TEST_ASSERT(on_position_called == true, "On position should be called.");

        // Can't really check window position. Different WM can give different values.
        TEST_ASSERT(position.x > -100000 && position.y > -100000, "Window always has position.");

        TEST_ASSERT(window.size() == size640, "Window should save its size.");
    }

    void window_title()
    {
        const std::string title      = u8"winodw_title";
        const std::string new_title  = u8"new_window_title";
        const std::string utf8_title = u8"พᛁቢ⠗☺w ⊤Iτსе";

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

        void reset()
        {
            show_called = 0;
            size_called = 0;
            last_size   = Size();
        }
    };
};

int main()
{
    return run_tests(WindowPropertiesTest());
}
