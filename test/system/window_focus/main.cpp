
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

#include <iostream>

#include <log/log.hpp>
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

        Window alpha({640, 480}, "alpha");
        Window betta({640, 480}, "betta");

        alpha.on_focus.connect([&alpha_focused](const Window& /*unused*/) { alpha_focused++; });
        betta.on_focus.connect([&betta_focused](const Window& /*unused*/) { betta_focused++; });

        alpha.on_lost_focus.connect([&alpha_lost_focus](const Window& /*unused*/) { alpha_lost_focus++; });
        betta.on_lost_focus.connect([&betta_lost_focus](const Window& /*unused*/) { betta_lost_focus++; });

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

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");

        alpha.focus();

        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha_focused == 2, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 1, "Window should not has focus.");
        TEST_ASSERT(betta_focused == 1, "Window should has focus.");
        TEST_ASSERT(betta_lost_focus == 1, "Window should not has focus.");

        TEST_ASSERT(alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(!betta.has_input_focus(), "Focus function is not working.");

        betta.focus();

        alpha.process_events();
        betta.process_events();

        TEST_ASSERT(alpha_focused == 2, "Window should has focus.");
        TEST_ASSERT(alpha_lost_focus == 2, "Window should not has focus.");
        TEST_ASSERT(betta_focused == 2, "Window should has focus.");
        TEST_ASSERT(betta_lost_focus == 1, "Window should not has focus.");

        TEST_ASSERT(!alpha.has_input_focus(), "Focus function is not working.");
        TEST_ASSERT(betta.has_input_focus(), "Focus function is not working.");
    }
};

class WindowCursorTest : public framework::unit_test::Suite
{
public:
    WindowCursorTest()
        : Suite("WindowCursorTest")
    {
        add_test([this]() { grab_cursor(); }, "grub_cursor");
    }

private:
    void grab_cursor()
    {
        Window window({640, 480}, name());

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.grab_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.hide();
        window.show();

        window.process_events();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        Window tmp({640, 480}, "Tmp");
        tmp.show();

        tmp.process_events();
        window.process_events();

        TEST_ASSERT(!window.has_input_focus(), "Window should not be focused.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.focus();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.release_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
    }
};

int main()
{
    // return run_tests(WindowFocusTest());
    return run_tests(WindowCursorTest());
}
