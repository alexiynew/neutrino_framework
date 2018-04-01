#include <chrono>
#include <thread>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_focus_test : public framework::unit_test::suite
{
public:
    window_focus_test()
        : suite("window_focus_test")
    {
        add_test([this]() { focus_window(); }, "focus_window");
    }

private:
    void focus_window()
    {
        constexpr std::chrono::milliseconds timespan(10);

        framework::window alpha;
        framework::window betta;

        alpha.show();
        betta.show();

        std::this_thread::sleep_for(timespan);
        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");

        alpha.focus();

        std::this_thread::sleep_for(timespan);
        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(!betta.focused(), "Focus function is not working.");
    }
};

int main()
{
    return run_tests(window_focus_test());
}
