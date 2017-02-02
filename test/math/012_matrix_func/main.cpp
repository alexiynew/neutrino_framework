#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class matrix_function_tests : public test::suite
{
public:
    matrix_function_tests()
        : suite("matrix_function_tests")
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
        const Matrix4x4F test44 = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
        const Matrix4x3F test43(test44);
        const Matrix4x2F test42(test44);
        const Matrix3x4F test34(test44);
        const Matrix3x3F test33(test44);
        const Matrix3x2F test32(test44);
        const Matrix2x4F test24(test44);
        const Matrix2x3F test23(test44);
        const Matrix2x2F test22(test44);

        const Matrix4x4F result44 = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
        const Matrix4x3F result43(result44);
        const Matrix4x2F result42(result44);
        const Matrix3x4F result34(result44);
        const Matrix3x3F result33(result44);
        const Matrix3x2F result32(result44);
        const Matrix2x4F result24(result44);
        const Matrix2x3F result23(result44);
        const Matrix2x2F result22(result44);

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
        const Matrix4x4F test44 = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
        const Matrix4x3F test43(test44);
        const Matrix4x2F test42(test44);
        const Matrix3x4F test34(test44);
        const Matrix3x3F test33(test44);
        const Matrix3x2F test32(test44);
        const Matrix2x4F test24(test44);
        const Matrix2x3F test23(test44);
        const Matrix2x2F test22(test44);

        const Matrix4x4F result44 = {1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16, 1, 4, 9, 16};
        const Matrix4x3F result43(result44);
        const Matrix4x2F result42(result44);
        const Matrix3x4F result34(result44);
        const Matrix3x3F result33(result44);
        const Matrix3x2F result32(result44);
        const Matrix2x4F result24(result44);
        const Matrix2x3F result23(result44);
        const Matrix2x2F result22(result44);

        TEST_ASSERT(crossComponentMultiplication(test44, test44) == result44,
                    "Cross_component_multiplication function for Matrix4x4 failed.");
        TEST_ASSERT(crossComponentMultiplication(test43, test43) == result43,
                    "Cross_component_multiplication function for Matrix4x3 failed.");
        TEST_ASSERT(crossComponentMultiplication(test42, test42) == result42,
                    "Cross_component_multiplication function for Matrix4x2 failed.");
        TEST_ASSERT(crossComponentMultiplication(test34, test34) == result34,
                    "Cross_component_multiplication function for Matrix3x4 failed.");
        TEST_ASSERT(crossComponentMultiplication(test33, test33) == result33,
                    "Cross_component_multiplication function for Matrix3x3 failed.");
        TEST_ASSERT(crossComponentMultiplication(test32, test32) == result32,
                    "Cross_component_multiplication function for Matrix3x2 failed.");
        TEST_ASSERT(crossComponentMultiplication(test24, test24) == result24,
                    "Cross_component_multiplication function for Matrix2x4 failed.");
        TEST_ASSERT(crossComponentMultiplication(test23, test23) == result23,
                    "Cross_component_multiplication function for Matrix2x3 failed.");
        TEST_ASSERT(crossComponentMultiplication(test22, test22) == result22,
                    "Cross_component_multiplication function for Matrix2x2 failed.");
    }

    void outer_product_function()
    {
        const Vector2F v2(1, 2);
        const Vector3F v3(1, 2, 3);
        const Vector4F v4(1, 2, 3, 4);

        const Matrix4x4F result44 = {1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12, 4, 8, 12, 16};
        const Matrix4x3F result43 = {1, 2, 3, 2, 4, 6, 3, 6, 9, 4, 8, 12};
        const Matrix4x2F result42 = {1, 2, 2, 4, 3, 6, 4, 8};
        const Matrix3x4F result34 = {1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12};
        const Matrix3x3F result33 = {1, 2, 3, 2, 4, 6, 3, 6, 9};
        const Matrix3x2F result32 = {1, 2, 2, 4, 3, 6};
        const Matrix2x4F result24 = {1, 2, 3, 4, 2, 4, 6, 8};
        const Matrix2x3F result23 = {1, 2, 3, 2, 4, 6};
        const Matrix2x2F result22 = {1, 2, 2, 4};

        TEST_ASSERT(outerProduct(v4, v4) == result44, "Outer_product function from (v4, v4) failed.");
        TEST_ASSERT(outerProduct(v3, v4) == result43, "Outer_product function from (v3, v4) failed.");
        TEST_ASSERT(outerProduct(v2, v4) == result42, "Outer_product function from (v2, v4) failed.");
        TEST_ASSERT(outerProduct(v4, v3) == result34, "Outer_product function from (v4, v3) failed.");
        TEST_ASSERT(outerProduct(v3, v3) == result33, "Outer_product function from (v3, v3) failed.");
        TEST_ASSERT(outerProduct(v2, v3) == result32, "Outer_product function from (v2, v3) failed.");
        TEST_ASSERT(outerProduct(v4, v2) == result24, "Outer_product function from (v4, v2) failed.");
        TEST_ASSERT(outerProduct(v3, v2) == result23, "Outer_product function from (v3, v2) failed.");
        TEST_ASSERT(outerProduct(v2, v2) == result22, "Outer_product function from (v2, v2) failed.");
    }

    void determinant_function()
    {
        TEST_ASSERT(almost_equal(determinant(Matrix2x2F()), 1.0f), "Determinant function for Matrix2x2F failed.");
        TEST_ASSERT(almost_equal(determinant(Matrix3x3F()), 1.0f), "Determinant function for Matrix3x3F failed.");
        TEST_ASSERT(almost_equal(determinant(Matrix4x4F()), 1.0f), "Determinant function for Matrix4x4F failed.");

        const Matrix2x2F dependent2 = {1, 2, 1, 2};
        const Matrix3x3F dependent3 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
        const Matrix4x4F dependent4 = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

        TEST_ASSERT(almost_equal(determinant(dependent2), 0.0f), "Determinant function for Matrix2x2F failed.");
        TEST_ASSERT(almost_equal(determinant(dependent3), 0.0f), "Determinant function for Matrix3x3F failed.");
        TEST_ASSERT(almost_equal(determinant(dependent4), 0.0f), "Determinant function for Matrix4x4F failed.");

        const Matrix2x2F independent2 = {4, 2, 2, 3};
        const Matrix3x3F independent3 = {8, 6, 7, 4, 2, 3, 1, 5, 2};
        const Matrix4x4F independent4 = {1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1};

        TEST_ASSERT(almost_equal(determinant(independent2), 8.0f), "Determinant function for Matrix2x2F failed.");
        TEST_ASSERT(almost_equal(determinant(independent3), 8.0f), "Determinant function for Matrix3x3F failed.");
        TEST_ASSERT(almost_equal(determinant(independent4), -1.0f), "Determinant function for Matrix4x4F failed.");
    }

    void inverse_function()
    {
        const Matrix2x2F test2 = {4, 2, 2, 3};
        const Matrix3x3F test3 = {8, 6, 7, 4, 2, 3, 1, 5, 2};
        const Matrix4x4F test4 = {1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1};

        TEST_ASSERT(inverse(test2) * test2 == Matrix2x2F(), "Inverse function for Matrix2x2F failed.");
        TEST_ASSERT(inverse(test3) * test3 == Matrix3x3F(), "Inverse function for Matrix3x3F failed.");
        TEST_ASSERT(inverse(test4) * test4 == Matrix4x4F(), "Inverse function for Matrix4x4F failed.");

        TEST_ASSERT(almost_equal(determinant(inverse(test2)), 1.0f / determinant(test2)),
                    "Determinant of inverse Matrix2x2F is wrong.");
        TEST_ASSERT(almost_equal(determinant(inverse(test3)), 1.0f / determinant(test3)),
                    "Determinant of inverse Matrix3x3F is wrong.");
        TEST_ASSERT(almost_equal(determinant(inverse(test4)), 1.0f / determinant(test4)),
                    "Determinant of inverse Matrix4x4F is wrong.");
    }

    void affine_inverse_function()
    {
        const Matrix3x3F test3 = {0, -1, 0, -1, 0, 0, 5, 5, 1};

        TEST_ASSERT(affineInverse(test3) == inverse(test3), "Affine inverse function for Matrix3x3F failed.");

        // clang-format off
        const Matrix4F test_matrix = {
            0.707f, 0.0f,   -0.707f, 0.0f,
            0.354f, 0.866f, 0.354f,  0.0f,
            0.612f, -0.5f,  0.612f,  0.0f,
            1.0f,   1.0f,   4.0f,    1.0f
        };
        // clang-format on

        auto test   = affineInverse(test_matrix);
        auto result = inverse(test_matrix);

        TEST_ASSERT(almost_equal(test, result), "Affine inverse function for Matrix4x4F failed.");
    }

    void inverse_transpose_function()
    {
        const Matrix2x2F test2 = {4, 2, 2, 3};
        const Matrix3x3F test3 = {8, 6, 7, 4, 2, 3, 1, 5, 2};
        const Matrix4x4F test4 = {1, 2, 1, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 1};

        TEST_ASSERT(transpose(inverse(test2)) == inverseTranspose(test2),
                    "Inverse_transpose function for Matrix2x2F failed.");
        TEST_ASSERT(transpose(inverse(test3)) == inverseTranspose(test3),
                    "Inverse_transpose function for Matrix3x3F failed.");
        TEST_ASSERT(transpose(inverse(test4)) == inverseTranspose(test4),
                    "Inverse_transpose function for Matrix4x4F failed.");
    }
};

int main()
{
    return run_tests(matrix_function_tests());
}
