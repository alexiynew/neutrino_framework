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
        Matrix3F m = {1, 4, 7, 2, 5, 8, 3, 6, 9};

        Matrix3F r30 = {1.8660254f, 5.96410162f, 10.06217783f, 1.23205081f, 2.33012702f, 3.42820323f, 3.0f, 6.0f, 9.0f};
        Matrix3F r45 = {
        2.121320340f, 6.363961030f, 10.606601720f, 0.707106780f, 0.707106780f, 0.707106780f, 3.0f, 6.0f, 9.0f,
        };
        Matrix3F r60 = {2.232050810f,  6.330127020f, 10.428203230f, 0.13397460f, -0.964101620f,
                        -2.062177830f, 3.0f,         6.0f,          9.0f};
        Matrix3F r90 = {2.0f, 5.0f, 8.0f, -1.0f, -4.0f, -7.0f, 3.0f, 6.0f, 9.0f};

        Matrix3F r180 = {-1.0f, -4.0f, -7.0f, -2.0f, -5.0f, -8.0f, 3.0f, 6.0f, 9.0f};
        Matrix3F r300 = {-1.23205081f, -2.33012702f, -3.42820323f, 1.8660254f, 5.96410162f,
                         10.06217783f, 3.0f,         6.0f,         9.0f};
        Matrix3F r270 = {-2.0f, -5.0f, -8.0f, 1.0f, 4.0f, 7.0f, 3.0f, 6.0f, 9.0f};

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

        // std::cout << ::shearX(m, -2.0f);

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

int main()
{

    std::vector<std::unique_ptr<test::Suite>> tests;

    tests.emplace_back(new Transform2DTest());

    bool all_successed = true;

    for (auto& test : tests) {
        test->run();
        all_successed &= test->isSuccessed();
    }

    return all_successed ? 0 : 1;
}
