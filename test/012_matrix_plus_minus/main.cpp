#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix +=, -= matrix
    {
        mat4f m44f;
        mat4x3f m43f;
        mat4x2f m42f;
        mat3x4f m34f;
        mat3f m33f;
        mat3x2f m32f;
        mat2x4f m24f;
        mat2x3f m23f;
        mat2f m22f;

        m44f += m44f;
        m43f += m43f;
        m42f += m42f;
        m34f += m34f;
        m33f += m33f;
        m32f += m32f;
        m24f += m24f;
        m23f += m23f;
        m22f += m22f;

        assert_msg(m44f == mat4f(2), "matrix m44f += failed");
        assert_msg(m43f == mat4x3f(2), "matrix m43f += failed");
        assert_msg(m42f == mat4x2f(2), "matrix m42f += failed");
        assert_msg(m34f == mat3x4f(2), "matrix m34f += failed");
        assert_msg(m33f == mat3f(2), "matrix m33f += failed");
        assert_msg(m32f == mat3x2f(2), "matrix m32f += failed");
        assert_msg(m24f == mat2x4f(2), "matrix m24f += failed");
        assert_msg(m23f == mat2x3f(2), "matrix m23f += failed");
        assert_msg(m22f == mat2f(2), "matrix m22f += failed");

        m44f -= m44f;
        m43f -= m43f;
        m42f -= m42f;
        m34f -= m34f;
        m33f -= m33f;
        m32f -= m32f;
        m24f -= m24f;
        m23f -= m23f;
        m22f -= m22f;

        assert_msg(m44f == mat4f(0), "matrix m44f -= failed");
        assert_msg(m43f == mat4x3f(0), "matrix m43f -= failed");
        assert_msg(m42f == mat4x2f(0), "matrix m42f -= failed");
        assert_msg(m34f == mat3x4f(0), "matrix m34f -= failed");
        assert_msg(m33f == mat3f(0), "matrix m33f -= failed");
        assert_msg(m32f == mat3x2f(0), "matrix m32f -= failed");
        assert_msg(m24f == mat2x4f(0), "matrix m24f -= failed");
        assert_msg(m23f == mat2x3f(0), "matrix m23f -= failed");
        assert_msg(m22f == mat2f(0), "matrix m22f -= failed");
    }

    // matrix unary minus and unary plus
    {
        mat4f m44f;
        mat4x3f m43f;
        mat4x2f m42f;
        mat3x4f m34f;
        mat3f m33f;
        mat3x2f m32f;
        mat2x4f m24f;
        mat2x3f m23f;
        mat2f m22f;

        assert_msg(-m44f == mat4f(-1), "matrix m44f operator- failed");
        assert_msg(-m43f == mat4x3f(-1), "matrix m43f operator- failed");
        assert_msg(-m42f == mat4x2f(-1), "matrix m42f operator- failed");
        assert_msg(-m34f == mat3x4f(-1), "matrix m34f operator- failed");
        assert_msg(-m33f == mat3f(-1), "matrix m33f operator- failed");
        assert_msg(-m32f == mat3x2f(-1), "matrix m32f operator- failed");
        assert_msg(-m24f == mat2x4f(-1), "matrix m24f operator- failed");
        assert_msg(-m23f == mat2x3f(-1), "matrix m23f operator- failed");
        assert_msg(-m22f == mat2f(-1), "matrix m22f operator- failed");

        assert_msg(+m44f == mat4f(1), "matrix m44f operator+ failed");
        assert_msg(+m43f == mat4x3f(1), "matrix m43f operator+ failed");
        assert_msg(+m42f == mat4x2f(1), "matrix m42f operator+ failed");
        assert_msg(+m34f == mat3x4f(1), "matrix m34f operator+ failed");
        assert_msg(+m33f == mat3f(1), "matrix m33f operator+ failed");
        assert_msg(+m32f == mat3x2f(1), "matrix m32f operator+ failed");
        assert_msg(+m24f == mat2x4f(1), "matrix m24f operator+ failed");
        assert_msg(+m23f == mat2x3f(1), "matrix m23f operator+ failed");
        assert_msg(+m22f == mat2f(1), "matrix m22f operator+ failed");
    }

    return 0;
}
