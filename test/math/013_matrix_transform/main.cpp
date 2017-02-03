#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class transform_2d_function_tests : public test::suite
{
public:
    transform_2d_function_tests()
        : suite("transform_2d_function_tests")
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
        const Matrix3F m  = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m1 = {
            1,  4,  7,
            2,  5,  8,
            33, 96, 159
        };
        // clang-format on

        TEST_ASSERT(translate(m, Vector2F(10, 10)) == m1, "Translate by (10, 10) failed.");
        TEST_ASSERT(translate(m1, Vector2F(-10, -10)) == m, "Translate by (-10, -10) failed.");
        TEST_ASSERT(translate(m, Vector2F(0, 0)) == m, "Translate by (0, 0) failed.");
    }

    void rotate_function()
    {
        // clang-format off
        const Matrix3F m = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F r30 = {
            1.8660254f,  5.96410162f, 10.06217783f,
            1.23205081f, 2.33012702f, 3.42820323f,
            3.0f,        6.0f,        9.0f
        };

        const Matrix3F r45 = {
            2.121320340f, 6.363961030f, 10.606601720f,
            0.707106780f, 0.707106780f, 0.707106780f,
            3.0f,         6.0f,         9.0f
        };

        const Matrix3F r60 = {
            2.232050810f, 6.330127020f,  10.428203230f,
            0.13397460f,  -0.964101620f, -2.062177830f,
            3.0f,         6.0f,          9.0f
        };

        const Matrix3F r90 = {
            2.0f,  5.0f,  8.0f,
            -1.0f, -4.0f, -7.0f,
            3.0f,  6.0f,  9.0f
        };

        const Matrix3F r180 = {
            -1.0f, -4.0f, -7.0f,
            -2.0f, -5.0f, -8.0f,
            3.0f,  6.0f,  9.0f
        };

        const Matrix3F r300 = {
            -1.23205081f, -2.33012702f, -3.42820323f,
            1.8660254f,   5.96410162f,  10.06217783f,
            3.0f,         6.0f,         9.0f
        };

        const Matrix3F r270 = {
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
        const Matrix3F m = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m11 = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m55 = {
            5,  20, 35,
            10, 25, 40,
            3,  6,  9
        };

        const Matrix3F m12 = {
            1, 4,  7,
            4, 10, 16,
            3, 6,  9
        };

        const Matrix3F m21 = {
            2, 8, 14,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m01 = {
            0, 0, 0,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m10 = {
            1, 4, 7,
            0, 0, 0,
            3, 6, 9
        };

        const Matrix3F m00 = {
            0, 0, 0,
            0, 0, 0,
            3, 6, 9
        };
        // clang-format on

        TEST_ASSERT(scale(m, Vector2F(1, 1)) == m11, "Scale by (1, 1) failed.");
        TEST_ASSERT(scale(m, Vector2F(5, 5)) == m55, "Scale by (5, 5) failed.");
        TEST_ASSERT(scale(m, Vector2F(1, 2)) == m12, "Scale by (1, 2) failed.");
        TEST_ASSERT(scale(m, Vector2F(2, 1)) == m21, "Scale by (2, 1) failed.");
        TEST_ASSERT(scale(m, Vector2F(0, 1)) == m01, "Scale by (0, 1) failed.");
        TEST_ASSERT(scale(m, Vector2F(1, 0)) == m10, "Scale by (1, 0) failed.");
        TEST_ASSERT(scale(m, Vector2F(0, 0)) == m00, "Scale by (0, 0) failed.");
    }

    void shear_function()
    {
        // clang-format off
        const Matrix3F m = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m1 = {
            3, 9, 15,
            2, 5, 8,
            3, 6, 9
        };

        const Matrix3F m2 = {
            -3, -6, -9,
            2,  5,  8,
            3,  6,  9
        };

        const Matrix3F m3 = {
            1, 4, 7,
            3, 9, 15,
            3, 6, 9
        };

        const Matrix3F m4 = {
            1, 4,  7,
            0, -3, -6,
            3, 6,  9
        };
        // clang-format on

        TEST_ASSERT(shear(m, Vector2F(0.0f, 0.0f)) == m, "Shear by (0, 0) failed.");
        TEST_ASSERT(shear(m, Vector2F(1.0f, 0.0f)) == m1, "Shear by (1, 0) failed.");
        TEST_ASSERT(shear(m, Vector2F(-2.0f, 0.0f)) == m2, "Shear by (-2, 0) failed.");
        TEST_ASSERT(shear(m, Vector2F(0.0f, 1.0f)) == m3, "Shear by (0, 1) failed.");
        TEST_ASSERT(shear(m, Vector2F(0.0f, -2.0f)) == m4, "Shear by (0, -2) failed.");
    }
};

class transform_3d_function_tests : public test::suite
{
public:
    transform_3d_function_tests()
        : suite("transform_3d_function_tests")
    {
        add_test([this]() { create_translate_function(); }, "create_translate_function");
        add_test([this]() { create_rotate_function(); }, "create_rotate_function");
        add_test([this]() { create_scale_function(); }, "create_scale_function");
        add_test([this]() { translate_function(); }, "translate_function");
        add_test([this]() { scale_function(); }, "scale_function");
        add_test([this]() { rotate_function(); }, "rotate_function");
    }

private:
    void create_translate_function()
    {
        // clang-format off
        const Matrix4F m = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            1, 2, 3, 1
        };
        // clang-format on

        TEST_ASSERT(createTranslateMatrix(Vector3F(1, 2, 3)) == m,
                    "Create_translate_matrix function from (1, 2, 3) failed.");
    }

    void create_rotate_function()
    {
        // clang-format off
        const Matrix4F mx = {
            1.0f, 0.0f,                   0.0f,                   0.0f,
            0.0f, -0.000000043711388286f, 1.0f,                   0.0f,
            0.0f, -1.0f,                  -0.000000043711388286f, 0.0f,
            0.0f, 0.0f,                   0.0f,                   1.0f
          };

        const Matrix4F my = {
            -0.000000043711388286f, 0.0f, -1.0f,                  0.0f,
            0.0f,                   1.0f, 0.0f,                   0.0f,
            1.0f,                   0.0f, -0.000000043711388286f, 0.0f,
            0.0f,                   0.0f, 0.0f,                   1.0f
        };

        const Matrix4F mz = {
            -0.000000043711388286f, 1.0f,                   0.0f, 0.0f,
            -1.0f,                  -0.000000043711388286f, 0.0f, 0.0f,
            0.0f,                   0.0f,                   1.0f, 0.0f,
            0.0f,                   0.0f,                   0.0f, 1.0f
        };

        const Matrix4F m1 = {
            1.0f,             0.207911690818f,  0.0218523992662f,0.0f,
            -0.207911690818f, 0.978147600734f,  0.207911690818f, 0.0f,
            0.0218523992662f, -0.207911690818f, 1.0f,            0.0f,
            0.0f,             0.0f,             0.0f,            1.0f
          };

        const Matrix4F m2 = {
            -0.190808995377f, 0.0f, 0.981627183448f,  0.0f,
            0.0f,             1.0f, 0.0f,             0.0f,
            -0.981627183448f, 0.0f, -0.190808995377f, 0.0f,
            0.0f,             0.0f, 0.0f,             1.0f
        };

        const Matrix4F m3 = {
            1.0f,             -0.410768609213f, 1.09865055123f,   0.0f,
            1.09865055123f,   1.0f,             -0.410768609213f, 0.0f,
            -0.410768609213f, 1.09865055123f,   1.0f,             0.0f,
            0.0f,             0.0f,             0.0f,             1.0f
        };
        // clang-format on

        const Matrix4F resultx = createRotateMatrix(Vector3F(1, 0, 0), radians(90.0f));
        const Matrix4F resulty = createRotateMatrix(Vector3F(0, 1, 0), radians(90.0f));
        const Matrix4F resultz = createRotateMatrix(Vector3F(0, 0, 1), radians(90.0f));

        const Matrix4F result1 = createRotateMatrix(Vector3F(1, 0, 1), radians(12.0f));
        const Matrix4F result2 = createRotateMatrix(Vector3F(0, 1, 0), radians(259.0f));
        const Matrix4F result3 = createRotateMatrix(Vector3F(1, 1, 1), radians(-49.0f));

        TEST_ASSERT(almost_equal(resultx, mx, 1), "Create_rotate_matrix function from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almost_equal(resulty, my, 1), "Create_rotate_matrix function from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almost_equal(resultz, mz, 1), "Create_rotate_matrix function from (0, 0, 1) by 90 degrees failed.");

        TEST_ASSERT(almost_equal(result1, m1, 6), "Create_rotate_matrix function from (1, 0, 1) by 12 degrees failed.");
        TEST_ASSERT(almost_equal(result2, m2, 4),
                    "Create_rotate_matrix function from (0, 1, 0) by 259 degrees failed.");
        TEST_ASSERT(almost_equal(result3, m3, 1),
                    "Create_rotate_matrix function from (1, 1, 1) by -49 degrees failed.");
    }

    void create_scale_function()
    {
        // clang-format off
        const Matrix4F m = {
            4, 0, 0, 0,
            0, 3, 0, 0,
            0, 0, 2, 0,
            0, 0, 0, 1
        };
        // clang-format on

        TEST_ASSERT(createScaleMatrix(Vector3F(4, 3, 2)) == m, "Create_scale_matrix function from (4, 3, 2) failed.");
    }

    void translate_function()
    {
        // clang-format off
        const Matrix4F m = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4F m1 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            3, 5, 7, 5
        };

        const Matrix4F m2 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            6, 4, 6, 4
        };

        const Matrix4F m3 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            5, 7, 5, 3
        };

        const Matrix4F m4 = {
            1,  2,  3,  4,
            4,  1,  2,  3,
            3,  4,  1,  2,
            20, 19, 14, 17
        };
        // clang-format on

        TEST_ASSERT(translate(m, Vector3F(0, 0, 0)) == m, "Translate matrix to (0, 0, 0) failed.");
        TEST_ASSERT(translate(m, Vector3F(1, 0, 0)) == m1, "Translate matrix to (1, 0, 0) failed.");
        TEST_ASSERT(translate(m, Vector3F(0, 1, 0)) == m2, "Translate matrix to (0, 1, 0) failed.");
        TEST_ASSERT(translate(m, Vector3F(0, 0, 1)) == m3, "Translate matrix to (0, 0, 1) failed.");
        TEST_ASSERT(translate(m, Vector3F(1, 2, 3)) == m4, "Translate matrix to (1, 2, 3) failed.");
    }

    void scale_function()
    {
        // clang-format off
        const Matrix4F m = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4F m1 = {
            2, 4, 6, 8,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4F m2 = {
            1, 2, 3, 4,
            8, 2, 4, 6,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4F m3 = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            6, 8, 2, 4,
            2, 3, 4, 1
        };
        // clang-format on

        TEST_ASSERT(scale(m, Vector3F(1, 1, 1)) == m, "Scale matrix to (1, 1, 1) failed.");
        TEST_ASSERT(scale(m, Vector3F(2, 1, 1)) == m1, "Scale matrix to (2, 1, 1) failed.");
        TEST_ASSERT(scale(m, Vector3F(1, 2, 1)) == m2, "Scale matrix to (1, 2, 1) failed.");
        TEST_ASSERT(scale(m, Vector3F(1, 1, 2)) == m3, "Scale matrix to (1, 1, 2) failed.");
    }

    void rotate_function()
    {
        // clang-format off
        const Matrix4F m = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4F mx = {
            1,  2,  3,  4,
            3,  4,  1,  2,
            -4, -1, -2, -3,
            2,  3,  4,  1
        };

        const Matrix4F my = {
            -3, -4, -1, -2,
            4, 1,  2,  3,
            1, 2,  3,  4,
            2, 3,  4,  1
        };

        const Matrix4F mz = {
            4,  1,  2,  3,
            -1, -2, -3, -4,
            3,  4,  1,  2,
            2,  3,  4,  1
        };
        // clang-format on

        const Matrix4F resultx = rotate(m, Vector3F(1, 0, 0), radians(90.0f));
        const Matrix4F resulty = rotate(m, Vector3F(0, 1, 0), radians(90.0f));
        const Matrix4F resultz = rotate(m, Vector3F(0, 0, 1), radians(90.0f));

        TEST_ASSERT(almost_equal(resultx, mx, 1), "Rotate matrix from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almost_equal(resulty, my, 1), "Rotate matrix from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almost_equal(resultz, mz, 1), "Rotate matrix from (0, 0, 1) by 90 degrees failed.");
    }
};

class projection_function_tests : public test::suite
{
public:
    projection_function_tests()
        : suite("projection_function_tests")
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
        const Matrix4F target = {
            0.5f, 0,    0,    0,
            0,    0.5f, 0,    0,
            0,    0,    0.5f, 0,
            0,    0,    0,    1
        };
        // clang-format on

        const Vector4F v1{0, 0, 0, 1};
        const Vector4F v2{1, 1, 1, 1};
        const Vector4F v3{2, 2, 2, 1};

        const Matrix4F projection = ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);

        TEST_ASSERT(projection == target, "Orthogonal projection matrix is not correct.");

        TEST_ASSERT(projection * v1 == Vector4F(0, 0, 0, 1), "Projection of (0, 0, 0, 1) is not correct.");
        TEST_ASSERT(projection * v2 == Vector4F(0.5, 0.5, 0.5, 1), "Projection of (1, 1, 1, 1) is not correct.");
        TEST_ASSERT(projection * v3 == Vector4F(1, 1, 1, 1), "Projection of (2, 2, 2, 1) is not correct.");
    }

    void ortho2d_function()
    {
        // clang-format off
        const Matrix4F proj2D = {
            0.5f, 0,    0, 0,
            0,    0.5f, 0, 0,
            0,    0,    1, 0,
            0,    0,    0, 1
        };
        // clang-format on

        TEST_ASSERT(::ortho2D(-2.0f, 2.0f, -2.0f, 2.0f) == proj2D, "2D orthogonal projection matrix is not correct.");
    }

    void frustum_function()
    {
        // clang-format off
        const Matrix4F target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -3, -1,
            0, 0, -4, 0
        };
        // clang-format on

        const Matrix4F projection = frustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(projection == target, "Frustum projection matrix is not correct.");

        const Vector4F v1{2, 2, -1, 1};
        const Vector4F v2{2, 2, -1.5f, 1};
        const Vector4F v3{2, 2, -2, 1};

        TEST_ASSERT(projection * v1 == Vector4F(2, 2, -1, 1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(projection * v2 == Vector4F(2, 2, 0.5f, 1.5f), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(projection * v3 == Vector4F(2, 2, 2, 2), "Projection of (2, 2, -2, 1) is not correct.");
    }

    void perspective_function()
    {
        // clang-format off
        const Matrix4F target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -3, -1,
            0, 0, -4, 0
        };
        // clang-format on

        const Matrix4F projection = perspective(float(HALF_PI), 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(projection == target, "Perspective projection matrix is not correct.");

        const Vector4F v1{2, 2, -1, 1};
        const Vector4F v2{2, 2, -1.5f, 1};
        const Vector4F v3{2, 2, -2, 1};

        TEST_ASSERT(projection * v1 == Vector4F(2, 2, -1, 1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(projection * v2 == Vector4F(2, 2, 0.5f, 1.5f), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(projection * v3 == Vector4F(2, 2, 2, 2), "Projection of (2, 2, -2, 1) is not correct.");
    }

    void perspective_fov_function()
    {
        const Matrix4F target     = perspective(float(HALF_PI), 1.0f, 1.0f, 2.0f);
        const Matrix4F projection = perspectiveFov(float(HALF_PI), 1.0f, 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(projection == target, "PerspectiveFov projection matrix is not correct.");
    }

    void infinite_perspective_function()
    {
        // clang-format off
        const Matrix4F target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -1, -1,
            0, 0, -2, 0
        };
        // clang-format on

        const Matrix4F projection = infinitePerspective(float(HALF_PI), 1.0f, 1.0f);

        TEST_ASSERT(almost_equal(projection, target, 1), "Infinite perspective projection matrix is not correct.");

        const Vector4F v1{2, 2, -1, 1};
        const Vector4F v2{2, 2, -1.5f, 1};
        const Vector4F v3{2, 2, -2, 1};

        const Vector4F test1 = Vector4F(2, 2, -1, 1);
        const Vector4F test2 = Vector4F(2, 2, -0.5f, 1.5f);
        const Vector4F test3 = Vector4F(2, 2, -0.0000001192092895f, 2);

        TEST_ASSERT(almost_equal(projection * v1, test1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(almost_equal(projection * v2, test2, 1), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(almost_equal(projection * v3, test3, 1), "Projection of (2, 2, -2, 1) is not correct.");
    }
};

class helpers_function_test : public test::suite
{
public:
    helpers_function_test()
        : suite("helpers_function_test")
    {
        add_test([this]() { project_function(); }, "project_function");
        add_test([this]() { unproject_function(); }, "unproject_function");
        add_test([this]() { pick_region_function(); }, "pick_region_function");
        add_test([this]() { look_at_function(); }, "look_at_function");
    }

private:
    void project_function()
    {
        const float near = 1.0f;
        const float far  = 10.0f;

        const float width  = 480.0f;
        const float height = 320.0f;

        const Matrix4F model;
        const Matrix4F projection = perspectiveFov(float(HALF_PI), width, height, near, far);

        const Vector4F viewport{0, 0, width, height};

        const Vector3F obj1{0, 0, -1};
        const Vector3F obj2{0, 1, -1};
        const Vector3F obj3{1.5, 0, -1};
        const Vector3F obj4{-1.5, -1, -1};
        const Vector3F obj5{0, 0, -10};

        const Vector3F projected1{width / 2, height / 2, -0.0000000596046447f};
        const Vector3F projected2{width / 2, height, -0.0000000596046447f};
        const Vector3F projected3{width, height / 2, -0.0000000596046447f};
        const Vector3F projected4{0, 0, -0.0000000596046447f};
        const Vector3F projected5{width / 2, height / 2, 1};

        const Vector3F project1 = project(obj1, model, projection, viewport);
        const Vector3F project2 = project(obj2, model, projection, viewport);
        const Vector3F project3 = project(obj3, model, projection, viewport);
        const Vector3F project4 = project(obj4, model, projection, viewport);
        const Vector3F project5 = project(obj5, model, projection, viewport);

        TEST_ASSERT(almost_equal(project1, projected1), "Projection of (0, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(project2, projected2), "Projection of (0, 1, -1) is not correct.");
        TEST_ASSERT(almost_equal(project3, projected3), "Projection of (1.5, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(project4, projected4), "Projection of (-1.5, -1, -1) is not correct.");
        TEST_ASSERT(almost_equal(project5, projected5), "Projection of (0, 0, -10) is not correct.");
    }

    void unproject_function()
    {
        const float near = 1.0f;
        const float far  = 10.0f;

        const float width  = 480.0f;
        const float height = 320.0f;

        const Matrix4F model;
        const Matrix4F projection = perspectiveFov(float(HALF_PI), width, height, near, far);

        const Vector4F viewport{0, 0, width, height};

        const Vector3F obj1{0, 0, -1};
        const Vector3F obj2{0, 1, -1};
        const Vector3F obj3{1.5, 0, -1};
        const Vector3F obj4{-1.5, -1, -1};
        const Vector3F obj5{0, 0, -10};

        const Vector3F project1 = project(obj1, model, projection, viewport);
        const Vector3F project2 = project(obj2, model, projection, viewport);
        const Vector3F project3 = project(obj3, model, projection, viewport);
        const Vector3F project4 = project(obj4, model, projection, viewport);
        const Vector3F project5 = project(obj5, model, projection, viewport);

        const Vector3F unproject1 = unProject(project1, model, projection, viewport);
        const Vector3F unproject2 = unProject(project2, model, projection, viewport);
        const Vector3F unproject3 = unProject(project3, model, projection, viewport);
        const Vector3F unproject4 = unProject(project4, model, projection, viewport);
        const Vector3F unproject5 = unProject(project5, model, projection, viewport);

        TEST_ASSERT(almost_equal(unproject1, obj1), "UnProjection of (0, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject2, obj2), "UnProjection of (0, 1, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject3, obj3), "UnProjection of (1.5, 0, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject4, obj4), "UnProjection of (-1.5, -1, -1) is not correct.");
        TEST_ASSERT(almost_equal(unproject5, obj5, 2), "UnProjection of (0, 0, -10) is not correct.");
    }

    void pick_region_function()
    {
        // clang-format off
        const Matrix4F region = {
            2, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            2, 2, 0, 1
        };
        // clang-format on

        const float width  = 480.0f;
        const float height = 320.0f;

        const Vector4F viewport{0, 0, width, height};

        const Matrix4F result = pickMatrix(Vector2F(0, 0), Vector2F(width / 2, height / 2), viewport);

        TEST_ASSERT(result == region, "Pick region matrix is not correct.");
    }

    void look_at_function()
    {
        // clang-format off
        const Matrix4F look_at = {
            0, 0, -1, 0,
            0, 1, 0,  0,
            1, 0, 0,  0,
            0, 0, 0,  1
        };
        // clang-format on

        const Vector3F eye(0, 0, 0);
        const Vector3F center(1, 0, 0);
        const Vector3F up(0, 1, 0);

        const Matrix4F result = lookAt(eye, center, up);

        TEST_ASSERT(result == look_at, "Look_at matrix is not correct.");
    }
};

int main()
{
    return run_tests(
    transform_2d_function_tests(), transform_3d_function_tests(), projection_function_tests(), helpers_function_test());
}
