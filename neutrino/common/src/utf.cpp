/// @file
/// @brief Utf confertions
/// @author Fedorov Alexey
/// @date 23.09.2020

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

#include <vector>

#include <common/utf.hpp>

namespace
{
using framework::utf::CodePoint;

std::pair<CodePoint, size_t> get_code_point(const std::u16string& str, size_t pos)
{
    if (pos >= str.length()) {
        return std::make_pair(0, 0);
    }

    const CodePoint first = str[pos];
    if (first < 0xD800 || first > 0xDFFF) {
        return std::make_pair(first, 1);
    }

    // need to get second part of codepoint
    if (pos + 1 >= str.length()) {
        return std::make_pair(0, 0);
    }

    const CodePoint second = str[pos + 1];
    const CodePoint cp     = ((first ^ 0xD800) << 10) | (second ^ 0xDC00) | 0x10000;

    return std::make_pair(cp, 2);
};

std::vector<char>::iterator set_as_utf8(std::vector<char>::iterator to, CodePoint cp)
{
    // 1-byte UTF-8 = 0xxxxxxx = 7 bits = 0x00 - 0x7F
    // 2-byte UTF-8 = 110xxxxx 10xxxxxx = 5+6(11) bits = 0x80 - 0x7FF
    // 3-byte UTF-8 = 1110xxxx 10xxxxxx 10xxxxxx = 4+6+6(16) bits = 0x800 - 0xFFFF
    // 4-byte UTF-8 = 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx = 3+6+6+6(21) bits = 0x10000 - 0x10FFFF

    if (cp <= 0x7F) {
        to[0] = static_cast<char>(cp & 0x7f);
        return to + 1;
    } else if (cp >= 0x80 && cp <= 0x7FF) {
        to[0] = static_cast<char>(((cp >> 6) & 0x1F) | 0xC0);
        to[1] = static_cast<char>(((cp >> 0) & 0x3F) | 0x80);
        return to + 2;
    } else if (cp >= 0x800 && cp <= 0xFFFF) {
        to[0] = static_cast<char>(((cp >> 12) & 0x0F) | 0xE0);
        to[1] = static_cast<char>(((cp >> 6) & 0x3F) | 0x80);
        to[2] = static_cast<char>(((cp >> 0) & 0x3F) | 0x80);
        return to + 3;
    } else if (cp >= 0x10000 && cp <= 0x10FFFF) {
        to[0] = static_cast<char>(((cp >> 18) & 0x07) | 0xF0);
        to[1] = static_cast<char>(((cp >> 12) & 0x3F) | 0x80);
        to[2] = static_cast<char>(((cp >> 6) & 0x3F) | 0x80);
        to[3] = static_cast<char>(((cp >> 0) & 0x3F) | 0x80);
        return to + 4;
    }

    return to;
}

} // namespace

namespace framework::utf
{

std::string to_utf8(const std::u16string& str)
{
    const size_t buffer_size = str.length() * 4;

    std::vector<char> buffer(buffer_size, '\0');

    size_t begin = 0;
    size_t end   = str.length();
    auto to      = buffer.begin();
    while (begin != end) {
        auto [cp, size] = get_code_point(str, begin);
        to              = set_as_utf8(to, cp);
        begin += size;
    }

    return std::string(buffer.data());
}

} // namespace framework::utf
