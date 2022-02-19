# Unit tests

[<sub> Main Page </sub>](https://github.com/alexiynew/neutrino_framework#neutrino-framework)

-------

The module provides simple functionality to test different features 
of the neutrino framework.

All tests must de derived form the `framework::unit_test::Suite` class.

``` cpp
class ExampleTest : public framework::unit_test::Suite
{
public:
    ExampleTest() : Suite("Example test name")
    {
        add_test([this]() { test_function(); }, "Test function name");
    }
private:
    void test_function()
    {
        bool condition = true;
        TEST_ASSERT(condition, "Test fail message.");
    }
};
```

The `Suite::add_test` function adds tests to current suite.

``` cpp
add_test([this]() { test_function(); }, "test_function_name");
```

The `Suite::test_failed` function marks test as failed.  
The `TEST_FAIL` and `TEST_ASSERT` macros can be used 
to get **file path** and **line number** for `Suite::test_failed`.

``` cpp
TEST_FAIL("Test fail message.");
TEST_ASSERT(condition, "Test fail message.");
```

Tests can be run with the `Suite::run`.

``` cpp
framework::unit_test::Suite* test = new ExampleTest();
test->run();
```

Or a group of tests can be run with the helper function `run_tests`.

``` cpp
run_tests(ExampleTest(), OtherExampleTest());
```
