#include <chrono>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

#pragma mark - test for window

class window_test : public framework::unit_test::suite
{
public:
    window_test()
        : suite("window_test")
    {
        add_test([this]() { open_window(); }, "open_window");
    }

private:
    void open_window()
    {
        framework::window window;
        window.show();

        std::chrono::seconds timespan(1);
        std::this_thread::sleep_for(timespan);

        window.hide();
    }
};

int main()
{
    return run_tests(window_test());
}
