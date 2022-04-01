#include <vector>

#include <common/utf.hpp>

namespace
{
using framework::utf::CodePoint;

using U8Type       = std::string::value_type;
using U16Type      = std::u16string::value_type;
using U32Type      = std::u32string::value_type;
using WideCharType = std::wstring::value_type;

std::pair<CodePoint, size_t> get_code_point(const std::string& str, size_t pos)
{
    // 1-byte UTF-8 = 0xxxxxxx = 7 bits = 0x00 - 0x7F
    // 2-byte UTF-8 = 110xxxxx 10xxxxxx = 5+6(11) bits = 0x80 - 0x7FF
    // 3-byte UTF-8 = 1110xxxx 10xxxxxx 10xxxxxx = 4+6+6(16) bits = 0x800 - 0xFFFF
    // 4-byte UTF-8 = 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx = 3+6+6+6(21) bits = 0x10000 - 0x10FFFF

    if (pos >= str.length()) {
        return std::make_pair(0, 0);
    }

    CodePoint cp = static_cast<CodePoint>(str[pos] & 0xFF);

    if (cp >= 0x80 && cp <= 0xBF) {
        // error, missing code point first byte
        return std::make_pair(0, 0);
    }

    std::size_t offset = 1;
    if (cp <= 0x7F) {
        return std::make_pair(cp, 1);
    } else if (cp >= 0xC0 && cp <= 0xDF) {
        cp     = cp & 0x1F;
        offset = 2;
    } else if (cp >= 0xE0 && cp <= 0xEF) {
        cp     = cp & 0x0F;
        offset = 3;
    } else if (cp >= 0xF0 && cp <= 0xF7) {
        cp     = cp & 0x07;
        offset = 4;
    } else {
        // error, unknown byte
        return std::make_pair(0, 0);
    }

    if (pos + offset > str.length()) {
        // error, not enough chars in string
        return std::make_pair(0, 0);
    }

    for (size_t i = 1; i < offset; i++) {
        cp <<= 6;
        cp |= str[pos + i] & 0b00111111;
    }

    return std::make_pair(cp, offset);
}

std::pair<CodePoint, size_t> get_code_point(const std::u16string& str, size_t pos)
{
    if (pos >= str.length()) {
        return std::make_pair(0, 0);
    }

    const U16Type first = str[pos];
    if (first <= 0xD7FF || first >= 0xE000) {
        return std::make_pair(first, 1);
    }

    if (pos + 1 >= str.length()) {
        // error, need to get second part of codepoint
        return std::make_pair(0, 0);
    }

    const CodePoint second = str[pos + 1];
    const CodePoint cp     = static_cast<CodePoint>((first ^ 0xD800) << 10) | (second ^ 0xDC00) | 0x10000;

    return std::make_pair(cp, 2);
}

std::pair<CodePoint, size_t> get_code_point(const std::u32string& str, size_t pos)
{
    if (pos >= str.length()) {
        return std::make_pair(0, 0);
    }

    return std::make_pair(static_cast<CodePoint>(str[pos]), 1);
}

std::pair<CodePoint, size_t> get_code_point(const std::wstring& str, size_t pos)
{
    if (pos >= str.length()) {
        return std::make_pair(0, 0);
    }

    if constexpr (sizeof(WideCharType) == sizeof(U16Type)) {
        // save as utf-16, but different cnar type

        const WideCharType first = str[pos];
        if (first <= 0xD7FF || first >= 0xE000) {
            return std::make_pair(first, 1);
        }

        if (pos + 1 >= str.length()) {
            // error, need to get second part of codepoint
            return std::make_pair(0, 0);
        }

        const CodePoint second = str[pos + 1];
        const CodePoint cp     = static_cast<CodePoint>((first ^ 0xD800) << 10) | (second ^ 0xDC00) | 0x10000;

        return std::make_pair(cp, 2);
    } else {
        // save as utf-32, but different cnar type
        return std::make_pair(static_cast<CodePoint>(str[pos]), 1);
    }
}

std::vector<U8Type>::iterator set_as_utf8(std::vector<U8Type>::iterator to, CodePoint cp)
{
    // 1-byte UTF-8 = 0xxxxxxx = 7 bits = 0x00 - 0x7F
    // 2-byte UTF-8 = 110xxxxx 10xxxxxx = 5+6(11) bits = 0x80 - 0x7FF
    // 3-byte UTF-8 = 1110xxxx 10xxxxxx 10xxxxxx = 4+6+6(16) bits = 0x800 - 0xFFFF
    // 4-byte UTF-8 = 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx = 3+6+6+6(21) bits = 0x10000 - 0x10FFFF

    if (cp <= 0x7F) {
        to[0] = static_cast<U8Type>(cp & 0x7f);
        return to + 1;
    } else if (cp >= 0x80 && cp <= 0x7FF) {
        to[0] = static_cast<U8Type>(((cp >> 6) & 0x1F) | 0xC0);
        to[1] = static_cast<U8Type>(((cp >> 0) & 0x3F) | 0x80);
        return to + 2;
    } else if (cp >= 0x800 && cp <= 0xFFFF) {
        to[0] = static_cast<U8Type>(((cp >> 12) & 0x0F) | 0xE0);
        to[1] = static_cast<U8Type>(((cp >> 6) & 0x3F) | 0x80);
        to[2] = static_cast<U8Type>(((cp >> 0) & 0x3F) | 0x80);
        return to + 3;
    } else if (cp >= 0x10000 && cp <= 0x10FFFF) {
        to[0] = static_cast<U8Type>(((cp >> 18) & 0x07) | 0xF0);
        to[1] = static_cast<U8Type>(((cp >> 12) & 0x3F) | 0x80);
        to[2] = static_cast<U8Type>(((cp >> 6) & 0x3F) | 0x80);
        to[3] = static_cast<U8Type>(((cp >> 0) & 0x3F) | 0x80);
        return to + 4;
    }

    return to;
}

std::vector<U16Type>::iterator set_as_utf16(std::vector<U16Type>::iterator to, CodePoint cp)
{
    // 2-byte UTF-16 xxxx = 0x0000 to 0xD7FF or 0xE000 to 0xFFFF
    // 2-byte UTF-16 0xD800 to 0xDFFF are invalid
    // 4-byte UTF-16 110110xxxxxxxxxx 110111xxxxxxxxxx = 10+10(20) bits = 0x10000 to 0x10FFFF as (cp - 0x10000)

    if (cp <= 0xD7FF || (cp >= 0xE000 && cp <= 0xFFFF)) {
        to[0] = static_cast<U16Type>(cp & 0xFFFF);
        return to + 1;
    } else if (cp >= 0x10000 && cp <= 0x10FFFF) {
        cp -= 0x10000;
        to[0] = static_cast<U16Type>(((cp >> 10) & 0x3FF) | 0xD800);
        to[1] = static_cast<U16Type>(((cp >> 0) & 0x3FF) | 0xDC00);
        return to + 2;
    } else {
        // invalide codepoint
    }

    return to;
}

std::vector<U32Type>::iterator set_as_utf32(std::vector<U32Type>::iterator to, CodePoint cp)
{
    *to = cp;
    return to + 1;
}

std::vector<WideCharType>::iterator set_as_widechar(std::vector<WideCharType>::iterator to, CodePoint cp)
{
    if constexpr (sizeof(WideCharType) == sizeof(U16Type)) {
        // save as utf-16, but different cnar type

        // 2-byte UTF-16 xxxx = 0x0000 to 0xD7FF or 0xE000 to 0xFFFF
        // 2-byte UTF-16 0xD800 to 0xDFFF are invalid
        // 4-byte UTF-16 110110xxxxxxxxxx 110111xxxxxxxxxx = 10+10(20) bits = 0x10000 to 0x10FFFF as (cp - 0x10000)

        if (cp <= 0xD7FF || (cp >= 0xE000 && cp <= 0xFFFF)) {
            to[0] = static_cast<WideCharType>(cp & 0xFFFF);
            return to + 1;
        } else if (cp >= 0x10000 && cp <= 0x10FFFF) {
            cp -= 0x10000;
            to[0] = static_cast<WideCharType>(((cp >> 10) & 0x3FF) | 0xD800);
            to[1] = static_cast<WideCharType>(((cp >> 0) & 0x3FF) | 0xDC00);
            return to + 2;
        } else {
            // invalide codepoint
        }

    } else {
        // save as utf-32, but different cnar type
        *to = static_cast<WideCharType>(cp);
        return to + 1;
    }

    return to;
}

template <typename T>
std::string to_utf8_impl(const T& str, std::size_t buffer_size)
{
    std::vector<U8Type> buffer(buffer_size, '\0');

    size_t pos = 0;
    size_t end = str.length();
    auto to    = buffer.begin();

    while (pos != end) {
        auto [cp, offset] = get_code_point(str, pos);
        to                = set_as_utf8(to, cp);
        pos += offset;
        if (offset == 0) {
            break;
        }
    }

    return std::string(buffer.data());
}

template <typename T>
std::u16string to_utf16_impl(const T& str, std::size_t buffer_size)
{
    std::vector<U16Type> buffer(buffer_size, '\0');

    size_t pos = 0;
    size_t end = str.length();
    auto to    = buffer.begin();

    while (pos != end) {
        auto [cp, offset] = get_code_point(str, pos);
        to                = set_as_utf16(to, cp);
        pos += offset;
        if (offset == 0) {
            break;
        }
    }

    return std::u16string(buffer.data());
}

template <typename T>
std::u32string to_utf32_impl(const T& str, std::size_t buffer_size)
{
    std::vector<U32Type> buffer(buffer_size, '\0');

    size_t pos = 0;
    size_t end = str.length();
    auto to    = buffer.begin();

    while (pos != end) {
        auto [cp, offset] = get_code_point(str, pos);
        to                = set_as_utf32(to, cp);
        pos += offset;
        if (offset == 0) {
            break;
        }
    }

    return std::u32string(buffer.data());
}

template <typename T>
std::wstring to_wstring_impl(const T& str, std::size_t buffer_size)
{
    std::vector<WideCharType> buffer(buffer_size, '\0');

    size_t pos = 0;
    size_t end = str.length();
    auto to    = buffer.begin();

    while (pos != end) {
        auto [cp, offset] = get_code_point(str, pos);
        to                = set_as_widechar(to, cp);
        pos += offset;
        if (offset == 0) {
            break;
        }
    }

    return std::wstring(buffer.data());
}

template <typename T>
std::vector<CodePoint> to_codepoints_impl(const T& str)
{
    const size_t buffer_size = str.length();
    std::vector<CodePoint> buffer;
    buffer.reserve(buffer_size);

    size_t pos = 0;
    size_t end = str.length();

    while (pos != end) {
        auto [cp, offset] = get_code_point(str, pos);

        buffer.push_back(cp);
        pos += offset;
        if (offset == 0) {
            break;
        }
    }

    return buffer;
}

} // namespace

namespace framework::utf
{

std::string to_utf8(const std::u16string& str)
{
    const size_t buffer_size = str.length() * 4 + 1;
    return to_utf8_impl(str, buffer_size);
}

std::string to_utf8(const std::u32string& str)
{
    const size_t buffer_size = str.length() * 4 + 1;
    return to_utf8_impl(str, buffer_size);
}

std::string to_utf8(const std::wstring& str)
{
    static_assert(sizeof(WideCharType) == sizeof(U16Type) || sizeof(WideCharType) == sizeof(U32Type));

    const size_t buffer_size = str.length() * 4 + 1;
    return to_utf8_impl(str, buffer_size);
}

std::u16string to_utf16(const std::string& str)
{
    const size_t buffer_size = str.length() + 1;
    return to_utf16_impl(str, buffer_size);
}

std::u16string to_utf16(const std::u32string& str)
{
    const size_t buffer_size = str.length() * 2 + 1;
    return to_utf16_impl(str, buffer_size);
}

std::u16string to_utf16(const std::wstring& str)
{
    static_assert(sizeof(WideCharType) == sizeof(U16Type) || sizeof(WideCharType) == sizeof(U32Type));

    const size_t buffer_size = (sizeof(WideCharType) == sizeof(U16Type) ? str.length() : str.length() * 2) + 1;
    return to_utf16_impl(str, buffer_size);
}

std::u32string to_utf32(const std::string& str)
{
    const size_t buffer_size = str.length() + 1;
    return to_utf32_impl(str, buffer_size);
}

std::u32string to_utf32(const std::u16string& str)
{
    const size_t buffer_size = str.length() + 1;
    return to_utf32_impl(str, buffer_size);
}

std::u32string to_utf32(const std::wstring& str)
{
    static_assert(sizeof(WideCharType) == sizeof(U16Type) || sizeof(WideCharType) == sizeof(U32Type));

    const size_t buffer_size = str.length() + 1;
    return to_utf32_impl(str, buffer_size);
}

std::wstring to_wstring(const std::string& str)
{
    static_assert(sizeof(WideCharType) == sizeof(U16Type) || sizeof(WideCharType) == sizeof(U32Type));

    const size_t buffer_size = str.length() + 1;
    return to_wstring_impl(str, buffer_size);
}

std::wstring to_wstring(const std::u16string& str)
{
    static_assert(sizeof(WideCharType) == sizeof(U16Type) || sizeof(WideCharType) == sizeof(U32Type));

    const size_t buffer_size = str.length() + 1;
    return to_wstring_impl(str, buffer_size);
}

std::wstring to_wstring(const std::u32string& str)
{
    static_assert(sizeof(WideCharType) == sizeof(U16Type) || sizeof(WideCharType) == sizeof(U32Type));

    const size_t buffer_size = (sizeof(WideCharType) == sizeof(U16Type) ? str.length() * 2 : str.length()) + 1;
    return to_wstring_impl(str, buffer_size);
}

std::vector<CodePoint> to_codepoints(const std::string& str)
{
    return to_codepoints_impl(str);
}

std::vector<CodePoint> to_codepoints(const std::u16string& str)
{
    return to_codepoints_impl(str);
}

std::vector<CodePoint> to_codepoints(const std::u32string& str)
{
    return to_codepoints_impl(str);
}

std::vector<CodePoint> to_codepoints(const std::wstring& str)
{
    return to_codepoints_impl(str);
}

} // namespace framework::utf
