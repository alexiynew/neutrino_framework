#include <math/math.hpp>
#include <unit_test/suite.hpp>

using neutrino::math::Matrix2x2f;
using neutrino::math::Matrix2x3f;
using neutrino::math::Matrix2x4f;
using neutrino::math::Matrix3x2f;
using neutrino::math::Matrix3x3f;
using neutrino::math::Matrix3x4f;
using neutrino::math::Matrix4x2f;
using neutrino::math::Matrix4x3f;
using neutrino::math::Matrix4x4f;

using neutrino::math::Matrix2f;
using neutrino::math::Matrix3f;
using neutrino::math::Matrix4f;

using neutrino::math::Vector2d;
using neutrino::math::Vector2f;
using neutrino::math::Vector2i;
using neutrino::math::Vector3d;
using neutrino::math::Vector3f;
using neutrino::math::Vector3i;
using neutrino::math::Vector4d;
using neutrino::math::Vector4f;
using neutrino::math::Vector4i;

class matrix_test : public neutrino::unit_test::Suite
{
public:
    matrix_test()
        : Suite("matrix_test")
    {
        add_test([this]() { size_check(); }, "size_check");
        add_test([this]() { default_constructor(); }, "default_constructor");
        add_test([this]() { copy_constructor(); }, "copy_constructor");
        add_test([this]() { one_argument_constructor(); }, "one_argument_constructor");
        add_test([this]() { const_pointer_constructor(); }, "const_pointer_constructor");
        add_test([this]() { pointer_constructor(); }, "pointer_constructor");
        add_test([this]() { Matrix4x4_constructors(); }, "Matrix4x4_constructors");
        add_test([this]() { Matrix4x3_constructors(); }, "Matrix4x3_constructors");
        add_test([this]() { Matrix4x2_constructors(); }, "Matrix4x2_constructors");
        add_test([this]() { Matrix3x4_constructors(); }, "Matrix3x4_constructors");
        add_test([this]() { Matrix3x3_constructors(); }, "Matrix3x3_constructors");
        add_test([this]() { Matrix3x2_constructors(); }, "Matrix3x2_constructors");
        add_test([this]() { Matrix2x4_constructors(); }, "Matrix2x4_constructors");
        add_test([this]() { Matrix2x3_constructors(); }, "Matrix2x3_constructors");
        add_test([this]() { Matrix2x2_constructors(); }, "Matrix2x2_constructors");
    }

private:
    void size_check()
    {
        constexpr Matrix2x2f Matrix22;
        constexpr Matrix2x3f Matrix23;
        constexpr Matrix2x4f Matrix24;

        constexpr Matrix3x2f Matrix32;
        constexpr Matrix3x3f Matrix33;
        constexpr Matrix3x4f Matrix34;

        constexpr Matrix4x2f Matrix42;
        constexpr Matrix4x3f Matrix43;
        constexpr Matrix4x4f Matrix44;

        static_assert(sizeof(Matrix22) == sizeof(float) * 2 * 2 && Matrix22.size() == 2,
                      "Matrix2x2 size check failed.");
        static_assert(sizeof(Matrix23) == sizeof(float) * 2 * 3 && Matrix23.size() == 2,
                      "Matrix2x3 size check failed.");
        static_assert(sizeof(Matrix24) == sizeof(float) * 2 * 4 && Matrix24.size() == 2,
                      "Matrix2x4 size check failed.");
        static_assert(sizeof(Matrix32) == sizeof(float) * 3 * 2 && Matrix32.size() == 3,
                      "Matrix3x2 size check failed.");
        static_assert(sizeof(Matrix33) == sizeof(float) * 3 * 3 && Matrix33.size() == 3,
                      "Matrix3x3 size check failed.");
        static_assert(sizeof(Matrix34) == sizeof(float) * 3 * 4 && Matrix34.size() == 3,
                      "Matrix3x4 size check failed.");
        static_assert(sizeof(Matrix42) == sizeof(float) * 4 * 2 && Matrix42.size() == 4,
                      "Matrix4x2 size check failed.");
        static_assert(sizeof(Matrix43) == sizeof(float) * 4 * 3 && Matrix43.size() == 4,
                      "Matrix4x3 size check failed.");
        static_assert(sizeof(Matrix44) == sizeof(float) * 4 * 4 && Matrix44.size() == 4,
                      "Matrix4x4 size check failed.");
    }

    void default_constructor()
    {
        constexpr Matrix2x2f Matrix22;
        constexpr Matrix2x3f Matrix23;
        constexpr Matrix2x4f Matrix24;

        constexpr Matrix3x2f Matrix32;
        constexpr Matrix3x3f Matrix33;
        constexpr Matrix3x4f Matrix34;

        constexpr Matrix4x2f Matrix42;
        constexpr Matrix4x3f Matrix43;
        constexpr Matrix4x4f Matrix44;

        // clang-format off
        TEST_ASSERT(Matrix22 == Matrix2x2f(
            1, 0,
            0, 1
        ), "Matrix2x2 default constructor failed.");

        TEST_ASSERT(Matrix23 == Matrix2x3f(
            1, 0, 0,
            0, 1, 0
        ), "Matrix2x3 default constructor failed.");

        TEST_ASSERT(Matrix24 == Matrix2x4f(
            1, 0, 0, 0,
            0, 1, 0, 0
        ), "Matrix2x4 default constructor failed.");

        TEST_ASSERT(Matrix32 == Matrix3x2f(
            1, 0,
            0, 1,
            0, 0
        ), "Matrix3x2 default constructor failed.");

        TEST_ASSERT(Matrix33 == Matrix3x3f(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        ), "Matrix3x3 default constructor failed.");

        TEST_ASSERT(Matrix34 == Matrix3x4f(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0
        ), "Matrix3x4 default constructor failed.");

        TEST_ASSERT(Matrix42 == Matrix4x2f(
            1, 0,
            0, 1,
            0, 0,
            0, 0
        ), "Matrix4x2 default constructor failed.");

        TEST_ASSERT(Matrix43 == Matrix4x3f(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1,
            0, 0, 0
        ), "Matrix4x3 default constructor failed.");

        TEST_ASSERT(Matrix44 == Matrix4x4f(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        ), "Matrix4x4 default constructor failed.");
        // clang-format on
    }

    void copy_constructor()
    {
        constexpr Matrix2x2f Matrix22;
        constexpr Matrix2x3f Matrix23;
        constexpr Matrix2x4f Matrix24;

        constexpr Matrix3x2f Matrix32;
        constexpr Matrix3x3f Matrix33;
        constexpr Matrix3x4f Matrix34;

        constexpr Matrix4x2f Matrix42;
        constexpr Matrix4x3f Matrix43;
        constexpr Matrix4x4f Matrix44;

        constexpr Matrix2x2f Matrix22_2 = Matrix22;
        constexpr Matrix2x3f Matrix23_2 = Matrix23;
        constexpr Matrix2x4f Matrix24_2 = Matrix24;

        constexpr Matrix3x2f Matrix32_2 = Matrix32;
        constexpr Matrix3x3f Matrix33_2 = Matrix33;
        constexpr Matrix3x4f Matrix34_2 = Matrix34;

        constexpr Matrix4x2f Matrix42_2 = Matrix42;
        constexpr Matrix4x3f Matrix43_2 = Matrix43;
        constexpr Matrix4x4f Matrix44_2 = Matrix44;

        TEST_ASSERT(Matrix22 == Matrix22_2, "Matrix2x2 copy constructor failed.");
        TEST_ASSERT(Matrix23 == Matrix23_2, "Matrix2x3 copy constructor failed.");
        TEST_ASSERT(Matrix24 == Matrix24_2, "Matrix2x4 copy constructor failed.");

        TEST_ASSERT(Matrix32 == Matrix32_2, "Matrix3x2 copy constructor failed.");
        TEST_ASSERT(Matrix33 == Matrix33_2, "Matrix3x3 copy constructor failed.");
        TEST_ASSERT(Matrix34 == Matrix34_2, "Matrix3x4 copy constructor failed.");

        TEST_ASSERT(Matrix42 == Matrix42_2, "Matrix4x2 copy constructor failed.");
        TEST_ASSERT(Matrix43 == Matrix43_2, "Matrix4x3 copy constructor failed.");
        TEST_ASSERT(Matrix44 == Matrix44_2, "Matrix4x4 copy constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr Matrix2x2f Matrix22;
        constexpr Matrix2x3f Matrix23;
        constexpr Matrix2x4f Matrix24;

        constexpr Matrix3x2f Matrix32;
        constexpr Matrix3x3f Matrix33;
        constexpr Matrix3x4f Matrix34;

        constexpr Matrix4x2f Matrix42;
        constexpr Matrix4x3f Matrix43;
        constexpr Matrix4x4f Matrix44;

        TEST_ASSERT(Matrix22 == Matrix2x2f(1), "Matrix2x2 one argument constructor failed.");
        TEST_ASSERT(Matrix23 == Matrix2x3f(1), "Matrix2x3 one argument constructor failed.");
        TEST_ASSERT(Matrix24 == Matrix2x4f(1), "Matrix2x4 one argument constructor failed.");

        TEST_ASSERT(Matrix32 == Matrix3x2f(1), "Matrix3x2 one argument constructor failed.");
        TEST_ASSERT(Matrix33 == Matrix3x3f(1), "Matrix3x3 one argument constructor failed.");
        TEST_ASSERT(Matrix34 == Matrix3x4f(1), "Matrix3x4 one argument constructor failed.");

        TEST_ASSERT(Matrix42 == Matrix4x2f(1), "Matrix4x2 one argument constructor failed.");
        TEST_ASSERT(Matrix43 == Matrix4x3f(1), "Matrix4x3 one argument constructor failed.");
        TEST_ASSERT(Matrix44 == Matrix4x4f(1), "Matrix4x4 one argument constructor failed.");
    }

    void const_pointer_constructor()
    {
        const float data4[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
        const float data3[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        const float data2[] = {0, 1, 0, 1, 0, 1, 0, 1};

        const Matrix4x4f m44(data4);
        const Matrix3x4f m34(data4);
        const Matrix2x4f m24(data4);

        const Matrix4x3f m43(data3);
        const Matrix3x3f m33(data3);
        const Matrix2x3f m23(data3);

        const Matrix4x2f m42(data2);
        const Matrix3x2f m32(data2);
        const Matrix2x2f m22(data2);

        const Vector4f tmp4f = {0, 1, 2, 3};
        const Vector3f tmp3f = {0, 1, 2};
        const Vector2f tmp2f = {0, 1};

        TEST_ASSERT(m44 == Matrix4x4f(tmp4f, tmp4f, tmp4f, tmp4f), "Matrix4x4 from pointer constructor failed.");
        TEST_ASSERT(m34 == Matrix3x4f(tmp4f, tmp4f, tmp4f), "Matrix3x4 from pointer constructor failed.");
        TEST_ASSERT(m24 == Matrix2x4f(tmp4f, tmp4f), "Matrix2x4 from pointer constructor failed.");

        TEST_ASSERT(m43 == Matrix4x3f(tmp3f, tmp3f, tmp3f, tmp3f), "Matrix4x3 from pointer constructor failed.");
        TEST_ASSERT(m33 == Matrix3x3f(tmp3f, tmp3f, tmp3f), "Matrix3x3 from pointer constructor failed.");
        TEST_ASSERT(m23 == Matrix2x3f(tmp3f, tmp3f), "Matrix2x3 from pointer constructor failed.");

        TEST_ASSERT(m42 == Matrix4x2f(tmp2f, tmp2f, tmp2f, tmp2f), "Matrix4x3 from pointer constructor.");
        TEST_ASSERT(m32 == Matrix3x2f(tmp2f, tmp2f, tmp2f), "Matrix3x3 from pointer constructor.");
        TEST_ASSERT(m22 == Matrix2x2f(tmp2f, tmp2f), "Matrix2x3 from pointer constructor.");
    }

    void pointer_constructor()
    {
        float data4[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
        float data3[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        float data2[] = {0, 1, 0, 1, 0, 1, 0, 1};

        const Matrix4x4f m44(data4);
        const Matrix3x4f m34(data4);
        const Matrix2x4f m24(data4);

        const Matrix4x3f m43(data3);
        const Matrix3x3f m33(data3);
        const Matrix2x3f m23(data3);

        const Matrix4x2f m42(data2);
        const Matrix3x2f m32(data2);
        const Matrix2x2f m22(data2);

        const Vector4f tmp4f = {0, 1, 2, 3};
        const Vector3f tmp3f = {0, 1, 2};
        const Vector2f tmp2f = {0, 1};

        TEST_ASSERT(m44 == Matrix4x4f(tmp4f, tmp4f, tmp4f, tmp4f), "Matrix4x4 from pointer constructor failed.");
        TEST_ASSERT(m34 == Matrix3x4f(tmp4f, tmp4f, tmp4f), "Matrix3x4 from pointer constructor failed.");
        TEST_ASSERT(m24 == Matrix2x4f(tmp4f, tmp4f), "Matrix2x4 from pointer constructor failed.");

        TEST_ASSERT(m43 == Matrix4x3f(tmp3f, tmp3f, tmp3f, tmp3f), "Matrix4x3 from pointer constructor failed.");
        TEST_ASSERT(m33 == Matrix3x3f(tmp3f, tmp3f, tmp3f), "Matrix3x3 from pointer constructor failed.");
        TEST_ASSERT(m23 == Matrix2x3f(tmp3f, tmp3f), "Matrix2x3 from pointer constructor failed.");

        TEST_ASSERT(m42 == Matrix4x2f(tmp2f, tmp2f, tmp2f, tmp2f), "Matrix4x3 from pointer constructor.");
        TEST_ASSERT(m32 == Matrix3x2f(tmp2f, tmp2f, tmp2f), "Matrix3x3 from pointer constructor.");
        TEST_ASSERT(m22 == Matrix2x2f(tmp2f, tmp2f), "Matrix2x3 from pointer constructor.");
    }

    void Matrix4x4_constructors()
    {
        // clang-format off
        const Matrix4x4f m1 = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const Matrix4x4f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4),
            Vector4i(1, 2, 3, 4),
            Vector4f(1, 2, 3, 4)
        };

        const Matrix4x4f m3 = {
            Vector3f(1, 2, 3), 4,
            Vector3d(1, 2, 3), 4,
            Vector3i(1, 2, 3), 4,
            Vector3f(1, 2, 3), 4
        };

        const Matrix4x4f m4 = {
            1, Vector3f(2, 3, 4),
            1, Vector3d(2, 3, 4),
            1, Vector3i(2, 3, 4),
            1, Vector3f(2, 3, 4)
        };

        const Matrix4x4f m5 = {
            Vector2f(1, 2), Vector2f(3, 4),
            Vector2d(1, 2), Vector2d(3, 4),
            Vector2i(1, 2), Vector2i(3, 4),
            Vector2f(1, 2), Vector2f(3, 4)
        };

        const Matrix4x4f m6 = {
            Vector2f(1, 2), 3, 4,
            Vector2d(1, 2), 3, 4,
            Vector2i(1, 2), 3, 4,
            Vector2f(1, 2), 3, 4
        };

        const Matrix4x4f m7 = {
            1, Vector2f(2, 3), 4,
            1, Vector2d(2, 3), 4,
            1, Vector2i(2, 3), 4,
            1, Vector2f(2, 3), 4
        };

        const Matrix4x4f m8 = {
            1, 2, Vector2f(3, 4),
            1, 2, Vector2d(3, 4),
            1, 2, Vector2i(3, 4),
            1, 2, Vector2f(3, 4)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix4x4f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix4x4f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix4x4f constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix4x4f constructor failed.");
        TEST_ASSERT(m1 == m6, "Matrix4x4f constructor failed.");
        TEST_ASSERT(m1 == m7, "Matrix4x4f constructor failed.");
        TEST_ASSERT(m1 == m8, "Matrix4x4f constructor failed.");
    }

    void Matrix4x3_constructors()
    {
        // clang-format off
        const Matrix4x3f m1 = {
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f
        };

        const Matrix4x3f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4),
            Vector4i(1, 2, 3, 4),
            Vector4f(1, 2, 3, 4)
        };

        const Matrix4x3f m3 = {
            Vector3f(1, 2, 3),
            Vector3d(1, 2, 3),
            Vector3i(1, 2, 3),
            Vector3f(1, 2, 3)
        };

        const Matrix4x3f m4 = {
            Vector2f(1, 2), 3,
            Vector2d(1, 2), 3,
            Vector2i(1, 2), 3,
            Vector2f(1, 2), 3
        };

        const Matrix4x3f m5 = {
            1, Vector2f(2, 3),
            1, Vector2d(2, 3),
            1, Vector2i(2, 3),
            1, Vector2f(2, 3)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix4x3f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix4x3f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix4x3f constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix4x3f constructor failed.");
    }

    void Matrix4x2_constructors()
    {
        // clang-format off
        const Matrix4x2f m1 = {
            1.0f, 2.0f,
            1.0f, 2.0f,
            1.0f, 2.0f,
            1.0f, 2.0f
        };

        const Matrix4x2f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4),
            Vector4i(1, 2, 3, 4),
            Vector4f(1, 2, 3, 4)
        };

        const Matrix4x2f m3 = {
            Vector3f(1, 2, 3),
            Vector3d(1, 2, 3),
            Vector3i(1, 2, 3),
            Vector3f(1, 2, 3)
        };

        const Matrix4x2f m4 = {
            Vector2f(1, 2),
            Vector2d(1, 2),
            Vector2i(1, 2),
            Vector2f(1, 2)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix4x2f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix4x2f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix4x2f constructor failed.");
    }

    void Matrix3x4_constructors()
    {
        // clang-format off
        const Matrix3x4f m1 = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const Matrix3x4f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4),
            Vector4i(1, 2, 3, 4)
        };

        const Matrix3x4f m3 = {
            Vector3f(1, 2, 3), 4,
            Vector3d(1, 2, 3), 4,
            Vector3i(1, 2, 3), 4
        };

        const Matrix3x4f m4 = {
            1, Vector3f(2, 3, 4),
            1, Vector3d(2, 3, 4),
            1, Vector3i(2, 3, 4)
        };

        const Matrix3x4f m5 = {
            Vector2f(1, 2), Vector2f(3, 4),
            Vector2d(1, 2), Vector2d(3, 4),
            Vector2i(1, 2), Vector2i(3, 4)
        };

        const Matrix3x4f m6 = {
            Vector2f(1, 2), 3, 4,
            Vector2d(1, 2), 3, 4,
            Vector2i(1, 2), 3, 4
        };

        const Matrix3x4f m7 = {
            1, Vector2f(2, 3), 4,
            1, Vector2d(2, 3), 4,
            1, Vector2i(2, 3), 4
        };

        const Matrix3x4f m8 = {
            1, 2, Vector2f(3, 4),
            1, 2, Vector2d(3, 4),
            1, 2, Vector2i(3, 4)\
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix3x4f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix3x4f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix3x4f constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix3x4f constructor failed.");
        TEST_ASSERT(m1 == m6, "Matrix3x4f constructor failed.");
        TEST_ASSERT(m1 == m7, "Matrix3x4f constructor failed.");
        TEST_ASSERT(m1 == m8, "Matrix3x4f constructor failed.");
    }

    void Matrix3x3_constructors()
    {
        // clang-format off
        const Matrix3x3f m1 = {
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f
        };

        const Matrix3x3f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4),
            Vector4i(1, 2, 3, 4)
        };

        const Matrix3x3f m3 = {
            Vector3f(1, 2, 3),
            Vector3d(1, 2, 3),
            Vector3i(1, 2, 3)
        };

        const Matrix3x3f m4 = {
            Vector2f(1, 2), 3,
            Vector2d(1, 2), 3,
            Vector2i(1, 2), 3
        };

        const Matrix3x3f m5 = {
            1, Vector2f(2, 3),
            1, Vector2d(2, 3),
            1, Vector2i(2, 3)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix3x3f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix3x3f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix3x3f constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix3x3f constructor failed.");
    }

    void Matrix3x2_constructors()
    {
        // clang-format off
        const Matrix3x2f m1 = {
            1.0f, 2.0f,
            1.0f, 2.0f,
            1.0f, 2.0f
        };

        const Matrix3x2f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4),
            Vector4i(1, 2, 3, 4)
        };

        const Matrix3x2f m3 = {
            Vector3f(1, 2, 3),
            Vector3d(1, 2, 3),
            Vector3i(1, 2, 3)
        };

        const Matrix3x2f m4 = {
            Vector2f(1, 2),
            Vector2d(1, 2),
            Vector2i(1, 2)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix3x2f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix3x2f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix3x2f constructor failed.");
    }

    void Matrix2x4_constructors()
    {
        // clang-format off
        const Matrix2x4f m1 = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const Matrix2x4f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4)
        };

        const Matrix2x4f m3 = {
            Vector3f(1, 2, 3), 4,
            Vector3d(1, 2, 3), 4
        };

        const Matrix2x4f m4 = {
            1, Vector3f(2, 3, 4),
            1, Vector3d(2, 3, 4)
        };

        const Matrix2x4f m5 = {
            Vector2f(1, 2), Vector2f(3, 4),
            Vector2d(1, 2), Vector2d(3, 4)
        };

        const Matrix2x4f m6 = {
            Vector2f(1, 2), 3, 4,
            Vector2d(1, 2), 3, 4
        };

        const Matrix2x4f m7 = {
            1, Vector2f(2, 3), 4,
            1, Vector2d(2, 3), 4
        };

        const Matrix2x4f m8 = {
            1, 2, Vector2f(3, 4),
            1, 2, Vector2d(3, 4)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix2x4f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix2x4f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix2x4f constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix2x4f constructor failed.");
        TEST_ASSERT(m1 == m6, "Matrix2x4f constructor failed.");
        TEST_ASSERT(m1 == m7, "Matrix2x4f constructor failed.");
        TEST_ASSERT(m1 == m8, "Matrix2x4f constructor failed.");
    }

    void Matrix2x3_constructors()
    {
        // clang-format off
        const Matrix2x3f m1 = {
            1.0f, 2.0f, 3.0f,
            1.0f, 2.0f, 3.0f
        };

        const Matrix2x3f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4)
        };

        const Matrix2x3f m3 = {
            Vector3f(1, 2, 3),
            Vector3d(1, 2, 3)
        };

        const Matrix2x3f m4 = {
            Vector2f(1, 2), 3,
            Vector2d(1, 2), 3
        };

        const Matrix2x3f m5 = {
            1, Vector2f(2, 3),
            1, Vector2d(2, 3)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix2x3f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix2x3f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix2x3f constructor failed.");
        TEST_ASSERT(m1 == m5, "Matrix2x3f constructor failed.");
    }

    void Matrix2x2_constructors()
    {
        // clang-format off
        const Matrix2x2f m1 = {
            1.0f, 2.0f,
            1.0f, 2.0f
        };

        const Matrix2x2f m2 = {
            Vector4f(1, 2, 3, 4),
            Vector4d(1, 2, 3, 4)
        };

        const Matrix2x2f m3 = {
            Vector3f(1, 2, 3),
            Vector3d(1, 2, 3)
        };

        const Matrix2x2f m4 = {
            Vector2f(1, 2),
            Vector2d(1, 2)
        };
        // clang-format on

        TEST_ASSERT(m1 == m2, "Matrix2x2f constructor failed.");
        TEST_ASSERT(m1 == m3, "Matrix2x2f constructor failed.");
        TEST_ASSERT(m1 == m4, "Matrix2x2f constructor failed.");
    }
};

class matrix_from_matrix_test : public neutrino::unit_test::Suite
{
public:
    matrix_from_matrix_test()
        : Suite("matrix_from_matrix_test")
    {
        add_test([this]() { Matrix4x4_constructors(); }, "Matrix4x4_constructors");
        add_test([this]() { Matrix4x3_constructors(); }, "Matrix4x3_constructors");
        add_test([this]() { Matrix4x2_constructors(); }, "Matrix4x2_constructors");
        add_test([this]() { Matrix3x4_constructors(); }, "Matrix3x4_constructors");
        add_test([this]() { Matrix3x3_constructors(); }, "Matrix3x3_constructors");
        add_test([this]() { Matrix3x2_constructors(); }, "Matrix3x2_constructors");
        add_test([this]() { Matrix2x4_constructors(); }, "Matrix2x4_constructors");
        add_test([this]() { Matrix2x3_constructors(); }, "Matrix2x3_constructors");
        add_test([this]() { Matrix2x2_constructors(); }, "Matrix2x2_constructors");

        // clang-format off
        Matrix44 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        Matrix43 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        Matrix42 = {
            0, 1,
            0, 1,
            0, 1,
            0, 1
        };

        Matrix34 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        Matrix33 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        Matrix32 = {
            0, 1,
            0, 1,
            0, 1
        };

        Matrix24 = {
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        Matrix23 = {
            0, 1, 2,
            0, 1, 2
        };

        Matrix22 = {
            0, 1,
            0, 1
        };
        // clang-format on
    }

private:
    void Matrix4x4_constructors()
    {
        TEST_ASSERT(Matrix4f(Matrix44) == Matrix4f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix4x4 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix4f(Matrix43) == Matrix4f(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 1),
                    "Matrix4x4 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix4f(Matrix42) == Matrix4f(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1),
                    "Matrix4x4 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix4f(Matrix34) == Matrix4f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix4f(Matrix33) == Matrix4f(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix4f(Matrix32) == Matrix4f(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix4f(Matrix24) == Matrix4f(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix4f(Matrix23) == Matrix4f(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix4f(Matrix22) == Matrix4f(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1),
                    "Matrix4x4 from Matrix2x2 constructor failed.");
    }

    void Matrix4x3_constructors()
    {
        TEST_ASSERT(Matrix4x3f(Matrix44) == Matrix4x3f(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix4x3 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix4x3f(Matrix43) == Matrix4x3f(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix4x3 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix4x3f(Matrix42) == Matrix4x3f(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0),
                    "Matrix4x3 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix4x3f(Matrix34) == Matrix4x3f(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                    "Matrix4x3 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix4x3f(Matrix33) == Matrix4x3f(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0),
                    "Matrix4x3 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix4x3f(Matrix32) == Matrix4x3f(0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix4x3f(Matrix24) == Matrix4x3f(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix4x3f(Matrix23) == Matrix4x3f(0, 1, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix4x3f(Matrix22) == Matrix4x3f(0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
                    "Matrix4x3 form Matrix2x2 constructor failed.");
    }

    void Matrix4x2_constructors()
    {
        TEST_ASSERT(Matrix4x2f(Matrix44) == Matrix4x2f(0, 1, 0, 1, 0, 1, 0, 1),
                    "Matrix4x2 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix4x2f(Matrix43) == Matrix4x2f(0, 1, 0, 1, 0, 1, 0, 1),
                    "Matrix4x2 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix4x2f(Matrix42) == Matrix4x2f(0, 1, 0, 1, 0, 1, 0, 1),
                    "Matrix4x2 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix4x2f(Matrix34) == Matrix4x2f(0, 1, 0, 1, 0, 1, 0, 0),
                    "Matrix4x2 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix4x2f(Matrix33) == Matrix4x2f(0, 1, 0, 1, 0, 1, 0, 0),
                    "Matrix4x2 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix4x2f(Matrix32) == Matrix4x2f(0, 1, 0, 1, 0, 1, 0, 0),
                    "Matrix4x2 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix4x2f(Matrix24) == Matrix4x2f(0, 1, 0, 1, 0, 0, 0, 0),
                    "Matrix4x2 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix4x2f(Matrix23) == Matrix4x2f(0, 1, 0, 1, 0, 0, 0, 0),
                    "Matrix4x2 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix4x2f(Matrix22) == Matrix4x2f(0, 1, 0, 1, 0, 0, 0, 0),
                    "Matrix4x2 from Matrix2x2 constructor failed.");
    }

    void Matrix3x4_constructors()
    {
        TEST_ASSERT(Matrix3x4f(Matrix44) == Matrix3x4f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix3x4 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix3x4f(Matrix43) == Matrix3x4f(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix3x4 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix3x4f(Matrix42) == Matrix3x4f(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                    "Matrix3x4 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix3x4f(Matrix34) == Matrix3x4f(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix3x4 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix3x4f(Matrix33) == Matrix3x4f(0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix3x4 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix3x4f(Matrix32) == Matrix3x4f(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),
                    "Matrix3x4 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix3x4f(Matrix24) == Matrix3x4f(0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 0),
                    "Matrix3x4 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix3x4f(Matrix23) == Matrix3x4f(0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0),
                    "Matrix3x4 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix3x4f(Matrix22) == Matrix3x4f(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0),
                    "Matrix3x4 from Matrix2x2 constructor failed.");
    }

    void Matrix3x3_constructors()
    {
        TEST_ASSERT(Matrix3f(Matrix44) == Matrix3f(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix3f(Matrix43) == Matrix3f(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix3f(Matrix42) == Matrix3f(0, 1, 0, 0, 1, 0, 0, 1, 1),
                    "Matrix3x3 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix3f(Matrix34) == Matrix3f(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix3f(Matrix33) == Matrix3f(0, 1, 2, 0, 1, 2, 0, 1, 2),
                    "Matrix3x3 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix3f(Matrix32) == Matrix3f(0, 1, 0, 0, 1, 0, 0, 1, 1),
                    "Matrix3x3 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix3f(Matrix24) == Matrix3f(0, 1, 2, 0, 1, 2, 0, 0, 1),
                    "Matrix3x3 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix3f(Matrix23) == Matrix3f(0, 1, 2, 0, 1, 2, 0, 0, 1),
                    "Matrix3x3 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix3f(Matrix22) == Matrix3f(0, 1, 0, 0, 1, 0, 0, 0, 1),
                    "Matrix3x3 from Matrix2x2 constructor failed.");
    }

    void Matrix3x2_constructors()
    {
        TEST_ASSERT(Matrix3x2f(Matrix44) == Matrix3x2f(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix3x2f(Matrix43) == Matrix3x2f(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix3x2f(Matrix42) == Matrix3x2f(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix3x2f(Matrix34) == Matrix3x2f(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix3x2f(Matrix33) == Matrix3x2f(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix3x2f(Matrix32) == Matrix3x2f(0, 1, 0, 1, 0, 1),
                    "Matrix3x2 from Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix3x2f(Matrix24) == Matrix3x2f(0, 1, 0, 1, 0, 0),
                    "Matrix3x2 from Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix3x2f(Matrix23) == Matrix3x2f(0, 1, 0, 1, 0, 0),
                    "Matrix3x2 from Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix3x2f(Matrix22) == Matrix3x2f(0, 1, 0, 1, 0, 0),
                    "Matrix3x2 from Matrix2x2 constructor failed.");
    }

    void Matrix2x4_constructors()
    {
        TEST_ASSERT(Matrix2x4f(Matrix44) == Matrix2x4f(0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix2x4 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix2x4f(Matrix43) == Matrix2x4f(0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix2x4 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix2x4f(Matrix42) == Matrix2x4f(0, 1, 0, 0, 0, 1, 0, 0),
                    "Matrix2x4 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix2x4f(Matrix34) == Matrix2x4f(0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix2x4 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix2x4f(Matrix33) == Matrix2x4f(0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix2x4 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix2x4f(Matrix32) == Matrix2x4f(0, 1, 0, 0, 0, 1, 0, 0),
                    "Matrix2x4 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix2x4f(Matrix24) == Matrix2x4f(0, 1, 2, 3, 0, 1, 2, 3),
                    "Matrix2x4 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix2x4f(Matrix23) == Matrix2x4f(0, 1, 2, 0, 0, 1, 2, 0),
                    "Matrix2x4 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix2x4f(Matrix22) == Matrix2x4f(0, 1, 0, 0, 0, 1, 0, 0),
                    "Matrix2x4 form Matrix2x2 constructor failed.");
    }

    void Matrix2x3_constructors()
    {
        TEST_ASSERT(Matrix2x3f(Matrix44) == Matrix2x3f(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix2x3f(Matrix43) == Matrix2x3f(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix2x3f(Matrix42) == Matrix2x3f(0, 1, 0, 0, 1, 0),
                    "Matrix2x3 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix2x3f(Matrix34) == Matrix2x3f(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix2x3f(Matrix33) == Matrix2x3f(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix2x3f(Matrix32) == Matrix2x3f(0, 1, 0, 0, 1, 0),
                    "Matrix2x3 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix2x3f(Matrix24) == Matrix2x3f(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix2x3f(Matrix23) == Matrix2x3f(0, 1, 2, 0, 1, 2),
                    "Matrix2x3 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix2x3f(Matrix22) == Matrix2x3f(0, 1, 0, 0, 1, 0),
                    "Matrix2x3 form Matrix2x2 constructor failed.");
    }

    void Matrix2x2_constructors()
    {
        TEST_ASSERT(Matrix2f(Matrix44) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix4x4 constructor failed.");
        TEST_ASSERT(Matrix2f(Matrix43) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix4x3 constructor failed.");
        TEST_ASSERT(Matrix2f(Matrix42) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix4x2 constructor failed.");

        TEST_ASSERT(Matrix2f(Matrix34) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix3x4 constructor failed.");
        TEST_ASSERT(Matrix2f(Matrix33) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix3x3 constructor failed.");
        TEST_ASSERT(Matrix2f(Matrix32) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix3x2 constructor failed.");

        TEST_ASSERT(Matrix2f(Matrix24) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix2x4 constructor failed.");
        TEST_ASSERT(Matrix2f(Matrix23) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix2x3 constructor failed.");
        TEST_ASSERT(Matrix2f(Matrix22) == Matrix2f(0, 1, 0, 1), "Matrix2x2 form Matrix2x2 constructor failed.");
    }

    Matrix4x4f Matrix44;
    Matrix4x3f Matrix43;
    Matrix4x2f Matrix42;

    Matrix3x4f Matrix34;
    Matrix3x3f Matrix33;
    Matrix3x2f Matrix32;

    Matrix2x4f Matrix24;
    Matrix2x3f Matrix23;
    Matrix2x2f Matrix22;
};

int main()
{
    return run_tests(matrix_test(), matrix_from_matrix_test());
}
