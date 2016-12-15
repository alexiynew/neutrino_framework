#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class operator_test : public test::suite
{
public:
    operator_test()
        : suite("operator_test")
    {
        add_test([this]() { vector_assign(); }, "vector_assign");
        add_test([this]() { bool_vector_assign(); }, "bool_vector_assign");
    }

private:
    void vector_assign()
    {
        const Vector4D v4d(1.1, 2.2, 3.3, 4);
        const Vector3F v3f(5.5f, 6.6f, 7.7f);
        const Vector2I v2i(1, 2.0);

        Vector4D v4d_result;
        Vector3F v3f_result;
        Vector2I v2i_result;

        Vector4I v4i_result;
        Vector3D v3d_result;
        Vector2F v2f_result;

        v4d_result = v4d;
        v3f_result = v3f;
        v2i_result = v2i;

        v4i_result = v4d;
        v3d_result = v3f;
        v2f_result = v2i;

        ASSERT_MSG(v4i_result == Vector4I(1, 2, 3, 4), "Assign operator failed.");
        ASSERT_MSG(v4d_result == Vector4D(1.1, 2.2, 3.3, 4), "Assign operator failed.");

        ASSERT_MSG(v3d_result == Vector3D(double(5.5f), double(6.6f), double(7.7f)), "Assign operator failed.");
        ASSERT_MSG(v3f_result == Vector3F(5.5f, 6.6f, 7.7f), "Assign operator failed.");

        ASSERT_MSG(v2f_result == Vector2F(1, 2), "Assign operator failed.");
        ASSERT_MSG(v2i_result == Vector2I(1, 2.0), "Assign operator failed.");
    }

    void bool_vector_assign()
    {
        const Vector4B v4b(true, false, true, false);
        const Vector3B v3b(true, false, true);
        const Vector2B v2b(true, false);

        const Vector4D v4d(-1.1, 0.0, 3.3, 0.0);
        const Vector3F v3f(5.5f, 0.0, -7.7f);
        const Vector2I v2i(1, 0);

        Vector4B v4b_result;
        Vector3B v3b_result;
        Vector2B v2b_result;

        v4b_result = v4b;
        v3b_result = v3b;
        v2b_result = v2b;

        ASSERT_MSG(v4b_result == v4b, "Assign to bool vector failed.");
        ASSERT_MSG(v3b_result == v3b, "Assign to bool vector failed.");
        ASSERT_MSG(v2b_result == v2b, "Assign to bool vector failed.");

        v4b_result = v4d;
        v3b_result = v3f;
        v2b_result = v2i;

        ASSERT_MSG(v4b_result == v4b, "Assign to bool vector failed.");
        ASSERT_MSG(v3b_result == v3b, "Assign to bool vector failed.");
        ASSERT_MSG(v2b_result == v2b, "Assign to bool vector failed.");
    }
};


int main()
{
    return run_tests(operator_test());

    // vector access
    {

        // TODO: add data access test id:6
        // double* p = v4d.data();
        // ASSERT_MSG(p[0] == 1.0 && p[1] == 2.0 && p[2] == 3.0 && p[3] == 4.0,
        // "pointer data access");
        // TODO: add vector bool pointer access id:7
        Vector4D v4d(1.1, 2.2, 3.3, 4.4);
        Vector3F v3f(5.5f, 6.6f, 7.7f);
        Vector2I v2i(1, 2);

        Vector4B v4b(true, false, true, false);
        Vector3B v3b(true, false, true);
        Vector2B v2b(true, false);

        ASSERT_MSG(almost_equal(v4d[0], 1.1) && almost_equal(v4d[1], 2.2) && almost_equal(v4d[2], 3.3) &&
                   almost_equal(v4d[3], 4.4),
                   "access filed");
        ASSERT_MSG(almost_equal(v3f[0], 5.5f) && almost_equal(v3f[1], 6.6f) && almost_equal(v3f[2], 7.7f),
                   "access failed");
        ASSERT_MSG(v2i[0] == 1 && v2i[1] == 2, "access failed");

        ASSERT_MSG(v4b[0] && !v4b[1] && v4b[2] && !v4b[3], "access filed");
        ASSERT_MSG(v3b[0] && !v3b[1] && v3b[2], "access failed");
        ASSERT_MSG(v2b[0] && !v2b[1], "access failed");
    }

    // TODO: test for vector of bool matematics
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

        ASSERT_MSG(
        v4d == Vector4D(1.0, 1.1, 1.2, 1.3) &&
        almost_equal(v4d2, Vector4D(2.1666666666666665, 2.1200000000000001, 2.076923076923076, 2.037037037037037), 1),
        "math-4 failed");
        ASSERT_MSG(v3f == Vector3F(1.0f, 1.1f, 1.2f) &&
                   v3f2 == Vector3F(11.90000057220459, 11.118182182312012, 10.466666221618652),
                   "math-5 failed");
        ASSERT_MSG(v2i == Vector2I(1, 5) && v2i2 == Vector2I(9, -8), "math-6 failed");
    }

    return 0;
}
