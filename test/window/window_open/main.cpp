#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_open_test : public framework::unit_test::suite
{
public:
    window_open_test() : suite("window_open_test")
    {
        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
    }

private:
    void open_window()
    {
        ::framework::window window({640, 480});
        window.show();

        TEST_ASSERT(window.visible(), "Window is not visible.");

        window.hide();

        TEST_ASSERT(!window.visible(), "Window is still visible.");
    }

    void open_several_windows()
    {
        ::framework::window windows[5] = {
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        ::framework::window::size_t{640, 480},
        };

        for (auto& window : windows) {
            window.show();
        }

        for (auto& window : windows) {
            window.hide();
        }

        for (auto& window : windows) {
            window.show();
        }
    }
};

int main()
{
    return run_tests(window_open_test());
}
