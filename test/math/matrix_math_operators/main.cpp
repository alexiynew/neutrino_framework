
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

using framework::math::Matrix2x2f;
using framework::math::Matrix2x3f;
using framework::math::Matrix2x4f;
using framework::math::Matrix3x2f;
using framework::math::Matrix3x3f;
using framework::math::Matrix3x4f;
using framework::math::Matrix4x2f;
using framework::math::Matrix4x3f;
using framework::math::Matrix4x4f;

using framework::math::Vector2f;
using framework::math::Vector3f;
using framework::math::Vector4f;

class MatrixOperatorsTest : public framework::unit_test::Suite
{
public:
    MatrixOperatorsTest()
        : Suite("MatrixOperatorsTest")
    {
        add_test([this]() { unary_minus_operator(); }, "unary_minus_operator");
        add_test([this]() { unary_plus_operator(); }, "unary_plus_operator");
        add_test([this]() { add_assign_operator(); }, "add_assign_operator");
        add_test([this]() { subtract_assign_operator(); }, "subtract_assign_operator");
        add_test([this]() { multiplies_assign_operator(); }, "multiplies_assign_operator");
        add_test([this]() { divides_assign_operator(); }, "divides_assign_operator");
        add_test([this]() { add_operator(); }, "add_operator");
        add_test([this]() { subtract_operator(); }, "subtract_operator");
        add_test([this]() { multiply_with_scalar_operator(); }, "multiply_with_scalar_operator");
        add_test([this]() { multiply_with_vector_operator(); }, "multiply_with_vector_operator");
        add_test([this]() { multiply_with_matrix_operator(); }, "multiply_with_matrix_operator");
        add_test([this]() { divide_operator(); }, "divide_operator");
    }

private:
    void unary_minus_operator()
    {
        TEST_ASSERT(-Matrix44 == Matrix4x4f(-1), "Matrix4x4 unary subtract failed.");
        TEST_ASSERT(-Matrix43 == Matrix4x3f(-1), "Matrix4x3 unary subtract failed.");
        TEST_ASSERT(-Matrix42 == Matrix4x2f(-1), "Matrix4x2 unary subtract failed.");
        TEST_ASSERT(-Matrix34 == Matrix3x4f(-1), "Matrix3x4 unary subtract failed.");
        TEST_ASSERT(-Matrix33 == Matrix3x3f(-1), "Matrix3x3 unary subtract failed.");
        TEST_ASSERT(-Matrix32 == Matrix3x2f(-1), "Matrix3x2 unary subtract failed.");
        TEST_ASSERT(-Matrix24 == Matrix2x4f(-1), "Matrix2x4 unary subtract failed.");
        TEST_ASSERT(-Matrix23 == Matrix2x3f(-1), "Matrix2x3 unary subtract failed.");
        TEST_ASSERT(-Matrix22 == Matrix2x2f(-1), "Matrix2x2 unary subtract failed.");
    }

    void unary_plus_operator()
    {
        TEST_ASSERT(+Matrix44 == Matrix4x4f(1), "Matrix4x4 unary add operator failed.");
        TEST_ASSERT(+Matrix43 == Matrix4x3f(1), "Matrix4x3 unary add operator failed.");
        TEST_ASSERT(+Matrix42 == Matrix4x2f(1), "Matrix4x2 unary add operator failed.");
        TEST_ASSERT(+Matrix34 == Matrix3x4f(1), "Matrix3x4 unary add operator failed.");
        TEST_ASSERT(+Matrix33 == Matrix3x3f(1), "Matrix3x3 unary add operator failed.");
        TEST_ASSERT(+Matrix32 == Matrix3x2f(1), "Matrix3x2 unary add operator failed.");
        TEST_ASSERT(+Matrix24 == Matrix2x4f(1), "Matrix2x4 unary add operator failed.");
        TEST_ASSERT(+Matrix23 == Matrix2x3f(1), "Matrix2x3 unary add operator failed.");
        TEST_ASSERT(+Matrix22 == Matrix2x2f(1), "Matrix2x2 unary add operator failed.");
    }

    void add_assign_operator()
    {
        Matrix4x4f temp44;
        Matrix4x3f temp43;
        Matrix4x2f temp42;
        Matrix3x4f temp34;
        Matrix3x3f temp33;
        Matrix3x2f temp32;
        Matrix2x4f temp24;
        Matrix2x3f temp23;
        Matrix2x2f temp22;

        temp44 += Matrix44;
        temp43 += Matrix43;
        temp42 += Matrix42;
        temp34 += Matrix34;
        temp33 += Matrix33;
        temp32 += Matrix32;
        temp24 += Matrix24;
        temp23 += Matrix23;
        temp22 += Matrix22;

        TEST_ASSERT(temp44 == Matrix4x4f(2), "Matrix4x4 add_assign operator failed.");
        TEST_ASSERT(temp43 == Matrix4x3f(2), "Matrix4x3 add_assign operator failed.");
        TEST_ASSERT(temp42 == Matrix4x2f(2), "Matrix4x2 add_assign operator failed.");
        TEST_ASSERT(temp34 == Matrix3x4f(2), "Matrix3x4 add_assign operator failed.");
        TEST_ASSERT(temp33 == Matrix3x3f(2), "Matrix3x3 add_assign operator failed.");
        TEST_ASSERT(temp32 == Matrix3x2f(2), "Matrix3x2 add_assign operator failed.");
        TEST_ASSERT(temp24 == Matrix2x4f(2), "Matrix2x4 add_assign operator failed.");
        TEST_ASSERT(temp23 == Matrix2x3f(2), "Matrix2x3 add_assign operator failed.");
        TEST_ASSERT(temp22 == Matrix2x2f(2), "Matrix2x2 add_assign operator failed.");

        temp44 += 1;
        temp43 += 1;
        temp42 += 1;
        temp34 += 1;
        temp33 += 1;
        temp32 += 1;
        temp24 += 1;
        temp23 += 1;
        temp22 += 1;

        const Matrix4x4f result44 = {3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3};
        const Matrix4x3f result43 = {3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1};
        const Matrix4x2f result42 = {3, 1, 1, 3, 1, 1, 1, 1};
        const Matrix3x4f result34 = {3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1};
        const Matrix3x3f result33 = {3, 1, 1, 1, 3, 1, 1, 1, 3};
        const Matrix3x2f result32 = {3, 1, 1, 3, 1, 1};
        const Matrix2x4f result24 = {3, 1, 1, 1, 1, 3, 1, 1};
        const Matrix2x3f result23 = {3, 1, 1, 1, 3, 1};
        const Matrix2x2f result22 = {3, 1, 1, 3};

        TEST_ASSERT(temp44 == result44, "Matrix4x4 add_assign operator failed.");
        TEST_ASSERT(temp43 == result43, "Matrix4x3 add_assign operator failed.");
        TEST_ASSERT(temp42 == result42, "Matrix4x2 add_assign operator failed.");
        TEST_ASSERT(temp34 == result34, "Matrix3x4 add_assign operator failed.");
        TEST_ASSERT(temp33 == result33, "Matrix3x3 add_assign operator failed.");
        TEST_ASSERT(temp32 == result32, "Matrix3x2 add_assign operator failed.");
        TEST_ASSERT(temp24 == result24, "Matrix2x4 add_assign operator failed.");
        TEST_ASSERT(temp23 == result23, "Matrix2x3 add_assign operator failed.");
        TEST_ASSERT(temp22 == result22, "Matrix2x2 add_assign operator failed.");
    }

    void subtract_assign_operator()
    {
        Matrix4x4f temp44(2);
        Matrix4x3f temp43(2);
        Matrix4x2f temp42(2);
        Matrix3x4f temp34(2);
        Matrix3x3f temp33(2);
        Matrix3x2f temp32(2);
        Matrix2x4f temp24(2);
        Matrix2x3f temp23(2);
        Matrix2x2f temp22(2);

        temp44 -= Matrix44;
        temp43 -= Matrix43;
        temp42 -= Matrix42;
        temp34 -= Matrix34;
        temp33 -= Matrix33;
        temp32 -= Matrix32;
        temp24 -= Matrix24;
        temp23 -= Matrix23;
        temp22 -= Matrix22;

        TEST_ASSERT(temp44 == Matrix44, "Matrix4x4 subtract_assign operator failed.");
        TEST_ASSERT(temp43 == Matrix43, "Matrix4x3 subtract_assign operator failed.");
        TEST_ASSERT(temp42 == Matrix42, "Matrix4x2 subtract_assign operator failed.");
        TEST_ASSERT(temp34 == Matrix34, "Matrix3x4 subtract_assign operator failed.");
        TEST_ASSERT(temp33 == Matrix33, "Matrix3x3 subtract_assign operator failed.");
        TEST_ASSERT(temp32 == Matrix32, "Matrix3x2 subtract_assign operator failed.");
        TEST_ASSERT(temp24 == Matrix24, "Matrix2x4 subtract_assign operator failed.");
        TEST_ASSERT(temp23 == Matrix23, "Matrix2x3 subtract_assign operator failed.");
        TEST_ASSERT(temp22 == Matrix22, "Matrix2x2 subtract_assign operator failed.");

        temp44 -= 1;
        temp43 -= 1;
        temp42 -= 1;
        temp34 -= 1;
        temp33 -= 1;
        temp32 -= 1;
        temp24 -= 1;
        temp23 -= 1;
        temp22 -= 1;

        const Matrix4x4f result44 = {0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0};
        const Matrix4x3f result43 = {0, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, -1};
        const Matrix4x2f result42 = {0, -1, -1, 0, -1, -1, -1, -1};
        const Matrix3x4f result34 = {0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, -1};
        const Matrix3x3f result33 = {0, -1, -1, -1, 0, -1, -1, -1, 0};
        const Matrix3x2f result32 = {0, -1, -1, 0, -1, -1};
        const Matrix2x4f result24 = {0, -1, -1, -1, -1, 0, -1, -1};
        const Matrix2x3f result23 = {0, -1, -1, -1, 0, -1};
        const Matrix2x2f result22 = {0, -1, -1, 0};

        TEST_ASSERT(temp44 == result44, "Matrix4x4 subtract_assign operator failed.");
        TEST_ASSERT(temp43 == result43, "Matrix4x3 subtract_assign operator failed.");
        TEST_ASSERT(temp42 == result42, "Matrix4x2 subtract_assign operator failed.");
        TEST_ASSERT(temp34 == result34, "Matrix3x4 subtract_assign operator failed.");
        TEST_ASSERT(temp33 == result33, "Matrix3x3 subtract_assign operator failed.");
        TEST_ASSERT(temp32 == result32, "Matrix3x2 subtract_assign operator failed.");
        TEST_ASSERT(temp24 == result24, "Matrix2x4 subtract_assign operator failed.");
        TEST_ASSERT(temp23 == result23, "Matrix2x3 subtract_assign operator failed.");
        TEST_ASSERT(temp22 == result22, "Matrix2x2 subtract_assign operator failed.");
    }

    void multiplies_assign_operator()
    {
        Matrix4x4f temp44(2);
        Matrix4x3f temp43(2);
        Matrix4x2f temp42(2);
        Matrix3x4f temp34(2);
        Matrix3x3f temp33(2);
        Matrix3x2f temp32(2);
        Matrix2x4f temp24(2);
        Matrix2x3f temp23(2);
        Matrix2x2f temp22(2);

        temp44 *= Matrix4x4f(2);
        temp43 *= Matrix4x4f(2);
        temp42 *= Matrix4x4f(2);
        temp34 *= Matrix3x3f(2);
        temp33 *= Matrix3x3f(2);
        temp32 *= Matrix3x3f(2);
        temp24 *= Matrix2x2f(2);
        temp23 *= Matrix2x2f(2);
        temp22 *= Matrix2x2f(2);

        TEST_ASSERT(temp44 == Matrix4x4f(4), "Matrix4x4 multiplies_assign operator failed.");
        TEST_ASSERT(temp43 == Matrix4x3f(4), "Matrix4x3 multiplies_assign operator failed.");
        TEST_ASSERT(temp42 == Matrix4x2f(4), "Matrix4x2 multiplies_assign operator failed.");
        TEST_ASSERT(temp34 == Matrix3x4f(4), "Matrix3x4 multiplies_assign operator failed.");
        TEST_ASSERT(temp33 == Matrix3x3f(4), "Matrix3x3 multiplies_assign operator failed.");
        TEST_ASSERT(temp32 == Matrix3x2f(4), "Matrix3x2 multiplies_assign operator failed.");
        TEST_ASSERT(temp24 == Matrix2x4f(4), "Matrix2x4 multiplies_assign operator failed.");
        TEST_ASSERT(temp23 == Matrix2x3f(4), "Matrix2x3 multiplies_assign operator failed.");
        TEST_ASSERT(temp22 == Matrix2x2f(4), "Matrix2x2 multiplies_assign operator failed.");

        temp44 *= 10;
        temp43 *= 10;
        temp42 *= 10;
        temp34 *= 10;
        temp33 *= 10;
        temp32 *= 10;
        temp24 *= 10;
        temp23 *= 10;
        temp22 *= 10;

        TEST_ASSERT(temp44 == Matrix4x4f(40), "Matrix4x4 multiplies_assign operator failed.");
        TEST_ASSERT(temp43 == Matrix4x3f(40), "Matrix4x3 multiplies_assign operator failed.");
        TEST_ASSERT(temp42 == Matrix4x2f(40), "Matrix4x2 multiplies_assign operator failed.");
        TEST_ASSERT(temp34 == Matrix3x4f(40), "Matrix3x4 multiplies_assign operator failed.");
        TEST_ASSERT(temp33 == Matrix3x3f(40), "Matrix3x3 multiplies_assign operator failed.");
        TEST_ASSERT(temp32 == Matrix3x2f(40), "Matrix3x2 multiplies_assign operator failed.");
        TEST_ASSERT(temp24 == Matrix2x4f(40), "Matrix2x4 multiplies_assign operator failed.");
        TEST_ASSERT(temp23 == Matrix2x3f(40), "Matrix2x3 multiplies_assign operator failed.");
        TEST_ASSERT(temp22 == Matrix2x2f(40), "Matrix2x2 multiplies_assign operator failed.");
    }

    void divides_assign_operator()
    {
        Matrix4x4f temp44(20);
        Matrix4x3f temp43(20);
        Matrix4x2f temp42(20);
        Matrix3x4f temp34(20);
        Matrix3x3f temp33(20);
        Matrix3x2f temp32(20);
        Matrix2x4f temp24(20);
        Matrix2x3f temp23(20);
        Matrix2x2f temp22(20);

        temp44 /= 10;
        temp43 /= 10;
        temp42 /= 10;
        temp34 /= 10;
        temp33 /= 10;
        temp32 /= 10;
        temp24 /= 10;
        temp23 /= 10;
        temp22 /= 10;

        TEST_ASSERT(temp44 == Matrix4x4f(2), "Matrix4x4 divides_assign operator failed.");
        TEST_ASSERT(temp43 == Matrix4x3f(2), "Matrix4x3 divides_assign operator failed.");
        TEST_ASSERT(temp42 == Matrix4x2f(2), "Matrix4x2 divides_assign operator failed.");
        TEST_ASSERT(temp34 == Matrix3x4f(2), "Matrix3x4 divides_assign operator failed.");
        TEST_ASSERT(temp33 == Matrix3x3f(2), "Matrix3x3 divides_assign operator failed.");
        TEST_ASSERT(temp32 == Matrix3x2f(2), "Matrix3x2 divides_assign operator failed.");
        TEST_ASSERT(temp24 == Matrix2x4f(2), "Matrix2x4 divides_assign operator failed.");
        TEST_ASSERT(temp23 == Matrix2x3f(2), "Matrix2x3 divides_assign operator failed.");
        TEST_ASSERT(temp22 == Matrix2x2f(2), "Matrix2x2 divides_assign operator failed.");
    }

    void add_operator()
    {
        const Matrix4x4f temp44 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix4x3f temp43 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix4x2f temp42 = {1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x4f temp34 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x3f temp33 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x2f temp32 = {1, 1, 1, 1, 1, 1};
        const Matrix2x4f temp24 = {1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix2x3f temp23 = {1, 1, 1, 1, 1, 1};
        const Matrix2x2f temp22 = {1, 1, 1, 1};

        const Matrix4x4f result44 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix4x3f result43 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix4x2f result42 = {2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x4f result34 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x3f result33 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x2f result32 = {2, 2, 2, 2, 2, 2};
        const Matrix2x4f result24 = {2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix2x3f result23 = {2, 2, 2, 2, 2, 2};
        const Matrix2x2f result22 = {2, 2, 2, 2};

        TEST_ASSERT(temp44 + 1.0f == result44, "Matrix4x4 add operator failed.");
        TEST_ASSERT(temp43 + 1.0f == result43, "Matrix4x3 add operator failed.");
        TEST_ASSERT(temp42 + 1.0f == result42, "Matrix4x2 add operator failed.");
        TEST_ASSERT(temp34 + 1.0f == result34, "Matrix3x4 add operator failed.");
        TEST_ASSERT(temp33 + 1.0f == result33, "Matrix3x3 add operator failed.");
        TEST_ASSERT(temp32 + 1.0f == result32, "Matrix3x2 add operator failed.");
        TEST_ASSERT(temp24 + 1.0f == result24, "Matrix2x4 add operator failed.");
        TEST_ASSERT(temp23 + 1.0f == result23, "Matrix2x3 add operator failed.");
        TEST_ASSERT(temp22 + 1.0f == result22, "Matrix2x2 add operator failed.");

        TEST_ASSERT(1.0f + temp44 == result44, "Matrix4x4 add operator failed.");
        TEST_ASSERT(1.0f + temp43 == result43, "Matrix4x3 add operator failed.");
        TEST_ASSERT(1.0f + temp42 == result42, "Matrix4x2 add operator failed.");
        TEST_ASSERT(1.0f + temp34 == result34, "Matrix3x4 add operator failed.");
        TEST_ASSERT(1.0f + temp33 == result33, "Matrix3x3 add operator failed.");
        TEST_ASSERT(1.0f + temp32 == result32, "Matrix3x2 add operator failed.");
        TEST_ASSERT(1.0f + temp24 == result24, "Matrix2x4 add operator failed.");
        TEST_ASSERT(1.0f + temp23 == result23, "Matrix2x3 add operator failed.");
        TEST_ASSERT(1.0f + temp22 == result22, "Matrix2x2 add operator failed.");

        TEST_ASSERT(temp44 + temp44 == result44, "Matrix4x4 add operator failed.");
        TEST_ASSERT(temp43 + temp43 == result43, "Matrix4x3 add operator failed.");
        TEST_ASSERT(temp42 + temp42 == result42, "Matrix4x2 add operator failed.");
        TEST_ASSERT(temp34 + temp34 == result34, "Matrix3x4 add operator failed.");
        TEST_ASSERT(temp33 + temp33 == result33, "Matrix3x3 add operator failed.");
        TEST_ASSERT(temp32 + temp32 == result32, "Matrix3x2 add operator failed.");
        TEST_ASSERT(temp24 + temp24 == result24, "Matrix2x4 add operator failed.");
        TEST_ASSERT(temp23 + temp23 == result23, "Matrix2x3 add operator failed.");
        TEST_ASSERT(temp22 + temp22 == result22, "Matrix2x2 add operator failed.");
    }

    void subtract_operator()
    {
        const Matrix4x4f temp44 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix4x3f temp43 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix4x2f temp42 = {2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x4f temp34 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x3f temp33 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x2f temp32 = {2, 2, 2, 2, 2, 2};
        const Matrix2x4f temp24 = {2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix2x3f temp23 = {2, 2, 2, 2, 2, 2};
        const Matrix2x2f temp22 = {2, 2, 2, 2};

        const Matrix4x4f result44 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix4x3f result43 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix4x2f result42 = {1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x4f result34 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x3f result33 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x2f result32 = {1, 1, 1, 1, 1, 1};
        const Matrix2x4f result24 = {1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix2x3f result23 = {1, 1, 1, 1, 1, 1};
        const Matrix2x2f result22 = {1, 1, 1, 1};

        TEST_ASSERT(temp44 - 1.0f == result44, "Matrix4x4 subtract operator failed.");
        TEST_ASSERT(temp43 - 1.0f == result43, "Matrix4x3 subtract operator failed.");
        TEST_ASSERT(temp42 - 1.0f == result42, "Matrix4x2 subtract operator failed.");
        TEST_ASSERT(temp34 - 1.0f == result34, "Matrix3x4 subtract operator failed.");
        TEST_ASSERT(temp33 - 1.0f == result33, "Matrix3x3 subtract operator failed.");
        TEST_ASSERT(temp32 - 1.0f == result32, "Matrix3x2 subtract operator failed.");
        TEST_ASSERT(temp24 - 1.0f == result24, "Matrix2x4 subtract operator failed.");
        TEST_ASSERT(temp23 - 1.0f == result23, "Matrix2x3 subtract operator failed.");
        TEST_ASSERT(temp22 - 1.0f == result22, "Matrix2x2 subtract operator failed.");

        TEST_ASSERT(2.0f - temp44 == Matrix4x4f(0), "Matrix4x4 subtract operator failed.");
        TEST_ASSERT(2.0f - temp43 == Matrix4x3f(0), "Matrix4x3 subtract operator failed.");
        TEST_ASSERT(2.0f - temp42 == Matrix4x2f(0), "Matrix4x2 subtract operator failed.");
        TEST_ASSERT(2.0f - temp34 == Matrix3x4f(0), "Matrix3x4 subtract operator failed.");
        TEST_ASSERT(2.0f - temp33 == Matrix3x3f(0), "Matrix3x3 subtract operator failed.");
        TEST_ASSERT(2.0f - temp32 == Matrix3x2f(0), "Matrix3x2 subtract operator failed.");
        TEST_ASSERT(2.0f - temp24 == Matrix2x4f(0), "Matrix2x4 subtract operator failed.");
        TEST_ASSERT(2.0f - temp23 == Matrix2x3f(0), "Matrix2x3 subtract operator failed.");
        TEST_ASSERT(2.0f - temp22 == Matrix2x2f(0), "Matrix2x2 subtract operator failed.");

        TEST_ASSERT(temp44 - temp44 == Matrix4x4f(0), "Matrix4x4 subtract operator failed.");
        TEST_ASSERT(temp43 - temp43 == Matrix4x3f(0), "Matrix4x3 subtract operator failed.");
        TEST_ASSERT(temp42 - temp42 == Matrix4x2f(0), "Matrix4x2 subtract operator failed.");
        TEST_ASSERT(temp34 - temp34 == Matrix3x4f(0), "Matrix3x4 subtract operator failed.");
        TEST_ASSERT(temp33 - temp33 == Matrix3x3f(0), "Matrix3x3 subtract operator failed.");
        TEST_ASSERT(temp32 - temp32 == Matrix3x2f(0), "Matrix3x2 subtract operator failed.");
        TEST_ASSERT(temp24 - temp24 == Matrix2x4f(0), "Matrix2x4 subtract operator failed.");
        TEST_ASSERT(temp23 - temp23 == Matrix2x3f(0), "Matrix2x3 subtract operator failed.");
        TEST_ASSERT(temp22 - temp22 == Matrix2x2f(0), "Matrix2x2 subtract operator failed.");
    }

    void multiply_with_scalar_operator()
    {
        const Matrix4x4f temp44 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix4x3f temp43 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix4x2f temp42 = {1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x4f temp34 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x3f temp33 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix3x2f temp32 = {1, 1, 1, 1, 1, 1};
        const Matrix2x4f temp24 = {1, 1, 1, 1, 1, 1, 1, 1};
        const Matrix2x3f temp23 = {1, 1, 1, 1, 1, 1};
        const Matrix2x2f temp22 = {1, 1, 1, 1};

        const Matrix4x4f result44 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix4x3f result43 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix4x2f result42 = {2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x4f result34 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x3f result33 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix3x2f result32 = {2, 2, 2, 2, 2, 2};
        const Matrix2x4f result24 = {2, 2, 2, 2, 2, 2, 2, 2};
        const Matrix2x3f result23 = {2, 2, 2, 2, 2, 2};
        const Matrix2x2f result22 = {2, 2, 2, 2};

        TEST_ASSERT(temp44 * 2.0f == result44, "Matrix4x4 multiply with scalar operator failed.");
        TEST_ASSERT(temp43 * 2.0f == result43, "Matrix4x3 multiply with scalar operator failed.");
        TEST_ASSERT(temp42 * 2.0f == result42, "Matrix4x2 multiply with scalar operator failed.");
        TEST_ASSERT(temp34 * 2.0f == result34, "Matrix3x4 multiply with scalar operator failed.");
        TEST_ASSERT(temp33 * 2.0f == result33, "Matrix3x3 multiply with scalar operator failed.");
        TEST_ASSERT(temp32 * 2.0f == result32, "Matrix3x2 multiply with scalar operator failed.");
        TEST_ASSERT(temp24 * 2.0f == result24, "Matrix2x4 multiply with scalar operator failed.");
        TEST_ASSERT(temp23 * 2.0f == result23, "Matrix2x3 multiply with scalar operator failed.");
        TEST_ASSERT(temp22 * 2.0f == result22, "Matrix2x2 multiply with scalar operator failed.");

        TEST_ASSERT(2.0f * temp44 == result44, "Matrix4x4 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp43 == result43, "Matrix4x3 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp42 == result42, "Matrix4x2 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp34 == result34, "Matrix3x4 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp33 == result33, "Matrix3x3 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp32 == result32, "Matrix3x2 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp24 == result24, "Matrix2x4 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp23 == result23, "Matrix2x3 multiply with scalar operator failed.");
        TEST_ASSERT(2.0f * temp22 == result22, "Matrix2x2 multiply with scalar operator failed.");
    }

    void multiply_with_vector_operator()
    {
        // clang-format off
        Matrix4x4f temp44 = {
            1, 2, 3, 4,
            1, 2, 3, 4,
            1, 2, 3, 4,
            1, 2, 3, 4
        };
        // clang-format on

        Matrix4x3f temp43(temp44);
        Matrix4x2f temp42(temp44);
        Matrix3x4f temp34(temp44);
        Matrix3x3f temp33(temp44);
        Matrix3x2f temp32(temp44);
        Matrix2x4f temp24(temp44);
        Matrix2x3f temp23(temp44);
        Matrix2x2f temp22(temp44);

        Vector4f vector4(1, 2, 3, 4);
        Vector3f vector3(1, 2, 3);
        Vector2f vector2(1, 2);

        TEST_ASSERT(vector4 * temp44 == Vector4f(30, 30, 30, 30), "Matrix4x4 multiply with vector operator failed.");
        TEST_ASSERT(vector3 * temp43 == Vector4f(14, 14, 14, 14), "Matrix4x3 multiply with vector operator failed.");
        TEST_ASSERT(vector2 * temp42 == Vector4f(5, 5, 5, 5), "Matrix4x2 multiply with vector operator failed.");

        TEST_ASSERT(vector4 * temp34 == Vector3f(30, 30, 30), "Matrix3x4 multiply with vector operator failed.");
        TEST_ASSERT(vector3 * temp33 == Vector3f(14, 14, 14), "Matrix3x3 multiply with vector operator failed.");
        TEST_ASSERT(vector2 * temp32 == Vector3f(5, 5, 5), "Matrix3x2 multiply with vector operator failed.");

        TEST_ASSERT(vector4 * temp24 == Vector2f(30, 30), "Matrix2x4 multiply with vector operator failed.");
        TEST_ASSERT(vector3 * temp23 == Vector2f(14, 14), "Matrix2x3 multiply with vector operator failed.");
        TEST_ASSERT(vector2 * temp22 == Vector2f(5, 5), "Matrix2x2 multiply with vector operator failed.");

        TEST_ASSERT(temp44 * vector4 == Vector4f(10, 20, 30, 40), "Matrix4x4 multiply with vector operator failed.");
        TEST_ASSERT(temp43 * vector4 == Vector3f(10, 20, 30), "Matrix4x3 multiply with vector operator failed.");
        TEST_ASSERT(temp42 * vector4 == Vector2f(10, 20), "Matrix4x2 multiply with vector operator failed.");

        TEST_ASSERT(temp34 * vector3 == Vector4f(6, 12, 18, 24), "Matrix3x4 multiply with vector operator failed.");
        TEST_ASSERT(temp33 * vector3 == Vector3f(6, 12, 18), "Matrix3x3 multiply with vector operator failed.");
        TEST_ASSERT(temp32 * vector3 == Vector2f(6, 12), "Matrix3x2 multiply with vector operator failed.");

        TEST_ASSERT(temp24 * vector2 == Vector4f(3, 6, 9, 12), "Matrix2x4 multiply with vector operator failed.");
        TEST_ASSERT(temp23 * vector2 == Vector3f(3, 6, 9), "Matrix2x3 multiply with vector operator failed.");
        TEST_ASSERT(temp22 * vector2 == Vector2f(3, 6), "Matrix2x2 multiply with vector operator failed.");
    }

    void multiply_with_matrix_operator()
    {
        const Matrix4x4f temp44 = {1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1};
        const Matrix4x3f temp43 = {1, 2, 3, 3, 1, 2, 2, 3, 1, 1, 2, 3};
        const Matrix4x2f temp42 = {1, 2, 2, 1, 1, 2, 2, 1};
        const Matrix3x4f temp34 = {1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2};
        const Matrix3x3f temp33 = {1, 2, 3, 3, 1, 2, 2, 3, 1};
        const Matrix3x2f temp32 = {1, 2, 2, 1, 1, 2};
        const Matrix2x4f temp24 = {1, 2, 3, 4, 4, 1, 2, 3};
        const Matrix2x3f temp23 = {1, 2, 3, 3, 1, 2};
        const Matrix2x2f temp22 = {1, 2, 2, 1};

        const Matrix4x4f result44x44 = {26, 28, 26, 20, 20, 26, 28, 26, 26, 20, 26, 28, 28, 26, 20, 26};
        const Matrix3x4f result44x34 = {26, 28, 26, 20, 20, 26, 28, 26, 26, 20, 26, 28};
        const Matrix2x4f result44x24 = {26, 28, 26, 20, 20, 26, 28, 26};

        const Matrix4x3f result43x44 = {17, 21, 22, 14, 21, 25, 19, 17, 24, 20, 21, 19};
        const Matrix3x3f result43x34 = {17, 21, 22, 14, 21, 25, 19, 17, 24};
        const Matrix2x3f result43x24 = {17, 21, 22, 14, 21, 25};

        const Matrix4x2f result42x44 = {16, 14, 14, 16, 16, 14, 14, 16};
        const Matrix3x2f result42x34 = {16, 14, 14, 16, 16, 14};
        const Matrix2x2f result42x24 = {16, 14, 14, 16};

        const Matrix4x4f result34x43 = {18, 16, 10, 16, 13, 15, 13, 19, 17, 11, 13, 19, 18, 16, 10, 16};
        const Matrix3x4f result34x33 = {18, 16, 10, 16, 13, 15, 13, 19, 17, 11, 13, 19};
        const Matrix2x4f result34x23 = {18, 16, 10, 16, 13, 15, 13, 19};

        const Matrix4x3f result33x43 = {13, 13, 10, 10, 13, 13, 13, 10, 13, 13, 13, 10};
        const Matrix3x3f result33x33 = {13, 13, 10, 10, 13, 13, 13, 10, 13};
        const Matrix2x3f result33x23 = {13, 13, 10, 10, 13, 13};

        const Matrix4x2f result32x43 = {8, 10, 7, 11, 9, 9, 8, 10};
        const Matrix3x2f result32x33 = {8, 10, 7, 11, 9, 9};
        const Matrix2x2f result32x23 = {8, 10, 7, 11};

        const Matrix4x4f result24x42 = {9, 4, 7, 10, 6, 5, 8, 11, 9, 4, 7, 10, 6, 5, 8, 11};
        const Matrix3x4f result24x32 = {9, 4, 7, 10, 6, 5, 8, 11, 9, 4, 7, 10};
        const Matrix2x4f result24x22 = {9, 4, 7, 10, 6, 5, 8, 11};

        const Matrix4x3f result23x42 = {7, 4, 7, 5, 5, 8, 7, 4, 7, 5, 5, 8};
        const Matrix3x3f result23x32 = {7, 4, 7, 5, 5, 8, 7, 4, 7};
        const Matrix2x3f result23x22 = {7, 4, 7, 5, 5, 8};

        const Matrix4x2f result22x42 = {5, 4, 4, 5, 5, 4, 4, 5};
        const Matrix3x2f result22x32 = {5, 4, 4, 5, 5, 4};
        const Matrix2x2f result22x22 = {5, 4, 4, 5};

        TEST_ASSERT(temp44 * temp44 == result44x44, "Matrix4x4 multiply with matrix operator failed.");
        TEST_ASSERT(temp44 * temp34 == result44x34, "Matrix4x4 multiply with matrix operator failed.");
        TEST_ASSERT(temp44 * temp24 == result44x24, "Matrix4x4 multiply with matrix operator failed.");

        TEST_ASSERT(temp43 * temp44 == result43x44, "Matrix4x3 multiply with matrix operator failed.");
        TEST_ASSERT(temp43 * temp34 == result43x34, "Matrix4x3 multiply with matrix operator failed.");
        TEST_ASSERT(temp43 * temp24 == result43x24, "Matrix4x3 multiply with matrix operator failed.");

        TEST_ASSERT(temp42 * temp44 == result42x44, "Matrix4x2 multiply with matrix operator failed.");
        TEST_ASSERT(temp42 * temp34 == result42x34, "Matrix4x2 multiply with matrix operator failed.");
        TEST_ASSERT(temp42 * temp24 == result42x24, "Matrix4x2 multiply with matrix operator failed.");

        TEST_ASSERT(temp34 * temp43 == result34x43, "Matrix3x4 multiply with matrix operator failed.");
        TEST_ASSERT(temp34 * temp33 == result34x33, "Matrix3x4 multiply with matrix operator failed.");
        TEST_ASSERT(temp34 * temp23 == result34x23, "Matrix3x4 multiply with matrix operator failed.");

        TEST_ASSERT(temp33 * temp43 == result33x43, "Matrix3x3 multiply with matrix operator failed.");
        TEST_ASSERT(temp33 * temp33 == result33x33, "Matrix3x3 multiply with matrix operator failed.");
        TEST_ASSERT(temp33 * temp23 == result33x23, "Matrix3x3 multiply with matrix operator failed.");

        TEST_ASSERT(temp32 * temp43 == result32x43, "Matrix3x2 multiply with matrix operator failed.");
        TEST_ASSERT(temp32 * temp33 == result32x33, "Matrix3x2 multiply with matrix operator failed.");
        TEST_ASSERT(temp32 * temp23 == result32x23, "Matrix3x2 multiply with matrix operator failed.");

        TEST_ASSERT(temp24 * temp42 == result24x42, "Matrix2x4 multiply with matrix operator failed.");
        TEST_ASSERT(temp24 * temp32 == result24x32, "Matrix2x4 multiply with matrix operator failed.");
        TEST_ASSERT(temp24 * temp22 == result24x22, "Matrix2x4 multiply with matrix operator failed.");

        TEST_ASSERT(temp23 * temp42 == result23x42, "Matrix2x3 multiply with matrix operator failed.");
        TEST_ASSERT(temp23 * temp32 == result23x32, "Matrix2x3 multiply with matrix operator failed.");
        TEST_ASSERT(temp23 * temp22 == result23x22, "Matrix2x3 multiply with matrix operator failed.");

        TEST_ASSERT(temp22 * temp42 == result22x42, "Matrix2x2 multiply with matrix operator failed.");
        TEST_ASSERT(temp22 * temp32 == result22x32, "Matrix2x2 multiply with matrix operator failed.");
        TEST_ASSERT(temp22 * temp22 == result22x22, "Matrix2x2 multiply with matrix operator failed.");
    }

    void divide_operator()
    {
        const Matrix4x4f temp44 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        const Matrix4x3f temp43 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        const Matrix4x2f temp42 = {10, 10, 10, 10, 10, 10, 10, 10};
        const Matrix3x4f temp34 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        const Matrix3x3f temp33 = {10, 10, 10, 10, 10, 10, 10, 10, 10};
        const Matrix3x2f temp32 = {10, 10, 10, 10, 10, 10};
        const Matrix2x4f temp24 = {10, 10, 10, 10, 10, 10, 10, 10};
        const Matrix2x3f temp23 = {10, 10, 10, 10, 10, 10};
        const Matrix2x2f temp22 = {10, 10, 10, 10};

        const Matrix4x4f result44 = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
        const Matrix4x3f result43 = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
        const Matrix4x2f result42 = {5, 5, 5, 5, 5, 5, 5, 5};
        const Matrix3x4f result34 = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
        const Matrix3x3f result33 = {5, 5, 5, 5, 5, 5, 5, 5, 5};
        const Matrix3x2f result32 = {5, 5, 5, 5, 5, 5};
        const Matrix2x4f result24 = {5, 5, 5, 5, 5, 5, 5, 5};
        const Matrix2x3f result23 = {5, 5, 5, 5, 5, 5};
        const Matrix2x2f result22 = {5, 5, 5, 5};

        TEST_ASSERT(temp44 / 2.0f == result44, "Matrix4x4 divide operator failed.");
        TEST_ASSERT(temp43 / 2.0f == result43, "Matrix4x3 divide operator failed.");
        TEST_ASSERT(temp42 / 2.0f == result42, "Matrix4x2 divide operator failed.");
        TEST_ASSERT(temp34 / 2.0f == result34, "Matrix3x4 divide operator failed.");
        TEST_ASSERT(temp33 / 2.0f == result33, "Matrix3x3 divide operator failed.");
        TEST_ASSERT(temp32 / 2.0f == result32, "Matrix3x2 divide operator failed.");
        TEST_ASSERT(temp24 / 2.0f == result24, "Matrix2x4 divide operator failed.");
        TEST_ASSERT(temp23 / 2.0f == result23, "Matrix2x3 divide operator failed.");
        TEST_ASSERT(temp22 / 2.0f == result22, "Matrix2x2 divide operator failed.");

        TEST_ASSERT(50.0f / temp44 == result44, "Matrix4x4 divide operator failed.");
        TEST_ASSERT(50.0f / temp43 == result43, "Matrix4x3 divide operator failed.");
        TEST_ASSERT(50.0f / temp42 == result42, "Matrix4x2 divide operator failed.");
        TEST_ASSERT(50.0f / temp34 == result34, "Matrix3x4 divide operator failed.");
        TEST_ASSERT(50.0f / temp33 == result33, "Matrix3x3 divide operator failed.");
        TEST_ASSERT(50.0f / temp32 == result32, "Matrix3x2 divide operator failed.");
        TEST_ASSERT(50.0f / temp24 == result24, "Matrix2x4 divide operator failed.");
        TEST_ASSERT(50.0f / temp23 == result23, "Matrix2x3 divide operator failed.");
        TEST_ASSERT(50.0f / temp22 == result22, "Matrix2x2 divide operator failed.");
    }

    const Matrix4x4f Matrix44;
    const Matrix4x3f Matrix43;
    const Matrix4x2f Matrix42;
    const Matrix3x4f Matrix34;
    const Matrix3x3f Matrix33;
    const Matrix3x2f Matrix32;
    const Matrix2x4f Matrix24;
    const Matrix2x3f Matrix23;
    const Matrix2x2f Matrix22;
};

int main()
{
    return run_tests(MatrixOperatorsTest());
}
