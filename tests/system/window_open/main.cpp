#include <chrono>
#include <thread>

#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace neutrino::system;

class WindowOpenTest : public neutrino::unit_test::Suite
{
public:
    WindowOpenTest()
        : Suite("WindowOpenTest")
    {
        add_test([this]() { create_window(); }, "create_window");
        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
    }

private:
    Window create_window_internal(bool* show_called_flag, bool* hide_called_flag)
    {
        Window window(name(), {640, 480});
        window.set_on_show_callback([flag = show_called_flag]() { *flag = true; });
        window.set_on_hide_callback([flag = hide_called_flag]() { *flag = true; });

        return window;
    }

    void create_window()
    {
        bool show_called = false;
        bool hide_called = false;

        Window window = create_window_internal(&show_called, &hide_called);

        window.show();

        Window window2 = std::move(window);

        TEST_ASSERT(window2.is_visible(), "Window should keep its state.");

        window = std::move(window2);

        TEST_ASSERT(window.is_visible(), "Window should keep its state.");

        window.hide();

        // TODO: On MacOS a hidden window can appear on screen by Command+Tab,
        // but it's counts as invisible and we can't properly hadle it in OsxWindow::window_did_becomekey

        TEST_ASSERT(show_called, "The on_show callback must be called.");
        TEST_ASSERT(hide_called, "The on_hide callback must be called.");
    }

    void open_window()
    {
        int show_called = 0;
        int hide_called = 0;

        Window window(name(), {640, 480});

        window.set_on_show_callback([&window, &show_called, this]() {
            TEST_ASSERT(window.is_visible(), "The on_show callback called for non visible window.");
            show_called++;
        });

        window.set_on_hide_callback([&window, &hide_called, this]() {
            TEST_ASSERT(!window.is_visible(), "The on_hide callback called for visible window.");
            hide_called++;
        });

        TEST_ASSERT(!window.is_visible(), "Window is visible before been shown.");

        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window is still visible.");
        TEST_ASSERT(hide_called == 0, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 0,
                    "Wrong callbacks call s:(" + std::to_string(show_called) + ") h:(" + std::to_string(hide_called) +
                    ").");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 0,
                    "Wrong callbacks call s:(" + std::to_string(show_called) + ") h:(" + std::to_string(hide_called) +
                    ").");

        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window is still visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 1,
                    "Wrong callbacks call s:(" + std::to_string(show_called) + ") h:(" + std::to_string(hide_called) +
                    ").");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 2 && hide_called == 1,
                    "Wrong callbacks call s:(" + std::to_string(show_called) + ") h:(" + std::to_string(hide_called) +
                    ").");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window is still visible.");
        TEST_ASSERT(show_called == 2 && hide_called == 2,
                    "Wrong callbacks call s:(" + std::to_string(show_called) + ") h:(" + std::to_string(hide_called) +
                    ").");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 3 && hide_called == 2,
                    "Wrong callbacks call s:(" + std::to_string(show_called) + ") h:(" + std::to_string(hide_called) +
                    ").");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void open_several_windows()
    {
        Window windows[5] = {
        Window(name() + " 0", {640, 480}),
        Window(name() + " 1", {640, 480}),
        Window(name() + " 2", {640, 480}),
        Window(name() + " 3", {640, 480}),
        Window(name() + " 4", {640, 480}),
        };

        TEST_ASSERT(!windows[0].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[1].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[2].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[3].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[4].is_visible(), "Window is visible before been shown.");

        for (auto& w : windows) {
            w.show();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        TEST_ASSERT(windows[0].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[1].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[2].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[3].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[4].is_visible(), "Window is not visible.");

        for (auto& w : windows) {
            w.hide();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        TEST_ASSERT(!windows[0].is_visible(), "Window is still visible.");
        TEST_ASSERT(!windows[1].is_visible(), "Window is still visible.");
        TEST_ASSERT(!windows[2].is_visible(), "Window is still visible.");
        TEST_ASSERT(!windows[3].is_visible(), "Window is still visible.");
        TEST_ASSERT(!windows[4].is_visible(), "Window is still visible.");

        for (auto& w : windows) {
            w.show();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        TEST_ASSERT(windows[0].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[1].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[2].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[3].is_visible(), "Window is not visible.");
        TEST_ASSERT(windows[4].is_visible(), "Window is not visible.");
    }
};

int main()
{
    return run_tests(WindowOpenTest());
}
