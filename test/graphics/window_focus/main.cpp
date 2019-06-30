
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <graphics/window.hpp>
#include <unit_test/suite.hpp>

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
        using ::framework::system::window;

        int alpha_focused    = 0;
        int alpha_lost_focus = 0;

        int betta_focused    = 0;
        int betta_lost_focus = 0;

        window alpha({640, 480}, "alpha");
        window betta({640, 480}, "betta");

        alpha.set_on_focus_callback([&alpha_focused](const window& /*unused*/) { alpha_focused++; });
        betta.set_on_focus_callback([&betta_focused](const window& /*unused*/) { betta_focused++; });

        alpha.set_on_focus_lost_callback([&alpha_lost_focus](const window& /*unused*/) { alpha_lost_focus++; });
        betta.set_on_focus_lost_callback([&betta_lost_focus](const window& /*unused*/) { betta_lost_focus++; });

        alpha.show();

        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha_focused == 1, "Window should has focus.");

        betta.show();

        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha_focused == 1, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should not has focus.");
        TEST_ASSERT(betta_focused == 1, "Window should has focus.");
        TEST_ASSERT(betta_lost_focus == 0, "Window should not has focus.");

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");

        alpha.focus();

        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha_focused == 2, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should not has focus.");
        TEST_ASSERT(betta_focused == 1, "Window should has focus.");
        TEST_ASSERT(betta_lost_focus == 1, "Window should not has focus.");

        TEST_ASSERT(alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(!betta.focused(), "Focus function is not working.");

        betta.focus();

        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha_focused == 2, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 2, "Window should not has focus.");
        TEST_ASSERT(betta_focused == 2, "Window should has focus.");
        TEST_ASSERT(betta_lost_focus == 1, "Window should not has focus.");

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");
    }
};

int main()
{
    return run_tests(window_focus_test());
}
