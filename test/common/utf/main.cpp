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
        add_test([this]() { utf8_to_utf32(); }, "utf8_to_utf32");
        add_test([this]() { utf16_to_utf32(); }, "utf16_to_utf32");
        add_test([this]() { utf8_to_codepoints(); }, "utf8_to_codepoints");
        add_test([this]() { utf16_to_codepoints(); }, "utf16_to_codepoints");
        add_test([this]() { utf32_to_codepoints(); }, "utf32_to_codepoints");
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

    void utf8_to_utf32()
    {
        const std::string utf8_1(u8"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::string utf8_2(u8"\u00a3\u00a4\u00a5");
        const std::string utf8_3(u8"\u7cc2\u7cc3\u7cc4");
        const std::string utf8_4(u8"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::string utf8_5(u8"\uf900\uf901\uf902\uf903");
        const std::string utf8_6(u8"\U00010000\U00010001\U00010002\U00010003");

        const std::u32string utf32_1(U"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u32string utf32_2(U"\u00a3\u00a4\u00a5");
        const std::u32string utf32_3(U"\u7cc2\u7cc3\u7cc4");
        const std::u32string utf32_4(U"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u32string utf32_5(U"\uf900\uf901\uf902\uf903");
        const std::u32string utf32_6(U"\U00010000\U00010001\U00010002\U00010003");

        auto s1 = utf::to_utf32(utf8_1);
        auto s2 = utf::to_utf32(utf8_2);
        auto s3 = utf::to_utf32(utf8_3);
        auto s4 = utf::to_utf32(utf8_4);
        auto s5 = utf::to_utf32(utf8_5);
        auto s6 = utf::to_utf32(utf8_6);

        TEST_ASSERT(utf::to_utf32(utf8_1) == utf32_1, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf8_2) == utf32_2, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf8_3) == utf32_3, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf8_4) == utf32_4, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf8_5) == utf32_5, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf8_6) == utf32_6, "Convertation failed.");

        // TODO: Add tests with broken codepoints
    }

    void utf16_to_utf32()
    {
        const std::u16string utf16_1(u"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u16string utf16_2(u"\u00a3\u00a4\u00a5");
        const std::u16string utf16_3(u"\u7cc2\u7cc3\u7cc4");
        const std::u16string utf16_4(u"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u16string utf16_5(u"\uf900\uf901\uf902\uf903");
        const std::u16string utf16_6(u"\U00010000\U00010001\U00010002\U00010003");

        const std::u32string utf32_1(U"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u32string utf32_2(U"\u00a3\u00a4\u00a5");
        const std::u32string utf32_3(U"\u7cc2\u7cc3\u7cc4");
        const std::u32string utf32_4(U"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u32string utf32_5(U"\uf900\uf901\uf902\uf903");
        const std::u32string utf32_6(U"\U00010000\U00010001\U00010002\U00010003");

        TEST_ASSERT(utf::to_utf32(utf16_1) == utf32_1, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf16_2) == utf32_2, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf16_3) == utf32_3, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf16_4) == utf32_4, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf16_5) == utf32_5, "Convertation failed.");
        TEST_ASSERT(utf::to_utf32(utf16_6) == utf32_6, "Convertation failed.");

        // TODO: Add tests with broken codepoints
    }

    void utf8_to_codepoints()
    {
        const std::string utf8_1(u8"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::string utf8_2(u8"\u00a3\u00a4\u00a5");
        const std::string utf8_3(u8"\u7cc2\u7cc3\u7cc4");
        const std::string utf8_4(u8"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::string utf8_5(u8"\uf900\uf901\uf902\uf903");
        const std::string utf8_6(u8"\U00010000\U00010001\U00010002\U00010003");

        std::vector<utf::CodePoint> cp_1 = {0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
                                            0x6c, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x79, 0x76, 0x77, 0x78,
                                            0x79, 0x7a, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                                            0x30, 0x2d, 0x3d, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a,
                                            0x28, 0x29, 0x5f, 0x2b, 0x7b, 0x7d, 0x7c, 0x5b, 0x5d, 0x5c, 0x3b,
                                            0x27, 0x3a, 0x22, 0x2c, 0x2e, 0x2f, 0x3c, 0x3e, 0x3f, 0x60, 0x7e};
        std::vector<utf::CodePoint> cp_2 = {0xA3, 0xa4, 0xa5};
        std::vector<utf::CodePoint> cp_3 = {0x7cc2, 0x7cc3, 0x7cc4};
        std::vector<utf::CodePoint> cp_4 = {0xd7f8, 0xd7f9, 0xd7fa, 0xd7fb};
        std::vector<utf::CodePoint> cp_5 = {0xf900, 0xf901, 0xf902, 0xf903};
        std::vector<utf::CodePoint> cp_6 = {0x00010000, 0x00010001, 0x00010002, 0x00010003};

        TEST_ASSERT(utf::to_codepoints(utf8_1) == cp_1, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf8_2) == cp_2, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf8_3) == cp_3, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf8_4) == cp_4, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf8_5) == cp_5, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf8_6) == cp_6, "Convertion to codepoints failed.");
    }

    void utf16_to_codepoints()
    {
        const std::u16string utf16_1(u"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u16string utf16_2(u"\u00a3\u00a4\u00a5");
        const std::u16string utf16_3(u"\u7cc2\u7cc3\u7cc4");
        const std::u16string utf16_4(u"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u16string utf16_5(u"\uf900\uf901\uf902\uf903");
        const std::u16string utf16_6(u"\U00010000\U00010001\U00010002\U00010003");

        std::vector<utf::CodePoint> cp_1 = {0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
                                            0x6c, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x79, 0x76, 0x77, 0x78,
                                            0x79, 0x7a, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                                            0x30, 0x2d, 0x3d, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a,
                                            0x28, 0x29, 0x5f, 0x2b, 0x7b, 0x7d, 0x7c, 0x5b, 0x5d, 0x5c, 0x3b,
                                            0x27, 0x3a, 0x22, 0x2c, 0x2e, 0x2f, 0x3c, 0x3e, 0x3f, 0x60, 0x7e};
        std::vector<utf::CodePoint> cp_2 = {0xA3, 0xa4, 0xa5};
        std::vector<utf::CodePoint> cp_3 = {0x7cc2, 0x7cc3, 0x7cc4};
        std::vector<utf::CodePoint> cp_4 = {0xd7f8, 0xd7f9, 0xd7fa, 0xd7fb};
        std::vector<utf::CodePoint> cp_5 = {0xf900, 0xf901, 0xf902, 0xf903};
        std::vector<utf::CodePoint> cp_6 = {0x00010000, 0x00010001, 0x00010002, 0x00010003};

        TEST_ASSERT(utf::to_codepoints(utf16_1) == cp_1, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf16_2) == cp_2, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf16_3) == cp_3, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf16_4) == cp_4, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf16_5) == cp_5, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf16_6) == cp_6, "Convertion to codepoints failed.");
    }

    void utf32_to_codepoints()
    {
        const std::u32string utf32_1(U"abcdefghijklopqrstyvwxyz1234567890-=!@#$%^&*()_+{}|[]\\;':\",./<>?`~");
        const std::u32string utf32_2(U"\u00a3\u00a4\u00a5");
        const std::u32string utf32_3(U"\u7cc2\u7cc3\u7cc4");
        const std::u32string utf32_4(U"\ud7f8\ud7f9\ud7fa\ud7fb");
        const std::u32string utf32_5(U"\uf900\uf901\uf902\uf903");
        const std::u32string utf32_6(U"\U00010000\U00010001\U00010002\U00010003");

        std::vector<utf::CodePoint> cp_1 = {0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
                                            0x6c, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x79, 0x76, 0x77, 0x78,
                                            0x79, 0x7a, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                                            0x30, 0x2d, 0x3d, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a,
                                            0x28, 0x29, 0x5f, 0x2b, 0x7b, 0x7d, 0x7c, 0x5b, 0x5d, 0x5c, 0x3b,
                                            0x27, 0x3a, 0x22, 0x2c, 0x2e, 0x2f, 0x3c, 0x3e, 0x3f, 0x60, 0x7e};
        std::vector<utf::CodePoint> cp_2 = {0xA3, 0xa4, 0xa5};
        std::vector<utf::CodePoint> cp_3 = {0x7cc2, 0x7cc3, 0x7cc4};
        std::vector<utf::CodePoint> cp_4 = {0xd7f8, 0xd7f9, 0xd7fa, 0xd7fb};
        std::vector<utf::CodePoint> cp_5 = {0xf900, 0xf901, 0xf902, 0xf903};
        std::vector<utf::CodePoint> cp_6 = {0x00010000, 0x00010001, 0x00010002, 0x00010003};

        TEST_ASSERT(utf::to_codepoints(utf32_1) == cp_1, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf32_2) == cp_2, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf32_3) == cp_3, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf32_4) == cp_4, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf32_5) == cp_5, "Convertion to codepoints failed.");
        TEST_ASSERT(utf::to_codepoints(utf32_6) == cp_6, "Convertion to codepoints failed.");
    }
};

int main()
{
    return run_tests(UtfTest());
}
