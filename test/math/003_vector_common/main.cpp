#include <debug.hpp>

#include <math/math.hpp>

using namespace framework::math;

int main()
{

    // vector common functions
    {
        Vector4D v4d(1.1, -1.5, 0.0, -1.8);
        Vector3F v3f(1.6f, -1.5f, 0.0f);
        Vector3I v3i(1, -5, 0);
        Vector2U v2u(10, 0);

        ASSERT_MSG(abs(v4d) == Vector4D(1.1, 1.5, 0.0, 1.8) && abs(v3f) == Vector3F(1.6f, 1.5f, 0.0f) &&
                   abs(v3i) == Vector3I(1, 5, 0) && abs(v2u) == Vector2U(10, 0),
                   "abs failed");

        ASSERT_MSG(sign(v4d) == Vector4D(1.0, -1.0, 0.0, -1.0) && sign(v3f) == Vector3F(1.0f, -1.0f, 0.0f) &&
                   sign(v3i) == Vector3I(1, -1, 0) && sign(v2u) == Vector2U(1, 0),
                   "sign failed");

        ASSERT_MSG(floor(v4d) == Vector4D(1.0, -2.0, 0.0, -2.0) && floor(v3f) == Vector3F(1.0f, -2.0f, 0.0f) &&
                   floor(v3i) == Vector3I(1, -5, 0) && floor(v2u) == Vector2U(10, 0),
                   "floor failed");

        ASSERT_MSG(trunc(v4d) == Vector4D(1.0, -1.0, 0.0, -1.0) && trunc(v3f) == Vector3F(1.0f, -1.0f, 0.0f) &&
                   trunc(v3i) == Vector3I(1, -5, 0) && trunc(v2u) == Vector2U(10, 0),
                   "trunc failed");

        ASSERT_MSG(round(v4d) == Vector4D(1.0, -2.0, 0.0, -2.0) && round(v3f) == Vector3F(2.0f, -2.0f, 0.0f) &&
                   round(v3i) == Vector3I(1, -5, 0) && round(v2u) == Vector2U(10, 0),
                   "round failed");

        ASSERT_MSG(ceil(v4d) == Vector4D(2.0, -1.0, 0.0, -1.0) && ceil(v3f) == Vector3F(2.0f, -1.0f, 0.0f) &&
                   ceil(v3i) == Vector3I(1, -5, 0) && ceil(v2u) == Vector2U(10, 0),
                   "ceil failed");

        ASSERT_MSG(fract(Vector3F(1.5f, -1.23f, 0.0f)) == Vector3F(0.5f, 0.77f, 0.0f), "fract failed");

        ASSERT_MSG(mod(v4d, 3.0) == Vector4D(1.1, 1.5, 0.0, 1.2) &&
                   mod(v4d, Vector4D(1.2, -2.0, 0.5, 5.8)) == Vector4D(1.1, -1.5, 0.0, 4.0),
                   "mod failed");

        Vector4D v4d_tmp;
        Vector3F v3f_tmp;

        ASSERT_MSG(modf(v4d, v4d_tmp) == Vector4D(0.10000000000000009, -0.5, 0.0, -0.80000000000000004) &&
                   v4d_tmp == Vector4D(1, -1, 0, -1) && modf(v3f, v3f_tmp) == Vector3F(0.60000002384185791, -0.5, 0) &&
                   v3f_tmp == Vector3F(1, -1, 0),
                   "modf failed");

        ASSERT_MSG(min(v4d, Vector4D(1.0, -0.5, 0.00001, -1.8)) == Vector4D(1.0, -1.5, 0.0, -1.8) &&
                   min(v3f, 1.0f) == Vector3F(1.0f, -1.5f, 0.0f) && min(v3i, Vector3I(2, 5, 0)) == Vector3I(1, -5, 0),
                   "min failed");

        ASSERT_MSG(max(v4d, Vector4D(1.0, -0.5, 0.00001, -1.8)) == Vector4D(1.1, -0.5, 0.00001, -1.8) &&
                   max(v3f, 1.0f) == Vector3F(1.6f, 1.0f, 1.0f) && max(v3i, Vector3I(2, 5, 0)) == Vector3I(2, 5, 0),
                   "max failed");

        ASSERT_MSG(clamp(v4d, Vector4D(1.1, -1.1, 2.5, -2), Vector4D(1.1, -0.5, 2.6, -1.9)) == Vector4D(1.1, -1.1, 2.5, -1.9) &&
                   clamp(v3i, -1, 0) == Vector3I(0, -1, 0),
                   "clamp failed");

        ASSERT_MSG(mix(Vector4D(1.0), Vector4D(10.0), 0.5) == Vector4D(5.5) &&
                   mix(Vector4D(1.0), Vector4D(10.0), false) == Vector4D(1.0) &&
                   mix(Vector4D(1.0), Vector4D(10.0), true) == Vector4D(10.0) &&
                   mix(Vector4D(1.0), Vector4D(10.0), Vector4D(0.25, 0.5, -3, 3)) == Vector4D(3.25, 5.5, -26, 28) &&
                   mix(Vector3D(1.0), Vector3D(10.0), Vector3B(true, false, true)) == Vector3D(10.0, 1.0, 10.0) &&
                   mix(Vector2I(1), Vector2I(10), Vector2I(1, 0)) == Vector2I(10, 1),
                   "mix failed");

        ASSERT_MSG(step(Vector3F(1.1f, 1.2f, 1.3f), 1.2f) == Vector3F(0.0f, 1.0f, 1.0f) &&
                   step(Vector3I(1, 2, 3), Vector3I(3, 2, 1)) == Vector3I(0, 1, 1),
                   "step failed");

        ASSERT_MSG(smoothstep(Vector3F(1.0f, 5.0f, 10.0f), 4.0f, 6.0f) == Vector3F(0.0f, 0.5f, 1) &&
                   smoothstep(Vector3F(5), Vector3F(1, 6, 1), Vector3F(6, 7, 4)) == Vector3F(0.89600002765655518, 0, 1),
                   "smoothstep failed");

        ASSERT_MSG(isnan(Vector2F(1.0f, NAN)) == Vector2B(false, true), "isnan failed");

        ASSERT_MSG(isinf(Vector2F(1.0f, INFINITY)) == Vector2B(false, true), "isinf failed");

        ASSERT_MSG(fma(Vector2F(1.2f), Vector2F(1.3f), Vector2F(1.4f)) == Vector2F(2.96f), "fma failed");

        Vector4I v4i_tmp;
        Vector3I v3i_tmp;
        Vector2I v2i_tmp;

        ASSERT_MSG(frexp(v4d, v4i_tmp) == Vector4D(0.55000000000000004, -0.75, 0, -0.90000000000000002) &&
                   v4i_tmp == Vector4I(1, 1, 0, 1) && frexp(v3f, v3i_tmp) == Vector3F(0.80000001192092896, -0.75, 0) &&
                   v3i_tmp == Vector3I(1, 1, 0) && frexp(v2u, v2i_tmp) == Vector2D(0.625, 0) && v2i_tmp == Vector2I(4, 0),
                   "frexp failed");

        ASSERT_MSG(ldexp(frexp(v4d, v4i_tmp), v4i_tmp) == v4d && ldexp(frexp(v3f, v3i_tmp), v3i_tmp) == v3f &&
                   ldexp(frexp(v2u, v2i_tmp), v2i_tmp) == Vector2D(v2u),
                   "ldexp failed");

        ASSERT_MSG(almost_equal(v4d, Vector4D(1.1, -1.5, 0.0, -1.8)), "almost_equal failed");
        ASSERT_MSG(almost_equal(v3f, Vector3F(1.6f, -1.5f, 0.0f)), "almost_equal failed");

        Vector2F v2f(0.00001f, 1.0f);
        ASSERT_MSG(almost_equal(v2f, Vector2F(0.00001f, 0.99999999999999f)), "almost_equal failed");

        // TODO: add tests for matrix id:8
    }

    return 0;
}
