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
        add_test([this]() { grab_cursor_before_show(); }, "grab_cursor_before_show");
        add_test([this]() { release_cursor_after_hide(); }, "release_cursor_after_hide");
        add_test([this]() { cursor_visibility(); }, "cursor_visibility");

        // TODO: Check that upper left corner of the window is (0,0) and lower right corner is (width - 1, height - 1).
        // TODO: When grubbed: 0,0 - is window center x is from left to right, y is from top to bottom.
        // TODO: Window should release cursor for system when focus lost or the window is hidden.
        // TODO: Window should return grubbed cursor in same position when cursor released
    }

private:
    void grab_cursor()
    {
        Window window(name(), {640, 480});
        CursorPosition last_mouse_pos{-1, -1};
        bool mouse_inside = false;

        window.set_on_mouse_move_callback([&last_mouse_pos](CursorPosition pos) { last_mouse_pos = pos; });

        window.set_on_mouse_enter_callback([&mouse_inside]() { mouse_inside = true; });
        window.set_on_mouse_leave_callback([&mouse_inside]() { mouse_inside = false; });

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.grab_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
        TEST_ASSERT(mouse_inside == true, "Grubbed cursor must be inside the window");
        TEST_ASSERT(last_mouse_pos == CursorPosition(0, 0), "On grubbed, cursor must be in 0,0 position");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.hide();

        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        Window tmp("Tmp", {640, 480});
        tmp.show();

        TEST_ASSERT(tmp.has_input_focus(), "Tmp window should not be focused.");
        TEST_ASSERT(!tmp.is_cursor_grabbed(), "Tmp window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        TEST_ASSERT(!window.has_input_focus(), "Window should not be focused.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        TEST_ASSERT(tmp.has_input_focus(), "Window should not be focused.");
        TEST_ASSERT(!tmp.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(tmp.is_cursor_visible(), "Cursor should be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.focus();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.release_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void grab_cursor_before_show()
    {
        Window window(name(), {640, 480});

        window.grab_cursor();

        TEST_ASSERT(window.is_cursor_grabbed(), "Window should grab cursor.");

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.hide();

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
    }

    void release_cursor_after_hide()
    {
        Window window(name(), {640, 480});

        window.grab_cursor();
        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.hide();

        window.release_cursor();

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.grab_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_grabbed(), "Window should not grab cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
    }

    void cursor_visibility()
    {
        Window window(name(), {640, 480});

        window.show();

        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.set_cursor_visible(false);

        // TODO: Automate this check
        // TEST_FAIL("Cursor is still visible.");
        // while (!window.should_close()) {
        //     window.process_events();
        // }

        window.hide();

        // TODO: Automate this check
        // TEST_FAIL("Cursor is hidden in window, BUT must be visible for system.");
        // while (!window.should_close()) {
        //     window.process_events();
        // }

        window.show();

        // TODO: Automate this check
        // TEST_FAIL("Cursor is hidden in window, AND must be visible for system.");
        // while (!window.should_close()) {
        //     window.process_events();
        // }

        TEST_ASSERT(!window.is_cursor_visible(), "Cursor should not be visible.");

        window.set_cursor_visible(true);

        // TEST_FAIL("Cursor is visible in window, AND must be visible for system.");
        // while (!window.should_close()) {
        //     window.process_events();
        // }

        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
    }
};

int main()
{
    return run_tests(WindowCursorTest());
}
