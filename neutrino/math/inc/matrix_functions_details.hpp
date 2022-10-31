#ifndef MATH_INC_MATRIX_FUNCTIONS_DETAILS_HPP
#define MATH_INC_MATRIX_FUNCTIONS_DETAILS_HPP

#include <math/inc/matrix_type.hpp>

namespace neutrino::math::matrix_functions_details
{
template <std::size_t C, typename T>
inline Matrix<4, C, T> transpose(const Matrix<C, 4, T>& value)
{
    return Matrix<4, C, T>{value.row(0), value.row(1), value.row(2), value.row(3)};
}

template <std::size_t C, typename T>
inline Matrix<3, C, T> transpose(const Matrix<C, 3, T>& value)
{
    return Matrix<3, C, T>{value.row(0), value.row(1), value.row(2)};
}

template <std::size_t C, typename T>
inline Matrix<2, C, T> transpose(const Matrix<C, 2, T>& value)
{
    return Matrix<2, C, T>{value.row(0), value.row(1)};
}

template <std::size_t R, typename T>
inline Matrix<4, R, T> outer_product(const Vector<R, T>& lhs, const Vector<4, T>& rhs)
{
    return Matrix<4, R, T>{lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]};
}

template <std::size_t R, typename T>
inline Matrix<3, R, T> outer_product(const Vector<R, T>& lhs, const Vector<3, T>& rhs)
{
    return Matrix<3, R, T>{lhs * rhs[0], lhs * rhs[1], lhs * rhs[2]};
}

template <std::size_t R, typename T>
inline Matrix<2, R, T> outer_product(const Vector<R, T>& lhs, const Vector<2, T>& rhs)
{
    return Matrix<2, R, T>{lhs * rhs[0], lhs * rhs[1]};
}

template <typename T>
inline T determinant(const Matrix<4, 4, T>& m)
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
inline T determinant(const Matrix<3, 3, T>& m)
{
    // clang-format off
    return m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
           m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) +
           m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    // clang-format on
}

template <typename T>
inline T determinant(const Matrix<2, 2, T>& m)
{
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

template <typename T>
inline Matrix<4, 4, T> inverse(const Matrix<4, 4, T>& m)
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

    const Matrix<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03,
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
inline Matrix<3, 3, T> inverse(const Matrix<3, 3, T>& m)
{
    const Matrix<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1],
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
inline Matrix<2, 2, T> inverse(const Matrix<2, 2, T>& m)
{
    const Matrix<2, 2, T> result(m[1][1], -m[0][1], -m[1][0], m[0][0]);

    return result / determinant(m);
}

template <typename T>
inline Matrix<3, 3, T> affine_inverse(const Matrix<3, 3, T>& value)
{
    using vector3t = typename Matrix<3, 3, T>::ColumnType;
    using vector2t = typename Matrix<2, 2, T>::ColumnType;

    const Matrix<2, 2, T> temp = inverse(Matrix<2, 2, T>(value));

    return Matrix<3, 3, T>(vector3t(temp[0], T{0}),
                           vector3t(temp[1], T{0}),
                           vector3t(-temp * vector2t(value[2]), T{1}));
}

template <typename T>
inline Matrix<4, 4, T> affine_inverse(const Matrix<4, 4, T>& value)
{
    using vector4t = typename Matrix<4, 4, T>::ColumnType;
    using vector3t = typename Matrix<3, 3, T>::ColumnType;

    Matrix<3, 3, T> const temp = inverse(Matrix<3, 3, T>(value));

    return Matrix<4, 4, T>(vector4t(temp[0], T{0}),
                           vector4t(temp[1], T{0}),
                           vector4t(temp[2], T{0}),
                           vector4t(-temp * vector3t(value[3]), T{1}));
}

template <typename T>
inline Matrix<4, 4, T> inverse_transpose(const Matrix<4, 4, T>& m)
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

    Matrix<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03,
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
inline Matrix<3, 3, T> inverse_transpose(const Matrix<3, 3, T>& m)
{
    Matrix<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1],
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
inline Matrix<2, 2, T> inverse_transpose(const Matrix<2, 2, T>& m)
{
    const Matrix<2, 2, T> result(m[1][1], -m[1][0], -m[0][1], m[0][0]);

    return result / determinant(m);
}

} // namespace neutrino::math::matrix_functions_details

#endif
