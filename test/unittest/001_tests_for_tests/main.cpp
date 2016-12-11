#include <iomanip>
#include <iostream>

#include <unittest/test.h>

#pragma mark - tests to be tested

class ShouldFailTest : public test::Suite
{
public:
    ShouldFailTest()
        : Suite("ShouldFailTest")
    {
        add_test([this]() { testAssert(); }, "testAssert");
        add_test([this]() { testFail(); }, "testFail");
    }

private:
    void testAssert()
    {
        TEST_ASSERT(false, "Test assert message.");
    }

    void testFail()
    {
        TEST_FAIL("Test fail message.");
    }
};

class ShouldPassTest : public test::Suite
{
public:
    ShouldPassTest()
        : Suite("ShouldPassTest")
    {
        add_test([this]() { testAssert(); }, "testAssert");
    }

private:
    void testAssert()
    {
        TEST_ASSERT(true, "Test assert message.");
    }
};

#pragma mark - test suite for tests

class TestForTest : public test::Suite
{
public:
    TestForTest()
        : Suite("TestForTest")
    {
        add_test([this]() { shouldFail(); }, "shouldFail");
        add_test([this]() { shouldPass(); }, "shouldPass");
    }

private:
    void shouldFail()
    {
        ShouldFailTest should_fail;

        runSuite(should_fail);

        TEST_ASSERT(!should_fail.is_successed(), "This test should fail.");
    }

    void shouldPass()
    {
        ShouldPassTest should_pass;

        runSuite(should_pass);

        TEST_ASSERT(should_pass.is_successed(), "This test should pass.");
    }

    void runSuite(test::Suite& test)
    {
        std::streambuf* cout_buffer = std::cout.rdbuf();
        std::cout.rdbuf(nullptr);

        test.run();

        std::cout.rdbuf(cout_buffer);
        std::cout << std::setw(0);
    }
};

#pragma mark - main function

int main()
{
    return run_tests(TestForTest());
}
