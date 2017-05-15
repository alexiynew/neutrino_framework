/**
 * @file
 * @brief Declaration of base class for tests.
 * @author Fedorov Alexey
 * @date 04.03.2017
 */

#ifndef FRAMEWORK_UNIT_TEST_SUITE_HPP
#define FRAMEWORK_UNIT_TEST_SUITE_HPP

#include <functional>
#include <string>
#include <vector>

namespace framework {

/**
 * @defgroup unit_test_module Unit test module
 * @{
 */

/**
 * @brief Contains classes related to unit tests.
 */
namespace unit_test {

/**
 * @brief Base class to work with tests.
 *
 * You should use it as the base class for your test classes.
 * @code
 * class example_test : public framework::unit_test::suite
 * {
 * public:
 *     example_test() : suite("example_test_name")
 *     {
 *         add_test([this]() { test_function(); }, "test_function_name");
 *     }
 * private:
 *     void test_function()
 *     {
 *         TEST_ASSERT(false, "Test fail message.");
 *     }
 * };
 * @endcode
 *
 * And then you can run this test.
 * @code
 * framework::unit_test::suite* test_suite = new example_test();
 * test_suite->run();
 * @endcode
 *
 * Or you can launch group of tests.
 * @code
 * run_tests(example_test(), other_example_test());
 * @endcode
 */
class suite
{
public:
    /**
     * @brief Creates test suite with provided name.
     *
     * @param name Name of the test suite.
     */
    suite(const std::string& name);

    /**
     * @brief Function to run all tests in the suite.
     */
    void run();

    /**
     * @brief Checks if all tests finished successfully.
     *
     * @return @b true if all tests were successful.
     */
    bool is_succeeded() const;

protected:
    /** Creates a function shortcut for internal usage */
    using function_type = std::function<void()>;

    /**
     * @brief Adds function to test suite.
     *
     * @param function Member function of the derived class.
     * @param name Name of the current test function.
     */
    void add_test(function_type&& function, const std::string& name);

    /**
     * @brief Fails current test.
     *
     * @param file Path to the source file.
     * @param line Line number in the file.
     * @param message Error description.
     *
     * @note You can use @ref TEST_FAIL and @ref TEST_ASSERT macros to get @b file path and @b line number.
     */
    void test_failed(const std::string& file, int line, const std::string& message);

private:
    /** Test description. */
    struct test_data
    {
        struct Status
        {
            std::string message;
            std::string file;
            int line;
        };

        Status status;
        std::string name;
        function_type function;
        bool success;

        test_data(function_type&& function, const std::string& name);
    };

    void output_fail(const test_data& test);

    void output_success(const test_data& test);

    bool m_success;
    std::string m_name;

    std::vector<test_data> m_tests;
    std::vector<test_data>::iterator m_current_test;
};


/**
 * @brief Runs test in all test suites.
 *
 * @param tests Test suites to run.
 * @return Count of suites were failed.
 */
template <typename... Arguments>
int run_tests(Arguments&&... tests)
{
    int count  = sizeof...(tests);
    int passed = 0;

    std::vector<::framework::unit_test::suite*> tests_container{&tests...};

    for (auto* test : tests_container) {
        test->run();
        passed += test->is_succeeded() ? 1 : 0;
    }

    return count - passed;
}

/**
 * @brief Unconditionally fails current test.
 *
 * @param MESSAGE Error description.
 */
#define TEST_FAIL(MESSAGE) test_failed(__FILE__, __LINE__, (MESSAGE) != 0 ? #MESSAGE : "")

/**
 * @brief Fails current test if EXPRESSION evaluates to @b false.
 *
 * @param EXPRESSION Expression to check as test condition.
 * @param MESSAGE Error description.
 */
#define TEST_ASSERT(EXPRESSION, MESSAGE) !(EXPRESSION) ? TEST_FAIL(MESSAGE) : static_cast<void>(0)

} // namespace unit_test

/**
 * @}
 */

} // namespace framework

#endif
