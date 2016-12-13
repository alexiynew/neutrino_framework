#include <debug.hpp>

#include <math/fmath.hpp>

using namespace framework::math;

int main()
{

    // matrix assign
    {
        Matrix4F m44f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        Matrix4x3F m43f(m44f);
        Matrix4x2F m42f(m44f);
        Matrix3x4F m34f(m44f);
        Matrix3F m33f(m44f);
        Matrix3x2F m32f(m44f);
        Matrix2x4F m24f(m44f);
        Matrix2x3F m23f(m44f);
        Matrix2F m22f(m44f);

        Matrix4x2F n42f;
        Matrix4x3F n43f;
        Matrix4F n44f;
        Matrix3x2F n32f;
        Matrix3F n33f;
        Matrix3x4F n34f;
        Matrix2F n22f;
        Matrix2x3F n23f;
        Matrix2x4F n24f;

        n44f = m44f;
        n43f = m43f;
        n42f = m42f;
        n34f = m34f;
        n33f = m33f;
        n32f = m32f;
        n24f = m24f;
        n23f = m23f;
        n22f = m22f;

        ASSERT_MSG(n44f == m44f, "matrix assign n44f == m44f failed");
        ASSERT_MSG(n43f == m43f, "matrix assign n43f == m43f failed");
        ASSERT_MSG(n42f == m42f, "matrix assign n42f == m42f failed");
        ASSERT_MSG(n34f == m34f, "matrix assign n34f == m34f failed");
        ASSERT_MSG(n33f == m33f, "matrix assign n33f == m33f failed");
        ASSERT_MSG(n32f == m32f, "matrix assign n32f == m32f failed");
        ASSERT_MSG(n24f == m24f, "matrix assign n24f == m24f failed");
        ASSERT_MSG(n23f == m23f, "matrix assign n23f == m23f failed");
        ASSERT_MSG(n22f == m22f, "matrix assign n22f == m22f failed");

        Matrix4x2D n42d;
        Matrix4x3D n43d;
        Matrix4D n44d;
        Matrix3x2D n32d;
        Matrix3D n33d;
        Matrix3x4D n34d;
        Matrix2D n22d;
        Matrix2x3D n23d;
        Matrix2x4D n24d;

        n44d = m44f;
        n43d = m43f;
        n42d = m42f;
        n34d = m34f;
        n33d = m33f;
        n32d = m32f;
        n24d = m24f;
        n23d = m23f;
        n22d = m22f;

        ASSERT_MSG(n44d == Matrix4D(m44f), "matrix assign n44d == m44f failed");
        ASSERT_MSG(n43d == Matrix4x3D(m43f), "matrix assign n43d == m43f failed");
        ASSERT_MSG(n42d == Matrix4x2D(m42f), "matrix assign n42d == m42f failed");
        ASSERT_MSG(n34d == Matrix3x4D(m34f), "matrix assign n34d == m34f failed");
        ASSERT_MSG(n33d == Matrix3D(m33f), "matrix assign n33d == m33f failed");
        ASSERT_MSG(n32d == Matrix3x2D(m32f), "matrix assign n32d == m32f failed");
        ASSERT_MSG(n24d == Matrix2x4D(m24f), "matrix assign n24d == m24f failed");
        ASSERT_MSG(n23d == Matrix2x3D(m23f), "matrix assign n23d == m23f failed");
        ASSERT_MSG(n22d == Matrix2D(m22f), "matrix assign n22d == m22f failed");
    }
    return 0;
}
