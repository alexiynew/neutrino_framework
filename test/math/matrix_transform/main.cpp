#include <cassert>

#include <math/math.hpp>
#include <unit_test/suite.hpp>

using ::framework::math::matrix2x2f;
using ::framework::math::matrix2x3f;
using ::framework::math::matrix2x4f;
using ::framework::math::matrix3x2f;
using ::framework::math::matrix3x3f;
using ::framework::math::matrix3x4f;
using ::framework::math::matrix4x2f;
using ::framework::math::matrix4x3f;
using ::framework::math::matrix4x4f;

using ::framework::math::matrix3f;
using ::framework::math::matrix4f;

using ::framework::math::vector2f;
using ::framework::math::vector3f;
using ::framework::math::vector4f;

using ::framework::float32;

using ::framework::math::radians;
using ::framework::math::ortho2d;
using ::framework::math::ortho;
using ::framework::math::frustum;
using ::framework::math::perspective;
using ::framework::math::perspective_fov;
using ::framework::math::infinite_perspective;

using ::framework::math::half_pi;


class transform_2d_function_tests : public framework::unit_test::suite
{
public:
    transform_2d_function_tests() : suite("transform_2d_function_tests")
    {
        add_test([this]() { translate_function(); }, "translate_function");
        add_test([this]() { rotate_function(); }, "rotate_function");
        add_test([this]() { scale_function(); }, "scale_function");
        add_test([this]() { shear_function(); }, "shear_function");
    }

private:
    void translate_function()
    {
        // clang-format off
        const matrix3f m  = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m1 = {
            1,  4,  7,
            2,  5,  8,
            33, 96, 159
        };
        // clang-format on

        TEST_ASSERT(translate(m, vector2f(10, 10)) == m1, "Translate by (10, 10) failed.");
        TEST_ASSERT(translate(m1, vector2f(-10, -10)) == m, "Translate by (-10, -10) failed.");
        TEST_ASSERT(translate(m, vector2f(0, 0)) == m, "Translate by (0, 0) failed.");
    }

    void rotate_function()
    {
        // clang-format off
        const matrix3f m = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f r30 = {
            1.8660254f,  5.96410162f, 10.06217783f,
            1.23205081f, 2.33012702f, 3.42820323f,
            3.0f,        6.0f,        9.0f
        };

        const matrix3f r45 = {
            2.121320340f, 6.363961030f, 10.606601720f,
            0.707106780f, 0.707106780f, 0.707106780f,
            3.0f,         6.0f,         9.0f
        };

        const matrix3f r60 = {
            2.232050810f, 6.330127020f,  10.428203230f,
            0.13397460f,  -0.964101620f, -2.062177830f,
            3.0f,         6.0f,          9.0f
        };

        const matrix3f r90 = {
            2.0f,  5.0f,  8.0f,
            -1.0f, -4.0f, -7.0f,
            3.0f,  6.0f,  9.0f
        };

        const matrix3f r180 = {
            -1.0f, -4.0f, -7.0f,
            -2.0f, -5.0f, -8.0f,
            3.0f,  6.0f,  9.0f
        };

        const matrix3f r300 = {
            -1.23205081f, -2.33012702f, -3.42820323f,
            1.8660254f,   5.96410162f,  10.06217783f,
            3.0f,         6.0f,         9.0f
        };

        const matrix3f r270 = {
            -2.0f, -5.0f, -8.0f,
            1.0f,  4.0f,  7.0f,
            3.0f,  6.0f,  9.0f
        };
        // clang-format on

        TEST_ASSERT(almost_equal(rotate(m, radians(30.0f)), r30, 1), "Rotate by 30 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(45.0f)), r45, 2), "Rotate by 45 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(60.0f)), r60, 4), "Rotate by 60 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(90.0f)), r90, 1), "Rotate by 90 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(180.0f)), r180, 1), "Rotate by 180 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(270.0f)), r270, 1), "Rotate by 270 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(300.0f)), r300, 2), "Rotate by 300 deg failed.");

        TEST_ASSERT(almost_equal(rotate(m, radians(-90.0f)), r270, 1), "Rotate by -90 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(-180.0f)), r180, 1), "Rotate by -180 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(-270.0f)), r90, 1), "Rotate by -270 deg failed.");

        TEST_ASSERT(almost_equal(rotate(m, radians(0.0f)), m, 1), "Rotate by 0 deg failed.");
        TEST_ASSERT(almost_equal(rotate(m, radians(360.0f)), m, 2), "Rotate by 360 deg failed.");
    }

    void scale_function()
    {
        // clang-format off
        const matrix3f m = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m11 = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m55 = {
            5,  20, 35,
            10, 25, 40,
            3,  6,  9
        };

        const matrix3f m12 = {
            1, 4,  7,
            4, 10, 16,
            3, 6,  9
        };

        const matrix3f m21 = {
            2, 8, 14,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m01 = {
            0, 0, 0,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m10 = {
            1, 4, 7,
            0, 0, 0,
            3, 6, 9
        };

        const matrix3f m00 = {
            0, 0, 0,
            0, 0, 0,
            3, 6, 9
        };
        // clang-format on

        TEST_ASSERT(scale(m, vector2f(1, 1)) == m11, "Scale by (1, 1) failed.");
        TEST_ASSERT(scale(m, vector2f(5, 5)) == m55, "Scale by (5, 5) failed.");
        TEST_ASSERT(scale(m, vector2f(1, 2)) == m12, "Scale by (1, 2) failed.");
        TEST_ASSERT(scale(m, vector2f(2, 1)) == m21, "Scale by (2, 1) failed.");
        TEST_ASSERT(scale(m, vector2f(0, 1)) == m01, "Scale by (0, 1) failed.");
        TEST_ASSERT(scale(m, vector2f(1, 0)) == m10, "Scale by (1, 0) failed.");
        TEST_ASSERT(scale(m, vector2f(0, 0)) == m00, "Scale by (0, 0) failed.");
    }

    void shear_function()
    {
        // clang-format off
        const matrix3f m = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m1 = {
            3, 9, 15,
            2, 5, 8,
            3, 6, 9
        };

        const matrix3f m2 = {
            -3, -6, -9,
            2,  5,  8,
            3,  6,  9
        };

        const matrix3f m3 = {
            1, 4, 7,
            3, 9, 15,
            3, 6, 9
        };

        const matrix3f m4 = {
            1, 4,  7,
            0, -3, -6,
            3, 6,  9
        };
        // clang-format on

        TEST_ASSERT(shear(m, vector2f(0.0f, 0.0f)) == m, "Shear by (0, 0) failed.");
        TEST_ASSERT(shear(m, vector2f(1.0f, 0.0f)) == m1, "Shear by (1, 0) failed.");
        TEST_ASSERT(shear(m, vector2f(-2.0f, 0.0f)) == m2, "Shear by (-2, 0) failed.");
        TEST_ASSERT(shear(m, vector2f(0.0f, 1.0f)) == m3, "Shear by (0, 1) failed.");
        TEST_ASSERT(shear(m, vector2f(0.0f, -2.0f)) == m4, "Shear by (0, -2) failed.");
    }
};

class transform_3d_function_tests : public framework::unit_test::suite
{
public:
    transform_3d_function_tests() : suite("transform_3d_function_tests")
    {
        add_test([this]() { translate_function(); }, "translate_function");
        add_test([this]() { scale_function(); }, "scale_function");
        add_test([this]() { rotate_function(); }, "rotate_function");
    }

private:
    void translate_function()
    {
        // clang-format off
        const matrix4f m = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const matrix4f m1 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            3, 5, 7, 5
        };

        const matrix4f m2 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            6, 4, 6, 4
        };

        const matrix4f m3 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            5, 7, 5, 3
        };

        const matrix4f m4 = {
            1,  2,  3,  4,
            4,  1,  2,  3,
            3,  4,  1,  2,
            20, 19, 14, 17
        };
        // clang-format on

        TEST_ASSERT(translate(m, vector3f(0, 0, 0)) == m, "Translate matrix to (0, 0, 0) failed.");
        TEST_ASSERT(translate(m, vector3f(1, 0, 0)) == m1, "Translate matrix to (1, 0, 0) failed.");
        TEST_ASSERT(translate(m, vector3f(0, 1, 0)) == m2, "Translate matrix to (0, 1, 0) failed.");
        TEST_ASSERT(translate(m, vector3f(0, 0, 1)) == m3, "Translate matrix to (0, 0, 1) failed.");
        TEST_ASSERT(translate(m, vector3f(1, 2, 3)) == m4, "Translate matrix to (1, 2, 3) failed.");
    }

    void scale_function()
    {
        // clang-format off
        const matrix4f m = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const matrix4f m1 = {
            2, 4, 6, 8,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const matrix4f m2 = {
            1, 2, 3, 4,
            8, 2, 4, 6,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const matrix4f m3 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            6, 8, 2, 4,
            2, 3, 4, 1
        };
        // clang-format on

        TEST_ASSERT(scale(m, vector3f(1, 1, 1)) == m, "Scale matrix to (1, 1, 1) failed.");
        TEST_ASSERT(scale(m, vector3f(2, 1, 1)) == m1, "Scale matrix to (2, 1, 1) failed.");
        TEST_ASSERT(scale(m, vector3f(1, 2, 1)) == m2, "Scale matrix to (1, 2, 1) failed.");
        TEST_ASSERT(scale(m, vector3f(1, 1, 2)) == m3, "Scale matrix to (1, 1, 2) failed.");
    }

    void rotate_function()
    {
        // clang-format off
        const matrix4f m = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const matrix4f mx = {
            1,  2,  3,  4,
            3,  4,  1,  2,
            -4, -1, -2, -3,
            2,  3,  4,  1
        };

        const matrix4f my = {
            -3, -4, -1, -2,
            4, 1,  2,  3,
            1, 2,  3,  4,
            2, 3,  4,  1
        };

        const matrix4f mz = {
            4,  1,  2,  3,
            -1, -2, -3, -4,
            3,  4,  1,  2,
            2,  3,  4,  1
        };
        // clang-format on

        const matrix4f resultx = rotate(m, vector3f(1, 0, 0), radians(90.0f));
        const matrix4f resulty = rotate(m, vector3f(0, 1, 0), radians(90.0f));
        const matrix4f resultz = rotate(m, vector3f(0, 0, 1), radians(90.0f));

        TEST_ASSERT(almost_equal(resultx, mx, 1), "Rotate matrix from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almost_equal(resulty, my, 1), "Rotate matrix from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almost_equal(resultz, mz, 1), "Rotate matrix from (0, 0, 1) by 90 degrees failed.");
    }
};

class projection_function_tests : public framework::unit_test::suite
{
public:
    projection_function_tests() : suite("projection_function_tests")
    {
        add_test([this]() { ortho_function(); }, "ortho_function");
        add_test([this]() { ortho2d_function(); }, "ortho2d_function");
        add_test([this]() { frustum_function(); }, "frustum_function");
        add_test([this]() { perspective_function(); }, "perspective_function");
        add_test([this]() { perspective_fov_function(); }, "perspective_fov_function");
        add_test([this]() { infinite_perspective_function(); }, "infinite_perspective_function");
    }

private:
    void ortho_function()
    {
        // clang-format off
        const matrix4f target = {
            0.5f, 0,    0,    0,
            0,    0.5f, 0,    0,
            0,    0,    0.5f, 0,
            0,    0,    0,    1
        };
        // clang-format on

        const vector4f v1{0, 0, 0, 1};
        const vector4f v2{1, 1, 1, 1};
        const vector4f v3{2, 2, 2, 1};

        const matrix4f projection = ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);

        TEST_ASSERT(projection == target, "Orthogonal projection matrix is not correct.");

        TEST_ASSERT(projection * v1 == vector4f(0, 0, 0, 1), "Projection of (0, 0, 0, 1) is not correct.");
        TEST_ASSERT(projection * v2 == vector4f(0.5, 0.5, 0.5, 1), "Projection of (1, 1, 1, 1) is not correct.");
        TEST_ASSERT(projection * v3 == vector4f(1, 1, 1, 1), "Projection of (2, 2, 2, 1) is not correct.");
    }

    void ortho2d_function()
    {
        // clang-format off
        const matrix4f proj2D = {
            0.5f, 0,    0, 0,
            0,    0.5f, 0, 0,
            0,    0,    1, 0,
            0,    0,    0, 1
        };
        // clang-format on

        TEST_ASSERT(ortho2d(-2.0f, 2.0f, -2.0f, 2.0f) == proj2D, "2D orthogonal projection matrix is not correct.");
    }

    void frustum_function()
    {
        // clang-format off
        const matrix4f target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -3, -1,
            0, 0, -4, 0
        };
        // clang-format on

        const matrix4f projection = frustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(projection == target, "Frustum projection matrix is not correct.");

        const vector4f v1{2, 2, -1, 1};
        const vector4f v2{2, 2, -1.5f, 1};
        const vector4f v3{2, 2, -2, 1};

        TEST_ASSERT(projection * v1 == vector4f(2, 2, -1, 1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(projection * v2 == vector4f(2, 2, 0.5f, 1.5f), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(projection * v3 == vector4f(2, 2, 2, 2), "Projection of (2, 2, -2, 1) is not correct.");
    }

    void perspective_function()
    {
        // clang-format off
        const matrix4f target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -3, -1,
            0, 0, -4, 0
        };
        // clang-format on

        const matrix4f projection = perspective(float32(half_pi), 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(projection == target, "Perspective projection matrix is not correct.");

        const vector4f v1{2, 2, -1, 1};
        const vector4f v2{2, 2, -1.5f, 1};
        const vector4f v3{2, 2, -2, 1};

        TEST_ASSERT(projection * v1 == vector4f(2, 2, -1, 1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(projection * v2 == vector4f(2, 2, 0.5f, 1.5f), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(projection * v3 == vector4f(2, 2, 2, 2), "Projection of (2, 2, -2, 1) is not correct.");
    }

    void perspective_fov_function()
    {
        const matrix4f target     = perspective(float32(half_pi), 1.0f, 1.0f, 2.0f);
        const matrix4f projection = perspective_fov(float32(half_pi), 1.0f, 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(projection == target, "Perspective_fov projection matrix is not correct.");
    }

    void infinite_perspective_function()
    {
        // clang-format off
        const matrix4f target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -1, -1,
            0, 0, -2, 0
        };
        // clang-format on

        const matrix4f projection = infinite_perspective(float32(half_pi), 1.0f, 1.0f);

        TEST_ASSERT(almost_equal(projection, target, 1), "Infinite perspective projection matrix is not correct.");

        const vector4f v1{2, 2, -1, 1};
        const vector4f v2{2, 2, -1.5f, 1};
        const vector4f v3{2, 2, -2, 1};

        const vector4f test1 = vector4f(2, 2, -1, 1);
        const vector4f test2 = vector4f(2, 2, -0.5f, 1.5f);
        const vector4f test3 = vector4f(2, 2, -0.0000001192092895f, 2);

        TEST_ASSERT(almost_equal(projection * v1, test1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(almost_equal(projection * v2, test2, 1), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(almost_equal(projection * v3, test3, 1), "Projection of (2, 2, -2, 1) is not correct.");
    }
};

class helpers_function_test : public framework::unit_test::suite
{
public:
    helpers_function_test() : suite("helpers_function_test")
    {
        add_test([this]() { project_function(); }, "project_function");
        add_test([this]() { unproject_function(); }, "unproject_function");
        add_test([this]() { pick_region_function(); }, "pick_region_function");
        add_test([this]() { look_at_function(); }, "look_at_function");
    }

private:
    void project_function()
    {
        const float32 near = 1.0f;
        const float32 far  = 10.0f;

        const float32 width  = 480.0f;
        const float32 height = 320.0f;

        const matrix4f model;
        const matrix4f projection = perspective_fov(float32(half_pi), width, height, near, far);

        const vector4f viewport{0, 0, width, height};

        const vector3f obj1{0, 0, -1};
        const vector3f obj2{0, 1, -1};
        const vector3f obj3{1.5, 0, -1};
        const vector3f obj4{-1.5, -1, -1};
        const vector3f obj5{0, 0, -10};

        const vector3f projected1{width / 2, height / 2, -0.0000000596046447f};
        const vector3f projected2{width / 2, height, -0.0000000596046447f};
        const vector3f projected3{width, height / 2, -0.0000000596046447f};
        const vector3f projected4{0, 0, -0.0000000596046447f};
        const vector3f projected5{width / 2, height / 2, 1};

        const vector3f project1 = project(obj1, model, projection, viewport);
        const vector3f project2 = project(obj2, model, projection, viewport);
        const vector3f project3 = project(obj3, model, projection, viewport);
        const vector3f project4 = project(obj4, model, projection, viewport);
        const vector3f project5 = project(obj5, model, projection, viewport);

        TEST_ASSERT(almost_equal(project1, projected1), "Projection of (0, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(project2, projected2), "Projection of (0, 1, -1) is not correct.");
        TEST_ASSERT(almost_equal(project3, projected3), "Projection of (1.5, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(project4, projected4), "Projection of (-1.5, -1, -1) is not correct.");
        TEST_ASSERT(almost_equal(project5, projected5), "Projection of (0, 0, -10) is not correct.");
    }

    void unproject_function()
    {
        const float32 near = 1.0f;
        const float32 far  = 10.0f;

        const float32 width  = 480.0f;
        const float32 height = 320.0f;

        const matrix4f model;
        const matrix4f projection = perspective_fov(float32(half_pi), width, height, near, far);

        const vector4f viewport{0, 0, width, height};

        const vector3f obj1{0, 0, -1};
        const vector3f obj2{0, 1, -1};
        const vector3f obj3{1.5, 0, -1};
        const vector3f obj4{-1.5, -1, -1};
        const vector3f obj5{0, 0, -10};

        const vector3f project1 = project(obj1, model, projection, viewport);
        const vector3f project2 = project(obj2, model, projection, viewport);
        const vector3f project3 = project(obj3, model, projection, viewport);
        const vector3f project4 = project(obj4, model, projection, viewport);
        const vector3f project5 = project(obj5, model, projection, viewport);

        const vector3f unproject1 = unproject(project1, model, projection, viewport);
        const vector3f unproject2 = unproject(project2, model, projection, viewport);
        const vector3f unproject3 = unproject(project3, model, projection, viewport);
        const vector3f unproject4 = unproject(project4, model, projection, viewport);
        const vector3f unproject5 = unproject(project5, model, projection, viewport);

        TEST_ASSERT(almost_equal(unproject1, obj1), "Un projection of (0, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject2, obj2), "Un projection of (0, 1, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject3, obj3), "Un projection of (1.5, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject4, obj4), "Un projection of (-1.5, -1, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject5, obj5, 2), "Un projection of (0, 0, -10) is not correct.");
    }

    void pick_region_function()
    {
        // clang-format off
        const matrix4f region = {
            2, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            2, 2, 0, 1
        };
        // clang-format on

        const float32 width  = 480.0f;
        const float32 height = 320.0f;

        const vector4f viewport{0, 0, width, height};

        const matrix4f result = pick_matrix(vector2f(0, 0), vector2f(width / 2, height / 2), viewport);

        TEST_ASSERT(result == region, "Pick region matrix is not correct.");
    }

    void look_at_function()
    {
        // clang-format off
        const matrix4f test = {
            0, 0, -1, 0,
            0, 1, 0,  0,
            1, 0, 0,  0,
            0, 0, 0,  1
        };
        // clang-format on

        const vector3f eye(0, 0, 0);
        const vector3f center(1, 0, 0);
        const vector3f up(0, 1, 0);

        const matrix4f result = look_at(eye, center, up);

        TEST_ASSERT(result == test, "Look_at matrix is not correct.");
    }
};

int main()
{
    return run_tests(transform_2d_function_tests(),
                     transform_3d_function_tests(),
                     projection_function_tests(),
                     helpers_function_test());
}
