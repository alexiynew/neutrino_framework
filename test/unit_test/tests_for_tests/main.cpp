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

#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include <unit_test/suite.hpp>

class CustomException
{};

class ShouldFailTestAssert : public framework::unit_test::Suite
{
public:
    ShouldFailTestAssert()
        : Suite("ShouldFailTestAssert")
    {
        add_test([this]() { test_assert(); }, "test_assert");
    }

private:
    void test_assert()
    {
        TEST_ASSERT(false, "Test assert message.");
    }
};

class ShouldFailTestFail : public framework::unit_test::Suite
{
public:
    ShouldFailTestFail()
        : Suite("ShouldFailTestFail")
    {
        add_test([this]() { test_fail(); }, "test_fail");
    }

private:
    void test_fail()
    {
        TEST_FAIL("Test fail message.");
    }
};

class ShouldFailTestStdException : public framework::unit_test::Suite
{
public:
    ShouldFailTestStdException()
        : Suite("ShouldFailTestStdException")
    {
        add_test([this]() { test_std_exception(); }, "test_std_exception");
    }

private:
    [[noreturn]] void test_std_exception()
    {
        throw std::runtime_error("Test exception");
    }
};

class ShouldFailTestAnyException : public framework::unit_test::Suite
{
public:
    ShouldFailTestAnyException()
        : Suite("ShouldFailTestAnyException")
    {
        add_test([this]() { test_any_exception(); }, "test_any_exception");
    }

private:
    // NOLINTNEXTLINE(hicpp-exception-baseclass)
    [[noreturn]] void test_any_exception()
    {
        throw CustomException();
    }
};

class ShouldPassTest : public framework::unit_test::Suite
{
public:
    ShouldPassTest()
        : Suite("ShouldPassTest")
    {
        add_test([this]() { test_pass(); }, "test_pass");
    }

private:
    void test_pass()
    {}
};

class ShouldPassTestAssert : public framework::unit_test::Suite
{
public:
    ShouldPassTestAssert()
        : Suite("ShouldPassTestAssert")
    {
        add_test([this]() { test_assert(); }, "test_assert");
    }

private:
    void test_assert()
    {
        TEST_ASSERT(true, "Test assert message.");
    }
};

class TestForTest : public framework::unit_test::Suite
{
public:
    TestForTest()
        : Suite("TestForTest")
    {
        add_test([this]() { should_fail(); }, "should_fail");
        add_test([this]() { should_pass(); }, "should_pass");
    }

private:
    void should_fail()
    {
        std::vector<std::unique_ptr<framework::unit_test::Suite>> tests;

        tests.emplace_back(std::make_unique<ShouldFailTestAssert>());
        tests.emplace_back(std::make_unique<ShouldFailTestFail>());
        tests.emplace_back(std::make_unique<ShouldFailTestStdException>());
        tests.emplace_back(std::make_unique<ShouldFailTestAnyException>());

        for (auto& test : tests) {
            run_suite(test.get());

            std::stringstream error_stream;
            error_stream << "Test [" << test->name() << "] should fail.";
            TEST_ASSERT(!test->is_succeeded(), error_stream.str());
        }
    }

    void should_pass()
    {
        std::vector<std::unique_ptr<framework::unit_test::Suite>> tests;
        tests.emplace_back(std::make_unique<ShouldPassTest>());
        tests.emplace_back(std::make_unique<ShouldPassTestAssert>());

        for (auto& test : tests) {
            run_suite(test.get());

            std::stringstream error_stream;
            error_stream << "Test [" << test->name() << "] should pass.";
            TEST_ASSERT(test->is_succeeded(), error_stream.str());
        }
    }

    void run_suite(framework::unit_test::Suite* test)
    {
        std::streambuf* buffer = std::cout.rdbuf();
        std::cout.rdbuf(nullptr);

        try {
            test->run();
        } catch (...) {
        }

        std::cout.rdbuf(buffer);
        std::cout << std::setw(0);
    }
};

int main()
{
    return run_tests(TestForTest());
}
