#include <math/math.hpp>
#include <unit_test/test.hpp>

using namespace framework::math;

class matrix_assign_test : public test::suite
{
public:
    matrix_assign_test()
        : suite("matrix_assign_test")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
    }

private:
    void assign_operator()
    {
        // clang-format off
        const Matrix4x4F temp_matrix = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };
        // clang-format on

        const Matrix4x4F test44(temp_matrix);
        const Matrix4x3F test43(temp_matrix);
        const Matrix4x2F test42(temp_matrix);
        const Matrix3x4F test34(temp_matrix);
        const Matrix3x3F test33(temp_matrix);
        const Matrix3x2F test32(temp_matrix);
        const Matrix2x4F test24(temp_matrix);
        const Matrix2x3F test23(temp_matrix);
        const Matrix2x2F test22(temp_matrix);

        Matrix4x4D result44;
        Matrix4x3D result43;
        Matrix4x2D result42;
        Matrix3x4D result34;
        Matrix3x3D result33;
        Matrix3x2D result32;
        Matrix2x4D result24;
        Matrix2x3D result23;
        Matrix2x2D result22;

        result44 = test44;
        result43 = test43;
        result42 = test42;
        result34 = test34;
        result33 = test33;
        result32 = test32;
        result24 = test24;
        result23 = test23;
        result22 = test22;

        TEST_ASSERT(static_cast<Matrix4x4F>(result44) == test44, "Matrix4x4 assign failed.");
        TEST_ASSERT(static_cast<Matrix4x3F>(result43) == test43, "Matrix4x3 assign failed.");
        TEST_ASSERT(static_cast<Matrix4x2F>(result42) == test42, "Matrix4x2 assign failed.");
        TEST_ASSERT(static_cast<Matrix3x4F>(result34) == test34, "Matrix3x4 assign failed.");
        TEST_ASSERT(static_cast<Matrix3x3F>(result33) == test33, "Matrix3x3 assign failed.");
        TEST_ASSERT(static_cast<Matrix3x2F>(result32) == test32, "Matrix3x2 assign failed.");
        TEST_ASSERT(static_cast<Matrix2x4F>(result24) == test24, "Matrix2x4 assign failed.");
        TEST_ASSERT(static_cast<Matrix2x3F>(result23) == test23, "Matrix2x3 assign failed.");
        TEST_ASSERT(static_cast<Matrix2x2F>(result22) == test22, "Matrix2x2 assign failed.");
    }
};

int main()
{
    return run_tests(matrix_assign_test());
}
