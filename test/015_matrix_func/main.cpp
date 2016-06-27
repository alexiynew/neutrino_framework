#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{
    {
        mat4x4f m44;
        mat4x3f m43;
        mat4x2f m42;
        mat3x4f m34;
        mat3x3f m33;
        mat3x2f m32;
        mat2x4f m24;
        mat2x3f m23;
        mat2x2f m22;

        assert_msg(transpose(m44) == m44, "transpose m44 failed");
        assert_msg(transpose(m43) == m34, "transpose m43 failed");
        assert_msg(transpose(m42) == m24, "transpose m42 failed");

        assert_msg(transpose(m34) == m43, "transpose m34 failed");
        assert_msg(transpose(m33) == m33, "transpose m33 failed");
        assert_msg(transpose(m32) == m23, "transpose m32 failed");

        assert_msg(transpose(m24) == m42, "transpose m24 failed");
        assert_msg(transpose(m23) == m32, "transpose m23 failed");
        assert_msg(transpose(m22) == m22, "transpose m22 failed");
    }

    {
        mat4x4f m44(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

        mat4x3f m43(m44);
        mat4x2f m42(m44);
        mat3x4f m34(m44);
        mat3x3f m33(m44);
        mat3x2f m32(m44);
        mat2x4f m24(m44);
        mat2x3f m23(m44);
        mat2x2f m22(m44);

        mat4x4f r44(1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16);

        mat4x3f r43(r44);
        mat4x2f r42(r44);
        mat3x4f r34(r44);
        mat3x3f r33(r44);
        mat3x2f r32(r44);
        mat2x4f r24(r44);
        mat2x3f r23(r44);
        mat2x2f r22(r44);

        assert_msg(xcomp_mult(m44, m44) == r44, "xcomp_mult m44 failed");
        assert_msg(xcomp_mult(m43, m43) == r43, "xcomp_mult m43 failed");
        assert_msg(xcomp_mult(m42, m42) == r42, "xcomp_mult m42 failed");
        assert_msg(xcomp_mult(m34, m34) == r34, "xcomp_mult m34 failed");
        assert_msg(xcomp_mult(m33, m33) == r33, "xcomp_mult m33 failed");
        assert_msg(xcomp_mult(m32, m32) == r32, "xcomp_mult m32 failed");
        assert_msg(xcomp_mult(m24, m24) == r24, "xcomp_mult m24 failed");
        assert_msg(xcomp_mult(m23, m23) == r23, "xcomp_mult m23 failed");
        assert_msg(xcomp_mult(m22, m22) == r22, "xcomp_mult m22 failed");
    }

    {
        vec2f v2(1, 2);
        vec3f v3(1, 2, 3);
        vec4f v4(1, 2, 3, 4);

        assert_msg(outer_product(v2, v2) == mat2x2f(1, 2, 2, 4), "outer_product(v2, v2) failed");
        assert_msg(outer_product(v2, v3) == mat3x2f(1, 2, 2, 4, 3, 6), "outer_product(v2, v3) failed");
        assert_msg(outer_product(v2, v4) == mat4x2f(1, 2, 2, 4, 3, 6, 4, 8), "outer_product(v2, v4) failed");

        assert_msg(outer_product(v3, v2) == mat2x3f(1, 2, 3, 2, 4, 6), "outer_product(v3, v2) failed");
        assert_msg(outer_product(v3, v3) == mat3x3f(1, 2, 3, 2, 4, 6, 3, 6, 9), "outer_product(v3, v3) failed");
        assert_msg(outer_product(v3, v4) == mat4x3f(1, 2, 3, 2, 4, 6, 3, 6, 9, 4, 8, 12), "outer_product(v3, v4) "
                                                                                          "failed");

        assert_msg(outer_product(v4, v2) == mat2x4f(1, 2, 3, 4, 2, 4, 6, 8), "outer_product(v4, v2) failed");
        assert_msg(outer_product(v4, v3) == mat3x4f(1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12), "outer_product(v4, v3) "
                                                                                          "failed");
        assert_msg(outer_product(v4, v4) == mat4x4f(1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12, 4, 8, 12, 16),
                   "outer_product(v4, v4) failed");
    }

    {
        mat2f m2(1, 2, 1, 2);
        mat3f m3(1, 2, 3, 1, 2, 3, 1, 2, 3);
        mat4f m4(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

        assert_msg(almost_equal(determinant(mat2f()), 1.0f), "determinant faled");
        assert_msg(almost_equal(determinant(mat3f()), 1.0f), "determinant faled");
        assert_msg(almost_equal(determinant(mat4f()), 1.0f), "determinant faled");

        assert_msg(almost_equal(determinant(m2), 0.0f), "determinant faled");
        assert_msg(almost_equal(determinant(m3), 0.0f), "determinant faled");
        assert_msg(almost_equal(determinant(m3), 0.0f), "determinant faled");
    }

    {
        mat2f m2(4, 2, 2, 3);
        mat3f m3(8, 6, 7, 4, 2, 3, 1, 5, 2);
        mat4f m4(1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1);

        assert_msg(almost_equal(determinant(m2), 8.0f), "determinant faled");
        assert_msg(almost_equal(determinant(m3), 8.0f), "determinant faled");
        assert_msg(almost_equal(determinant(m4), -1.0f), "determinant faled");

        assert_msg(inverse(m2) * m2 == mat2x2f(), "inverse failed");
        assert_msg(inverse(m3) * m3 == mat3x3f(), "inverse failed");
        assert_msg(inverse(m4) * m4 == mat4x4f(), "inverse failed");

        assert_msg(almost_equal(determinant(inverse(m3)), 1.0f / determinant(m3)), "inverse determinant failed");
        assert_msg(almost_equal(determinant(inverse(m4)), 1.0f / determinant(m4)), "inverse determinant failed");
        assert_msg(almost_equal(determinant(inverse(m2)), 1.0f / determinant(m2)), "inverse determinant failed");
    }

    {
        mat3f m3(0, -1, 0, -1, 0, 0, 5, 5, 1);

        assert_msg(affine_inverse(m3) == inverse(m3), "matrix 3f affine inverse failed");
    }

    {
        mat4f m4(0.707f, 0.0f, -0.707f, 0.0f, 0.354f, 0.866f, 0.354f, 0.0f, 0.612f, -0.5f, 0.612f, 0.0f, 1.0f, 1.0f, 4.0f, 1.0f);

        auto a = affine_inverse(m4);
        auto b = inverse(m4);

        assert_msg(almost_equal(a[0], b[0]) && almost_equal(a[1], b[1]) && almost_equal(a[2], b[2]) && almost_equal(a[3], b[3]), "matrix 4f affine inverse failed");
    }

    {
        mat2f m2(4, 2, 2, 3);
        mat3f m3(8, 6, 7, 4, 2, 3, 1, 5, 2);
        mat4f m4(1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1);

        assert_msg(transpose(inverse(m2)) == inverse_transpose(m2), "mat2 inverse_transpose failed");
        assert_msg(transpose(inverse(m3)) == inverse_transpose(m3), "mat3 inverse_transpose failed");
        assert_msg(transpose(inverse(m4)) == inverse_transpose(m4), "mat4 inverse_transpose failed");
    }

    return 0;
}
