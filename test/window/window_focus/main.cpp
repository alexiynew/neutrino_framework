#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_focus_test : public framework::unit_test::suite
{
public:
    window_focus_test() : suite("window_focus_test")
    {
        add_test([this]() { focus_window(); }, "focus_window");
    }

private:
    void focus_window()
    {
        framework::window alpha({640, 480}, "Test");
        framework::window betta({640, 480}, "Test");

        alpha.show();
        betta.show();

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");

        alpha.focus();

        TEST_ASSERT(alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(!betta.focused(), "Focus function is not working.");
    }
};

int main()
{
    return run_tests(window_focus_test());
}
