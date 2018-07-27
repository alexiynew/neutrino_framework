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
        add_test([this]() { window_position(); }, "window_position");
        add_test([this]() { window_title(); }, "window_title");
    }

private:
    void window_size()
    {
        const ::framework::window::size_t size480{480, 320};
        const ::framework::window::size_t size640{640, 480};

        ::framework::window window({480, 320}, "Test");

        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        window.show();

        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        window.set_size({640, 480});

        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.hide();
        window.show();

        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void window_size_limits()
    {
        const ::framework::window::size_t size640{640, 480};
        const ::framework::window::size_t size960{960, 640};
        const ::framework::window::size_t no_size{0, 0};
        const ::framework::window::size_t small_size{150, 150};
        const ::framework::window::size_t big_size{1000, 1000};

        ::framework::window window({640, 480}, "Test");

        // Base values
        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");

        window.set_min_size(size640);
        window.set_max_size(size960);

        window.show();

        // All sizes setted up correctly
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size640, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        // Check size limits
        window.set_size(big_size);

        TEST_ASSERT(window.size() == size960, "Window has wrong size.");

        window.set_size(small_size);

        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        // No more limits. Can change size as we want
        window.set_min_size(no_size);
        window.set_max_size(no_size);

        window.set_size(small_size);

        TEST_ASSERT(window.size() == small_size, "Window has wrong size.");

        window.set_size(big_size);

        TEST_ASSERT(window.size() == big_size, "Window has wrong size.");
    }

    void window_resizability()
    {
        const ::framework::window::size_t size480{480, 320};
        const ::framework::window::size_t size640{640, 480};
        const ::framework::window::size_t size960{960, 640};
        const ::framework::window::size_t no_size{0, 0};

        ::framework::window window(size640, "Test");

        window.show();

        TEST_ASSERT(window.resizable(), "Window has wrong state.");

        window.set_resizable(false);

        // No other values were changed
        TEST_ASSERT(!window.resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");

        window.set_size(size480);
        window.set_min_size(size480);
        window.set_max_size(size960);

        // Can change size limits, and window size
        TEST_ASSERT(!window.resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        window.set_resizable(true);

        // Size limits and window size still are the same
        TEST_ASSERT(window.resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");

        window.set_size({1000, 1000});

        TEST_ASSERT(window.resizable(), "Window has wrong state.");
        TEST_ASSERT(window.size() == size960, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size960, "Window has wrong max size.");
    }

    void window_position()
    {
        ::framework::window::size_t size640 = {640, 480};

        ::framework::window window(size640, "Test");

        window.show();

        window.set_position({100, 100});

        auto position = window.position();

        // Can't really check window position. Different WM can give different values.
        TEST_ASSERT(position.x > -100000 && position.y > -100000, "Window always has position.");

        TEST_ASSERT(window.size() == size640, "Window should save its size.");
    }

    void window_title()
    {
        const std::string title      = u8"winodw_title";
        const std::string new_title  = u8"new_window_title";
        const std::string utf8_title = u8"พᛁቢ⠗☺w ⊤Iτსе";

        ::framework::window window({640, 480}, title);

        window.show();

        TEST_ASSERT(window.title() == title, "Window has wrong title");

        window.set_title(new_title);

        TEST_ASSERT(window.title() == new_title, "Window has wrong title");

        window.set_title(utf8_title);

        TEST_ASSERT(window.title() == utf8_title, "Window has wrong title");
    }
};

int main()
{
    return run_tests(window_properties_test());
}
