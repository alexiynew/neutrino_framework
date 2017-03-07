#include <math/math.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;

class matrix_test : public framework::unit_test::suite
{
public:
    matrix_test()
        : suite("matrix_test")
    {
        add_test([this]() { size_check(); }, "size_check");
        add_test([this]() { default_constructor(); }, "default_constructor");
        add_test([this]() { one_argument_constructor(); }, "one_argument_constructor");
        add_test([this]() { pointer_constructor(); }, "pointer_constructor");
        add_test([this]() { matrix4x4_constructors(); }, "matrix4x4_constructors");
        add_test([this]() { matrix4x3_constructors(); }, "matrix4x3_constructors");
        add_test([this]() { matrix4x2_constructors(); }, "matrix4x2_constructors");
        add_test([this]() { matrix3x4_constructors(); }, "matrix3x4_constructors");
        add_test([this]() { matrix3x3_constructors(); }, "matrix3x3_constructors");
        add_test([this]() { matrix3x2_constructors(); }, "matrix3x2_constructors");
        add_test([this]() { matrix2x4_constructors(); }, "matrix2x4_constructors");
        add_test([this]() { matrix2x3_constructors(); }, "matrix2x3_constructors");
        add_test([this]() { matrix2x2_constructors(); }, "matrix2x2_constructors");

        matrix22 = Matrix2x2F();
        matrix23 = Matrix2x3F();
        matrix24 = Matrix2x4F();

        matrix32 = Matrix3x2F();
        matrix33 = Matrix3x3F();
        matrix34 = Matrix3x4F();

        matrix42 = Matrix4x2F();
        matrix43 = Matrix4x3F();
        matrix44 = Matrix4x4F();
    }

private:
    void size_check()
    {
        TEST_ASSERT(sizeof(matrix22) == sizeof(float) * 2 * 2 && matrix22.size() == 2, "Matrix2x2 size check failed.");
        TEST_ASSERT(sizeof(matrix23) == sizeof(float) * 2 * 3 && matrix23.size() == 2, "Matrix2x3 size check failed.");
        TEST_ASSERT(sizeof(matrix24) == sizeof(float) * 2 * 4 && matrix24.size() == 2, "Matrix2x4 size check failed.");

        TEST_ASSERT(sizeof(matrix32) == sizeof(float) * 3 * 2 && matrix32.size() == 3, "Matrix3x2 size check failed.");
        TEST_ASSERT(sizeof(matrix33) == sizeof(float) * 3 * 3 && matrix33.size() == 3, "Matrix3x3 size check failed.");
        TEST_ASSERT(sizeof(matrix34) == sizeof(float) * 3 * 4 && matrix34.size() == 3, "Matrix3x4 size check failed.");

        TEST_ASSERT(sizeof(matrix42) == sizeof(float) * 4 * 2 && matrix42.size() == 4, "Matrix4x2 size check failed.");
        TEST_ASSERT(sizeof(matrix43) == sizeof(float) * 4 * 3 && matrix43.size() == 4, "Matrix4x3 size check failed.");
        TEST_ASSERT(sizeof(matrix44) == sizeof(float) * 4 * 4 && matrix44.size() == 4, "Matrix4x4 size check failed.");
    }

    void default_constructor()
    {
        // clang-format off
        TEST_ASSERT(matrix22 == Matrix2x2F(
            1, 0,
            0, 1
        ), "Matrix2x2 default constructor failed.");

        TEST_ASSERT(matrix23 == Matrix2x3F(
            1, 0, 0,
            0, 1, 0
        ), "Matrix2x3 default constructor failed.");

        TEST_ASSERT(matrix24 == Matrix2x4F(
            1, 0, 0, 0,
            0, 1, 0, 0
        ), "Matrix2x4 default constructor failed.");

        TEST_ASSERT(matrix32 == Matrix3x2F(
            1, 0,
            0, 1,
            0, 0
        ), "Matrix3x2 default constructor failed.");

        TEST_ASSERT(matrix33 == Matrix3x3F(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        ), "Matrix3x3 default constructor failed.");

        TEST_ASSERT(matrix34 == Matrix3x4F(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0
        ), "Matrix3x4 default constructor failed.");

        TEST_ASSERT(matrix42 == Matrix4x2F(
            1, 0,
            0, 1,
            0, 0,
            0, 0
        ), "Matrix4x2 default constructor failed.");

        TEST_ASSERT(matrix43 == Matrix4x3F(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1,
            0, 0, 0
        ), "Matrix4x3 default constructor failed.");

        TEST_ASSERT(matrix44 == Matrix4x4F(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        ), "Matrix4x4 default constructor failed.");
        // clang-format on
    }

    void one_argument_constructor()
    {
        TEST_ASSERT(matrix22 == Matrix2x2F(1), "Matrix2x2 one argument constructor failed.");
        TEST_ASSERT(matrix23 == Matrix2x3F(1), "Matrix2x3 one argument constructor failed.");
        TEST_ASSERT(matrix24 == Matrix2x4F(1), "Matrix2x4 one argument constructor failed.");

        TEST_ASSERT(matrix32 == Matrix3x2F(1), "Matrix3x2 one argument constructor failed.");
        TEST_ASSERT(matrix33 == Matrix3x3F(1), "Matrix3x3 one argument constructor failed.");
        TEST_ASSERT(matrix34 == Matrix3x4F(1), "Matrix3x4 one argument constructor failed.");

        TEST_ASSERT(matrix42 == Matrix4x2F(1), "Matrix4x2 one argument constructor failed.");
        TEST_ASSERT(matrix43 == Matrix4x3F(1), "Matrix4x3 one argument constructor failed.");
        TEST_ASSERT(matrix44 == Matrix4x4F(1), "Matrix4x4 one argument constructor failed.");
    }

    void pointer_constructor()
    {
        const float data4[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
        const float data3[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        const float data2[] = {0, 1, 0, 1, 0, 1, 0, 1};

        const Matrix4x4F m44(data4);
        const Matrix3x4F m34(data4);
        const Matrix2x4F m24(data4);

        const Matrix4x3F m43(data3);
        const Matrix3x3F m33(data3);
        const Matrix2x3F m23(data3);

        const Matrix4x2F m42(data2);
        const Matrix3x2F m32(data2);
        const Matrix2x2F m22(data2);

        const Vector4F tmp4f = {0, 1, 2, 3};
        const Vector3F tmp3f = {0, 1, 2};
        const Vector2F tmp2f = {0, 1};

        TEST_ASSERT(m44 == Matrix4x4F(tmp4f, tmp4f, tmp4f, tmp4f), "Matrix4x4 from pointer constructor failed.");
        TEST_ASSERT(m34 == Matrix3x4F(tmp4f, tmp4f, tmp4f), "Matrix3x4 from pointer constructor failed.");
        TEST_ASSERT(m24 == Matrix2x4F(tmp4f, tmp4f), "Matrix2x4 from pointer constructor failed.");

        TEST_ASSERT(m43 == Matrix4x3F(tmp3f, tmp3f, tmp3f, tmp3f), "Matrix4x3 from pointer constructor failed.");
        TEST_ASSERT(m33 == Matrix3x3F(tmp3f, tmp3f, tmp3f), "Matrix3x3 from pointer constructor failed.");
        TEST_ASSERT(m23 == Matrix2x3F(tmp3f, tmp3f), "Matrix2x3 from pointer constructor failed.");

        TEST_ASSERT(m42 == Matrix4x2F(tmp2f, tmp2f, tmp2f, tmp2f), "Matrix4x3 from pointer constructor.");
        TEST_ASSERT(m32 == Matrix3x2F(tmp2f, tmp2f, tmp2f), "Matrix3x3 from pointer constructor.");
        TEST_ASSERT(m22 == Matrix2x2F(tmp2f, tmp2f), "Matrix2x3 from pointer constructor.");
    }

    void matrix4x4_constructors()
    {
        // clang-format off
        const Matrix4x4F m1 = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const Matrix4x4F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4),
            Vector4I(1, 2, 3, 4),
            Vector4F(1, 2, 3, 4)
        };

        const Matrix4x4F m3 = {
            Vector3F(1, 2, 3), 4,
            Vector3D(1, 2, 3), 4,
            Vector3I(1, 2, 3), 4,
            Vector3F(1, 2, 3), 4
        };

        const Matrix4x4F m4 = {
            1, Vector3F(2, 3, 4),
            1, Vector3D(2, 3, 4),
            1, Vector3I(2, 3, 4),
            1, Vector3F(2, 3, 4)
        };

        const Matrix4x4F m5 = {
            Vector2F(1, 2), Vector2F(3, 4),
            Vector2D(1, 2), Vector2D(3, 4),
            Vector2I(1, 2), Vector2I(3, 4),
            Vector2F(1, 2), Vector2F(3, 4)
        };

        const Matrix4x4F m6 = {
            Vector2F(1, 2), 3, 4,
            Vector2D(1, 2), 3, 4,
            Vector2I(1, 2), 3, 4,
            Vector2F(1, 2), 3, 4
        };

        const Matrix4x4F m7 = {
            1, Vector2F(2, 3), 4,
            1, Vector2D(2, 3), 4,
            1, Vector2I(2, 3), 4,
            1, Vector2F(2, 3), 4
        };

        const Matrix4x4F m8 = {
            1, 2, Vector2F(3, 4),
            1, 2, Vector2D(3, 4),
            1, 2, Vector2I(3, 4),
            1, 2, Vector2F(3, 4)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix4x4F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix4x4F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix4x4F constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix4x4F constructor failed.");
        TEST_ASSERT(m1 == m6, "Matrix4x4F constructor failed.");
        TEST_ASSERT(m1 == m7, "Matrix4x4F constructor failed.");
        TEST_ASSERT(m1 == m8, "Matrix4x4F constructor failed.");
    }

    void matrix4x3_constructors()
    {
        // clang-format off
        const Matrix4x3F m1 = {
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f
        };

        const Matrix4x3F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4),
            Vector4I(1, 2, 3, 4),
            Vector4F(1, 2, 3, 4)
        };

        const Matrix4x3F m3 = {
            Vector3F(1, 2, 3),
            Vector3D(1, 2, 3),
            Vector3I(1, 2, 3),
            Vector3F(1, 2, 3)
        };

        const Matrix4x3F m4 = {
            Vector2F(1, 2), 3,
            Vector2D(1, 2), 3,
            Vector2I(1, 2), 3,
            Vector2F(1, 2), 3
        };

        const Matrix4x3F m5 = {
            1, Vector2F(2, 3),
            1, Vector2D(2, 3),
            1, Vector2I(2, 3),
            1, Vector2F(2, 3)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix4x3F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix4x3F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix4x3F constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix4x3F constructor failed.");
    }

    void matrix4x2_constructors()
    {
        // clang-format off
        const Matrix4x2F m1 = {
            1.0f, 2.0f,
            1.0f, 2.0f,
            1.0f, 2.0f,
            1.0f, 2.0f
        };

        const Matrix4x2F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4),
            Vector4I(1, 2, 3, 4),
            Vector4F(1, 2, 3, 4)
        };

        const Matrix4x2F m3 = {
            Vector3F(1, 2, 3),
            Vector3D(1, 2, 3),
            Vector3I(1, 2, 3),
            Vector3F(1, 2, 3)
        };

        const Matrix4x2F m4 = {
            Vector2F(1, 2),
            Vector2D(1, 2),
            Vector2I(1, 2),
            Vector2F(1, 2)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix4x2F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix4x2F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix4x2F constructor failed.");
    }

    void matrix3x4_constructors()
    {
        // clang-format off
        const Matrix3x4F m1 = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const Matrix3x4F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4),
            Vector4I(1, 2, 3, 4)
        };

        const Matrix3x4F m3 = {
            Vector3F(1, 2, 3), 4,
            Vector3D(1, 2, 3), 4,
            Vector3I(1, 2, 3), 4
        };

        const Matrix3x4F m4 = {
            1, Vector3F(2, 3, 4),
            1, Vector3D(2, 3, 4),
            1, Vector3I(2, 3, 4)
        };

        const Matrix3x4F m5 = {
            Vector2F(1, 2), Vector2F(3, 4),
            Vector2D(1, 2), Vector2D(3, 4),
            Vector2I(1, 2), Vector2I(3, 4)
        };

        const Matrix3x4F m6 = {
            Vector2F(1, 2), 3, 4,
            Vector2D(1, 2), 3, 4,
            Vector2I(1, 2), 3, 4
        };

        const Matrix3x4F m7 = {
            1, Vector2F(2, 3), 4,
            1, Vector2D(2, 3), 4,
            1, Vector2I(2, 3), 4
        };

        const Matrix3x4F m8 = {
            1, 2, Vector2F(3, 4),
            1, 2, Vector2D(3, 4),
            1, 2, Vector2I(3, 4)\
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix3x4F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix3x4F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix3x4F constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix3x4F constructor failed.");
        TEST_ASSERT(m1 == m6, "Matrix3x4F constructor failed.");
        TEST_ASSERT(m1 == m7, "Matrix3x4F constructor failed.");
        TEST_ASSERT(m1 == m8, "Matrix3x4F constructor failed.");
    }

    void matrix3x3_constructors()
    {
        // clang-format off
        const Matrix3x3F m1 = {
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f
        };

        const Matrix3x3F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4),
            Vector4I(1, 2, 3, 4)
        };

        const Matrix3x3F m3 = {
            Vector3F(1, 2, 3),
            Vector3D(1, 2, 3),
            Vector3I(1, 2, 3)
        };

        const Matrix3x3F m4 = {
            Vector2F(1, 2), 3,
            Vector2D(1, 2), 3,
            Vector2I(1, 2), 3
        };

        const Matrix3x3F m5 = {
            1, Vector2F(2, 3),
            1, Vector2D(2, 3),
            1, Vector2I(2, 3)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix3x3F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix3x3F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix3x3F constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix3x3F constructor failed.");
    }

    void matrix3x2_constructors()
    {
        // clang-format off
        const Matrix3x2F m1 = {
            1.0f, 2.0f,
            1.0f, 2.0f,
            1.0f, 2.0f
        };

        const Matrix3x2F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4),
            Vector4I(1, 2, 3, 4)
        };

        const Matrix3x2F m3 = {
            Vector3F(1, 2, 3),
            Vector3D(1, 2, 3),
            Vector3I(1, 2, 3)
        };

        const Matrix3x2F m4 = {
            Vector2F(1, 2),
            Vector2D(1, 2),
            Vector2I(1, 2)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix3x2F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix3x2F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix3x2F constructor failed.");
    }

    void matrix2x4_constructors()
    {
        // clang-format off
        const Matrix2x4F m1 = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const Matrix2x4F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4)
        };

        const Matrix2x4F m3 = {
            Vector3F(1, 2, 3), 4,
            Vector3D(1, 2, 3), 4
        };

        const Matrix2x4F m4 = {
            1, Vector3F(2, 3, 4),
            1, Vector3D(2, 3, 4)
        };

        const Matrix2x4F m5 = {
            Vector2F(1, 2), Vector2F(3, 4),
            Vector2D(1, 2), Vector2D(3, 4)
        };

        const Matrix2x4F m6 = {
            Vector2F(1, 2), 3, 4,
            Vector2D(1, 2), 3, 4
        };

        const Matrix2x4F m7 = {
            1, Vector2F(2, 3), 4,
            1, Vector2D(2, 3), 4
        };

        const Matrix2x4F m8 = {
            1, 2, Vector2F(3, 4),
            1, 2, Vector2D(3, 4)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix2x4F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix2x4F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix2x4F constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix2x4F constructor failed.");
        TEST_ASSERT(m1 == m6, "Matrix2x4F constructor failed.");
        TEST_ASSERT(m1 == m7, "Matrix2x4F constructor failed.");
        TEST_ASSERT(m1 == m8, "Matrix2x4F constructor failed.");
    }

    void matrix2x3_constructors()
    {
        // clang-format off
        const Matrix2x3F m1 = {
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f
        };

        const Matrix2x3F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4)
        };

        const Matrix2x3F m3 = {
            Vector3F(1, 2, 3),
            Vector3D(1, 2, 3)
        };

        const Matrix2x3F m4 = {
            Vector2F(1, 2), 3,
            Vector2D(1, 2), 3
        };

        const Matrix2x3F m5 = {
            1, Vector2F(2, 3),
            1, Vector2D(2, 3)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix2x3F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix2x3F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix2x3F constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix2x3F constructor failed.");
    }

    void matrix2x2_constructors()
    {
        // clang-format off
        const Matrix2x2F m1 = {
            1.0f, 2.0f,
            1.0f, 2.0f
        };

        const Matrix2x2F m2 = {
            Vector4F(1, 2, 3, 4),
            Vector4D(1, 2, 3, 4)
        };

        const Matrix2x2F m3 = {
            Vector3F(1, 2, 3),
            Vector3D(1, 2, 3)
        };

        const Matrix2x2F m4 = {
            Vector2F(1, 2),
            Vector2D(1, 2)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix2x2F constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix2x2F constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix2x2F constructor failed.");
    }

    Matrix2x2F matrix22;
    Matrix2x3F matrix23;
    Matrix2x4F matrix24;

    Matrix3x2F matrix32;
    Matrix3x3F matrix33;
    Matrix3x4F matrix34;

    Matrix4x2F matrix42;
    Matrix4x3F matrix43;
    Matrix4x4F matrix44;
};

class matrix_from_matrix_test : public framework::unit_test::suite
{
public:
    matrix_from_matrix_test()
        : suite("matrix_from_matrix_test")
    {

        add_test([this]() { matrix4x4_constructors(); }, "matrix4x4_constructors");
        add_test([this]() { matrix4x3_constructors(); }, "matrix4x3_constructors");
        add_test([this]() { matrix4x2_constructors(); }, "matrix4x2_constructors");
        add_test([this]() { matrix3x4_constructors(); }, "matrix3x4_constructors");
        add_test([this]() { matrix3x3_constructors(); }, "matrix3x3_constructors");
        add_test([this]() { matrix3x2_constructors(); }, "matrix3x2_constructors");
        add_test([this]() { matrix2x4_constructors(); }, "matrix2x4_constructors");
        add_test([this]() { matrix2x3_constructors(); }, "matrix2x3_constructors");
        add_test([this]() { matrix2x2_constructors(); }, "matrix2x2_constructors");

        // clang-format off
        matrix44 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        matrix43 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        matrix42 = {
            0, 1,
            0, 1,
            0, 1,
            0, 1
        };

        matrix34 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        matrix33 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        matrix32 = {
            0, 1,
            0, 1,
            0, 1
        };

        matrix24 = {
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        matrix23 = {
            0, 1, 2,
            0, 1, 2
        };

        matrix22 = {
            0, 1,
            0, 1
        };
        // clang-format on
    }

private:
    void matrix4x4_constructors()
    {
        TEST_ASSERT(Matrix4F(matrix44) == Matrix4F(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix4x4 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix4F(matrix43) == Matrix4F(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 1),
                    "Matrix4x4 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix4F(matrix42) == Matrix4F(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1),
                    "Matrix4x4 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix4F(matrix34) == Matrix4F(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix4F(matrix33) == Matrix4F(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix4F(matrix32) == Matrix4F(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix4F(matrix24) == Matrix4F(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix4F(matrix23) == Matrix4F(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix4F(matrix22) == Matrix4F(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix2x2 constructor failed.");
    }

    void matrix4x3_constructors()
    {
        TEST_ASSERT(Matrix4x3F(matrix44) == Matrix4x3F(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix4x3 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix4x3F(matrix43) == Matrix4x3F(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix4x3 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix4x3F(matrix42) == Matrix4x3F(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0),
                    "Matrix4x3 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix4x3F(matrix34) == Matrix4x3F(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                    "Matrix4x3 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix4x3F(matrix33) == Matrix4x3F(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                    "Matrix4x3 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix4x3F(matrix32) == Matrix4x3F(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix4x3F(matrix24) == Matrix4x3F(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix4x3F(matrix23) == Matrix4x3F(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix4x3F(matrix22) == Matrix4x3F(0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix2x2 constructor failed.");
    }

    void matrix4x2_constructors()
    {
        TEST_ASSERT(Matrix4x2F(matrix44) == Matrix4x2F(0, 1, 0, 1, 0, 1, 0, 1),
                    "Matrix4x2 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix4x2F(matrix43) == Matrix4x2F(0, 1, 0, 1, 0, 1, 0, 1),
                    "Matrix4x2 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix4x2F(matrix42) == Matrix4x2F(0, 1, 0, 1, 0, 1, 0, 1),
                    "Matrix4x2 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix4x2F(matrix34) == Matrix4x2F(0, 1, 0, 1, 0, 1, 0, 0),
                    "Matrix4x2 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix4x2F(matrix33) == Matrix4x2F(0, 1, 0, 1, 0, 1, 0, 0),
                    "Matrix4x2 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix4x2F(matrix32) == Matrix4x2F(0, 1, 0, 1, 0, 1, 0, 0),
                    "Matrix4x2 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix4x2F(matrix24) == Matrix4x2F(0, 1, 0, 1, 0, 0, 0, 0),
                    "Matrix4x2 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix4x2F(matrix23) == Matrix4x2F(0, 1, 0, 1, 0, 0, 0, 0),
                    "Matrix4x2 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix4x2F(matrix22) == Matrix4x2F(0, 1, 0, 1, 0, 0, 0, 0),
                    "Matrix4x2 from Matrix2x2 constructor failed.");
    }

    void matrix3x4_constructors()
    {
        TEST_ASSERT(Matrix3x4F(matrix44) == Matrix3x4F(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix3x4 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix3x4F(matrix43) == Matrix3x4F(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix3x4 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix3x4F(matrix42) == Matrix3x4F(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                    "Matrix3x4 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix3x4F(matrix34) == Matrix3x4F(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix3x4 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix3x4F(matrix33) == Matrix3x4F(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix3x4 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix3x4F(matrix32) == Matrix3x4F(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                    "Matrix3x4 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix3x4F(matrix24) == Matrix3x4F(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0),
                    "Matrix3x4 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix3x4F(matrix23) == Matrix3x4F(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0),
                    "Matrix3x4 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix3x4F(matrix22) == Matrix3x4F(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0),
                    "Matrix3x4 from Matrix2x2 constructor failed.");
    }

    void matrix3x3_constructors()
    {
        TEST_ASSERT(Matrix3F(matrix44) == Matrix3F(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix3F(matrix43) == Matrix3F(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix3F(matrix42) == Matrix3F(0, 1, 0, 0, 1, 0, 0, 1, 1),
                    "Matrix3x3 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix3F(matrix34) == Matrix3F(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix3F(matrix33) == Matrix3F(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix3F(matrix32) == Matrix3F(0, 1, 0, 0, 1, 0, 0, 1, 1),
                    "Matrix3x3 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix3F(matrix24) == Matrix3F(0, 1, 2, 0, 1, 2, 0, 0, 1),
                    "Matrix3x3 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix3F(matrix23) == Matrix3F(0, 1, 2, 0, 1, 2, 0, 0, 1),
                    "Matrix3x3 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix3F(matrix22) == Matrix3F(0, 1, 0, 0, 1, 0, 0, 0, 1),
                    "Matrix3x3 from Matrix2x2 constructor failed.");
    }

    void matrix3x2_constructors()
    {
        TEST_ASSERT(Matrix3x2F(matrix44) == Matrix3x2F(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix3x2F(matrix43) == Matrix3x2F(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix3x2F(matrix42) == Matrix3x2F(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix3x2F(matrix34) == Matrix3x2F(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix3x2F(matrix33) == Matrix3x2F(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix3x2F(matrix32) == Matrix3x2F(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix3x2F(matrix24) == Matrix3x2F(0, 1, 0, 1, 0, 0),
                    "Matrix3x2 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix3x2F(matrix23) == Matrix3x2F(0, 1, 0, 1, 0, 0),
                    "Matrix3x2 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix3x2F(matrix22) == Matrix3x2F(0, 1, 0, 1, 0, 0),
                    "Matrix3x2 from Matrix2x2 constructor failed.");
    }

    void matrix2x4_constructors()
    {
        TEST_ASSERT(Matrix2x4F(matrix44) == Matrix2x4F(0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix2x4 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix2x4F(matrix43) == Matrix2x4F(0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix2x4 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix2x4F(matrix42) == Matrix2x4F(0, 1, 0, 0, 0, 1, 0, 0),
                    "Matrix2x4 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix2x4F(matrix34) == Matrix2x4F(0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix2x4 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix2x4F(matrix33) == Matrix2x4F(0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix2x4 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix2x4F(matrix32) == Matrix2x4F(0, 1, 0, 0, 0, 1, 0, 0),
                    "Matrix2x4 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix2x4F(matrix24) == Matrix2x4F(0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix2x4 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix2x4F(matrix23) == Matrix2x4F(0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix2x4 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix2x4F(matrix22) == Matrix2x4F(0, 1, 0, 0, 0, 1, 0, 0),
                    "Matrix2x4 form Matrix2x2 constructor failed.");
    }

    void matrix2x3_constructors()
    {
        TEST_ASSERT(Matrix2x3F(matrix44) == Matrix2x3F(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix2x3F(matrix43) == Matrix2x3F(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix2x3F(matrix42) == Matrix2x3F(0, 1, 0, 0, 1, 0),
                    "Matrix2x3 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix2x3F(matrix34) == Matrix2x3F(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix2x3F(matrix33) == Matrix2x3F(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix2x3F(matrix32) == Matrix2x3F(0, 1, 0, 0, 1, 0),
                    "Matrix2x3 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix2x3F(matrix24) == Matrix2x3F(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix2x3F(matrix23) == Matrix2x3F(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix2x3F(matrix22) == Matrix2x3F(0, 1, 0, 0, 1, 0),
                    "Matrix2x3 form Matrix2x2 constructor failed.");
    }

    void matrix2x2_constructors()
    {
        TEST_ASSERT(Matrix2F(matrix44) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix2F(matrix43) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix2F(matrix42) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix2F(matrix34) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix2F(matrix33) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix2F(matrix32) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix2F(matrix24) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix2F(matrix23) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix2F(matrix22) == Matrix2F(0, 1, 0, 1), "Matrix2x2 form Matrix2x2 constructor failed.");
    }

    Matrix4x4F matrix44;
    Matrix4x3F matrix43;
    Matrix4x2F matrix42;

    Matrix3x4F matrix34;
    Matrix3x3F matrix33;
    Matrix3x2F matrix32;

    Matrix2x4F matrix24;
    Matrix2x3F matrix23;
    Matrix2x2F matrix22;
};

int main()
{
    return run_tests(matrix_test(), matrix_from_matrix_test());
}
