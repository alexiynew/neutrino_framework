
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::uint32;

using framework::math::Vector2f;
using framework::math::Vector3f;
using framework::math::Vector4f;

using framework::math::Vector2d;
using framework::math::Vector3d;
using framework::math::Vector4d;

using framework::math::almost_equal;

class exponential_function_tests : public framework::unit_test::Suite
{
public:
    exponential_function_tests()
        : Suite("exponential_function_tests")
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
        const Vector4d result = {1.2100000000000002, 2.25, 0, 3.2400000000000002};
        TEST_ASSERT(pow(v4d, Vector4d(2)) == result, "Pow function failed.");
    }

    void exp_function()
    {
        const Vector4d result = {3.0041660239464334, 0.22313016014842982, 1, 0.16529888822158653};
        TEST_ASSERT(exp(v4d) == result, "Exp function failed.");
    }

    void log_function()
    {
        TEST_ASSERT(log(exp(v4d)) == v4d, "Log function failed.");
    }

    void exp2_function()
    {
        const Vector4d result = {2.1435469250725863, 0.35355339059327379, 1, 0.28717458874925872};
        TEST_ASSERT(almost_equal(exp2(v4d), result, 4), "Exp2 function failed.");
    }

    void log2_function()
    {
        const Vector4d result = {1.0999999999999999, -1.5, 0, -1.8000000000000003};
        TEST_ASSERT(almost_equal(log2(exp2(v4d)), result, 4), "Log2 function failed.");
    }

    void sqrt_function()
    {
        const Vector4d result = {3, 10, 1.4142135623730951, 1.772004514666935};
        TEST_ASSERT(sqrt(Vector4d(9.0, 100.0, 2.0, 3.14)) == result, "Sqrt function failed.");
    }

    void invsqrt_function()
    {
        const Vector4d result = {0.33333333333333331, 0.10000000000000001, 0.70710678118654746, 0.56433264798310034};
        TEST_ASSERT(invsqrt(Vector4d(9.0, 100.0, 2.0, 3.14)) == result, "Invsqrt function failed.");
    }

    Vector4d v4d;
};

int main()
{
    return run_tests(exponential_function_tests());
}
