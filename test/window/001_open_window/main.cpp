#include <chrono>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_test : public framework::unit_test::suite
{
public:
    window_test()
        : suite("window_test")
    {
        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
    }

private:
    void open_window()
    {
        constexpr std::chrono::milliseconds timespan(100);

        framework::window window;
        window.show();

        std::this_thread::sleep_for(timespan);

        TEST_ASSERT(window.visible(), "Window is not visible.");

        std::this_thread::sleep_for(timespan);

        window.hide();

        TEST_ASSERT(!window.visible(), "Window is still visible.");
    }

    void open_several_windows()
    {
        constexpr std::chrono::milliseconds timespan(100);

        framework::window window1;
        framework::window window2;
        framework::window window3;
        framework::window window4;
        framework::window window5;

        window1.show();
        window2.show();
        window3.show();
        window4.show();
        window5.show();

        std::this_thread::sleep_for(timespan);

        window1.hide();
        window2.hide();
        window3.hide();
        window4.hide();
        window5.hide();

        std::this_thread::sleep_for(timespan);

        window1.show();
        window2.show();
        window3.show();
        window4.show();
        window5.show();
    }
};

int main()
{
    return run_tests(window_test());
}
