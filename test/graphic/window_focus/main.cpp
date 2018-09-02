
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#include <graphic/window.hpp>
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
        framework::graphic::window alpha({640, 480}, "Test");
        framework::graphic::window betta({640, 480}, "Test");

        alpha.show();
        betta.show();

        TEST_ASSERT(!alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(betta.focused(), "Focus function is not working.");

        alpha.focus();

        TEST_ASSERT(alpha.focused(), "Focus function is not working.");
        TEST_ASSERT(!betta.focused(), "Focus function is not working.");
    }
};

int main()
{
    return run_tests(window_focus_test());
}
