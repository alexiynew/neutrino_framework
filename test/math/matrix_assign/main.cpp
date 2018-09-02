
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

using ::framework::math::matrix2x2f;
using ::framework::math::matrix2x3f;
using ::framework::math::matrix2x4f;
using ::framework::math::matrix3x2f;
using ::framework::math::matrix3x3f;
using ::framework::math::matrix3x4f;
using ::framework::math::matrix4x2f;
using ::framework::math::matrix4x3f;
using ::framework::math::matrix4x4f;

class matrix_assign_test : public framework::unit_test::suite
{
public:
    matrix_assign_test() : suite("matrix_assign_test")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
    }

private:
    void assign_operator()
    {
        // clang-format off
        const matrix4x4f temp_matrix = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };
        // clang-format on

        const matrix4x4f test44(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix4x3f test43(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix4x2f test42(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix3x4f test34(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix3x3f test33(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix3x2f test32(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix2x4f test24(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix2x3f test23(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const matrix2x2f test22(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)

        matrix4x4f result44;
        matrix4x3f result43;
        matrix4x2f result42;
        matrix3x4f result34;
        matrix3x3f result33;
        matrix3x2f result32;
        matrix2x4f result24;
        matrix2x3f result23;
        matrix2x2f result22;

        result44 = test44;
        result43 = test43;
        result42 = test42;
        result34 = test34;
        result33 = test33;
        result32 = test32;
        result24 = test24;
        result23 = test23;
        result22 = test22;

        TEST_ASSERT(result44 == test44, "Matrix4x4 assign failed.");
        TEST_ASSERT(result43 == test43, "Matrix4x3 assign failed.");
        TEST_ASSERT(result42 == test42, "Matrix4x2 assign failed.");
        TEST_ASSERT(result34 == test34, "Matrix3x4 assign failed.");
        TEST_ASSERT(result33 == test33, "Matrix3x3 assign failed.");
        TEST_ASSERT(result32 == test32, "Matrix3x2 assign failed.");
        TEST_ASSERT(result24 == test24, "Matrix2x4 assign failed.");
        TEST_ASSERT(result23 == test23, "Matrix2x3 assign failed.");
        TEST_ASSERT(result22 == test22, "Matrix2x2 assign failed.");
    }
};

int main()
{
    return run_tests(matrix_assign_test());
}
