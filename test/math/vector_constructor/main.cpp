
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <common/types.hpp>
#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::int32;
using framework::uint32;

using framework::math::Vector2f;
using framework::math::Vector3f;
using framework::math::Vector4f;

using framework::math::Vector2d;
using framework::math::Vector3d;
using framework::math::Vector4d;

using framework::math::Vector2i;
using framework::math::Vector3i;
using framework::math::Vector4i;

using framework::math::Vector2u;
using framework::math::Vector3u;
using framework::math::Vector4u;

using framework::math::Vector2b;
using framework::math::Vector3b;
using framework::math::Vector4b;

using framework::math::almost_equal;

class VectorTest : public framework::unit_test::Suite
{
public:
    VectorTest()
        : Suite("VectorTest")
    {
        add_test([this]() { size_check(); }, "size_check");
        add_test([this]() { default_constructor(); }, "default_constructor");
        add_test([this]() { copy_constructor(); }, "copy_constructor");
        add_test([this]() { one_argument_constructor(); }, "one_argument_constructor");
        add_test([this]() { non_default_constructor(); }, "non_default_constructor");
        add_test([this]() { type_cast_constructor(); }, "type_cast_constructor");
        add_test([this]() { from_vector_of_bool_constructor(); }, "from_vector_of_bool_constructor");
        add_test([this]() { const_pointer_constructor(); }, "const_pointer_constructor");
        add_test([this]() { pointer_constructor(); }, "pointer_constructor");
        add_test([this]() { integer_zero_constructor(); }, "integer_zero_constructor");
        add_test([this]() { from_vector4d_constructor(); }, "from_vector4d_constructor");
        add_test([this]() { from_vector3d_constructor(); }, "from_vector3d_constructor");
        add_test([this]() { from_vector2d_constructor(); }, "from_vector2d_constructor");
    }

private:
    void size_check()
    {
        constexpr Vector4d v4d;
        constexpr Vector3f v3f;
        constexpr Vector2i v2i;

        static_assert(sizeof(v4d) == sizeof(double) * 4 && v4d.size() == 4, "Vector4d size check failed.");
        static_assert(sizeof(v3f) == sizeof(float) * 3 && v3f.size() == 3, "Vector3f size check failed.");
        static_assert(sizeof(v2i) == sizeof(int) * 2 && v2i.size() == 2, "Vector2i size check failed.");
    }

    void default_constructor()
    {
        constexpr Vector4d v4d;
        constexpr Vector3f v3f;
        constexpr Vector2i v2i;

        static_assert(v4d == Vector4d(0, 0, 0, 1), "Vector4d default constructor failed.");
        static_assert(v3f == Vector3f(0, 0, 0), "Vector3f default constructor failed.");
        static_assert(v2i == Vector2i(0, 0), "Vector2i default constructor failed.");
    }

    void copy_constructor()
    {
        constexpr Vector4d v4d;
        constexpr Vector3f v3f;
        constexpr Vector2i v2i;

        constexpr Vector4d v4d2 = v4d;
        constexpr Vector3f v3f2 = v3f;
        constexpr Vector2i v2i2 = v2i;

        static_assert(v4d == v4d2, "Vector4d copy constructor failed.");
        static_assert(v3f == v3f2, "Vector3f copy constructor failed.");
        static_assert(v2i == v2i2, "Vector2i copy constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr Vector4d v4d = Vector4d(1.4);
        constexpr Vector3f v3f = Vector3f(2.4f);
        constexpr Vector2i v2i = Vector2i(3);

        static_assert(v4d == Vector4d(1.4, 1.4, 1.4, 1.4), "Vector4d one argument constructor failed.");
        static_assert(v3f == Vector3f(2.4f, 2.4f, 2.4f), "Vector3f one argument constructor failed.");
        static_assert(v2i == Vector2i(3, 3), "Vector2i one argument constructor failed.");
    }

    void non_default_constructor()
    {
        const Vector4d v4d = {1.1, 2.2, 3.3, 4.4};
        const Vector3f v3f = {5.5f, 6.6f, 7.7f};
        const Vector2i v2i = {1, 2};

        // clang-format off
        TEST_ASSERT(almost_equal(v4d[0], 1.1) &&
                    almost_equal(v4d[1], 2.2) &&
                    almost_equal(v4d[2], 3.3) &&
                    almost_equal(v4d[3], 4.4),
                    "Vector4d non default constructor failed.");

        TEST_ASSERT(almost_equal(v3f[0], 5.5f) &&
                    almost_equal(v3f[1], 6.6f) &&
                    almost_equal(v3f[2], 7.7f),
                    "Vector3f non default constructor failed.");

        TEST_ASSERT(v2i[0] == 1 && v2i[1] == 2, "Vector2i non default constructor failed.");
        // clang-format on
    }

    void type_cast_constructor()
    {
        constexpr Vector4d v4d = {1.1, 2.2, 3.3, 4.4};
        constexpr Vector3f v3f = {5.5f, 6.6f, 7.7f};
        constexpr Vector2i v2i = {1, 2};

        constexpr Vector4i v4i = Vector4i(v4d);
        constexpr Vector3d v3d = Vector3d(v3f);
        constexpr Vector2f v2f = Vector2f(v2i);

        static_assert(v4i == Vector4i(1, 2, 3, 4), "Vector4i type cast constructor failed.");
        static_assert(v3d == Vector3d(5.5f, 6.6f, 7.7f), "Vector3d type cast constructor failed.");
        static_assert(v2f == Vector2f(1.0f, 2.0f), "Vector2f type cast constructor failed.");
    }

    void from_vector_of_bool_constructor()
    {
        constexpr Vector4b v4b = Vector4b(false, true, false, true);
        constexpr Vector3b v3b = Vector3b(false, true, false);
        constexpr Vector2b v2b = Vector2b(false, true);

        constexpr Vector4d v4d = Vector4d(v4b);
        constexpr Vector3f v3f = Vector3f(v3b);
        constexpr Vector2i v2i = Vector2i(v2b);

        static_assert(v4d == Vector4d(0.0, 1.0, 0.0, 1.0), "Vector4d from bool cast constructor failed.");
        static_assert(v3f == Vector3f(0.0f, 1.0f, 0.0f), "Vector3f from bool cast constructor failed.");
        static_assert(v2i == Vector2i(0, 1), "Vector2i from bool cast constructor failed.");
    }

    void const_pointer_constructor()
    {
        const double data_d[4] = {1.0, 2.0, 3.0, 4.0};
        const float data_f[3]  = {1.0f, 2.0f, 3.0f};
        const int32 data_i[2]  = {1, 2};
        const uint32 data_u[2] = {1, 2};

        const Vector4d v4d(data_d);
        const Vector3f v3f(data_f);
        const Vector2i v2i(data_i);
        const Vector2u v2u(data_u);

        TEST_ASSERT(v4d == Vector4d(1.0, 2.0, 3.0, 4.0), "Vector4d pointer constructor failed.");
        TEST_ASSERT(v3f == Vector3f(1.0f, 2.0f, 3.0f), "Vector3f pointer constructor failed.");
        TEST_ASSERT(v2i == Vector2i(1, 2), "Vector2i pointer constructor failed.");
        TEST_ASSERT(v2u == Vector2u(1, 2), "Vector2u pointer constructor failed.");
    }

    void pointer_constructor()
    {
        double data_d[4] = {1.0, 2.0, 3.0, 4.0};
        float data_f[3]  = {1.0f, 2.0f, 3.0f};
        int32 data_i[2]  = {1, 2};
        uint32 data_u[2] = {1, 2};

        const Vector4d v4d(data_d);
        const Vector3f v3f(data_f);
        const Vector2i v2i(data_i);
        const Vector2u v2u(data_u);

        TEST_ASSERT(v4d == Vector4d(1.0, 2.0, 3.0, 4.0), "Vector4d pointer constructor failed.");
        TEST_ASSERT(v3f == Vector3f(1.0f, 2.0f, 3.0f), "Vector3f pointer constructor failed.");
        TEST_ASSERT(v2i == Vector2i(1, 2), "Vector2i pointer constructor failed.");
        TEST_ASSERT(v2u == Vector2u(1, 2), "Vector2u pointer constructor failed.");
    }

    void integer_zero_constructor()
    {
        const Vector2i v2i_zero(0);
        const Vector2u v2u_zero(0);

        TEST_ASSERT(v2i_zero == Vector2i(0, 0), "Vector2i zero constructor failed.");
        TEST_ASSERT(v2u_zero == Vector2u(0, 0), "Vector2u zero constructor failed.");
    }

    void from_vector4d_constructor()
    {
        constexpr Vector4d v4d = {1.1, 2.2, 3.3, 4.4};

        constexpr Vector3d v3d = Vector3d(v4d);
        constexpr Vector2d v2d = Vector2d(v4d);

        static_assert(v3d == Vector3d(1.1, 2.2, 3.3), "Vector3d from Vector4d constructor failed.");
        static_assert(v2d == Vector2d(1.1, 2.2), "Vector2d from Vector4d constructor failed.");
    }

    void from_vector3d_constructor()
    {
        constexpr Vector3d v3d = {1.1, 2.2, 3.3};

        constexpr Vector4d v4d1 = Vector4d(v3d);
        constexpr Vector4d v4d2 = Vector4d(v3d, 4.4);
        constexpr Vector4d v4d3 = Vector4d(4.4, v3d);

        constexpr Vector2d v2d = Vector2d(v3d);

        static_assert(v4d1 == Vector4d(1.1, 2.2, 3.3, 1.0), "Vector4d from Vector3d constructor failed.");
        static_assert(v4d2 == Vector4d(1.1, 2.2, 3.3, 4.4), "Vector4d from Vector3d and scalar constructor failed.");
        static_assert(v4d3 == Vector4d(4.4, 1.1, 2.2, 3.3), "Vector4d from scalar and Vector3d constructor failed.");

        static_assert(v2d == Vector2d(1.1, 2.2), "Vector2d from Vector3d constructor failed.");
    }

    void from_vector2d_constructor()
    {
        constexpr Vector2d v2d = {1.1, 2.2};

        constexpr Vector4d v4d1 = Vector4d(v2d);
        constexpr Vector4d v4d2 = Vector4d(v2d, 3.3, 4.4);
        constexpr Vector4d v4d3 = Vector4d(3.3, v2d, 4.4);
        constexpr Vector4d v4d4 = Vector4d(3.3, 4.4, v2d);
        constexpr Vector4d v4d5 = Vector4d(v2d, v2d);

        constexpr Vector3d v3d1 = Vector3d(v2d);
        constexpr Vector3d v3d2 = Vector3d(v2d, 3.3);
        constexpr Vector3d v3d3 = Vector3d(3.3, v2d);

        static_assert(v4d1 == Vector4d(1.1, 2.2, 0.0, 1.0), "Vector4d from Vector2d constructor failed.");
        static_assert(v4d2 == Vector4d(1.1, 2.2, 3.3, 4.4), "Vector4d from Vector2d and 2 scalars constructor failed.");
        static_assert(v4d3 == Vector4d(3.3, 1.1, 2.2, 4.4),
                      "Vector4d from scalar, Vector2d and scalar constructor failed.");
        static_assert(v4d4 == Vector4d(3.3, 4.4, 1.1, 2.2), "Vector4d from 2 scalars and Vector2d constructor failed.");
        static_assert(v4d5 == Vector4d(1.1, 2.2, 1.1, 2.2), "Vector4d from 2 Vector2d constructor failed.");

        static_assert(v3d1 == Vector3d(1.1, 2.2, 0.0), "Vector3d from Vector2d constructor failed.");
        static_assert(v3d2 == Vector3d(1.1, 2.2, 3.3), "Vector3d from Vector2d and scalar constructor failed.");
        static_assert(v3d3 == Vector3d(3.3, 1.1, 2.2), "Vector3d from scalar and Vector2d constructor failed.");
    }
};

class BoolVectorTest : public framework::unit_test::Suite
{
public:
    BoolVectorTest()
        : Suite("BoolVectorTest")
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
        constexpr Vector4b v4b;
        constexpr Vector3b v3b;
        constexpr Vector2b v2b;

        static_assert(sizeof(v4b) == sizeof(bool) * 4 && v4b.size() == 4, "Vector4b size check failed.");
        static_assert(sizeof(v3b) == sizeof(bool) * 3 && v3b.size() == 3, "Vector3b size check failed.");
        static_assert(sizeof(v2b) == sizeof(bool) * 2 && v2b.size() == 2, "Vector2b size check failed.");
    }

    void default_constructor()
    {
        constexpr Vector4b v4b;
        constexpr Vector3b v3b;
        constexpr Vector2b v2b;

        static_assert(v4b == Vector4b(false, false, false, false), "Vector4b default constructor failed.");
        static_assert(v3b == Vector3b(false, false, false), "Vector3b default constructor failed.");
        static_assert(v2b == Vector2b(false, false), "Vector2b default constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr Vector4b v4b = Vector4b(false);
        constexpr Vector3b v3b = Vector3b(true);
        constexpr Vector2b v2b = Vector2b(false);

        static_assert(v4b == Vector4b(false, false, false, false), "Vector4b one arg constructor failed.");
        static_assert(v3b == Vector3b(true, true, true), "Vector3b one arg constructor failed.");
        static_assert(v2b == Vector2b(false, false), "Vector2b one arg constructor failed.");
    }

    void non_default_constructor()
    {
        const Vector4b v4b = Vector4b(false, true, false, true);
        const Vector3b v3b = Vector3b(false, true, false);
        const Vector2b v2b = Vector2b(false, true);

        TEST_ASSERT(!v4b[0] && v4b[1] && !v4b[2] && v4b[3], "Vector4b non default constructor failed.");
        TEST_ASSERT(!v3b[0] && v3b[1] && !v3b[2], "Vector3b non default constructor failed.");
        TEST_ASSERT(!v2b[0] && v2b[1], "Vector2b non default constructor failed.");
    }

    void type_cast_constructor()
    {
        constexpr Vector4b v4b = Vector4b(Vector4i(0, -1, 0, 1));
        constexpr Vector3b v3b = Vector3b(Vector3d(0, -1.1, 0.1));
        constexpr Vector2b v2b = Vector2b(Vector2f(0.4f, -1.6f));

        static_assert(v4b == Vector4b(false, true, false, true), "Vector4b type cast constructor failed.");
        static_assert(v3b == Vector3b(false, true, true), "Vector3b type cast constructor failed.");
        static_assert(v2b == Vector2b(true, true), "Vector2b type cast constructor failed.");
    }

    void pointer_constructor()
    {
        const bool data4[4] = {false, true, false, true};
        const bool data3[3] = {false, true, false};
        const bool data2[2] = {false, true};

        const Vector4b v4b(data4);
        const Vector3b v3b(data3);
        const Vector2b v2b(data2);

        TEST_ASSERT(v4b == Vector4b(false, true, false, true), "Vector4b pointer constructor failed.");
        TEST_ASSERT(v3b == Vector3b(false, true, false), "Vector3b pointer constructor failed.");
        TEST_ASSERT(v2b == Vector2b(false, true), "Vector2b pointer constructor failed.");
    }

    void from_vector4b_constructor()
    {
        constexpr Vector4b v4b = {true, false, true, false};

        constexpr Vector3b v3b = Vector3b(v4b);
        constexpr Vector2b v2b = Vector2b(v4b);

        static_assert(v3b == Vector3b(true, false, true), "Vector3b from Vector4b constructor failed.");
        static_assert(v2b == Vector2b(true, false), "Vector2b from Vector4b constructor failed.");
    }

    void from_vector3b_constructor()
    {
        constexpr Vector3b v3b = {true, false, true};

        constexpr Vector4b v4b1 = Vector4b(v3b);
        constexpr Vector4b v4b2 = Vector4b(v3b, true);
        constexpr Vector4b v4b3 = Vector4b(true, v3b);

        constexpr Vector2b v2b = Vector2b(v3b);

        static_assert(v4b1 == Vector4b(true, false, true, false), "Vector4b from Vector3b constructor failed.");
        static_assert(v4b2 == Vector4b(true, false, true, true),
                      "Vector4b from Vector3b and scalar constructor failed.");
        static_assert(v4b3 == Vector4b(true, true, false, true),
                      "Vector4b from scalar and Vector3b constructor failed.");

        static_assert(v2b == Vector2b(true, false), "Vector2b from Vector3b constructor failed.");
    }

    void from_vector2b_constructor()
    {
        constexpr Vector2b v2b = {true, false};

        constexpr Vector4b v4b1 = Vector4b(v2b);
        constexpr Vector4b v4b2 = Vector4b(v2b, true, false);
        constexpr Vector4b v4b3 = Vector4b(true, v2b, false);
        constexpr Vector4b v4b4 = Vector4b(true, false, v2b);
        constexpr Vector4b v4b5 = Vector4b(v2b, v2b);

        constexpr Vector3b v3b1 = Vector3b(v2b);
        constexpr Vector3b v3b2 = Vector3b(v2b, true);
        constexpr Vector3b v3b3 = Vector3b(true, v2b);

        static_assert(v4b1 == Vector4b(true, false, false, false), "Vector4b from Vector2b constructor failed.");
        static_assert(v4b2 == Vector4b(true, false, true, false),
                      "Vector4b from Vector2b and 2 scalars constructor failed.");
        static_assert(v4b3 == Vector4b(true, true, false, false),
                      "Vector4b from scalar, Vector2b and scalar constructor failed.");
        static_assert(v4b4 == Vector4b(true, false, true, false),
                      "Vector4b from 2 scalars and Vector2b constructor failed.");
        static_assert(v4b5 == Vector4b(true, false, true, false), "Vector4b from 2 Vector2b constructor failed.");

        static_assert(v3b1 == Vector3b(true, false, false), "Vector3b from Vector2b constructor failed.");
        static_assert(v3b2 == Vector3b(true, false, true), "Vector3b from Vector2b and scalar constructor failed.");
        static_assert(v3b3 == Vector3b(true, true, false), "Vector3b from scalar and Vector2b constructor failed.");
    }
};

int main()
{
    return run_tests(VectorTest(), BoolVectorTest());
}
