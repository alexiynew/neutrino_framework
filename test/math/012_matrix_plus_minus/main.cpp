#include <debug.hpp>

#include <math/math.hpp>

using namespace framework::math;

int main()
{

    // matrix +=, -= matrix
    {
        Matrix4F m44f;
        Matrix4x3F m43f;
        Matrix4x2F m42f;
        Matrix3x4F m34f;
        Matrix3F m33f;
        Matrix3x2F m32f;
        Matrix2x4F m24f;
        Matrix2x3F m23f;
        Matrix2F m22f;

        m44f += m44f;
        m43f += m43f;
        m42f += m42f;
        m34f += m34f;
        m33f += m33f;
        m32f += m32f;
        m24f += m24f;
        m23f += m23f;
        m22f += m22f;

        ASSERT_MSG(m44f == Matrix4F(2), "matrix m44f += failed");
        ASSERT_MSG(m43f == Matrix4x3F(2), "matrix m43f += failed");
        ASSERT_MSG(m42f == Matrix4x2F(2), "matrix m42f += failed");
        ASSERT_MSG(m34f == Matrix3x4F(2), "matrix m34f += failed");
        ASSERT_MSG(m33f == Matrix3F(2), "matrix m33f += failed");
        ASSERT_MSG(m32f == Matrix3x2F(2), "matrix m32f += failed");
        ASSERT_MSG(m24f == Matrix2x4F(2), "matrix m24f += failed");
        ASSERT_MSG(m23f == Matrix2x3F(2), "matrix m23f += failed");
        ASSERT_MSG(m22f == Matrix2F(2), "matrix m22f += failed");

        m44f -= m44f;
        m43f -= m43f;
        m42f -= m42f;
        m34f -= m34f;
        m33f -= m33f;
        m32f -= m32f;
        m24f -= m24f;
        m23f -= m23f;
        m22f -= m22f;

        ASSERT_MSG(m44f == Matrix4F(0), "matrix m44f -= failed");
        ASSERT_MSG(m43f == Matrix4x3F(0), "matrix m43f -= failed");
        ASSERT_MSG(m42f == Matrix4x2F(0), "matrix m42f -= failed");
        ASSERT_MSG(m34f == Matrix3x4F(0), "matrix m34f -= failed");
        ASSERT_MSG(m33f == Matrix3F(0), "matrix m33f -= failed");
        ASSERT_MSG(m32f == Matrix3x2F(0), "matrix m32f -= failed");
        ASSERT_MSG(m24f == Matrix2x4F(0), "matrix m24f -= failed");
        ASSERT_MSG(m23f == Matrix2x3F(0), "matrix m23f -= failed");
        ASSERT_MSG(m22f == Matrix2F(0), "matrix m22f -= failed");
    }

    // matrix unary minus and unary plus
    {
        Matrix4F m44f;
        Matrix4x3F m43f;
        Matrix4x2F m42f;
        Matrix3x4F m34f;
        Matrix3F m33f;
        Matrix3x2F m32f;
        Matrix2x4F m24f;
        Matrix2x3F m23f;
        Matrix2F m22f;

        ASSERT_MSG(-m44f == Matrix4F(-1), "matrix m44f operator- failed");
        ASSERT_MSG(-m43f == Matrix4x3F(-1), "matrix m43f operator- failed");
        ASSERT_MSG(-m42f == Matrix4x2F(-1), "matrix m42f operator- failed");
        ASSERT_MSG(-m34f == Matrix3x4F(-1), "matrix m34f operator- failed");
        ASSERT_MSG(-m33f == Matrix3F(-1), "matrix m33f operator- failed");
        ASSERT_MSG(-m32f == Matrix3x2F(-1), "matrix m32f operator- failed");
        ASSERT_MSG(-m24f == Matrix2x4F(-1), "matrix m24f operator- failed");
        ASSERT_MSG(-m23f == Matrix2x3F(-1), "matrix m23f operator- failed");
        ASSERT_MSG(-m22f == Matrix2F(-1), "matrix m22f operator- failed");

        ASSERT_MSG(+m44f == Matrix4F(1), "matrix m44f operator+ failed");
        ASSERT_MSG(+m43f == Matrix4x3F(1), "matrix m43f operator+ failed");
        ASSERT_MSG(+m42f == Matrix4x2F(1), "matrix m42f operator+ failed");
        ASSERT_MSG(+m34f == Matrix3x4F(1), "matrix m34f operator+ failed");
        ASSERT_MSG(+m33f == Matrix3F(1), "matrix m33f operator+ failed");
        ASSERT_MSG(+m32f == Matrix3x2F(1), "matrix m32f operator+ failed");
        ASSERT_MSG(+m24f == Matrix2x4F(1), "matrix m24f operator+ failed");
        ASSERT_MSG(+m23f == Matrix2x3F(1), "matrix m23f operator+ failed");
        ASSERT_MSG(+m22f == Matrix2F(1), "matrix m22f operator+ failed");
    }

    return 0;
}
