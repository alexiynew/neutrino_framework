#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class exponential_function_tests : public test::suite
{
public:
    exponential_function_tests()
        : suite("exponential_function_tests")
    {
        add_test([this]() { pow_function(); }, "pow_function");
        add_test([this]() { exp_function(); }, "exp_function");
        add_test([this]() { log_function(); }, "log_function");
        add_test([this]() { exp2_function(); }, "exp2_function");
        add_test([this]() { log2_function(); }, "log2_function");
        add_test([this]() { sqrt_function(); }, "sqrt_function");
        add_test([this]() { invsqrt_function(); }, "invsqrt_function");

        v4d = {1.1, -1.5, 0.0, -1.8};
    }

private:
    void pow_function()
    {
        const Vector4D result = {1.2100000000000002, 2.25, 0, 3.2400000000000002};
        TEST_ASSERT(pow(v4d, Vector4D(2)) == result, "Pow function failed.");
    }

    void exp_function()
    {
        const Vector4D result = {3.0041660239464334, 0.22313016014842982, 1, 0.16529888822158653};
        TEST_ASSERT(exp(v4d) == result, "Exp function failed.");
    }

    void log_function()
    {
        TEST_ASSERT(log(exp(v4d)) == v4d, "Log function failed.");
    }

    void exp2_function()
    {
        const Vector4D result = {2.1435469250725863, 0.35355339059327379, 1, 0.28717458874925872};
        TEST_ASSERT(exp2(v4d) == result, "Exp2 function failed.");
    }

    void log2_function()
    {
        const Vector4D result = {1.0999999999999999, -1.5, 0, -1.8000000000000003};
        TEST_ASSERT(log2(exp2(v4d)) == result, "Log2 function failed.");
    }

    void sqrt_function()
    {
        const Vector4D result = {3, 10, 1.4142135623730951, 1.772004514666935};
        TEST_ASSERT(sqrt(Vector4D(9.0, 100.0, 2.0, 3.14)) == result, "Sqrt function failed.");
    }

    void invsqrt_function()
    {
        const Vector4D result = {0.33333333333333331, 0.10000000000000001, 0.70710678118654746, 0.56433264798310034};
        TEST_ASSERT(invsqrt(Vector4D(9.0, 100.0, 2.0, 3.14)) == result, "Invsqrt function failed.");
    }

    Vector4D v4d;
};

int main()
{
    return run_tests(exponential_function_tests());
}
