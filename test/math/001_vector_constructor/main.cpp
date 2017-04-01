#include <math/math.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;

class vector_test : public framework::unit_test::suite
{
public:
    vector_test()
        : suite("vector_test")
    {
        add_test([this]() { size_check(); }, "size_check");
        add_test([this]() { default_constructor(); }, "default_constructor");
        add_test([this]() { one_argument_constructor(); }, "one_argument_constructor");
        add_test([this]() { non_default_constructor(); }, "non_default_constructor");
        add_test([this]() { type_cast_constructor(); }, "type_cast_constructor");
        add_test([this]() { from_vector_of_bool_constructor(); }, "from_vector_of_bool_constructor");
        add_test([this]() { pointer_constructor(); }, "pointer_constructor");
        add_test([this]() { integer_zero_constructor(); }, "integer_zero_constructor");
        add_test([this]() { from_vector4d_constructor(); }, "from_vector4d_constructor");
        add_test([this]() { from_vector3d_constructor(); }, "from_vector3d_constructor");
        add_test([this]() { from_vector2d_constructor(); }, "from_vector2d_constructor");
    }

private:
    void size_check()
    {
        constexpr vector4D v4d;
        constexpr vector3F v3f;
        constexpr vector2I v2i;

        static_assert(sizeof(v4d) == sizeof(double) * 4 && v4d.size() == 4, "Vector4D size check failed.");
        static_assert(sizeof(v3f) == sizeof(float) * 3 && v3f.size() == 3, "Vector3F size check failed.");
        static_assert(sizeof(v2i) == sizeof(int) * 2 && v2i.size() == 2, "Vector2I size check failed.");
    }

    void default_constructor()
    {
        constexpr vector4D v4d;
        constexpr vector3F v3f;
        constexpr vector2I v2i;

        static_assert(v4d == vector4D(0, 0, 0, 1), "Vector4D default constructor failed.");
        static_assert(v3f == vector3F(0, 0, 0), "Vector3F default constructor failed.");
        static_assert(v2i == vector2I(0, 0), "Vector2I default constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr vector4D v4d = vector4D(1.4);
        constexpr vector3F v3f = vector3F(2.4f);
        constexpr vector2I v2i = vector2I(3);

        static_assert(v4d == vector4D(1.4, 1.4, 1.4, 1.4), "Vector4D one argument constructor failed.");
        static_assert(v3f == vector3F(2.4f, 2.4f, 2.4f), "Vector3F one argument constructor failed.");
        static_assert(v2i == vector2I(3, 3), "Vector2I one argument constructor failed.");
    }

    void non_default_constructor()
    {
        const vector4D v4d = {1.1, 2.2, 3.3, 4.4};
        const vector3F v3f = {5.5f, 6.6f, 7.7f};
        const vector2I v2i = {1, 2};

        // clang-format off
        TEST_ASSERT(almost_equal(v4d[0], 1.1) &&
                    almost_equal(v4d[1], 2.2) &&
                    almost_equal(v4d[2], 3.3) &&
                    almost_equal(v4d[3], 4.4),
                    "Vector4D non default constructor failed.");

        TEST_ASSERT(almost_equal(v3f[0], 5.5f) &&
                    almost_equal(v3f[1], 6.6f) &&
                    almost_equal(v3f[2], 7.7f),
                    "Vector3F non default constructor failed.");

        TEST_ASSERT(v2i[0] == 1 && v2i[1] == 2, "Vector2I non default constructor failed.");
        // clang-format on
    }

    void type_cast_constructor()
    {
        constexpr vector4D v4d = {1.1, 2.2, 3.3, 4.4};
        constexpr vector3F v3f = {5.5f, 6.6f, 7.7f};
        constexpr vector2I v2i = {1, 2};

        constexpr vector4I v4i = vector4I(v4d);
        constexpr vector3D v3d = vector3D(v3f);
        constexpr vector2F v2f = vector2F(v2i);

        static_assert(v4i == vector4I(1, 2, 3, 4), "Vector4I type cast constructor failed.");
        static_assert(v3d == vector3D(5.5f, 6.6f, 7.7f), "Vector3D type cast constructor failed.");
        static_assert(v2f == vector2F(1.0f, 2.0f), "Vector2F type cast constructor failed.");
    }

    void from_vector_of_bool_constructor()
    {
        constexpr vector4B v4b = vector4B(false, true, false, true);
        constexpr vector3B v3b = vector3B(false, true, false);
        constexpr vector2B v2b = vector2B(false, true);

        constexpr vector4D v4d = vector4D(v4b);
        constexpr vector3F v3f = vector3F(v3b);
        constexpr vector2I v2i = vector2I(v2b);

        static_assert(v4d == vector4D(0.0, 1.0, 0.0, 1.0), "Vector4D from bool cast constructor failed.");
        static_assert(v3f == vector3F(0.0f, 1.0f, 0.0f), "Vector3F from bool cast constructor failed.");
        static_assert(v2i == vector2I(0, 1), "Vector2I from bool cast constructor failed.");
    }

    void pointer_constructor()
    {
        const double data_d[4]       = {1.0, 2.0, 3.0, 4.0};
        const float data_f[3]        = {1.0f, 2.0f, 3.0f};
        const int data_i[2]          = {1, 2};
        const unsigned int data_u[2] = {1, 2};

        const vector4D v4d(data_d);
        const vector3F v3f(data_f);
        const vector2I v2i(data_i);
        const vector2U v2u(data_u);

        TEST_ASSERT(v4d == vector4D(1.0, 2.0, 3.0, 4.0), "Vector4D pointer constructor failed.");
        TEST_ASSERT(v3f == vector3F(1.0f, 2.0f, 3.0f), "Vector3F pointer constructor failed.");
        TEST_ASSERT(v2i == vector2I(1, 2), "Vector2I pointer constructor failed.");
        TEST_ASSERT(v2u == vector2U(1, 2), "Vector2U pointer constructor failed.");
    }

    void integer_zero_constructor()
    {
        const vector2I v2i_zero(0);
        const vector2U v2u_zero(0);

        TEST_ASSERT(v2i_zero == vector2I(0, 0), "Vector2I zero constructor failed.");
        TEST_ASSERT(v2u_zero == vector2U(0, 0), "Vector2U zero constructor failed.");
    }

    void from_vector4d_constructor()
    {
        constexpr vector4D v4d = {1.1, 2.2, 3.3, 4.4};

        constexpr vector3D v3d = vector3D(v4d);
        constexpr vector2D v2d = vector2D(v4d);

        static_assert(v3d == vector3D(1.1, 2.2, 3.3), "Vector3D from vector4D constructor failed.");
        static_assert(v2d == vector2D(1.1, 2.2), "Vector2D from vector4D constructor failed.");
    }

    void from_vector3d_constructor()
    {
        constexpr vector3D v3d = {1.1, 2.2, 3.3};

        constexpr vector4D v4d1 = vector4D(v3d);
        constexpr vector4D v4d2 = vector4D(v3d, 4.4);
        constexpr vector4D v4d3 = vector4D(4.4, v3d);

        constexpr vector2D v2d = vector2D(v3d);

        static_assert(v4d1 == vector4D(1.1, 2.2, 3.3, 1.0), "Vector4D from vector3D constructor failed.");
        static_assert(v4d2 == vector4D(1.1, 2.2, 3.3, 4.4), "Vector4D from vector3D and scalar constructor failed.");
        static_assert(v4d3 == vector4D(4.4, 1.1, 2.2, 3.3), "Vector4D from scalar and vector3D constructor failed.");

        static_assert(v2d == vector2D(1.1, 2.2), "Vector2D from vector3D constructor failed.");
    }

    void from_vector2d_constructor()
    {
        constexpr vector2D v2d = {1.1, 2.2};

        constexpr vector4D v4d1 = vector4D(v2d);
        constexpr vector4D v4d2 = vector4D(v2d, 3.3, 4.4);
        constexpr vector4D v4d3 = vector4D(3.3, v2d, 4.4);
        constexpr vector4D v4d4 = vector4D(3.3, 4.4, v2d);
        constexpr vector4D v4d5 = vector4D(v2d, v2d);

        constexpr vector3D v3d1 = vector3D(v2d);
        constexpr vector3D v3d2 = vector3D(v2d, 3.3);
        constexpr vector3D v3d3 = vector3D(3.3, v2d);

        static_assert(v4d1 == vector4D(1.1, 2.2, 0.0, 1.0), "Vector4D from vector2D constructor failed.");
        static_assert(v4d2 == vector4D(1.1, 2.2, 3.3, 4.4), "Vector4D from vector2D and 2 scalars constructor failed.");
        static_assert(v4d3 == vector4D(3.3, 1.1, 2.2, 4.4),
                      "Vector4D from scalar, vector2D and scalar constructor failed.");
        static_assert(v4d4 == vector4D(3.3, 4.4, 1.1, 2.2), "Vector4D from 2 scalars and vector2D constructor failed.");
        static_assert(v4d5 == vector4D(1.1, 2.2, 1.1, 2.2), "Vector4D from 2 vector2D constructor failed.");

        static_assert(v3d1 == vector3D(1.1, 2.2, 0.0), "Vector3D from vector2D constructor failed.");
        static_assert(v3d2 == vector3D(1.1, 2.2, 3.3), "Vector3D from vector2D and scalar constructor failed.");
        static_assert(v3d3 == vector3D(3.3, 1.1, 2.2), "Vector3D from scalar and vector2D constructor failed.");
    }
};

class bool_vector_test : public framework::unit_test::suite
{
public:
    bool_vector_test()
        : suite("bool_vector_test")
    {
        add_test([this]() { size_check(); }, "size_check");
        add_test([this]() { default_constructor(); }, "default_constructor");
        add_test([this]() { one_argument_constructor(); }, "one_argument_constructor");
        add_test([this]() { non_default_constructor(); }, "non_default_constructor");
        add_test([this]() { type_cast_constructor(); }, "type_cast_constructor");
        add_test([this]() { pointer_constructor(); }, "pointer_constructor");
        add_test([this]() { from_vector4b_constructor(); }, "from_vector4b_constructor");
        add_test([this]() { from_vector3b_constructor(); }, "from_vector3b_constructor");
        add_test([this]() { from_vector2b_constructor(); }, "from_vector2b_constructor");
    }

private:
    void size_check()
    {
        constexpr vector4B v4b;
        constexpr vector3B v3b;
        constexpr vector2B v2b;

        static_assert(sizeof(v4b) == sizeof(bool) * 4 && v4b.size() == 4, "Vector4B size check failed.");
        static_assert(sizeof(v3b) == sizeof(bool) * 3 && v3b.size() == 3, "Vector3B size check failed.");
        static_assert(sizeof(v2b) == sizeof(bool) * 2 && v2b.size() == 2, "Vector2B size check failed.");
    }

    void default_constructor()
    {
        constexpr vector4B v4b;
        constexpr vector3B v3b;
        constexpr vector2B v2b;

        static_assert(v4b == vector4B(false, false, false, false), "Vector4B default constructor failed.");
        static_assert(v3b == vector3B(false, false, false), "Vector3B default constructor failed.");
        static_assert(v2b == vector2B(false, false), "Vector2B default constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr vector4B v4b = vector4B(false);
        constexpr vector3B v3b = vector3B(true);
        constexpr vector2B v2b = vector2B(false);

        static_assert(v4b == vector4B(false, false, false, false), "Vector4B one arg constructor failed.");
        static_assert(v3b == vector3B(true, true, true), "Vector3B one arg constructor failed.");
        static_assert(v2b == vector2B(false, false), "Vector2B one arg constructor failed.");
    }

    void non_default_constructor()
    {
        const vector4B v4b = vector4B(false, true, false, true);
        const vector3B v3b = vector3B(false, true, false);
        const vector2B v2b = vector2B(false, true);

        TEST_ASSERT(!v4b[0] && v4b[1] && !v4b[2] && v4b[3], "Vector4B non default constructor failed.");
        TEST_ASSERT(!v3b[0] && v3b[1] && !v3b[2], "Vector3B non default constructor failed.");
        TEST_ASSERT(!v2b[0] && v2b[1], "Vector2B non default constructor failed.");
    }

    void type_cast_constructor()
    {
        constexpr vector4B v4b = vector4B(vector4I(0, -1, 0, 1));
        constexpr vector3B v3b = vector3B(vector3D(0, -1.1, 0.1));
        constexpr vector2B v2b = vector2B(vector2F(0.4f, -1.6f));

        static_assert(v4b == vector4B(false, true, false, true), "Vector4B type cast constructor failed.");
        static_assert(v3b == vector3B(false, true, true), "Vector3B type cast constructor failed.");
        static_assert(v2b == vector2B(true, true), "Vector2B type cast constructor failed.");
    }

    void pointer_constructor()
    {
        const bool data4[4] = {false, true, false, true};
        const bool data3[3] = {false, true, false};
        const bool data2[2] = {false, true};

        const vector4B v4b(data4);
        const vector3B v3b(data3);
        const vector2B v2b(data2);

        TEST_ASSERT(v4b == vector4B(false, true, false, true), "Vector4B pointer constructor failed.");
        TEST_ASSERT(v3b == vector3B(false, true, false), "Vector3B pointer constructor failed.");
        TEST_ASSERT(v2b == vector2B(false, true), "Vector2B pointer constructor failed.");
    }

    void from_vector4b_constructor()
    {
        constexpr vector4B v4b = {true, false, true, false};

        constexpr vector3B v3b = vector3B(v4b);
        constexpr vector2B v2b = vector2B(v4b);

        static_assert(v3b == vector3B(true, false, true), "Vector3B from vector4B constructor failed.");
        static_assert(v2b == vector2B(true, false), "Vector2B from vector4B constructor failed.");
    }

    void from_vector3b_constructor()
    {
        constexpr vector3B v3b = {true, false, true};

        constexpr vector4B v4b1 = vector4B(v3b);
        constexpr vector4B v4b2 = vector4B(v3b, true);
        constexpr vector4B v4b3 = vector4B(true, v3b);

        constexpr vector2B v2b = vector2B(v3b);

        static_assert(v4b1 == vector4B(true, false, true, false), "Vector4B from vector3B constructor failed.");
        static_assert(v4b2 == vector4B(true, false, true, true),
                      "Vector4B from vector3B and scalar constructor failed.");
        static_assert(v4b3 == vector4B(true, true, false, true),
                      "Vector4B from scalar and vector3B constructor failed.");

        static_assert(v2b == vector2B(true, false), "Vector2B from vector3B constructor failed.");
    }

    void from_vector2b_constructor()
    {
        constexpr vector2B v2b = {true, false};

        constexpr vector4B v4b1 = vector4B(v2b);
        constexpr vector4B v4b2 = vector4B(v2b, true, false);
        constexpr vector4B v4b3 = vector4B(true, v2b, false);
        constexpr vector4B v4b4 = vector4B(true, false, v2b);
        constexpr vector4B v4b5 = vector4B(v2b, v2b);

        constexpr vector3B v3b1 = vector3B(v2b);
        constexpr vector3B v3b2 = vector3B(v2b, true);
        constexpr vector3B v3b3 = vector3B(true, v2b);

        static_assert(v4b1 == vector4B(true, false, false, false), "Vector4B from vector2B constructor failed.");
        static_assert(v4b2 == vector4B(true, false, true, false), "Vector4B from vector2B and 2 scalars constructor failed.");
        static_assert(v4b3 == vector4B(true, true, false, false),
                      "Vector4B from scalar, vector2B and scalar constructor failed.");
        static_assert(v4b4 == vector4B(true, false, true, false), "Vector4B from 2 scalars and vector2B constructor failed.");
        static_assert(v4b5 == vector4B(true, false, true, false), "Vector4B from 2 vector2B constructor failed.");

        static_assert(v3b1 == vector3B(true, false, false), "Vector3B from vector2B constructor faileb.");
        static_assert(v3b2 == vector3B(true, false, true), "Vector3B from vector2B and scalar constructor failed.");
        static_assert(v3b3 == vector3B(true, true, false), "Vector3B from scalar and vector2B constructor failed.");
    }
};

int main()
{
    return run_tests(vector_test(), bool_vector_test());
}
