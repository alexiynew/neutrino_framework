#include <iostream>
#include <iomanip>

#include <unittest/test.h>

#pragma mark - tests to be tested

class ShouldFailTest : public test::Suite
{
public:
    ShouldFailTest()
    {
        ADD_TEST(ShouldFailTest::testAssert);
        ADD_TEST(ShouldFailTest::testFail);
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
    {
        ADD_TEST(ShouldPassTest::testAssert);
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
    {
        ADD_TEST(TestForTest::shouldFail);
        ADD_TEST(TestForTest::shouldPass);
    }

private:
    void shouldFail()
    {
        ShouldFailTest should_fail;

        runSuite(should_fail);

        TEST_ASSERT(!should_fail.isSuccessed(), "This test should fail.");
    }

    void shouldPass()
    {
        ShouldPassTest should_pass;

        runSuite(should_pass);

        TEST_ASSERT(should_pass.isSuccessed(), "This test should pass.");
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
    TestForTest test;
    test.run();
    return test.isSuccessed() ? 0 : 1;
}
