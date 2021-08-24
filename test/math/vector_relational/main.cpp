
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

using framework::math::Vector2b;
using framework::math::Vector2f;
using framework::math::Vector2i;
using framework::math::Vector2u;
using framework::math::Vector3b;
using framework::math::Vector3d;
using framework::math::Vector3f;
using framework::math::Vector3i;
using framework::math::Vector4b;
using framework::math::Vector4d;
using framework::math::Vector4i;

using framework::math::Matrix2x2f;
using framework::math::Matrix2x3f;
using framework::math::Matrix2x4f;
using framework::math::Matrix3x2f;
using framework::math::Matrix3x3f;
using framework::math::Matrix3x4f;
using framework::math::Matrix4x2f;
using framework::math::Matrix4x3f;
using framework::math::Matrix4x4f;

class RelationalFunctionsTest : public framework::unit_test::Suite
{
public:
    RelationalFunctionsTest()
        : Suite("RelationalFunctionsTest")
    {
        add_test([this]() { less_function(); }, "less_function");
        add_test([this]() { less_equal_function(); }, "less_equal_function");
        add_test([this]() { greater_function(); }, "greater_function");
        add_test([this]() { greater_equal_function(); }, "greater_equal_function");
        add_test([this]() { equal_function(); }, "equal_function");
        add_test([this]() { not_equal_function(); }, "not_equal_function");
        add_test([this]() { almost_equal_function(); }, "almost_equal_function");
        add_test([this]() { almost_equal_matrix_function(); }, "almost_equal_matrix_function");
        add_test([this]() { logical_not_function(); }, "logical_not_function");
        add_test([this]() { logical_and_function(); }, "logical_and_function");
        add_test([this]() { logical_or_function(); }, "logical_or_function");
        add_test([this]() { all_function(); }, "all_function");
        add_test([this]() { any_function(); }, "any_function");

        v2i1 = {1, 5};
        v2i2 = {2, 5};
    }

private:
    void less_function()
    {
        TEST_ASSERT(less(v2i1, v2i2) == Vector2b(true, false), "Less function failed.");
        TEST_ASSERT(less(v2i2, v2i1) == Vector2b(false, false), "Less function failed.");
    }

    void less_equal_function()
    {
        TEST_ASSERT(less_equal(v2i1, v2i2) == Vector2b(true, true), "Less_equal function failed.");
        TEST_ASSERT(less_equal(v2i2, v2i1) == Vector2b(false, true), "Less_equal function failed.");
    }

    void greater_function()
    {
        TEST_ASSERT(greater(v2i1, v2i2) == Vector2b(false, false), "Greater function failed.");
        TEST_ASSERT(greater(v2i2, v2i1) == Vector2b(true, false), "Greater function failed.");
    }

    void greater_equal_function()
    {
        TEST_ASSERT(greater_equal(v2i1, v2i2) == Vector2b(false, true), "Greater_equal function failed.");
        TEST_ASSERT(greater_equal(v2i2, v2i1) == Vector2b(true, true), "Greater_equal function failed.");
    }

    void equal_function()
    {
        TEST_ASSERT(equal(v2i1, v2i2) == Vector2b(false, true), "Equal function failed.");
    }

    void not_equal_function()
    {
        TEST_ASSERT(not_equal(v2i2, v2i1) == Vector2b(true, false), "Not_equal function failed.");
    }

    void almost_equal_function()
    {
        const Vector4d v4d = {1.1, -1.5, 0.0, -1.8};
        const Vector3f v3f = {1.6f, -1.5f, 0.0f};
        const Vector3i v3i = {1, -5, 0};
        const Vector2u v2u = {10, 0};

        TEST_ASSERT(almost_equal(v4d, Vector4d(1.1, -1.5, 0.0, -1.8)), "Almost_equal function failed.");
        TEST_ASSERT(almost_equal(v3f, Vector3f(1.6f, -1.5f, 0.0f)), "Almost_equal function failed.");
        TEST_ASSERT(almost_equal(v3i, Vector3i(1, -5, 0)), "Almost_equal function failed.");
        TEST_ASSERT(almost_equal(v2u, Vector2u(10, 0)), "Almost_equal function failed.");
    }

    void almost_equal_matrix_function()
    {
        // clang-format off
        const Matrix4x4f m44f = {
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        };

        const Matrix4x3f m43f = {
            1, 2, 3, 3,
            1, 2, 2, 3,
            1, 1, 2, 3
        };

        const Matrix4x2f m42f = {
            1, 2, 2, 1,
            1, 2, 2, 1
        };

        const Matrix3x4f m34f = {
            1, 2, 3,
            4, 4, 1,
            2, 3, 3,
            4, 1, 2
        };

        const Matrix3x3f m33f = {
            1, 2, 3,
            3, 1, 2,
            2, 3, 1
        };

        const Matrix3x2f m32f = {
            1, 2, 2,
            1, 1, 2};

        const Matrix2x4f m24f = {
            1, 2,
            3, 4,
            4, 1,
            2, 3
        };

        const Matrix2x3f m23f = {
            1, 2,
            3, 4,
            1, 2
        };

        const Matrix2x2f m22f = {
            1, 2,
            4, 1
        };

        TEST_ASSERT(almost_equal(m44f, Matrix4x4f{
            1, 2, 3, 4,
            4, 1, 2, 3,
            3, 4, 1, 2,
            2, 3, 4, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m43f, Matrix4x3f{
            1, 2, 3, 3,
            1, 2, 2, 3,
            1, 1, 2, 3
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m42f, Matrix4x2f{
            1, 2, 2, 1,
            1, 2, 2, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m34f, Matrix3x4f{
            1, 2, 3,
            4, 4, 1,
            2, 3, 3,
            4, 1, 2
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m33f, Matrix3x3f{
            1, 2, 3,
            3, 1, 2,
            2, 3, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m32f, Matrix3x2f{
            1, 2, 2,
            1, 1, 2
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m24f, Matrix2x4f{
            1, 2,
            3, 4,
            4, 1,
            2, 3
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m23f, Matrix2x3f{
            1, 2,
            3, 4,
            1, 2
        }), "Almost_equal function failed.");

        TEST_ASSERT(almost_equal(m22f, Matrix2x2f{
            1, 2,
            4, 1
        }), "Almost_equal function failed.");

        TEST_ASSERT(!almost_equal(m44f, Matrix4x4f{
            1, 2, 3, 0,
            4, 1, 2, 0,
            3, 4, 1, 0,
            2, 3, 4, 0
        }), "Almost_equal function failed.");

        // clang-format on
    }

    void logical_not_function()
    {
        TEST_ASSERT(logical_not(Vector2b(false, true)) == Vector2b(true, false), "Logical_not function failed.");
    }

    void logical_and_function()
    {
        const Vector2b result = logical_and(Vector2b(true, true), Vector2b(true, false));
        TEST_ASSERT(result == Vector2b(true, false), "Logical_and function failed.");
    }

    void logical_or_function()
    {
        const Vector2b result = logical_or(Vector2b(true, true), Vector2b(true, false));
        TEST_ASSERT(result == Vector2b(true, true), "Logical_or function failed.");
    }

    void all_function()
    {
        TEST_ASSERT(all(Vector2b(true, true)), "All function failed.");
        TEST_ASSERT(all(Vector2b(true, false)) == false, "All function failed.");
    }

    void any_function()
    {
        TEST_ASSERT(any(Vector2b(true, false)), "Any function failed.");
        TEST_ASSERT(any(Vector2b(false, false)) == false, "Any function failed.");
    }

    Vector2i v2i1;
    Vector2i v2i2;
};

int main()
{
    return run_tests(RelationalFunctionsTest());
}
