#ifndef FRAMEWORK_MATH_RELATIONAL_FTNC_HPP
#define FRAMEWORK_MATH_RELATIONAL_FTNC_HPP

#include <type_traits>

#include <math/utils.hpp>

namespace framework {

namespace math {

/// Returns the component-wise comparison result of l < r.
template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, bool> less(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(l, r, [](const T& a, const T& b) { return a < b; });
}

/// Returns the component-wise comparison of result l <= r.
template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, bool> lessEqual(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(l, r, [](const T& a, const T& b) { return a <= b; });
}

/// Returns the component-wise comparison of result l > r.
template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, bool> greater(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(l, r, [](const T& a, const T& b) { return a > b; });
}

/// Returns the component-wise comparison of result l >= r.
template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, bool> greaterEqual(const TVec<N, T>& l, const TVec<N, T>& r)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(l, r, [](const T& a, const T& b) { return a >= b; });
}

/// Returns the component-wise comparison of result l == r.
template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, bool> equal(const TVec<N, T>& l, const TVec<N, T>& r)
{
    return utils::createVector(l, r, [](const T& a, const T& b) { return a == b; });
}

/// Returns the component-wise comparison of result l != r.
template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, bool> notEqual(const TVec<N, T>& l, const TVec<N, T>& r)
{
    return utils::createVector(l, r, [](const T& a, const T& b) { return a != b; });
}

/// Returns the component-wise logical not of v.
template <unsigned int N, template <unsigned int, typename> class TVec>
inline TVec<N, bool> logicalNot(const TVec<N, bool>& v)
{
    return utils::createVector(v, [](const bool a) { return !a; });
}

/// Returns the component-wise comparison of result l && r.
template <unsigned int N, template <unsigned int, typename> class TVec>
inline TVec<N, bool> logicalAnd(const TVec<N, bool>& l, const TVec<N, bool>& r)
{
    return utils::createVector(l, r, [](const bool a, const bool b) { return a && b; });
}

/// Returns the component-wise comparison of result l || r.
template <unsigned int N, template <unsigned int, typename> class TVec>
inline TVec<N, bool> logicalOr(const TVec<N, bool>& l, const TVec<N, bool>& r)
{
    return utils::createVector(l, r, [](const bool a, const bool b) { return a || b; });
}

/// Returns true if any component of v is true.
template <template <unsigned int, typename> class TVec>
inline bool any(const TVec<4, bool>& v)
{
    return v.x || v.y || v.z || v.w;
}

template <template <unsigned int, typename> class TVec>
inline bool any(const TVec<3, bool>& v)
{
    return v.x || v.y || v.z;
}

template <template <unsigned int, typename> class TVec>
inline bool any(const TVec<2, bool>& v)
{
    return v.x || v.y;
}

/// Returns true if all components of v are true.
template <template <unsigned int, typename> class TVec>
inline bool all(const TVec<4, bool>& v)
{
    return v.x && v.y && v.z && v.w;
}

template <template <unsigned int, typename> class TVec>
inline bool all(const TVec<3, bool>& v)
{
    return v.x && v.y && v.z;
}

template <template <unsigned int, typename> class TVec>
inline bool all(const TVec<2, bool>& v)
{
    return v.x && v.y;
}

} // namespace math

} // namespace framework

#endif
