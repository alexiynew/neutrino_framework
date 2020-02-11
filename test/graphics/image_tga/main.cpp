
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

#include <graphics/image.hpp>
#include <unit_test/suite.hpp>

class tga_image_test : public framework::unit_test::suite
{
public:
    tga_image_test() : suite("tga_image_test")
    {
        add_test([this]() { tga_load(); }, "tga_load");
    }

private:
    void tga_load()
    {
        framework::graphics::image img;

        TEST_ASSERT(img.load("tga/cbw8.tga"), "Failed to load cbw8.tga");
        TEST_ASSERT(img.load("tga/ccm8.tga"), "Failed to load ccm8.tga");
        TEST_ASSERT(img.load("tga/ctc16.tga"), "Failed to load ctc16.tga");
        TEST_ASSERT(img.load("tga/ctc24.tga"), "Failed to load ctc24.tga");
        TEST_ASSERT(img.load("tga/ctc32.tga"), "Failed to load ctc32.tga");
        TEST_ASSERT(img.load("tga/flag_b16.tga"), "Failed to load flag_b16.tga");
        TEST_ASSERT(img.load("tga/flag_b24.tga"), "Failed to load flag_b24.tga");
        TEST_ASSERT(img.load("tga/flag_b32.tga"), "Failed to load flag_b32.tga");
        TEST_ASSERT(img.load("tga/flag_t16.tga"), "Failed to load flag_t16.tga");
        TEST_ASSERT(img.load("tga/flag_t32.tga"), "Failed to load flag_t32.tga");
        TEST_ASSERT(img.load("tga/marbles.tga"), "Failed to load marbles.tga");
        TEST_ASSERT(img.load("tga/ubw8.tga"), "Failed to load ubw8.tga");
        TEST_ASSERT(img.load("tga/ucm8.tga"), "Failed to load ucm8.tga");
        TEST_ASSERT(img.load("tga/utc16.tga"), "Failed to load utc16.tga");
        TEST_ASSERT(img.load("tga/utc24.tga"), "Failed to load utc24.tga");
        TEST_ASSERT(img.load("tga/utc32.tga"), "Failed to load utc32.tga");
        TEST_ASSERT(img.load("tga/xing_b16.tga"), "Failed to load xing_b16.tga");
        TEST_ASSERT(img.load("tga/xing_b24.tga"), "Failed to load xing_b24.tga");
        TEST_ASSERT(img.load("tga/xing_b32.tga"), "Failed to load xing_b32.tga");
        TEST_ASSERT(img.load("tga/xing_t16.tga"), "Failed to load xing_t16.tga");
        TEST_ASSERT(img.load("tga/xing_t24.tga"), "Failed to load xing_t24.tga");
        TEST_ASSERT(img.load("tga/xing_t32.tga"), "Failed to load xing_t32.tga");
    }
};

int main()
{
    return run_tests(tga_image_test());
}
