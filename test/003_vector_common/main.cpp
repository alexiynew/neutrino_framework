#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // vector common functions
    {
        vec4d v4d(1.1, -1.5, 0.0, -1.8);
        vec3f v3f(1.6f, -1.5f, 0.0f);
        vec3i v3i(1, -5, 0);
        vec2u v2u(10, 0);

        assert_msg(abs(v4d) == vec4d(1.1, 1.5, 0.0, 1.8) && abs(v3f) == vec3f(1.6f, 1.5f, 0.0f) && abs(v3i) == vec3i(1, 5, 0) && abs(v2u) == vec2u(10, 0), "abs failed");

        assert_msg(sign(v4d) == vec4d(1.0, -1.0, 0.0, -1.0) && sign(v3f) == vec3f(1.0f, -1.0f, 0.0f) && sign(v3i) == vec3i(1, -1, 0) && sign(v2u) == vec2u(1, 0), "sign failed");

        assert_msg(floor(v4d) == vec4d(1.0, -2.0, 0.0, -2.0) && floor(v3f) == vec3f(1.0f, -2.0f, 0.0f) && floor(v3i) == vec3i(1, -5, 0) && floor(v2u) == vec2u(10, 0), "floor failed");

        assert_msg(trunc(v4d) == vec4d(1.0, -1.0, 0.0, -1.0) && trunc(v3f) == vec3f(1.0f, -1.0f, 0.0f) && trunc(v3i) == vec3i(1, -5, 0) && trunc(v2u) == vec2u(10, 0), "trunc failed");

        assert_msg(round(v4d) == vec4d(1.0, -2.0, 0.0, -2.0) && round(v3f) == vec3f(2.0f, -2.0f, 0.0f) && round(v3i) == vec3i(1, -5, 0) && round(v2u) == vec2u(10, 0), "round failed");

        assert_msg(ceil(v4d) == vec4d(2.0, -1.0, 0.0, -1.0) && ceil(v3f) == vec3f(2.0f, -1.0f, 0.0f) && ceil(v3i) == vec3i(1, -5, 0) && ceil(v2u) == vec2u(10, 0), "ceil failed");

        assert_msg(fract(vec3f(1.5f, -1.23f, 0.0f)) == vec3f(0.5f, 0.77f, 0.0f), "fract failed");

        assert_msg(mod(v4d, 3.0) == vec4d(1.1, 1.5, 0.0, 1.2) && mod(v4d, vec4d(1.2, -2.0, 0.5, 5.8)) == vec4d(1.1, -1.5, 0.0, 4.0), "mod failed");

        vec4d v4d_tmp;
        vec3f v3f_tmp;

        assert_msg(modf(v4d, v4d_tmp) == vec4d(0.10000000000000009, -0.5, 0.0, -0.80000000000000004) && v4d_tmp == vec4d(1, -1, 0, -1) && modf(v3f, v3f_tmp) == vec3f(0.60000002384185791, -0.5, 0) && v3f_tmp == vec3f(1, -1, 0), "modf failed");

        assert_msg(min(v4d, vec4d(1.0, -0.5, 0.00001, -1.8)) == vec4d(1.0, -1.5, 0.0, -1.8) && min(v3f, 1.0f) == vec3f(1.0f, -1.5f, 0.0f) && min(v3i, vec3i(2, 5, 0)) == vec3i(1, -5, 0), "min failed");

        assert_msg(max(v4d, vec4d(1.0, -0.5, 0.00001, -1.8)) == vec4d(1.1, -0.5, 0.00001, -1.8) && max(v3f, 1.0f) == vec3f(1.6f, 1.0f, 1.0f) && max(v3i, vec3i(2, 5, 0)) == vec3i(2, 5, 0), "max failed");

        assert_msg(clamp(v4d, vec4d(1.1, -1.1, 2.5, -2), vec4d(1.1, -0.5, 2.6, -1.9)) == vec4d(1.1, -1.1, 2.5, -1.9) && clamp(v3i, -1, 0) == vec3i(0, -1, 0), "clamp failed");

        assert_msg(mix(vec4d(1.0), vec4d(10.0), 0.5) == vec4d(5.5) && mix(vec4d(1.0), vec4d(10.0), false) == vec4d(1.0) && mix(vec4d(1.0), vec4d(10.0), true) == vec4d(10.0) && mix(vec4d(1.0), vec4d(10.0), vec4d(0.25, 0.5, -3, 3)) == vec4d(3.25, 5.5, -26, 28) && mix(vec3d(1.0), vec3d(10.0), vec3b(true, false, true)) == vec3d(10.0, 1.0, 10.0) && mix(vec2i(1), vec2i(10), vec2i(1, 0)) == vec2i(10, 1), "mix failed");

        assert_msg(step(vec3f(1.1f, 1.2f, 1.3f), 1.2f) == vec3f(0.0f, 1.0f, 1.0f) && step(vec3i(1, 2, 3), vec3i(3, 2, 1)) == vec3i(0, 1, 1), "step failed");

        assert_msg(smoothstep(vec3f(1.0f, 5.0f, 10.0f), 4.0f, 6.0f) == vec3f(0.0f, 0.5f, 1) && smoothstep(vec3f(5), vec3f(1, 6, 1), vec3f(6, 7, 4)) == vec3f(0.89600002765655518, 0, 1), "smoothstep failed");

        assert_msg(isnan(vec2f(1.0f, NAN)) == vec2b(false, true), "isnan failed");

        assert_msg(isinf(vec2f(1.0f, INFINITY)) == vec2b(false, true), "isinf failed");

        assert_msg(fma(vec2f(1.2f), vec2f(1.3f), vec2f(1.4f)) == vec2f(2.96f), "fma failed");

        vec4i v4i_tmp;
        vec3i v3i_tmp;
        vec2i v2i_tmp;

        assert_msg(frexp(v4d, v4i_tmp) == vec4d(0.55000000000000004, -0.75, 0, -0.90000000000000002) && v4i_tmp == vec4i(1, 1, 0, 1) && frexp(v3f, v3i_tmp) == vec3f(0.80000001192092896, -0.75, 0) && v3i_tmp == vec3i(1, 1, 0) && frexp(v2u, v2i_tmp) == vec2d(0.625, 0) && v2i_tmp == vec2i(4, 0), "frexp failed");

        assert_msg(ldexp(frexp(v4d, v4i_tmp), v4i_tmp) == v4d && ldexp(frexp(v3f, v3i_tmp), v3i_tmp) == v3f && ldexp(frexp(v2u, v2i_tmp), v2i_tmp) == vec2d(v2u), "ldexp failed");

        assert_msg(almost_equal(v4d, vec4d(1.1, -1.5, 0.0, -1.8)), "almost_equal failed");
        assert_msg(almost_equal(v3f, vec3f(1.6f, -1.5f, 0.0f)), "almost_equal failed");

        vec2f v2f(0.00001f, 1.0f);
        assert_msg(almost_equal(v2f, vec2f(0.00001f, 0.99999999999999f)), "almost_equal failed");
    }

    return 0;
}
