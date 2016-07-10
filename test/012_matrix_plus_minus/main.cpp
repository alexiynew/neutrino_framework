#include <debug.h>

#include <math/fmath.h>

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

        assert_msg(m44f == Matrix4F(2), "matrix m44f += failed");
        assert_msg(m43f == Matrix4x3F(2), "matrix m43f += failed");
        assert_msg(m42f == Matrix4x2F(2), "matrix m42f += failed");
        assert_msg(m34f == Matrix3x4F(2), "matrix m34f += failed");
        assert_msg(m33f == Matrix3F(2), "matrix m33f += failed");
        assert_msg(m32f == Matrix3x2F(2), "matrix m32f += failed");
        assert_msg(m24f == Matrix2x4F(2), "matrix m24f += failed");
        assert_msg(m23f == Matrix2x3F(2), "matrix m23f += failed");
        assert_msg(m22f == Matrix2F(2), "matrix m22f += failed");

        m44f -= m44f;
        m43f -= m43f;
        m42f -= m42f;
        m34f -= m34f;
        m33f -= m33f;
        m32f -= m32f;
        m24f -= m24f;
        m23f -= m23f;
        m22f -= m22f;

        assert_msg(m44f == Matrix4F(0), "matrix m44f -= failed");
        assert_msg(m43f == Matrix4x3F(0), "matrix m43f -= failed");
        assert_msg(m42f == Matrix4x2F(0), "matrix m42f -= failed");
        assert_msg(m34f == Matrix3x4F(0), "matrix m34f -= failed");
        assert_msg(m33f == Matrix3F(0), "matrix m33f -= failed");
        assert_msg(m32f == Matrix3x2F(0), "matrix m32f -= failed");
        assert_msg(m24f == Matrix2x4F(0), "matrix m24f -= failed");
        assert_msg(m23f == Matrix2x3F(0), "matrix m23f -= failed");
        assert_msg(m22f == Matrix2F(0), "matrix m22f -= failed");
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

        assert_msg(-m44f == Matrix4F(-1), "matrix m44f operator- failed");
        assert_msg(-m43f == Matrix4x3F(-1), "matrix m43f operator- failed");
        assert_msg(-m42f == Matrix4x2F(-1), "matrix m42f operator- failed");
        assert_msg(-m34f == Matrix3x4F(-1), "matrix m34f operator- failed");
        assert_msg(-m33f == Matrix3F(-1), "matrix m33f operator- failed");
        assert_msg(-m32f == Matrix3x2F(-1), "matrix m32f operator- failed");
        assert_msg(-m24f == Matrix2x4F(-1), "matrix m24f operator- failed");
        assert_msg(-m23f == Matrix2x3F(-1), "matrix m23f operator- failed");
        assert_msg(-m22f == Matrix2F(-1), "matrix m22f operator- failed");

        assert_msg(+m44f == Matrix4F(1), "matrix m44f operator+ failed");
        assert_msg(+m43f == Matrix4x3F(1), "matrix m43f operator+ failed");
        assert_msg(+m42f == Matrix4x2F(1), "matrix m42f operator+ failed");
        assert_msg(+m34f == Matrix3x4F(1), "matrix m34f operator+ failed");
        assert_msg(+m33f == Matrix3F(1), "matrix m33f operator+ failed");
        assert_msg(+m32f == Matrix3x2F(1), "matrix m32f operator+ failed");
        assert_msg(+m24f == Matrix2x4F(1), "matrix m24f operator+ failed");
        assert_msg(+m23f == Matrix2x3F(1), "matrix m23f operator+ failed");
        assert_msg(+m22f == Matrix2F(1), "matrix m22f operator+ failed");
    }

    return 0;
}
