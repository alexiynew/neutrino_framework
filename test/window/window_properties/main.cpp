#include <chrono>
#include <thread>

#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_properties_test : public framework::unit_test::suite
{
public:
    window_properties_test() : suite("window_properties_test")
    {
        add_test([this]() { window_size(); }, "window_size");
        add_test([this]() { window_size_limits(); }, "window_size_limits");
        add_test([this]() { window_position(); }, "window_position");
        add_test([this]() { window_title(); }, "window_title");
    }

private:
    void window_size()
    {
        constexpr std::chrono::milliseconds timespan(50);

        const ::framework::window::size_t size480{480, 320};
        const ::framework::window::size_t size640{640, 480};

        ::framework::window window({480, 320});

        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.size() == size480, "Window has wrong size.");

        window.set_size({640, 480});

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.hide();
        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.size() == size640, "Window has wrong size.");
    }

    void window_size_limits()
    {
        constexpr std::chrono::milliseconds timespan(50);

        const ::framework::window::size_t size480{480, 320};
        const ::framework::window::size_t size640{640, 480};
        const ::framework::window::size_t no_size{-1, -1};

        ::framework::window window({480, 320});

        TEST_ASSERT(window.min_size() == no_size, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == no_size, "Window has wrong max size.");

        window.set_min_size(size480);
        window.set_max_size(size640);

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
        TEST_ASSERT(window.min_size() == size480, "Window has wrong min size.");
        TEST_ASSERT(window.max_size() == size640, "Window has wrong max size.");

        window.set_size({1000, 1000});

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.size() == size640, "Window has wrong size.");

        window.set_size({100, 100});

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.size() == size480, "Window has wrong size.");
    }

    void window_position()
    {
        constexpr std::chrono::milliseconds timespan(50);

        ::framework::window window({640, 480});

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        window.set_position({100, 100});

        std::this_thread::sleep_for(timespan);
        window.process_events();

        auto position = window.position();

        // Can't really check window position. Different WM can give different values.
        TEST_ASSERT(position.x > 0 && position.y > 0, "Window always has position.");
    }

    void window_title()
    {
        constexpr std::chrono::milliseconds timespan(50);

        const std::string title     = u8"winodw_title";
        const std::string new_title = u8"new_window_title";

        ::framework::window window({640, 480}, title);

        window.show();

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.title() == title, "Window has wrong title");

        window.set_title(new_title);

        std::this_thread::sleep_for(timespan);
        window.process_events();

        TEST_ASSERT(window.title() == new_title, "Window has wrong title");
    }
};

int main()
{
    return run_tests(window_properties_test());
}
