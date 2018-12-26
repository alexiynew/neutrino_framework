
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_properties_test : public framework::unit_test::suite
{
public:
    window_properties_test() : suite("window_properties_test")
    {
        add_test([this]() { window_size(); }, "window_size");
        add_test([this]() { window_size_limits(); }, "window_size_limits");
        add_test([this]() { window_resizability(); }, "window_resizability");
        add_test([this]() { window_resizability_and_size(); }, "window_resizability_and_size");
        add_test([this]() { window_resizability_before_show(); }, "window_resizability_before_show");
        add_test([this]() { window_position(); }, "window_position");
        add_test([this]() { window_title(); }, "window_title");
    }

private:
    void window_size()
    {
        using ::framework::system::window;

        bool on_size_called = false;

        const window::size_t size480{480, 320};
        const window::size_t size640{640, 480};

        window w({480, 320}, "Test");

        w.on_size = [&on_size_called](const window& /*unused*/, window::size_t /*unused*/) { on_size_called = true; };

        TEST_ASSERT(w.size() == size480, "Window has wrong size.");

        w.show();

        TEST_ASSERT(on_size_called == true, "On size should be called.");
        TEST_ASSERT(w.size() == size480, "Window has wrong size.");

        on_size_called = false;
        w.set_size({640, 480});

        TEST_ASSERT(on_size_called == true, "On size should be called.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.hide();
        on_size_called = false;
        w.show();

        TEST_ASSERT(on_size_called == true, "On size should be called.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.hide();
        w.set_size({480, 320});
        on_size_called = false;
        w.show();

        TEST_ASSERT(on_size_called == true, "On size should be called.");
        TEST_ASSERT(w.size() == size480, "Window has wrong size.");
    }

    void window_size_limits()
    {
        using ::framework::system::window;

        const window::size_t size640{640, 480};
        const window::size_t size960{960, 640};
        const window::size_t no_size{0, 0};
        const window::size_t small_size{150, 150};
        const window::size_t big_size{1000, 1000};

        window w({640, 480}, "Test");

        // Base values
        TEST_ASSERT(w.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == no_size, "Window has wrong max size.");

        w.set_min_size(size640);
        w.set_max_size(size960);

        w.show();

        // All sizes setted up correctly
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
        TEST_ASSERT(w.min_size() == size640, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == size960, "Window has wrong max size.");

        // Check size limits
        w.set_size(big_size);

        TEST_ASSERT(w.size() == size960, "Window has wrong size.");

        w.set_size(small_size);

        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        // No more limits. Can change size as we want
        w.set_min_size(no_size);
        w.set_max_size(no_size);

        w.set_size(small_size);

        TEST_ASSERT(w.size() == small_size, "Window has wrong size.");

        w.set_size(big_size);

        TEST_ASSERT(w.size() == big_size, "Window has wrong size.");
    }

    void window_resizability()
    {
        using ::framework::system::window;

        const window::size_t size640{640, 480};
        const window::size_t no_size{0, 0};

        window w(size640, "Test");

        w.show();

        TEST_ASSERT(w.resizable(), "Window has wrong state.");

        w.set_resizable(false);

        // No other values were changed
        TEST_ASSERT(!w.resizable(), "Window has wrong state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
        TEST_ASSERT(w.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == no_size, "Window has wrong max size.");
    }

    void window_resizability_and_size()
    {
        using ::framework::system::window;

        const window::size_t size480{480, 320};
        const window::size_t size640{640, 480};
        const window::size_t size960{960, 640};

        window w(size640, "Test");

        w.show();

        w.set_resizable(false);

        w.set_size(size480);
        w.set_min_size(size480);
        w.set_max_size(size960);

        // Can change size limits, and window size
        TEST_ASSERT(!w.resizable(), "Window has wrong state.");
        TEST_ASSERT(w.size() == size480, "Window has wrong size.");
        TEST_ASSERT(w.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == size960, "Window has wrong max size.");

        w.set_resizable(true);

        // Size limits and window size still are the same
        TEST_ASSERT(w.resizable(), "Window has wrong state.");
        TEST_ASSERT(w.size() == size480, "Window has wrong size.");
        TEST_ASSERT(w.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == size960, "Window has wrong max size.");

        w.set_size({1000, 1000});

        TEST_ASSERT(w.resizable(), "Window has wrong state.");
        TEST_ASSERT(w.size() == size960, "Window has wrong size.");
        TEST_ASSERT(w.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == size960, "Window has wrong max size.");
    }

    void window_resizability_before_show()
    {
        using ::framework::system::window;

        const window::size_t no_size{0, 0};
        const window::size_t size640{640, 480};

        window w(size640, "Test");

        w.set_resizable(false);

        w.show();

        TEST_ASSERT(!w.resizable(), "Window has wrong state.");

        w.set_resizable(true);

        // No other values were changed
        TEST_ASSERT(w.resizable(), "Window has wrong state.");
        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
        TEST_ASSERT(w.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(w.max_size() == no_size, "Window has wrong max size.");
    }

    void window_position()
    {
        using ::framework::system::window;

        bool on_position_called = false;
        window::size_t size640  = {640, 480};

        window w(size640, "Test");

        w.on_position = [&on_position_called](const window& /*unused*/, window::position_t /*unused*/) {
            on_position_called = true;
        };

        w.show();

        w.set_position({100, 100});

        auto position = w.position();

        TEST_ASSERT(on_position_called == true, "On position should be called.");

        // Can't really check window position. Different WM can give different values.
        TEST_ASSERT(position.x > -100000 && position.y > -100000, "Window always has position.");

        TEST_ASSERT(w.size() == size640, "Window should save its size.");
    }

    void window_title()
    {
        using ::framework::system::window;

        const std::string title      = u8"winodw_title";
        const std::string new_title  = u8"new_window_title";
        const std::string utf8_title = u8"พᛁቢ⠗☺w ⊤Iτსе";

        window w({640, 480}, title);

        w.show();

        TEST_ASSERT(w.title() == title, "Window has wrong title");

        w.set_title(new_title);

        TEST_ASSERT(w.title() == new_title, "Window has wrong title");

        w.set_title(utf8_title);

        TEST_ASSERT(w.title() == utf8_title, "Window has wrong title");
    }
};

int main()
{
    return run_tests(window_properties_test());
}
