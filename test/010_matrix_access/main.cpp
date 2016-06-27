#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    mat2x4f m24;
    mat2x3f m23;
    mat2x2f m22;
    mat3x4f m34;
    mat3x3f m33;
    mat3x2f m32;
    mat4x4f m44;
    mat4x3f m43;
    mat4x2f m42;

    assert_msg(m44[0] == vec4f(1, 0, 0, 0) && m44[1] == vec4f(0, 1, 0, 0) && m44[2] == vec4f(0, 0, 1, 0) && m44[3] == vec4f(0, 0, 0, 1), "matrix 4f access failed");
    assert_msg(m34[0] == vec4f(1, 0, 0, 0) && m34[1] == vec4f(0, 1, 0, 0) && m34[2] == vec4f(0, 0, 1, 0),
               "matrix 34f access failed");
    assert_msg(m24[0] == vec4f(1, 0, 0, 0) && m24[1] == vec4f(0, 1, 0, 0), "matrix 24f access failed");

    assert_msg(m43[0] == vec3f(1, 0, 0) && m43[1] == vec3f(0, 1, 0) && m43[2] == vec3f(0, 0, 1) && m43[3] == vec3f(0, 0, 0), "matrix 43f access failed");
    assert_msg(m33[0] == vec3f(1, 0, 0) && m33[1] == vec3f(0, 1, 0) && m33[2] == vec3f(0, 0, 1), "matrix 3f access "
                                                                                                 "failed");
    assert_msg(m23[0] == vec3f(1, 0, 0) && m23[1] == vec3f(0, 1, 0), "matrix 23f access failed");

    assert_msg(m42[0] == vec2f(1, 0) && m42[1] == vec2f(0, 1) && m42[2] == vec2f(0, 0) && m42[3] == vec2f(0, 0),
               "matrix 42f access failed");
    assert_msg(m32[0] == vec2f(1, 0) && m32[1] == vec2f(0, 1) && m32[2] == vec2f(0, 0), "matrix 32f access failed");
    assert_msg(m22[0] == vec2f(1, 0) && m22[1] == vec2f(0, 1), "matrix 2f access failed");


    assert_msg(m44.column(0) == vec4f(1, 0, 0, 0) && m44.column(1) == vec4f(0, 1, 0, 0) && m44.column(2) == vec4f(0, 0, 1, 0) &&
               m44.column(3) == vec4f(0, 0, 0, 1),
               "matrix 4f access failed");
    assert_msg(m34.column(0) == vec4f(1, 0, 0, 0) && m34.column(1) == vec4f(0, 1, 0, 0) && m34.column(2) == vec4f(0, 0, 1, 0), "matrix 34f access failed");
    assert_msg(m24.column(0) == vec4f(1, 0, 0, 0) && m24.column(1) == vec4f(0, 1, 0, 0), "matrix 24f access failed");

    assert_msg(
    m43.column(0) == vec3f(1, 0, 0) && m43.column(1) == vec3f(0, 1, 0) && m43.column(2) == vec3f(0, 0, 1) && m43.column(3) == vec3f(0, 0, 0), "matrix 43f access failed");
    assert_msg(m33.column(0) == vec3f(1, 0, 0) && m33.column(1) == vec3f(0, 1, 0) && m33.column(2) == vec3f(0, 0, 1), "matrix 3f access failed");
    assert_msg(m23.column(0) == vec3f(1, 0, 0) && m23.column(1) == vec3f(0, 1, 0), "matrix 23f access failed");

    assert_msg(m42.column(0) == vec2f(1, 0) && m42.column(1) == vec2f(0, 1) && m42.column(2) == vec2f(0, 0) && m42.column(3) == vec2f(0, 0), "matrix 42f access failed");
    assert_msg(m32.column(0) == vec2f(1, 0) && m32.column(1) == vec2f(0, 1) && m32.column(2) == vec2f(0, 0),
               "matrix 32f access failed");
    assert_msg(m22.column(0) == vec2f(1, 0) && m22.column(1) == vec2f(0, 1), "matrix 2f access failed");


    assert_msg(
    m44.row(0) == vec4f(1, 0, 0, 0) && m44.row(1) == vec4f(0, 1, 0, 0) && m44.row(2) == vec4f(0, 0, 1, 0) && m44.row(3) == vec4f(0, 0, 0, 1), "matrix 4f access failed");
    assert_msg(m34.row(0) == vec3f(1, 0, 0) && m34.row(1) == vec3f(0, 1, 0) && m34.row(2) == vec3f(0, 0, 1) && m34.row(3) == vec3f(0, 0, 0), "matrix 34f access failed");
    assert_msg(m24.row(0) == vec2f(1, 0) && m24.row(1) == vec2f(0, 1) && m24.row(2) == vec2f(0, 0) && m24.row(3) == vec2f(0, 0), "matrix 24f access failed");

    assert_msg(m43.row(0) == vec4f(1, 0, 0, 0) && m43.row(1) == vec4f(0, 1, 0, 0) && m43.row(2) == vec4f(0, 0, 1, 0), "matrix 43f access failed");
    assert_msg(m33.row(0) == vec3f(1, 0, 0) && m33.row(1) == vec3f(0, 1, 0) && m33.row(2) == vec3f(0, 0, 1),
               "matrix 33f access failed");
    assert_msg(m23.row(0) == vec2f(1, 0) && m23.row(1) == vec2f(0, 1) && m23.row(2) == vec2f(0, 0), "matrix 23f access "
                                                                                                    "failed");

    assert_msg(m42.row(0) == vec4f(1, 0, 0, 0) && m42.row(1) == vec4f(0, 1, 0, 0), "matrix 42f access failed");
    assert_msg(m32.row(0) == vec3f(1, 0, 0) && m32.row(1) == vec3f(0, 1, 0), "matrix 32f access failed");
    assert_msg(m22.row(0) == vec2f(1, 0) && m22.row(1) == vec2f(0, 1), "matrix 22f access failed");

    return 0;
}
