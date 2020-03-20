
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

#include <limits>

#include <common/utils.hpp>
#include <unit_test/suite.hpp>

class random_numbers_test : public framework::unit_test::Suite
{
public:
    random_numbers_test() : Suite("random_numbers_test")
    {
        add_test([this]() { random_numbers(); }, "random_numbers");
    }

private:
    void random_numbers()
    {
        using ::framework::float32;
        using ::framework::float64;
        using ::framework::int32;
        using ::framework::uint16;

        using ::framework::utils::random_numbers;

        const auto no_numbers = random_numbers<float32>(-1000.0f, 1000.0f, 0);
        TEST_ASSERT(no_numbers.size() == 0, "Wrond numbers count.");

        const auto numbers = random_numbers<int32>(0, 0, 1000);
        TEST_ASSERT(numbers.size() == 1000, "Wrond numbers count.");

        for (auto i : numbers) {
            TEST_ASSERT(i == 0, "Wrong number in the sequence.");
        }

        for (auto i : random_numbers<float64>(0.0, 1.0, 10)) {
            TEST_ASSERT(i >= 0.0 && i <= 1.0, "Wrong number in the sequence.");
        }

        for (int32 i : random_numbers<uint16>(0xFFFF, 0, 1000)) {
            TEST_ASSERT(i >= 0 && i <= 0xFFFF, "Wrong number in the sequence.");
        }
    }
};

/*
class format_string_test : public framework::unit_test::Suite
{
public:
    format_string_test() : Suite("format_string_test")
    {
        add_test([this]() { type_foramting(); }, "type_formating");
    }

private:
    void type_foramting()
    {
        using framework::utils::format;

        TEST_ASSERT(format("{0}", 1) == "1", "Wrong number formating.");

        TEST_ASSERT(format("{0}", 1.123456789) == "1.12346", "Wrong floating-point number formating.");

        TEST_ASSERT(format("{0}", "string") == "string", "Wrong string formating.");

        TEST_ASSERT(format("{{{0}}}", "string") == "{string}", "Wrong braces formating.");
        TEST_ASSERT(format("{0}}}", "string") == "string}", "Wrong braces formating.");
        TEST_ASSERT(format("{{{0}", "string") == "{string", "Wrong braces formating.");

        // ERROR_TEST(make_string("{{0}}}", "string"), "Single '}' in format string");
        // ERROR_TEST(make_string("{{{0}}", "string"), "Single '}' in format string");
        // ERROR_TEST(make_string("0}}}", "string"), "Single '}' in format string");
        // ERROR_TEST(make_string("{{{0", "string"), "'}' expected");
    }
};
*/

int main()
{
    return run_tests(random_numbers_test());
}
