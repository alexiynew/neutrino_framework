#include <debug.h>
#include <math/fmath.h>

using namespace framework::math;

int main()
{
    // vector assign
    {
        vec4d v4d(1.1, 2.2, 3.3, 4);
        vec3f v3f(5.5f, 6.6f, 7.7f);
        vec2i v2i(1, 2.0);

        vec4d v4d2;
        vec3f v3f2;
        vec2i v2i2;

        vec4i v4i;
        vec3d v3d;
        vec2f v2f;

        v4d2 = v4d;
        v3f2 = v3f;
        v2i2 = v2i;

        v4i = v4d;
        v3d = v3f;
        v2f = v2i;

        assert_msg(v4i == vec4i(1, 2, 3, 4) && v4d2 == vec4d(1.1, 2.2, 3.3, 4), "assign failed");
        assert_msg(v3d == vec3d(static_cast<F64>(5.5f), static_cast<F64>(6.6f), static_cast<F64>(7.7f)) && v3f2 == vec3f(5.5f, 6.6f, 7.7f), "assign failed");
        assert_msg(v2f == vec2f(1, 2) && v2i2 == vec2i(1, 2.0), "assign failed");
    }

    // bool vector assing
    {
        vec4b v4b(true, false, true, false);
        vec3b v3b(true, false, true);
        vec2b v2b(true, false);

        vec4d v4d(-1.1, 0.0, 3.3, 0.0);
        vec3f v3f(5.5f, 0.0, -7.7f);
        vec2i v2i(1, 0);

        vec4b v4b2;
        vec3b v3b2;
        vec2b v2b2;

        v4b2 = v4b;
        v3b2 = v3b;
        v2b2 = v2b;

        vec4b v4b3;
        vec3b v3b3;
        vec2b v2b3;

        v4b3 = v4d;
        v3b3 = v3f;
        v2b3 = v2i;

        assert_msg(v4b == v4b2 && v4b == v4b3, "assign failed");
        assert_msg(v3b == v3b2 && v3b == v3b3, "assign failed");
        assert_msg(v2b == v2b2 && v2b == v2b3, "assign failed");
    }

    // vector access
    {
        vec4d v4d(1.1, 2.2, 3.3, 4.4);
        vec3f v3f(5.5f, 6.6f, 7.7f);
        vec2i v2i(1, 2);

        vec4b v4b(true, false, true, false);
        vec3b v3b(true, false, true);
        vec2b v2b(true, false);

        assert_msg(almost_equal(v4d[0], 1.1) && almost_equal(v4d[1], 2.2) && almost_equal(v4d[2], 3.3) && almost_equal(v4d[3], 4.4), "access filed");
        assert_msg(almost_equal(v3f[0], 5.5f) && almost_equal(v3f[1], 6.6f) && almost_equal(v3f[2], 7.7f), "access "
                                                                                                           "failed");
        assert_msg(v2i[0] == 1 && v2i[1] == 2, "access failed");

        assert_msg(v4b[0] == true && v4b[1] == false && v4b[2] == true && v4b[3] == false, "access filed");
        assert_msg(v3b[0] == true && v3b[1] == false && v3b[2] == true, "access failed");
        assert_msg(v2b[0] == true && v2b[1] == false, "access failed");
    }

    // vector inverse vector and unary plus
    {
        vec4d v4d(1.4);
        vec3f v3f(2.4f);
        vec2i v2i(3);

        assert_msg(-v4d == vec4d(-1.4, -1.4, -1.4, -1.4), "inverse vector");
        assert_msg(-v3f == vec3f(-2.4f, -2.4f, -2.4f), "inverse vector");
        assert_msg(-v2i == vec2i(-3, -3), "inverse vector");

        assert_msg(+v4d == vec4d(1.4, 1.4, 1.4, 1.4), "unary plus vector");
        assert_msg(+v3f == vec3f(2.4f, 2.4f, 2.4f), "unary plus vector");
        assert_msg(+v2i == vec2i(3, 3), "unary plus vector");
    }

    // vector math-1
    {
        vec4d v4d1(1.0, 1.1, 1.2, 1.3);
        vec4d v4d2(2.0, 2.1, 2.2, 2.3);
        vec4d v4d3(3.0, 3.1, 3.2, 3.3);
        vec4d v4d4(4.0, 4.1, 4.2, 4.3);

        vec4d r = ((v4d1 + v4d2) * v4d3) / (v4d4 - v4d1);

        assert_msg(r == vec4d(3, 3.3066666666666675, 3.6266666666666674, 3.9599999999999995), "math-1 failed");
    }

    // vector math-2
    {
        vec3f v3f1(1.0f, 1.1f, 1.2f);
        vec3f v3f2(2.0f, 2.1f, 2.2f);
        vec3f v3f3(3.0f, 3.1f, 3.2f);
        vec3f v3f4(4.0f, 4.1f, 4.2f);

        vec3f r = ((v3f1 - v3f4) + (v3f2 * v3f3)) / v3f4;
        assert_msg(r == vec3f(0.75, 0.85609740018844604, 0.96190500259399414), "math-2 failed");
    }

    // vector math-3
    {
        vec2i v2i1(1, 5);
        vec2i v2i2(2, 6);
        vec2i v2i3(3, 7);
        vec2i v2i4(4, 8);

        vec2i r = (v2i3 * v2i4 - v2i1) / (v2i1 + v2i2);
        assert_msg(r == vec2i(3, 4), "math-3 failed");
    }

    // vector math-4,5,6
    {
        vec4d v4d(1.0, 1.1, 1.2, 1.3);
        vec3f v3f(1.0f, 1.1f, 1.2f);
        vec2i v2i(1, 5);

        vec4d v4d2 = 3.0 - ((2.0 / (v4d + 1.4)) * v4d);
        vec3f v3f2 = ((2.0f + v3f) * (4.3f / v3f)) - 1.0f;
        vec2i v2i2 = (((3 - v2i) * 9) + 1) / 2;

        assert_msg(v4d == vec4d(1.0, 1.1, 1.2, 1.3) && almost_equal(v4d2, vec4d(2.1666666666666665, 2.1200000000000001, 2.076923076923076, 2.037037037037037), 1), "math-4 failed");
        assert_msg(v3f == vec3f(1.0f, 1.1f, 1.2f) && v3f2 == vec3f(11.90000057220459, 11.118182182312012, 10.466666221618652), "math-5 failed");
        assert_msg(v2i == vec2i(1, 5) && v2i2 == vec2i(9, -8), "math-6 failed");
    }

    return 0;
}
