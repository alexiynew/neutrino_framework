#ifndef FRAMEWORK_MATH_GEOMETRIC_FUNC_H
#define FRAMEWORK_MATH_GEOMETRIC_FUNC_H

#include <math/common_func.h>
#include <math/exponential_func.h>

namespace framework {

namespace math {

namespace gemetric_impl {

template <U32 N>
struct dot_impl
{
};

template <>
struct dot_impl<4>
{
    template <typename T, template <U32, typename> class TVec>
    T operator()(const TVec<4, T>& a, const TVec<4, T>& b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
    }
};

template <>
struct dot_impl<3>
{
    template <typename T, template <U32, typename> class TVec>
    T operator()(const TVec<3, T>& a, const TVec<3, T>& b)
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }
};

template <>
struct dot_impl<2>
{
    template <typename T, template <U32, typename> class TVec>
    T operator()(const TVec<2, T>& a, const TVec<2, T>& b)
    {
        return (a.x * b.x) + (a.y * b.y);
    }
};

} // namespace gemetric_impl

/// Returns the length of x, i.e., sqrt(x * x).
template <typename T>
inline T length(const T& v)
{
    return abs(v);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline T length(const TVec<N, T>& v)
{
    return static_cast<T>(sqrt(gemetric_impl::dot_impl<N>()(v, v)));
}

/// Returns the distance betwen p0 and p1, i.e., length(p0 - p1).
template <typename T>
inline T distance(const T& a, const T& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return length(b - a);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline T distance(const TVec<N, T>& a, const TVec<N, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return length(b - a);
}

/// Returns the dot product of x and y, i.e., result = x * y.
template <typename T>
inline T dot(const T& a, const T& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return a * b;
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline T dot(const TVec<N, T>& a, const TVec<N, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return gemetric_impl::dot_impl<N>()(a, b);
}

/// Returns the cross product of x and y.
template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> cross(const TVec<3, T>& a, const TVec<3, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return TVec<3, T>(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}

/// Returns a vector in the same direction as x but with length of 1.
/// if length(x) == 0 then result is undefined and generate an error.
template <typename T>
inline T normalize(const T& a)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return T(0) > a ? T(1) : T(-1);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> normalize(const TVec<N, T>& a)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return a * invsqrt(dot(a, a));
}

/// If dot(Nref, v) < 0.0, return N, otherwise, return -N.
template <typename T>
inline T faceforward(const T& n, const T& v, const T& nref)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return dot(nref, v) < T(0) ? n : -n;
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> faceforward(const TVec<N, T>& n, const TVec<N, T>& v, const TVec<N, T>& nref)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return dot(nref, v) < T(0) ? n : -n;
}

/// For the incident vector v and surface orientation N,
/// returns the reflection direction : result = v - 2.0 * dot(N, v) * N
template <typename T>
inline T reflection(const T& v, const T& n)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return v - T(2) * dot(n, v) * n;
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> reflection(const TVec<N, T>& v, const TVec<N, T>& n)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return v - T(2) * dot(n, v) * n;
}

/// For the incident vector v and surface normal N,
/// and the ratio of indices of refraction eta,
/// return the refraction vector.
template <typename T>
inline T refraction(const T& v, const T& n, const T& eta)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    T dot_value = dot(n, v);
    T k         = T(1) - eta * eta * (T(1) - dot_value * dot_value);
    return k < T(0) ? T(0) : eta * v - (eta * dot_value + sqrt(k)) * n;
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> refraction(const TVec<N, T>& v, const TVec<N, T>& n, const T& eta)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    T dot_value = dot(n, v);
    T k         = T(1) - eta * eta * (T(1) - dot_value * dot_value);
    return k < T(0) ? TVec<N, T>(0) : eta * v - (eta * dot_value + sqrt(k)) * n;
}

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_GEOMETRIC_FUNC_H
