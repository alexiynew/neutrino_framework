
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

using framework::float32;
using framework::float64;
using framework::int32;
using framework::uint32;

using framework::math::vector2f;
using framework::math::vector3f;
using framework::math::vector4f;

using framework::math::vector2d;
using framework::math::vector3d;
using framework::math::vector4d;

using framework::math::vector2i;
using framework::math::vector3i;
using framework::math::vector4i;

using framework::math::vector2u;
using framework::math::vector3u;
using framework::math::vector4u;

using framework::math::vector2b;
using framework::math::vector3b;
using framework::math::vector4b;

using framework::math::almost_equal;

class vector_test : public framework::unit_test::Suite
{
public:
    vector_test() : Suite("vector_test")
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
        constexpr vector4d v4d;
        constexpr vector3f v3f;
        constexpr vector2i v2i;

        static_assert(sizeof(v4d) == sizeof(float64) * 4 && v4d.size() == 4, "Vector4d size check failed.");
        static_assert(sizeof(v3f) == sizeof(float32) * 3 && v3f.size() == 3, "Vector3f size check failed.");
        static_assert(sizeof(v2i) == sizeof(int) * 2 && v2i.size() == 2, "Vector2i size check failed.");
    }

    void default_constructor()
    {
        constexpr vector4d v4d;
        constexpr vector3f v3f;
        constexpr vector2i v2i;

        static_assert(v4d == vector4d(0, 0, 0, 1), "Vector4d default constructor failed.");
        static_assert(v3f == vector3f(0, 0, 0), "Vector3f default constructor failed.");
        static_assert(v2i == vector2i(0, 0), "Vector2i default constructor failed.");
    }

    void copy_constructor()
    {
        constexpr vector4d v4d;
        constexpr vector3f v3f;
        constexpr vector2i v2i;

        constexpr vector4d v4d2 = v4d;
        constexpr vector3f v3f2 = v3f;
        constexpr vector2i v2i2 = v2i;

        static_assert(v4d == v4d2, "Vector4d copy constructor failed.");
        static_assert(v3f == v3f2, "Vector3f copy constructor failed.");
        static_assert(v2i == v2i2, "Vector2i copy constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr vector4d v4d = vector4d(1.4);
        constexpr vector3f v3f = vector3f(2.4f);
        constexpr vector2i v2i = vector2i(3);

        static_assert(v4d == vector4d(1.4, 1.4, 1.4, 1.4), "Vector4d one argument constructor failed.");
        static_assert(v3f == vector3f(2.4f, 2.4f, 2.4f), "Vector3f one argument constructor failed.");
        static_assert(v2i == vector2i(3, 3), "Vector2i one argument constructor failed.");
    }

    void non_default_constructor()
    {
        const vector4d v4d = {1.1, 2.2, 3.3, 4.4};
        const vector3f v3f = {5.5f, 6.6f, 7.7f};
        const vector2i v2i = {1, 2};

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
        constexpr vector4d v4d = {1.1, 2.2, 3.3, 4.4};
        constexpr vector3f v3f = {5.5f, 6.6f, 7.7f};
        constexpr vector2i v2i = {1, 2};

        constexpr vector4i v4i = vector4i(v4d);
        constexpr vector3d v3d = vector3d(v3f);
        constexpr vector2f v2f = vector2f(v2i);

        static_assert(v4i == vector4i(1, 2, 3, 4), "Vector4i type cast constructor failed.");
        static_assert(v3d == vector3d(5.5f, 6.6f, 7.7f), "Vector3d type cast constructor failed.");
        static_assert(v2f == vector2f(1.0f, 2.0f), "Vector2f type cast constructor failed.");
    }

    void from_vector_of_bool_constructor()
    {
        constexpr vector4b v4b = vector4b(false, true, false, true);
        constexpr vector3b v3b = vector3b(false, true, false);
        constexpr vector2b v2b = vector2b(false, true);

        constexpr vector4d v4d = vector4d(v4b);
        constexpr vector3f v3f = vector3f(v3b);
        constexpr vector2i v2i = vector2i(v2b);

        static_assert(v4d == vector4d(0.0, 1.0, 0.0, 1.0), "Vector4d from bool cast constructor failed.");
        static_assert(v3f == vector3f(0.0f, 1.0f, 0.0f), "Vector3f from bool cast constructor failed.");
        static_assert(v2i == vector2i(0, 1), "Vector2i from bool cast constructor failed.");
    }

    void const_pointer_constructor()
    {
        const float64 data_d[4] = {1.0, 2.0, 3.0, 4.0};
        const float32 data_f[3] = {1.0f, 2.0f, 3.0f};
        const int32 data_i[2]   = {1, 2};
        const uint32 data_u[2]  = {1, 2};

        const vector4d v4d(data_d);
        const vector3f v3f(data_f);
        const vector2i v2i(data_i);
        const vector2u v2u(data_u);

        TEST_ASSERT(v4d == vector4d(1.0, 2.0, 3.0, 4.0), "Vector4d pointer constructor failed.");
        TEST_ASSERT(v3f == vector3f(1.0f, 2.0f, 3.0f), "Vector3f pointer constructor failed.");
        TEST_ASSERT(v2i == vector2i(1, 2), "Vector2i pointer constructor failed.");
        TEST_ASSERT(v2u == vector2u(1, 2), "Vector2u pointer constructor failed.");
    }

    void pointer_constructor()
    {
        float64 data_d[4] = {1.0, 2.0, 3.0, 4.0};
        float32 data_f[3] = {1.0f, 2.0f, 3.0f};
        int32 data_i[2]   = {1, 2};
        uint32 data_u[2]  = {1, 2};

        const vector4d v4d(data_d);
        const vector3f v3f(data_f);
        const vector2i v2i(data_i);
        const vector2u v2u(data_u);

        TEST_ASSERT(v4d == vector4d(1.0, 2.0, 3.0, 4.0), "Vector4d pointer constructor failed.");
        TEST_ASSERT(v3f == vector3f(1.0f, 2.0f, 3.0f), "Vector3f pointer constructor failed.");
        TEST_ASSERT(v2i == vector2i(1, 2), "Vector2i pointer constructor failed.");
        TEST_ASSERT(v2u == vector2u(1, 2), "Vector2u pointer constructor failed.");
    }

    void integer_zero_constructor()
    {
        const vector2i v2i_zero(0);
        const vector2u v2u_zero(0);

        TEST_ASSERT(v2i_zero == vector2i(0, 0), "Vector2i zero constructor failed.");
        TEST_ASSERT(v2u_zero == vector2u(0, 0), "Vector2u zero constructor failed.");
    }

    void from_vector4d_constructor()
    {
        constexpr vector4d v4d = {1.1, 2.2, 3.3, 4.4};

        constexpr vector3d v3d = vector3d(v4d);
        constexpr vector2d v2d = vector2d(v4d);

        static_assert(v3d == vector3d(1.1, 2.2, 3.3), "Vector3d from vector4d constructor failed.");
        static_assert(v2d == vector2d(1.1, 2.2), "Vector2d from vector4d constructor failed.");
    }

    void from_vector3d_constructor()
    {
        constexpr vector3d v3d = {1.1, 2.2, 3.3};

        constexpr vector4d v4d1 = vector4d(v3d);
        constexpr vector4d v4d2 = vector4d(v3d, 4.4);
        constexpr vector4d v4d3 = vector4d(4.4, v3d);

        constexpr vector2d v2d = vector2d(v3d);

        static_assert(v4d1 == vector4d(1.1, 2.2, 3.3, 1.0), "Vector4d from vector3d constructor failed.");
        static_assert(v4d2 == vector4d(1.1, 2.2, 3.3, 4.4), "Vector4d from vector3d and scalar constructor failed.");
        static_assert(v4d3 == vector4d(4.4, 1.1, 2.2, 3.3), "Vector4d from scalar and vector3d constructor failed.");

        static_assert(v2d == vector2d(1.1, 2.2), "Vector2d from vector3d constructor failed.");
    }

    void from_vector2d_constructor()
    {
        constexpr vector2d v2d = {1.1, 2.2};

        constexpr vector4d v4d1 = vector4d(v2d);
        constexpr vector4d v4d2 = vector4d(v2d, 3.3, 4.4);
        constexpr vector4d v4d3 = vector4d(3.3, v2d, 4.4);
        constexpr vector4d v4d4 = vector4d(3.3, 4.4, v2d);
        constexpr vector4d v4d5 = vector4d(v2d, v2d);

        constexpr vector3d v3d1 = vector3d(v2d);
        constexpr vector3d v3d2 = vector3d(v2d, 3.3);
        constexpr vector3d v3d3 = vector3d(3.3, v2d);

        static_assert(v4d1 == vector4d(1.1, 2.2, 0.0, 1.0), "Vector4d from vector2d constructor failed.");
        static_assert(v4d2 == vector4d(1.1, 2.2, 3.3, 4.4), "Vector4d from vector2d and 2 scalars constructor failed.");
        static_assert(v4d3 == vector4d(3.3, 1.1, 2.2, 4.4),
                      "Vector4d from scalar, vector2d and scalar constructor failed.");
        static_assert(v4d4 == vector4d(3.3, 4.4, 1.1, 2.2), "Vector4d from 2 scalars and vector2d constructor failed.");
        static_assert(v4d5 == vector4d(1.1, 2.2, 1.1, 2.2), "Vector4d from 2 vector2d constructor failed.");

        static_assert(v3d1 == vector3d(1.1, 2.2, 0.0), "Vector3d from vector2d constructor failed.");
        static_assert(v3d2 == vector3d(1.1, 2.2, 3.3), "Vector3d from vector2d and scalar constructor failed.");
        static_assert(v3d3 == vector3d(3.3, 1.1, 2.2), "Vector3d from scalar and vector2d constructor failed.");
    }
};

class bool_vector_test : public framework::unit_test::Suite
{
public:
    bool_vector_test() : Suite("bool_vector_test")
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
        constexpr vector4b v4b;
        constexpr vector3b v3b;
        constexpr vector2b v2b;

        static_assert(sizeof(v4b) == sizeof(bool) * 4 && v4b.size() == 4, "Vector4b size check failed.");
        static_assert(sizeof(v3b) == sizeof(bool) * 3 && v3b.size() == 3, "Vector3b size check failed.");
        static_assert(sizeof(v2b) == sizeof(bool) * 2 && v2b.size() == 2, "Vector2b size check failed.");
    }

    void default_constructor()
    {
        constexpr vector4b v4b;
        constexpr vector3b v3b;
        constexpr vector2b v2b;

        static_assert(v4b == vector4b(false, false, false, false), "Vector4b default constructor failed.");
        static_assert(v3b == vector3b(false, false, false), "Vector3b default constructor failed.");
        static_assert(v2b == vector2b(false, false), "Vector2b default constructor failed.");
    }

    void one_argument_constructor()
    {
        constexpr vector4b v4b = vector4b(false);
        constexpr vector3b v3b = vector3b(true);
        constexpr vector2b v2b = vector2b(false);

        static_assert(v4b == vector4b(false, false, false, false), "Vector4b one arg constructor failed.");
        static_assert(v3b == vector3b(true, true, true), "Vector3b one arg constructor failed.");
        static_assert(v2b == vector2b(false, false), "Vector2b one arg constructor failed.");
    }

    void non_default_constructor()
    {
        const vector4b v4b = vector4b(false, true, false, true);
        const vector3b v3b = vector3b(false, true, false);
        const vector2b v2b = vector2b(false, true);

        TEST_ASSERT(!v4b[0] && v4b[1] && !v4b[2] && v4b[3], "Vector4b non default constructor failed.");
        TEST_ASSERT(!v3b[0] && v3b[1] && !v3b[2], "Vector3b non default constructor failed.");
        TEST_ASSERT(!v2b[0] && v2b[1], "Vector2b non default constructor failed.");
    }

    void type_cast_constructor()
    {
        constexpr vector4b v4b = vector4b(vector4i(0, -1, 0, 1));
        constexpr vector3b v3b = vector3b(vector3d(0, -1.1, 0.1));
        constexpr vector2b v2b = vector2b(vector2f(0.4f, -1.6f));

        static_assert(v4b == vector4b(false, true, false, true), "Vector4b type cast constructor failed.");
        static_assert(v3b == vector3b(false, true, true), "Vector3b type cast constructor failed.");
        static_assert(v2b == vector2b(true, true), "Vector2b type cast constructor failed.");
    }

    void pointer_constructor()
    {
        const bool data4[4] = {false, true, false, true};
        const bool data3[3] = {false, true, false};
        const bool data2[2] = {false, true};

        const vector4b v4b(data4);
        const vector3b v3b(data3);
        const vector2b v2b(data2);

        TEST_ASSERT(v4b == vector4b(false, true, false, true), "Vector4b pointer constructor failed.");
        TEST_ASSERT(v3b == vector3b(false, true, false), "Vector3b pointer constructor failed.");
        TEST_ASSERT(v2b == vector2b(false, true), "Vector2b pointer constructor failed.");
    }

    void from_vector4b_constructor()
    {
        constexpr vector4b v4b = {true, false, true, false};

        constexpr vector3b v3b = vector3b(v4b);
        constexpr vector2b v2b = vector2b(v4b);

        static_assert(v3b == vector3b(true, false, true), "Vector3b from vector4b constructor failed.");
        static_assert(v2b == vector2b(true, false), "Vector2b from vector4b constructor failed.");
    }

    void from_vector3b_constructor()
    {
        constexpr vector3b v3b = {true, false, true};

        constexpr vector4b v4b1 = vector4b(v3b);
        constexpr vector4b v4b2 = vector4b(v3b, true);
        constexpr vector4b v4b3 = vector4b(true, v3b);

        constexpr vector2b v2b = vector2b(v3b);

        static_assert(v4b1 == vector4b(true, false, true, false), "Vector4b from vector3b constructor failed.");
        static_assert(v4b2 == vector4b(true, false, true, true),
                      "Vector4b from vector3b and scalar constructor failed.");
        static_assert(v4b3 == vector4b(true, true, false, true),
                      "Vector4b from scalar and vector3b constructor failed.");

        static_assert(v2b == vector2b(true, false), "Vector2b from vector3b constructor failed.");
    }

    void from_vector2b_constructor()
    {
        constexpr vector2b v2b = {true, false};

        constexpr vector4b v4b1 = vector4b(v2b);
        constexpr vector4b v4b2 = vector4b(v2b, true, false);
        constexpr vector4b v4b3 = vector4b(true, v2b, false);
        constexpr vector4b v4b4 = vector4b(true, false, v2b);
        constexpr vector4b v4b5 = vector4b(v2b, v2b);

        constexpr vector3b v3b1 = vector3b(v2b);
        constexpr vector3b v3b2 = vector3b(v2b, true);
        constexpr vector3b v3b3 = vector3b(true, v2b);

        static_assert(v4b1 == vector4b(true, false, false, false), "Vector4b from vector2b constructor failed.");
        static_assert(v4b2 == vector4b(true, false, true, false),
                      "Vector4b from vector2b and 2 scalars constructor failed.");
        static_assert(v4b3 == vector4b(true, true, false, false),
                      "Vector4b from scalar, vector2b and scalar constructor failed.");
        static_assert(v4b4 == vector4b(true, false, true, false),
                      "Vector4b from 2 scalars and vector2b constructor failed.");
        static_assert(v4b5 == vector4b(true, false, true, false), "Vector4b from 2 vector2b constructor failed.");

        static_assert(v3b1 == vector3b(true, false, false), "Vector3b from vector2b constructor failed.");
        static_assert(v3b2 == vector3b(true, false, true), "Vector3b from vector2b and scalar constructor failed.");
        static_assert(v3b3 == vector3b(true, true, false), "Vector3b from scalar and vector2b constructor failed.");
    }
};

int main()
{
    return run_tests(vector_test(), bool_vector_test());
}
