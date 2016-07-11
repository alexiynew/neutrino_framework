#ifndef FRAMEWORK_MATH_MATRIX_FUNC_H
#define FRAMEWORK_MATH_MATRIX_FUNC_H

#include <math/matrix_type.h>

namespace framework {

namespace math {

template <U32 C, U32 R, typename T, template <U32, U32, typename> class TMat>
inline TMat<R, C, T> transpose(const TMat<C, R, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::type_creator<R>::template create<TMat<R, C, T>>([&m](U32 index) { return m.row(index); });
}

template <U32 C, U32 R, typename T, template <U32, U32, typename> class TMat>
inline TMat<C, R, T> xcomp_mult(const TMat<C, R, T>& lhs, const TMat<C, R, T>& rhs)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::type_creator<C>::template create<TMat<C, R, T>>(
    [&lhs, &rhs](U32 index) { return lhs[index] * rhs[index]; });
}

template <U32 C, U32 R, typename T, template <U32, typename> class TVec>
inline matrix_impl::Matrix<C, R, T> outer_product(const TVec<R, T>& lhs, const TVec<C, T>& rhs)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::type_creator<C>::template create<matrix_impl::Matrix<C, R, T>>(
    [&lhs, &rhs](U32 index) { return lhs * rhs[index]; });
}

template <typename T, template <U32, U32, typename> class TMat>
inline T determinant(const TMat<2, 2, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

template <typename T, template <U32, U32, typename> class TMat>
inline T determinant(const TMat<3, 3, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return +m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

template <typename T, template <U32, U32, typename> class TMat>
inline T determinant(const TMat<4, 4, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    T s01 = (m[2][2] * m[3][3] - m[3][2] * m[2][3]);
    T s02 = (m[2][1] * m[3][3] - m[3][1] * m[2][3]);
    T s03 = (m[2][1] * m[3][2] - m[3][1] * m[2][2]);
    T s04 = (m[2][0] * m[3][3] - m[3][0] * m[2][3]);
    T s05 = (m[2][0] * m[3][2] - m[3][0] * m[2][2]);
    T s06 = (m[2][0] * m[3][1] - m[3][0] * m[2][1]);

    return +m[0][0] * (m[1][1] * s01 - m[1][2] * s02 + m[1][3] * s03) - m[0][1] * (m[1][0] * s01 - m[1][2] * s04 + m[1][3] * s05) + m[0][2] * (m[1][0] * s02 - m[1][1] * s04 + m[1][3] * s06) - m[0][3] * (m[1][0] * s03 - m[1][1] * s05 + m[1][2] * s06);
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<2, 2, T> inverse(const TMat<2, 2, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    T det = determinant(m);
    ASSERT_MSG(F64(det) != 0.0, "matrix has no inverse");

    return TMat<2, 2, T>(m[1][1] / det, -m[0][1] / det, -m[1][0] / det, m[0][0] / det);
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<3, 3, T> inverse(const TMat<3, 3, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    T det = determinant(m);
    ASSERT_MSG(F64(det) != 0.0, "matrix has no inverse");

    TMat<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1], m[0][2] * m[2][1] - m[0][1] * m[2][2], m[0][1] * m[1][2] - m[0][2] * m[1][1],

                         m[1][2] * m[2][0] - m[1][0] * m[2][2], m[0][0] * m[2][2] - m[0][2] * m[2][0], m[0][2] * m[1][0] - m[0][0] * m[1][2],

                         m[1][0] * m[2][1] - m[1][1] * m[2][0], m[0][1] * m[2][0] - m[0][0] * m[2][1], m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return result / det;
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<4, 4, T> inverse(const TMat<4, 4, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

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

    TMat<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03, m[0][3] * s01 - m[2][3] * s04 + m[3][3] * s05, -m[0][3] * s02 + m[1][3] * s04 - m[3][3] * s06, m[0][3] * s03 - m[1][3] * s05 + m[2][3] * s06,

                         m[1][3] * s07 - m[2][3] * s08 + m[3][3] * s09, -m[0][3] * s07 + m[2][3] * s10 - m[3][3] * s11, m[0][3] * s08 - m[1][3] * s10 + m[3][3] * s12, -m[0][3] * s09 + m[1][3] * s11 - m[2][3] * s12,

                         -m[1][3] * s13 + m[2][3] * s14 - m[3][3] * s15, m[0][3] * s13 - m[2][3] * s16 + m[3][3] * s17, -m[0][3] * s14 + m[1][3] * s16 - m[3][3] * s18, m[0][3] * s15 - m[1][3] * s17 + m[2][3] * s18,

                         m[1][2] * s13 - m[2][2] * s14 + m[3][2] * s15, -m[0][2] * s13 + m[2][2] * s16 - m[3][2] * s17, m[0][2] * s14 - m[1][2] * s16 + m[3][2] * s18, -m[0][2] * s15 + m[1][2] * s17 - m[2][2] * s18);

    T det = m[0][0] * result[0][0] + m[1][0] * result[0][1] + m[2][0] * result[0][2] + m[3][0] * result[0][3];
    ASSERT_MSG(F64(det) != 0.0, "matrix has no inverse");

    return result / det;
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<3, 3, T> affine_inverse(const TMat<3, 3, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    using TVec3 = typename TMat<3, 3, T>::ColumnType;
    using TVec2 = typename TMat<2, 2, T>::ColumnType;

    TMat<2, 2, T> const inv = inverse(TMat<2, 2, T>(m));

    return TMat<3, 3, T>(TVec3(inv[0], T(0)), TVec3(inv[1], T(0)), TVec3(-inv * TVec2(m[2]), T(1)));
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<4, 4, T> affine_inverse(const TMat<4, 4, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    using TVec4 = typename TMat<4, 4, T>::ColumnType;
    using TVec3 = typename TMat<3, 3, T>::ColumnType;

    TMat<3, 3, T> const inv(inverse(TMat<3, 3, T>(m)));

    return TMat<4, 4, T>(TVec4(inv[0], T(0)), TVec4(inv[1], T(0)), TVec4(inv[2], T(0)), TVec4(-inv * TVec3(m[3]), T(1)));
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<2, 2, T> inverse_transpose(const TMat<2, 2, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    T det = determinant(m);
    ASSERT_MSG(F64(det) != 0.0, "matrix has no inverse");

    return TMat<2, 2, T>(m[1][1] / det, -m[1][0] / det, -m[0][1] / det, m[0][0] / det);
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<3, 3, T> inverse_transpose(const TMat<3, 3, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

    T det = determinant(m);
    ASSERT_MSG(F64(det) != 0.0, "matrix has no inverse");

    TMat<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1], m[1][2] * m[2][0] - m[1][0] * m[2][2], m[1][0] * m[2][1] - m[1][1] * m[2][0],

                         m[0][2] * m[2][1] - m[0][1] * m[2][2], m[0][0] * m[2][2] - m[0][2] * m[2][0], m[0][1] * m[2][0] - m[0][0] * m[2][1],

                         m[0][1] * m[1][2] - m[0][2] * m[1][1], m[0][2] * m[1][0] - m[0][0] * m[1][2], m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return result / det;
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <U32, U32, typename> class TMat>
inline TMat<4, 4, T> inverse_transpose(const TMat<4, 4, T>& m)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "expected floating-point or integer type");

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

    TMat<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03, m[1][3] * s07 - m[2][3] * s08 + m[3][3] * s09, -m[1][3] * s13 + m[2][3] * s14 - m[3][3] * s15, m[1][2] * s13 - m[2][2] * s14 + m[3][2] * s15,

                         m[0][3] * s01 - m[2][3] * s04 + m[3][3] * s05, -m[0][3] * s07 + m[2][3] * s10 - m[3][3] * s11, m[0][3] * s13 - m[2][3] * s16 + m[3][3] * s17, -m[0][2] * s13 + m[2][2] * s16 - m[3][2] * s17,

                         -m[0][3] * s02 + m[1][3] * s04 - m[3][3] * s06, m[0][3] * s08 - m[1][3] * s10 + m[3][3] * s12, -m[0][3] * s14 + m[1][3] * s16 - m[3][3] * s18, m[0][2] * s14 - m[1][2] * s16 + m[3][2] * s18,

                         m[0][3] * s03 - m[1][3] * s05 + m[2][3] * s06, -m[0][3] * s09 + m[1][3] * s11 - m[2][3] * s12, m[0][3] * s15 - m[1][3] * s17 + m[2][3] * s18, -m[0][2] * s15 + m[1][2] * s17 - m[2][2] * s18);

    T det = m[0][0] * result[0][0] + m[1][0] * result[0][1] + m[2][0] * result[0][2] + m[3][0] * result[0][3];
    ASSERT_MSG(F64(det) != 0.0, "matrix has no inverse");

    return result / det;
}

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_MATRIX_FUNC_H
