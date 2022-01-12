#include <cstdint>
#include <sstream>

#include <common/utils.hpp>
#include <unit_test/suite.hpp>

class RandomNumbersTest : public framework::unit_test::Suite
{
public:
    RandomNumbersTest()
        : Suite("RandomNumbersTest")
    {
        add_test([this]() { generate_random_numbers(); }, "generate_random_numbers");
    }

private:
    void generate_random_numbers()
    {
        using namespace framework::utils;

        const auto no_numbers = random_numbers<float>(-1000.0f, 1000.0f, 0);
        TEST_ASSERT(no_numbers.size() == 0, "Wrond numbers count.");

        const auto numbers = random_numbers<int>(0, 0, 1000);
        TEST_ASSERT(numbers.size() == 1000, "Wrond numbers count.");

        for (auto i : numbers) {
            TEST_ASSERT(i == 0, "Wrong number in the sequence.");
        }

        for (auto i : random_numbers<double>(0.0, 1.0, 10)) {
            TEST_ASSERT(i >= 0.0 && i <= 1.0, "Wrong number in the sequence.");
        }

        for (auto i : random_numbers<std::uint16_t>(0xFFFF, 0, 1000)) {
            TEST_ASSERT(i >= 0 && i <= 0xFFFF, "Wrong number in the sequence.");
        }
    }
};

class ReadValueFromBufferTest : public framework::unit_test::Suite
{
public:
    ReadValueFromBufferTest()
        : Suite("ReadValueFromBufferTest")
    {
        add_test([this]() { read_big_endian_value_from_buffer(); }, "read_big_endian_value_from_buffer");
        add_test([this]() { read_little_endian_value_from_buffer(); }, "read_little_endian_value_from_buffer");
    }

private:
    void read_big_endian_value_from_buffer()
    {
        using namespace framework::utils;

        char buffer1[] = {0x1};
        char buffer2[] = {0x1, 0x0};
        char buffer3[] = {0x1, 0x0, 0x0, 0x0};

        char value1  = big_endian_value<char>(std::begin(buffer1), std::end(buffer1));
        short value2 = big_endian_value<short>(std::begin(buffer2), std::end(buffer2));
        int value3   = big_endian_value<int>(std::begin(buffer3), std::end(buffer3));

        TEST_ASSERT(value1 == 0x01, "Wrong value");
        TEST_ASSERT(value2 == 0x0100, "Wrong value");
        TEST_ASSERT(value3 == 0x01000000, "Wrong value");
    }

    void read_little_endian_value_from_buffer()
    {
        using namespace framework::utils;

        char buffer1[] = {0x1};
        char buffer2[] = {0x1, 0x0};
        char buffer3[] = {0x1, 0x0, 0x0, 0x0};

        char value1  = little_endian_value<char>(std::begin(buffer1), std::end(buffer1));
        short value2 = little_endian_value<short>(std::begin(buffer2), std::end(buffer2));
        int value3   = little_endian_value<int>(std::begin(buffer3), std::end(buffer3));

        TEST_ASSERT(value1 == 0x01, "Wrong value");
        TEST_ASSERT(value2 == 0x0001, "Wrong value");
        TEST_ASSERT(value3 == 0x00000001, "Wrong value");
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
    return run_tests(RandomNumbersTest(), ReadValueFromBufferTest());
}
