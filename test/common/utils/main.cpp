#include <limits>

#include <common/utils.hpp>
#include <unit_test/suite.hpp>

class random_numbers_test : public framework::unit_test::suite
{
public:
    random_numbers_test() : suite("random_numbers_test")
    {
        add_test([this]() { random_numbers(); }, "random_numbers");
    }

private:
    void random_numbers()
    {
        using ::framework::float32;
        using ::framework::float64;
        using ::framework::int32;
        using ::framework::uint8;

        using ::framework::utils::random_numbers;

        const auto no_numbers = random_numbers<float32>(-1000.0f, 1000.0f, 0);
        TEST_ASSERT(no_numbers.size() == 0, "Wrond numbers count.");

        const auto numbers = random_numbers<int32>(0, 0, 1000);
        TEST_ASSERT(numbers.size() == 1000, "Wrond numbers count.");

        for (auto i : numbers) {
            if (i != 0) {
                TEST_FAIL("Wrong number in the sequence.");
            }
        }

        for (auto i : random_numbers<float64>(0.0, 1.0, 10)) {
            if (i < 0.0 || i > 1.0) {
                TEST_FAIL("Wrong number in the sequence.");
            }
        }

        for (int32 i : random_numbers<uint8>(255, 0, 1000)) {
            if (i < 0 || i > 255) {
                TEST_FAIL("Wrong number in the sequence.");
            }
        }
    }
};

class format_string_test : public framework::unit_test::suite
{
public:
    format_string_test() : suite("format_string_test")
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

int main()
{
    return run_tests(random_numbers_test(), format_string_test());
}
