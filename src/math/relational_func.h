#ifndef FRAMEWORK_MATH_RELATIONAL_FTNC_H
#define FRAMEWORK_MATH_RELATIONAL_FTNC_H

#include <cmath>
#include <type_traits>
#include <limits>

#include <math/vector_type.h>

namespace framework {

namespace math {

/// Returns the component-wise comparison result of l < r.
template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> less(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::vec_helper<N>::apply(l, r, [](const T& a, const T& b) { return a < b; });
}

/// Returns the component-wise comparison of result l <= r.
template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> less_equal(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::vec_helper<N>::apply(l, r, [](const T& a, const T& b) { return a <= b; });
}

/// Returns the component-wise comparison of result l > r.
template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> greater(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::vec_helper<N>::apply(l, r, [](const T& a, const T& b) { return a > b; });
}

/// Returns the component-wise comparison of result l >= r.
template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> greater_equal(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::floating_point_or_integer<T>::value, "expected floating-point or integer type");
    return utils::vec_helper<N>::apply(l, r, [](const T& a, const T& b) { return a >= b; });
}

/// Returns the component-wise comparison of result l == r.
template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> equal(const TVec<N, T>& l, const TVec<N, T>& r)
{
    return utils::vec_helper<N>::apply(l, r, [](const T& a, const T& b) { return a == b; });
}

/// Returns the component-wise comparison of result l != r.
template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> not_equal(const TVec<N, T>& l, const TVec<N, T>& r)
{
    return utils::vec_helper<N>::apply(l, r, [](const T& a, const T& b) { return a != b; });
}

/// Returns the component-wise logical not of v.
template <U32 N, template <U32, typename> class TVec>
inline TVec<N, bool> logical_not(const TVec<N, bool>& v)
{
    return utils::vec_helper<N>::apply(v, [](const bool a) { return !a; });
}

/// Returns the component-wise comparison of result l && r.
template <U32 N, template <U32, typename> class TVec>
inline TVec<N, bool> logical_and(const TVec<N, bool>& l, const TVec<N, bool>& r)
{
    return utils::vec_helper<N>::apply(l, r, [](const bool a, const bool b) { return a && b; });
}

/// Returns the component-wise comparison of result l || r.
template <U32 N, template <U32, typename> class TVec>
inline TVec<N, bool> logical_or(const TVec<N, bool>& l, const TVec<N, bool>& r)
{
    return utils::vec_helper<N>::apply(l, r, [](const bool a, const bool b) { return a || b; });
}

/// Returns true if any component of v is true.
inline bool any(const vector_impl::vec<4, bool>& v)
{
    return v.x || v.y || v.z || v.w;
}

inline bool any(const vector_impl::vec<3, bool>& v)
{
    return v.x || v.y || v.z;
}

inline bool any(const vector_impl::vec<2, bool>& v)
{
    return v.x || v.y;
}

/// Returns true if all components of v are true.
inline bool all(const vector_impl::vec<4, bool>& v)
{
    return v.x && v.y && v.z && v.w;
}

inline bool all(const vector_impl::vec<3, bool>& v)
{
    return v.x && v.y && v.z;
}

inline bool all(const vector_impl::vec<2, bool>& v)
{
    return v.x && v.y;
}

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_RELATIONAL_FTNC_H
