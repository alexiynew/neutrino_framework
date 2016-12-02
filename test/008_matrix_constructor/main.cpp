#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // matrix size, default constructor and one argument constructor test
    {
        constexpr Matrix2F m2;
        constexpr Matrix2x3F m23;
        constexpr Matrix2x4F m24;

        constexpr Matrix3F m3;
        constexpr Matrix3x2F m32;
        constexpr Matrix3x4F m34;

        constexpr Matrix4F m4;
        constexpr Matrix4x2F m42;
        constexpr Matrix4x3F m43;

        static_assert(sizeof(m2) == sizeof(float) * 2 * 2 && m2.size() == 2, "matrix size ASSERT_MSG");
        static_assert(sizeof(m23) == sizeof(float) * 2 * 3 && m23.size() == 2, "matrix size ASSERT_MSG");
        static_assert(sizeof(m24) == sizeof(float) * 2 * 4 && m24.size() == 2, "matrix size ASSERT_MSG");

        static_assert(sizeof(m3) == sizeof(float) * 3 * 3 && m3.size() == 3, "matrix size ASSERT_MSG");
        static_assert(sizeof(m32) == sizeof(float) * 3 * 2 && m32.size() == 3, "matrix size ASSERT_MSG");
        static_assert(sizeof(m34) == sizeof(float) * 3 * 4 && m34.size() == 3, "matrix size ASSERT_MSG");

        static_assert(sizeof(m4) == sizeof(float) * 4 * 4 && m4.size() == 4, "matrix size ASSERT_MSG");
        static_assert(sizeof(m42) == sizeof(float) * 4 * 2 && m42.size() == 4, "matrix size ASSERT_MSG");
        static_assert(sizeof(m43) == sizeof(float) * 4 * 3 && m43.size() == 4, "matrix size ASSERT_MSG");

        ASSERT_MSG(m2 == Matrix2F(1, 0, 0, 1), "matrix2 default constructor");

        ASSERT_MSG(m23 == Matrix2x3F(1, 0, 0, 0, 1, 0), "matrix2x3 default constructor");

        ASSERT_MSG(m24 == Matrix2x4F(1, 0, 0, 0, 0, 1, 0, 0), "matrix2x4 default constructor");

        ASSERT_MSG(m3 == Matrix3F(1, 0, 0, 0, 1, 0, 0, 0, 1), "matrix3 default constructor");

        ASSERT_MSG(m32 == Matrix3x2F(1, 0, 0, 1, 0, 0), "matrix3x2 default constructor");

        ASSERT_MSG(m34 == Matrix3x4F(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0), "matrix3x4 default constructor");

        ASSERT_MSG(m4 == Matrix4F(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), "matrix4 default constructor");

        ASSERT_MSG(m42 == Matrix4x2F(1, 0, 0, 1, 0, 0, 0, 0), "matrix4x2 default constructor");

        ASSERT_MSG(m43 == Matrix4x3F(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), "matrix4x3 default constructor");

        ASSERT_MSG(m2 == Matrix2F(1), "matrix2 one argument constructor");
        ASSERT_MSG(m23 == Matrix2x3F(1), "matrix2x3 one argument constructor");
        ASSERT_MSG(m24 == Matrix2x4F(1), "matrix2x4 one argument constructor");

        ASSERT_MSG(m3 == Matrix3F(1), "matrix3 one argument constructor");
        ASSERT_MSG(m32 == Matrix3x2F(1), "matrix3x2 one argument constructor");
        ASSERT_MSG(m34 == Matrix3x4F(1), "matrix3x4 one argument constructor");

        ASSERT_MSG(m4 == Matrix4F(1), "matrix4 one argument constructor");
        ASSERT_MSG(m42 == Matrix4x2F(1), "matrix4x2 one argument constructor");
        ASSERT_MSG(m43 == Matrix4x3F(1), "matrix4x3 one argument constructor");
    }

    // matrix from pinter costructor
    {
        F64 data4[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
        F64 data3[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        F64 data2[] = {0, 1, 0, 1, 0, 1, 0, 1};

        Matrix4x4D m44(data4);
        Matrix3x4D m34(data4);
        Matrix2x4D m24(data4);

        Matrix4x3D m43(data3);
        Matrix3x3D m33(data3);
        Matrix2x3D m23(data3);

        Matrix4x2D m42(data2);
        Matrix3x2D m32(data2);
        Matrix2x2D m22(data2);

        ASSERT_MSG(m44 == Matrix4x4D(Vector4D(0, 1, 2, 3), Vector4D(0, 1, 2, 3), Vector4D(0, 1, 2, 3), Vector4D(0, 1, 2, 3)),
                   "matrix4x4 from pointer constructor");
        ASSERT_MSG(m34 == Matrix3x4D(Vector4D(0, 1, 2, 3), Vector4D(0, 1, 2, 3), Vector4D(0, 1, 2, 3)),
                   "matrix3x4 from pointer "
                   "constructor");
        ASSERT_MSG(m24 == Matrix2x4D(Vector4D(0, 1, 2, 3), Vector4D(0, 1, 2, 3)), "matrix2x4 from pointer constructor");

        ASSERT_MSG(m43 == Matrix4x3D(Vector3D(0, 1, 2), Vector3D(0, 1, 2), Vector3D(0, 1, 2), Vector3D(0, 1, 2)),
                   "matrix4x3 from pointer constructor");
        ASSERT_MSG(m33 == Matrix3x3D(Vector3D(0, 1, 2), Vector3D(0, 1, 2), Vector3D(0, 1, 2)),
                   "matrix3x3 from pointer "
                   "constructor");
        ASSERT_MSG(m23 == Matrix2x3D(Vector3D(0, 1, 2), Vector3D(0, 1, 2)), "matrix2x3 from pointer constructor");

        ASSERT_MSG(m42 == Matrix4x2D(Vector2D(0, 1), Vector2D(0, 1), Vector2D(0, 1), Vector2D(0, 1)),
                   "matrix4x3 from pointer "
                   "constructor");
        ASSERT_MSG(m32 == Matrix3x2D(Vector2D(0, 1), Vector2D(0, 1), Vector2D(0, 1)),
                   "matrix3x3 from pointer constructor");
        ASSERT_MSG(m22 == Matrix2x2D(Vector2D(0, 1), Vector2D(0, 1)), "matrix2x3 from pointer constructor");

        F64* p44 = m44.data();
        F64* p34 = m34.data();
        F64* p24 = m24.data();

        F64* p43 = m43.data();
        F64* p33 = m33.data();
        F64* p23 = m23.data();

        F64* p42 = m42.data();
        F64* p32 = m32.data();
        F64* p22 = m22.data();

        ASSERT_MSG(p44[0] == 0.0 && p44[1] == 1.0 && p44[2] == 2.0 && p44[3] == 3.0 && p44[4] == 0.0 && p44[5] == 1.0 &&
                   p44[6] == 2.0 && p44[7] == 3.0 && p44[8] == 0.0 && p44[9] == 1.0 && p44[10] == 2.0 &&
                   p44[11] == 3.0 && p44[12] == 0.0 && p44[13] == 1.0 && p44[14] == 2.0 && p44[15] == 3.0,
                   "matrix4x4 pointer access");
        ASSERT_MSG(p34[0] == 0.0 && p34[1] == 1.0 && p34[2] == 2.0 && p34[3] == 3.0 && p34[4] == 0.0 && p34[5] == 1.0 &&
                   p34[6] == 2.0 && p34[7] == 3.0 && p34[8] == 0.0 && p34[9] == 1.0 && p34[10] == 2.0 && p34[11] == 3.0,
                   "matrix3x4 pointer access");
        ASSERT_MSG(p24[0] == 0.0 && p24[1] == 1.0 && p24[2] == 2.0 && p24[3] == 3.0 && p24[4] == 0.0 && p24[5] == 1.0 &&
                   p24[6] == 2.0 && p24[7] == 3.0,
                   "matrix2x4 pointer access");

        ASSERT_MSG(p43[0] == 0.0 && p43[1] == 1.0 && p43[2] == 2.0 && p43[3] == 0.0 && p43[4] == 1.0 && p43[5] == 2.0 &&
                   p43[6] == 0.0 && p43[7] == 1.0 && p43[8] == 2.0 && p43[9] == 0.0 && p43[10] == 1.0 && p43[11] == 2.0,
                   "matrix4x3 pointer access");
        ASSERT_MSG(p33[0] == 0.0 && p33[1] == 1.0 && p33[2] == 2.0 && p33[3] == 0.0 && p33[4] == 1.0 && p33[5] == 2.0 &&
                   p33[6] == 0.0 && p33[7] == 1.0 && p33[8] == 2.0,
                   "matrix3x3 pointer access");
        ASSERT_MSG(p23[0] == 0.0 && p23[1] == 1.0 && p23[2] == 2.0 && p23[3] == 0.0 && p23[4] == 1.0 && p23[5] == 2.0,
                   "matrix2x3 pointer access");

        ASSERT_MSG(p42[0] == 0.0 && p42[1] == 1.0 && p42[2] == 0.0 && p42[3] == 1.0 && p42[4] == 0.0 && p42[5] == 1.0 &&
                   p42[6] == 0.0 && p42[7] == 1.0,
                   "matrix4x2 pointer access");
        ASSERT_MSG(p32[0] == 0.0 && p32[1] == 1.0 && p32[2] == 0.0 && p32[3] == 1.0 && p32[4] == 0.0 && p32[5] == 1.0,
                   "matrix3x2 pointer access");
        ASSERT_MSG(p22[0] == 0.0 && p22[1] == 1.0 && p22[2] == 0.0 && p22[3] == 1.0, "matrix2x2 pointer access");
    }

    // Matrix4F from vectors constructor
    {
        constexpr Matrix4F m(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        ASSERT_MSG(Matrix4F(Vector4D(0, 1, 2, 3), Vector4F(0, 1, 2, 3), Vector4F(0, 1, 2, 3), Vector4I(0, 1, 2, 3)) == m,
                   "matrix4 vector constructor");

        ASSERT_MSG(Matrix4F(Vector3I(0, 1, 2), 3, Vector3F(0, 1, 2), 3, Vector3D(0, 1, 2), 3, Vector3F(0, 1, 2), 3) == m,
                   "matrix4 vector constructor");

        ASSERT_MSG(Matrix4F(0, Vector3F(1, 2, 3), 0, Vector3D(1, 2, 3), 0, Vector3F(1, 2, 3), 0, Vector3I(1, 2, 3)) == m,
                   "matrix4 vector constructor");

        ASSERT_MSG(Matrix4F(Vector2F(0, 1),
                            Vector2D(2, 3),
                            Vector2D(0, 1),
                            Vector2F(2, 3),
                            Vector2F(0, 1),
                            Vector2I(2, 3),
                            Vector2I(0, 1),
                            Vector2F(2, 3)) == m,
                   "matrix4 vector constructor");

        ASSERT_MSG(Matrix4F(Vector2D(0, 1), 2, 3, Vector2F(0, 1), 2, 3, Vector2I(0, 1), 2, 3, Vector2F(0, 1), 2, 3) == m,
                   "matrix4 vector constructor");

        ASSERT_MSG(Matrix4F(0, Vector2D(1, 2), 3, 0, Vector2F(1, 2), 3, 0, Vector2I(1, 2), 3, 0, Vector2F(1, 2), 3) == m,
                   "matrix4 vector constructor");

        ASSERT_MSG(Matrix4F(0, 1, Vector2D(2, 3), 0, 1, Vector2F(2, 3), 0, 1, Vector2I(2, 3), 0, 1, Vector2F(2, 3)) == m,
                   "matrix4 vector constructor");
    }

    // Matrix4x3F from vectors constructor
    {
        constexpr Matrix4x3F m(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2);

        ASSERT_MSG(Matrix4x3F(Vector4F(0, 1, 2, 3), Vector4D(0, 1, 2, 3), Vector4I(0, 1, 2, 3), Vector4F(0, 1, 2, 3)) == m,
                   "matrix4x3 vector constructor");

        ASSERT_MSG(Matrix4x3F(Vector3F(0, 1, 2), Vector3F(0, 1, 2), Vector3D(0, 1, 2), Vector3I(0, 1, 2)) == m,
                   "matrix4x3 vector "
                   "constructor");

        ASSERT_MSG(Matrix4x3F(Vector2F(0, 1), 2, Vector2F(0, 1), 2, Vector2D(0, 1), 2, Vector2I(0, 1), 2) == m,
                   "matrix4x3 vector "
                   "constructor");

        ASSERT_MSG(Matrix4x3F(0, Vector2F(1, 2), 0, Vector2F(1, 2), 0, Vector2D(1, 2), 0, Vector2I(1, 2)) == m,
                   "matrix4x3 vector "
                   "constructor");
    }

    // Matrix4x2F from vectors constructor
    {
        constexpr Matrix4x2F m(0, 1, 0, 1, 0, 1, 0, 1);

        ASSERT_MSG(Matrix4x2F(Vector4D(0, 1, 2, 3), Vector4F(0, 1, 2, 3), Vector4F(0, 1, 2, 3), Vector4I(0, 1, 2, 3)) == m,
                   "matrix4x2 vector constructor");

        ASSERT_MSG(Matrix4x2F(Vector3F(0, 1, 2), Vector3I(0, 1, 2), Vector3D(0, 1, 2), Vector3F(0, 1, 2)) == m,
                   "matrix4x2 vector "
                   "constructor");
    }

    // Matrix3x4F from vectors constructor
    {
        constexpr Matrix3x4F m(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        ASSERT_MSG(Matrix3x4F(Vector4D(0, 1, 2, 3), Vector4F(0, 1, 2, 3), Vector4I(0, 1, 2, 3)) == m,
                   "matrix3x4 vector "
                   "constructor");

        ASSERT_MSG(Matrix3x4F(Vector3I(0, 1, 2), 3, Vector3F(0, 1, 2), 3, Vector3D(0, 1, 2), 3) == m,
                   "matrix3x4 vector "
                   "constructor");

        ASSERT_MSG(Matrix3x4F(0.0, Vector3F(1, 2, 3), 0, Vector3F(1, 2, 3), 0, Vector3I(1, 2, 3)) == m,
                   "matrix3x4 vector "
                   "constructor");

        ASSERT_MSG(
        Matrix3x4F(Vector2I(0, 1), Vector2I(2, 3), Vector2F(0, 1), Vector2D(2, 3), Vector2D(0, 1), Vector2F(2, 3)) == m,
        "matrix3x4 vector constructor");

        ASSERT_MSG(Matrix3x4F(Vector2I(0, 1), 2, 3, Vector2F(0, 1), 2, 3, Vector2D(0, 1), 2, 3) == m,
                   "matrix3x4 vector "
                   "constructor");

        ASSERT_MSG(Matrix3x4F(0, Vector2I(1, 2), 3, 0, Vector2D(1, 2), 3, 0, Vector2F(1, 2), 3) == m,
                   "matrix3x4 vector "
                   "constructor");

        ASSERT_MSG(Matrix3x4F(0, 1.0, Vector2F(2, 3), 0, 1.0, Vector2F(2, 3), 0, 1.0, Vector2F(2, 3)) == m,
                   "matrix3x4 vector "
                   "constructor");
    }

    // Matrix3F from vectors constructor
    {
        constexpr Matrix3F m(0, 1, 2, 0, 1, 2, 0, 1, 2);

        ASSERT_MSG(Matrix3F(Vector4I(0, 1, 2, 3), Vector4D(0, 1, 2, 3), Vector4F(0, 1, 2, 3)) == m,
                   "matrix3 vector constructor");

        ASSERT_MSG(Matrix3F(Vector3F(0, 1, 2), Vector3I(0, 1, 2), Vector3D(0, 1, 2)) == m,
                   "matrix3 vector constructor");

        ASSERT_MSG(Matrix3F(Vector2I(0, 1), 2, Vector2D(0, 1), 2, Vector2F(0, 1), 2) == m,
                   "matrix3 vector constructor");

        ASSERT_MSG(Matrix3F(0, Vector2D(1, 2), 0, Vector2I(1, 2), 0, Vector2F(1, 2)) == m,
                   "matrix3 vector constructor");
    }

    // Matrix3x2F from vectors constructor
    {
        constexpr Matrix3x2F m(0, 1, 0, 1, 0, 1);

        ASSERT_MSG(Matrix3x2F(Vector4F(0, 1, 2, 3), Vector4I(0, 1, 2, 3), Vector4D(0, 1, 2, 3)) == m,
                   "matrix3x2 vector "
                   "constructor");

        ASSERT_MSG(Matrix3x2F(Vector3I(0, 1, 2), Vector3D(0, 1, 2), Vector3F(0, 1, 2)) == m,
                   "matrix3x2 vector constructor");
    }

    // Matrix2x4F from vectors constructor
    {
        constexpr Matrix2x4F m(0, 1, 2, 3, 0, 1, 2, 3);

        ASSERT_MSG(Matrix2x4F(Vector4F(0, 1, 2, 3), Vector4F(0, 1, 2, 3)) == m, "matrix2x4 vector constructor");

        ASSERT_MSG(Matrix2x4F(Vector3F(0, 1, 2), 3, Vector3D(0, 1, 2), 3) == m, "matrix2x4 vector constructor");

        ASSERT_MSG(Matrix2x4F(0, Vector3F(1, 2, 3), 0, Vector3D(1, 2, 3)) == m, "matrix2x4 vector constructor");

        ASSERT_MSG(Matrix2x4F(Vector2F(0, 1), Vector2F(2, 3), Vector2I(0, 1), Vector2F(2, 3)) == m,
                   "matrix2x4 vector constructor");

        ASSERT_MSG(Matrix2x4F(Vector2F(0, 1), 2, 3, Vector2D(0, 1), 2, 3) == m, "matrix2x4 vector constructor");

        ASSERT_MSG(Matrix2x4F(0, Vector2F(1, 2), 3, 0, Vector2I(1, 2), 3) == m, "matrix2x4 vector constructor");

        ASSERT_MSG(Matrix2x4F(0, 1, Vector2F(2, 3), 0, 1, Vector2D(2, 3)) == m, "matrix2x4 vector constructor");
    }

    // Matrix2x3F from vectors constructor
    {
        constexpr Matrix2x3F m(0, 1, 2, 0, 1, 2);

        ASSERT_MSG(Matrix2x3F(Vector4D(0, 1, 2, 3), Vector4F(0, 1, 2, 3)) == m, "matrix2x3 vector constructor");

        ASSERT_MSG(Matrix2x3F(Vector3I(0, 1, 2), Vector3F(0, 1, 2)) == m, "matrix2x3 vector constructor");

        ASSERT_MSG(Matrix2x3F(Vector2D(0, 1), 2, Vector2F(0, 1), 2) == m, "matrix2x3 vector constructor");

        ASSERT_MSG(Matrix2x3F(0, Vector2F(1, 2), 0, Vector2I(1, 2)) == m, "matrix2x3 vector constructor");
    }

    // Matrix2F from vectors constructor
    {
        constexpr Matrix2F m(0, 1, 0, 1);

        ASSERT_MSG(Matrix2F(Vector4F(0, 1, 2, 3), Vector4I(0, 1, 2, 3)) == m, "matrix2 vector constructor");

        ASSERT_MSG(Matrix2F(Vector3D(0, 1, 2), Vector3F(0, 1, 2)) == m, "matrix2 vector constructor");
    }

    // matrix from matrix constructor
    {
        constexpr Matrix4F m44f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        constexpr Matrix4x3F m43f(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2);

        constexpr Matrix4x2F m42f(0, 1, 0, 1, 0, 1, 0, 1);

        constexpr Matrix3x4F m34f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3);

        constexpr Matrix3F m33f(0, 1, 2, 0, 1, 2, 0, 1, 2);

        constexpr Matrix3x2F m32f(0, 1, 0, 1, 0, 1);

        constexpr Matrix2x4F m24f(0, 1, 2, 3, 0, 1, 2, 3);

        constexpr Matrix2x3F m23f(0, 1, 2, 0, 1, 2);

        constexpr Matrix2F m22f(0, 1, 0, 1);

        // mat 4x4
        ASSERT_MSG(Matrix4D(m44f) == Matrix4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                   "matrix4d Matrix4F constructor");

        ASSERT_MSG(Matrix4D(m43f) == Matrix4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 1),
                   "matrix4d Matrix4x3F "
                   "constructor");

        ASSERT_MSG(Matrix4D(m42f) == Matrix4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1),
                   "matrix4d Matrix4x2F "
                   "constructor");

        ASSERT_MSG(Matrix4D(m34f) == Matrix4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 0, 1),
                   "matrix4d Matrix3x4F "
                   "constructor");

        ASSERT_MSG(Matrix4D(m33f) == Matrix4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 0, 1),
                   "matrix4d Matrix3F constructor");

        ASSERT_MSG(Matrix4D(m32f) == Matrix4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1),
                   "matrix4d Matrix3x2F "
                   "constructor");

        ASSERT_MSG(Matrix4D(m24f) == Matrix4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0, 0, 0, 0, 1),
                   "matrix4d Matrix2x4F "
                   "constructor");

        ASSERT_MSG(Matrix4D(m23f) == Matrix4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                   "matrix4d Matrix2x3F "
                   "constructor");

        ASSERT_MSG(Matrix4D(m22f) == Matrix4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                   "matrix4d Matrix2F constructor");

        // mat 4x3
        ASSERT_MSG(Matrix4x3D(m44f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                   "matrix4x3d Matrix4F constructor");

        ASSERT_MSG(Matrix4x3D(m43f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                   "matrix4x3d Matrix4x3F constructor");

        ASSERT_MSG(Matrix4x3D(m42f) == Matrix4x3D(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0),
                   "matrix4x3d Matrix4x2F constructor");

        ASSERT_MSG(Matrix4x3D(m34f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                   "matrix4x3d Matrix3x4F constructor");

        ASSERT_MSG(Matrix4x3D(m33f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                   "matrix4x3d Matrix3F constructor");

        ASSERT_MSG(Matrix4x3D(m32f) == Matrix4x3D(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0),
                   "matrix4x3d Matrix3x2F constructor");

        ASSERT_MSG(Matrix4x3D(m24f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                   "matrix4x3d Matrix2x4F constructor");

        ASSERT_MSG(Matrix4x3D(m23f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                   "matrix4x3d Matrix2x3F constructor");

        ASSERT_MSG(Matrix4x3D(m22f) == Matrix4x3D(0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
                   "matrix4x3d Matrix2F constructor");

        // mat 4x2
        ASSERT_MSG(Matrix4x2D(m44f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d Matrix4F constructor");

        ASSERT_MSG(Matrix4x2D(m43f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d Matrix4x3F constructor");

        ASSERT_MSG(Matrix4x2D(m42f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d Matrix4x2F constructor");

        ASSERT_MSG(Matrix4x2D(m34f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d Matrix3x4F constructor");

        ASSERT_MSG(Matrix4x2D(m33f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d Matrix3F constructor");

        ASSERT_MSG(Matrix4x2D(m32f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d Matrix3x2F constructor");

        ASSERT_MSG(Matrix4x2D(m24f) == Matrix4x2D(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d Matrix2x4F constructor");

        ASSERT_MSG(Matrix4x2D(m23f) == Matrix4x2D(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d Matrix2x3F constructor");

        ASSERT_MSG(Matrix4x2D(m22f) == Matrix4x2D(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d Matrix2F constructor");

        // mat 3x4
        ASSERT_MSG(Matrix3x4D(m44f) == Matrix3x4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                   "matrix3x4d Matrix4F constructor");

        ASSERT_MSG(Matrix3x4D(m43f) == Matrix3x4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                   "matrix3x4d Matrix4x3F constructor");

        ASSERT_MSG(Matrix3x4D(m42f) == Matrix3x4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                   "matrix3x4d Matrix4x2F constructor");

        ASSERT_MSG(Matrix3x4D(m34f) == Matrix3x4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                   "matrix3x4d Matrix3x4F constructor");

        ASSERT_MSG(Matrix3x4D(m33f) == Matrix3x4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                   "matrix3x4d Matrix3F constructor");

        ASSERT_MSG(Matrix3x4D(m32f) == Matrix3x4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                   "matrix3x4d Matrix3x2F constructor");

        ASSERT_MSG(Matrix3x4D(m24f) == Matrix3x4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0),
                   "matrix3x4d Matrix2x4F constructor");

        ASSERT_MSG(Matrix3x4D(m23f) == Matrix3x4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0),
                   "matrix3x4d Matrix2x3F constructor");

        ASSERT_MSG(Matrix3x4D(m22f) == Matrix3x4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0),
                   "matrix3x4d Matrix2F constructor");

        // mat 3
        ASSERT_MSG(Matrix3D(m44f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix4F constructor");

        ASSERT_MSG(Matrix3D(m43f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix4x3F constructor");

        ASSERT_MSG(Matrix3D(m42f) == Matrix3D(0, 1, 0, 0, 1, 0, 0, 1, 1), "matrix3d Matrix4x2F constructor");

        ASSERT_MSG(Matrix3D(m34f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix3x4F constructor");

        ASSERT_MSG(Matrix3D(m33f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix3F constructor");

        ASSERT_MSG(Matrix3D(m32f) == Matrix3D(0, 1, 0, 0, 1, 0, 0, 1, 1), "matrix3d Matrix3x2F constructor");

        ASSERT_MSG(Matrix3D(m24f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 0, 1), "matrix3d Matrix2x4F constructor");

        ASSERT_MSG(Matrix3D(m23f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 0, 1), "matrix3d Matrix2x3F constructor");

        ASSERT_MSG(Matrix3D(m22f) == Matrix3D(0, 1, 0, 0, 1, 0, 0, 0, 1), "matrix3d Matrix2F constructor");

        // mat 3x2
        ASSERT_MSG(Matrix3x2D(m44f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix4F constructor");

        ASSERT_MSG(Matrix3x2D(m43f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix4x3F constructor");

        ASSERT_MSG(Matrix3x2D(m42f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix4x2F constructor");

        ASSERT_MSG(Matrix3x2D(m34f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix3x4F constructor");

        ASSERT_MSG(Matrix3x2D(m33f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix3F constructor");

        ASSERT_MSG(Matrix3x2D(m32f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix3x2F constructor");

        ASSERT_MSG(Matrix3x2D(m24f) == Matrix3x2D(0, 1, 0, 1, 0, 0), "matrix3x2d Matrix2x4F constructor");

        ASSERT_MSG(Matrix3x2D(m23f) == Matrix3x2D(0, 1, 0, 1, 0, 0), "matrix3x2d Matrix2x3F constructor");

        ASSERT_MSG(Matrix3x2D(m22f) == Matrix3x2D(0, 1, 0, 1, 0, 0), "matrix3x2d Matrix2F constructor");

        // mat 2x4
        ASSERT_MSG(Matrix2x4D(m44f) == Matrix2x4D(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d Matrix4F constructor");

        ASSERT_MSG(Matrix2x4D(m43f) == Matrix2x4D(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d Matrix4x3F constructor");

        ASSERT_MSG(Matrix2x4D(m42f) == Matrix2x4D(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d Matrix4x2F constructor");

        ASSERT_MSG(Matrix2x4D(m34f) == Matrix2x4D(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d Matrix3x4F constructor");

        ASSERT_MSG(Matrix2x4D(m33f) == Matrix2x4D(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d Matrix3F constructor");

        ASSERT_MSG(Matrix2x4D(m32f) == Matrix2x4D(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d Matrix3x2F constructor");

        ASSERT_MSG(Matrix2x4D(m24f) == Matrix2x4D(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d Matrix2x4F constructor");

        ASSERT_MSG(Matrix2x4D(m23f) == Matrix2x4D(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d Matrix2x3F constructor");

        ASSERT_MSG(Matrix2x4D(m22f) == Matrix2x4D(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d Matrix2F constructor");

        // mat 2x3
        ASSERT_MSG(Matrix2x3D(m44f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix4F constructor");

        ASSERT_MSG(Matrix2x3D(m43f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix4x3F constructor");

        ASSERT_MSG(Matrix2x3D(m42f) == Matrix2x3D(0, 1, 0, 0, 1, 0), "matrix2x3d Matrix4x2F constructor");

        ASSERT_MSG(Matrix2x3D(m34f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix3x4F constructor");

        ASSERT_MSG(Matrix2x3D(m33f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix3F constructor");

        ASSERT_MSG(Matrix2x3D(m32f) == Matrix2x3D(0, 1, 0, 0, 1, 0), "matrix2x3d Matrix3x2F constructor");

        ASSERT_MSG(Matrix2x3D(m24f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix2x4F constructor");

        ASSERT_MSG(Matrix2x3D(m23f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix2x3F constructor");

        ASSERT_MSG(Matrix2x3D(m22f) == Matrix2x3D(0, 1, 0, 0, 1, 0), "matrix2x3d Matrix2F constructor");

        // mat 2
        ASSERT_MSG(Matrix2D(m44f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix4F constructor");

        ASSERT_MSG(Matrix2D(m43f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix4x3F constructor");

        ASSERT_MSG(Matrix2D(m42f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix4x2F constructor");

        ASSERT_MSG(Matrix2D(m34f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix3x4F constructor");

        ASSERT_MSG(Matrix2D(m33f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix3F constructor");

        ASSERT_MSG(Matrix2D(m32f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix3x2F constructor");

        ASSERT_MSG(Matrix2D(m24f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix2x4F constructor");

        ASSERT_MSG(Matrix2D(m23f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix2x3F constructor");

        ASSERT_MSG(Matrix2D(m22f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix2F constructor");
    }

    return 0;
}
