#include <chrono>
#include <iostream>
#include <thread>

#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework::system;

class WindowFocusTest : public framework::unit_test::Suite
{
public:
    WindowFocusTest()
        : Suite("WindowFocusTest")
    {
        add_test([this]() { focus_one_window(); }, "focus_one_windows");
        add_test([this]() { focus_two_windows(); }, "focus_two_windows");
    }

private:
    void focus_one_window()
    {
        int on_focus_called      = 0;
        int on_lost_focus_called = 0;

        Window w(name(), {640, 480});

        w.set_on_focus_callback([&on_focus_called]() { on_focus_called++; });
        w.set_on_lost_focus_callback([&on_lost_focus_called]() { on_lost_focus_called++; });

        w.request_input_focus();

        TEST_ASSERT(on_focus_called == 0, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 0");
        TEST_ASSERT(on_lost_focus_called == 0,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 0");

        w.show();

        TEST_ASSERT(w.is_visible(), "Window should be visible.");
        TEST_ASSERT(w.has_input_focus(), "Window should has focus.");

        TEST_ASSERT(on_focus_called == 1, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 1");
        TEST_ASSERT(on_lost_focus_called == 0,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 0");

        w.request_input_focus();

        TEST_ASSERT(on_focus_called == 1, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 1");
        TEST_ASSERT(on_lost_focus_called == 0,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 0");

        w.hide();

        TEST_ASSERT(!w.is_visible(), "Window should be visible.");
        TEST_ASSERT(!w.has_input_focus(), "Window should has focus.");

        TEST_ASSERT(on_focus_called == 1, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 1");
        TEST_ASSERT(on_lost_focus_called == 1,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 1");

        w.request_input_focus();

        TEST_ASSERT(on_focus_called == 1, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 1");
        TEST_ASSERT(on_lost_focus_called == 1,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 1");

        w.show();

        TEST_ASSERT(w.is_visible(), "Window should be visible.");
        TEST_ASSERT(w.has_input_focus(), "Window should has focus.");

        TEST_ASSERT(on_focus_called == 2, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 2");
        TEST_ASSERT(on_lost_focus_called == 1,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 1");

        w.hide();

        TEST_ASSERT(!w.is_visible(), "Window should be visible.");
        TEST_ASSERT(!w.has_input_focus(), "Window should has focus.");

        TEST_ASSERT(on_focus_called == 2, "Invalid on_focus_called " + std::to_string(on_focus_called) + " = 2");
        TEST_ASSERT(on_lost_focus_called == 2,
                    "Invalid on_lost_focus_called " + std::to_string(on_lost_focus_called) + " = 2");
    }

    void focus_two_windows()
    {
        int alpha_focused    = 0;
        int alpha_lost_focus = 0;

        int betta_focused    = 0;
        int betta_lost_focus = 0;

        Window alpha(name() + ":alpha", {640, 480});
        Window betta(name() + ":betta", {640, 480});

        alpha.set_on_focus_callback([&alpha_focused]() { alpha_focused++; });
        alpha.set_on_lost_focus_callback([&alpha_lost_focus]() { alpha_lost_focus++; });

        betta.set_on_focus_callback([&betta_focused]() { betta_focused++; });
        betta.set_on_lost_focus_callback([&betta_lost_focus]() { betta_lost_focus++; });

        TEST_ASSERT(!alpha.is_visible(), "Window should not be visible.");
        TEST_ASSERT(!betta.is_visible(), "Window should not be visible.");

        TEST_ASSERT(!alpha.has_input_focus(), "Window should not has focus.");
        TEST_ASSERT(!betta.has_input_focus(), "Window should not has focus.");

        // Try to focus hidden windows, should not get focus
        alpha.request_input_focus();
        betta.request_input_focus();

        TEST_ASSERT(!alpha.has_input_focus(), "Window should not has focus.");
        TEST_ASSERT(!betta.has_input_focus(), "Window should not has focus.");

        TEST_ASSERT(alpha_focused == 0, "Window should not has focus (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 0, "Window should not lost focus (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 0, "Window should not has focus (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not lost focus (" + std::to_string(betta_lost_focus) + ")");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Show the alpha window, should get focus
        alpha.show();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(!betta.is_visible(), "Window should not be visible.");

        TEST_ASSERT(alpha_focused == 1, "Window should has focus (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 0, "Window should not lost focus (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 0, "Window should not has focus (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not lost focus (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Show the betta window, alpha should lost focus, betta should get focus
        betta.show();
        alpha.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 1,
                    "Window should have had focus previously (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should lost focus (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 1, "Window should has focus (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not lost focus (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Return focus to alpha, betta should lost focus
        alpha.request_input_focus();
        betta.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 2, "Window should get focus twice (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should lost focus once (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 1,
                    "Window should have had focus previously (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 1, "Window should lost focus (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Return focus to betta, alpha should lost focus
        betta.request_input_focus();
        alpha.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 2, "Window should get focus twice (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 2, "Window should lost focus twice (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 2, "Window should get focus twice (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 1, "Window should lost focus (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Hide alpha, no on_lost_focus message for alpha
        alpha.hide();
        betta.process_events();

        TEST_ASSERT(!alpha.is_visible(), "Window should not be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 2, "Window should get focus twice (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 2, "Window should lost focus twice (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 2, "Window should get focus twice (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 1, "Window should lost focus (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Show alpha
        alpha.show();
        betta.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 3, "Window should get focus 3 times (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 2, "Window should lost focus twice (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 2, "Window should get focus twice (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 2, "Window should lost focus twice (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Return focus to betta again, alpha should lost focus
        betta.request_input_focus();
        alpha.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 3, "Window should get focus 3 times (" + std::to_string(alpha_focused) + ")");
        TEST_ASSERT(alpha_lost_focus == 3,
                    "Window should lost focus 3 times (" + std::to_string(alpha_lost_focus) + ")");
        TEST_ASSERT(betta_focused == 3, "Window should get focus 3 times (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 2, "Window should lost focus twice (" + std::to_string(betta_lost_focus) + ")");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Hide betta
        betta.hide();

        TEST_ASSERT(!betta.is_visible(), "Window should be visible.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        TEST_ASSERT(betta_focused == 3, "Window should get focus 3 times (" + std::to_string(betta_focused) + ")");
        TEST_ASSERT(betta_lost_focus == 3,
                    "Window should lost focus 3 times (" + std::to_string(betta_lost_focus) + ")");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Hide alpha
        alpha.hide();

        TEST_ASSERT(!alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
    }
};

int main()
{
    return run_tests(WindowFocusTest());
}
