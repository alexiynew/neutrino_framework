#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix * vector, vector * matrix multiply
    {
        Matrix4F m44f(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

        Matrix4x3F m43f(m44f);
        Matrix4x2F m42f(m44f);
        Matrix3x4F m34f(m44f);
        Matrix3F m33f(m44f);
        Matrix3x2F m32f(m44f);
        Matrix2x4F m24f(m44f);
        Matrix2x3F m23f(m44f);
        Matrix2F m22f(m44f);

        Vector4F v4f(1, 2, 3, 4);
        Vector3F v3f(1, 2, 3);
        Vector2F v2f(1, 2);

        ASSERT_MSG(v4f * m44f == Vector4F(30, 30, 30, 30), "Vector4F * mat44f failed");
        ASSERT_MSG(v4f * m34f == Vector3F(30, 30, 30), "Vector4F * mat34f failed");
        ASSERT_MSG(v4f * m24f == Vector2F(30, 30), "Vector4F * mat24f failed");

        ASSERT_MSG(v3f * m43f == Vector4F(14, 14, 14, 14), "Vector3F * mat43f failed");
        ASSERT_MSG(v3f * m33f == Vector3F(14, 14, 14), "Vector3F * mat33f failed");
        ASSERT_MSG(v3f * m23f == Vector2F(14, 14), "Vector3F * mat23f failed");

        ASSERT_MSG(v2f * m42f == Vector4F(5, 5, 5, 5), "Vector2F * mat42f failed");
        ASSERT_MSG(v2f * m32f == Vector3F(5, 5, 5), "Vector2F * mat32f failed");
        ASSERT_MSG(v2f * m22f == Vector2F(5, 5), "Vector2F * mat22f failed");

        ASSERT_MSG(m44f * v4f == Vector4F(10, 20, 30, 40), "mat44f * Vector4F failed");
        ASSERT_MSG(m43f * v4f == Vector3F(10, 20, 30), "mat43f * Vector4F failed");
        ASSERT_MSG(m42f * v4f == Vector2F(10, 20), "mat42f * Vector4F failed");

        ASSERT_MSG(m34f * v3f == Vector4F(6, 12, 18, 24), "mat34f * Vector3F failed");
        ASSERT_MSG(m33f * v3f == Vector3F(6, 12, 18), "mat33f * Vector3F failed");
        ASSERT_MSG(m32f * v3f == Vector2F(6, 12), "mat32f * Vector3F failed");

        ASSERT_MSG(m24f * v2f == Vector4F(3, 6, 9, 12), "mat24f * Vector2F failed");
        ASSERT_MSG(m23f * v2f == Vector3F(3, 6, 9), "mat23f * Vector2F failed");
        ASSERT_MSG(m22f * v2f == Vector2F(3, 6), "mat22f * Vector2F failed");
    }

    // martix multiplying
    {
        Matrix4F m44f(1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1);

        Matrix4x3F m43f(1, 2, 3, 3, 1, 2, 2, 3, 1, 1, 2, 3);

        Matrix4x2F m42f(1, 2, 2, 1, 1, 2, 2, 1);

        Matrix3x4F m34f(1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2);

        Matrix3F m33f(1, 2, 3, 3, 1, 2, 2, 3, 1);

        Matrix3x2F m32f(1, 2, 2, 1, 1, 2);

        Matrix2x4F m24f(1, 2, 3, 4, 4, 1, 2, 3);

        Matrix2x3F m23f(1, 2, 3, 4, 1, 2);

        Matrix2F m22f(1, 2, 4, 1);

        ASSERT_MSG(m44f * m44f == Matrix4F(26, 28, 26, 20, 20, 26, 28, 26, 26, 20, 26, 28, 28, 26, 20, 26), "matrix m44f * m44f failed");

        ASSERT_MSG(m44f * m34f == Matrix3x4F(26, 28, 26, 20, 20, 26, 28, 26, 26, 20, 26, 28), "matrix m44f * m34f failed");

        ASSERT_MSG(m44f * m24f == Matrix2x4F(26, 28, 26, 20, 20, 26, 28, 26), "matrix m44f * m24f failed");

        ASSERT_MSG(m43f * m44f == Matrix4x3F(17, 21, 22, 14, 21, 25, 19, 17, 24, 20, 21, 19), "matrix m43f * m44f failed");

        ASSERT_MSG(m43f * m34f == Matrix3F(17, 21, 22, 14, 21, 25, 19, 17, 24), "matrix m43f * m34f failed");

        ASSERT_MSG(m43f * m24f == Matrix2x3F(17, 21, 22, 14, 21, 25), "matrix m43f * m24f failed");

        ASSERT_MSG(m42f * m44f == Matrix4x2F(16, 14, 14, 16, 16, 14, 14, 16), "matrix m42f * m44f failed");

        ASSERT_MSG(m42f * m34f == Matrix3x2F(16, 14, 14, 16, 16, 14), "matrix m42f * m34f failed");

        ASSERT_MSG(m42f * m24f == Matrix2F(16, 14, 14, 16), "matrix m42f * m24f failed");

        ASSERT_MSG(m34f * m43f == Matrix4F(18, 16, 10, 16, 13, 15, 13, 19, 17, 11, 13, 19, 18, 16, 10, 16), "matrix m34f * m43f failed");

        ASSERT_MSG(m34f * m33f == Matrix3x4F(18, 16, 10, 16, 13, 15, 13, 19, 17, 11, 13, 19), "matrix m34f * m33f failed");

        ASSERT_MSG(m34f * m23f == Matrix2x4F(18, 16, 10, 16, 14, 17, 16, 23), "matrix m34f * m23f failed");

        ASSERT_MSG(m33f * m43f == Matrix4x3F(13, 13, 10, 10, 13, 13, 13, 10, 13, 13, 13, 10), "matrix m33f * m43f failed");

        ASSERT_MSG(m33f * m33f == Matrix3F(13, 13, 10, 10, 13, 13, 13, 10, 13), "matrix m33f * m33f failed");

        ASSERT_MSG(m33f * m23f == Matrix2x3F(13, 13, 10, 11, 15, 16), "matrix m33f * m23f failed");

        ASSERT_MSG(m32f * m43f == Matrix4x2F(8, 10, 7, 11, 9, 9, 8, 10), "matrix m32f * m43f failed");

        ASSERT_MSG(m32f * m33f == Matrix3x2F(8, 10, 7, 11, 9, 9), "matrix m32f * m33f failed");

        ASSERT_MSG(m32f * m23f == Matrix2F(8, 10, 8, 13), "matrix m32f * m23f failed");

        ASSERT_MSG(m24f * m42f == Matrix4F(9, 4, 7, 10, 6, 5, 8, 11, 9, 4, 7, 10, 6, 5, 8, 11),
        "matrix m24f * m42f "
        "failed");

        ASSERT_MSG(m24f * m32f == Matrix3x4F(9, 4, 7, 10, 6, 5, 8, 11, 9, 4, 7, 10), "matrix m24f * m32f failed");

        ASSERT_MSG(m24f * m22f == Matrix2x4F(9, 4, 7, 10, 8, 9, 14, 19), "matrix m24f * m22f failed");

        ASSERT_MSG(m23f * m42f == Matrix4x3F(9, 4, 7, 6, 5, 8, 9, 4, 7, 6, 5, 8), "matrix m23f * m42f failed");

        ASSERT_MSG(m23f * m32f == Matrix3F(9, 4, 7, 6, 5, 8, 9, 4, 7), "matrix m23f * m32f failed");

        ASSERT_MSG(m23f * m22f == Matrix2x3F(9, 4, 7, 8, 9, 14), "matrix m23f * m22f failed");

        ASSERT_MSG(m22f * m42f == Matrix4x2F(9, 4, 6, 5, 9, 4, 6, 5), "matrix m22f * m42f failed");

        ASSERT_MSG(m22f * m32f == Matrix3x2F(9, 4, 6, 5, 9, 4), "matrix m22f * m32f failed");

        ASSERT_MSG(m22f * m22f == Matrix2F(9, 4, 8, 9), "matrix m22f * m22f failed");
    }

    return 0;
}
