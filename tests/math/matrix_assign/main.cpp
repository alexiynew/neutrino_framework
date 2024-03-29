#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::math::Matrix2x2f;
using framework::math::Matrix2x3f;
using framework::math::Matrix2x4f;
using framework::math::Matrix3x2f;
using framework::math::Matrix3x3f;
using framework::math::Matrix3x4f;
using framework::math::Matrix4x2f;
using framework::math::Matrix4x3f;
using framework::math::Matrix4x4f;

class MatrixAssignTest : public framework::unit_test::Suite
{
public:
    MatrixAssignTest()
        : Suite("MatrixAssignTest")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
    }

private:
    void assign_operator()
    {
        // clang-format off
        const Matrix4x4f temp_matrix = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };
        // clang-format on

        const Matrix4x4f test44(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix4x3f test43(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix4x2f test42(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix3x4f test34(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix3x3f test33(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix3x2f test32(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix2x4f test24(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix2x3f test23(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)
        const Matrix2x2f test22(temp_matrix); // NOLINT(performance-unnecessary-copy-initialization)

        Matrix4x4f result44;
        Matrix4x3f result43;
        Matrix4x2f result42;
        Matrix3x4f result34;
        Matrix3x3f result33;
        Matrix3x2f result32;
        Matrix2x4f result24;
        Matrix2x3f result23;
        Matrix2x2f result22;

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
    return run_tests(MatrixAssignTest());
}
