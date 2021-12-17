// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

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
        add_test([this]() { focus_window(); }, "focus_window");
    }

private:
    void focus_window()
    {
        int alpha_focused    = 0;
        int alpha_lost_focus = 0;

        int betta_focused    = 0;
        int betta_lost_focus = 0;

        Window alpha(name() + ":alpha", {640, 480});
        Window betta(name() + ":betta", {640, 480});

        alpha.on_focus.connect([&alpha_focused](const Window& /*unused*/) { alpha_focused++; });
        alpha.on_lost_focus.connect([&alpha_lost_focus](const Window& /*unused*/) { alpha_lost_focus++; });

        betta.on_focus.connect([&betta_focused](const Window& /*unused*/) { betta_focused++; });
        betta.on_lost_focus.connect([&betta_lost_focus](const Window& /*unused*/) { betta_lost_focus++; });

        TEST_ASSERT(!alpha.is_visible(), "Window should not be visible.");
        TEST_ASSERT(!betta.is_visible(), "Window should not be visible.");

        TEST_ASSERT(!alpha.has_input_focus(), "Window should not has focus.");
        TEST_ASSERT(!betta.has_input_focus(), "Window should not has focus.");

        // Try to focus hidden windows, should not get focus
        alpha.focus();
        betta.focus();

        TEST_ASSERT(!alpha.has_input_focus(), "Window should not has focus.");
        TEST_ASSERT(!betta.has_input_focus(), "Window should not has focus.");

        TEST_ASSERT(alpha_focused == 0, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 0, "Window should not lost focus.");
        TEST_ASSERT(betta_focused == 0, "Window should not has focus.");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not lost focus.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Show the alpha window, should get focus
        alpha.show();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(!betta.is_visible(), "Window should not be visible.");

        TEST_ASSERT(alpha_focused == 1, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 0, "Window should not lost focus.");
        TEST_ASSERT(betta_focused == 0, "Window should not has focus.");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not lost focus.");

        TEST_ASSERT(alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Show the betta window, alpha should lost focus, betta should get focus
        betta.show();
        alpha.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 1, "Window should have had focus previously.");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should lost focus.");
        TEST_ASSERT(betta_focused == 1, "Window should has focus.");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not lost focus.");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Return focus to alpha, betta should lost focus
        alpha.focus();
        betta.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 2, "Window should get focus twice.");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should lost focus once.");
        TEST_ASSERT(betta_focused == 1, "Window should have had focus previously.");
        TEST_ASSERT(betta_lost_focus == 1, "Window should lost focus.");

        TEST_ASSERT(alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Return focus to betta, alpha should lost focus
        betta.focus();
        alpha.process_events();

        TEST_ASSERT(alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(betta.is_visible(), "Window should be visible.");

        TEST_ASSERT(alpha_focused == 2, "Window should get focus twice.");
        TEST_ASSERT(alpha_lost_focus == 2, "Window should lost focus twice.");
        TEST_ASSERT(betta_focused == 2, "Window should get focus twice.");
        TEST_ASSERT(betta_lost_focus == 1, "Window should lost focus.");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Hide betta, should lost focus
        betta.hide();

        TEST_ASSERT(!betta.is_visible(), "Window should be visible.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        TEST_ASSERT(betta_focused == 2, "Window should get focus twice.");
        TEST_ASSERT(betta_lost_focus == 2, "Window should lost focus twice.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Hide alpha, should lost focus
        alpha.hide();

        TEST_ASSERT(!alpha.is_visible(), "Window should be visible.");
        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");

        TEST_ASSERT(alpha_focused == 3, "Window should get focus twice.");
        TEST_ASSERT(alpha_lost_focus == 3, "Window should lost focus twice.");
    }
};

int main()
{
    return run_tests(WindowFocusTest());
}
