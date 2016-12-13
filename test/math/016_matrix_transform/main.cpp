#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class Transform2DTest : public test::suite
{
public:
    Transform2DTest()
        : suite("Transform2DTest")
    {
        add_test([this]() { translate(); }, "translate");
        add_test([this]() { rotate(); }, "rotate");
        add_test([this]() { scale(); }, "scale");
        add_test([this]() { shear(); }, "shear");
    }

private:
    void translate()
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

        TEST_ASSERT(::translate(m, Vector2F(10, 10)) == m1, "Translate by (10, 10) failed.");
        TEST_ASSERT(::translate(m1, Vector2F(-10, -10)) == m, "Translate by (-10, -10) failed.");
        TEST_ASSERT(::translate(m, Vector2F(0, 0)) == m, "Translate by (0, 0) failed.");
    }

    void rotate()
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

        TEST_ASSERT(almostEqual(::rotate(m, radians(30.0f)), r30, 1), "Rotate by 30 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(45.0f)), r45, 2), "Rotate by 45 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(60.0f)), r60, 4), "Rotate by 60 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(90.0f)), r90, 1), "Rotate by 90 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(180.0f)), r180, 1), "Rotate by 180 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(270.0f)), r270, 1), "Rotate by 270 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(300.0f)), r300, 2), "Rotate by 300 deg failed.");

        TEST_ASSERT(almostEqual(::rotate(m, radians(-90.0f)), r270, 1), "Rotate by -90 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(-180.0f)), r180, 1), "Rotate by -180 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(-270.0f)), r90, 1), "Rotate by -270 deg failed.");

        TEST_ASSERT(almostEqual(::rotate(m, radians(0.0f)), m, 1), "Rotate by 0 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(360.0f)), m, 2), "Rotate by 360 deg failed.");
    }

    void scale()
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

        TEST_ASSERT(::scale(m, Vector2F(1, 1)) == m11, "Scale by (1, 1) failed.");
        TEST_ASSERT(::scale(m, Vector2F(5, 5)) == m55, "Scale by (5, 5) failed.");
        TEST_ASSERT(::scale(m, Vector2F(1, 2)) == m12, "Scale by (1, 2) failed.");
        TEST_ASSERT(::scale(m, Vector2F(2, 1)) == m21, "Scale by (2, 1) failed.");
        TEST_ASSERT(::scale(m, Vector2F(0, 1)) == m01, "Scale by (0, 1) failed.");
        TEST_ASSERT(::scale(m, Vector2F(1, 0)) == m10, "Scale by (1, 0) failed.");
        TEST_ASSERT(::scale(m, Vector2F(0, 0)) == m00, "Scale by (0, 0) failed.");
    }

    void shear()
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

        TEST_ASSERT(::shear(m, Vector2F(0.0f, 0.0f)) == m, "Shear by (0, 0) failed.");
        TEST_ASSERT(::shear(m, Vector2F(1.0f, 0.0f)) == m1, "Shear by (1, 0) failed.");
        TEST_ASSERT(::shear(m, Vector2F(-2.0f, 0.0f)) == m2, "Shear by (-2, 0) failed.");
        TEST_ASSERT(::shear(m, Vector2F(0.0f, 1.0f)) == m3, "Shear by (0, 1) failed.");
        TEST_ASSERT(::shear(m, Vector2F(0.0f, -2.0f)) == m4, "Shear by (0, -2) failed.");
    }
};

class Transform3DTest : public test::suite
{
public:
    Transform3DTest()
        : suite("Transform3DTest")
    {
        add_test([this]() { createTranslate(); }, "createTranslate");
        add_test([this]() { createRotate(); }, "createRotate");
        add_test([this]() { createScale(); }, "createScale");
        add_test([this]() { translate(); }, "translate");
        add_test([this]() { scale(); }, "scale");
        add_test([this]() { rotate(); }, "rotate");
    }

private:
    void createTranslate()
    {
        // clang-format off
        const Matrix4F m = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            1, 2, 3, 1
        };
        // clang-format on

        TEST_ASSERT(createTranslateMatrix(Vector3F(1, 2, 3)) == m, "Create translate matrix from (1, 2, 3) failed.");
    }

    void createRotate()
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

        TEST_ASSERT(almostEqual(resultx, mx, 1), "Create rotate matrix from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(resulty, my, 1), "Create rotate matrix from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(resultz, mz, 1), "Create rotate matrix from (0, 0, 1) by 90 degrees failed.");

        TEST_ASSERT(almostEqual(result1, m1, 6), "Create rotate matrix from (1, 0, 1) by 12 degrees failed.");
        TEST_ASSERT(almostEqual(result2, m2, 4), "Create rotate matrix from (0, 1, 0) by 259 degrees failed.");
        TEST_ASSERT(almostEqual(result3, m3, 1), "Create rotate matrix from (1, 1, 1) by -49 degrees failed.");
    }

    void createScale()
    {
        // clang-format off
        const Matrix4F m = {
            4, 0, 0, 0,
            0, 3, 0, 0,
            0, 0, 2, 0,
            0, 0, 0, 1
        };
        // clang-format on

        TEST_ASSERT(createScaleMatrix(Vector3F(4, 3, 2)) == m, "Create scale matrix from (4, 3, 2) failed.");
    }

    void translate()
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

        TEST_ASSERT(::translate(m, Vector3F(0, 0, 0)) == m, "Translate matrix to (0, 0, 0) failed.");
        TEST_ASSERT(::translate(m, Vector3F(1, 0, 0)) == m1, "Translate matrix to (1, 0, 0) failed.");
        TEST_ASSERT(::translate(m, Vector3F(0, 1, 0)) == m2, "Translate matrix to (0, 1, 0) failed.");
        TEST_ASSERT(::translate(m, Vector3F(0, 0, 1)) == m3, "Translate matrix to (0, 0, 1) failed.");
        TEST_ASSERT(::translate(m, Vector3F(1, 2, 3)) == m4, "Translate matrix to (1, 2, 3) failed.");
    }

    void scale()
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

        TEST_ASSERT(::scale(m, Vector3F(1, 1, 1)) == m, "Scale matrix to (1, 1, 1) failed.");
        TEST_ASSERT(::scale(m, Vector3F(2, 1, 1)) == m1, "Scale matrix to (2, 1, 1) failed.");
        TEST_ASSERT(::scale(m, Vector3F(1, 2, 1)) == m2, "Scale matrix to (1, 2, 1) failed.");
        TEST_ASSERT(::scale(m, Vector3F(1, 1, 2)) == m3, "Scale matrix to (1, 1, 2) failed.");
    }

    void rotate()
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

        const Matrix4F resultx = ::rotate(m, Vector3F(1, 0, 0), radians(90.0f));
        const Matrix4F resulty = ::rotate(m, Vector3F(0, 1, 0), radians(90.0f));
        const Matrix4F resultz = ::rotate(m, Vector3F(0, 0, 1), radians(90.0f));

        TEST_ASSERT(almostEqual(resultx, mx, 1), "Rotate matrix from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(resulty, my, 1), "Rotate matrix from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(resultz, mz, 1), "Rotate matrix from (0, 0, 1) by 90 degrees failed.");
    }
};

class ProjectionTest : public test::suite
{
public:
    ProjectionTest()
        : suite("ProjectionTest")
    {
        add_test([this]() { orthogonal(); }, "orthogonal");
        add_test([this]() { orthogonal2D(); }, "orthogonal2D");
        add_test([this]() { frustum(); }, "frustum");
        add_test([this]() { perspective(); }, "perspective");
        add_test([this]() { perspectiveFov(); }, "perspectiveFov");
        add_test([this]() { infinitePerspective(); }, "infinitePerspective");
    }

private:
    void orthogonal()
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

        const Matrix4F proj = ::ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);

        TEST_ASSERT(proj == target, "Orthogonal projection matrix is not correct.");

        TEST_ASSERT(proj * v1 == Vector4F(0, 0, 0, 1), "Projection of (0, 0, 0, 1) is not correct.");
        TEST_ASSERT(proj * v2 == Vector4F(0.5, 0.5, 0.5, 1), "Projection of (1, 1, 1, 1) is not correct.");
        TEST_ASSERT(proj * v3 == Vector4F(1, 1, 1, 1), "Projection of (2, 2, 2, 1) is not correct.");
    }

    void orthogonal2D()
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

    void frustum()
    {
        // clang-format off
        const Matrix4F target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -3, -1,
            0, 0, -4, 0
        };
        // clang-format on

        const Matrix4F proj = ::frustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(proj == target, "Frustum projection matrix is not correct.");

        const Vector4F v1{2, 2, -1, 1};
        const Vector4F v2{2, 2, -1.5f, 1};
        const Vector4F v3{2, 2, -2, 1};

        TEST_ASSERT(proj * v1 == Vector4F(2, 2, -1, 1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(proj * v2 == Vector4F(2, 2, 0.5f, 1.5f), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(proj * v3 == Vector4F(2, 2, 2, 2), "Projection of (2, 2, -2, 1) is not correct.");
    }

    void perspective()
    {
        // clang-format off
        const Matrix4F target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -3, -1,
            0, 0, -4, 0
        };
        // clang-format on

        const Matrix4F proj = ::perspective(F32(HALF_PI), 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(proj == target, "Perspective projection matrix is not correct.");

        const Vector4F v1{2, 2, -1, 1};
        const Vector4F v2{2, 2, -1.5f, 1};
        const Vector4F v3{2, 2, -2, 1};

        TEST_ASSERT(proj * v1 == Vector4F(2, 2, -1, 1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(proj * v2 == Vector4F(2, 2, 0.5f, 1.5f), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(proj * v3 == Vector4F(2, 2, 2, 2), "Projection of (2, 2, -2, 1) is not correct.");
    }

    void perspectiveFov()
    {
        const Matrix4F target = ::perspective(F32(HALF_PI), 1.0f, 1.0f, 2.0f);
        const Matrix4F proj   = ::perspectiveFov(F32(HALF_PI), 1.0f, 1.0f, 1.0f, 2.0f);

        TEST_ASSERT(proj == target, "PerspectiveFov projection matrix is not correct.");
    }

    void infinitePerspective()
    {
        // clang-format off
        const Matrix4F target = {
            1, 0, 0,  0,
            0, 1, 0,  0,
            0, 0, -1, -1,
            0, 0, -2, 0
        };
        // clang-format on

        const Matrix4F proj = ::infinitePerspective(F32(HALF_PI), 1.0f, 1.0f);

        TEST_ASSERT(almostEqual(proj, target, 1), "Infinite perspective projection matrix is not correct.");

        const Vector4F v1{2, 2, -1, 1};
        const Vector4F v2{2, 2, -1.5f, 1};
        const Vector4F v3{2, 2, -2, 1};

        const Vector4F test1 = Vector4F(2, 2, -1, 1);
        const Vector4F test2 = Vector4F(2, 2, -0.5f, 1.5f);
        const Vector4F test3 = Vector4F(2, 2, -0.0000001192092895f, 2);

        TEST_ASSERT(almostEqual(proj * v1, test1), "Projection of (2, 2, -1, 1) is not correct.");
        TEST_ASSERT(almostEqual(proj * v2, test2, 1), "Projection of (2, 2, -1.5, 1) is not correct.");
        TEST_ASSERT(almostEqual(proj * v3, test3, 1), "Projection of (2, 2, -2, 1) is not correct.");
    }
};

class HelpersTest : public test::suite
{
public:
    HelpersTest()
        : suite("HelpersTest")
    {
        add_test([this]() { project(); }, "project");
        add_test([this]() { pickRegion(); }, "pickRegion");
        add_test([this]() { lookAt(); }, "lookAt");
    }

private:
    void project()
    {
        const F32 near = 1.0f;
        const F32 far  = 10.0f;

        const F32 width  = 480.0f;
        const F32 height = 320.0f;

        const Matrix4F model;
        const Matrix4F proj = perspectiveFov(F32(HALF_PI), width, height, near, far);

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

        const Vector3F project1 = ::project(obj1, model, proj, viewport);
        const Vector3F project2 = ::project(obj2, model, proj, viewport);
        const Vector3F project3 = ::project(obj3, model, proj, viewport);
        const Vector3F project4 = ::project(obj4, model, proj, viewport);
        const Vector3F project5 = ::project(obj5, model, proj, viewport);

        TEST_ASSERT(almostEqual(project1, projected1), "Projection of (0, 0, -1) is not correct.");
        TEST_ASSERT(almostEqual(project2, projected2), "Projection of (0, 1, -1) is not correct.");
        TEST_ASSERT(almostEqual(project3, projected3), "Projection of (1.5, 0, -1) is not correct.");
        TEST_ASSERT(almostEqual(project4, projected4), "Projection of (-1.5, -1, -1) is not correct.");
        TEST_ASSERT(almostEqual(project5, projected5), "Projection of (0, 0, -10) is not correct.");

        const Vector3F unproject1 = ::unProject(project1, model, proj, viewport);
        const Vector3F unproject2 = ::unProject(project2, model, proj, viewport);
        const Vector3F unproject3 = ::unProject(project3, model, proj, viewport);
        const Vector3F unproject4 = ::unProject(project4, model, proj, viewport);
        const Vector3F unproject5 = ::unProject(project5, model, proj, viewport);

        TEST_ASSERT(almostEqual(unproject1, obj1), "UnProjection of (0, 0, -1) is not correct.");
        TEST_ASSERT(almostEqual(unproject2, obj2), "UnProjection of (0, 1, -1) is not correct.");
        TEST_ASSERT(almostEqual(unproject3, obj3), "UnProjection of (1.5, 0, -1) is not correct.");
        TEST_ASSERT(almostEqual(unproject4, obj4), "UnProjection of (-1.5, -1, -1) is not correct.");
        TEST_ASSERT(almostEqual(unproject5, obj5, 2), "UnProjection of (0, 0, -10) is not correct.");
    }

    void pickRegion()
    {
        // clang-format off
        const Matrix4F region = {
            2, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            2, 2, 0, 1
        };
        // clang-format on

        const F32 width  = 480.0f;
        const F32 height = 320.0f;

        const Vector4F viewport{0, 0, width, height};

        const Matrix4F result = ::pickMatrix(Vector2F(0, 0), Vector2F(width / 2, height / 2), viewport);

        TEST_ASSERT(result == region, "Pick region matrix is not correct");
    }

    void lookAt()
    {
        // clang-format off
        const Matrix4F lookat = {
            0, 0, -1, 0,
            0, 1, 0,  0,
            1, 0, 0,  0,
            0, 0, 0,  1
        };
        // clang-format on

        const Vector3F eye(0, 0, 0);
        const Vector3F center(1, 0, 0);
        const Vector3F up(0, 1, 0);

        const Matrix4F result = ::lookAt(eye, center, up);

        TEST_ASSERT(result == lookat, "lookAt matrix is not correct.");
    }
};

int main()
{
    return run_tests(Transform2DTest(), Transform3DTest(), ProjectionTest(), HelpersTest());
}
