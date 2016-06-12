#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;



int main()
{

    // matrix size, default constructor and one argument constructor test
    {
        constexpr mat2f m2;
        constexpr mat2x3f m23;
        constexpr mat2x4f m24;

        constexpr mat3f m3;
        constexpr mat3x2f m32;
        constexpr mat3x4f m34;

        constexpr mat4f m4;
        constexpr mat4x2f m42;
        constexpr mat4x3f m43;

        static_assert(sizeof(m2) == sizeof(float) * 2 * 2 && m2.size() == 2, "matrix size assert_msg");
        static_assert(sizeof(m23) == sizeof(float) * 2 * 3 && m23.size() == 2, "matrix size assert_msg");
        static_assert(sizeof(m24) == sizeof(float) * 2 * 4 && m24.size() == 2, "matrix size assert_msg");

        static_assert(sizeof(m3) == sizeof(float) * 3 * 3 && m3.size() == 3, "matrix size assert_msg");
        static_assert(sizeof(m32) == sizeof(float) * 3 * 2 && m32.size() == 3, "matrix size assert_msg");
        static_assert(sizeof(m34) == sizeof(float) * 3 * 4 && m34.size() == 3, "matrix size assert_msg");

        static_assert(sizeof(m4) == sizeof(float) * 4 * 4 && m4.size() == 4, "matrix size assert_msg");
        static_assert(sizeof(m42) == sizeof(float) * 4 * 2 && m42.size() == 4, "matrix size assert_msg");
        static_assert(sizeof(m43) == sizeof(float) * 4 * 3 && m43.size() == 4, "matrix size assert_msg");

        assert_msg(m2 == mat2f(1, 0, 0, 1), "matrix2 default constructor");

        assert_msg(m23 == mat2x3f(1, 0, 0, 0, 1, 0), "matrix2x3 default constructor");

        assert_msg(m24 == mat2x4f(1, 0, 0, 0, 0, 1, 0, 0), "matrix2x4 default constructor");

        assert_msg(m3 == mat3f(1, 0, 0, 0, 1, 0, 0, 0, 1), "matrix3 default constructor");

        assert_msg(m32 == mat3x2f(1, 0, 0, 1, 0, 0), "matrix3x2 default constructor");

        assert_msg(m34 == mat3x4f(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0), "matrix3x4 default constructor");

        assert_msg(m4 == mat4f(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), "matrix4 default constructor");

        assert_msg(m42 == mat4x2f(1, 0, 0, 1, 0, 0, 0, 0), "matrix4x2 default constructor");

        assert_msg(m43 == mat4x3f(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), "matrix4x3 default constructor");

        assert_msg(m2 == mat2f(1), "matrix2 one argument constructor");
        assert_msg(m23 == mat2x3f(1), "matrix2x3 one argument constructor");
        assert_msg(m24 == mat2x4f(1), "matrix2x4 one argument constructor");

        assert_msg(m3 == mat3f(1), "matrix3 one argument constructor");
        assert_msg(m32 == mat3x2f(1), "matrix3x2 one argument constructor");
        assert_msg(m34 == mat3x4f(1), "matrix3x4 one argument constructor");

        assert_msg(m4 == mat4f(1), "matrix4 one argument constructor");
        assert_msg(m42 == mat4x2f(1), "matrix4x2 one argument constructor");
        assert_msg(m43 == mat4x3f(1), "matrix4x3 one argument constructor");
    }

    // matrix from pinter costructor
    {
        F64 data4[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
        F64 data3[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        F64 data2[] = {0, 1, 0, 1, 0, 1, 0, 1};

        mat4x4d m44(data4);
        mat3x4d m34(data4);
        mat2x4d m24(data4);

        mat4x3d m43(data3);
        mat3x3d m33(data3);
        mat2x3d m23(data3);

        mat4x2d m42(data2);
        mat3x2d m32(data2);
        mat2x2d m22(data2);

        assert_msg(m44 == mat4x4d(vec4d(0, 1, 2, 3), vec4d(0, 1, 2, 3), vec4d(0, 1, 2, 3), vec4d(0, 1, 2, 3)), "matrix4x4 from pointer constructor");
        assert_msg(m34 == mat3x4d(vec4d(0, 1, 2, 3), vec4d(0, 1, 2, 3), vec4d(0, 1, 2, 3)), "matrix3x4 from pointer constructor");
        assert_msg(m24 == mat2x4d(vec4d(0, 1, 2, 3), vec4d(0, 1, 2, 3)), "matrix2x4 from pointer constructor");

        assert_msg(m43 == mat4x3d(vec3d(0, 1, 2), vec3d(0, 1, 2), vec3d(0, 1, 2), vec3d(0, 1, 2)), "matrix4x3 from pointer constructor");
        assert_msg(m33 == mat3x3d(vec3d(0, 1, 2), vec3d(0, 1, 2), vec3d(0, 1, 2)), "matrix3x3 from pointer constructor");
        assert_msg(m23 == mat2x3d(vec3d(0, 1, 2), vec3d(0, 1, 2)), "matrix2x3 from pointer constructor");

        assert_msg(m42 == mat4x2d(vec2d(0, 1), vec2d(0, 1), vec2d(0, 1), vec2d(0, 1)), "matrix4x3 from pointer constructor");
        assert_msg(m32 == mat3x2d(vec2d(0, 1), vec2d(0, 1), vec2d(0, 1)), "matrix3x3 from pointer constructor");
        assert_msg(m22 == mat2x2d(vec2d(0, 1), vec2d(0, 1)), "matrix2x3 from pointer constructor");

        F64* p44 = m44.data();
        F64* p34 = m34.data();
        F64* p24 = m24.data();

        F64* p43 = m43.data();
        F64* p33 = m33.data();
        F64* p23 = m23.data();

        F64* p42 = m42.data();
        F64* p32 = m32.data();
        F64* p22 = m22.data();

        assert_msg(p44[0]  == 0.0 && p44[1]  == 1.0 && p44[2]  == 2.0 && p44[3]  == 3.0 &&
                   p44[4]  == 0.0 && p44[5]  == 1.0 && p44[6]  == 2.0 && p44[7]  == 3.0 &&
                   p44[8]  == 0.0 && p44[9]  == 1.0 && p44[10] == 2.0 && p44[11] == 3.0 &&
                   p44[12] == 0.0 && p44[13] == 1.0 && p44[14] == 2.0 && p44[15] == 3.0, "matrix4x4 pointer access");
        assert_msg(p34[0]  == 0.0 && p34[1]  == 1.0 && p34[2]  == 2.0 && p34[3]  == 3.0 &&
                   p34[4]  == 0.0 && p34[5]  == 1.0 && p34[6]  == 2.0 && p34[7]  == 3.0 &&
                   p34[8]  == 0.0 && p34[9]  == 1.0 && p34[10] == 2.0 && p34[11] == 3.0, "matrix3x4 pointer access");
        assert_msg(p24[0]  == 0.0 && p24[1]  == 1.0 && p24[2]  == 2.0 && p24[3]  == 3.0 &&
                   p24[4]  == 0.0 && p24[5]  == 1.0 && p24[6]  == 2.0 && p24[7]  == 3.0, "matrix2x4 pointer access");

        assert_msg(p43[0] == 0.0 && p43[1]  == 1.0 && p43[2]  == 2.0 &&
                   p43[3] == 0.0 && p43[4]  == 1.0 && p43[5]  == 2.0 &&
                   p43[6] == 0.0 && p43[7]  == 1.0 && p43[8]  == 2.0 &&
                   p43[9] == 0.0 && p43[10] == 1.0 && p43[11] == 2.0, "matrix4x3 pointer access");
        assert_msg(p33[0] == 0.0 && p33[1]  == 1.0 && p33[2]  == 2.0 &&
                   p33[3] == 0.0 && p33[4]  == 1.0 && p33[5]  == 2.0 &&
                   p33[6] == 0.0 && p33[7]  == 1.0 && p33[8]  == 2.0, "matrix3x3 pointer access");
        assert_msg(p23[0] == 0.0 && p23[1]  == 1.0 && p23[2]  == 2.0 &&
                   p23[3] == 0.0 && p23[4]  == 1.0 && p23[5]  == 2.0, "matrix2x3 pointer access");

        assert_msg(p42[0] == 0.0 && p42[1] == 1.0 &&
                   p42[2] == 0.0 && p42[3] == 1.0 &&
                   p42[4] == 0.0 && p42[5] == 1.0 &&
                   p42[6] == 0.0 && p42[7] == 1.0, "matrix4x2 pointer access");
        assert_msg(p32[0] == 0.0 && p32[1] == 1.0 &&
                   p32[2] == 0.0 && p32[3] == 1.0 &&
                   p32[4] == 0.0 && p32[5] == 1.0, "matrix3x2 pointer access");
        assert_msg(p22[0] == 0.0 && p22[1] == 1.0 &&
                   p22[2] == 0.0 && p22[3] == 1.0, "matrix2x2 pointer access");
    }

    // mat4f from vectors constructor
    {
        constexpr mat4f m(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        assert_msg(mat4f(vec4d(0, 1, 2, 3), vec4f(0, 1, 2, 3), vec4f(0, 1, 2, 3), vec4i(0, 1, 2, 3)) == m,
                   "matrix4 vector constructor");

        assert_msg(mat4f(vec3i(0, 1, 2), 3, vec3f(0, 1, 2), 3, vec3d(0, 1, 2), 3, vec3f(0, 1, 2), 3) == m,
                   "matrix4 vector constructor");

        assert_msg(mat4f(0, vec3f(1, 2, 3), 0, vec3d(1, 2, 3), 0, vec3f(1, 2, 3), 0, vec3i(1, 2, 3)) == m,
                   "matrix4 vector constructor");

        assert_msg(mat4f(vec2f(0, 1), vec2d(2, 3), vec2d(0, 1), vec2f(2, 3), vec2f(0, 1), vec2i(2, 3), vec2i(0, 1), vec2f(2, 3)) == m, "matrix4 vector constructor");

        assert_msg(mat4f(vec2d(0, 1), 2, 3, vec2f(0, 1), 2, 3, vec2i(0, 1), 2, 3, vec2f(0, 1), 2, 3) == m,
                   "matrix4 vector constructor");

        assert_msg(mat4f(0, vec2d(1, 2), 3, 0, vec2f(1, 2), 3, 0, vec2i(1, 2), 3, 0, vec2f(1, 2), 3) == m,
                   "matrix4 vector constructor");

        assert_msg(mat4f(0, 1, vec2d(2, 3), 0, 1, vec2f(2, 3), 0, 1, vec2i(2, 3), 0, 1, vec2f(2, 3)) == m,
                   "matrix4 vector constructor");
    }

    // mat4x3f from vectors constructor
    {
        constexpr mat4x3f m(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2);

        assert_msg(mat4x3f(vec4f(0, 1, 2, 3), vec4d(0, 1, 2, 3), vec4i(0, 1, 2, 3), vec4f(0, 1, 2, 3)) == m,
                   "matrix4x3 vector constructor");

        assert_msg(mat4x3f(vec3f(0, 1, 2), vec3f(0, 1, 2), vec3d(0, 1, 2), vec3i(0, 1, 2)) == m, "matrix4x3 vector "
                                                                                                 "constructor");

        assert_msg(mat4x3f(vec2f(0, 1), 2, vec2f(0, 1), 2, vec2d(0, 1), 2, vec2i(0, 1), 2) == m, "matrix4x3 vector "
                                                                                                 "constructor");

        assert_msg(mat4x3f(0, vec2f(1, 2), 0, vec2f(1, 2), 0, vec2d(1, 2), 0, vec2i(1, 2)) == m, "matrix4x3 vector "
                                                                                                 "constructor");
    }

    // mat4x2f from vectors constructor
    {
        constexpr mat4x2f m(0, 1, 0, 1, 0, 1, 0, 1);

        assert_msg(mat4x2f(vec4d(0, 1, 2, 3), vec4f(0, 1, 2, 3), vec4f(0, 1, 2, 3), vec4i(0, 1, 2, 3)) == m,
                   "matrix4x2 vector constructor");

        assert_msg(mat4x2f(vec3f(0, 1, 2), vec3i(0, 1, 2), vec3d(0, 1, 2), vec3f(0, 1, 2)) == m, "matrix4x2 vector "
                                                                                                 "constructor");
    }

    // mat3x4f from vectors constructor
    {
        constexpr mat3x4f m(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        assert_msg(mat3x4f(vec4d(0, 1, 2, 3), vec4f(0, 1, 2, 3), vec4i(0, 1, 2, 3)) == m, "matrix3x4 vector "
                                                                                          "constructor");

        assert_msg(mat3x4f(vec3i(0, 1, 2), 3, vec3f(0, 1, 2), 3, vec3d(0, 1, 2), 3) == m, "matrix3x4 vector "
                                                                                          "constructor");

        assert_msg(mat3x4f(0.0, vec3f(1, 2, 3), 0, vec3f(1, 2, 3), 0, vec3i(1, 2, 3)) == m, "matrix3x4 vector "
                                                                                            "constructor");

        assert_msg(mat3x4f(vec2i(0, 1), vec2i(2, 3), vec2f(0, 1), vec2d(2, 3), vec2d(0, 1), vec2f(2, 3)) == m,
                   "matrix3x4 vector constructor");

        assert_msg(mat3x4f(vec2i(0, 1), 2, 3, vec2f(0, 1), 2, 3, vec2d(0, 1), 2, 3) == m, "matrix3x4 vector "
                                                                                          "constructor");

        assert_msg(mat3x4f(0, vec2i(1, 2), 3, 0, vec2d(1, 2), 3, 0, vec2f(1, 2), 3) == m, "matrix3x4 vector "
                                                                                          "constructor");

        assert_msg(mat3x4f(0, 1.0, vec2f(2, 3), 0, 1.0, vec2f(2, 3), 0, 1.0, vec2f(2, 3)) == m, "matrix3x4 vector "
                                                                                                "constructor");
    }

    // mat3f from vectors constructor
    {
        constexpr mat3f m(0, 1, 2, 0, 1, 2, 0, 1, 2);

        assert_msg(mat3f(vec4i(0, 1, 2, 3), vec4d(0, 1, 2, 3), vec4f(0, 1, 2, 3)) == m, "matrix3 vector constructor");

        assert_msg(mat3f(vec3f(0, 1, 2), vec3i(0, 1, 2), vec3d(0, 1, 2)) == m, "matrix3 vector constructor");

        assert_msg(mat3f(vec2i(0, 1), 2, vec2d(0, 1), 2, vec2f(0, 1), 2) == m, "matrix3 vector constructor");

        assert_msg(mat3f(0, vec2d(1, 2), 0, vec2i(1, 2), 0, vec2f(1, 2)) == m, "matrix3 vector constructor");
    }

    // mat3x2f from vectors constructor
    {
        constexpr mat3x2f m(0, 1, 0, 1, 0, 1);

        assert_msg(mat3x2f(vec4f(0, 1, 2, 3), vec4i(0, 1, 2, 3), vec4d(0, 1, 2, 3)) == m, "matrix3x2 vector "
                                                                                          "constructor");

        assert_msg(mat3x2f(vec3i(0, 1, 2), vec3d(0, 1, 2), vec3f(0, 1, 2)) == m, "matrix3x2 vector constructor");
    }

    // mat2x4f from vectors constructor
    {
        constexpr mat2x4f m(0, 1, 2, 3, 0, 1, 2, 3);

        assert_msg(mat2x4f(vec4f(0, 1, 2, 3), vec4f(0, 1, 2, 3)) == m, "matrix2x4 vector constructor");

        assert_msg(mat2x4f(vec3f(0, 1, 2), 3, vec3d(0, 1, 2), 3) == m, "matrix2x4 vector constructor");

        assert_msg(mat2x4f(0, vec3f(1, 2, 3), 0, vec3d(1, 2, 3)) == m, "matrix2x4 vector constructor");

        assert_msg(mat2x4f(vec2f(0, 1), vec2f(2, 3), vec2i(0, 1), vec2f(2, 3)) == m, "matrix2x4 vector constructor");

        assert_msg(mat2x4f(vec2f(0, 1), 2, 3, vec2d(0, 1), 2, 3) == m, "matrix2x4 vector constructor");

        assert_msg(mat2x4f(0, vec2f(1, 2), 3, 0, vec2i(1, 2), 3) == m, "matrix2x4 vector constructor");

        assert_msg(mat2x4f(0, 1, vec2f(2, 3), 0, 1, vec2d(2, 3)) == m, "matrix2x4 vector constructor");
    }

    // mat2x3f from vectors constructor
    {
        constexpr mat2x3f m(0, 1, 2, 0, 1, 2);

        assert_msg(mat2x3f(vec4d(0, 1, 2, 3), vec4f(0, 1, 2, 3)) == m, "matrix2x3 vector constructor");

        assert_msg(mat2x3f(vec3i(0, 1, 2), vec3f(0, 1, 2)) == m, "matrix2x3 vector constructor");

        assert_msg(mat2x3f(vec2d(0, 1), 2, vec2f(0, 1), 2) == m, "matrix2x3 vector constructor");

        assert_msg(mat2x3f(0, vec2f(1, 2), 0, vec2i(1, 2)) == m, "matrix2x3 vector constructor");
    }

    // mat2f from vectors constructor
    {
        constexpr mat2f m(0, 1, 0, 1);

        assert_msg(mat2f(vec4f(0, 1, 2, 3), vec4i(0, 1, 2, 3)) == m, "matrix2 vector constructor");

        assert_msg(mat2f(vec3d(0, 1, 2), vec3f(0, 1, 2)) == m, "matrix2 vector constructor");
    }

    // matrix from matrix constructor
    {
        constexpr mat4f m44f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        constexpr mat4x3f m43f(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2);

        constexpr mat4x2f m42f(0, 1, 0, 1, 0, 1, 0, 1);

        constexpr mat3x4f m34f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        constexpr mat3f m33f(0, 1, 2, 0, 1, 2, 0, 1, 2);

        constexpr mat3x2f m32f(0, 1, 0, 1, 0, 1);

        constexpr mat2x4f m24f(0, 1, 2, 3, 0, 1, 2, 3);

        constexpr mat2x3f m23f(0, 1, 2, 0, 1, 2);

        constexpr mat2f m22f(0, 1, 0, 1);

        // mat 4x4
        assert_msg(mat4d(m44f) == mat4d(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3), "matrix4d mat4f constructor");

        assert_msg(mat4d(m43f) == mat4d(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 1), "matrix4d mat4x3f "
                                                                                         "constructor");

        assert_msg(mat4d(m42f) == mat4d(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1), "matrix4d mat4x2f "
                                                                                         "constructor");

        assert_msg(mat4d(m34f) == mat4d(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 0, 1), "matrix4d mat3x4f "
                                                                                         "constructor");

        assert_msg(mat4d(m33f) == mat4d(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 0, 1), "matrix4d mat3f constructor");

        assert_msg(mat4d(m32f) == mat4d(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1), "matrix4d mat3x2f "
                                                                                         "constructor");

        assert_msg(mat4d(m24f) == mat4d(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0, 0, 0, 0, 1), "matrix4d mat2x4f "
                                                                                         "constructor");

        assert_msg(mat4d(m23f) == mat4d(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1), "matrix4d mat2x3f "
                                                                                         "constructor");

        assert_msg(mat4d(m22f) == mat4d(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), "matrix4d mat2f constructor");

        // mat 4x3
        assert_msg(mat4x3d(m44f) == mat4x3d(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix4x3d mat4f constructor");

        assert_msg(mat4x3d(m43f) == mat4x3d(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix4x3d mat4x3f constructor");

        assert_msg(mat4x3d(m42f) == mat4x3d(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0), "matrix4x3d mat4x2f constructor");

        assert_msg(mat4x3d(m34f) == mat4x3d(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0), "matrix4x3d mat3x4f constructor");

        assert_msg(mat4x3d(m33f) == mat4x3d(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0), "matrix4x3d mat3f constructor");

        assert_msg(mat4x3d(m32f) == mat4x3d(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0), "matrix4x3d mat3x2f constructor");

        assert_msg(mat4x3d(m24f) == mat4x3d(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0), "matrix4x3d mat2x4f constructor");

        assert_msg(mat4x3d(m23f) == mat4x3d(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0), "matrix4x3d mat2x3f constructor");

        assert_msg(mat4x3d(m22f) == mat4x3d(0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), "matrix4x3d mat2f constructor");

        // mat 4x2
        assert_msg(mat4x2d(m44f) == mat4x2d(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d mat4f constructor");

        assert_msg(mat4x2d(m43f) == mat4x2d(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d mat4x3f constructor");

        assert_msg(mat4x2d(m42f) == mat4x2d(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d mat4x2f constructor");

        assert_msg(mat4x2d(m34f) == mat4x2d(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d mat3x4f constructor");

        assert_msg(mat4x2d(m33f) == mat4x2d(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d mat3f constructor");

        assert_msg(mat4x2d(m32f) == mat4x2d(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d mat3x2f constructor");

        assert_msg(mat4x2d(m24f) == mat4x2d(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d mat2x4f constructor");

        assert_msg(mat4x2d(m23f) == mat4x2d(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d mat2x3f constructor");

        assert_msg(mat4x2d(m22f) == mat4x2d(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d mat2f constructor");

        // mat 3x4
        assert_msg(mat3x4d(m44f) == mat3x4d(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3), "matrix3x4d mat4f constructor");

        assert_msg(mat3x4d(m43f) == mat3x4d(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0), "matrix3x4d mat4x3f constructor");

        assert_msg(mat3x4d(m42f) == mat3x4d(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0), "matrix3x4d mat4x2f constructor");

        assert_msg(mat3x4d(m34f) == mat3x4d(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3), "matrix3x4d mat3x4f constructor");

        assert_msg(mat3x4d(m33f) == mat3x4d(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0), "matrix3x4d mat3f constructor");

        assert_msg(mat3x4d(m32f) == mat3x4d(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0), "matrix3x4d mat3x2f constructor");

        assert_msg(mat3x4d(m24f) == mat3x4d(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0), "matrix3x4d mat2x4f constructor");

        assert_msg(mat3x4d(m23f) == mat3x4d(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0), "matrix3x4d mat2x3f constructor");

        assert_msg(mat3x4d(m22f) == mat3x4d(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0), "matrix3x4d mat2f constructor");

        // mat 3
        assert_msg(mat3d(m44f) == mat3d(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d mat4f constructor");

        assert_msg(mat3d(m43f) == mat3d(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d mat4x3f constructor");

        assert_msg(mat3d(m42f) == mat3d(0, 1, 0, 0, 1, 0, 0, 1, 1), "matrix3d mat4x2f constructor");

        assert_msg(mat3d(m34f) == mat3d(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d mat3x4f constructor");

        assert_msg(mat3d(m33f) == mat3d(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d mat3f constructor");

        assert_msg(mat3d(m32f) == mat3d(0, 1, 0, 0, 1, 0, 0, 1, 1), "matrix3d mat3x2f constructor");

        assert_msg(mat3d(m24f) == mat3d(0, 1, 2, 0, 1, 2, 0, 0, 1), "matrix3d mat2x4f constructor");

        assert_msg(mat3d(m23f) == mat3d(0, 1, 2, 0, 1, 2, 0, 0, 1), "matrix3d mat2x3f constructor");

        assert_msg(mat3d(m22f) == mat3d(0, 1, 0, 0, 1, 0, 0, 0, 1), "matrix3d mat2f constructor");

        // mat 3x2
        assert_msg(mat3x2d(m44f) == mat3x2d(0, 1, 0, 1, 0, 1), "matrix3x2d mat4f constructor");

        assert_msg(mat3x2d(m43f) == mat3x2d(0, 1, 0, 1, 0, 1), "matrix3x2d mat4x3f constructor");

        assert_msg(mat3x2d(m42f) == mat3x2d(0, 1, 0, 1, 0, 1), "matrix3x2d mat4x2f constructor");

        assert_msg(mat3x2d(m34f) == mat3x2d(0, 1, 0, 1, 0, 1), "matrix3x2d mat3x4f constructor");

        assert_msg(mat3x2d(m33f) == mat3x2d(0, 1, 0, 1, 0, 1), "matrix3x2d mat3f constructor");

        assert_msg(mat3x2d(m32f) == mat3x2d(0, 1, 0, 1, 0, 1), "matrix3x2d mat3x2f constructor");

        assert_msg(mat3x2d(m24f) == mat3x2d(0, 1, 0, 1, 0, 0), "matrix3x2d mat2x4f constructor");

        assert_msg(mat3x2d(m23f) == mat3x2d(0, 1, 0, 1, 0, 0), "matrix3x2d mat2x3f constructor");

        assert_msg(mat3x2d(m22f) == mat3x2d(0, 1, 0, 1, 0, 0), "matrix3x2d mat2f constructor");

        // mat 2x4
        assert_msg(mat2x4d(m44f) == mat2x4d(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d mat4f constructor");

        assert_msg(mat2x4d(m43f) == mat2x4d(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d mat4x3f constructor");

        assert_msg(mat2x4d(m42f) == mat2x4d(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d mat4x2f constructor");

        assert_msg(mat2x4d(m34f) == mat2x4d(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d mat3x4f constructor");

        assert_msg(mat2x4d(m33f) == mat2x4d(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d mat3f constructor");

        assert_msg(mat2x4d(m32f) == mat2x4d(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d mat3x2f constructor");

        assert_msg(mat2x4d(m24f) == mat2x4d(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d mat2x4f constructor");

        assert_msg(mat2x4d(m23f) == mat2x4d(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d mat2x3f constructor");

        assert_msg(mat2x4d(m22f) == mat2x4d(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d mat2f constructor");

        // mat 2x3
        assert_msg(mat2x3d(m44f) == mat2x3d(0, 1, 2, 0, 1, 2), "matrix2x3d mat4f constructor");

        assert_msg(mat2x3d(m43f) == mat2x3d(0, 1, 2, 0, 1, 2), "matrix2x3d mat4x3f constructor");

        assert_msg(mat2x3d(m42f) == mat2x3d(0, 1, 0, 0, 1, 0), "matrix2x3d mat4x2f constructor");

        assert_msg(mat2x3d(m34f) == mat2x3d(0, 1, 2, 0, 1, 2), "matrix2x3d mat3x4f constructor");

        assert_msg(mat2x3d(m33f) == mat2x3d(0, 1, 2, 0, 1, 2), "matrix2x3d mat3f constructor");

        assert_msg(mat2x3d(m32f) == mat2x3d(0, 1, 0, 0, 1, 0), "matrix2x3d mat3x2f constructor");

        assert_msg(mat2x3d(m24f) == mat2x3d(0, 1, 2, 0, 1, 2), "matrix2x3d mat2x4f constructor");

        assert_msg(mat2x3d(m23f) == mat2x3d(0, 1, 2, 0, 1, 2), "matrix2x3d mat2x3f constructor");

        assert_msg(mat2x3d(m22f) == mat2x3d(0, 1, 0, 0, 1, 0), "matrix2x3d mat2f constructor");

        // mat 2
        assert_msg(mat2d(m44f) == mat2d(0, 1, 0, 1), "matrix2d mat4f constructor");

        assert_msg(mat2d(m43f) == mat2d(0, 1, 0, 1), "matrix2d mat4x3f constructor");

        assert_msg(mat2d(m42f) == mat2d(0, 1, 0, 1), "matrix2d mat4x2f constructor");

        assert_msg(mat2d(m34f) == mat2d(0, 1, 0, 1), "matrix2d mat3x4f constructor");

        assert_msg(mat2d(m33f) == mat2d(0, 1, 0, 1), "matrix2d mat3f constructor");

        assert_msg(mat2d(m32f) == mat2d(0, 1, 0, 1), "matrix2d mat3x2f constructor");

        assert_msg(mat2d(m24f) == mat2d(0, 1, 0, 1), "matrix2d mat2x4f constructor");

        assert_msg(mat2d(m23f) == mat2d(0, 1, 0, 1), "matrix2d mat2x3f constructor");

        assert_msg(mat2d(m22f) == mat2d(0, 1, 0, 1), "matrix2d mat2f constructor");
    }

    return 0;
}
