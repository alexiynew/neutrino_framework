// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::int32;

using framework::math::Vector2b;
using framework::math::Vector2f;
using framework::math::Vector2i;
using framework::math::Vector2u;
using framework::math::Vector3b;
using framework::math::Vector3d;
using framework::math::Vector3f;
using framework::math::Vector4b;
using framework::math::Vector4d;
using framework::math::Vector4i;

using framework::math::almost_equal;

class VectorOperatorsTest : public framework::unit_test::Suite
{
public:
    VectorOperatorsTest()
        : Suite("VectorOperatorsTest")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
        add_test([this]() { access_operator(); }, "access_operator");
        add_test([this]() { data_function(); }, "data_function");
        add_test([this]() { unary_minus_operator(); }, "unary_minus_operator");
        add_test([this]() { unary_plus_operator(); }, "unary_plus_operator");
        add_test([this]() { add_assign_operator(); }, "add_assign_operator");
        add_test([this]() { subtract_assign_operator(); }, "subtract_assign_operator");
        add_test([this]() { multiplies_assign_operator(); }, "multiplies_assign_operator");
        add_test([this]() { divides_assign_operator(); }, "divides_assign_operator");
        add_test([this]() { add_operator(); }, "add_operator");
        add_test([this]() { subtract_operator(); }, "subtract_operator");
        add_test([this]() { multiply_operator(); }, "multiply_operator");
        add_test([this]() { divide_operator(); }, "divide_operator");
        add_test([this]() { equality_operator(); }, "equality_operator");
        add_test([this]() { inequality_operator(); }, "inequality_operator");
    }

private:
    void assign_operator()
    {
        const Vector4d v4d(1.1, 2.2, 3.3, 4);
        const Vector3f v3f(5.5f, 6.6f, 7.7f);
        const Vector2i v2i(1, 2);

        Vector4d v4d_result;
        Vector3f v3f_result;
        Vector2i v2i_result;

        Vector4i v4i_result;
        Vector3d v3d_result;
        Vector2f v2f_result;

        v4d_result = v4d;
        v3f_result = v3f;
        v2i_result = v2i;

        v4i_result = static_cast<Vector4i>(v4d);
        v3d_result = static_cast<Vector3d>(v3f);
        v2f_result = static_cast<Vector2f>(v2i);

        TEST_ASSERT(v4i_result == Vector4i(1, 2, 3, 4), "Assign to Vector4i failed.");
        TEST_ASSERT(v4d_result == Vector4d(1.1, 2.2, 3.3, 4), "Assign to Vector4d failed.");

        TEST_ASSERT(v3d_result == Vector3d(double(5.5f), double(6.6f), double(7.7f)), "Assign to Vector3d failed.");
        TEST_ASSERT(v3f_result == Vector3f(5.5f, 6.6f, 7.7f), "Assign to Vector3f failed.");

        TEST_ASSERT(v2f_result == Vector2f(1, 2), "Assign to Vector2f failed.");
        TEST_ASSERT(v2i_result == Vector2i(1, 2), "Assign to Vector2i failed.");
    }

    void access_operator()
    {
        const Vector4d v4d(1.1, 2.2, 3.3, 4.4);
        const Vector3f v3f(5.5f, 6.6f, 7.7f);
        const Vector2i v2i(1, 2);

        // clang-format off
        TEST_ASSERT(almost_equal(v4d[0], 1.1) &&
                    almost_equal(v4d[1], 2.2) &&
                    almost_equal(v4d[2], 3.3) &&
                    almost_equal(v4d[3], 4.4),
                    "Access to Vector4d filed.");

        TEST_ASSERT(almost_equal(v3f[0], 5.5f) &&
                    almost_equal(v3f[1], 6.6f) &&
                    almost_equal(v3f[2], 7.7f),
                    "Access to Vector3f failed.");

        TEST_ASSERT(v2i[0] == 1 && v2i[1] == 2, "Access to Vector2i failed.");
        // clang-format on
    }

    void data_function()
    {
        const Vector4d v4d(1.1, 2.2, 3.3, 4.4);
        const Vector3f v3f(5.5f, 6.6f, 7.7f);
        const Vector2i v2i(1, 2);

        const double* double_pointer = v4d.data();
        const float* float_pointer   = v3f.data();
        const int32* int_pointer     = v2i.data();

        // clang-format off
        TEST_ASSERT(almost_equal(double_pointer[0], 1.1) &&
                    almost_equal(double_pointer[1], 2.2) &&
                    almost_equal(double_pointer[2], 3.3) &&
                    almost_equal(double_pointer[3], 4.4),
                    "Access to data of Vector4d filed.");

        TEST_ASSERT(almost_equal(float_pointer[0], 5.5f) &&
                    almost_equal(float_pointer[1], 6.6f) &&
                    almost_equal(float_pointer[2], 7.7f),
                    "Access to data of Vector3f failed.");

        TEST_ASSERT(int_pointer[0] == 1 && int_pointer[1] == 2, "Access to data of Vector2i failed.");
        // clang-format on
    }

    void unary_minus_operator()
    {
        const Vector4d v4d(1.4);
        const Vector3f v3f(2.4f);
        const Vector2i v2i(3);

        TEST_ASSERT(-v4d == Vector4d(-1.4, -1.4, -1.4, -1.4), "Inverse of Vector4d failed.");
        TEST_ASSERT(-v3f == Vector3f(-2.4f, -2.4f, -2.4f), "Inverse of Vector3f failed.");
        TEST_ASSERT(-v2i == Vector2i(-3, -3), "Inverse of Vector2i failed.");
    }

    void unary_plus_operator()
    {
        const Vector4d v4d(1.4);
        const Vector3f v3f(2.4f);
        const Vector2i v2i(3);

        TEST_ASSERT(+v4d == Vector4d(1.4, 1.4, 1.4, 1.4), "Unary add of Vector4d failed.");
        TEST_ASSERT(+v3f == Vector3f(2.4f, 2.4f, 2.4f), "Unary add of Vector3f failed.");
        TEST_ASSERT(+v2i == Vector2i(3, 3), "Unary add of Vector2i failed.");
    }

    void add_assign_operator()
    {
        Vector4d v4d(1.0);
        Vector3f v3f(1.0f);
        Vector2i v2i(1);

        v4d += Vector4d(1.0);
        TEST_ASSERT(v4d == Vector4d(2.0), "Add_assign operator failed.");

        v4d += 1.0;
        TEST_ASSERT(v4d == Vector4d(3.0), "Add_assign operator failed.");

        v3f += Vector3f(1.0f);
        TEST_ASSERT(v3f == Vector3f(2.0f), "Add_assign operator failed.");

        v3f += 1.0f;
        TEST_ASSERT(v3f == Vector3f(3.0f), "Add_assign operator failed.");

        v2i += Vector2i(1);
        TEST_ASSERT(v2i == Vector2i(2), "Add_assign operator failed.");

        v2i += 1;
        TEST_ASSERT(v2i == Vector2i(3), "Add_assign operator failed.");
    }

    void subtract_assign_operator()
    {
        Vector4d v4d(3.0);
        Vector3f v3f(3.0f);
        Vector2i v2i(3);

        v4d -= Vector4d(1.0);
        TEST_ASSERT(v4d == Vector4d(2.0), "Subtract_assign operator failed.");

        v4d -= 1.0;
        TEST_ASSERT(v4d == Vector4d(1.0), "Subtract_assign operator failed.");

        v3f -= Vector3f(1.0f);
        TEST_ASSERT(v3f == Vector3f(2.0f), "Subtract_assign operator failed.");

        v3f -= 1.0f;
        TEST_ASSERT(v3f == Vector3f(1.0f), "Subtract_assign operator failed.");

        v2i -= Vector2i(1);
        TEST_ASSERT(v2i == Vector2i(2), "Subtract_assign operator failed.");

        v2i -= 1;
        TEST_ASSERT(v2i == Vector2i(1), "Subtract_assign operator failed.");
    }

    void multiplies_assign_operator()
    {
        Vector4d v4d(1.0);
        Vector3f v3f(1.0f);
        Vector2i v2i(1);

        v4d *= Vector4d(2.0);
        TEST_ASSERT(v4d == Vector4d(2.0), "Multiplies_assign operator failed.");

        v4d *= 2.0;
        TEST_ASSERT(v4d == Vector4d(4.0), "Multiplies_assign operator failed.");

        v3f *= Vector3f(2.0f);
        TEST_ASSERT(v3f == Vector3f(2.0f), "Multiplies_assign operator failed.");

        v3f *= 2.0f;
        TEST_ASSERT(v3f == Vector3f(4.0f), "Multiplies_assign operator failed.");

        v2i *= Vector2i(2);
        TEST_ASSERT(v2i == Vector2i(2), "Multiplies_assign operator failed.");

        v2i *= 2;
        TEST_ASSERT(v2i == Vector2i(4), "Multiplies_assign operator failed.");
    }

    void divides_assign_operator()
    {
        Vector4d v4d(4.0);
        Vector3f v3f(4.0f);
        Vector2i v2i(4);

        v4d /= Vector4d(2.0);
        TEST_ASSERT(v4d == Vector4d(2.0), "Divides_assign operator failed.");

        v4d /= 2.0;
        TEST_ASSERT(v4d == Vector4d(1.0), "Divides_assign operator failed.");

        v3f /= Vector3f(2.0f);
        TEST_ASSERT(v3f == Vector3f(2.0f), "Divides_assign operator failed.");

        v3f /= 2.0f;
        TEST_ASSERT(v3f == Vector3f(1.0f), "Divides_assign operator failed.");

        v2i /= Vector2i(2);
        TEST_ASSERT(v2i == Vector2i(2), "Divides_assign operator failed.");

        v2i /= 2;
        TEST_ASSERT(v2i == Vector2i(1), "Divides_assign operator failed.");
    }

    void add_operator()
    {
        const Vector4d v4d(1.0);
        const Vector3f v3f(1.0f);
        const Vector2i v2i(1);

        TEST_ASSERT(v4d + v4d == Vector4d(2.0), "Add operator failed.");
        TEST_ASSERT(v4d + 1.0 == Vector4d(2.0), "Add operator failed.");
        TEST_ASSERT(1.0 + v4d == Vector4d(2.0), "Add operator failed.");

        TEST_ASSERT(v3f + v3f == Vector3f(2.0f), "Add operator failed.");
        TEST_ASSERT(v3f + 1.0f == Vector3f(2.0f), "Add operator failed.");
        TEST_ASSERT(1.0f + v3f == Vector3f(2.0f), "Add operator failed.");

        TEST_ASSERT(v2i + v2i == Vector2i(2), "Add operator failed.");
        TEST_ASSERT(v2i + 1 == Vector2i(2), "Add operator failed.");
        TEST_ASSERT(1 + v2i == Vector2i(2), "Add operator failed.");
    }

    void subtract_operator()
    {
        const Vector4d v4d(1.0);
        const Vector3f v3f(1.0f);
        const Vector2i v2i(1);

        TEST_ASSERT(v4d - v4d == Vector4d(0.0), "Subtract operator failed.");
        TEST_ASSERT(v4d - 1.0 == Vector4d(0.0), "Subtract operator failed.");
        TEST_ASSERT(1.0 - v4d == Vector4d(0.0), "Subtract operator failed.");

        TEST_ASSERT(v3f - v3f == Vector3f(0.0f), "Subtract operator failed.");
        TEST_ASSERT(v3f - 1.0f == Vector3f(0.0f), "Subtract operator failed.");
        TEST_ASSERT(1.0f - v3f == Vector3f(0.0f), "Subtract operator failed.");

        TEST_ASSERT(v2i - v2i == Vector2i(0), "Subtract operator failed.");
        TEST_ASSERT(v2i - 1 == Vector2i(0), "Subtract operator failed.");
        TEST_ASSERT(1 - v2i == Vector2i(0), "Subtract operator failed.");
    }

    void multiply_operator()
    {
        const Vector4d v4d(2.0);
        const Vector3f v3f(2.0f);
        const Vector2i v2i(2);

        TEST_ASSERT(v4d * v4d == Vector4d(4.0), "Multiply operator failed.");
        TEST_ASSERT(v4d * 2.0 == Vector4d(4.0), "Multiply operator failed.");
        TEST_ASSERT(2.0 * v4d == Vector4d(4.0), "Multiply operator failed.");

        TEST_ASSERT(v3f * v3f == Vector3f(4.0f), "Multiply operator failed.");
        TEST_ASSERT(v3f * 2.0f == Vector3f(4.0f), "Multiply operator failed.");
        TEST_ASSERT(2.0f * v3f == Vector3f(4.0f), "Multiply operator failed.");

        TEST_ASSERT(v2i * v2i == Vector2i(4), "Multiply operator failed.");
        TEST_ASSERT(v2i * 2 == Vector2i(4), "Multiply operator failed.");
        TEST_ASSERT(2 * v2i == Vector2i(4), "Multiply operator failed.");
    }

    void divide_operator()
    {
        const Vector4d v4d(2.0);
        const Vector3f v3f(2.0f);
        const Vector2i v2i(2);

        TEST_ASSERT(v4d / v4d == Vector4d(1.0), "Divide operator failed.");
        TEST_ASSERT(v4d / 2.0 == Vector4d(1.0), "Divide operator failed.");
        TEST_ASSERT(2.0 / v4d == Vector4d(1.0), "Divide operator failed.");

        TEST_ASSERT(v3f / v3f == Vector3f(1.0f), "Divide operator failed.");
        TEST_ASSERT(v3f / 2.0f == Vector3f(1.0f), "Divide operator failed.");
        TEST_ASSERT(2.0f / v3f == Vector3f(1.0f), "Divide operator failed.");

        TEST_ASSERT(v2i / v2i == Vector2i(1), "Divide operator failed.");
        TEST_ASSERT(v2i / 2 == Vector2i(1), "Divide operator failed.");
        TEST_ASSERT(2 / v2i == Vector2i(1), "Divide operator failed.");
    }

    void equality_operator()
    {
        const Vector4d v4d(1.1, 2.2, 3.3, 4);
        const Vector3f v3f(5.5f, 6.6f, 7.7f);
        const Vector2i v2i(1, -2);
        const Vector2u v2u(1, 2);

        TEST_ASSERT(v4d == v4d, "Equality operator for Vector4d failed.");
        TEST_ASSERT(v3f == v3f, "Equality operator for Vector3f failed.");
        TEST_ASSERT(v2i == v2i, "Equality operator for Vector2i failed.");
        TEST_ASSERT(v2u == v2u, "Equality operator for Vector2u failed.");
    }

    void inequality_operator()
    {
        const Vector4d v4d(1.1, 2.2, 3.3, 4);
        const Vector3f v3f(5.5f, 6.6f, 7.7f);
        const Vector2i v2i(1, -2);
        const Vector2u v2u(1, 2);

        TEST_ASSERT(Vector4d(1.1, 2.2, 3.3, 4.4) != v4d, "Inequality operator for Vector4d failed.");
        TEST_ASSERT(!(Vector3f(5.5f, 6.6f, 7.7f) != v3f), "Inequality operator for Vector3f failed.");
        TEST_ASSERT(Vector2i(-2, 1) != v2i, "Inequality operator for Vector2i failed.");
        TEST_ASSERT(!(Vector2u(1, 2) != v2u), "Inequality operator for Vector2u failed.");
    }
};

class BoolVectorOperatorsTest : public framework::unit_test::Suite
{
public:
    BoolVectorOperatorsTest()
        : Suite("BoolVectorOperatorsTest")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
        add_test([this]() { access_operator(); }, "access_operator");
        add_test([this]() { data_access(); }, "data_access");
    }

private:
    void assign_operator()
    {
        const Vector4b v4b(true, false, true, false);
        const Vector3b v3b(true, false, true);
        const Vector2b v2b(true, false);

        const Vector4d v4d(-1.1, 0.0, 3.3, 0.0);
        const Vector3f v3f(5.5f, 0.0, -7.7f);
        const Vector2i v2i(1, 0);

        Vector4b v4b_result;
        Vector3b v3b_result;
        Vector2b v2b_result;

        v4b_result = v4b;
        v3b_result = v3b;
        v2b_result = v2b;

        TEST_ASSERT(v4b_result == v4b, "Assign to Vector4b failed.");
        TEST_ASSERT(v3b_result == v3b, "Assign to Vector3b failed.");
        TEST_ASSERT(v2b_result == v2b, "Assign to Vector2b failed.");

        v4b_result = static_cast<Vector4b>(v4d);
        v3b_result = static_cast<Vector3b>(v3f);
        v2b_result = static_cast<Vector2b>(v2i);

        TEST_ASSERT(v4b_result == v4b, "Assign to Vector4b failed.");
        TEST_ASSERT(v3b_result == v3b, "Assign to Vector3b failed.");
        TEST_ASSERT(v2b_result == v2b, "Assign to Vector2b failed.");
    }

    void access_operator()
    {
        const Vector4b v4b(true, false, true, false);
        const Vector3b v3b(true, false, true);
        const Vector2b v2b(true, false);

        TEST_ASSERT(v4b[0] && !v4b[1] && v4b[2] && !v4b[3], "Access to Vector4b failed.");
        TEST_ASSERT(v3b[0] && !v3b[1] && v3b[2], "Access to Vector3b failed.");
        TEST_ASSERT(v2b[0] && !v2b[1], "Access to Vector2b failed.");
    }

    void data_access()
    {
        const Vector4b v4b(true, false, true, false);
        const Vector3b v3b(true, false, true);
        const Vector2b v2b(true, false);

        const bool* bool4 = v4b.data();
        const bool* bool3 = v3b.data();
        const bool* bool2 = v2b.data();

        TEST_ASSERT(bool4[0] && !bool4[1] && bool4[2] && !bool4[3], "Access to data of Vector4b failed.");
        TEST_ASSERT(bool3[0] && !bool3[1] && bool3[2], "Access to data of Vector3b failed.");
        TEST_ASSERT(bool2[0] && !bool2[1], "Access to data of Vector2b failed.");
    }
};

int main()
{
    return run_tests(VectorOperatorsTest(), BoolVectorOperatorsTest());
}
