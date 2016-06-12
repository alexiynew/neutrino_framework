#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix +=, -=, *=, /= scalar
    {
        mat4x4f m44f;
        mat4x3f m43f;
        mat4x2f m42f;
        mat3x4f m34f;
        mat3x3f m33f;
        mat3x2f m32f;
        mat2x4f m24f;
        mat2x3f m23f;
        mat2x2f m22f;

        m44f += 1;
        m43f += 1;
        m42f += 1;
        m34f += 1;
        m33f += 1;
        m32f += 1;
        m24f += 1;
        m23f += 1;
        m22f += 1;

        assert_msg(m44f == mat4x4f(2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2), "matrix m44f += 1 failed");
        assert_msg(m43f == mat4x3f(2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1), "matrix m43f += 1 failed");
        assert_msg(m42f == mat4x2f(2, 1, 1, 2, 1, 1, 1, 1), "matrix m42f += 1 failed");

        assert_msg(m34f == mat3x4f(2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1), "matrix m34f += 1 failed");
        assert_msg(m33f == mat3x3f(2, 1, 1, 1, 2, 1, 1, 1, 2), "matrix m33f += 1 failed");
        assert_msg(m32f == mat3x2f(2, 1, 1, 2, 1, 1), "matrix m32f += 1 failed");

        assert_msg(m24f == mat2x4f(2, 1, 1, 1, 1, 2, 1, 1), "matrix m24f += 1 failed");
        assert_msg(m23f == mat2x3f(2, 1, 1, 1, 2, 1), "matrix m23f += 1 failed");
        assert_msg(m22f == mat2x2f(2, 1, 1, 2), "matrix m22f += 1 failed");

        m44f -= 1;
        m43f -= 1;
        m42f -= 1;
        m34f -= 1;
        m33f -= 1;
        m32f -= 1;
        m24f -= 1;
        m23f -= 1;
        m22f -= 1;

        assert_msg(m44f == mat4x4f(), "matrix m44f -= 1 failed");
        assert_msg(m43f == mat4x3f(), "matrix m43f -= 1 failed");
        assert_msg(m42f == mat4x2f(), "matrix m42f -= 1 failed");
        assert_msg(m34f == mat3x4f(), "matrix m34f -= 1 failed");
        assert_msg(m33f == mat3x3f(), "matrix m33f -= 1 failed");
        assert_msg(m32f == mat3x2f(), "matrix m32f -= 1 failed");
        assert_msg(m24f == mat2x4f(), "matrix m24f -= 1 failed");
        assert_msg(m23f == mat2x3f(), "matrix m23f -= 1 failed");
        assert_msg(m22f == mat2x2f(), "matrix m22f -= 1 failed");

        m44f *= 10;
        m43f *= 10;
        m42f *= 10;
        m34f *= 10;
        m33f *= 10;
        m32f *= 10;
        m24f *= 10;
        m23f *= 10;
        m22f *= 10;

        assert_msg(m44f == mat4x4f(10), "matrix m44f *= 10 failed");
        assert_msg(m43f == mat4x3f(10), "matrix m43f *= 10 failed");
        assert_msg(m42f == mat4x2f(10), "matrix m42f *= 10 failed");
        assert_msg(m34f == mat3x4f(10), "matrix m34f *= 10 failed");
        assert_msg(m33f == mat3x3f(10), "matrix m33f *= 10 failed");
        assert_msg(m32f == mat3x2f(10), "matrix m32f *= 10 failed");
        assert_msg(m24f == mat2x4f(10), "matrix m24f *= 10 failed");
        assert_msg(m23f == mat2x3f(10), "matrix m23f *= 10 failed");
        assert_msg(m22f == mat2x2f(10), "matrix m22f *= 10 failed");

        m44f /= 2;
        m43f /= 2;
        m42f /= 2;
        m34f /= 2;
        m33f /= 2;
        m32f /= 2;
        m24f /= 2;
        m23f /= 2;
        m22f /= 2;

        assert_msg(m44f == mat4x4f(5), "matrix m44f /= 2 failed");
        assert_msg(m43f == mat4x3f(5), "matrix m43f /= 2 failed");
        assert_msg(m42f == mat4x2f(5), "matrix m42f /= 2 failed");
        assert_msg(m34f == mat3x4f(5), "matrix m34f /= 2 failed");
        assert_msg(m33f == mat3x3f(5), "matrix m33f /= 2 failed");
        assert_msg(m32f == mat3x2f(5), "matrix m32f /= 2 failed");
        assert_msg(m24f == mat2x4f(5), "matrix m24f /= 2 failed");
        assert_msg(m23f == mat2x3f(5), "matrix m23f /= 2 failed");
        assert_msg(m22f == mat2x2f(5), "matrix m22f /= 2 failed");
    }

    {
        mat4x4f m44f(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
        mat4x3f m43f(1,1,1,1,1,1,1,1,1,1,1,1);
        mat4x2f m42f(1,1,1,1,1,1,1,1);
        mat3x4f m34f(1,1,1,1,1,1,1,1,1,1,1,1);
        mat3x3f m33f(1,1,1,1,1,1,1,1,1);
        mat3x2f m32f(1,1,1,1,1,1);
        mat2x4f m24f(1,1,1,1,1,1,1,1);
        mat2x3f m23f(1,1,1,1,1,1);
        mat2x2f m22f(1,1,1,1);

        mat4x4f r44f(5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5);
        mat4x3f r43f(5,5,5,5,5,5,5,5,5,5,5,5);
        mat4x2f r42f(5,5,5,5,5,5,5,5);
        mat3x4f r34f(5,5,5,5,5,5,5,5,5,5,5,5);
        mat3x3f r33f(5,5,5,5,5,5,5,5,5);
        mat3x2f r32f(5,5,5,5,5,5);
        mat2x4f r24f(5,5,5,5,5,5,5,5);
        mat2x3f r23f(5,5,5,5,5,5);
        mat2x2f r22f(5,5,5,5);

        assert_msg(m44f + 4.0f == r44f, "matrix + scalar failed");
        assert_msg(m43f + 4.0f == r43f, "matrix + scalar failed");
        assert_msg(m42f + 4.0f == r42f, "matrix + scalar failed");
        assert_msg(m34f + 4.0f == r34f, "matrix + scalar failed");
        assert_msg(m33f + 4.0f == r33f, "matrix + scalar failed");
        assert_msg(m32f + 4.0f == r32f, "matrix + scalar failed");
        assert_msg(m24f + 4.0f == r24f, "matrix + scalar failed");
        assert_msg(m23f + 4.0f == r23f, "matrix + scalar failed");
        assert_msg(m22f + 4.0f == r22f, "matrix + scalar failed");

        assert_msg(r44f - 4.0f == m44f, "matrix - scalar failed");
        assert_msg(r43f - 4.0f == m43f, "matrix - scalar failed");
        assert_msg(r42f - 4.0f == m42f, "matrix - scalar failed");
        assert_msg(r34f - 4.0f == m34f, "matrix - scalar failed");
        assert_msg(r33f - 4.0f == m33f, "matrix - scalar failed");
        assert_msg(r32f - 4.0f == m32f, "matrix - scalar failed");
        assert_msg(r24f - 4.0f == m24f, "matrix - scalar failed");
        assert_msg(r23f - 4.0f == m23f, "matrix - scalar failed");
        assert_msg(r22f - 4.0f == m22f, "matrix - scalar failed");

        assert_msg(m44f * 5.0f == r44f, "matrix * scalar failed");
        assert_msg(m43f * 5.0f == r43f, "matrix * scalar failed");
        assert_msg(m42f * 5.0f == r42f, "matrix * scalar failed");
        assert_msg(m34f * 5.0f == r34f, "matrix * scalar failed");
        assert_msg(m33f * 5.0f == r33f, "matrix * scalar failed");
        assert_msg(m32f * 5.0f == r32f, "matrix * scalar failed");
        assert_msg(m24f * 5.0f == r24f, "matrix * scalar failed");
        assert_msg(m23f * 5.0f == r23f, "matrix * scalar failed");
        assert_msg(m22f * 5.0f == r22f, "matrix * scalar failed");

        assert_msg(r44f / 5.0f == m44f, "matrix / scalar failed");
        assert_msg(r43f / 5.0f == m43f, "matrix / scalar failed");
        assert_msg(r42f / 5.0f == m42f, "matrix / scalar failed");
        assert_msg(r34f / 5.0f == m34f, "matrix / scalar failed");
        assert_msg(r33f / 5.0f == m33f, "matrix / scalar failed");
        assert_msg(r32f / 5.0f == m32f, "matrix / scalar failed");
        assert_msg(r24f / 5.0f == m24f, "matrix / scalar failed");
        assert_msg(r23f / 5.0f == m23f, "matrix / scalar failed");
        assert_msg(r22f / 5.0f == m22f, "matrix / scalar failed");



        assert_msg(4.0f + m44f == r44f, "scalar + matrix failed");
        assert_msg(4.0f + m43f == r43f, "scalar + matrix failed");
        assert_msg(4.0f + m42f == r42f, "scalar + matrix failed");
        assert_msg(4.0f + m34f == r34f, "scalar + matrix failed");
        assert_msg(4.0f + m33f == r33f, "scalar + matrix failed");
        assert_msg(4.0f + m32f == r32f, "scalar + matrix failed");
        assert_msg(4.0f + m24f == r24f, "scalar + matrix failed");
        assert_msg(4.0f + m23f == r23f, "scalar + matrix failed");
        assert_msg(4.0f + m22f == r22f, "scalar + matrix failed");

        assert_msg(6.0f - r44f == m44f, "scalar - matrix failed");
        assert_msg(6.0f - r43f == m43f, "scalar - matrix failed");
        assert_msg(6.0f - r42f == m42f, "scalar - matrix failed");
        assert_msg(6.0f - r34f == m34f, "scalar - matrix failed");
        assert_msg(6.0f - r33f == m33f, "scalar - matrix failed");
        assert_msg(6.0f - r32f == m32f, "scalar - matrix failed");
        assert_msg(6.0f - r24f == m24f, "scalar - matrix failed");
        assert_msg(6.0f - r23f == m23f, "scalar - matrix failed");
        assert_msg(6.0f - r22f == m22f, "scalar - matrix failed");

        assert_msg(5.0f * m44f == r44f, "scalar * matrix failed");
        assert_msg(5.0f * m43f == r43f, "scalar * matrix failed");
        assert_msg(5.0f * m42f == r42f, "scalar * matrix failed");
        assert_msg(5.0f * m34f == r34f, "scalar * matrix failed");
        assert_msg(5.0f * m33f == r33f, "scalar * matrix failed");
        assert_msg(5.0f * m32f == r32f, "scalar * matrix failed");
        assert_msg(5.0f * m24f == r24f, "scalar * matrix failed");
        assert_msg(5.0f * m23f == r23f, "scalar * matrix failed");
        assert_msg(5.0f * m22f == r22f, "scalar * matrix failed");

        assert_msg(5.0f / r44f == m44f, "scalar / matrix failed");
        assert_msg(5.0f / r43f == m43f, "scalar / matrix failed");
        assert_msg(5.0f / r42f == m42f, "scalar / matrix failed");
        assert_msg(5.0f / r34f == m34f, "scalar / matrix failed");
        assert_msg(5.0f / r33f == m33f, "scalar / matrix failed");
        assert_msg(5.0f / r32f == m32f, "scalar / matrix failed");
        assert_msg(5.0f / r24f == m24f, "scalar / matrix failed");
        assert_msg(5.0f / r23f == m23f, "scalar / matrix failed");
        assert_msg(5.0f / r22f == m22f, "scalar / matrix failed");

    }

    return 0;
}
