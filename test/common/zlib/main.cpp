
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
#include <common/zlib.hpp>
#include <unit_test/suite.hpp>

using framework::uint8;

std::string to_string(const std::vector<uint8>& data)
{
    return std::string(reinterpret_cast<const char*>(data.data()), data.size());
}

std::vector<uint8> to_vector(const std::string& str)
{
    return std::vector<uint8>(str.c_str(), str.c_str() + str.size());
}

class zlib_test : public framework::unit_test::suite
{
public:
    zlib_test() : suite("zlib_test")
    {
        add_test([this]() { inflate_test(); }, "inflate_test");
        add_test([this]() { deflate_test(); }, "daflate_test");
    }

private:
    void inflate_test()
    {
        using namespace framework::utils::zlib;

        std::vector<uint8> best  = inflate(best_compression);
        std::vector<uint8> speed = inflate(best_speed);
        std::vector<uint8> def   = inflate(default_compression);
        std::vector<uint8> no    = inflate(no_compression);

        TEST_ASSERT(to_string(best) == data, "Inflate error.");
        TEST_ASSERT(to_string(speed) == data, "Inflate error.");
        TEST_ASSERT(to_string(def) == data, "Inflate error.");
        TEST_ASSERT(to_string(no) == data, "Inflate error.");
    }

    void deflate_test()
    {
        using namespace framework::utils::zlib;

        std::vector<uint8> best  = deflate(to_vector(data), compression::best_compression);
        std::vector<uint8> speed = deflate(to_vector(data), compression::best_speed);
        std::vector<uint8> def   = deflate(to_vector(data), compression::default_compression);
        std::vector<uint8> no    = deflate(to_vector(data), compression::no_compression);

        TEST_ASSERT(best == best_compression, "Deflate error.");
        TEST_ASSERT(speed == best_speed, "Deflate error.");
        TEST_ASSERT(def == default_compression, "Deflate error.");
        TEST_ASSERT(no == no_compression, "Deflate error.");
    }

    std::string data = "Hello Hello Hello Hello Hello Hello!";

    std::vector<framework::uint8> best_compression = {
    0x78, 0xDA, 0xF3, 0x48, 0xCD, 0xC9, 0xC9, 0x57, 0xF0, 0xC0, 0x47, 0x2A, 0x32, 0x00, 0x00, 0xF5, 0x49, 0x0C, 0x7A,
    };

    std::vector<framework::uint8> best_speed = {
    0x78, 0x01, 0xF3, 0x48, 0xCD, 0xC9, 0xC9, 0x57, 0xF0, 0xC0, 0x47, 0x2A, 0x32, 0x00, 0x00, 0xF5, 0x49, 0x0C, 0x7A,
    };

    std::vector<framework::uint8> default_compression = {
    0x78, 0x9C, 0xF3, 0x48, 0xCD, 0xC9, 0xC9, 0x57, 0xF0, 0xC0, 0x47, 0x2A, 0x32, 0x00, 0x00, 0xF5, 0x49, 0x0C, 0x7A,
    };

    std::vector<framework::uint8> no_compression = {
    0x78, 0x01, 0x01, 0x25, 0x00, 0xDA, 0xFF, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C,
    0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48,
    0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x21, 0x00, 0xF5, 0x49, 0x0C, 0x7A,
    };
};

int main()
{
    return run_tests(zlib_test());
}
