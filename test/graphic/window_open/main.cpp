#include <graphic/window.hpp>
#include <unit_test/suite.hpp>

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
        using ::framework::graphic::window;

        window w({640, 480}, "Test");
        w.show();

        TEST_ASSERT(w.visible(), "Window is not visible.");

        w.hide();

        TEST_ASSERT(!w.visible(), "Window is still visible.");
    }

    void open_several_windows()
    {
        using ::framework::graphic::window;

        window windows[5] = {
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
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
