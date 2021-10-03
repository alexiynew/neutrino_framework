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

#include <game_core/fps_counter.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::game_core;

class FpsCounterTest : public unit_test::Suite
{
public:
    FpsCounterTest()
        : Suite("FpsCounterTest")
    {
        add_test([this]() { fps_count(); }, "fps_count");
    }

private:
    void fps_count()
    {
        FpsCounter fps;

        for (int i = 0; i < 100; ++i) {
            fps.tick();
        }

        while (fps.fps() == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }

        TEST_ASSERT(fps.fps() == 100, "Should be 100 frames");

        while (fps.fps() != 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }

        TEST_ASSERT(fps.fps() == 0, "Should be 0 frames");
        TEST_ASSERT(fps.total_fames() == 100, "Should be 100 frames");
    }
};

int main()
{
    return run_tests(FpsCounterTest());
}
