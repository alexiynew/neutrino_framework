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
#include <thread>

#include <common/types.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework::system;

class WindowOpenTest : public framework::unit_test::Suite
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
    Window create_window_internal()
    {
        Window window(name(), {640, 480});
        window.on_show.connect([](const Window& /*unused*/) {});
        window.on_hide.connect([](const Window& /*unused*/) {});

        return window;
    }

    void create_window()
    {
        Window window = create_window_internal();

        window.show();
        window.hide();
    }

    void open_window()
    {
        int show_called = 0;
        int hide_called = 0;

        Window window(name(), {640, 480});

        window.on_show.connect([&show_called](const Window& /*unused*/) { show_called++; });
        window.on_hide.connect([&hide_called](const Window& /*unused*/) { hide_called++; });

        TEST_ASSERT(!window.is_visible(), "Window is visible before been shown.");

        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window is still visible.");
        TEST_ASSERT(hide_called == 0, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 0, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 0, "Wrong callbacks call.");

        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window is still visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 1, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 2 && hide_called == 1, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.hide();
        TEST_ASSERT(!window.is_visible(), "Window is still visible.");
        TEST_ASSERT(show_called == 2 && hide_called == 2, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        window.show();
        TEST_ASSERT(window.is_visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 3 && hide_called == 2, "Wrong callbacks call.");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void open_several_windows()
    {
        Window windows[5] = {
        Window(name(), {640, 480}),
        Window(name(), {640, 480}),
        Window(name(), {640, 480}),
        Window(name(), {640, 480}),
        Window(name(), {640, 480}),
        };

        TEST_ASSERT(!windows[0].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[1].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[2].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[3].is_visible(), "Window is visible before been shown.");
        TEST_ASSERT(!windows[4].is_visible(), "Window is visible before been shown.");

        for (auto& w : windows) {
            w.show();
        }

        TEST_ASSERT(windows[0].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[1].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[2].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[3].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[4].is_visible(), "Window is not visidle.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (auto& w : windows) {
            w.hide();
        }

        TEST_ASSERT(!windows[0].is_visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[1].is_visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[2].is_visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[3].is_visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[4].is_visible(), "Window is still visidle.");

        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (auto& w : windows) {
            w.show();
        }

        TEST_ASSERT(windows[0].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[1].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[2].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[3].is_visible(), "Window is not visidle.");
        TEST_ASSERT(windows[4].is_visible(), "Window is not visidle.");
    }
};

int main()
{
    return run_tests(WindowOpenTest());
}
