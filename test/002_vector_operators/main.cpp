#include <debug.h>
#include <math/fmath.h>

using namespace framework::math;

int main()
{
    // vector assign
    {
        Vector4D v4d(1.1, 2.2, 3.3, 4);
        Vector3F v3f(5.5f, 6.6f, 7.7f);
        Vector2I v2i(1, 2.0);

        Vector4D v4d2;
        Vector3F v3f2;
        Vector2I v2i2;

        Vector4I v4i;
        Vector3D v3d;
        Vector2F v2f;

        v4d2 = v4d;
        v3f2 = v3f;
        v2i2 = v2i;

        v4i = v4d;
        v3d = v3f;
        v2f = v2i;

        ASSERT_MSG(v4i == Vector4I(1, 2, 3, 4) && v4d2 == Vector4D(1.1, 2.2, 3.3, 4), "assign failed");
        ASSERT_MSG(v3d == Vector3D(static_cast<F64>(5.5f), static_cast<F64>(6.6f), static_cast<F64>(7.7f)) && v3f2 == Vector3F(5.5f, 6.6f, 7.7f), "assign failed");
        ASSERT_MSG(v2f == Vector2F(1, 2) && v2i2 == Vector2I(1, 2.0), "assign failed");
    }

    // bool vector assing
    {
        Vector4B v4b(true, false, true, false);
        Vector3B v3b(true, false, true);
        Vector2B v2b(true, false);

        Vector4D v4d(-1.1, 0.0, 3.3, 0.0);
        Vector3F v3f(5.5f, 0.0, -7.7f);
        Vector2I v2i(1, 0);

        Vector4B v4b2;
        Vector3B v3b2;
        Vector2B v2b2;

        v4b2 = v4b;
        v3b2 = v3b;
        v2b2 = v2b;

        Vector4B v4b3;
        Vector3B v3b3;
        Vector2B v2b3;

        v4b3 = v4d;
        v3b3 = v3f;
        v2b3 = v2i;

        ASSERT_MSG(v4b == v4b2 && v4b == v4b3, "assign failed");
        ASSERT_MSG(v3b == v3b2 && v3b == v3b3, "assign failed");
        ASSERT_MSG(v2b == v2b2 && v2b == v2b3, "assign failed");
    }

    // vector access
    {

        // TODO add data access test
        // double* p = v4d.data();
        // ASSERT_MSG(p[0] == 1.0 && p[1] == 2.0 && p[2] == 3.0 && p[3] == 4.0, "pointer data access");
        // TODO: add vector bool pointer access
        Vector4D v4d(1.1, 2.2, 3.3, 4.4);
        Vector3F v3f(5.5f, 6.6f, 7.7f);
        Vector2I v2i(1, 2);

        Vector4B v4b(true, false, true, false);
        Vector3B v3b(true, false, true);
        Vector2B v2b(true, false);

        ASSERT_MSG(almostEqual(v4d[0], 1.1) && almostEqual(v4d[1], 2.2) && almostEqual(v4d[2], 3.3) && almostEqual(v4d[3], 4.4), "access filed");
        ASSERT_MSG(almostEqual(v3f[0], 5.5f) && almostEqual(v3f[1], 6.6f) && almostEqual(v3f[2], 7.7f), "access failed");
        ASSERT_MSG(v2i[0] == 1 && v2i[1] == 2, "access failed");

        ASSERT_MSG(v4b[0] == true && v4b[1] == false && v4b[2] == true && v4b[3] == false, "access filed");
        ASSERT_MSG(v3b[0] == true && v3b[1] == false && v3b[2] == true, "access failed");
        ASSERT_MSG(v2b[0] == true && v2b[1] == false, "access failed");
    }

    // vector inverse vector and unary plus
    {
        Vector4D v4d(1.4);
        Vector3F v3f(2.4f);
        Vector2I v2i(3);

        ASSERT_MSG(-v4d == Vector4D(-1.4, -1.4, -1.4, -1.4), "inverse vector");
        ASSERT_MSG(-v3f == Vector3F(-2.4f, -2.4f, -2.4f), "inverse vector");
        ASSERT_MSG(-v2i == Vector2I(-3, -3), "inverse vector");

        ASSERT_MSG(+v4d == Vector4D(1.4, 1.4, 1.4, 1.4), "unary plus vector");
        ASSERT_MSG(+v3f == Vector3F(2.4f, 2.4f, 2.4f), "unary plus vector");
        ASSERT_MSG(+v2i == Vector2I(3, 3), "unary plus vector");
    }

    // vector math-1
    {
        Vector4D v4d1(1.0, 1.1, 1.2, 1.3);
        Vector4D v4d2(2.0, 2.1, 2.2, 2.3);
        Vector4D v4d3(3.0, 3.1, 3.2, 3.3);
        Vector4D v4d4(4.0, 4.1, 4.2, 4.3);

        Vector4D r = ((v4d1 + v4d2) * v4d3) / (v4d4 - v4d1);

        ASSERT_MSG(r == Vector4D(3, 3.3066666666666675, 3.6266666666666674, 3.9599999999999995), "math-1 failed");
    }

    // vector math-2
    {
        Vector3F v3f1(1.0f, 1.1f, 1.2f);
        Vector3F v3f2(2.0f, 2.1f, 2.2f);
        Vector3F v3f3(3.0f, 3.1f, 3.2f);
        Vector3F v3f4(4.0f, 4.1f, 4.2f);

        Vector3F r = ((v3f1 - v3f4) + (v3f2 * v3f3)) / v3f4;
        ASSERT_MSG(r == Vector3F(0.75, 0.85609740018844604, 0.96190500259399414), "math-2 failed");
    }

    // vector math-3
    {
        Vector2I v2i1(1, 5);
        Vector2I v2i2(2, 6);
        Vector2I v2i3(3, 7);
        Vector2I v2i4(4, 8);

        Vector2I r = (v2i3 * v2i4 - v2i1) / (v2i1 + v2i2);
        ASSERT_MSG(r == Vector2I(3, 4), "math-3 failed");
    }

    // vector math-4,5,6
    {
        Vector4D v4d(1.0, 1.1, 1.2, 1.3);
        Vector3F v3f(1.0f, 1.1f, 1.2f);
        Vector2I v2i(1, 5);

        Vector4D v4d2 = 3.0 - ((2.0 / (v4d + 1.4)) * v4d);
        Vector3F v3f2 = ((2.0f + v3f) * (4.3f / v3f)) - 1.0f;
        Vector2I v2i2 = (((3 - v2i) * 9) + 1) / 2;

        ASSERT_MSG(v4d == Vector4D(1.0, 1.1, 1.2, 1.3) && almostEqual(v4d2, Vector4D(2.1666666666666665, 2.1200000000000001, 2.076923076923076, 2.037037037037037), 1),
                   "math-4 failed");
        ASSERT_MSG(v3f == Vector3F(1.0f, 1.1f, 1.2f) && v3f2 == Vector3F(11.90000057220459, 11.118182182312012, 10.466666221618652), "math-5 failed");
        ASSERT_MSG(v2i == Vector2I(1, 5) && v2i2 == Vector2I(9, -8), "math-6 failed");
    }

    return 0;
}
