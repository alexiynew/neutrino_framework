#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix assign
    {
        mat4f m44f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        mat4x3f m43f(m44f);
        mat4x2f m42f(m44f);
        mat3x4f m34f(m44f);
        mat3f m33f(m44f);
        mat3x2f m32f(m44f);
        mat2x4f m24f(m44f);
        mat2x3f m23f(m44f);
        mat2f m22f(m44f);

        mat4x2f n42f;
        mat4x3f n43f;
        mat4f n44f;
        mat3x2f n32f;
        mat3f n33f;
        mat3x4f n34f;
        mat2f n22f;
        mat2x3f n23f;
        mat2x4f n24f;

        n44f = m44f;
        n43f = m43f;
        n42f = m42f;
        n34f = m34f;
        n33f = m33f;
        n32f = m32f;
        n24f = m24f;
        n23f = m23f;
        n22f = m22f;

        assert_msg(n44f == m44f, "matrix assign n44f == m44f failed");
        assert_msg(n43f == m43f, "matrix assign n43f == m43f failed");
        assert_msg(n42f == m42f, "matrix assign n42f == m42f failed");
        assert_msg(n34f == m34f, "matrix assign n34f == m34f failed");
        assert_msg(n33f == m33f, "matrix assign n33f == m33f failed");
        assert_msg(n32f == m32f, "matrix assign n32f == m32f failed");
        assert_msg(n24f == m24f, "matrix assign n24f == m24f failed");
        assert_msg(n23f == m23f, "matrix assign n23f == m23f failed");
        assert_msg(n22f == m22f, "matrix assign n22f == m22f failed");

        mat4x2d n42d;
        mat4x3d n43d;
        mat4d n44d;
        mat3x2d n32d;
        mat3d n33d;
        mat3x4d n34d;
        mat2d n22d;
        mat2x3d n23d;
        mat2x4d n24d;

        n44d = m44f;
        n43d = m43f;
        n42d = m42f;
        n34d = m34f;
        n33d = m33f;
        n32d = m32f;
        n24d = m24f;
        n23d = m23f;
        n22d = m22f;

        assert_msg(n44d == mat4d(m44f), "matrix assign n44d == m44f failed");
        assert_msg(n43d == mat4x3d(m43f), "matrix assign n43d == m43f failed");
        assert_msg(n42d == mat4x2d(m42f), "matrix assign n42d == m42f failed");
        assert_msg(n34d == mat3x4d(m34f), "matrix assign n34d == m34f failed");
        assert_msg(n33d == mat3d(m33f), "matrix assign n33d == m33f failed");
        assert_msg(n32d == mat3x2d(m32f), "matrix assign n32d == m32f failed");
        assert_msg(n24d == mat2x4d(m24f), "matrix assign n24d == m24f failed");
        assert_msg(n23d == mat2x3d(m23f), "matrix assign n23d == m23f failed");
        assert_msg(n22d == mat2d(m22f), "matrix assign n22d == m22f failed");
    }
    return 0;
}
