#include <iostream>
#include <memory>
#include <vector>

#include <math/fmath.h>
#include <unittest/test.h>

using namespace framework::math;

class Transform2DTest : public test::Suite
{
public:
    Transform2DTest()
    {
        ADD_TEST(Transform2DTest::translate);
        ADD_TEST(Transform2DTest::rotate);
        ADD_TEST(Transform2DTest::scale);
        ADD_TEST(Transform2DTest::shearX);
        ADD_TEST(Transform2DTest::shearY);
    }

private:
    void translate()
    {
        Matrix3F m  = {1, 4, 7, 2, 5, 8, 3, 6, 9};
        Matrix3F m1 = {1, 4, 7, 2, 5, 8, 33, 96, 159};

        TEST_ASSERT(::translate(m, Vector2F(10, 10)) == m1, "Translate by (10, 10) failed.");
        TEST_ASSERT(::translate(m1, Vector2F(-10, -10)) == m, "Translate by (-10, -10) failed.");
        TEST_ASSERT(::translate(m, Vector2F(0, 0)) == m, "Translate by (0, 0) failed.");
    }

    void rotate()
    {
        // clang-format off
        Matrix3F m = {1, 4, 7,
                      2, 5, 8,
                      3, 6, 9};

        Matrix3F r30 = {1.8660254f,  5.96410162f, 10.06217783f,
                        1.23205081f, 2.33012702f, 3.42820323f,
                        3.0f,        6.0f,        9.0f};

        Matrix3F r45 = {2.121320340f, 6.363961030f, 10.606601720f,
                        0.707106780f, 0.707106780f, 0.707106780f,
                        3.0f,         6.0f,         9.0f};

        Matrix3F r60 = {2.232050810f,  6.330127020f,  10.428203230f,
                        0.13397460f,  -0.964101620f, -2.062177830f,
                        3.0f,          6.0f,          9.0f};

        Matrix3F r90 = { 2.0f,  5.0f,  8.0f,
                        -1.0f, -4.0f, -7.0f,
                         3.0f,  6.0f,  9.0f};

        Matrix3F r180 = {-1.0f, -4.0f, -7.0f,
                         -2.0f, -5.0f, -8.0f,
                         3.0f,   6.0f,  9.0f};

        Matrix3F r300 = {-1.23205081f, -2.33012702f, -3.42820323f,
                          1.8660254f,   5.96410162f,  10.06217783f,
                          3.0f,         6.0f,         9.0f};

        Matrix3F r270 = {-2.0f, -5.0f, -8.0f,
                          1.0f,  4.0f,  7.0f,
                          3.0f,  6.0f,  9.0f};
        // clang-format on

        TEST_ASSERT(almostEqual(::rotate(m, radians(30.0f)), r30, 1), "Rotate by 30 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(45.0f)), r45, 2), "Rotate by 45 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(60.0f)), r60, 4), "Rotate by 60 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(90.0f)), r90, 1), "Rotate by 90 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(180.0f)), r180, 1), "Rotate by 180 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(270.0f)), r270, 1), "Rotate by 270 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(300.0f)), r300, 2), "Rotate by 300 deg failed.");

        TEST_ASSERT(almostEqual(::rotate(m, radians(-90.0f)), r270, 1), "Rotate by -180 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(-180.0f)), r180, 1), "Rotate by -180 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(-270.0f)), r90, 1), "Rotate by -270 deg failed.");

        TEST_ASSERT(almostEqual(::rotate(m, radians(0.0f)), m, 1), "Rotate by 0 deg failed.");
        TEST_ASSERT(almostEqual(::rotate(m, radians(360.0f)), m, 2), "Rotate by 360 deg failed.");
    }

    void scale()
    {
        Matrix3F m = {1, 4, 7, 2, 5, 8, 3, 6, 9};

        Matrix3F m11 = {1, 4, 7, 2, 5, 8, 3, 6, 9};
        Matrix3F m55 = {5, 20, 35, 10, 25, 40, 3, 6, 9};
        Matrix3F m12 = {1, 4, 7, 4, 10, 16, 3, 6, 9};
        Matrix3F m21 = {2, 8, 14, 2, 5, 8, 3, 6, 9};
        Matrix3F m01 = {0, 0, 0, 2, 5, 8, 3, 6, 9};
        Matrix3F m10 = {1, 4, 7, 0, 0, 0, 3, 6, 9};
        Matrix3F m00 = {0, 0, 0, 0, 0, 0, 3, 6, 9};

        TEST_ASSERT(::scale(m, Vector2F(1, 1)) == m11, "Scale by (1, 1) failed.");
        TEST_ASSERT(::scale(m, Vector2F(5, 5)) == m55, "Scale by (5, 5) failed.");
        TEST_ASSERT(::scale(m, Vector2F(1, 2)) == m12, "Scale by (1, 2) failed.");
        TEST_ASSERT(::scale(m, Vector2F(2, 1)) == m21, "Scale by (2, 1) failed.");
        TEST_ASSERT(::scale(m, Vector2F(0, 1)) == m01, "Scale by (0, 1) failed.");
        TEST_ASSERT(::scale(m, Vector2F(1, 0)) == m10, "Scale by (1, 0) failed.");
        TEST_ASSERT(::scale(m, Vector2F(0, 0)) == m00, "Scale by (0, 0) failed.");
    }

    void shearX()
    {
        Matrix3F m = {1, 4, 7, 2, 5, 8, 3, 6, 9};

        Matrix3F m1 = {3, 9, 15, 2, 5, 8, 3, 6, 9};
        Matrix3F m2 = {-3, -6, -9, 2, 5, 8, 3, 6, 9};

        TEST_ASSERT(::shearX(m, 0.0f) == m, "ShearX by 0 failed.");
        TEST_ASSERT(::shearX(m, 1.0f) == m1, "ShearX by 1 failed.");
        TEST_ASSERT(::shearX(m, -2.0f) == m2, "ShearX by -2 failed.");
    }

    void shearY()
    {
        Matrix3F m = {1, 4, 7, 2, 5, 8, 3, 6, 9};

        Matrix3F m1 = {1, 4, 7, 3, 9, 15, 3, 6, 9};
        Matrix3F m2 = {1, 4, 7, 0, -3, -6, 3, 6, 9};

        TEST_ASSERT(::shearY(m, 0.0f) == m, "ShearY by 0 failed.");
        TEST_ASSERT(::shearY(m, 1.0f) == m1, "ShearY by 1 failed.");
        TEST_ASSERT(::shearY(m, -2.0f) == m2, "ShearY by -2 failed.");
    }
};

class Transform3DTest : public test::Suite
{
public:
    Transform3DTest()
    {
        ADD_TEST(Transform3DTest::createTranslate);
        ADD_TEST(Transform3DTest::createRotate);
        ADD_TEST(Transform3DTest::createScale);
        ADD_TEST(Transform3DTest::translate);
        ADD_TEST(Transform3DTest::scale);
        ADD_TEST(Transform3DTest::rotate);
    }

private:
    void createTranslate()
    {
        // clang-format off
        Matrix4F m = {1, 0, 0, 0,
                      0, 1, 0, 0,
                      0, 0, 1, 0,
                      1, 2, 3, 1};
        // clang-format on

        TEST_ASSERT(createTranslateMatrix(Vector3F(1, 2, 3)) == m, "Create translate matrix from (1, 2, 3) failed.");
    }

    void createRotate()
    {
        // clang-format off
        Matrix4F mx = {1.0f,  0.0f,                   0.0f,                  0.0f,
                       0.0f, -0.000000043711388286f,  1.0f,                  0.0f,
                       0.0f, -1.0f,                  -0.000000043711388286f, 0.0f,
                       0.0f,  0.0f,                   0.0f,                  1.0f};

        Matrix4F my = {-0.000000043711388286f, 0.0f, -1.0f,                  0.0f,
                        0.0f,                  1.0f,  0.0f,                  0.0f,
                        1.0f,                  0.0f, -0.000000043711388286f, 0.0f,
                        0.0f,                  0.0f,  0.0f,                  1.0f};

        Matrix4F mz = {-0.000000043711388286f,  1.0f,                  0.0f, 0.0f,
                       -1.0f,                  -0.000000043711388286f, 0.0f, 0.0f,
                        0.0f,                   0.0f,                  1.0f, 0.0f,
                        0.0f,                   0.0f,                  0.0f, 1.0f};

        Matrix4F m1 = {1.0f,             0.207911690818f, 0.0218523992662f,0.0f,
                      -0.207911690818f,  0.978147600734f, 0.207911690818f, 0.0f,
                       0.0218523992662f,-0.207911690818f, 1.0f,            0.0f,
                       0.0f,             0.0f,            0.0f,            1.0f};

        Matrix4F m2 = {-0.190808995377f, 0.0f,  0.981627183448f, 0.0f,
                        0.0f,            1.0f,  0.0f,            0.0f,
                       -0.981627183448f, 0.0f, -0.190808995377f, 0.0f,
                        0.0f,            0.0f,  0.0f,            1.0f};

        Matrix4F m3 = { 1.0f,            -0.410768609213f,  1.09865055123f,  0.0f,
                        1.09865055123f,   1.0f,            -0.410768609213f, 0.0f,
                       -0.410768609213f,  1.09865055123f,   1.0f,            0.0f,
                        0.0f,             0.0f,             0.0f,            1.0f};
        // clang-format on

        TEST_ASSERT(almostEqual(createRotateMatrix(Vector3F(1, 0, 0), radians(90.0f)), mx, 1),
                    "Create rotate matrix from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(createRotateMatrix(Vector3F(0, 1, 0), radians(90.0f)), my, 1),
                    "Create rotate matrix from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(createRotateMatrix(Vector3F(0, 0, 1), radians(90.0f)), mz, 1),
                    "Create rotate matrix from (0, 0, 1) by 90 degrees failed.");

        TEST_ASSERT(almostEqual(createRotateMatrix(Vector3F(1, 0, 1), radians(12.0f)), m1, 6),
                    "Create rotate matrix from (1, 0, 1) by 12 degrees failed.");
        TEST_ASSERT(almostEqual(createRotateMatrix(Vector3F(0, 1, 0), radians(259.0f)), m2, 4),
                    "Create rotate matrix from (0, 1, 0) by 259 degrees failed.");
        TEST_ASSERT(almostEqual(createRotateMatrix(Vector3F(1, 1, 1), radians(-49.0f)), m3, 1),
                    "Create rotate matrix from (1, 1, 1) by -49 degrees failed.");
    }

    void createScale()
    {
        // clang-format off
        Matrix4F m = {4, 0, 0, 0,
                      0, 3, 0, 0,
                      0, 0, 2, 0,
                      0, 0, 0, 1};
        // clang-format on

        TEST_ASSERT(createScaleMatrix(Vector3F(4, 3, 2)) == m, "Create scale matrix from (4, 3, 2) failed.");
    }

    void translate()
    {
        // clang-format off
        Matrix4F m = {1, 2, 3, 4,
                      4, 1, 2, 3,
                      3, 4, 1, 2,
                      2, 3, 4, 1};

        Matrix4F m1 = {1, 2, 3, 4,
                       4, 1, 2, 3,
                       3, 4, 1, 2,
                       3, 5, 7, 5};

        Matrix4F m2 = {1, 2, 3, 4,
                       4, 1, 2, 3,
                       3, 4, 1, 2,
                       6, 4, 6, 4};

        Matrix4F m3 = {1, 2, 3, 4,
                       4, 1, 2, 3,
                       3, 4, 1, 2,
                       5, 7, 5, 3};

        Matrix4F m4 = {1,  2,  3,  4,
                       4,  1,  2,  3,
                       3,  4,  1,  2,
                       20, 19, 14, 17};
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
        Matrix4F m = {1, 2, 3, 4,
                      4, 1, 2, 3,
                      3, 4, 1, 2,
                      2, 3, 4, 1};

        Matrix4F m1 = {2, 4, 6, 8,
                       4, 1, 2, 3,
                       3, 4, 1, 2,
                       2, 3, 4, 1};

        Matrix4F m2 = {1, 2, 3, 4,
                       8, 2, 4, 6,
                       3, 4, 1, 2,
                       2, 3, 4, 1};

        Matrix4F m3 = {1, 2, 3, 4,
                       4, 1, 2, 3,
                       6, 8, 2, 4,
                       2, 3, 4, 1};
        // clang-format on

        TEST_ASSERT(::scale(m, Vector3F(1, 1, 1)) == m, "Scale matrix to (1, 1, 1) failed.");
        TEST_ASSERT(::scale(m, Vector3F(2, 1, 1)) == m1, "Scale matrix to (2, 1, 1) failed.");
        TEST_ASSERT(::scale(m, Vector3F(1, 2, 1)) == m2, "Scale matrix to (1, 2, 1) failed.");
        TEST_ASSERT(::scale(m, Vector3F(1, 1, 2)) == m3, "Scale matrix to (1, 1, 2) failed.");
    }

    void rotate()
    {
        // clang-format off
        Matrix4F m = {1, 2, 3, 4,
                      4, 1, 2, 3,
                      3, 4, 1, 2,
                      2, 3, 4, 1};

        Matrix4F mx = {1,  2,  3,  4,
                       3,  4,  1,  2,
                       -4, -1, -2, -3,
                       2,  3,  4,  1};

        Matrix4F my = {-3, -4, -1, -2,
                        4, 1,  2,  3,
                        1, 2,  3,  4,
                        2, 3,  4,  1};

        Matrix4F mz = {4,  1,  2,  3,
                       -1, -2, -3, -4,
                       3,  4,  1,  2,
                       2,  3,  4,  1};
        // clang-format on

        TEST_ASSERT(almostEqual(::rotate(m, Vector3F(1, 0, 0), radians(90.0f)), mx, 1),
                    "Rotate matrix from (1, 0, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(::rotate(m, Vector3F(0, 1, 0), radians(90.0f)), my, 1),
                    "Rotate matrix from (0, 1, 0) by 90 degrees failed.");
        TEST_ASSERT(almostEqual(::rotate(m, Vector3F(0, 0, 1), radians(90.0f)), mz, 1),
                    "Rotate matrix from (0, 0, 1) by 90 degrees failed.");
    }
};

int main()
{
    std::vector<std::unique_ptr<test::Suite>> tests;

    tests.emplace_back(new Transform2DTest());
    tests.emplace_back(new Transform3DTest());

    bool all_succeeded = true;

    for (auto& test : tests) {
        test->run();
        all_succeeded = all_succeeded && test->isSuccessed();
    }

    return all_succeeded ? 0 : 1;
}
