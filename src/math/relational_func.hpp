#ifndef FRAMEWORK_MATH_RELATIONAL_FTNC_HPP
#define FRAMEWORK_MATH_RELATIONAL_FTNC_HPP

#include <math/vector_type.hpp>

namespace framework {

namespace math {

/// Returns the component-wise comparison result of l < r.
template <typename T>
inline vector<4, bool> less(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    return vector<4, bool>(lhs.x < rhs.x, lhs.y < rhs.y, lhs.z < rhs.z, lhs.w < rhs.w);
}

template <typename T>
inline vector<3, bool> less(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    return vector<3, bool>(lhs.x < rhs.x, lhs.y < rhs.y, lhs.z < rhs.z);
}

template <typename T>
inline vector<2, bool> less(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    return vector<2, bool>(lhs.x < rhs.x, lhs.y < rhs.y);
}

/// Returns the component-wise comparison of result l <= r.
template <typename T>
inline vector<4, bool> less_equal(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    return vector<4, bool>(lhs.x <= rhs.x, lhs.y <= rhs.y, lhs.z <= rhs.z, lhs.w <= rhs.w);
}

template <typename T>
inline vector<3, bool> less_equal(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    return vector<3, bool>(lhs.x <= rhs.x, lhs.y <= rhs.y, lhs.z <= rhs.z);
}

template <typename T>
inline vector<2, bool> less_equal(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    return vector<2, bool>(lhs.x <= rhs.x, lhs.y <= rhs.y);
}

/// Returns the component-wise comparison of result l > r.
template <typename T>
inline vector<4, bool> greater(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    return vector<4, bool>(lhs.x > rhs.x, lhs.y > rhs.y, lhs.z > rhs.z, lhs.w > rhs.w);
}

template <typename T>
inline vector<3, bool> greater(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    return vector<3, bool>(lhs.x > rhs.x, lhs.y > rhs.y, lhs.z > rhs.z);
}

template <typename T>
inline vector<2, bool> greater(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    return vector<2, bool>(lhs.x > rhs.x, lhs.y > rhs.y);
}

/// Returns the component-wise comparison of result l >= r.
template <typename T>
inline vector<4, bool> greater_equal(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    return vector<4, bool>(lhs.x >= rhs.x, lhs.y >= rhs.y, lhs.z >= rhs.z, lhs.w >= rhs.w);
}

template <typename T>
inline vector<3, bool> greater_equal(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    return vector<3, bool>(lhs.x >= rhs.x, lhs.y >= rhs.y, lhs.z >= rhs.z);
}

template <typename T>
inline vector<2, bool> greater_equal(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    return vector<2, bool>(lhs.x >= rhs.x, lhs.y >= rhs.y);
}

/// Returns the component-wise comparison of result l == r.
template <typename T>
inline vector<4, bool> equal(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    constexpr auto impl = std::equal_to<T>();
    return vector<4, bool>(impl(lhs.x, rhs.x), impl(lhs.y, rhs.y), impl(lhs.z, rhs.z), impl(lhs.w, rhs.w));
}

template <typename T>
inline vector<3, bool> equal(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    constexpr auto impl = std::equal_to<T>();
    return vector<3, bool>(impl(lhs.x, rhs.x), impl(lhs.y, rhs.y), impl(lhs.z, rhs.z));
}

template <typename T>
inline vector<2, bool> equal(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    constexpr auto impl = std::equal_to<T>();
    return vector<2, bool>(impl(lhs.x, rhs.x), impl(lhs.y, rhs.y));
}

/// Returns the component-wise comparison of result l != r.
template <typename T>
inline vector<4, bool> not_equal(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    constexpr auto impl = std::not_equal_to<T>();
    return vector<4, bool>(impl(lhs.x, rhs.x), impl(lhs.y, rhs.y), impl(lhs.z, rhs.z), impl(lhs.w, rhs.w));
}

template <typename T>
inline vector<3, bool> not_equal(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    constexpr auto impl = std::not_equal_to<T>();
    return vector<3, bool>(impl(lhs.x, rhs.x), impl(lhs.y, rhs.y), impl(lhs.z, rhs.z));
}

template <typename T>
inline vector<2, bool> not_equal(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    constexpr auto impl = std::not_equal_to<T>();
    return vector<2, bool>(impl(lhs.x, rhs.x), impl(lhs.y, rhs.y));
}

/// Returns the component-wise logical not of v.
template <typename T>
inline vector<4, bool> logical_not(const vector<4, bool>& value)
{
    return vector<4, bool>(!value.x, !value.y, !value.z, !value.w);
}

template <typename T>
inline vector<3, bool> logical_not(const vector<3, bool>& value)
{
    return vector<3, bool>(!value.x, !value.y, !value.z);
}

template <typename T>
inline vector<2, bool> logical_not(const vector<2, bool>& value)
{
    return vector<2, bool>(!value.x, !value.y);
}

/// Returns the component-wise comparison of result l && r.
template <typename T>
inline vector<4, bool> logical_and(const vector<4, bool>& lhs, const vector<4, bool>& rhs)
{
    return vector<4, bool>(lhs.x && rhs.x, lhs.y && rhs.y, lhs.z && rhs.z, lhs.w && rhs.w);
}

template <typename T>
inline vector<3, bool> logical_and(const vector<3, bool>& lhs, const vector<3, bool>& rhs)
{
    return vector<3, bool>(lhs.x && rhs.x, lhs.y && rhs.y, lhs.z && rhs.z);
}

template <typename T>
inline vector<2, bool> logical_and(const vector<2, bool>& lhs, const vector<2, bool>& rhs)
{
    return vector<2, bool>(lhs.x && rhs.x, lhs.y && rhs.y);
}

/// Returns the component-wise comparison of result l || r.
template <typename T>
inline vector<4, bool> logical_or(const vector<4, bool>& lhs, const vector<4, bool>& rhs)
{
    return vector<4, bool>(lhs.x || rhs.x, lhs.y || rhs.y, lhs.z || rhs.z, lhs.w || rhs.w);
}

template <typename T>
inline vector<3, bool> logical_or(const vector<3, bool>& lhs, const vector<3, bool>& rhs)
{
    return vector<3, bool>(lhs.x || rhs.x, lhs.y || rhs.y, lhs.z || rhs.z);
}

template <typename T>
inline vector<2, bool> logical_or(const vector<2, bool>& lhs, const vector<2, bool>& rhs)
{
    return vector<2, bool>(lhs.x || rhs.x, lhs.y || rhs.y);
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
