#ifndef FRAMEWORK_MATH_COMMON_FUNC_H
#define FRAMEWORK_MATH_COMMON_FUNC_H

#include <cmath>
#include <limits>

#include <math/relational_func.h>
#include <math/utils.h>

namespace framework {

namespace math {

namespace common_impl {

template <typename T, bool B>
struct abs_impl
{
};

template <typename T>
struct abs_impl<T, true>
{
    T operator()(const T& v)
    {
        return v < T(0) ? -v : v;
    }
};

template <typename T>
struct abs_impl<T, false>
{
    T operator()(const T& v)
    {
        return v;
    }
};

template <typename T, bool B>
struct sign_impl
{
};

template <typename T>
struct sign_impl<T, true>
{
    T operator()(const T& v)
    {
        return (T(0) < v) - (v < T(0));
    }
};

template <typename T>
struct sign_impl<T, false>
{
    T operator()(const T& v)
    {
        return (T(0) < v);
    }
};

template <U32 N, bool B>
struct sign_vector_impl
{
};

template <U32 N>
struct sign_vector_impl<N, true>
{
    template <typename T, template <U32, typename> class TVec>
    TVec<N, T> operator()(const TVec<N, T>& v)
    {
        return TVec<N, T>(less(TVec<N, T>(T(0)), v)) - TVec<N, T>(less(v, TVec<N, T>(T(0))));
    }
};

template <U32 N>
struct sign_vector_impl<N, false>
{
    template <typename T, template <U32, typename> class TVec>
    TVec<N, T> operator()(const TVec<N, T>& v)
    {
        return TVec<N, T>(less(TVec<N, T>(T(0)), v));
    }
};

} // namespace common_impl

/// Returns x if x >= 0; otherwise, it returns -x.
template <typename T>
inline T abs(const T& v)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return common_impl::abs_impl<T, std::numeric_limits<T>::is_signed>()(v);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> abs(const TVec<N, T>& v)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(v, common_impl::abs_impl<T, std::numeric_limits<T>::is_signed>());
}

/// Returns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0.
template <typename T>
inline T sign(const T& v)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return common_impl::sign_impl<T, std::numeric_limits<T>::is_signed>()(v);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> sign(const TVec<N, T>& v)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return common_impl::sign_vector_impl<N, std::numeric_limits<T>::is_signed>()(v);
}

/// Returns a value equal to the nearest integer that is less then or equal to
/// x.
using ::std::floor;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> floor(const TVec<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return static_cast<T>(floor(a)); });
}

/// Returns a value equal to the nearest integer to x
/// whose absolute value is not larger than the absolute vfractional patr of
/// float-point numberalue of x.
using ::std::trunc;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> trunc(const TVec<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return static_cast<T>(trunc(a)); });
}

/// Returns a value equal to the nearest integer to x.
using ::std::round;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> round(const TVec<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return static_cast<T>(round(a)); });
}

/// Returns a value equal to the nearest integer
/// that is greater than or equal to x.
using ::std::ceil;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> ceil(const TVec<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return static_cast<T>(ceil(a)); });
}

/// Return fractional patr of floating point number
template <typename T>
inline T fract(const T& v)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return v - floor(v);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> fract(const TVec<N, T>& v)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(v, [](const T& a) { return fract(a); });
}

/// Modulus. Returns x - y * floor(x / y)
/// for each component in x using the floating point value y.
template <typename T>
inline T mod(const T& a, const T& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return a - b * floor(a / b);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> mod(const TVec<N, T>& v, const T& scalar)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(v, [&scalar](const T& a) { return mod(a, scalar); });
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> mod(const TVec<N, T>& a, const TVec<N, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, b, [](const T& l, const T& r) { return mod(l, r); });
}

/// Returns the fractional part of x and sets i to the integer
/// part (as a whole number floating point value). Both the
/// return value and the output parameter will have the same
/// sign as x.
template <typename T>
inline T modf(const T& a, T& b)
{
    static_assert(std::is_floating_point<T>::value, "Expected floating-point type.");
    return std::modf(a, &b);
}

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> modf(const TVec<4, T>& a, TVec<4, T>& b)
{
    static_assert(std::is_floating_point<T>::value, "Expected floating-point type.");
    return TVec<4, T>(modf(a.x, b.x), modf(a.y, b.y), modf(a.z, b.z), modf(a.w, b.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> modf(const TVec<3, T>& a, TVec<3, T>& b)
{
    static_assert(std::is_floating_point<T>::value, "Expected floating-point type.");
    return TVec<3, T>(modf(a.x, b.x), modf(a.y, b.y), modf(a.z, b.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> modf(const TVec<2, T>& a, TVec<2, T>& b)
{
    static_assert(std::is_floating_point<T>::value, "Expected floating-point type.");
    return TVec<2, T>(modf(a.x, b.x), modf(a.y, b.y));
}

/// Returns a if a < b; otherwise, it returns b.
template <typename T>
inline T min(const T& a, const T& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return a < b ? a : b;
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> min(const TVec<N, T>& a, const T& scalar)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, [&scalar](const T& l) { return min(l, scalar); });
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> min(const TVec<N, T>& a, const TVec<N, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, b, [](const T& l, const T& r) { return min(l, r); });
}

/// Returns a if a > b; otherwise, it returns b.
template <typename T>
inline T max(const T& a, const T& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return a > b ? a : b;
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> max(const TVec<N, T>& a, const T& scalar)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, [&scalar](const T& l) { return max(l, scalar); });
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> max(const TVec<N, T>& a, const TVec<N, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, b, [](const T& l, const T& r) { return max(l, r); });
}

/// Returns min(max(a, minv), maxv) for each component in a
/// using the floating-point values minv and maxv.
template <typename T>
inline T clamp(const T& a, const T& minv, const T& maxv)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return min(max(a, minv), maxv);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> clamp(const TVec<N, T>& a, const T& minv, const T& maxv)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return min(max(a, minv), maxv);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> clamp(const TVec<N, T>& a, const TVec<N, T>& minv, const TVec<N, T>& maxv)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return min(max(a, minv), maxv);
}

/// If genTypeU is a floating scalar or vector:
/// Returns x * (1.0 - a) + y * a, i.e., the linear blend of
/// x and y using the floating-point value a.
/// The value for a is not restricted to the range [0, 1].
///
/// If genTypeU is a boolean scalar or vector:
/// Selects which vector each returned component comes
/// from. For a component of a that is false, the
/// corresponding component of x is returned. For a
/// component of a that is true, the corresponding
/// component of y is returned. Components of x and y that
/// are not selected are allowed to be invalid floating point
/// values and will have no effect on the results
template <typename T, typename U>
inline T mix(const T& a, const T& b, const U& t)
{
    static_assert(utils::is_floating_point_or_integer<T>::value && utils::is_floating_point_or_integer<U>::value,
                  "Expected floating-point or integer type.");
    return static_cast<T>(a + t * (b - a));
}

template <typename T>
inline T mix(const T& a, const T& b, const bool& t)
{
    return t ? b : a;
}

template <U32 N, typename T, typename U, template <U32, typename> class TVec>
inline TVec<N, T> mix(const TVec<N, T>& a, const TVec<N, T>& b, const U& t)
{
    static_assert(utils::is_floating_point_or_integer<T>::value && utils::is_floating_point_or_integer<U>::value,
                  "Expected floating-point or integer type.");
    return TVec<N, T>(a + t * (b - a));
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> mix(const TVec<N, T>& a, const TVec<N, T>& b, const bool& t)
{
    return t ? b : a;
}

template <typename T, typename U, template <U32, typename> class TVec>
inline TVec<4, T> mix(const TVec<4, T>& a, const TVec<4, T>& b, const TVec<4, U>& t)
{
    return TVec<4, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y), mix(a.z, b.z, t.z), mix(a.w, b.w, t.w));
}

template <typename T, typename U, template <U32, typename> class TVec>
inline TVec<3, T> mix(const TVec<3, T>& a, const TVec<3, T>& b, const TVec<3, U>& t)
{
    return TVec<3, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y), mix(a.z, b.z, t.z));
}

template <typename T, typename U, template <U32, typename> class TVec>
inline TVec<2, T> mix(const TVec<2, T>& a, const TVec<2, T>& b, const TVec<2, U>& t)
{
    return TVec<2, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y));
}

/// Returns 0.0 if a < edge, otherwise it returns 1.0 for each component of a
/// genType.
template <typename T>
inline T step(const T& a, const T& edge)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return a < edge ? T(0) : T(1);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> step(const TVec<N, T>& a, const T& edge)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, [&edge](const T& l) { return step(l, edge); });
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> step(const TVec<N, T>& a, const TVec<N, T>& b)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, b, [](const T& l, const T& r) { return step(l, r); });
}

/// Returns 0.0 if x <= edge0 and 1.0 if x >= edge1 and
/// performs smooth Hermite interpolation between 0 and 1
/// when edge0 < x < edge1. This is useful in cases where
/// you would want a threshold function with a smooth
/// transition. This is equivalent to:
/// genType t;
/// t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
/// return t * t * (3 - 2 * t);
/// Results are undefined if edge0 >= edge1.
template <typename T>
inline T smoothstep(const T& a, const T& edge0, const T& edge1)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    T t = clamp((a - edge0) / (edge1 - edge0), T(0), T(1));
    return t * t * (T(3) - T(2) * t);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> smoothstep(const TVec<N, T>& a, const T& edge0, const T& edge1)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    TVec<N, T> t = clamp((a - edge0) / (edge1 - edge0), T(0), T(1));
    return t * t * (T(3) - T(2) * t);
}

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> smoothstep(const TVec<N, T>& a, const TVec<N, T>& edge0, const TVec<N, T>& edge1)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    TVec<N, T> t = clamp((a - edge0) / (edge1 - edge0), T(0), T(1));
    return t * t * (T(3) - T(2) * t);
}

/// Returns true if x holds a NaN (not a number)
/// representation in the underlying implementation's set of
/// floating point representations. Returns false otherwise,
/// including for implementations with no NaN
/// representations.
using ::std::isnan;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> isnan(const TVec<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return isnan(a); });
}

/// Returns true if x holds a positive infinity or negative
/// infinity representation in the underlying implementation's
/// set of floating point representations. Returns false
/// otherwise, including for implementations with no infinity
/// representations.
using ::std::isinf;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, bool> isinf(const TVec<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return isinf(a); });
}

/// Computes and returns a * b + c.
using ::std::fma;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> fma(const TVec<N, T>& a, const TVec<N, T>& b, const TVec<N, T>& c)
{
    return a * b + c;
}

/// Splits x into a floating-point significand in the range
/// [0.5, 1.0) and an integral exponent of two, such that:
/// x = significand * exp(2, exponent)
///
/// The significand is returned by the function and the
/// exponent is returned in the parameter exp. For a
/// floating-point value of zero, the significant and exponent
/// are both zero. For a floating-point value that is an
/// infinity or is not a number, the results are undefined.

template <typename T, typename TResult = decltype(std::frexp(std::declval<const T&>(), std::declval<I32*>()))>
inline TResult frexp(const T& a, I32& exp)
{
    return std::frexp(a, &exp);
}

template<typename T, template<U32, typename> class TVec, typename TResult = decltype(std::frexp(
        std::declval<const T &>(), std::declval<I32 *>()))>
inline TVec<4, TResult> frexp(const TVec<4, T>& a, TVec<4, I32>& exp)
{
    return TVec<4, TResult>(frexp(a.x, exp.x), frexp(a.y, exp.y), frexp(a.z, exp.z), frexp(a.w, exp.w));
}

template<typename T, template<U32, typename> class TVec, typename TResult = decltype(std::frexp(
        std::declval<const T &>(), std::declval<I32 *>()))>
inline TVec<3, TResult> frexp(const TVec<3, T>& a, TVec<3, I32>& exp)
{
    return TVec<3, TResult>(frexp(a.x, exp.x), frexp(a.y, exp.y), frexp(a.z, exp.z));
}

template<typename T, template<U32, typename> class TVec, typename TResult = decltype(std::frexp(
        std::declval<const T &>(), std::declval<I32 *>()))>
inline TVec<2, TResult> frexp(const TVec<2, T>& a, TVec<2, I32>& exp)
{
    return TVec<2, TResult>(frexp(a.x, exp.x), frexp(a.y, exp.y));
}

/// Builds a floating-point number from x and the
/// corresponding integral exponent of two in exp, returning:
/// significand * exp(2, exponent)
using ::std::ldexp;

template <U32 N, typename T, template <U32, typename> class TVec>
inline TVec<N, T> ldexp(const TVec<N, T>& vector, const I32 exp)
{
    return utils::createVector(vector, [&exp](const T& v) { return ldexp(v, exp); });
}

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> ldexp(const TVec<4, T>& vector, TVec<4, I32>& exp)
{
    return TVec<4, T>(ldexp(vector.x, exp.x), ldexp(vector.y, exp.y), ldexp(vector.z, exp.z), ldexp(vector.w, exp.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> ldexp(const TVec<3, T>& vector, TVec<3, I32>& exp)
{
    return TVec<3, T>(ldexp(vector.x, exp.x), ldexp(vector.y, exp.y), ldexp(vector.z, exp.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> ldexp(const TVec<2, T>& vector, TVec<2, I32>& exp)
{
    return TVec<2, T>(ldexp(vector.x, exp.x), ldexp(vector.y, exp.y));
}

// the machine epsilon has to be scaled to the magnitude of the values used
// and multiplied by the desired precision in ULPs (units in the last place)
// unless the result is subnormal
template <typename T, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(T x, T y, I32 ulp = 0)
{
    return std::abs(x - y) < std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp ||
           std::abs(x - y) < std::numeric_limits<T>::min();
}

template <typename T, template <U32, typename> class TVec, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(const TVec<4, T>& lhs, const TVec<4, T>& rhs, I32 ulp = 0)
{
    return almostEqual(lhs.x, rhs.x, ulp) && almostEqual(lhs.y, rhs.y, ulp) && almostEqual(lhs.z, rhs.z, ulp) &&
           almostEqual(lhs.w, rhs.w, ulp);
}

template <typename T, template <U32, typename> class TVec, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(const TVec<3, T>& lhs, const TVec<3, T>& rhs, I32 ulp = 0)
{
    return almostEqual(lhs.x, rhs.x, ulp) && almostEqual(lhs.y, rhs.y, ulp) && almostEqual(lhs.z, rhs.z, ulp);
}

template <typename T, template <U32, typename> class TVec, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(const TVec<2, T>& lhs, const TVec<2, T>& rhs, I32 ulp = 0)
{
    return almostEqual(lhs.x, rhs.x, ulp) && almostEqual(lhs.y, rhs.y, ulp);
}

template<U32 R, typename T, template<U32, U32, typename> class TMat, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(const TMat<4, R, T>& m, const TMat<4, R, T>& m1, I32 ulp = 0)
{
    return almostEqual(m[0], m1[0], ulp) && almostEqual(m[1], m1[1], ulp) && almostEqual(m[2], m1[2], ulp) &&
           almostEqual(m[3], m1[3], ulp);
}

template<U32 R, typename T, template<U32, U32, typename> class TMat, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(const TMat<3, R, T>& m, const TMat<3, R, T>& m1, I32 ulp = 0)
{
    return almostEqual(m[0], m1[0], ulp) && almostEqual(m[1], m1[1], ulp) && almostEqual(m[2], m1[2], ulp);
}

template<U32 R, typename T, template<U32, U32, typename> class TMat, typename TResult = typename std::enable_if<std::is_floating_point<T>::value, bool>::type>
TResult almostEqual(const TMat<2, R, T>& m, const TMat<2, R, T>& m1, I32 ulp = 0)
{
    return almostEqual(m[0], m1[0], ulp) && almostEqual(m[1], m1[1], ulp);
}

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_COMMON_FUNC_H
