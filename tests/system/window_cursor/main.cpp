#include <chrono>
#include <iostream>
#include <thread>

#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace neutrino::system;

class WindowCursorTest : public neutrino::unit_test::Suite
{
public:
    WindowCursorTest()
        : Suite("WindowCursorTest")
    {
        add_test([this]() { capture_cursor(); }, "capture_cursor");
        add_test([this]() { capture_cursor_before_show(); }, "capture_cursor_before_show");
        add_test([this]() { release_cursor_after_hide(); }, "release_cursor_after_hide");
        add_test([this]() { cursor_visibility(); }, "cursor_visibility");

        // TODO: Check that upper left corner of the window is (0,0) and lower right corner is (width - 1, height - 1).
        // TODO: When captured: 0,0 - is window center x is from left to right, y is from top to bottom.
        // TODO: Window should release cursor for system when focus lost or the window is hidden.
        // TODO: Window should return captured cursor in same position when cursor released
    }

private:
    void capture_cursor()
    {
        Window window(name(), {640, 480});
        CursorPosition last_mouse_pos{-1, -1};
        bool mouse_inside = false;

        window.set_on_mouse_move_callback([&last_mouse_pos](CursorPosition pos) { last_mouse_pos = pos; });

        window.set_on_mouse_enter_callback([&mouse_inside]() { mouse_inside = true; });
        window.set_on_mouse_leave_callback([&mouse_inside]() { mouse_inside = false; });

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.capture_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
        TEST_ASSERT(mouse_inside == true && window.is_cursor_hover(), "Grubbed cursor must be inside the window");
        TEST_ASSERT(last_mouse_pos == CursorPosition(0, 0), "On captured, cursor must be in 0,0 position");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.hide();

        TEST_ASSERT(window.is_cursor_captured(), "Window should capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        Window tmp("Tmp", {640, 480});
        tmp.show();

        TEST_ASSERT(tmp.has_input_focus(), "Tmp window should not be focused.");
        TEST_ASSERT(!tmp.is_cursor_captured(), "Tmp window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        TEST_ASSERT(!window.has_input_focus(), "Window should not be focused.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        TEST_ASSERT(tmp.has_input_focus(), "Window should not be focused.");
        TEST_ASSERT(!tmp.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(tmp.is_cursor_visible(), "Cursor should be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.request_input_focus();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.release_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void capture_cursor_before_show()
    {
        Window window(name(), {640, 480});

        window.capture_cursor();

        TEST_ASSERT(window.is_cursor_captured(), "Window should capture cursor.");

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.hide();

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");
    }

    void release_cursor_after_hide()
    {
        Window window(name(), {640, 480});

        window.capture_cursor();
        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.hide();

        window.release_cursor();

        window.show();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(!window.is_cursor_captured(), "Window should not capture cursor.");
        TEST_ASSERT(window.is_cursor_visible(), "Cursor should be visible.");

        window.capture_cursor();

        TEST_ASSERT(window.has_input_focus(), "Window should has focus.");
        TEST_ASSERT(window.is_cursor_captured(), "Window should not capture cursor.");
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
