#include <graphic/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework::graphic;

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
        window alpha({640, 480});
        window betta({640, 480});

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
