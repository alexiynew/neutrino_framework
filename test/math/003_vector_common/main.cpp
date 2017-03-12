#include <math/math.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;

class common_function_tests : public framework::unit_test::suite
{
public:
    common_function_tests()
        : suite("common_function_tests")
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
        add_test([this]() { almost_equal_function(); }, "almost_equal_function");
        add_test([this]() { almost_equal_matrix_function(); }, "almost_equal_matrix_function");

        v4d = {1.1, -1.5, 0.0, -1.8};
        v3f = {1.6f, -1.5f, 0.0f};
        v3i = {1, -5, 0};
        v2u = {10, 0};
    }

private:
    void abs_function()
    {
        TEST_ASSERT(abs(v4d) == vector4D(1.1, 1.5, 0.0, 1.8), "Abs function failed.");
        TEST_ASSERT(abs(v3f) == vector3F(1.6f, 1.5f, 0.0f), "Abs function failed.");
        TEST_ASSERT(abs(v3i) == vector3I(1, 5, 0), "Abs function failed.");
        TEST_ASSERT(abs(v2u) == vector2U(10, 0), "Abs function failed.");
        TEST_ASSERT(abs(vector2B(true, false)) == vector2B(true, false), "Abs function failed.");
    }

    void sign_function()
    {
        TEST_ASSERT(sign(v4d) == vector4D(1.0, -1.0, 0.0, -1.0), "Sign function failed.");
        TEST_ASSERT(sign(v3f) == vector3F(1.0f, -1.0f, 0.0f), "Sign function failed.");
        TEST_ASSERT(sign(v3i) == vector3I(1, -1, 0), "Sign function failed.");
        TEST_ASSERT(sign(v2u) == vector2U(1, 0), "Sign function failed.");
    }

    void floor_function()
    {
        TEST_ASSERT(floor(v4d) == vector4D(1.0, -2.0, 0.0, -2.0), "Floor function failed.");
        TEST_ASSERT(floor(v3f) == vector3F(1.0f, -2.0f, 0.0f), "Floor function failed.");
        TEST_ASSERT(floor(v3i) == vector3I(1, -5, 0), "Floor function failed.");
        TEST_ASSERT(floor(v2u) == vector2U(10, 0), "Floor function failed.");
    }

    void round_function()
    {
        TEST_ASSERT(round(v4d) == vector4D(1.0, -2.0, 0.0, -2.0), "Round function failed.");
        TEST_ASSERT(round(v3f) == vector3F(2.0f, -2.0f, 0.0f), "Round function failed.");
        TEST_ASSERT(round(v3i) == vector3I(1, -5, 0), "Round function failed.");
        TEST_ASSERT(round(v2u) == vector2U(10, 0), "Round function failed.");
    }

    void ceil_function()
    {
        TEST_ASSERT(ceil(v4d) == vector4D(2.0, -1.0, 0.0, -1.0), "Ceil function failed.");
        TEST_ASSERT(ceil(v3f) == vector3F(2.0f, -1.0f, 0.0f), "Ceil function failed.");
        TEST_ASSERT(ceil(v3i) == vector3I(1, -5, 0), "Ceil function failed.");
        TEST_ASSERT(ceil(v2u) == vector2U(10, 0), "Ceil function failed.");
    }

    void trunc_function()
    {
        TEST_ASSERT(trunc(v4d) == vector4D(1.0, -1.0, 0.0, -1.0), "Truncate function failed.");
        TEST_ASSERT(trunc(v3f) == vector3F(1.0f, -1.0f, 0.0f), "Truncate function failed.");
        TEST_ASSERT(trunc(v3i) == vector3I(1, -5, 0), "Truncate function failed.");
        TEST_ASSERT(trunc(v2u) == vector2U(10, 0), "Truncate function failed.");
    }

    void fract_function()
    {
        const vector4D v4d_fract = {0.10000000000000008882, 0.5, 0, 0.19999999999999995559};

        TEST_ASSERT(almost_equal(fract(v4d), v4d_fract), "Fract function failed.");
        TEST_ASSERT(fract(v3f) == vector3F(0.6f, 0.5f, 0.0f), "Fract function failed.");
        TEST_ASSERT(fract(v3i) == vector3I(0, 0, 0), "Fract function failed.");
        TEST_ASSERT(fract(v2u) == vector2U(0, 0), "Fract function failed.");
    }

    void mod_function()
    {
        TEST_ASSERT(mod(v4d, 3.0) == vector4D(1.1, 1.5, 0.0, 1.2), "Mod function failed.");
        TEST_ASSERT(mod(v4d, vector4D(1.2, -2.0, 0.5, 5.8)) == vector4D(1.1, -1.5, 0.0, 4.0), "Mod function failed.");
    }

    void modf_function()
    {
        vector4D v4d_integer;
        vector4D v4d_fractional = modf(v4d, v4d_integer);

        vector3F v3f_integer;
        vector3F v3f_fractional = modf(v3f, v3f_integer);

        TEST_ASSERT(almost_equal(v4d_fractional, vector4D(0.1, -0.5, 0.0, -0.8), 2), "Modf function failed.");
        TEST_ASSERT(v4d_integer == vector4D(1, -1, 0, -1), "Modf function failed.");

        TEST_ASSERT(v3f_fractional == vector3F(0.60000002384185791, -0.5, 0), "Modf function failed.");
        TEST_ASSERT(v3f_integer == vector3F(1, -1, 0), "Modf function failed.");
    }

    void min_function()
    {
        const vector4D other(1.0, -0.5, 0.00001, -1.8);

        TEST_ASSERT(min(v4d, other) == vector4D(1.0, -1.5, 0.0, -1.8), "Min function failed.");
        TEST_ASSERT(min(v3f, 1.0f) == vector3F(1.0f, -1.5f, 0.0f), "Min function failed.");
        TEST_ASSERT(min(v3i, vector3I(2, 5, 0)) == vector3I(1, -5, 0), "Min function failed.");
    }

    void max_function()
    {
        const vector4D other(1.0, -0.5, 0.00001, -1.8);

        TEST_ASSERT(max(v4d, other) == vector4D(1.1, -0.5, 0.00001, -1.8), "Max function failed.");
        TEST_ASSERT(max(v3f, 1.0f) == vector3F(1.6f, 1.0f, 1.0f), "Max function failed.");
        TEST_ASSERT(max(v3i, vector3I(2, 5, 0)) == vector3I(2, 5, 0), "Max function failed.");
    }

    void clamp_function()
    {
        vector4D min = {1.1, -1.1, 2.5, -2};
        vector4D max = {1.1, -0.5, 2.6, -1.9};

        TEST_ASSERT(clamp(v4d, min, max) == vector4D(1.1, -1.1, 2.5, -1.9), "Clamp function failed.");
        TEST_ASSERT(clamp(v3i, -1, 0) == vector3I(0, -1, 0), "Clamp function failed.");
    }

    void mix_function()
    {
        const vector4D result1 = mix(vector4D(1.0), vector4D(10.0), 0.5);
        const vector4D result2 = mix(vector4D(1.0), vector4D(10.0), false);
        const vector4D result3 = mix(vector4D(1.0), vector4D(10.0), true);
        const vector4D result4 = mix(vector4D(1.0), vector4D(10.0), vector4D(0.25, 0.5, -3, 3));
        const vector3D result5 = mix(vector3D(1.0), vector3D(10.0), vector3B(true, false, true));
        const vector2I result6 = mix(vector2I(1), vector2I(10), vector2I(1, 0));

        TEST_ASSERT(result1 == vector4D(5.5), "Mix function failed.");
        TEST_ASSERT(result2 == vector4D(1.0), "Mix function failed.");
        TEST_ASSERT(result3 == vector4D(10.0), "Mix function failed.");
        TEST_ASSERT(result4 == vector4D(3.25, 5.5, -26, 28), "Mix function failed.");
        TEST_ASSERT(result5 == vector3D(10.0, 1.0, 10.0), "Mix function failed.");
        TEST_ASSERT(result6 == vector2I(10, 1), "Mix function failed.");
    }

    void step_function()
    {
        TEST_ASSERT(step(vector3F(1.1f, 1.2f, 1.3f), 1.2f) == vector3F(0.0f, 1.0f, 1.0f), "Step function failed.");
        TEST_ASSERT(step(vector3I(1, 2, 3), vector3I(3, 2, 1)) == vector3I(0, 1, 1), "Step function failed.");
    }

    void smooth_step_function()
    {
        const vector3F result1 = smooth_step(vector3F(1.0f, 5.0f, 10.0f), 4.0f, 6.0f);
        const vector3F result2 = smooth_step(vector3F(5), vector3F(1, 6, 1), vector3F(6, 7, 4));

        TEST_ASSERT(result1 == vector3F(0.0f, 0.5f, 1), "Smooth_step function failed.");
        TEST_ASSERT(result2 == vector3F(0.89600002765655518, 0, 1), "Smooth_step function failed.");
    }

    void isnan_function()
    {
        TEST_ASSERT(isnan(vector2F(1.0f, NAN)) == vector2B(false, true), "Isnan function failed.");
    }

    void isinf_function()
    {
        TEST_ASSERT(isinf(vector2F(1.0f, INFINITY)) == vector2B(false, true), "Isinf function failed.");
    }

    void fma_function()
    {
        TEST_ASSERT(fma(vector2F(1.2f), vector2F(1.3f), vector2F(1.4f)) == vector2F(2.96f), "Fma function failed.");
    }

    void frexp_function()
    {
        vector4I v4i_exponent;
        const vector4D v4d_significand = frexp(v4d, v4i_exponent);

        vector3I v3i_exponent;
        const vector3F v3f_significand = frexp(v3f, v3i_exponent);

        vector2I v2i_exponent;
        const vector2D v2d_significand = frexp(v2u, v2i_exponent);

        TEST_ASSERT(v4d_significand == vector4D(0.55, -0.75, 0, -0.9), "Frexp function failed.");
        TEST_ASSERT(v4i_exponent == vector4I(1, 1, 0, 1), "Frexp function failed.");

        TEST_ASSERT(v3f_significand == vector3F(0.80000001192092896, -0.75, 0), "Frexp function failed.");
        TEST_ASSERT(v3i_exponent == vector3I(1, 1, 0), "Frexp function failed.");

        TEST_ASSERT(v2d_significand == vector2D(0.625, 0), "Frexp function failed.");
        TEST_ASSERT(v2i_exponent == vector2I(4, 0), "Frexp function failed.");
    }

    void ldexp_function()
    {
        vector4I v4i_exponent;
        vector3I v3i_exponent;
        vector2I v2i_exponent;

        TEST_ASSERT(ldexp(frexp(v4d, v4i_exponent), v4i_exponent) == v4d, "Ldexp function failed.");
        TEST_ASSERT(ldexp(frexp(v3f, v3i_exponent), v3i_exponent) == v3f, "Ldexp function failed.");
        TEST_ASSERT(ldexp(frexp(v2u, v2i_exponent), v2i_exponent) == vector2D(v2u), "Ldexp function failed.");
    }

    void almost_equal_function()
    {
        TEST_ASSERT(almost_equal(v4d, vector4D(1.1, -1.5, 0.0, -1.8)), "Almost_equal function failed.");
        TEST_ASSERT(almost_equal(v3f, vector3F(1.6f, -1.5f, 0.0f)), "Almost_equal function failed.");
        TEST_ASSERT(almost_equal(v3i, vector3I(1, -5, 0)), "Almost_equal function failed.");
        TEST_ASSERT(almost_equal(v2u, vector2U(10, 0)), "Almost_equal function failed.");
    }

    void almost_equal_matrix_function()
    {
        // clang-format off
        const Matrix4x4F m44f = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4x3F m43f = {
            1, 2, 3, 3,
            1, 2, 2, 3,
            1, 1, 2, 3
        };

        const Matrix4x2F m42f = {
            1, 2, 2, 1,
            1, 2, 2, 1
        };

        const Matrix3x4F m34f = {
            1, 2, 3,
            4, 4, 1,
            2, 3, 3,
            4, 1, 2
        };

        const Matrix3x3F m33f = {
            1, 2, 3,
            3, 1, 2,
            2, 3, 1
        };

        const Matrix3x2F m32f = {
            1, 2, 2,
            1, 1, 2};

        const Matrix2x4F m24f = {
            1, 2,
            3, 4,
            4, 1,
            2, 3
        };

        const Matrix2x3F m23f = {
            1, 2,
            3, 4,
            1, 2
        };

        const Matrix2x2F m22f = {
            1, 2,
            4, 1
        };

        TEST_ASSERT(almost_equal(m44f, Matrix4x4F{
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m43f, Matrix4x3F{
            1, 2, 3, 3,
            1, 2, 2, 3,
            1, 1, 2, 3
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m42f, Matrix4x2F{
            1, 2, 2, 1,
            1, 2, 2, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m34f, Matrix3x4F{
            1, 2, 3,
            4, 4, 1,
            2, 3, 3,
            4, 1, 2
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m33f, Matrix3x3F{
            1, 2, 3,
            3, 1, 2,
            2, 3, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m32f, Matrix3x2F{
            1, 2, 2,
            1, 1, 2
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m24f, Matrix2x4F{
            1, 2,
            3, 4,
            4, 1,
            2, 3
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m23f, Matrix2x3F{
            1, 2,
            3, 4,
            1, 2
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m22f, Matrix2x2F{
            1, 2,
            4, 1
        }), "Almost_equal function failed.");

        // clang-format on
    }

    vector4D v4d;
    vector3F v3f;
    vector3I v3i;
    vector2U v2u;
};

int main()
{
    return run_tests(common_function_tests());
}
