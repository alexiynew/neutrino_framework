#include <graphic/window.hpp>
#include <unit_test/suite.hpp>

class window_properties_test : public framework::unit_test::suite
{
public:
    window_properties_test() : suite("window_properties_test")
    {
        add_test([this]() { window_size(); }, "window_size");
        add_test([this]() { window_size_limits(); }, "window_size_limits");
        add_test([this]() { window_resizability(); }, "window_resizability");
        add_test([this]() { window_position(); }, "window_position");
        add_test([this]() { window_title(); }, "window_title");
    }

private:
    void window_size()
    {
        using ::framework::graphic::window;

        const window::size_t size480{480, 320};
        const window::size_t size640{640, 480};

        window w({480, 320}, "Test");

        TEST_ASSERT(w.size() == size480, "Window has wrong size.");

        w.show();

        TEST_ASSERT(w.size() == size480, "Window has wrong size.");

        w.set_size({640, 480});

        TEST_ASSERT(w.size() == size640, "Window has wrong size.");

        w.hide();
        w.show();

        TEST_ASSERT(w.size() == size640, "Window has wrong size.");
    }

    void window_size_limits()
    {
        using ::framework::graphic::window;

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
        using ::framework::graphic::window;

        const window::size_t size480{480, 320};
        const window::size_t size640{640, 480};
        const window::size_t size960{960, 640};
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

    void window_position()
    {
        using ::framework::graphic::window;

        window::size_t size640 = {640, 480};

        window w(size640, "Test");

        w.show();

        w.set_position({100, 100});

        auto position = w.position();

        // Can't really check window position. Different WM can give different values.
        TEST_ASSERT(position.x > -100000 && position.y > -100000, "Window always has position.");

        TEST_ASSERT(w.size() == size640, "Window should save its size.");
    }

    void window_title()
    {
        using ::framework::graphic::window;

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
