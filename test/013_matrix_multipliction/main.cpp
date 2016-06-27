#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix * vector, vector * matrix multiply
    {
        mat4f m44f(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

        mat4x3f m43f(m44f);
        mat4x2f m42f(m44f);
        mat3x4f m34f(m44f);
        mat3f m33f(m44f);
        mat3x2f m32f(m44f);
        mat2x4f m24f(m44f);
        mat2x3f m23f(m44f);
        mat2f m22f(m44f);

        vec4f v4f(1, 2, 3, 4);
        vec3f v3f(1, 2, 3);
        vec2f v2f(1, 2);

        assert_msg(v4f * m44f == vec4f(30, 30, 30, 30), "vec4f * mat44f failed");
        assert_msg(v4f * m34f == vec3f(30, 30, 30), "vec4f * mat34f failed");
        assert_msg(v4f * m24f == vec2f(30, 30), "vec4f * mat24f failed");

        assert_msg(v3f * m43f == vec4f(14, 14, 14, 14), "vec3f * mat43f failed");
        assert_msg(v3f * m33f == vec3f(14, 14, 14), "vec3f * mat33f failed");
        assert_msg(v3f * m23f == vec2f(14, 14), "vec3f * mat23f failed");

        assert_msg(v2f * m42f == vec4f(5, 5, 5, 5), "vec2f * mat42f failed");
        assert_msg(v2f * m32f == vec3f(5, 5, 5), "vec2f * mat32f failed");
        assert_msg(v2f * m22f == vec2f(5, 5), "vec2f * mat22f failed");

        assert_msg(m44f * v4f == vec4f(10, 20, 30, 40), "mat44f * vec4f failed");
        assert_msg(m43f * v4f == vec3f(10, 20, 30), "mat43f * vec4f failed");
        assert_msg(m42f * v4f == vec2f(10, 20), "mat42f * vec4f failed");

        assert_msg(m34f * v3f == vec4f(6, 12, 18, 24), "mat34f * vec3f failed");
        assert_msg(m33f * v3f == vec3f(6, 12, 18), "mat33f * vec3f failed");
        assert_msg(m32f * v3f == vec2f(6, 12), "mat32f * vec3f failed");

        assert_msg(m24f * v2f == vec4f(3, 6, 9, 12), "mat24f * vec2f failed");
        assert_msg(m23f * v2f == vec3f(3, 6, 9), "mat23f * vec2f failed");
        assert_msg(m22f * v2f == vec2f(3, 6), "mat22f * vec2f failed");
    }

    // martix multiplying
    {
        mat4f m44f(1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1);

        mat4x3f m43f(1, 2, 3, 3, 1, 2, 2, 3, 1, 1, 2, 3);

        mat4x2f m42f(1, 2, 2, 1, 1, 2, 2, 1);

        mat3x4f m34f(1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2);

        mat3f m33f(1, 2, 3, 3, 1, 2, 2, 3, 1);

        mat3x2f m32f(1, 2, 2, 1, 1, 2);

        mat2x4f m24f(1, 2, 3, 4, 4, 1, 2, 3);

        mat2x3f m23f(1, 2, 3, 4, 1, 2);

        mat2f m22f(1, 2, 4, 1);

        assert_msg(m44f * m44f == mat4f(26, 28, 26, 20, 20, 26, 28, 26, 26, 20, 26, 28, 28, 26, 20, 26),
                   "matrix m44f * m44f failed");

        assert_msg(m44f * m34f == mat3x4f(26, 28, 26, 20, 20, 26, 28, 26, 26, 20, 26, 28), "matrix m44f * m34f failed");

        assert_msg(m44f * m24f == mat2x4f(26, 28, 26, 20, 20, 26, 28, 26), "matrix m44f * m24f failed");

        assert_msg(m43f * m44f == mat4x3f(17, 21, 22, 14, 21, 25, 19, 17, 24, 20, 21, 19), "matrix m43f * m44f failed");

        assert_msg(m43f * m34f == mat3f(17, 21, 22, 14, 21, 25, 19, 17, 24), "matrix m43f * m34f failed");

        assert_msg(m43f * m24f == mat2x3f(17, 21, 22, 14, 21, 25), "matrix m43f * m24f failed");

        assert_msg(m42f * m44f == mat4x2f(16, 14, 14, 16, 16, 14, 14, 16), "matrix m42f * m44f failed");

        assert_msg(m42f * m34f == mat3x2f(16, 14, 14, 16, 16, 14), "matrix m42f * m34f failed");

        assert_msg(m42f * m24f == mat2f(16, 14, 14, 16), "matrix m42f * m24f failed");

        assert_msg(m34f * m43f == mat4f(18, 16, 10, 16, 13, 15, 13, 19, 17, 11, 13, 19, 18, 16, 10, 16),
                   "matrix m34f * m43f failed");

        assert_msg(m34f * m33f == mat3x4f(18, 16, 10, 16, 13, 15, 13, 19, 17, 11, 13, 19), "matrix m34f * m33f failed");

        assert_msg(m34f * m23f == mat2x4f(18, 16, 10, 16, 14, 17, 16, 23), "matrix m34f * m23f failed");

        assert_msg(m33f * m43f == mat4x3f(13, 13, 10, 10, 13, 13, 13, 10, 13, 13, 13, 10), "matrix m33f * m43f failed");

        assert_msg(m33f * m33f == mat3f(13, 13, 10, 10, 13, 13, 13, 10, 13), "matrix m33f * m33f failed");

        assert_msg(m33f * m23f == mat2x3f(13, 13, 10, 11, 15, 16), "matrix m33f * m23f failed");

        assert_msg(m32f * m43f == mat4x2f(8, 10, 7, 11, 9, 9, 8, 10), "matrix m32f * m43f failed");

        assert_msg(m32f * m33f == mat3x2f(8, 10, 7, 11, 9, 9), "matrix m32f * m33f failed");

        assert_msg(m32f * m23f == mat2f(8, 10, 8, 13), "matrix m32f * m23f failed");

        assert_msg(m24f * m42f == mat4f(9, 4, 7, 10, 6, 5, 8, 11, 9, 4, 7, 10, 6, 5, 8, 11), "matrix m24f * m42f "
                                                                                             "failed");

        assert_msg(m24f * m32f == mat3x4f(9, 4, 7, 10, 6, 5, 8, 11, 9, 4, 7, 10), "matrix m24f * m32f failed");

        assert_msg(m24f * m22f == mat2x4f(9, 4, 7, 10, 8, 9, 14, 19), "matrix m24f * m22f failed");

        assert_msg(m23f * m42f == mat4x3f(9, 4, 7, 6, 5, 8, 9, 4, 7, 6, 5, 8), "matrix m23f * m42f failed");

        assert_msg(m23f * m32f == mat3f(9, 4, 7, 6, 5, 8, 9, 4, 7), "matrix m23f * m32f failed");

        assert_msg(m23f * m22f == mat2x3f(9, 4, 7, 8, 9, 14), "matrix m23f * m22f failed");

        assert_msg(m22f * m42f == mat4x2f(9, 4, 6, 5, 9, 4, 6, 5), "matrix m22f * m42f failed");

        assert_msg(m22f * m32f == mat3x2f(9, 4, 6, 5, 9, 4), "matrix m22f * m32f failed");

        assert_msg(m22f * m22f == mat2f(9, 4, 8, 9), "matrix m22f * m22f failed");
    }

    return 0;
}
