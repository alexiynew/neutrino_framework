
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

using ::framework::math::vector2f;
using ::framework::math::vector3f;
using ::framework::math::vector4f;

using ::framework::float32;

class matrix_access_test : public framework::unit_test::Suite
{
public:
    matrix_access_test() : Suite("matrix_access_test")
    {
        add_test([this]() { access_operator(); }, "access_operator");
        add_test([this]() { column_function(); }, "column_function");
        add_test([this]() { row_function(); }, "row_function");
        add_test([this]() { data_function(); }, "data_function");

        // clang-format off
        matrix44 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        matrix43 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        matrix42 = {
            0, 1,
            0, 1,
            0, 1,
            0, 1
        };

        matrix34 = {
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        matrix33 = {
            0, 1, 2,
            0, 1, 2,
            0, 1, 2
        };

        matrix32 = {
            0, 1,
            0, 1,
            0, 1
        };

        matrix24 = {
            0, 1, 2, 3,
            0, 1, 2, 3
        };

        matrix23 = {
            0, 1, 2,
            0, 1, 2
        };

        matrix22 = {
            0, 1,
            0, 1
        };
        // clang-format on
    }

private:
    void access_operator()
    {
        // clang-format off
        TEST_ASSERT(matrix44[0] == vector4f(0, 1, 2, 3) &&
                    matrix44[1] == vector4f(0, 1, 2, 3) &&
                    matrix44[2] == vector4f(0, 1, 2, 3) &&
                    matrix44[3] == vector4f(0, 1, 2, 3),
                    "Matrix 4x4 access operator failed.");

        TEST_ASSERT(matrix43[0] == vector3f(0, 1, 2) &&
                    matrix43[1] == vector3f(0, 1, 2) &&
                    matrix43[2] == vector3f(0, 1, 2) &&
                    matrix43[3] == vector3f(0, 1, 2),
                    "Matrix 4x3 access operator failed.");

        TEST_ASSERT(matrix42[0] == vector2f(0, 1) &&
                    matrix42[1] == vector2f(0, 1) &&
                    matrix42[2] == vector2f(0, 1) &&
                    matrix42[3] == vector2f(0, 1),
                    "Matrix 4x2 access operator failed.");

        TEST_ASSERT(matrix34[0] == vector4f(0, 1, 2, 3) &&
                    matrix34[1] == vector4f(0, 1, 2, 3) &&
                    matrix34[2] == vector4f(0, 1, 2, 3),
                    "Matrix 3x4 access operator failed.");

        TEST_ASSERT(matrix33[0] == vector3f(0, 1, 2) &&
                    matrix33[1] == vector3f(0, 1, 2) &&
                    matrix33[2] == vector3f(0, 1, 2),
                    "Matrix 3x3 access operator failed.");

        TEST_ASSERT(matrix32[0] == vector2f(0, 1) &&
                    matrix32[1] == vector2f(0, 1) &&
                    matrix32[2] == vector2f(0, 1),
                    "Matrix 3x2 access operator failed.");

        TEST_ASSERT(matrix24[0] == vector4f(0, 1, 2, 3) &&
                    matrix24[1] == vector4f(0, 1, 2, 3),
                    "Matrix 2x4 access operator failed.");

        TEST_ASSERT(matrix23[0] == vector3f(0, 1, 2) &&
                    matrix23[1] == vector3f(0, 1, 2),
                    "Matrix 2x3 access operator failed.");

        TEST_ASSERT(matrix22[0] == vector2f(0, 1) &&
                    matrix22[1] == vector2f(0, 1),
                    "Matrix 2x2 access operator failed.");
        // clang-format on
    }

    void column_function()
    {
        // clang-format off
        TEST_ASSERT(matrix44.column(0) == vector4f(0, 1, 2, 3) &&
                    matrix44.column(1) == vector4f(0, 1, 2, 3) &&
                    matrix44.column(2) == vector4f(0, 1, 2, 3) &&
                    matrix44.column(3) == vector4f(0, 1, 2, 3),
                    "Matrix 4x4 column function failed.");

        TEST_ASSERT(matrix43.column(0) == vector3f(0, 1, 2) &&
                    matrix43.column(1) == vector3f(0, 1, 2) &&
                    matrix43.column(2) == vector3f(0, 1, 2) &&
                    matrix43.column(3) == vector3f(0, 1, 2),
                    "Matrix 4x3 column function failed.");

        TEST_ASSERT(matrix42.column(0) == vector2f(0, 1) &&
                    matrix42.column(1) == vector2f(0, 1) &&
                    matrix42.column(2) == vector2f(0, 1) &&
                    matrix42.column(3) == vector2f(0, 1),
                    "Matrix 4x2 column function failed.");

        TEST_ASSERT(matrix34.column(0) == vector4f(0, 1, 2, 3) &&
                    matrix34.column(1) == vector4f(0, 1, 2, 3) &&
                    matrix34.column(2) == vector4f(0, 1, 2, 3),
                    "Matrix 3x4 column function failed.");

        TEST_ASSERT(matrix33.column(0) == vector3f(0, 1, 2) &&
                    matrix33.column(1) == vector3f(0, 1, 2) &&
                    matrix33.column(2) == vector3f(0, 1, 2),
                    "Matrix 3x3 column function failed.");

        TEST_ASSERT(matrix32.column(0) == vector2f(0, 1) &&
                    matrix32.column(1) == vector2f(0, 1) &&
                    matrix32.column(2) == vector2f(0, 1),
                    "Matrix 3x2 column function failed.");

        TEST_ASSERT(matrix24.column(0) == vector4f(0, 1, 2, 3) &&
                    matrix24.column(1) == vector4f(0, 1, 2, 3),
                    "Matrix 2x4 column function failed.");

        TEST_ASSERT(matrix23.column(0) == vector3f(0, 1, 2) &&
                    matrix23.column(1) == vector3f(0, 1, 2),
                    "Matrix 2x3 column function failed.");

        TEST_ASSERT(matrix22.column(0) == vector2f(0, 1) &&
                    matrix22.column(1) == vector2f(0, 1),
                    "Matrix 2x2 column function failed.");
        // clang-format on
    }

    void row_function()
    {
        // clang-format off
        TEST_ASSERT(matrix44.row(0) == vector4f(0, 0, 0, 0) &&
                    matrix44.row(1) == vector4f(1, 1, 1, 1) &&
                    matrix44.row(2) == vector4f(2, 2, 2, 2) &&
                    matrix44.row(3) == vector4f(3, 3, 3, 3),
                    "Matrix 4x4 row function failed.");

        TEST_ASSERT(matrix43.row(0) == vector4f(0, 0, 0, 0) &&
                    matrix43.row(1) == vector4f(1, 1, 1, 1) &&
                    matrix43.row(2) == vector4f(2, 2, 2, 2),
                    "Matrix 4x3 row function failed.");

        TEST_ASSERT(matrix42.row(0) == vector4f(0, 0, 0, 0) &&
                    matrix42.row(1) == vector4f(1, 1, 1, 1),
                    "Matrix 4x2 row function failed.");

        TEST_ASSERT(matrix34.row(0) == vector3f(0, 0, 0) &&
                    matrix34.row(1) == vector3f(1, 1, 1) &&
                    matrix34.row(2) == vector3f(2, 2, 2) &&
                    matrix34.row(3) == vector3f(3, 3, 3),
                    "Matrix 3x4 row function failed.");

        TEST_ASSERT(matrix33.row(0) == vector3f(0, 0, 0) &&
                    matrix33.row(1) == vector3f(1, 1, 1) &&
                    matrix33.row(2) == vector3f(2, 2, 2),
                    "Matrix 3x3 row function failed.");

        TEST_ASSERT(matrix32.row(0) == vector3f(0, 0, 0) &&
                    matrix32.row(1) == vector3f(1, 1, 1),
                    "Matrix 3x2 row function failed.");

        TEST_ASSERT(matrix24.row(0) == vector2f(0, 0) &&
                    matrix24.row(1) == vector2f(1, 1) &&
                    matrix24.row(2) == vector2f(2, 2) &&
                    matrix24.row(3) == vector2f(3, 3),
                    "Matrix 2x4 row function failed.");

        TEST_ASSERT(matrix23.row(0) == vector2f(0, 0) &&
                    matrix23.row(1) == vector2f(1, 1) &&
                    matrix23.row(2) == vector2f(2, 2),
                    "Matrix 2x3 row function failed.");


        TEST_ASSERT(matrix22.row(0) == vector2f(0, 0) &&
                    matrix22.row(1) == vector2f(1, 1),
                    "Matrix 2x2 row function failed.");
        // clang-format on
    }

    void data_function()
    {
        float32* p44 = matrix44.data();
        float32* p34 = matrix34.data();
        float32* p24 = matrix24.data();
        float32* p43 = matrix43.data();
        float32* p33 = matrix33.data();
        float32* p23 = matrix23.data();
        float32* p42 = matrix42.data();
        float32* p32 = matrix32.data();
        float32* p22 = matrix22.data();

        auto check = [](const float32 a, const float32 b) { return framework::math::abs(a - b) <= 0; };

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

    matrix4x4f matrix44;
    matrix4x3f matrix43;
    matrix4x2f matrix42;

    matrix3x4f matrix34;
    matrix3x3f matrix33;
    matrix3x2f matrix32;

    matrix2x4f matrix24;
    matrix2x3f matrix23;
    matrix2x2f matrix22;
};

int main()
{
    return run_tests(matrix_access_test());
}
