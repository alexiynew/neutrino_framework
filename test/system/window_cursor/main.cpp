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

class WindowCursorTest : public framework::unit_test::Suite
{
public:
    WindowCursorTest()
        : Suite("WindowCursorTest")
    {
        add_test([this]() { grab_cursor(); }, "grub_cursor");
        add_test([this]() { cursor_visibility(); }, "cursor_visibility");
    }

private:
    void grab_cursor()
    {
        Window window(name(), {640, 480});

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

        Window tmp("Tmp", {640, 480});
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

    void cursor_visibility()
    {
        Window window(name(), {640, 480});

        window.show();

        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.set_cursor_visibility(false);

        window.process_events();

        TEST_ASSERT(!window.is_cursor_visible(), "Cursor should not be visible.");

        window.set_cursor_visibility(true);

        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
    }
};

int main()
{
    return run_tests(WindowCursorTest());
}
