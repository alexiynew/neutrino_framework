#ifndef FRAMEWORK_MATH_MATRIX_FUNC_HPP
#define FRAMEWORK_MATH_MATRIX_FUNC_HPP

#include <log/log.hpp>
#include <math/matrix_type.hpp>
#include <math/utils.hpp>

namespace framework {

namespace math {

template <unsigned int C, unsigned int R, typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<R, C, T> transpose(const TMat<C, R, T>& m)
{
    return utils::type_creator<R>::template create<TMat<R, C, T>>([&m](unsigned int index) { return m.row(index); });
}

template <unsigned int C, unsigned int R, typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<C, R, T> crossComponentMultiplication(const TMat<C, R, T>& lhs, const TMat<C, R, T>& rhs)
{
    return utils::type_creator<C>::template create<TMat<C, R, T>>(
    [&lhs, &rhs](unsigned int index) { return lhs[index] * rhs[index]; });
}

template <unsigned int C, unsigned int R, typename T, template <unsigned int, typename> class TVec>
inline matrix<C, R, T> outerProduct(const TVec<R, T>& lhs, const TVec<C, T>& rhs)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&lhs, &rhs](unsigned int index) { return lhs * rhs[index]; });
}

template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline T determinant(const TMat<2, 2, T>& m)
{
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline T determinant(const TMat<3, 3, T>& m)
{
    return +m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) +
           m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline T determinant(const TMat<4, 4, T>& m)
{
    T s01 = (m[2][2] * m[3][3] - m[3][2] * m[2][3]);
    T s02 = (m[2][1] * m[3][3] - m[3][1] * m[2][3]);
    T s03 = (m[2][1] * m[3][2] - m[3][1] * m[2][2]);
    T s04 = (m[2][0] * m[3][3] - m[3][0] * m[2][3]);
    T s05 = (m[2][0] * m[3][2] - m[3][0] * m[2][2]);
    T s06 = (m[2][0] * m[3][1] - m[3][0] * m[2][1]);

    return m[0][0] * (m[1][1] * s01 - m[1][2] * s02 + m[1][3] * s03) -
           m[0][1] * (m[1][0] * s01 - m[1][2] * s04 + m[1][3] * s05) +
           m[0][2] * (m[1][0] * s02 - m[1][1] * s04 + m[1][3] * s06) -
           m[0][3] * (m[1][0] * s03 - m[1][1] * s05 + m[1][2] * s06);
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<2, 2, T> inverse(const TMat<2, 2, T>& m)
{
    T det = determinant(m);
    ASSERT_MSG(framework::math::abs(double(det)) > 0.0, "Matrix has no inverse, result is undefined.");

    return TMat<2, 2, T>(m[1][1] / det, -m[0][1] / det, -m[1][0] / det, m[0][0] / det);
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<3, 3, T> inverse(const TMat<3, 3, T>& m)
{
    T det = determinant(m);
    ASSERT_MSG(framework::math::abs(double(det)) > 0.0, "Matrix has no inverse, result is undefined.");

    TMat<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1],
                         m[0][2] * m[2][1] - m[0][1] * m[2][2],
                         m[0][1] * m[1][2] - m[0][2] * m[1][1],

                         m[1][2] * m[2][0] - m[1][0] * m[2][2],
                         m[0][0] * m[2][2] - m[0][2] * m[2][0],
                         m[0][2] * m[1][0] - m[0][0] * m[1][2],

                         m[1][0] * m[2][1] - m[1][1] * m[2][0],
                         m[0][1] * m[2][0] - m[0][0] * m[2][1],
                         m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return result / det;
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<4, 4, T> inverse(const TMat<4, 4, T>& m)
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

    TMat<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03,
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

    T det = m[0][0] * result[0][0] + m[1][0] * result[0][1] + m[2][0] * result[0][2] + m[3][0] * result[0][3];
    ASSERT_MSG(framework::math::abs(double(det)) > 0.0, "Matrix has no inverse, result is undefined.");

    return result / det;
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<3, 3, T> affineInverse(const TMat<3, 3, T>& m)
{
    using TVec3 = typename TMat<3, 3, T>::column_type;
    using TVec2 = typename TMat<2, 2, T>::column_type;

    TMat<2, 2, T> const inv = inverse(TMat<2, 2, T>(m));

    return TMat<3, 3, T>(TVec3(inv[0], T(0)), TVec3(inv[1], T(0)), TVec3(-inv * TVec2(m[2]), T(1)));
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<4, 4, T> affineInverse(const TMat<4, 4, T>& m)
{
    using TVec4 = typename TMat<4, 4, T>::column_type;
    using TVec3 = typename TMat<3, 3, T>::column_type;

    TMat<3, 3, T> const inv(inverse(TMat<3, 3, T>(m)));

    return TMat<4, 4, T>(TVec4(inv[0], T(0)), TVec4(inv[1], T(0)), TVec4(inv[2], T(0)), TVec4(-inv * TVec3(m[3]), T(1)));
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<2, 2, T> inverseTranspose(const TMat<2, 2, T>& m)
{
    T det = determinant(m);
    ASSERT_MSG(framework::math::abs(double(det)) > 0.0, "Matrix has no inverse, result is undefined.");

    return TMat<2, 2, T>(m[1][1] / det, -m[1][0] / det, -m[0][1] / det, m[0][0] / det);
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<3, 3, T> inverseTranspose(const TMat<3, 3, T>& m)
{
    T det = determinant(m);
    ASSERT_MSG(framework::math::abs(double(det)) > 0.0, "Matrix has no inverse, result is undefined.");

    TMat<3, 3, T> result(m[1][1] * m[2][2] - m[1][2] * m[2][1],
                         m[1][2] * m[2][0] - m[1][0] * m[2][2],
                         m[1][0] * m[2][1] - m[1][1] * m[2][0],

                         m[0][2] * m[2][1] - m[0][1] * m[2][2],
                         m[0][0] * m[2][2] - m[0][2] * m[2][0],
                         m[0][1] * m[2][0] - m[0][0] * m[2][1],

                         m[0][1] * m[1][2] - m[0][2] * m[1][1],
                         m[0][2] * m[1][0] - m[0][0] * m[1][2],
                         m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return result / det;
}

/// Result are undefined if determinant(m) == 0
template <typename T, template <unsigned int, unsigned int, typename> class TMat>
inline TMat<4, 4, T> inverseTranspose(const TMat<4, 4, T>& m)
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

    TMat<4, 4, T> result(-m[1][3] * s01 + m[2][3] * s02 - m[3][3] * s03,
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
    ASSERT_MSG(framework::math::abs(double(det)) > 0.0, "Matrix has no inverse, result is undefined.");

    return result / det;
}

} // namespace math

} // namespace framework

#endif
