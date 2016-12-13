#include <iomanip>
#include <iostream>

#include <unit_test/test.hpp>

#pragma mark - tests to be tested

class should_fail_test : public test::suite
{
public:
    should_fail_test()
        : suite("should_fail_test")
    {
        add_test([this]() { test_assert(); }, "test_assert");
        add_test([this]() { test_fail(); }, "test_fail");
    }

private:
    void test_assert()
    {
        TEST_ASSERT(false, "Test assert message.");
    }

    void test_fail()
    {
        TEST_FAIL("Test fail message.");
    }
};

class should_pass_test : public test::suite
{
public:
    should_pass_test()
        : suite("should_pass_test")
    {
        add_test([this]() { test_assert(); }, "test_assert");
    }

private:
    void test_assert()
    {
        TEST_ASSERT(true, "Test assert message.");
    }
};

#pragma mark - test suite for tests

class test_for_test : public test::suite
{
public:
    test_for_test()
        : suite("test_for_test")
    {
        add_test([this]() { should_fail(); }, "should_fail");
        add_test([this]() { should_pass(); }, "should_pass");
    }

private:
    void should_fail()
    {
        should_fail_test should_fail;

        run_suite(should_fail);

        TEST_ASSERT(!should_fail.is_succeeded(), "This test should fail.");
    }

    void should_pass()
    {
        should_pass_test should_pass;

        run_suite(should_pass);

        TEST_ASSERT(should_pass.is_succeeded(), "This test should pass.");
    }

    void run_suite(test::suite& test)
    {
        std::streambuf* buffer = std::cout.rdbuf();
        std::cout.rdbuf(nullptr);

        test.run();

        std::cout.rdbuf(buffer);
        std::cout << std::setw(0);
    }
};

#pragma mark - main function

int main()
{
    return run_tests(test_for_test());
}
