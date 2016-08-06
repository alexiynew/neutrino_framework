#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    Matrix2x4F m24;
    Matrix2x3F m23;
    Matrix2x2F m22;
    Matrix3x4F m34;
    Matrix3x3F m33;
    Matrix3x2F m32;
    Matrix4x4F m44;
    Matrix4x3F m43;
    Matrix4x2F m42;

    ASSERT_MSG(m44[0] == Vector4F(1, 0, 0, 0) && m44[1] == Vector4F(0, 1, 0, 0) && m44[2] == Vector4F(0, 0, 1, 0) &&
               m44[3] == Vector4F(0, 0, 0, 1),
               "matrix 4f access failed");
    ASSERT_MSG(m34[0] == Vector4F(1, 0, 0, 0) && m34[1] == Vector4F(0, 1, 0, 0) && m34[2] == Vector4F(0, 0, 1, 0),
               "matrix 34f access failed");
    ASSERT_MSG(m24[0] == Vector4F(1, 0, 0, 0) && m24[1] == Vector4F(0, 1, 0, 0), "matrix 24f access failed");

    ASSERT_MSG(m43[0] == Vector3F(1, 0, 0) && m43[1] == Vector3F(0, 1, 0) && m43[2] == Vector3F(0, 0, 1) &&
               m43[3] == Vector3F(0, 0, 0),
               "matrix 43f access failed");
    ASSERT_MSG(m33[0] == Vector3F(1, 0, 0) && m33[1] == Vector3F(0, 1, 0) && m33[2] == Vector3F(0, 0, 1),
               "matrix 3f access "
               "failed");
    ASSERT_MSG(m23[0] == Vector3F(1, 0, 0) && m23[1] == Vector3F(0, 1, 0), "matrix 23f access failed");

    ASSERT_MSG(m42[0] == Vector2F(1, 0) && m42[1] == Vector2F(0, 1) && m42[2] == Vector2F(0, 0) && m42[3] == Vector2F(0, 0),
               "matrix 42f access failed");
    ASSERT_MSG(m32[0] == Vector2F(1, 0) && m32[1] == Vector2F(0, 1) && m32[2] == Vector2F(0, 0),
               "matrix 32f access failed");
    ASSERT_MSG(m22[0] == Vector2F(1, 0) && m22[1] == Vector2F(0, 1), "matrix 2f access failed");


    ASSERT_MSG(m44.column(0) == Vector4F(1, 0, 0, 0) && m44.column(1) == Vector4F(0, 1, 0, 0) &&
               m44.column(2) == Vector4F(0, 0, 1, 0) && m44.column(3) == Vector4F(0, 0, 0, 1),
               "matrix 4f access failed");
    ASSERT_MSG(m34.column(0) == Vector4F(1, 0, 0, 0) && m34.column(1) == Vector4F(0, 1, 0, 0) &&
               m34.column(2) == Vector4F(0, 0, 1, 0),
               "matrix 34f access failed");
    ASSERT_MSG(m24.column(0) == Vector4F(1, 0, 0, 0) && m24.column(1) == Vector4F(0, 1, 0, 0),
               "matrix 24f access failed");

    ASSERT_MSG(m43.column(0) == Vector3F(1, 0, 0) && m43.column(1) == Vector3F(0, 1, 0) &&
               m43.column(2) == Vector3F(0, 0, 1) && m43.column(3) == Vector3F(0, 0, 0),
               "matrix 43f access failed");
    ASSERT_MSG(m33.column(0) == Vector3F(1, 0, 0) && m33.column(1) == Vector3F(0, 1, 0) && m33.column(2) == Vector3F(0, 0, 1),
               "matrix 3f access failed");
    ASSERT_MSG(m23.column(0) == Vector3F(1, 0, 0) && m23.column(1) == Vector3F(0, 1, 0), "matrix 23f access failed");

    ASSERT_MSG(m42.column(0) == Vector2F(1, 0) && m42.column(1) == Vector2F(0, 1) && m42.column(2) == Vector2F(0, 0) &&
               m42.column(3) == Vector2F(0, 0),
               "matrix 42f access failed");
    ASSERT_MSG(m32.column(0) == Vector2F(1, 0) && m32.column(1) == Vector2F(0, 1) && m32.column(2) == Vector2F(0, 0),
               "matrix 32f access failed");
    ASSERT_MSG(m22.column(0) == Vector2F(1, 0) && m22.column(1) == Vector2F(0, 1), "matrix 2f access failed");


    ASSERT_MSG(m44.row(0) == Vector4F(1, 0, 0, 0) && m44.row(1) == Vector4F(0, 1, 0, 0) &&
               m44.row(2) == Vector4F(0, 0, 1, 0) && m44.row(3) == Vector4F(0, 0, 0, 1),
               "matrix 4f access failed");
    ASSERT_MSG(m34.row(0) == Vector3F(1, 0, 0) && m34.row(1) == Vector3F(0, 1, 0) && m34.row(2) == Vector3F(0, 0, 1) &&
               m34.row(3) == Vector3F(0, 0, 0),
               "matrix 34f access failed");
    ASSERT_MSG(m24.row(0) == Vector2F(1, 0) && m24.row(1) == Vector2F(0, 1) && m24.row(2) == Vector2F(0, 0) &&
               m24.row(3) == Vector2F(0, 0),
               "matrix 24f access failed");

    ASSERT_MSG(m43.row(0) == Vector4F(1, 0, 0, 0) && m43.row(1) == Vector4F(0, 1, 0, 0) && m43.row(2) == Vector4F(0, 0, 1, 0),
               "matrix 43f access failed");
    ASSERT_MSG(m33.row(0) == Vector3F(1, 0, 0) && m33.row(1) == Vector3F(0, 1, 0) && m33.row(2) == Vector3F(0, 0, 1),
               "matrix 33f access failed");
    ASSERT_MSG(m23.row(0) == Vector2F(1, 0) && m23.row(1) == Vector2F(0, 1) && m23.row(2) == Vector2F(0, 0),
               "matrix 23f access "
               "failed");

    ASSERT_MSG(m42.row(0) == Vector4F(1, 0, 0, 0) && m42.row(1) == Vector4F(0, 1, 0, 0), "matrix 42f access failed");
    ASSERT_MSG(m32.row(0) == Vector3F(1, 0, 0) && m32.row(1) == Vector3F(0, 1, 0), "matrix 32f access failed");
    ASSERT_MSG(m22.row(0) == Vector2F(1, 0) && m22.row(1) == Vector2F(0, 1), "matrix 22f access failed");

    return 0;
}
