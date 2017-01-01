#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class matrix_test : public test::suite
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
        add_test([this]() { matrix4x4_matrix_constructors(); }, "matrix4x4_matrix_constructors");

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

        TEST_ASSERT(m42 == Matrix4x2F(tmp2f, tmp2f, tmp2f, tmp2f), "matrix4x3 from pointer constructor");
        TEST_ASSERT(m32 == Matrix3x2F(tmp2f, tmp2f, tmp2f), "matrix3x3 from pointer constructor");
        TEST_ASSERT(m22 == Matrix2x2F(tmp2f, tmp2f), "matrix2x3 from pointer constructor");
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

    void matrix4x4_matrix_constructors()
    {
        // TODO implement
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


int main()
{
    return run_tests(matrix_test());
    /*

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
            TEST_ASSERT(Matrix4D(m44f) == Matrix4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                        "matrix4d Matrix4F constructor");

            TEST_ASSERT(Matrix4D(m43f) == Matrix4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 1),
                        "matrix4d Matrix4x3F "
                        "constructor");

            TEST_ASSERT(Matrix4D(m42f) == Matrix4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1),
                        "matrix4d Matrix4x2F "
                        "constructor");

            TEST_ASSERT(Matrix4D(m34f) == Matrix4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 0, 1),
                        "matrix4d Matrix3x4F "
                        "constructor");

            TEST_ASSERT(Matrix4D(m33f) == Matrix4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 0, 1),
                        "matrix4d Matrix3F constructor");

            TEST_ASSERT(Matrix4D(m32f) == Matrix4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1),
                        "matrix4d Matrix3x2F "
                        "constructor");

            TEST_ASSERT(Matrix4D(m24f) == Matrix4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0, 0, 0, 0, 1),
                        "matrix4d Matrix2x4F "
                        "constructor");

            TEST_ASSERT(Matrix4D(m23f) == Matrix4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                        "matrix4d Matrix2x3F "
                        "constructor");

            TEST_ASSERT(Matrix4D(m22f) == Matrix4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                        "matrix4d Matrix2F constructor");

            // mat 4x3
            TEST_ASSERT(Matrix4x3D(m44f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                        "matrix4x3d Matrix4F constructor");

            TEST_ASSERT(Matrix4x3D(m43f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                        "matrix4x3d Matrix4x3F constructor");

            TEST_ASSERT(Matrix4x3D(m42f) == Matrix4x3D(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0),
                        "matrix4x3d Matrix4x2F constructor");

            TEST_ASSERT(Matrix4x3D(m34f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                        "matrix4x3d Matrix3x4F constructor");

            TEST_ASSERT(Matrix4x3D(m33f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                        "matrix4x3d Matrix3F constructor");

            TEST_ASSERT(Matrix4x3D(m32f) == Matrix4x3D(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0),
                        "matrix4x3d Matrix3x2F constructor");

            TEST_ASSERT(Matrix4x3D(m24f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                        "matrix4x3d Matrix2x4F constructor");

            TEST_ASSERT(Matrix4x3D(m23f) == Matrix4x3D(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                        "matrix4x3d Matrix2x3F constructor");

            TEST_ASSERT(Matrix4x3D(m22f) == Matrix4x3D(0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
                        "matrix4x3d Matrix2F constructor");

            // mat 4x2
            TEST_ASSERT(Matrix4x2D(m44f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d Matrix4F constructor");

            TEST_ASSERT(Matrix4x2D(m43f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d Matrix4x3F constructor");

            TEST_ASSERT(Matrix4x2D(m42f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 1), "matrix4x2d Matrix4x2F constructor");

            TEST_ASSERT(Matrix4x2D(m34f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d Matrix3x4F constructor");

            TEST_ASSERT(Matrix4x2D(m33f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d Matrix3F constructor");

            TEST_ASSERT(Matrix4x2D(m32f) == Matrix4x2D(0, 1, 0, 1, 0, 1, 0, 0), "matrix4x2d Matrix3x2F constructor");

            TEST_ASSERT(Matrix4x2D(m24f) == Matrix4x2D(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d Matrix2x4F constructor");

            TEST_ASSERT(Matrix4x2D(m23f) == Matrix4x2D(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d Matrix2x3F constructor");

            TEST_ASSERT(Matrix4x2D(m22f) == Matrix4x2D(0, 1, 0, 1, 0, 0, 0, 0), "matrix4x2d Matrix2F constructor");

            // mat 3x4
            TEST_ASSERT(Matrix3x4D(m44f) == Matrix3x4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                        "matrix3x4d Matrix4F constructor");

            TEST_ASSERT(Matrix3x4D(m43f) == Matrix3x4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                        "matrix3x4d Matrix4x3F constructor");

            TEST_ASSERT(Matrix3x4D(m42f) == Matrix3x4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                        "matrix3x4d Matrix4x2F constructor");

            TEST_ASSERT(Matrix3x4D(m34f) == Matrix3x4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                        "matrix3x4d Matrix3x4F constructor");

            TEST_ASSERT(Matrix3x4D(m33f) == Matrix3x4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                        "matrix3x4d Matrix3F constructor");

            TEST_ASSERT(Matrix3x4D(m32f) == Matrix3x4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                        "matrix3x4d Matrix3x2F constructor");

            TEST_ASSERT(Matrix3x4D(m24f) == Matrix3x4D(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0),
                        "matrix3x4d Matrix2x4F constructor");

            TEST_ASSERT(Matrix3x4D(m23f) == Matrix3x4D(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0),
                        "matrix3x4d Matrix2x3F constructor");

            TEST_ASSERT(Matrix3x4D(m22f) == Matrix3x4D(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0),
                        "matrix3x4d Matrix2F constructor");

            // mat 3
            TEST_ASSERT(Matrix3D(m44f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix4F constructor");

            TEST_ASSERT(Matrix3D(m43f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix4x3F constructor");

            TEST_ASSERT(Matrix3D(m42f) == Matrix3D(0, 1, 0, 0, 1, 0, 0, 1, 1), "matrix3d Matrix4x2F constructor");

            TEST_ASSERT(Matrix3D(m34f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix3x4F constructor");

            TEST_ASSERT(Matrix3D(m33f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 1, 2), "matrix3d Matrix3F constructor");

            TEST_ASSERT(Matrix3D(m32f) == Matrix3D(0, 1, 0, 0, 1, 0, 0, 1, 1), "matrix3d Matrix3x2F constructor");

            TEST_ASSERT(Matrix3D(m24f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 0, 1), "matrix3d Matrix2x4F constructor");

            TEST_ASSERT(Matrix3D(m23f) == Matrix3D(0, 1, 2, 0, 1, 2, 0, 0, 1), "matrix3d Matrix2x3F constructor");

            TEST_ASSERT(Matrix3D(m22f) == Matrix3D(0, 1, 0, 0, 1, 0, 0, 0, 1), "matrix3d Matrix2F constructor");

            // mat 3x2
            TEST_ASSERT(Matrix3x2D(m44f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix4F constructor");

            TEST_ASSERT(Matrix3x2D(m43f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix4x3F constructor");

            TEST_ASSERT(Matrix3x2D(m42f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix4x2F constructor");

            TEST_ASSERT(Matrix3x2D(m34f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix3x4F constructor");

            TEST_ASSERT(Matrix3x2D(m33f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix3F constructor");

            TEST_ASSERT(Matrix3x2D(m32f) == Matrix3x2D(0, 1, 0, 1, 0, 1), "matrix3x2d Matrix3x2F constructor");

            TEST_ASSERT(Matrix3x2D(m24f) == Matrix3x2D(0, 1, 0, 1, 0, 0), "matrix3x2d Matrix2x4F constructor");

            TEST_ASSERT(Matrix3x2D(m23f) == Matrix3x2D(0, 1, 0, 1, 0, 0), "matrix3x2d Matrix2x3F constructor");

            TEST_ASSERT(Matrix3x2D(m22f) == Matrix3x2D(0, 1, 0, 1, 0, 0), "matrix3x2d Matrix2F constructor");

            // mat 2x4
            TEST_ASSERT(Matrix2x4D(m44f) == Matrix2x4D(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d Matrix4F constructor");

            TEST_ASSERT(Matrix2x4D(m43f) == Matrix2x4D(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d Matrix4x3F constructor");

            TEST_ASSERT(Matrix2x4D(m42f) == Matrix2x4D(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d Matrix4x2F constructor");

            TEST_ASSERT(Matrix2x4D(m34f) == Matrix2x4D(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d Matrix3x4F constructor");

            TEST_ASSERT(Matrix2x4D(m33f) == Matrix2x4D(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d Matrix3F constructor");

            TEST_ASSERT(Matrix2x4D(m32f) == Matrix2x4D(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d Matrix3x2F constructor");

            TEST_ASSERT(Matrix2x4D(m24f) == Matrix2x4D(0, 1, 2, 3, 0, 1, 2, 3), "matrix2x4d Matrix2x4F constructor");

            TEST_ASSERT(Matrix2x4D(m23f) == Matrix2x4D(0, 1, 2, 0, 0, 1, 2, 0), "matrix2x4d Matrix2x3F constructor");

            TEST_ASSERT(Matrix2x4D(m22f) == Matrix2x4D(0, 1, 0, 0, 0, 1, 0, 0), "matrix2x4d Matrix2F constructor");

            // mat 2x3
            TEST_ASSERT(Matrix2x3D(m44f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix4F constructor");

            TEST_ASSERT(Matrix2x3D(m43f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix4x3F constructor");

            TEST_ASSERT(Matrix2x3D(m42f) == Matrix2x3D(0, 1, 0, 0, 1, 0), "matrix2x3d Matrix4x2F constructor");

            TEST_ASSERT(Matrix2x3D(m34f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix3x4F constructor");

            TEST_ASSERT(Matrix2x3D(m33f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix3F constructor");

            TEST_ASSERT(Matrix2x3D(m32f) == Matrix2x3D(0, 1, 0, 0, 1, 0), "matrix2x3d Matrix3x2F constructor");

            TEST_ASSERT(Matrix2x3D(m24f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix2x4F constructor");

            TEST_ASSERT(Matrix2x3D(m23f) == Matrix2x3D(0, 1, 2, 0, 1, 2), "matrix2x3d Matrix2x3F constructor");

            TEST_ASSERT(Matrix2x3D(m22f) == Matrix2x3D(0, 1, 0, 0, 1, 0), "matrix2x3d Matrix2F constructor");

            // mat 2
            TEST_ASSERT(Matrix2D(m44f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix4F constructor");

            TEST_ASSERT(Matrix2D(m43f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix4x3F constructor");

            TEST_ASSERT(Matrix2D(m42f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix4x2F constructor");

            TEST_ASSERT(Matrix2D(m34f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix3x4F constructor");

            TEST_ASSERT(Matrix2D(m33f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix3F constructor");

            TEST_ASSERT(Matrix2D(m32f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix3x2F constructor");

            TEST_ASSERT(Matrix2D(m24f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix2x4F constructor");

            TEST_ASSERT(Matrix2D(m23f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix2x3F constructor");

            TEST_ASSERT(Matrix2D(m22f) == Matrix2D(0, 1, 0, 1), "matrix2d Matrix2F constructor");
        }

        return 0;
    */
}
