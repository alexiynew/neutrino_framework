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
        add_test([this]() { iconify_window(); }, "iconify_window");
        add_test([this]() { maximize_window(); }, "maximize_window");
        add_test([this]() { fullscreen_before_show(); }, "fullscreen_before_show");
        add_test([this]() { maximized_before_show(); }, "maximized_before_show");
        add_test([this]() { window_resizability(); }, "window_resizability");
        add_test([this]() { window_resizability_and_size(); }, "window_resizability_and_size");
        add_test([this]() { window_resizability_before_show(); }, "window_resizability_before_show");
    }

private:
    void fullscreen_window()
    {
        const Size size640{640, 480};

        Window w(name(), size640);

        w.show();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.fullscreen();

        TEST_ASSERT(w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        w.hide();
        w.show();

        TEST_ASSERT(w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        w.restore();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void iconify_window()
    {
        const Size size640{640, 480};

        Window w(name(), size640);

        w.show();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.iconify();

        // Window is iconified, but still on screen (visible)
        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

        w.hide();
        w.show();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.iconify();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(!w.has_input_focus(), "Invalid window state.");

        w.restore();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void maximize_window()
    {
        const Size size640{640, 480};

        Window w(name(), size640);

        w.show();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.maximize();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        w.hide();
        w.show();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");

        w.restore();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void fullscreen_before_show()
    {
        const Size size640{640, 480};

        Window w(name(), size640);

        w.fullscreen();
        w.show();

        TEST_ASSERT(w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(!w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
    }

    void maximized_before_show()
    {
        const Size size640{640, 480};

        Window w(name(), size640);

        w.maximize();
        w.show();

        TEST_ASSERT(!w.is_fullscreen(), "Invalid window state.");
        TEST_ASSERT(!w.is_iconified(), "Invalid window state.");
        TEST_ASSERT(w.is_maximized(), "Invalid window state.");
        TEST_ASSERT(w.is_visible(), "Invalid window state.");
        TEST_ASSERT(w.has_input_focus(), "Invalid window state.");
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
};

int main()
{
    return run_tests(WindowStateTest());
}
