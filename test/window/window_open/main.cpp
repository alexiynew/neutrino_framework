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
        ::framework::window window({640, 480}, "Test");
        window.show();

        TEST_ASSERT(window.visible(), "Window is not visible.");

        window.hide();

        TEST_ASSERT(!window.visible(), "Window is still visible.");
    }

    void open_several_windows()
    {
        using ::framework::window;

        window windows[5] = {
        window({640, 480}, "Test1"),
        window({640, 480}, "Test2"),
        window({640, 480}, "Test3"),
        window({640, 480}, "Test4"),
        window({640, 480}, "Test5"),
        };

        for (auto& w : windows) {
            w.show();
        }

        for (auto& w : windows) {
            w.hide();
        }

        for (auto& w : windows) {
            w.show();
        }
    }
};

int main()
{
    return run_tests(window_open_test());
}
