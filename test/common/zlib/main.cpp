
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

#include <string>
#include <vector>

#include <common/types.hpp>
#include <common/zlib.hpp>
#include <unit_test/suite.hpp>

using framework::uint8;

std::vector<uint8> to_vector(const std::string& str);

std::vector<uint8> to_vector(const std::string& str)
{
    std::vector<uint8> data(str.c_str(), str.c_str() + str.size());
    data.push_back(0x00);
    return data;
}

class ZlibTest : public framework::unit_test::Suite
{
public:
    ZlibTest()
        : Suite("ZlibTest")
        , data(to_vector("Hello Hello Hello Hello Hello Hello!"))
    {
        add_test([this]() { inflate_test(); }, "inflate_test");
        add_test([this]() { deflate_test(); }, "daflate_test");
    }

private:
    void inflate_test()
    {
        using namespace framework::zlib;

        const std::vector<uint8> fixed   = inflate(fixed_huffman);
        const std::vector<uint8> dynamic = inflate(dynamic_huffman);
        const std::vector<uint8> no      = inflate(no_compression);

        TEST_ASSERT(fixed == data, "Inflate error.");
        TEST_ASSERT(dynamic == data, "Inflate error.");
        TEST_ASSERT(no == data, "Inflate error.");
    }

    void deflate_test()
    {
        using namespace framework::zlib;

        const std::vector<uint8> compressed   = deflate(data);
        const std::vector<uint8> decompressed = inflate(compressed);

        TEST_ASSERT(decompressed == data, "Deflate error.");
    }

    std::vector<uint8> data;

    std::vector<uint8> fixed_huffman = {
    0x78, 0xDA, 0xF3, 0x48, 0xCD, 0xC9, 0xC9, 0x57, 0xF0, 0xC0, 0x47, 0x2A, 0x32, 0x00, 0x00, 0xF5, 0x49, 0x0C, 0x7A,
    };

    std::vector<uint8> dynamic_huffman = {
    0x78, 0xDA, 0x05, 0xC1, 0x31, 0x0D, 0x00, 0x30, 0x10, 0x03, 0xB1, 0x42, 0x49,
    0xD9, 0x84, 0x48, 0xB6, 0x93, 0x8E, 0xFF, 0xF6, 0x76, 0x07, 0xA6, 0x03, 0xD3,
    0x81, 0xE9, 0xC0, 0x74, 0x60, 0x3A, 0xF0, 0xBF, 0x03, 0xF5, 0x49, 0x0C, 0x7A,
    };

    std::vector<uint8> no_compression = {
    0x78, 0x01, 0x01, 0x25, 0x00, 0xDA, 0xFF, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C,
    0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48,
    0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x21, 0x00, 0xF5, 0x49, 0x0C, 0x7A,
    };
};

int main()
{
    return run_tests(ZlibTest());
}
