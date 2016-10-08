#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{
    {
        Matrix4x4F m44;
        Matrix4x3F m43;
        Matrix4x2F m42;
        Matrix3x4F m34;
        Matrix3x3F m33;
        Matrix3x2F m32;
        Matrix2x4F m24;
        Matrix2x3F m23;
        Matrix2x2F m22;

        ASSERT_MSG(transpose(m44) == m44, "transpose m44 failed");
        ASSERT_MSG(transpose(m43) == m34, "transpose m43 failed");
        ASSERT_MSG(transpose(m42) == m24, "transpose m42 failed");

        ASSERT_MSG(transpose(m34) == m43, "transpose m34 failed");
        ASSERT_MSG(transpose(m33) == m33, "transpose m33 failed");
        ASSERT_MSG(transpose(m32) == m23, "transpose m32 failed");

        ASSERT_MSG(transpose(m24) == m42, "transpose m24 failed");
        ASSERT_MSG(transpose(m23) == m32, "transpose m23 failed");
        ASSERT_MSG(transpose(m22) == m22, "transpose m22 failed");
    }

    {
        Matrix4x4F m44(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

        Matrix4x3F m43(m44);
        Matrix4x2F m42(m44);
        Matrix3x4F m34(m44);
        Matrix3x3F m33(m44);
        Matrix3x2F m32(m44);
        Matrix2x4F m24(m44);
        Matrix2x3F m23(m44);
        Matrix2x2F m22(m44);

        Matrix4x4F r44(1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16);

        Matrix4x3F r43(r44);
        Matrix4x2F r42(r44);
        Matrix3x4F r34(r44);
        Matrix3x3F r33(r44);
        Matrix3x2F r32(r44);
        Matrix2x4F r24(r44);
        Matrix2x3F r23(r44);
        Matrix2x2F r22(r44);

        ASSERT_MSG(crossComponentMultiplication(m44, m44) == r44, "crossComponentMultiplication m44 failed");
        ASSERT_MSG(crossComponentMultiplication(m43, m43) == r43, "crossComponentMultiplication m43 failed");
        ASSERT_MSG(crossComponentMultiplication(m42, m42) == r42, "crossComponentMultiplication m42 failed");
        ASSERT_MSG(crossComponentMultiplication(m34, m34) == r34, "crossComponentMultiplication m34 failed");
        ASSERT_MSG(crossComponentMultiplication(m33, m33) == r33, "crossComponentMultiplication m33 failed");
        ASSERT_MSG(crossComponentMultiplication(m32, m32) == r32, "crossComponentMultiplication m32 failed");
        ASSERT_MSG(crossComponentMultiplication(m24, m24) == r24, "crossComponentMultiplication m24 failed");
        ASSERT_MSG(crossComponentMultiplication(m23, m23) == r23, "crossComponentMultiplication m23 failed");
        ASSERT_MSG(crossComponentMultiplication(m22, m22) == r22, "crossComponentMultiplication m22 failed");
    }

    {
        Vector2F v2(1, 2);
        Vector3F v3(1, 2, 3);
        Vector4F v4(1, 2, 3, 4);

        ASSERT_MSG(outerProduct(v2, v2) == Matrix2x2F(1, 2, 2, 4), "outerProduct(v2, v2) failed");
        ASSERT_MSG(outerProduct(v2, v3) == Matrix3x2F(1, 2, 2, 4, 3, 6), "outerProduct(v2, v3) failed");
        ASSERT_MSG(outerProduct(v2, v4) == Matrix4x2F(1, 2, 2, 4, 3, 6, 4, 8), "outerProduct(v2, v4) failed");

        ASSERT_MSG(outerProduct(v3, v2) == Matrix2x3F(1, 2, 3, 2, 4, 6), "outerProduct(v3, v2) failed");
        ASSERT_MSG(outerProduct(v3, v3) == Matrix3x3F(1, 2, 3, 2, 4, 6, 3, 6, 9), "outerProduct(v3, v3) failed");
        ASSERT_MSG(outerProduct(v3, v4) == Matrix4x3F(1, 2, 3, 2, 4, 6, 3, 6, 9, 4, 8, 12),
        "outerProduct(v3, v4) "
        "failed");

        ASSERT_MSG(outerProduct(v4, v2) == Matrix2x4F(1, 2, 3, 4, 2, 4, 6, 8), "outerProduct(v4, v2) failed");
        ASSERT_MSG(outerProduct(v4, v3) == Matrix3x4F(1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12),
        "outerProduct(v4, v3) "
        "failed");
        ASSERT_MSG(outerProduct(v4, v4) == Matrix4x4F(1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12, 4, 8, 12, 16), "outerProduct(v4, v4) failed");
    }

    {
        Matrix2F m2(1, 2, 1, 2);
        Matrix3F m3(1, 2, 3, 1, 2, 3, 1, 2, 3);
        Matrix4F m4(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

        ASSERT_MSG(almostEqual(determinant(Matrix2F()), 1.0f), "determinant faled");
        ASSERT_MSG(almostEqual(determinant(Matrix3F()), 1.0f), "determinant faled");
        ASSERT_MSG(almostEqual(determinant(Matrix4F()), 1.0f), "determinant faled");

        ASSERT_MSG(almostEqual(determinant(m2), 0.0f), "determinant faled");
        ASSERT_MSG(almostEqual(determinant(m3), 0.0f), "determinant faled");
        ASSERT_MSG(almostEqual(determinant(m3), 0.0f), "determinant faled");
    }

    {
        Matrix2F m2(4, 2, 2, 3);
        Matrix3F m3(8, 6, 7, 4, 2, 3, 1, 5, 2);
        Matrix4F m4(1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1);

        ASSERT_MSG(almostEqual(determinant(m2), 8.0f), "determinant faled");
        ASSERT_MSG(almostEqual(determinant(m3), 8.0f), "determinant faled");
        ASSERT_MSG(almostEqual(determinant(m4), -1.0f), "determinant faled");

        ASSERT_MSG(inverse(m2) * m2 == Matrix2x2F(), "inverse failed");
        ASSERT_MSG(inverse(m3) * m3 == Matrix3x3F(), "inverse failed");
        ASSERT_MSG(inverse(m4) * m4 == Matrix4x4F(), "inverse failed");

        ASSERT_MSG(almostEqual(determinant(inverse(m3)), 1.0f / determinant(m3)), "inverse determinant failed");
        ASSERT_MSG(almostEqual(determinant(inverse(m4)), 1.0f / determinant(m4)), "inverse determinant failed");
        ASSERT_MSG(almostEqual(determinant(inverse(m2)), 1.0f / determinant(m2)), "inverse determinant failed");
    }

    {
        Matrix3F m3(0, -1, 0, -1, 0, 0, 5, 5, 1);

        ASSERT_MSG(affineInverse(m3) == inverse(m3), "matrix 3f affine inverse failed");
    }

    {
        Matrix4F m4(0.707f, 0.0f, -0.707f, 0.0f, 0.354f, 0.866f, 0.354f, 0.0f, 0.612f, -0.5f, 0.612f, 0.0f, 1.0f, 1.0f, 4.0f, 1.0f);

        auto a = affineInverse(m4);
        auto b = inverse(m4);

        ASSERT_MSG(almostEqual(a[0], b[0]) && almostEqual(a[1], b[1]) && almostEqual(a[2], b[2]) && almostEqual(a[3], b[3]), "matrix 4f affine inverse failed");
    }

    {
        Matrix2F m2(4, 2, 2, 3);
        Matrix3F m3(8, 6, 7, 4, 2, 3, 1, 5, 2);
        Matrix4F m4(1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1);

        ASSERT_MSG(transpose(inverse(m2)) == inverseTranspose(m2), "mat2 inverseTranspose failed");
        ASSERT_MSG(transpose(inverse(m3)) == inverseTranspose(m3), "mat3 inverseTranspose failed");
        ASSERT_MSG(transpose(inverse(m4)) == inverseTranspose(m4), "mat4 inverseTranspose failed");
    }

    return 0;
}
