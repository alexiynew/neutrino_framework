
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

#include <common/types.hpp>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

class window_open_test : public framework::unit_test::suite
{
public:
    window_open_test() : suite("window_open_test")
    {
        add_test([this]() { open_window(); }, "open_window");
        add_test([this]() { open_several_windows(); }, "open_several_windows");
    }

private:
    void open_window()
    {
        ::framework::int32 show_called = 0;
        ::framework::int32 hide_called = 0;

        ::framework::system::window window({640, 480}, "Test");

        window.set_on_show_callback([&show_called](const ::framework::system::window& /*unused*/) { show_called++; });
        window.show();

        TEST_ASSERT(window.visible(), "Window is not visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 0, "Wrong callbacks call.");

        window.set_on_hide_callback([&hide_called](const ::framework::system::window& /*unused*/) { hide_called++; });
        window.hide();

        TEST_ASSERT(!window.visible(), "Window is still visible.");
        TEST_ASSERT(show_called == 1 && hide_called == 1, "Wrong callbacks call.");
    }

    void open_several_windows()
    {
        using ::framework::system::window;

        window windows[5] = {
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        window({640, 480}, "Test"),
        };

        for (auto& w : windows) {
            w.show();
        }

        TEST_ASSERT(windows[0].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[1].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[2].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[3].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[4].visible(), "Window is not visidle.");

        for (auto& w : windows) {
            w.hide();
        }

        TEST_ASSERT(!windows[0].visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[1].visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[2].visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[3].visible(), "Window is still visidle.");
        TEST_ASSERT(!windows[4].visible(), "Window is still visidle.");

        for (auto& w : windows) {
            w.show();
        }

        TEST_ASSERT(windows[0].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[1].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[2].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[3].visible(), "Window is not visidle.");
        TEST_ASSERT(windows[4].visible(), "Window is not visidle.");
    }
};

int main()
{
    return run_tests(window_open_test());
}
