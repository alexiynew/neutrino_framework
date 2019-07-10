/// @file
/// @brief Contains matrix functions.
/// @author Fedorov Alexey
/// @date 05.07.2017

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

#ifndef FRAMEWORK_MATH_DETAILS
#error You should include math/math.hpp instead of matrix_functions_details.hpp
#endif

#ifndef FRAMEWORK_MATH_DETAILS_MATRIX_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_DETAILS_MATRIX_FUNCTIONS_DETAILS_HPP

#include <common/types.hpp>
#include <math/inc/matrix_type.hpp>

namespace framework
{
namespace math
{
namespace matrix_functions_details
{
/// @brief Realization of transpose function.
/// @{
template <uint32 C, typename T>
inline matrix<4, C, T> transpose(const matrix<C, 4, T>& value)
{
    return matrix<4, C, T>{value.row(0), value.row(1), value.row(2), value.row(3)};
}

template <uint32 C, typename T>
inline matrix<3, C, T> transpose(const matrix<C, 3, T>& value)
{
    return matrix<3, C, T>{value.row(0), value.row(1), value.row(2)};
}

template <uint32 C, typename T>
inline matrix<2, C, T> transpose(const matrix<C, 2, T>& value)
{
    return matrix<2, C, T>{value.row(0), value.row(1)};
}
/// @}

/// @brief Realization of outer_product function.
/// @{
template <uint32 R, typename T>
inline matrix<4, R, T> outer_product(const vector<R, T>& lhs, const vector<4, T>& rhs)
{
    return matrix<4, R, T>{lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]};
}

template <uint32 R, typename T>
inline matrix<3, R, T> outer_product(const vector<R, T>& lhs, const vector<3, T>& rhs)
{
    return matrix<3, R, T>{lhs * rhs[0], lhs * rhs[1], lhs * rhs[2]};
}

template <uint32 R, typename T>
inline matrix<2, R, T> outer_product(const vector<R, T>& lhs, const vector<2, T>& rhs)
{
    return matrix<2, R, T>{lhs * rhs[0], lhs * rhs[1]};
}
/// @}

/// @brief Realization of determinant function.
/// @{
template <typename T>
inline T determinant(const matrix<4, 4, T>& m)
{
    const T s01 = (m[2][2] * m[3][3] - m[3][2] * m[2][3]);
    const T s02 = (m[2][1] * m[3][3] - m[3][1] * m[2][3]);
    const T s03 = (m[2][1] * m[3][2] - m[3][1] * m[2][2]);
    const T s04 = (m[2][0] * m[3][3] - m[3][0] * m[2][3]);
    const T s05 = (m[2][0] * m[3][2] - m[3][0] * m[2][2]);
    const T s06 = (m[2][0] * m[3][1] - m[3][0] * m[2][1]);

    return m[0][0] * (m[1][1] * s01 - m[1][2] * s02 + m[1][3] * s03) -
           m[0][1] * (m[1][0] * s01 - m[1][2] * s04 + m[1][3] * s05) +
           m[0][2] * (m[1][0] * s02 - m[1][1] * s04 + m[1][3] * s06) -
           m[0][3] * (m[1][0] * s03 - m[1][1] * s05 + m[1][2] * s06);
}

template <typename T>
inline T determinant(const matrix<3, 3, T>& m)
{
    // clang-format off
    return m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
           m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) +
           m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    // clang-format on
}

template <typename T>
inline T determinant(const matrix<2, 2, T>& m)
{
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}
/// @}

/// @brief Realization of inverse function.
/// @{
template <typename T>
inline matrix<4, 4, T> inverse(const matrix<4, 4, T>& m)
{
    const T s01 = (m[3][1] * m[2][2] - m[2][1] * m[3][2]);
    const T s02 = (m[3][1] * m[1][2] - m[1][1] * m[3][2]);
    const T s03 = (m[2][1] * m[1][2] - m[1][1] * m[2][2]);
    const T s04 = (m[3][1] * m[0][2] - m[0][1] * m[3][2]);
    const T s05 = (m[2][1] * m[0][2] - m[0][1] * m[2][2]);
    const T s06 = (m[1][1] * m[0][2] - m[0][1] * m[1][2]);

    const T s07 = (m[3][0] * m[2][2] - m[2][0] * m[3][2]);
    const T s08 = (m[3][0] * m[1][2] - m[1][0] * m[3][2]);
    const T s09 = (m[2][0] * m[1][2] - m[1][0] * m[2][2]);
    const T s10 = (m[3][0] * m[0][2] - m[0][0] * m[3][2]);
    const T s11 = (m[2][0] * m[0][2] - m[0][0] * m[2][2]);
    const T s12 = (m[1][0] * m[0][2] - m[0][0] * m[1][2]);

    const T s13 = (m[3][0] * m[2][1] - m[2][0] * m[3][1]);
    const T s14 = (m[3][0] * m[1][1] - m[1][0] * m[3][1]);
    const T s15 = (m[2][0] * m[1][1] - m[1][0] * m[2][1]);
    const T s16 = (m[3][0] * m[0][1] - m[0][0] * m[3][1]);
    const T s17 = (m[2][0] * m[0][1] - m[0][0] * m[2][1]);
    const T s18 = (m[1][0] * m[0][1] - m[0][0] * m[1][1]);

    const matrix<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03,
                                 +m[0][3] * s01 - m[2][3] * s04 + m[3][3] * s05,
                                 -m[0][3] * s02 + m[1][3] * s04 - m[3][3] * s06,
                                 +m[0][3] * s03 - m[1][3] * s05 + m[2][3] * s06,

                                 +m[1][3] * s07 - m[2][3] * s08 + m[3][3] * s09,
                                 -m[0][3] * s07 + m[2][3] * s10 - m[3][3] * s11,
                                 +m[0][3] * s08 - m[1][3] * s10 + m[3][3] * s12,
                                 -m[0][3] * s09 + m[1][3] * s11 - m[2][3] * s12,

                                 -m[1][3] * s13 + m[2][3] * s14 - m[3][3] * s15,
                                 +m[0][3] * s13 - m[2][3] * s16 + m[3][3] * s17,
                                 -m[0][3] * s14 + m[1][3] * s16 - m[3][3] * s18,
                                 +m[0][3] * s15 - m[1][3] * s17 + m[2][3] * s18,

                                 +m[1][2] * s13 - m[2][2] * s14 + m[3][2] * s15,
                                 -m[0][2] * s13 + m[2][2] * s16 - m[3][2] * s17,
                                 +m[0][2] * s14 - m[1][2] * s16 + m[3][2] * s18,
                                 -m[0][2] * s15 + m[1][2] * s17 - m[2][2] * s18);

    const T det = m[0][0] * result[0][0] + m[1][0] * result[0][1] + m[2][0] * result[0][2] + m[3][0] * result[0][3];

    return result / det;
}

template <typename T>
inline matrix<3, 3, T> inverse(const matrix<3, 3, T>& m)
{
    const matrix<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1],
                                 m[0][2] * m[2][1] - m[0][1] * m[2][2],
                                 m[0][1] * m[1][2] - m[0][2] * m[1][1],

                                 m[1][2] * m[2][0] - m[1][0] * m[2][2],
                                 m[0][0] * m[2][2] - m[0][2] * m[2][0],
                                 m[0][2] * m[1][0] - m[0][0] * m[1][2],

                                 m[1][0] * m[2][1] - m[1][1] * m[2][0],
                                 m[0][1] * m[2][0] - m[0][0] * m[2][1],
                                 m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return result / determinant(m);
}

template <typename T>
inline matrix<2, 2, T> inverse(const matrix<2, 2, T>& m)
{
    const matrix<2, 2, T> result(m[1][1], -m[0][1], -m[1][0], m[0][0]);

    return result / determinant(m);
}
/// @}

/// @brief Realization of affine_inverse function.
/// @{
template <typename T>
inline matrix<3, 3, T> affine_inverse(const matrix<3, 3, T>& value)
{
    using vector3t = typename matrix<3, 3, T>::column_type;
    using vector2t = typename matrix<2, 2, T>::column_type;

    const matrix<2, 2, T> temp = inverse(matrix<2, 2, T>(value));

    return matrix<3, 3, T>(vector3t(temp[0], T{0}),
                           vector3t(temp[1], T{0}),
                           vector3t(-temp * vector2t(value[2]), T{1}));
}

template <typename T>
inline matrix<4, 4, T> affine_inverse(const matrix<4, 4, T>& value)
{
    using vector4t = typename matrix<4, 4, T>::column_type;
    using vector3t = typename matrix<3, 3, T>::column_type;

    matrix<3, 3, T> const temp = inverse(matrix<3, 3, T>(value));

    return matrix<4, 4, T>(vector4t(temp[0], T{0}),
                           vector4t(temp[1], T{0}),
                           vector4t(temp[2], T{0}),
                           vector4t(-temp * vector3t(value[3]), T{1}));
}
/// @}

/// @brief Realization of inverse_transpose function.
/// @{
template <typename T>
inline matrix<4, 4, T> inverse_transpose(const matrix<4, 4, T>& m)
{
    T s01 = (m[3][1] * m[2][2] - m[2][1] * m[3][2]);
    T s02 = (m[3][1] * m[1][2] - m[1][1] * m[3][2]);
    T s03 = (m[2][1] * m[1][2] - m[1][1] * m[2][2]);
    T s04 = (m[3][1] * m[0][2] - m[0][1] * m[3][2]);
    T s05 = (m[2][1] * m[0][2] - m[0][1] * m[2][2]);
    T s06 = (m[1][1] * m[0][2] - m[0][1] * m[1][2]);

    T s07 = (m[3][0] * m[2][2] - m[2][0] * m[3][2]);
    T s08 = (m[3][0] * m[1][2] - m[1][0] * m[3][2]);
    T s09 = (m[2][0] * m[1][2] - m[1][0] * m[2][2]);
    T s10 = (m[3][0] * m[0][2] - m[0][0] * m[3][2]);
    T s11 = (m[2][0] * m[0][2] - m[0][0] * m[2][2]);
    T s12 = (m[1][0] * m[0][2] - m[0][0] * m[1][2]);

    T s13 = (m[3][0] * m[2][1] - m[2][0] * m[3][1]);
    T s14 = (m[3][0] * m[1][1] - m[1][0] * m[3][1]);
    T s15 = (m[2][0] * m[1][1] - m[1][0] * m[2][1]);
    T s16 = (m[3][0] * m[0][1] - m[0][0] * m[3][1]);
    T s17 = (m[2][0] * m[0][1] - m[0][0] * m[2][1]);
    T s18 = (m[1][0] * m[0][1] - m[0][0] * m[1][1]);

    matrix<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03,
                           +m[1][3] * s07 - m[2][3] * s08 + m[3][3] * s09,
                           -m[1][3] * s13 + m[2][3] * s14 - m[3][3] * s15,
                           +m[1][2] * s13 - m[2][2] * s14 + m[3][2] * s15,

                           +m[0][3] * s01 - m[2][3] * s04 + m[3][3] * s05,
                           -m[0][3] * s07 + m[2][3] * s10 - m[3][3] * s11,
                           +m[0][3] * s13 - m[2][3] * s16 + m[3][3] * s17,
                           -m[0][2] * s13 + m[2][2] * s16 - m[3][2] * s17,

                           -m[0][3] * s02 + m[1][3] * s04 - m[3][3] * s06,
                           +m[0][3] * s08 - m[1][3] * s10 + m[3][3] * s12,
                           -m[0][3] * s14 + m[1][3] * s16 - m[3][3] * s18,
                           +m[0][2] * s14 - m[1][2] * s16 + m[3][2] * s18,

                           +m[0][3] * s03 - m[1][3] * s05 + m[2][3] * s06,
                           -m[0][3] * s09 + m[1][3] * s11 - m[2][3] * s12,
                           +m[0][3] * s15 - m[1][3] * s17 + m[2][3] * s18,
                           -m[0][2] * s15 + m[1][2] * s17 - m[2][2] * s18);

    T det = m[0][0] * result[0][0] + m[1][0] * result[0][1] + m[2][0] * result[0][2] + m[3][0] * result[0][3];

    return result / det;
}

template <typename T>
inline matrix<3, 3, T> inverse_transpose(const matrix<3, 3, T>& m)
{
    matrix<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1],
                           m[1][2] * m[2][0] - m[1][0] * m[2][2],
                           m[1][0] * m[2][1] - m[1][1] * m[2][0],

                           m[0][2] * m[2][1] - m[0][1] * m[2][2],
                           m[0][0] * m[2][2] - m[0][2] * m[2][0],
                           m[0][1] * m[2][0] - m[0][0] * m[2][1],

                           m[0][1] * m[1][2] - m[0][2] * m[1][1],
                           m[0][2] * m[1][0] - m[0][0] * m[1][2],
                           m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return result / determinant(m);
}

template <typename T>
inline matrix<2, 2, T> inverse_transpose(const matrix<2, 2, T>& m)
{
    const matrix<2, 2, T> result(m[1][1], -m[1][0], -m[0][1], m[0][0]);

    return result / determinant(m);
}
/// @}

} // namespace matrix_functions_details

} // namespace math

} // namespace framework

#endif
