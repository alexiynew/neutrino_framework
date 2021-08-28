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

#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::math::Vector2f;
using framework::math::Vector3f;
using framework::math::Vector4f;

using framework::math::Vector2d;
using framework::math::Vector3d;
using framework::math::Vector4d;

using framework::math::Vector2i;
using framework::math::Vector3i;
using framework::math::Vector4i;

using framework::math::Vector2u;
using framework::math::Vector3u;
using framework::math::Vector4u;

using framework::math::Vector2b;
using framework::math::Vector3b;
using framework::math::Vector4b;

using framework::math::mix;

class CommonFunctionsTest : public framework::unit_test::Suite
{
public:
    CommonFunctionsTest()
        : Suite("CommonFunctionsTest")
    {
        add_test([this]() { abs_function(); }, "abs_function");
        add_test([this]() { sign_function(); }, "sign_function");
        add_test([this]() { floor_function(); }, "floor_function");
        add_test([this]() { round_function(); }, "round_function");
        add_test([this]() { ceil_function(); }, "ceil_function");
        add_test([this]() { trunc_function(); }, "trunc_function");
        add_test([this]() { fract_function(); }, "fract_function");
        add_test([this]() { mod_function(); }, "mod_function");
        add_test([this]() { modf_function(); }, "modf_function");
        add_test([this]() { min_function(); }, "min_function");
        add_test([this]() { max_function(); }, "max_function");
        add_test([this]() { clamp_function(); }, "clamp_function");
        add_test([this]() { mix_function(); }, "mix_function");
        add_test([this]() { step_function(); }, "step_function");
        add_test([this]() { smooth_step_function(); }, "smooth_step_function");
        add_test([this]() { isnan_function(); }, "isnan_function");
        add_test([this]() { isinf_function(); }, "isinf_function");
        add_test([this]() { fma_function(); }, "fma_function");
        add_test([this]() { frexp_function(); }, "frexp_function");
        add_test([this]() { ldexp_function(); }, "ldexp_function");

        v4d = {1.1, -1.5, 0.0, -1.8};
        v3f = {1.6f, -1.5f, 0.0f};
        v3i = {1, -5, 0};
        v2u = {10, 0};
    }

private:
    void abs_function()
    {
        TEST_ASSERT(abs(v4d) == Vector4d(1.1, 1.5, 0.0, 1.8), "Abs function failed.");
        TEST_ASSERT(abs(v3f) == Vector3f(1.6f, 1.5f, 0.0f), "Abs function failed.");
        TEST_ASSERT(abs(v3i) == Vector3i(1, 5, 0), "Abs function failed.");
        TEST_ASSERT(abs(v2u) == Vector2u(10, 0), "Abs function failed.");
        TEST_ASSERT(abs(Vector2b(true, false)) == Vector2b(true, false), "Abs function failed.");
    }

    void sign_function()
    {
        TEST_ASSERT(sign(v4d) == Vector4d(1.0, -1.0, 0.0, -1.0), "Sign function failed.");
        TEST_ASSERT(sign(v3f) == Vector3f(1.0f, -1.0f, 0.0f), "Sign function failed.");
        TEST_ASSERT(sign(v3i) == Vector3i(1, -1, 0), "Sign function failed.");
        TEST_ASSERT(sign(v2u) == Vector2u(1, 0), "Sign function failed.");
    }

    void floor_function()
    {
        TEST_ASSERT(floor(v4d) == Vector4d(1.0, -2.0, 0.0, -2.0), "Floor function failed.");
        TEST_ASSERT(floor(v3f) == Vector3f(1.0f, -2.0f, 0.0f), "Floor function failed.");
        TEST_ASSERT(floor(v3i) == Vector3d(1, -5, 0), "Floor function failed.");
        TEST_ASSERT(floor(v2u) == Vector2d(10, 0), "Floor function failed.");
    }

    void round_function()
    {
        TEST_ASSERT(round(v4d) == Vector4d(1.0, -2.0, 0.0, -2.0), "Round function failed.");
        TEST_ASSERT(round(v3f) == Vector3f(2.0f, -2.0f, 0.0f), "Round function failed.");
        TEST_ASSERT(round(v3i) == Vector3d(1, -5, 0), "Round function failed.");
        TEST_ASSERT(round(v2u) == Vector2d(10, 0), "Round function failed.");
    }

    void ceil_function()
    {
        TEST_ASSERT(ceil(v4d) == Vector4d(2.0, -1.0, 0.0, -1.0), "Ceil function failed.");
        TEST_ASSERT(ceil(v3f) == Vector3f(2.0f, -1.0f, 0.0f), "Ceil function failed.");
        TEST_ASSERT(ceil(v3i) == Vector3d(1, -5, 0), "Ceil function failed.");
        TEST_ASSERT(ceil(v2u) == Vector2d(10, 0), "Ceil function failed.");
    }

    void trunc_function()
    {
        TEST_ASSERT(trunc(v4d) == Vector4d(1.0, -1.0, 0.0, -1.0), "Truncate function failed.");
        TEST_ASSERT(trunc(v3f) == Vector3f(1.0f, -1.0f, 0.0f), "Truncate function failed.");
        TEST_ASSERT(trunc(v3i) == Vector3d(1, -5, 0), "Truncate function failed.");
        TEST_ASSERT(trunc(v2u) == Vector2d(10, 0), "Truncate function failed.");
    }

    void fract_function()
    {
        const Vector4d v4d_fract = {0.10000000000000008882, 0.5, 0, 0.19999999999999995559};

        TEST_ASSERT(almost_equal(fract(v4d), v4d_fract), "Fract function failed.");
        TEST_ASSERT(fract(v3f) == Vector3f(0.6f, 0.5f, 0.0f), "Fract function failed.");
        TEST_ASSERT(fract(v3i) == Vector3d(0, 0, 0), "Fract function failed.");
        TEST_ASSERT(fract(v2u) == Vector2d(0, 0), "Fract function failed.");
    }

    void mod_function()
    {
        TEST_ASSERT(mod(v4d, 3.0) == Vector4d(1.1, 1.5, 0.0, 1.2), "Mod function failed.");
        TEST_ASSERT(mod(v4d, Vector4d(1.2, -2.0, 0.5, 5.8)) == Vector4d(1.1, -1.5, 0.0, 4.0), "Mod function failed.");
        TEST_ASSERT(mod(v3i, 3) == Vector3d(1.0, 1.0, 0.0), "Mod function failed.");
        TEST_ASSERT(mod(v2u, Vector2u(4, 5)) == Vector2d(2, 0), "Mod function failed.");
    }

    void modf_function()
    {
        Vector4d v4d_integer;
        Vector4d v4d_fractional = modf(v4d, v4d_integer);

        Vector3f v3f_integer;
        Vector3f v3f_fractional = modf(v3f, v3f_integer);

        TEST_ASSERT(almost_equal(v4d_fractional, Vector4d(0.1, -0.5, 0.0, -0.8), 2), "Modf function failed.");
        TEST_ASSERT(v4d_integer == Vector4d(1, -1, 0, -1), "Modf function failed.");

        TEST_ASSERT(v3f_fractional == Vector3f(0.60000002384185791, -0.5, 0), "Modf function failed.");
        TEST_ASSERT(v3f_integer == Vector3f(1, -1, 0), "Modf function failed.");
    }

    void min_function()
    {
        const Vector4d other(1.0, -0.5, 0.00001, -1.8);

        TEST_ASSERT(min(v4d, other) == Vector4d(1.0, -1.5, 0.0, -1.8), "Min function failed.");
        TEST_ASSERT(min(v3f, 1.0f) == Vector3f(1.0f, -1.5f, 0.0f), "Min function failed.");
        TEST_ASSERT(min(v3i, Vector3i(2, 5, 0)) == Vector3i(1, -5, 0), "Min function failed.");
    }

    void max_function()
    {
        const Vector4d other(1.0, -0.5, 0.00001, -1.8);

        TEST_ASSERT(max(v4d, other) == Vector4d(1.1, -0.5, 0.00001, -1.8), "Max function failed.");
        TEST_ASSERT(max(v3f, 1.0f) == Vector3f(1.6f, 1.0f, 1.0f), "Max function failed.");
        TEST_ASSERT(max(v3i, Vector3i(2, 5, 0)) == Vector3i(2, 5, 0), "Max function failed.");
    }

    void clamp_function()
    {
        Vector4d min = {1.1, -1.1, 2.5, -2};
        Vector4d max = {1.1, -0.5, 2.6, -1.9};

        TEST_ASSERT(clamp(v4d, min, max) == Vector4d(1.1, -1.1, 2.5, -1.9), "Clamp function failed.");
        TEST_ASSERT(clamp(v3i, -1, 0) == Vector3i(0, -1, 0), "Clamp function failed.");
    }

    void mix_function()
    {
        const Vector4d result1 = mix(Vector4d(0.0), Vector4d(10.0), 0.5);
        const Vector4d result2 = mix(Vector4d(0.0), Vector4d(10.0), false);
        const Vector4d result3 = mix(Vector4d(1.0), Vector4d(10.0), true);
        const Vector4d result4 = mix(Vector4d(1.0), Vector4d(10.0), Vector4d(0.25, 0.5, -3, 3));
        const Vector3d result5 = mix(Vector3d(1.0), Vector3d(10.0), Vector3b(true, false, true));
        const Vector2i result6 = mix(Vector2i(1), Vector2i(10), Vector2i(1, 0));

        TEST_ASSERT(mix(0, 10, 0.7) == 7, "Mix function failed.");
        TEST_ASSERT(mix(0, 10, true) == 10, "Mix function failed.");
        TEST_ASSERT(mix(0, 10, false) == 0, "Mix function failed.");

        TEST_ASSERT(result1 == Vector4d(5.0), "Mix function failed.");
        TEST_ASSERT(result2 == Vector4d(0.0), "Mix function failed.");
        TEST_ASSERT(result3 == Vector4d(10.0), "Mix function failed.");

        TEST_ASSERT(result4 == Vector4d(3.25, 5.5, -26, 28), "Mix function failed.");
        TEST_ASSERT(result5 == Vector3d(10.0, 1.0, 10.0), "Mix function failed.");
        TEST_ASSERT(result6 == Vector2i(10, 1), "Mix function failed.");
    }

    void step_function()
    {
        TEST_ASSERT(step(Vector3f(1.1f, 1.2f, 1.3f), 1.2f) == Vector3f(0.0f, 1.0f, 1.0f), "Step function failed.");
        TEST_ASSERT(step(Vector3i(1, 2, 3), Vector3i(3, 2, 1)) == Vector3i(0, 1, 1), "Step function failed.");
    }

    void smooth_step_function()
    {
        const Vector3f result1 = smooth_step(Vector3f(1.0f, 5.0f, 10.0f), 4.0f, 6.0f);
        const Vector3f result2 = smooth_step(Vector3f(5), Vector3f(1, 6, 1), Vector3f(6, 7, 4));

        TEST_ASSERT(result1 == Vector3f(0.0f, 0.5f, 1), "Smooth_step function failed.");
        TEST_ASSERT(result2 == Vector3f(0.89600002765655518, 0, 1), "Smooth_step function failed.");
    }

    void isnan_function()
    {
        TEST_ASSERT(isnan(Vector2f(1.0f, NAN)) == Vector2b(false, true), "Isnan function failed.");
    }

    void isinf_function()
    {
        TEST_ASSERT(isinf(Vector2f(1.0f, INFINITY)) == Vector2b(false, true), "Isinf function failed.");
    }

    void fma_function()
    {
        TEST_ASSERT(fma(Vector2f(1.2f), Vector2f(1.3f), Vector2f(1.4f)) == Vector2f(2.96f), "Fma function failed.");
    }

    void frexp_function()
    {
        Vector4i v4i_exponent;
        const Vector4d v4d_fraction = frexp(v4d, &v4i_exponent);

        Vector3i v3i_exponent;
        const Vector3f v3f_fraction = frexp(v3f, &v3i_exponent);

        Vector2i v2i_exponent;
        const Vector2d v2d_fraction = frexp(v2u, &v2i_exponent);

        TEST_ASSERT(v4d_fraction == Vector4d(0.55, -0.75, 0, -0.9), "Frexp function failed.");
        TEST_ASSERT(v4i_exponent == Vector4i(1, 1, 0, 1), "Frexp function failed.");

        TEST_ASSERT(v3f_fraction == Vector3f(0.80000001192092896, -0.75, 0), "Frexp function failed.");
        TEST_ASSERT(v3i_exponent == Vector3i(1, 1, 0), "Frexp function failed.");

        TEST_ASSERT(v2d_fraction == Vector2d(0.625, 0), "Frexp function failed.");
        TEST_ASSERT(v2i_exponent == Vector2i(4, 0), "Frexp function failed.");
    }

    void ldexp_function()
    {
        Vector4i v4i_exponent;
        Vector3i v3i_exponent;
        Vector2i v2i_exponent;

        TEST_ASSERT(ldexp(frexp(v4d, &v4i_exponent), v4i_exponent) == v4d, "Ldexp function failed.");
        TEST_ASSERT(ldexp(frexp(v3f, &v3i_exponent), v3i_exponent) == v3f, "Ldexp function failed.");
        TEST_ASSERT(ldexp(frexp(v2u, &v2i_exponent), v2i_exponent) == Vector2d(v2u), "Ldexp function failed.");
    }

    Vector4d v4d;
    Vector3f v3f;
    Vector3i v3i;
    Vector2u v2u;
};

int main()
{
    return run_tests(CommonFunctionsTest());
}
