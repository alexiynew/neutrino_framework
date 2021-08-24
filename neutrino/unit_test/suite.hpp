////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Declaration of base class for tests.
/// @author Fedorov Alexey
/// @date 04.03.2017
////////////////////////////////////////////////////////////////////////////////

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

#ifndef FRAMEWORK_UNIT_TEST_SUITE_HPP
#define FRAMEWORK_UNIT_TEST_SUITE_HPP

#include <functional>
#include <string>
#include <vector>

#include <common/types.hpp>

////////////////////////////////////////////////////////////////////////////////
/// @brief Contains classes related to unit tests.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @details
///
/// You should use the `unit_test::Suite` as base class for your tests.
/// @code
/// class example_test : public framework::unit_test::Suite
/// {
/// public:
///     example_test() : Suite("example_test_name")
///     {
///         add_test([this]() { test_function(); }, "test_function_name");
///     }
/// private:
///     void test_function()
///     {
///         TEST_ASSERT(false, "Test fail message.");
///     }
/// };
/// @endcode
///
/// Use the `unit_test::Suite::add_test` function to add tests to curretn Suite.
/// @code
/// add_test([this]() { test_function(); }, "test_function_name");
/// @endcode
///
/// Use the `unit_test::Suite::test_failed` function to mark test as failed.
/// You can use @ref TEST_FAIL and @ref TEST_ASSERT macros
/// to get @b file path and @b line number.
/// @code
/// TEST_FAIL("Test fail message.");
/// TEST_ASSERT(false, "Test fail message.");
/// @endcode
///
/// And then you can run this test.
/// @code
/// framework::unit_test::Suite* test_suite = new example_test();
/// test_suite->run();
/// @endcode
///
/// Or you can launch group of tests.
/// @code
/// run_tests(example_test(), other_example_test());
/// @endcode
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @defgroup unit_test_module Unit test
////////////////////////////////////////////////////////////////////////////////

namespace framework::unit_test
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup unit_test_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Base class to work with tests.
////////////////////////////////////////////////////////////////////////////////
class Suite
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates test Suite with provided name.
    ///
    /// @param name Name of the test Suite.
    ////////////////////////////////////////////////////////////////////////////
    explicit Suite(std::string name);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Function to run all tests in the Suite.
    ////////////////////////////////////////////////////////////////////////////
    void run();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Checks if all tests finished successfully.
    ///
    /// @return @b true if all tests were successful.
    ////////////////////////////////////////////////////////////////////////////
    bool is_succeeded() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Suite name.
    ///
    /// @return The name of this Suite.
    ////////////////////////////////////////////////////////////////////////////
    std::string name() const;

protected:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Function type shortcut, for internal usage.
    ////////////////////////////////////////////////////////////////////////////
    using FunctionType = std::function<void()>;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Adds function to test Suite.
    ///
    /// @param function Test function.
    /// @param name Name of the current test function.
    ////////////////////////////////////////////////////////////////////////////
    void add_test(FunctionType&& function, const std::string& name);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Fails current test.
    ///
    /// @param file Path to the source file.
    /// @param line Line number in the file.
    /// @param message Error description.
    ///
    /// @note You can use @ref TEST_FAIL and @ref TEST_ASSERT macros
    ///       to get @b file path and @b line number.
    ////////////////////////////////////////////////////////////////////////////
    void test_failed(const std::string& file, int32 line, const std::string& message);

private:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Test description.
    ////////////////////////////////////////////////////////////////////////////
    struct TestData
    {
        ////////////////////////////////////////////////////////////////////////
        /// @brief Test status info.
        ////////////////////////////////////////////////////////////////////////
        struct Status
        {
            std::string message; ///< Error message.
            std::string file;    ///< Path to test file.
            int32 line;          ///< Line which cause error.
        };

        ////////////////////////////////////////////////////////////////////////
        /// @brief Test result.
        ////////////////////////////////////////////////////////////////////////
        enum class Result
        {
            success,
            fail,
            exception,
        };

        std::string name;
        Status status         = {"", "", 0};
        FunctionType function = nullptr;
        Result reslut         = Result::success;

        TestData(std::string test_name, FunctionType&& function_to_call);
    };

    void output(const TestData& test);

    std::string m_name;

    std::vector<TestData> m_tests;
    std::vector<TestData>::iterator m_current_test;

    bool m_success = true;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Runs test in all test suites.
///
/// @param tests Test suites to run.
///
/// @return Number of test suites that failed.
////////////////////////////////////////////////////////////////////////////////
template <typename... Arguments>
int32 run_tests(Arguments&&... tests)
{
    const int32 count = sizeof...(tests);
    int32 passed      = 0;

    std::vector<framework::unit_test::Suite*> tests_container{&tests...};

    for (auto* test : tests_container) {
        test->run();
        passed += test->is_succeeded() ? 1 : 0;
    }

    return count - passed;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Unconditionally fails current test.
///
/// @param MESSAGE Error description.
////////////////////////////////////////////////////////////////////////////////
#define TEST_FAIL(MESSAGE) test_failed(__FILE__, __LINE__, (MESSAGE)) // NOLINT

////////////////////////////////////////////////////////////////////////////////
/// @brief Fails current test if EXPRESSION evaluates to @b false.
///
/// @param EXPRESSION Expression to check as test condition.
/// @param MESSAGE Error description.
////////////////////////////////////////////////////////////////////////////////
#define TEST_ASSERT(EXPRESSION, MESSAGE) !(EXPRESSION) ? TEST_FAIL(MESSAGE) : static_cast<void>(0)

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::unit_test

#endif
