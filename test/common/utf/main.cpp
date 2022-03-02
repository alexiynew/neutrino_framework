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
        add_test([this]() { utf32_to_utf8(); }, "utf32_to_utf8");
        add_test([this]() { utf8_to_utf16(); }, "utf8_to_utf16");
        add_test([this]() { utf32_to_utf16(); }, "utf32_to_utf16");
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

        // TODO: Add tests with broken codepoints
    }

    void utf32_to_utf8()
    {
        const std::u32string utf32_1(U"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u32string utf32_2(U"\u00a3\u00a4\u00a5");
        const std::u32string utf32_3(U"\u7cc2\u7cc3\u7cc4");
        const std::u32string utf32_4(U"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u32string utf32_5(U"\uf900\uf901\uf902\uf903");
        const std::u32string utf32_6(U"\U00010000\U00010001\U00010002\U00010003");

        const std::string utf8_1(u8"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::string utf8_2(u8"\u00a3\u00a4\u00a5");
        const std::string utf8_3(u8"\u7cc2\u7cc3\u7cc4");
        const std::string utf8_4(u8"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::string utf8_5(u8"\uf900\uf901\uf902\uf903");
        const std::string utf8_6(u8"\U00010000\U00010001\U00010002\U00010003");

        TEST_ASSERT(utf::to_utf8(utf32_1) == utf8_1, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf32_2) == utf8_2, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf32_3) == utf8_3, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf32_4) == utf8_4, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf32_5) == utf8_5, "Convertation failed.");
        TEST_ASSERT(utf::to_utf8(utf32_6) == utf8_6, "Convertation failed.");

        // TODO: Add tests with broken codepoints
    }

    void utf8_to_utf16()
    {
        const std::string utf8_1(u8"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::string utf8_2(u8"\u00a3\u00a4\u00a5");
        const std::string utf8_3(u8"\u7cc2\u7cc3\u7cc4");
        const std::string utf8_4(u8"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::string utf8_5(u8"\uf900\uf901\uf902\uf903");
        const std::string utf8_6(u8"\U00010000\U00010001\U00010002\U00010003");

        const std::u16string utf16_1(u"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u16string utf16_2(u"\u00a3\u00a4\u00a5");
        const std::u16string utf16_3(u"\u7cc2\u7cc3\u7cc4");
        const std::u16string utf16_4(u"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u16string utf16_5(u"\uf900\uf901\uf902\uf903");
        const std::u16string utf16_6(u"\U00010000\U00010001\U00010002\U00010003");

        TEST_ASSERT(utf::to_utf16(utf8_1) == utf16_1, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf8_2) == utf16_2, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf8_3) == utf16_3, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf8_4) == utf16_4, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf8_5) == utf16_5, "Convertation failed.");

        auto s = utf::to_utf16(utf8_6);
        TEST_ASSERT(utf::to_utf16(utf8_6) == utf16_6, "Convertation failed.");

        // TODO: Add tests with broken codepoints
    }

    void utf32_to_utf16()
    {
        const std::u32string utf32_1(U"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u32string utf32_2(U"\u00a3\u00a4\u00a5");
        const std::u32string utf32_3(U"\u7cc2\u7cc3\u7cc4");
        const std::u32string utf32_4(U"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u32string utf32_5(U"\uf900\uf901\uf902\uf903");
        const std::u32string utf32_6(U"\U00010000\U00010001\U00010002\U00010003");

        const std::u16string utf16_1(u"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u16string utf16_2(u"\u00a3\u00a4\u00a5");
        const std::u16string utf16_3(u"\u7cc2\u7cc3\u7cc4");
        const std::u16string utf16_4(u"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u16string utf16_5(u"\uf900\uf901\uf902\uf903");
        const std::u16string utf16_6(u"\U00010000\U00010001\U00010002\U00010003");

        TEST_ASSERT(utf::to_utf16(utf32_1) == utf16_1, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf32_2) == utf16_2, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf32_3) == utf16_3, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf32_4) == utf16_4, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf32_5) == utf16_5, "Convertation failed.");
        TEST_ASSERT(utf::to_utf16(utf32_6) == utf16_6, "Convertation failed.");

        // TODO: Add tests with broken codepoints
    }
};

int main()
{
    return run_tests(UtfTest());
}
