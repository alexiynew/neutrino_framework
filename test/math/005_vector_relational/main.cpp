#include <math/math.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;

// TODO add test for float and double

class relational_function_tests : public framework::unit_test::suite
{
public:
    relational_function_tests()
        : suite("relational_function_tests")
    {
        add_test([this]() { less_function(); }, "less_function");
        add_test([this]() { less_equal_function(); }, "less_equal_function");
        add_test([this]() { greater_function(); }, "greater_function");
        add_test([this]() { greater_equal_function(); }, "greater_equal_function");
        add_test([this]() { equal_function(); }, "equal_function");
        add_test([this]() { not_equal_function(); }, "not_equal_function");
        add_test([this]() { logical_not_function(); }, "logical_not_function");
        add_test([this]() { logical_and_function(); }, "logical_and_function");
        add_test([this]() { logical_or_function(); }, "logical_or_function");
        add_test([this]() { all_function(); }, "all_function");
        add_test([this]() { any_function(); }, "any_function");

        v2i1 = {1, 5};
        v2i2 = {2, 5};
    }

private:
    void less_function()
    {
        TEST_ASSERT(less(v2i1, v2i2) == vector2B(true, false), "Less function failed.");
        TEST_ASSERT(less(v2i2, v2i1) == vector2B(false, false), "Less function failed.");
    }

    void less_equal_function()
    {
        TEST_ASSERT(less_equal(v2i1, v2i2) == vector2B(true, true), "Less_equal function failed.");
        TEST_ASSERT(less_equal(v2i2, v2i1) == vector2B(false, true), "Less_equal function failed.");
    }

    void greater_function()
    {
        TEST_ASSERT(greater(v2i1, v2i2) == vector2B(false, false), "Greater function failed.");
        TEST_ASSERT(greater(v2i2, v2i1) == vector2B(true, false), "Greater function failed.");
    }

    void greater_equal_function()
    {
        TEST_ASSERT(greater_equal(v2i1, v2i2) == vector2B(false, true), "Greater_equal function failed.");
        TEST_ASSERT(greater_equal(v2i2, v2i1) == vector2B(true, true), "Greater_equal function failed.");
    }

    void equal_function()
    {
        TEST_ASSERT(equal(v2i1, v2i2) == vector2B(false, true), "Equal function failed.");
    }

    void not_equal_function()
    {
        TEST_ASSERT(not_equal(v2i2, v2i1) == vector2B(true, false), "Not_equal function failed.");
    }

    void logical_not_function()
    {
        TEST_ASSERT(logical_not(vector2B(false, true)) == vector2B(true, false), "Logical_not function failed.");
    }

    void logical_and_function()
    {
        const vector2B result = logical_and(vector2B(true, true), vector2B(true, false));
        TEST_ASSERT(result == vector2B(true, false), "Logical_and function failed.");
    }

    void logical_or_function()
    {
        const vector2B result = logical_or(vector2B(true, true), vector2B(true, false));
        TEST_ASSERT(result == vector2B(true, true), "Logical_or function failed.");
    }

    void all_function()
    {
        TEST_ASSERT(all(vector2B(true, true)), "All function failed.");
        TEST_ASSERT(all(vector2B(true, false)) == false, "All function failed.");
    }

    void any_function()
    {
        TEST_ASSERT(any(vector2B(true, false)), "Any function failed.");
        TEST_ASSERT(any(vector2B(false, false)) == false, "Any function failed.");
    }

    vector2I v2i1;
    vector2I v2i2;
};

int main()
{
    return run_tests(relational_function_tests());
}
