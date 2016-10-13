#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix +=, -=, *=, /= scalar
    {
        Matrix4x4F m44f;
        Matrix4x3F m43f;
        Matrix4x2F m42f;
        Matrix3x4F m34f;
        Matrix3x3F m33f;
        Matrix3x2F m32f;
        Matrix2x4F m24f;
        Matrix2x3F m23f;
        Matrix2x2F m22f;

        m44f += 1;
        m43f += 1;
        m42f += 1;
        m34f += 1;
        m33f += 1;
        m32f += 1;
        m24f += 1;
        m23f += 1;
        m22f += 1;

        ASSERT_MSG(m44f == Matrix4x4F(2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2), "matrix m44f += 1 failed");
        ASSERT_MSG(m43f == Matrix4x3F(2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1), "matrix m43f += 1 failed");
        ASSERT_MSG(m42f == Matrix4x2F(2, 1, 1, 2, 1, 1, 1, 1), "matrix m42f += 1 failed");

        ASSERT_MSG(m34f == Matrix3x4F(2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1), "matrix m34f += 1 failed");
        ASSERT_MSG(m33f == Matrix3x3F(2, 1, 1, 1, 2, 1, 1, 1, 2), "matrix m33f += 1 failed");
        ASSERT_MSG(m32f == Matrix3x2F(2, 1, 1, 2, 1, 1), "matrix m32f += 1 failed");

        ASSERT_MSG(m24f == Matrix2x4F(2, 1, 1, 1, 1, 2, 1, 1), "matrix m24f += 1 failed");
        ASSERT_MSG(m23f == Matrix2x3F(2, 1, 1, 1, 2, 1), "matrix m23f += 1 failed");
        ASSERT_MSG(m22f == Matrix2x2F(2, 1, 1, 2), "matrix m22f += 1 failed");

        m44f -= 1;
        m43f -= 1;
        m42f -= 1;
        m34f -= 1;
        m33f -= 1;
        m32f -= 1;
        m24f -= 1;
        m23f -= 1;
        m22f -= 1;

        ASSERT_MSG(m44f == Matrix4x4F(), "matrix m44f -= 1 failed");
        ASSERT_MSG(m43f == Matrix4x3F(), "matrix m43f -= 1 failed");
        ASSERT_MSG(m42f == Matrix4x2F(), "matrix m42f -= 1 failed");
        ASSERT_MSG(m34f == Matrix3x4F(), "matrix m34f -= 1 failed");
        ASSERT_MSG(m33f == Matrix3x3F(), "matrix m33f -= 1 failed");
        ASSERT_MSG(m32f == Matrix3x2F(), "matrix m32f -= 1 failed");
        ASSERT_MSG(m24f == Matrix2x4F(), "matrix m24f -= 1 failed");
        ASSERT_MSG(m23f == Matrix2x3F(), "matrix m23f -= 1 failed");
        ASSERT_MSG(m22f == Matrix2x2F(), "matrix m22f -= 1 failed");

        m44f *= 10;
        m43f *= 10;
        m42f *= 10;
        m34f *= 10;
        m33f *= 10;
        m32f *= 10;
        m24f *= 10;
        m23f *= 10;
        m22f *= 10;

        ASSERT_MSG(m44f == Matrix4x4F(10), "matrix m44f *= 10 failed");
        ASSERT_MSG(m43f == Matrix4x3F(10), "matrix m43f *= 10 failed");
        ASSERT_MSG(m42f == Matrix4x2F(10), "matrix m42f *= 10 failed");
        ASSERT_MSG(m34f == Matrix3x4F(10), "matrix m34f *= 10 failed");
        ASSERT_MSG(m33f == Matrix3x3F(10), "matrix m33f *= 10 failed");
        ASSERT_MSG(m32f == Matrix3x2F(10), "matrix m32f *= 10 failed");
        ASSERT_MSG(m24f == Matrix2x4F(10), "matrix m24f *= 10 failed");
        ASSERT_MSG(m23f == Matrix2x3F(10), "matrix m23f *= 10 failed");
        ASSERT_MSG(m22f == Matrix2x2F(10), "matrix m22f *= 10 failed");

        m44f /= 2;
        m43f /= 2;
        m42f /= 2;
        m34f /= 2;
        m33f /= 2;
        m32f /= 2;
        m24f /= 2;
        m23f /= 2;
        m22f /= 2;

        ASSERT_MSG(m44f == Matrix4x4F(5), "matrix m44f /= 2 failed");
        ASSERT_MSG(m43f == Matrix4x3F(5), "matrix m43f /= 2 failed");
        ASSERT_MSG(m42f == Matrix4x2F(5), "matrix m42f /= 2 failed");
        ASSERT_MSG(m34f == Matrix3x4F(5), "matrix m34f /= 2 failed");
        ASSERT_MSG(m33f == Matrix3x3F(5), "matrix m33f /= 2 failed");
        ASSERT_MSG(m32f == Matrix3x2F(5), "matrix m32f /= 2 failed");
        ASSERT_MSG(m24f == Matrix2x4F(5), "matrix m24f /= 2 failed");
        ASSERT_MSG(m23f == Matrix2x3F(5), "matrix m23f /= 2 failed");
        ASSERT_MSG(m22f == Matrix2x2F(5), "matrix m22f /= 2 failed");
    }

    {
        Matrix4x4F m44f(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix4x3F m43f(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix4x2F m42f(1, 1, 1, 1, 1, 1, 1, 1);
        Matrix3x4F m34f(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix3x3F m33f(1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix3x2F m32f(1, 1, 1, 1, 1, 1);
        Matrix2x4F m24f(1, 1, 1, 1, 1, 1, 1, 1);
        Matrix2x3F m23f(1, 1, 1, 1, 1, 1);
        Matrix2x2F m22f(1, 1, 1, 1);

        Matrix4x4F r44f(5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5);
        Matrix4x3F r43f(5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5);
        Matrix4x2F r42f(5, 5, 5, 5, 5, 5, 5, 5);
        Matrix3x4F r34f(5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5);
        Matrix3x3F r33f(5, 5, 5, 5, 5, 5, 5, 5, 5);
        Matrix3x2F r32f(5, 5, 5, 5, 5, 5);
        Matrix2x4F r24f(5, 5, 5, 5, 5, 5, 5, 5);
        Matrix2x3F r23f(5, 5, 5, 5, 5, 5);
        Matrix2x2F r22f(5, 5, 5, 5);

        ASSERT_MSG(m44f + 4.0f == r44f, "matrix + scalar failed");
        ASSERT_MSG(m43f + 4.0f == r43f, "matrix + scalar failed");
        ASSERT_MSG(m42f + 4.0f == r42f, "matrix + scalar failed");
        ASSERT_MSG(m34f + 4.0f == r34f, "matrix + scalar failed");
        ASSERT_MSG(m33f + 4.0f == r33f, "matrix + scalar failed");
        ASSERT_MSG(m32f + 4.0f == r32f, "matrix + scalar failed");
        ASSERT_MSG(m24f + 4.0f == r24f, "matrix + scalar failed");
        ASSERT_MSG(m23f + 4.0f == r23f, "matrix + scalar failed");
        ASSERT_MSG(m22f + 4.0f == r22f, "matrix + scalar failed");

        ASSERT_MSG(r44f - 4.0f == m44f, "matrix - scalar failed");
        ASSERT_MSG(r43f - 4.0f == m43f, "matrix - scalar failed");
        ASSERT_MSG(r42f - 4.0f == m42f, "matrix - scalar failed");
        ASSERT_MSG(r34f - 4.0f == m34f, "matrix - scalar failed");
        ASSERT_MSG(r33f - 4.0f == m33f, "matrix - scalar failed");
        ASSERT_MSG(r32f - 4.0f == m32f, "matrix - scalar failed");
        ASSERT_MSG(r24f - 4.0f == m24f, "matrix - scalar failed");
        ASSERT_MSG(r23f - 4.0f == m23f, "matrix - scalar failed");
        ASSERT_MSG(r22f - 4.0f == m22f, "matrix - scalar failed");

        ASSERT_MSG(m44f * 5.0f == r44f, "matrix * scalar failed");
        ASSERT_MSG(m43f * 5.0f == r43f, "matrix * scalar failed");
        ASSERT_MSG(m42f * 5.0f == r42f, "matrix * scalar failed");
        ASSERT_MSG(m34f * 5.0f == r34f, "matrix * scalar failed");
        ASSERT_MSG(m33f * 5.0f == r33f, "matrix * scalar failed");
        ASSERT_MSG(m32f * 5.0f == r32f, "matrix * scalar failed");
        ASSERT_MSG(m24f * 5.0f == r24f, "matrix * scalar failed");
        ASSERT_MSG(m23f * 5.0f == r23f, "matrix * scalar failed");
        ASSERT_MSG(m22f * 5.0f == r22f, "matrix * scalar failed");

        ASSERT_MSG(r44f / 5.0f == m44f, "matrix / scalar failed");
        ASSERT_MSG(r43f / 5.0f == m43f, "matrix / scalar failed");
        ASSERT_MSG(r42f / 5.0f == m42f, "matrix / scalar failed");
        ASSERT_MSG(r34f / 5.0f == m34f, "matrix / scalar failed");
        ASSERT_MSG(r33f / 5.0f == m33f, "matrix / scalar failed");
        ASSERT_MSG(r32f / 5.0f == m32f, "matrix / scalar failed");
        ASSERT_MSG(r24f / 5.0f == m24f, "matrix / scalar failed");
        ASSERT_MSG(r23f / 5.0f == m23f, "matrix / scalar failed");
        ASSERT_MSG(r22f / 5.0f == m22f, "matrix / scalar failed");

        ASSERT_MSG(4.0f + m44f == r44f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m43f == r43f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m42f == r42f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m34f == r34f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m33f == r33f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m32f == r32f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m24f == r24f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m23f == r23f, "scalar + matrix failed");
        ASSERT_MSG(4.0f + m22f == r22f, "scalar + matrix failed");

        ASSERT_MSG(6.0f - r44f == m44f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r43f == m43f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r42f == m42f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r34f == m34f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r33f == m33f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r32f == m32f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r24f == m24f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r23f == m23f, "scalar - matrix failed");
        ASSERT_MSG(6.0f - r22f == m22f, "scalar - matrix failed");

        ASSERT_MSG(5.0f * m44f == r44f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m43f == r43f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m42f == r42f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m34f == r34f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m33f == r33f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m32f == r32f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m24f == r24f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m23f == r23f, "scalar * matrix failed");
        ASSERT_MSG(5.0f * m22f == r22f, "scalar * matrix failed");

        ASSERT_MSG(5.0f / r44f == m44f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r43f == m43f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r42f == m42f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r34f == m34f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r33f == m33f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r32f == m32f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r24f == m24f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r23f == m23f, "scalar / matrix failed");
        ASSERT_MSG(5.0f / r22f == m22f, "scalar / matrix failed");
    }

    return 0;
}
