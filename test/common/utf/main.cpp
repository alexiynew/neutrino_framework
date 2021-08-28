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

#include <iostream>
#include <string>

#include <common/utf.hpp>
#include <log/log.hpp>
#include <unit_test/suite.hpp>

using namespace framework;

class UtfTest : public unit_test::Suite
{
public:
    UtfTest()
        : Suite("UtfTest")
    {
        add_test([this]() { utf16_to_utf8(); }, "utf16_to_utf8");
    }

private:
    void utf16_to_utf8()
    {
        const std::u16string utf16_1(u"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u16string utf16_2(u"\u00a3\u00a4\u00a5");
        const std::u16string utf16_3(u"\u7cc2\u7cc3\u7cc4");
        const std::u16string utf16_4(u"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u16string utf16_5(u"\uf900\uf901\uf902\uf903");
        const std::u16string utf16_6(u"\U00010000\U00010001\U00010002\U00010003");

        const std::string utf8_1(u8"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::string utf8_2(u8"\u00a3\u00a4\u00a5");
        const std::string utf8_3(u8"\u7cc2\u7cc3\u7cc4");
        const std::string utf8_4(u8"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::string utf8_5(u8"\uf900\uf901\uf902\uf903");
        const std::string utf8_6(u8"\U00010000\U00010001\U00010002\U00010003");

        TEST_ASSERT(utf::to_utf8(utf16_1) == utf8_1, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf16_2) == utf8_2, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf16_3) == utf8_3, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf16_4) == utf8_4, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf16_5) == utf8_5, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf16_6) == utf8_6, "Convertation failed.");
    }
};

int main()
{
    return run_tests(UtfTest());
}
