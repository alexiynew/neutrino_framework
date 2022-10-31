#include <math/math.hpp>
#include <unit_test/suite.hpp>

using neutrino::math::Matrix2x2f;
using neutrino::math::Matrix2x3f;
using neutrino::math::Matrix2x4f;
using neutrino::math::Matrix3x2f;
using neutrino::math::Matrix3x3f;
using neutrino::math::Matrix3x4f;
using neutrino::math::Matrix4x2f;
using neutrino::math::Matrix4x3f;
using neutrino::math::Matrix4x4f;

using neutrino::math::Vector2f;
using neutrino::math::Vector3f;
using neutrino::math::Vector4f;

class MatrixAccessTest : public neutrino::unit_test::Suite
{
public:
    MatrixAccessTest()
        : Suite("MatrixAccessTest")
    {
        add_test([this]() { access_operator(); }, "access_operator");
        add_test([this]() { column_function(); }, "column_function");
        add_test([this]() { row_function(); }, "row_function");
        add_test([this]() { data_function(); }, "data_function");

        // clang-format off
        Matrix44 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        Matrix43 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        Matrix42 = {
            0, 1,
            0, 1,
            0, 1,
            0, 1
        };

        Matrix34 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        Matrix33 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        Matrix32 = {
            0, 1,
            0, 1,
            0, 1
        };

        Matrix24 = {
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        Matrix23 = {
            0, 1, 2,
            0, 1, 2
        };

        Matrix22 = {
            0, 1,
            0, 1
        };
        // clang-format on
    }

private:
    void access_operator()
    {
        // clang-format off
        TEST_ASSERT(Matrix44[0] == Vector4f(0, 1, 2, 3) &&
                    Matrix44[1] == Vector4f(0, 1, 2, 3) &&
                    Matrix44[2] == Vector4f(0, 1, 2, 3) &&
                    Matrix44[3] == Vector4f(0, 1, 2, 3),
                    "Matrix 4x4 access operator failed.");

        TEST_ASSERT(Matrix43[0] == Vector3f(0, 1, 2) &&
                    Matrix43[1] == Vector3f(0, 1, 2) &&
                    Matrix43[2] == Vector3f(0, 1, 2) &&
                    Matrix43[3] == Vector3f(0, 1, 2),
                    "Matrix 4x3 access operator failed.");

        TEST_ASSERT(Matrix42[0] == Vector2f(0, 1) &&
                    Matrix42[1] == Vector2f(0, 1) &&
                    Matrix42[2] == Vector2f(0, 1) &&
                    Matrix42[3] == Vector2f(0, 1),
                    "Matrix 4x2 access operator failed.");

        TEST_ASSERT(Matrix34[0] == Vector4f(0, 1, 2, 3) &&
                    Matrix34[1] == Vector4f(0, 1, 2, 3) &&
                    Matrix34[2] == Vector4f(0, 1, 2, 3),
                    "Matrix 3x4 access operator failed.");

        TEST_ASSERT(Matrix33[0] == Vector3f(0, 1, 2) &&
                    Matrix33[1] == Vector3f(0, 1, 2) &&
                    Matrix33[2] == Vector3f(0, 1, 2),
                    "Matrix 3x3 access operator failed.");

        TEST_ASSERT(Matrix32[0] == Vector2f(0, 1) &&
                    Matrix32[1] == Vector2f(0, 1) &&
                    Matrix32[2] == Vector2f(0, 1),
                    "Matrix 3x2 access operator failed.");

        TEST_ASSERT(Matrix24[0] == Vector4f(0, 1, 2, 3) &&
                    Matrix24[1] == Vector4f(0, 1, 2, 3),
                    "Matrix 2x4 access operator failed.");

        TEST_ASSERT(Matrix23[0] == Vector3f(0, 1, 2) &&
                    Matrix23[1] == Vector3f(0, 1, 2),
                    "Matrix 2x3 access operator failed.");

        TEST_ASSERT(Matrix22[0] == Vector2f(0, 1) &&
                    Matrix22[1] == Vector2f(0, 1),
                    "Matrix 2x2 access operator failed.");
        // clang-format on
    }

    void column_function()
    {
        // clang-format off
        TEST_ASSERT(Matrix44.column(0) == Vector4f(0, 1, 2, 3) &&
                    Matrix44.column(1) == Vector4f(0, 1, 2, 3) &&
                    Matrix44.column(2) == Vector4f(0, 1, 2, 3) &&
                    Matrix44.column(3) == Vector4f(0, 1, 2, 3),
                    "Matrix 4x4 column function failed.");

        TEST_ASSERT(Matrix43.column(0) == Vector3f(0, 1, 2) &&
                    Matrix43.column(1) == Vector3f(0, 1, 2) &&
                    Matrix43.column(2) == Vector3f(0, 1, 2) &&
                    Matrix43.column(3) == Vector3f(0, 1, 2),
                    "Matrix 4x3 column function failed.");

        TEST_ASSERT(Matrix42.column(0) == Vector2f(0, 1) &&
                    Matrix42.column(1) == Vector2f(0, 1) &&
                    Matrix42.column(2) == Vector2f(0, 1) &&
                    Matrix42.column(3) == Vector2f(0, 1),
                    "Matrix 4x2 column function failed.");

        TEST_ASSERT(Matrix34.column(0) == Vector4f(0, 1, 2, 3) &&
                    Matrix34.column(1) == Vector4f(0, 1, 2, 3) &&
                    Matrix34.column(2) == Vector4f(0, 1, 2, 3),
                    "Matrix 3x4 column function failed.");

        TEST_ASSERT(Matrix33.column(0) == Vector3f(0, 1, 2) &&
                    Matrix33.column(1) == Vector3f(0, 1, 2) &&
                    Matrix33.column(2) == Vector3f(0, 1, 2),
                    "Matrix 3x3 column function failed.");

        TEST_ASSERT(Matrix32.column(0) == Vector2f(0, 1) &&
                    Matrix32.column(1) == Vector2f(0, 1) &&
                    Matrix32.column(2) == Vector2f(0, 1),
                    "Matrix 3x2 column function failed.");

        TEST_ASSERT(Matrix24.column(0) == Vector4f(0, 1, 2, 3) &&
                    Matrix24.column(1) == Vector4f(0, 1, 2, 3),
                    "Matrix 2x4 column function failed.");

        TEST_ASSERT(Matrix23.column(0) == Vector3f(0, 1, 2) &&
                    Matrix23.column(1) == Vector3f(0, 1, 2),
                    "Matrix 2x3 column function failed.");

        TEST_ASSERT(Matrix22.column(0) == Vector2f(0, 1) &&
                    Matrix22.column(1) == Vector2f(0, 1),
                    "Matrix 2x2 column function failed.");
        // clang-format on
    }

    void row_function()
    {
        // clang-format off
        TEST_ASSERT(Matrix44.row(0) == Vector4f(0, 0, 0, 0) &&
                    Matrix44.row(1) == Vector4f(1, 1, 1, 1) &&
                    Matrix44.row(2) == Vector4f(2, 2, 2, 2) &&
                    Matrix44.row(3) == Vector4f(3, 3, 3, 3),
                    "Matrix 4x4 row function failed.");

        TEST_ASSERT(Matrix43.row(0) == Vector4f(0, 0, 0, 0) &&
                    Matrix43.row(1) == Vector4f(1, 1, 1, 1) &&
                    Matrix43.row(2) == Vector4f(2, 2, 2, 2),
                    "Matrix 4x3 row function failed.");

        TEST_ASSERT(Matrix42.row(0) == Vector4f(0, 0, 0, 0) &&
                    Matrix42.row(1) == Vector4f(1, 1, 1, 1),
                    "Matrix 4x2 row function failed.");

        TEST_ASSERT(Matrix34.row(0) == Vector3f(0, 0, 0) &&
                    Matrix34.row(1) == Vector3f(1, 1, 1) &&
                    Matrix34.row(2) == Vector3f(2, 2, 2) &&
                    Matrix34.row(3) == Vector3f(3, 3, 3),
                    "Matrix 3x4 row function failed.");

        TEST_ASSERT(Matrix33.row(0) == Vector3f(0, 0, 0) &&
                    Matrix33.row(1) == Vector3f(1, 1, 1) &&
                    Matrix33.row(2) == Vector3f(2, 2, 2),
                    "Matrix 3x3 row function failed.");

        TEST_ASSERT(Matrix32.row(0) == Vector3f(0, 0, 0) &&
                    Matrix32.row(1) == Vector3f(1, 1, 1),
                    "Matrix 3x2 row function failed.");

        TEST_ASSERT(Matrix24.row(0) == Vector2f(0, 0) &&
                    Matrix24.row(1) == Vector2f(1, 1) &&
                    Matrix24.row(2) == Vector2f(2, 2) &&
                    Matrix24.row(3) == Vector2f(3, 3),
                    "Matrix 2x4 row function failed.");

        TEST_ASSERT(Matrix23.row(0) == Vector2f(0, 0) &&
                    Matrix23.row(1) == Vector2f(1, 1) &&
                    Matrix23.row(2) == Vector2f(2, 2),
                    "Matrix 2x3 row function failed.");


        TEST_ASSERT(Matrix22.row(0) == Vector2f(0, 0) &&
                    Matrix22.row(1) == Vector2f(1, 1),
                    "Matrix 2x2 row function failed.");
        // clang-format on
    }

    void data_function()
    {
        float* p44 = Matrix44.data();
        float* p34 = Matrix34.data();
        float* p24 = Matrix24.data();
        float* p43 = Matrix43.data();
        float* p33 = Matrix33.data();
        float* p23 = Matrix23.data();
        float* p42 = Matrix42.data();
        float* p32 = Matrix32.data();
        float* p22 = Matrix22.data();

        auto check = [](const float a, const float b) { return neutrino::math::abs(a - b) <= 0; };

        // clang-format off
        TEST_ASSERT(check(p44[0],  0.0f) && check(p44[1], 1.0f)  && check(p44[2], 2.0f)  && check(p44[3], 3.0f)  &&
                    check(p44[4],  0.0f) && check(p44[5], 1.0f)  && check(p44[6], 2.0f)  && check(p44[7], 3.0f)  &&
                    check(p44[8],  0.0f) && check(p44[9], 1.0f)  && check(p44[10], 2.0f) && check(p44[11], 3.0f) &&
                    check(p44[12], 0.0f) && check(p44[13], 1.0f) && check(p44[14], 2.0f) && check(p44[15], 3.0f),
                    "Matrix4x4 pointer data access failed.");

        TEST_ASSERT(check(p43[0], 0.0f) && check(p43[1],  1.0f) && check(p43[2],  2.0f) &&
                    check(p43[3], 0.0f) && check(p43[4],  1.0f) && check(p43[5],  2.0f) &&
                    check(p43[6], 0.0f) && check(p43[7],  1.0f) && check(p43[8],  2.0f) &&
                    check(p43[9], 0.0f) && check(p43[10], 1.0f) && check(p43[11], 2.0f),
                    "Matrix4x3 pointer data access failed.");

        TEST_ASSERT(check(p42[0], 0.0f) && check(p42[1], 1.0f) &&
                    check(p42[2], 0.0f) && check(p42[3], 1.0f) &&
                    check(p42[4], 0.0f) && check(p42[5], 1.0f) &&
                    check(p42[6], 0.0f) && check(p42[7], 1.0f),
                    "Matrix4x2 pointer data access failed.");

        TEST_ASSERT(check(p34[0], 0.0f) && check(p34[1], 1.0f) && check(p34[2],  2.0f) && check(p34[3],  3.0f) &&
                    check(p34[4], 0.0f) && check(p34[5], 1.0f) && check(p34[6],  2.0f) && check(p34[7],  3.0f) &&
                    check(p34[8], 0.0f) && check(p34[9], 1.0f) && check(p34[10], 2.0f) && check(p34[11], 3.0f),
                    "Matrix3x4 pointer data access failed.");

        TEST_ASSERT(check(p33[0], 0.0f) && check(p33[1], 1.0f) && check(p33[2], 2.0f) &&
                    check(p33[3], 0.0f) && check(p33[4], 1.0f) && check(p33[5], 2.0f) &&
                    check(p33[6], 0.0f) && check(p33[7], 1.0f) && check(p33[8], 2.0f),
                    "Matrix3x3 pointer data access failed.");

        TEST_ASSERT(check(p32[0], 0.0f) && check(p32[1], 1.0f) &&
                    check(p32[2], 0.0f) && check(p32[3], 1.0f) &&
                    check(p32[4], 0.0f) && check(p32[5], 1.0f),
                    "Matrix3x2 pointer data access failed.");

        TEST_ASSERT(check(p24[0], 0.0f) && check(p24[1], 1.0f) && check(p24[2], 2.0f) && check(p24[3], 3.0f) &&
                    check(p24[4], 0.0f) && check(p24[5], 1.0f) && check(p24[6], 2.0f) && check(p24[7], 3.0f),
                    "Matrix2x4 pointer data access failed.");

        TEST_ASSERT(check(p23[0], 0.0f) && check(p23[1], 1.0f) && check(p23[2], 2.0f) &&
                    check(p23[3], 0.0f) && check(p23[4], 1.0f) && check(p23[5], 2.0f),
                    "Matrix2x3 pointer data access failed.");

        TEST_ASSERT(check(p22[0], 0.0f) && check(p22[1], 1.0f) &&
                    check(p22[2], 0.0f) && check(p22[3], 1.0f),
                    "Matrix2x2 pointer data access failed.");
        // clang-format on
    }

    Matrix4x4f Matrix44;
    Matrix4x3f Matrix43;
    Matrix4x2f Matrix42;

    Matrix3x4f Matrix34;
    Matrix3x3f Matrix33;
    Matrix3x2f Matrix32;

    Matrix2x4f Matrix24;
    Matrix2x3f Matrix23;
    Matrix2x2f Matrix22;
};

int main()
{
    return run_tests(MatrixAccessTest());
}
