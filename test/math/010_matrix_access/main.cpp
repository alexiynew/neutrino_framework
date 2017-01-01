#include <debug.hpp>

#include <math/math.hpp>

using namespace framework::math;

int main()
{

    Matrix2x4F m24;
    Matrix2x3F m23;
    Matrix2x2F m22;
    Matrix3x4F m34;
    Matrix3x3F m33;
    Matrix3x2F m32;
    Matrix4x4F m44;
    Matrix4x3F m43;
    Matrix4x2F m42;

    ASSERT_MSG(m44[0] == Vector4F(1, 0, 0, 0) && m44[1] == Vector4F(0, 1, 0, 0) && m44[2] == Vector4F(0, 0, 1, 0) &&
               m44[3] == Vector4F(0, 0, 0, 1),
               "matrix 4f access failed");
    ASSERT_MSG(m34[0] == Vector4F(1, 0, 0, 0) && m34[1] == Vector4F(0, 1, 0, 0) && m34[2] == Vector4F(0, 0, 1, 0),
               "matrix 34f access failed");
    ASSERT_MSG(m24[0] == Vector4F(1, 0, 0, 0) && m24[1] == Vector4F(0, 1, 0, 0), "matrix 24f access failed");

    ASSERT_MSG(m43[0] == Vector3F(1, 0, 0) && m43[1] == Vector3F(0, 1, 0) && m43[2] == Vector3F(0, 0, 1) &&
               m43[3] == Vector3F(0, 0, 0),
               "matrix 43f access failed");
    ASSERT_MSG(m33[0] == Vector3F(1, 0, 0) && m33[1] == Vector3F(0, 1, 0) && m33[2] == Vector3F(0, 0, 1),
               "matrix 3f access "
               "failed");
    ASSERT_MSG(m23[0] == Vector3F(1, 0, 0) && m23[1] == Vector3F(0, 1, 0), "matrix 23f access failed");

    ASSERT_MSG(m42[0] == Vector2F(1, 0) && m42[1] == Vector2F(0, 1) && m42[2] == Vector2F(0, 0) && m42[3] == Vector2F(0, 0),
               "matrix 42f access failed");
    ASSERT_MSG(m32[0] == Vector2F(1, 0) && m32[1] == Vector2F(0, 1) && m32[2] == Vector2F(0, 0),
               "matrix 32f access failed");
    ASSERT_MSG(m22[0] == Vector2F(1, 0) && m22[1] == Vector2F(0, 1), "matrix 2f access failed");

    ASSERT_MSG(m44.column(0) == Vector4F(1, 0, 0, 0) && m44.column(1) == Vector4F(0, 1, 0, 0) &&
               m44.column(2) == Vector4F(0, 0, 1, 0) && m44.column(3) == Vector4F(0, 0, 0, 1),
               "matrix 4f access failed");
    ASSERT_MSG(m34.column(0) == Vector4F(1, 0, 0, 0) && m34.column(1) == Vector4F(0, 1, 0, 0) &&
               m34.column(2) == Vector4F(0, 0, 1, 0),
               "matrix 34f access failed");
    ASSERT_MSG(m24.column(0) == Vector4F(1, 0, 0, 0) && m24.column(1) == Vector4F(0, 1, 0, 0),
               "matrix 24f access failed");

    ASSERT_MSG(m43.column(0) == Vector3F(1, 0, 0) && m43.column(1) == Vector3F(0, 1, 0) &&
               m43.column(2) == Vector3F(0, 0, 1) && m43.column(3) == Vector3F(0, 0, 0),
               "matrix 43f access failed");
    ASSERT_MSG(m33.column(0) == Vector3F(1, 0, 0) && m33.column(1) == Vector3F(0, 1, 0) && m33.column(2) == Vector3F(0, 0, 1),
               "matrix 3f access failed");
    ASSERT_MSG(m23.column(0) == Vector3F(1, 0, 0) && m23.column(1) == Vector3F(0, 1, 0), "matrix 23f access failed");

    ASSERT_MSG(m42.column(0) == Vector2F(1, 0) && m42.column(1) == Vector2F(0, 1) && m42.column(2) == Vector2F(0, 0) &&
               m42.column(3) == Vector2F(0, 0),
               "matrix 42f access failed");
    ASSERT_MSG(m32.column(0) == Vector2F(1, 0) && m32.column(1) == Vector2F(0, 1) && m32.column(2) == Vector2F(0, 0),
               "matrix 32f access failed");
    ASSERT_MSG(m22.column(0) == Vector2F(1, 0) && m22.column(1) == Vector2F(0, 1), "matrix 2f access failed");

    ASSERT_MSG(m44.row(0) == Vector4F(1, 0, 0, 0) && m44.row(1) == Vector4F(0, 1, 0, 0) &&
               m44.row(2) == Vector4F(0, 0, 1, 0) && m44.row(3) == Vector4F(0, 0, 0, 1),
               "matrix 4f access failed");
    ASSERT_MSG(m34.row(0) == Vector3F(1, 0, 0) && m34.row(1) == Vector3F(0, 1, 0) && m34.row(2) == Vector3F(0, 0, 1) &&
               m34.row(3) == Vector3F(0, 0, 0),
               "matrix 34f access failed");
    ASSERT_MSG(m24.row(0) == Vector2F(1, 0) && m24.row(1) == Vector2F(0, 1) && m24.row(2) == Vector2F(0, 0) &&
               m24.row(3) == Vector2F(0, 0),
               "matrix 24f access failed");

    ASSERT_MSG(m43.row(0) == Vector4F(1, 0, 0, 0) && m43.row(1) == Vector4F(0, 1, 0, 0) && m43.row(2) == Vector4F(0, 0, 1, 0),
               "matrix 43f access failed");
    ASSERT_MSG(m33.row(0) == Vector3F(1, 0, 0) && m33.row(1) == Vector3F(0, 1, 0) && m33.row(2) == Vector3F(0, 0, 1),
               "matrix 33f access failed");
    ASSERT_MSG(m23.row(0) == Vector2F(1, 0) && m23.row(1) == Vector2F(0, 1) && m23.row(2) == Vector2F(0, 0),
               "matrix 23f access "
               "failed");

    ASSERT_MSG(m42.row(0) == Vector4F(1, 0, 0, 0) && m42.row(1) == Vector4F(0, 1, 0, 0), "matrix 42f access failed");
    ASSERT_MSG(m32.row(0) == Vector3F(1, 0, 0) && m32.row(1) == Vector3F(0, 1, 0), "matrix 32f access failed");
    ASSERT_MSG(m22.row(0) == Vector2F(1, 0) && m22.row(1) == Vector2F(0, 1), "matrix 22f access failed");

    // TODO add pointer access
    /*

                double* p44 = m44.data();
                double* p34 = m34.data();
                double* p24 = m24.data();

                double* p43 = m43.data();
                double* p33 = m33.data();
                double* p23 = m23.data();

                double* p42 = m42.data();
                double* p32 = m32.data();
                double* p22 = m22.data();

                TEST_ASSERT(p44[0] == 0.0 && p44[1] == 1.0 && p44[2] == 2.0 && p44[3] == 3.0 && p44[4] == 0.0 && p44[5]
       ==
           1.0 &&
                            p44[6] == 2.0 && p44[7] == 3.0 && p44[8] == 0.0 && p44[9] == 1.0 && p44[10] == 2.0 &&
                            p44[11] == 3.0 && p44[12] == 0.0 && p44[13] == 1.0 && p44[14] == 2.0 && p44[15] == 3.0,
                            "matrix4x4 pointer access");
                TEST_ASSERT(p34[0] == 0.0 && p34[1] == 1.0 && p34[2] == 2.0 && p34[3] == 3.0 && p34[4] == 0.0 && p34[5]
       ==
           1.0 &&
                            p34[6] == 2.0 && p34[7] == 3.0 && p34[8] == 0.0 && p34[9] == 1.0 && p34[10] == 2.0 &&
       p34[11] ==
           3.0,
                            "matrix3x4 pointer access");
                TEST_ASSERT(p24[0] == 0.0 && p24[1] == 1.0 && p24[2] == 2.0 && p24[3] == 3.0 && p24[4] == 0.0 &&
                            p24[5] == 1.0 && p24[6] == 2.0 && p24[7] == 3.0,
                            "matrix2x4 pointer access");

                TEST_ASSERT(p43[0] == 0.0 && p43[1] == 1.0 && p43[2] == 2.0 && p43[3] == 0.0 && p43[4] == 1.0 && p43[5]
       ==
           2.0 &&
                            p43[6] == 0.0 && p43[7] == 1.0 && p43[8] == 2.0 && p43[9] == 0.0 && p43[10] == 1.0 &&
       p43[11] ==
           2.0,
                            "matrix4x3 pointer access");
                TEST_ASSERT(p33[0] == 0.0 && p33[1] == 1.0 && p33[2] == 2.0 && p33[3] == 0.0 && p33[4] == 1.0 &&
                            p33[5] == 2.0 && p33[6] == 0.0 && p33[7] == 1.0 && p33[8] == 2.0,
                            "matrix3x3 pointer access");
                TEST_ASSERT(p23[0] == 0.0 && p23[1] == 1.0 && p23[2] == 2.0 && p23[3] == 0.0 && p23[4] == 1.0 && p23[5]
       ==
           2.0,
                            "matrix2x3 pointer access");

                TEST_ASSERT(p42[0] == 0.0 && p42[1] == 1.0 && p42[2] == 0.0 && p42[3] == 1.0 && p42[4] == 0.0 &&
                            p42[5] == 1.0 && p42[6] == 0.0 && p42[7] == 1.0,
                            "matrix4x2 pointer access");
                TEST_ASSERT(p32[0] == 0.0 && p32[1] == 1.0 && p32[2] == 0.0 && p32[3] == 1.0 && p32[4] == 0.0 && p32[5]
       ==
           1.0,
                            "matrix3x2 pointer access");
                TEST_ASSERT(p22[0] == 0.0 && p22[1] == 1.0 && p22[2] == 0.0 && p22[3] == 1.0, "matrix2x2 pointer
       access");
        */

    return 0;
}
