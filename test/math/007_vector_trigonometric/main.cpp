#include <debug.hpp>

#include <math/math.hpp>

using namespace framework::math;

int main()
{

    // vector trigonometric functions
    {
        Vector4D v4d(180.0, 360.0, 90.0, 45.0);

        Vector3D v3d(45.0, 60.0, 180.0);

        ASSERT_MSG(radians(v4d) == Vector4D(PI, TAU, PI / 2, PI / 4), "radians failed");

        ASSERT_MSG(degrees(radians(v4d)) == v4d, "degrees failed");

        ASSERT_MSG(almost_equal(sin(radians(v4d)), Vector4D(sin(PI), sin(TAU), sin(PI / 2), sin(PI / 4))),
                   "sin failed");

        ASSERT_MSG(almost_equal(cos(radians(v4d)), Vector4D(cos(PI), cos(TAU), cos(PI / 2), cos(PI / 4))),
                   "cos failed");

        ASSERT_MSG(almost_equal(tan(radians(v3d)), sin(radians(v3d)) / cos(radians(v3d))), "tan failed");

        ASSERT_MSG(almost_equal(asin(sin(radians(v4d))), Vector4D(asin(sin(PI)), asin(sin(TAU)), PI / 2, PI / 4), 1),
                   "asin failed");

        ASSERT_MSG(almost_equal(acos(cos(radians(v4d))), Vector4D(PI, 0, PI / 2, PI / 4)), "acos failed");

        ASSERT_MSG(almost_equal(atan(tan(radians(v3d))), Vector3D(PI / 4, PI / 3, atan(tan(PI)))),
                   "atan from tan failed");

        ASSERT_MSG(almost_equal(atan(sin(radians(v3d)), cos(radians(v3d))), Vector3D(PI / 4, PI / 3, PI)),
                   "atan from sin "
                   "failed");

        ASSERT_MSG(almost_equal(sinh(radians(v3d)), Vector3D(0.86867096148600953, 1.2493670505239751, 11.548739357257748)),
                   "sinh failed");

        ASSERT_MSG(almost_equal(cosh(radians(v3d)), Vector3D(1.3246090892520057, 1.6002868577023861, 11.591953275521519)),
                   "cosh failed");

        ASSERT_MSG(almost_equal(tanh(radians(v3d)), (sinh(radians(v3d)) / cosh(radians(v3d))), 1), "tanh failed");

        ASSERT_MSG(almost_equal(asinh(sinh(radians(v3d))), Vector3D(PI / 4, PI / 3, PI), 1), "asinh failed");

        ASSERT_MSG(almost_equal(acosh(cosh(radians(v3d))), Vector3D(PI / 4, PI / 3, PI), 1), "acosh failed");

        ASSERT_MSG(almost_equal(atanh(tanh(radians(v3d))), Vector3D(PI / 4, PI / 3, PI), 4), "atanh failed");
    }

    return 0;
}
