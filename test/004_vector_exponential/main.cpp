#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // vector exponential functions
    {
        Vector4D v4d(1.1, -1.5, 0.0, -1.8);

        ASSERT_MSG(pow(v4d, Vector4D(2)) == Vector4D(1.2100000000000002, 2.25, 0, 3.2400000000000002), "pow failed");

        ASSERT_MSG(exp(v4d) == Vector4D(3.0041660239464334, 0.22313016014842982, 1, 0.16529888822158653), "exp failed");

        ASSERT_MSG(log(exp(v4d)) == v4d, "log failed");

        ASSERT_MSG(exp2(v4d) == Vector4D(2.1435469250725863, 0.35355339059327379, 1, 0.28717458874925872), "exp2 failed");

        ASSERT_MSG(log2(exp2(v4d)) == Vector4D(1.0999999999999999, -1.5, 0, -1.8000000000000003), "log2 failed");

        ASSERT_MSG(sqrt(Vector4D(9.0, 100.0, 2.0, 3.14)) == Vector4D(3, 10, 1.4142135623730951, 1.772004514666935),
                   "log2 "
                   "failed");

        ASSERT_MSG(invsqrt(Vector4D(9.0, 100.0, 2.0, 3.14)) ==
                   Vector4D(0.33333333333333331, 0.10000000000000001, 0.70710678118654746, 0.56433264798310034),
                   "invsqrt failed");
    }

    return 0;
}
