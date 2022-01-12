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
