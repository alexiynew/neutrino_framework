
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

using ::framework::math::matrix4f;

using ::framework::math::vector2f;
using ::framework::math::vector3f;
using ::framework::math::vector4f;

using ::framework::math::almost_equal;

class matrix_function_tests : public framework::unit_test::suite
{
public:
    matrix_function_tests() : suite("matrix_function_tests")
    {
        add_test([this]() { transpose_function(); }, "transpose_function");
        add_test([this]() { cross_component_multiplication_function(); }, "cross_component_multiplication_function");
        add_test([this]() { outer_product_function(); }, "outer_product_function");
        add_test([this]() { determinant_function(); }, "determinant_function");
        add_test([this]() { inverse_function(); }, "inverse_function");
        add_test([this]() { affine_inverse_function(); }, "affine_inverse_function");
        add_test([this]() { inverse_transpose_function(); }, "inverse_transpose_function");
    }

private:
    void transpose_function()
    {
        const matrix4x4f test44 = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
        const matrix4x3f test43(test44);
        const matrix4x2f test42(test44);
        const matrix3x4f test34(test44);
        const matrix3x3f test33(test44);
        const matrix3x2f test32(test44);
        const matrix2x4f test24(test44);
        const matrix2x3f test23(test44);
        const matrix2x2f test22(test44);

        const matrix4x4f result44 = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
        const matrix4x3f result43(result44);
        const matrix4x2f result42(result44);
        const matrix3x4f result34(result44);
        const matrix3x3f result33(result44);
        const matrix3x2f result32(result44);
        const matrix2x4f result24(result44);
        const matrix2x3f result23(result44);
        const matrix2x2f result22(result44);

        TEST_ASSERT(transpose(test44) == result44, "Transpose function for Matrix4x4 failed.");
        TEST_ASSERT(transpose(test43) == result34, "Transpose function for Matrix4x3 failed.");
        TEST_ASSERT(transpose(test42) == result24, "Transpose function for Matrix4x2 failed.");

        TEST_ASSERT(transpose(test34) == result43, "Transpose function for Matrix3x4 failed.");
        TEST_ASSERT(transpose(test33) == result33, "Transpose function for Matrix3x3 failed.");
        TEST_ASSERT(transpose(test32) == result23, "Transpose function for Matrix3x2 failed.");

        TEST_ASSERT(transpose(test24) == result42, "Transpose function for Matrix2x4 failed.");
        TEST_ASSERT(transpose(test23) == result32, "Transpose function for Matrix2x3 failed.");
        TEST_ASSERT(transpose(test22) == result22, "Transpose function for Matrix2x2 failed.");
    }

    void cross_component_multiplication_function()
    {
        const matrix4x4f test44 = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
        const matrix4x3f test43(test44);
        const matrix4x2f test42(test44);
        const matrix3x4f test34(test44);
        const matrix3x3f test33(test44);
        const matrix3x2f test32(test44);
        const matrix2x4f test24(test44);
        const matrix2x3f test23(test44);
        const matrix2x2f test22(test44);

        const matrix4x4f result44 = {1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16};
        const matrix4x3f result43(result44);
        const matrix4x2f result42(result44);
        const matrix3x4f result34(result44);
        const matrix3x3f result33(result44);
        const matrix3x2f result32(result44);
        const matrix2x4f result24(result44);
        const matrix2x3f result23(result44);
        const matrix2x2f result22(result44);

        TEST_ASSERT(component_wise_multiplication(test44, test44) == result44,
                    "Component_wise_multiplication function for Matrix4x4 failed.");
        TEST_ASSERT(component_wise_multiplication(test43, test43) == result43,
                    "Component_wise_multiplication function for Matrix4x3 failed.");
        TEST_ASSERT(component_wise_multiplication(test42, test42) == result42,
                    "Component_wise_multiplication function for Matrix4x2 failed.");
        TEST_ASSERT(component_wise_multiplication(test34, test34) == result34,
                    "Component_wise_multiplication function for Matrix3x4 failed.");
        TEST_ASSERT(component_wise_multiplication(test33, test33) == result33,
                    "Component_wise_multiplication function for Matrix3x3 failed.");
        TEST_ASSERT(component_wise_multiplication(test32, test32) == result32,
                    "Component_wise_multiplication function for Matrix3x2 failed.");
        TEST_ASSERT(component_wise_multiplication(test24, test24) == result24,
                    "Component_wise_multiplication function for Matrix2x4 failed.");
        TEST_ASSERT(component_wise_multiplication(test23, test23) == result23,
                    "Component_wise_multiplication function for Matrix2x3 failed.");
        TEST_ASSERT(component_wise_multiplication(test22, test22) == result22,
                    "Component_wise_multiplication function for Matrix2x2 failed.");
    }

    void outer_product_function()
    {
        const vector2f v2(1, 2);
        const vector3f v3(1, 2, 3);
        const vector4f v4(1, 2, 3, 4);

        const matrix4x4f result44 = {1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12, 4, 8, 12, 16};
        const matrix4x3f result43 = {1, 2, 3, 2, 4, 6, 3, 6, 9, 4, 8, 12};
        const matrix4x2f result42 = {1, 2, 2, 4, 3, 6, 4, 8};
        const matrix3x4f result34 = {1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12};
        const matrix3x3f result33 = {1, 2, 3, 2, 4, 6, 3, 6, 9};
        const matrix3x2f result32 = {1, 2, 2, 4, 3, 6};
        const matrix2x4f result24 = {1, 2, 3, 4, 2, 4, 6, 8};
        const matrix2x3f result23 = {1, 2, 3, 2, 4, 6};
        const matrix2x2f result22 = {1, 2, 2, 4};

        TEST_ASSERT(outer_product(v4, v4) == result44, "Outer_product function from (v4, v4) failed.");
        TEST_ASSERT(outer_product(v3, v4) == result43, "Outer_product function from (v3, v4) failed.");
        TEST_ASSERT(outer_product(v2, v4) == result42, "Outer_product function from (v2, v4) failed.");
        TEST_ASSERT(outer_product(v4, v3) == result34, "Outer_product function from (v4, v3) failed.");
        TEST_ASSERT(outer_product(v3, v3) == result33, "Outer_product function from (v3, v3) failed.");
        TEST_ASSERT(outer_product(v2, v3) == result32, "Outer_product function from (v2, v3) failed.");
        TEST_ASSERT(outer_product(v4, v2) == result24, "Outer_product function from (v4, v2) failed.");
        TEST_ASSERT(outer_product(v3, v2) == result23, "Outer_product function from (v3, v2) failed.");
        TEST_ASSERT(outer_product(v2, v2) == result22, "Outer_product function from (v2, v2) failed.");
    }

    void determinant_function()
    {
        TEST_ASSERT(almost_equal(determinant(matrix2x2f()), 1.0f), "Determinant function for matrix2x2f failed.");
        TEST_ASSERT(almost_equal(determinant(matrix3x3f()), 1.0f), "Determinant function for matrix3x3f failed.");
        TEST_ASSERT(almost_equal(determinant(matrix4x4f()), 1.0f), "Determinant function for matrix4x4f failed.");

        const matrix2x2f dependent2 = {1, 2, 1, 2};
        const matrix3x3f dependent3 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
        const matrix4x4f dependent4 = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

        TEST_ASSERT(almost_equal(determinant(dependent2), 0.0f), "Determinant function for matrix2x2f failed.");
        TEST_ASSERT(almost_equal(determinant(dependent3), 0.0f), "Determinant function for matrix3x3f failed.");
        TEST_ASSERT(almost_equal(determinant(dependent4), 0.0f), "Determinant function for matrix4x4f failed.");

        const matrix2x2f independent2 = {4, 2, 2, 3};
        const matrix3x3f independent3 = {8, 6, 7, 4, 2, 3, 1, 5, 2};
        const matrix4x4f independent4 = {1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1};

        TEST_ASSERT(almost_equal(determinant(independent2), 8.0f), "Determinant function for matrix2x2f failed.");
        TEST_ASSERT(almost_equal(determinant(independent3), 8.0f), "Determinant function for matrix3x3f failed.");
        TEST_ASSERT(almost_equal(determinant(independent4), -1.0f), "Determinant function for matrix4x4f failed.");
    }

    void inverse_function()
    {
        const matrix2x2f test2 = {4, 2, 2, 3};
        const matrix3x3f test3 = {8, 6, 7, 4, 2, 3, 1, 5, 2};
        const matrix4x4f test4 = {1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1};

        TEST_ASSERT(inverse(test2) * test2 == matrix2x2f(), "Inverse function for matrix2x2f failed.");
        TEST_ASSERT(inverse(test3) * test3 == matrix3x3f(), "Inverse function for matrix3x3f failed.");
        TEST_ASSERT(inverse(test4) * test4 == matrix4x4f(), "Inverse function for matrix4x4f failed.");

        TEST_ASSERT(almost_equal(determinant(inverse(test2)), 1.0f / determinant(test2)),
                    "Determinant of inverse matrix2x2f is wrong.");
        TEST_ASSERT(almost_equal(determinant(inverse(test3)), 1.0f / determinant(test3)),
                    "Determinant of inverse matrix3x3f is wrong.");
        TEST_ASSERT(almost_equal(determinant(inverse(test4)), 1.0f / determinant(test4)),
                    "Determinant of inverse matrix4x4f is wrong.");
    }

    void affine_inverse_function()
    {
        const matrix3x3f test3 = {0, -1, 0, -1, 0, 0, 5, 5, 1};

        TEST_ASSERT(affine_inverse(test3) == inverse(test3), "Affine inverse function for matrix3x3f failed.");

        // clang-format off
        const matrix4f test_matrix = {
            0.707f, 0.0f,   -0.707f, 0.0f,
            0.354f, 0.866f, 0.354f,  0.0f,
            0.612f, -0.5f,  0.612f,  0.0f,
            1.0f,   1.0f,   4.0f,    1.0f
        };
        // clang-format on

        auto test   = affine_inverse(test_matrix);
        auto result = inverse(test_matrix);

        TEST_ASSERT(almost_equal(test, result), "Affine inverse function for matrix4x4f failed.");
    }

    void inverse_transpose_function()
    {
        const matrix2x2f test2 = {4, 2, 2, 3};
        const matrix3x3f test3 = {8, 6, 7, 4, 2, 3, 1, 5, 2};
        const matrix4x4f test4 = {1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1};

        TEST_ASSERT(transpose(inverse(test2)) == inverse_transpose(test2),
                    "Inverse_transpose function for matrix2x2f failed.");
        TEST_ASSERT(transpose(inverse(test3)) == inverse_transpose(test3),
                    "Inverse_transpose function for matrix3x3f failed.");
        TEST_ASSERT(transpose(inverse(test4)) == inverse_transpose(test4),
                    "Inverse_transpose function for matrix4x4f failed.");
    }
};

int main()
{
    return run_tests(matrix_function_tests());
}
