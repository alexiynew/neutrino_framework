/// @file
/// @brief Contains matrix functions.
/// @author Fedorov Alexey
/// @date 05.07.2017

#ifndef FRAMEWORK_MATH_MATRIX_FUNC_HPP
#define FRAMEWORK_MATH_MATRIX_FUNC_HPP

#include <common/common_types.hpp>
#include <math/matrix_type.hpp>

namespace framework {

namespace math {

namespace matrix_functions_details {

/// @brief Realization of transpose function.
/// @{
template <uint32 C, typename T>
inline matrix<4, C, T> transpose_details(const matrix<C, 4, T>& value)
{
    return matrix<4, C, T>{value.row(0), value.row(1), value.row(2), value.row(3)};
}

template <uint32 C, typename T>
inline matrix<3, C, T> transpose_details(const matrix<C, 3, T>& value)
{
    return matrix<3, C, T>{value.row(0), value.row(1), value.row(2)};
}

template <uint32 C, typename T>
inline matrix<2, C, T> transpose_details(const matrix<C, 2, T>& value)
{
    return matrix<2, C, T>{value.row(0), value.row(1)};
}
/// @}

/// @brief Realization of outer_product function.
/// @{
template <uint32 R, typename T>
inline matrix<4, R, T> outer_product_details(const vector<R, T>& lhs, const vector<4, T>& rhs)
{
    return matrix<4, R, T>{lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]};
}

template <uint32 R, typename T>
inline matrix<3, R, T> outer_product_details(const vector<R, T>& lhs, const vector<3, T>& rhs)
{
    return matrix<3, R, T>{lhs * rhs[0], lhs * rhs[1], lhs * rhs[2]};
}

template <uint32 R, typename T>
inline matrix<2, R, T> outer_product_details(const vector<R, T>& lhs, const vector<2, T>& rhs)
{
    return matrix<2, R, T>{lhs * rhs[0], lhs * rhs[1]};
}
/// @}

/// @brief Realization of determinant function.
/// @{
template <typename T>
inline T determinant_details(const matrix<4, 4, T>& m)
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
inline T determinant_details(const matrix<3, 3, T>& m)
{
    // clang-format off
    return m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
           m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) +
           m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    // clang-format on
}

template <typename T>
inline T determinant_details(const matrix<2, 2, T>& m)
{
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}
/// @}

/// @brief Realization of inverse function.
/// @{
template <typename T>
inline matrix<4, 4, T> inverse_details(const matrix<4, 4, T>& m)
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
inline matrix<3, 3, T> inverse_details(const matrix<3, 3, T>& m)
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
inline matrix<2, 2, T> inverse_details(const matrix<2, 2, T>& m)
{
    const matrix<2, 2, T> result(m[1][1], -m[0][1], -m[1][0], m[0][0]);

    return result / determinant(m);
}
/// @}

/// @brief Realization of affine_inverse function.
/// @{
template <typename T>
inline matrix<3, 3, T> affine_inverse_details(const matrix<3, 3, T>& value)
{
    using vector3t = typename matrix<3, 3, T>::column_type;
    using vector2t = typename matrix<2, 2, T>::column_type;

    const matrix<2, 2, T> temp = inverse(matrix<2, 2, T>(value));

    return matrix<3, 3, T>(vector3t(temp[0], T{0}), vector3t(temp[1], T{0}), vector3t(-temp * vector2t(value[2]), T{1}));
}

template <typename T>
inline matrix<4, 4, T> affine_inverse_details(const matrix<4, 4, T>& value)
{
    using vector4t = typename matrix<4, 4, T>::column_type;
    using vector3t = typename matrix<3, 3, T>::column_type;

    matrix<3, 3, T> const temp = inverse(matrix<3, 3, T>(value));

    return matrix<4, 4, T>(
    vector4t(temp[0], T{0}), vector4t(temp[1], T{0}), vector4t(temp[2], T{0}), vector4t(-temp * vector3t(value[3]), T{1}));
}
/// @}

/// @brief Realization of inverse_transpose function.
/// @{
template <typename T>
inline matrix<4, 4, T> inverse_transpose_details(const matrix<4, 4, T>& m)
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
inline matrix<3, 3, T> inverse_transpose_details(const matrix<3, 3, T>& m)
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
inline matrix<2, 2, T> inverse_transpose_details(const matrix<2, 2, T>& m)
{
    const matrix<2, 2, T> result(m[1][1], -m[1][0], -m[0][1], m[0][0]);

    return result / determinant(m);
}
/// @}

} // namespace matrix_functions_details

/// @brief Defines geometric math functions.
///
/// @addtogroup matrix_functions
/// @{

/// @name transpose
/// @{

/// @brief Calculate the transpose of a matrix.
///
/// @param value Specifies the matrix of which to take the transpose.
///
/// @return The transpose of the matrix.
template <uint32 C, uint32 R, typename T>
inline matrix<R, C, T> transpose(const matrix<C, R, T>& value)
{
    return matrix_functions_details::transpose_details(value);
}
/// @}

/// @name component_wise_multiplication
/// @{

/// @brief Perform a component-wise multiplication of two matrices.
///
/// @param lhs Specifies the first matrix multiplicand.
/// @param rhs Specifies the second matrix multiplicand.
///
/// @return The component-wise multiplication of two matrices.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> component_wise_multiplication(const matrix<C, R, T>& lhs, const matrix<C, R, T>& rhs)
{
    matrix<C, R, T> temp{lhs};

    for (uint32 i = 0; i < C; ++i) {
        temp[i] *= rhs[i];
    }

    return temp;
}
/// @}

/// @name outer_product
/// @{

/// @brief Calculate the outer product of a pair of vectors.
///
/// @param lhs Specifies the parameter to be treated as a column vector.
/// @param rhs Specifies the parameter to be treated as a row vector.
///
/// @return The outer product of a pair of vectors.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> outer_product(const vector<R, T>& lhs, const vector<C, T>& rhs)
{
    return matrix_functions_details::outer_product_details(lhs, rhs);
}
/// @}

/// @name determinant
/// @{

/// @brief Calculate the determinant of a matrix.
///
/// @param value Specifies the matrix of which to take the determinant.
///
/// @return The determinant of the matrix.
template <uint32 C, uint32 R, typename T>
inline T determinant(const matrix<C, R, T>& value)
{
    return matrix_functions_details::determinant_details(value);
}
/// @}

/// @name inverse
/// @{

/// @brief Calculate the inverse of a matrix.
///
/// The values in the returned matrix are undefined if matrix is singular or poorly-conditioned (nearly singular).
///
/// @param value Specifies the matrix of which to take the inverse.
///
/// @return The inverse of a matrix.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> inverse(const matrix<C, R, T>& value)
{
    return matrix_functions_details::inverse_details(value);
}
/// @}

/// @name affine_inverse
/// @{

/// @brief Calculate the inverse of a affine matrix.
///
/// The values in the returned matrix are undefined if matrix contains not affine transformations,
/// or matrix is singular or poorly-conditioned (nearly singular).
///
/// @param value Specifies the matrix of which to take the inverse.
///
/// @return The inverse of a matrix.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> affine_inverse(const matrix<C, R, T>& value)
{
    return matrix_functions_details::affine_inverse_details(value);
}
/// @}

/// @name inverse_transpose
/// @{

/// @brief Calculate the inverse-transpose of a matrix.
///
/// The values in the returned matrix are undefined if matrix is singular or poorly-conditioned (nearly singular).
///
/// @param value Specifies the matrix of which to take the inverse.
///
/// @return The matrix which is equivalent to `transpose(inverse(matrix))`.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> inverse_transpose(const matrix<C, R, T>& value)
{
    return matrix_functions_details::inverse_transpose_details(value);
}
/// @}

/// @}

} // namespace math

} // namespace framework

#endif
