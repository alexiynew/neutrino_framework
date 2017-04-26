#ifndef FRAMEWORK_MATH_COMMON_FUNC_HPP
#define FRAMEWORK_MATH_COMMON_FUNC_HPP

#include <cmath>
#include <limits>
#include <math/vector_type.hpp>

namespace framework {

namespace math {

namespace details {

template <typename T, bool B>
struct abs_details
{
};

template <typename T>
struct abs_details<T, true>
{
    constexpr T operator()(const T& v)
    {
        return v < T(0) ? -v : v;
    }
};

template <typename T>
struct abs_details<T, false>
{
    constexpr T operator()(const T& v)
    {
        return v;
    }
};

template <typename T, bool B>
struct sign_details
{
};

template <typename T>
struct sign_details<T, true>
{
    T operator()(const T& v)
    {
        return (T(0) < v) - (v < T(0));
    }
};

template <typename T>
struct sign_details<T, false>
{
    T operator()(const T& v)
    {
        return (T(0) < v);
    }
};
}

/// Returns x if x >= 0; otherwise, it returns -x.
template <typename T>
inline constexpr T abs(const T& value)
{
    return details::abs_details<T, std::numeric_limits<T>::is_signed>()(value);
}

template <typename T>
inline constexpr vector<4, T> abs(const vector<4, T>& value)
{
    using ::framework::math::abs;
    return vector<4, T>(abs(value.x), abs(value.y), abs(value.z), abs(value.w));
}

template <typename T>
inline constexpr vector<3, T> abs(const vector<3, T>& value)
{
    using ::framework::math::abs;
    return vector<3, T>(abs(value.x), abs(value.y), abs(value.z));
}

template <typename T>
inline constexpr vector<2, T> abs(const vector<2, T>& value)
{
    using ::framework::math::abs;
    return vector<2, T>(abs(value.x), abs(value.y));
}

/// Returns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0.
template <typename T>
inline constexpr T sign(const T& value)
{
    return details::sign_details<T, std::numeric_limits<T>::is_signed>()(value);
}

template <typename T>
inline constexpr vector<4, T> sign(const vector<4, T>& value)
{
    using ::framework::math::sign;
    return vector<4, T>(sign(value.x), sign(value.y), sign(value.z), sign(value.w));
}

template <typename T>
inline constexpr vector<3, T> sign(const vector<3, T>& value)
{
    using ::framework::math::sign;
    return vector<3, T>(sign(value.x), sign(value.y), sign(value.z));
}

template <typename T>
inline constexpr vector<2, T> sign(const vector<2, T>& value)
{
    using ::framework::math::sign;
    return vector<2, T>(sign(value.x), sign(value.y));
}

/// Returns a value equal to the nearest integer that is less then or equal to
/// x.
using ::std::floor;

template <typename T>
inline constexpr vector<4, T> floor(const vector<4, T>& value)
{
    using ::framework::math::floor;
    return vector<4, T>(floor(value.x), floor(value.y), floor(value.z), floor(value.w));
}

template <typename T>
inline constexpr vector<3, T> floor(const vector<3, T>& value)
{
    using ::framework::math::floor;
    return vector<3, T>(floor(value.x), floor(value.y), floor(value.z));
}

template <typename T>
inline constexpr vector<2, T> floor(const vector<2, T>& value)
{
    using ::framework::math::floor;
    return vector<2, T>(floor(value.x), floor(value.y));
}

/// Returns a value equal to the nearest integer to x.
using ::std::round;

template <typename T>
inline constexpr vector<4, T> round(const vector<4, T>& value)
{
    using ::framework::math::round;
    return vector<4, T>(round(value.x), round(value.y), round(value.z), round(value.w));
}

template <typename T>
inline constexpr vector<3, T> round(const vector<3, T>& value)
{
    using ::framework::math::round;
    return vector<3, T>(round(value.x), round(value.y), round(value.z));
}

template <typename T>
inline constexpr vector<2, T> round(const vector<2, T>& value)
{
    using ::framework::math::round;
    return vector<2, T>(round(value.x), round(value.y));
}

/// Returns a value equal to the nearest integer
/// that is greater than or equal to x.
using ::std::ceil;

template <typename T>
inline constexpr vector<4, T> ceil(const vector<4, T>& value)
{
    using ::framework::math::ceil;
    return vector<4, T>(ceil(value.x), ceil(value.y), ceil(value.z), ceil(value.w));
}

template <typename T>
inline constexpr vector<3, T> ceil(const vector<3, T>& value)
{
    using ::framework::math::ceil;
    return vector<3, T>(ceil(value.x), ceil(value.y), ceil(value.z));
}

template <typename T>
inline constexpr vector<2, T> ceil(const vector<2, T>& value)
{
    using ::framework::math::ceil;
    return vector<2, T>(ceil(value.x), ceil(value.y));
}

/// Returns a value equal to the nearest integer to x
/// whose absolute value is not larger than the absolute vfractional patr of
/// float-point numberalue of x.
using ::std::trunc;

template <typename T>
inline constexpr vector<4, T> trunc(const vector<4, T>& value)
{
    using ::framework::math::trunc;
    return vector<4, T>(trunc(value.x), trunc(value.y), trunc(value.z), trunc(value.w));
}

template <typename T>
inline constexpr vector<3, T> trunc(const vector<3, T>& value)
{
    using ::framework::math::trunc;
    return vector<3, T>(trunc(value.x), trunc(value.y), trunc(value.z));
}

template <typename T>
inline constexpr vector<2, T> trunc(const vector<2, T>& value)
{
    using ::framework::math::trunc;
    return vector<2, T>(trunc(value.x), trunc(value.y));
}

/// Return fractional part of floating point number
template <typename T>
inline T fract(const T& v)
{
    return static_cast<T>(v - floor(v));
}

template <typename T>
inline constexpr vector<4, T> fract(const vector<4, T>& value)
{
    using ::framework::math::fract;
    return vector<4, T>(fract(value.x), fract(value.y), fract(value.z), fract(value.w));
}

template <typename T>
inline constexpr vector<3, T> fract(const vector<3, T>& value)
{
    using ::framework::math::fract;
    return vector<3, T>(fract(value.x), fract(value.y), fract(value.z));
}

template <typename T>
inline constexpr vector<2, T> fract(const vector<2, T>& value)
{
    using ::framework::math::fract;
    return vector<2, T>(fract(value.x), fract(value.y));
}

/// Modulus. Returns x - y * floor(x / y)
/// for each component in x using the floating point value y.
template <typename T>
inline T mod(const T& a, const T& b)
{
    return a - b * floor(a / b);
}

template <typename T>
inline constexpr vector<4, T> mod(const vector<4, T>& value, const T& scalar)
{
    using ::framework::math::mod;
    return vector<4, T>(mod(value.x, scalar), mod(value.y, scalar), mod(value.z, scalar), mod(value.w, scalar));
}

template <typename T>
inline constexpr vector<3, T> mod(const vector<3, T>& value, const T& scalar)
{
    using ::framework::math::mod;
    return vector<3, T>(mod(value.x, scalar), mod(value.y, scalar), mod(value.z, scalar));
}

template <typename T>
inline constexpr vector<2, T> mod(const vector<2, T>& value, const T& scalar)
{
    using ::framework::math::mod;
    return vector<2, T>(mod(value.x, scalar), mod(value.y, scalar));
}

template <typename T>
inline constexpr vector<4, T> mod(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    using ::framework::math::mod;
    return vector<4, T>(mod(lhs.x, rhs.x), mod(lhs.y, rhs.y), mod(lhs.z, rhs.z), mod(lhs.w, rhs.w));
}

template <typename T>
inline constexpr vector<3, T> mod(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    using ::framework::math::mod;
    return vector<3, T>(mod(lhs.x, rhs), mod(lhs.y, rhs), mod(lhs.z, rhs));
}

template <typename T>
inline constexpr vector<2, T> mod(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    using ::framework::math::mod;
    return vector<2, T>(mod(lhs.x, rhs.x), mod(lhs.y, rhs.y));
}

/// Returns the fractional part of x and sets i to the integer
/// part (as a whole number floating point value). Both the
/// return value and the output parameter will have the same
/// sign as x.
template <typename T>
inline T modf(const T& a, T& b)
{
    return std::modf(a, &b);
}

template <typename T>
inline vector<4, T> modf(const vector<4, T>& a, vector<4, T>& b)
{
    return vector<4, T>(modf(a.x, b.x), modf(a.y, b.y), modf(a.z, b.z), modf(a.w, b.w));
}

template <typename T>
inline vector<3, T> modf(const vector<3, T>& a, vector<3, T>& b)
{
    return vector<3, T>(modf(a.x, b.x), modf(a.y, b.y), modf(a.z, b.z));
}

template <typename T>
inline vector<2, T> modf(const vector<2, T>& a, vector<2, T>& b)
{
    return vector<2, T>(modf(a.x, b.x), modf(a.y, b.y));
}

/// Returns a if a < b; otherwise, it returns b.
template <typename T>
inline T min(const T& a, const T& b)
{
    return a < b ? a : b;
}

template <typename T>
inline constexpr vector<4, T> min(const vector<4, T>& value, const T& scalar)
{
    using ::framework::math::min;
    return vector<4, T>(min(value.x, scalar), min(value.y, scalar), min(value.z, scalar), min(value.w, scalar));
}

template <typename T>
inline constexpr vector<3, T> min(const vector<3, T>& value, const T& scalar)
{
    using ::framework::math::min;
    return vector<3, T>(min(value.x, scalar), min(value.y, scalar), min(value.z, scalar));
}

template <typename T>
inline constexpr vector<2, T> min(const vector<2, T>& value, const T& scalar)
{
    using ::framework::math::min;
    return vector<2, T>(min(value.x, scalar), min(value.y, scalar));
}

template <typename T>
inline constexpr vector<4, T> min(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    using ::framework::math::min;
    return vector<4, T>(min(lhs.x, rhs.x), min(lhs.y, rhs.y), min(lhs.z, rhs.z), min(lhs.w, rhs.w));
}

template <typename T>
inline constexpr vector<3, T> min(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    using ::framework::math::min;
    return vector<3, T>(min(lhs.x, rhs), min(lhs.y, rhs), min(lhs.z, rhs));
}

template <typename T>
inline constexpr vector<2, T> min(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    using ::framework::math::min;
    return vector<2, T>(min(lhs.x, rhs.x), min(lhs.y, rhs.y));
}

/// Returns a if a > b; otherwise, it returns b.
template <typename T>
inline T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template <typename T>
inline constexpr vector<4, T> max(const vector<4, T>& value, const T& scalar)
{
    using ::framework::math::max;
    return vector<4, T>(max(value.x, scalar), max(value.y, scalar), max(value.z, scalar), max(value.w, scalar));
}

template <typename T>
inline constexpr vector<3, T> max(const vector<3, T>& value, const T& scalar)
{
    using ::framework::math::max;
    return vector<3, T>(max(value.x, scalar), max(value.y, scalar), max(value.z, scalar));
}

template <typename T>
inline constexpr vector<2, T> max(const vector<2, T>& value, const T& scalar)
{
    using ::framework::math::max;
    return vector<2, T>(max(value.x, scalar), max(value.y, scalar));
}

template <typename T>
inline constexpr vector<4, T> max(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    using ::framework::math::max;
    return vector<4, T>(max(lhs.x, rhs.x), max(lhs.y, rhs.y), max(lhs.z, rhs.z), max(lhs.w, rhs.w));
}

template <typename T>
inline constexpr vector<3, T> max(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    using ::framework::math::max;
    return vector<3, T>(max(lhs.x, rhs), max(lhs.y, rhs), max(lhs.z, rhs));
}

template <typename T>
inline constexpr vector<2, T> max(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    using ::framework::math::max;
    return vector<2, T>(max(lhs.x, rhs.x), max(lhs.y, rhs.y));
}

/// Returns min(max(a, minv), maxv) for each component in a
/// using the floating-point values minv and maxv.
template <typename T>
inline T clamp(const T& a, const T& minv, const T& maxv)
{
    return min(max(a, minv), maxv);
}

template <unsigned int N, typename T>
inline vector<N, T> clamp(const vector<N, T>& a, const T& minv, const T& maxv)
{
    return min(max(a, minv), maxv);
}

template <unsigned int N, typename T>
inline vector<N, T> clamp(const vector<N, T>& a, const vector<N, T>& minv, const vector<N, T>& maxv)
{
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
    return static_cast<T>(a + t * (b - a));
}

template <typename T>
inline T mix(const T& a, const T& b, const bool& t)
{
    return t ? b : a;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T> mix(const vector<N, T>& a, const vector<N, T>& b, const U& t)
{
    return vector<N, T>(a + t * (b - a));
}

template <unsigned int N, typename T>
inline vector<N, T> mix(const vector<N, T>& a, const vector<N, T>& b, const bool& t)
{
    return t ? b : a;
}

template <typename T, typename U>
inline vector<4, T> mix(const vector<4, T>& a, const vector<4, T>& b, const vector<4, U>& t)
{
    return vector<4, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y), mix(a.z, b.z, t.z), mix(a.w, b.w, t.w));
}

template <typename T, typename U>
inline vector<3, T> mix(const vector<3, T>& a, const vector<3, T>& b, const vector<3, U>& t)
{
    return vector<3, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y), mix(a.z, b.z, t.z));
}

template <typename T, typename U>
inline vector<2, T> mix(const vector<2, T>& a, const vector<2, T>& b, const vector<2, U>& t)
{
    return vector<2, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y));
}

/// Returns 0.0 if a < edge, otherwise it returns 1.0 for each component of a
template <typename T>
inline T step(const T& a, const T& edge)
{
    return a < edge ? T(0) : T(1);
}

template <typename T>
inline constexpr vector<4, T> step(const vector<4, T>& value, const T& edge)
{
    using ::framework::math::step;
    return vector<4, T>(step(value.x, edge), step(value.y, edge), step(value.z, edge), step(value.w, edge));
}

template <typename T>
inline constexpr vector<3, T> step(const vector<3, T>& value, const T& edge)
{
    using ::framework::math::step;
    return vector<3, T>(step(value.x, edge), step(value.y, edge), step(value.z, edge));
}

template <typename T>
inline constexpr vector<2, T> step(const vector<2, T>& value, const T& edge)
{
    using ::framework::math::step;
    return vector<2, T>(step(value.x, edge), step(value.y, edge));
}

template <typename T>
inline constexpr vector<4, T> step(const vector<4, T>& value, const vector<4, T>& edge)
{
    using ::framework::math::step;
    return vector<4, T>(step(value.x, edge.x), step(value.y, edge.y), step(value.z, edge.z), step(value.w, edge.w));
}

template <typename T>
inline constexpr vector<3, T> step(const vector<3, T>& value, const vector<3, T>& edge)
{
    using ::framework::math::step;
    return vector<3, T>(step(value.x, edge), step(value.y, edge), step(value.z, edge));
}

template <typename T>
inline constexpr vector<2, T> step(const vector<2, T>& value, const vector<2, T>& edge)
{
    using ::framework::math::step;
    return vector<2, T>(step(value.x, edge.x), step(value.y, edge.y));
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
inline T smooth_step(const T& a, const T& edge0, const T& edge1)
{
    T t = clamp((a - edge0) / (edge1 - edge0), T(0), T(1));
    return t * t * (T(3) - T(2) * t);
}

template <unsigned int N, typename T>
inline vector<N, T> smooth_step(const vector<N, T>& a, const T& edge0, const T& edge1)
{
    vector<N, T> t = clamp((a - edge0) / (edge1 - edge0), T(0), T(1));
    return t * t * (T(3) - T(2) * t);
}

template <unsigned int N, typename T>
inline vector<N, T> smooth_step(const vector<N, T>& a, const vector<N, T>& edge0, const vector<N, T>& edge1)
{
    vector<N, T> t = clamp((a - edge0) / (edge1 - edge0), T(0), T(1));
    return t * t * (T(3) - T(2) * t);
}

/// Returns true if x holds a NaN (not a number)
/// representation in the underlying implementation's set of
/// floating point representations. Returns false otherwise,
/// including for implementations with no NaN
/// representations.
using ::std::isnan;

template <typename T>
inline constexpr vector<4, bool> isnan(const vector<4, T>& value)
{
    using ::framework::math::isnan;
    return vector<4, bool>(isnan(value.x), isnan(value.y), isnan(value.z), isnan(value.w));
}

template <typename T>
inline constexpr vector<3, bool> isnan(const vector<3, T>& value)
{
    using ::framework::math::isnan;
    return vector<3, bool>(isnan(value.x), isnan(value.y), isnan(value.z));
}

template <typename T>
inline constexpr vector<2, bool> isnan(const vector<2, T>& value)
{
    using ::framework::math::isnan;
    return vector<2, bool>(isnan(value.x), isnan(value.y));
}

/// Returns true if x holds a positive infinity or negative
/// infinity representation in the underlying implementation's
/// set of floating point representations. Returns false
/// otherwise, including for implementations with no infinity
/// representations.
using ::std::isinf;

template <typename T>
inline constexpr vector<4, bool> isinf(const vector<4, T>& value)
{
    using ::framework::math::isinf;
    return vector<4, bool>(isinf(value.x), isinf(value.y), isinf(value.z), isinf(value.w));
}

template <typename T>
inline constexpr vector<3, bool> isinf(const vector<3, T>& value)
{
    using ::framework::math::isinf;
    return vector<3, bool>(isinf(value.x), isinf(value.y), isinf(value.z));
}

template <typename T>
inline constexpr vector<2, bool> isinf(const vector<2, T>& value)
{
    using ::framework::math::isinf;
    return vector<2, bool>(isinf(value.x), isinf(value.y));
}

/// Computes and returns a * b + c.
using ::std::fma;

template <unsigned int N, typename T>
inline vector<N, T> fma(const vector<N, T>& a, const vector<N, T>& b, const vector<N, T>& c)
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

template <typename T, typename TResult = decltype(std::frexp(std::declval<const T&>(), std::declval<int*>()))>
inline TResult frexp(const T& a, int& exp)
{
    return std::frexp(a, &exp);
}

template <typename T,
          template <unsigned int, typename> class vector,
          typename TResult = decltype(std::frexp(std::declval<const T&>(), std::declval<int*>()))>
inline vector<4, TResult> frexp(const vector<4, T>& a, vector<4, int>& exp)
{
    return vector<4, TResult>(frexp(a.x, exp.x), frexp(a.y, exp.y), frexp(a.z, exp.z), frexp(a.w, exp.w));
}

template <typename T,
          template <unsigned int, typename> class vector,
          typename TResult = decltype(std::frexp(std::declval<const T&>(), std::declval<int*>()))>
inline vector<3, TResult> frexp(const vector<3, T>& a, vector<3, int>& exp)
{
    return vector<3, TResult>(frexp(a.x, exp.x), frexp(a.y, exp.y), frexp(a.z, exp.z));
}

template <typename T,
          template <unsigned int, typename> class vector,
          typename TResult = decltype(std::frexp(std::declval<const T&>(), std::declval<int*>()))>
inline vector<2, TResult> frexp(const vector<2, T>& a, vector<2, int>& exp)
{
    return vector<2, TResult>(frexp(a.x, exp.x), frexp(a.y, exp.y));
}

/// Builds a floating-point number from x and the
/// corresponding integral exponent of two in exp, returning:
/// significand * exp(2, exponent)
using ::std::ldexp;

template <typename T>
inline constexpr vector<4, T> step(const vector<4, T>& value, const int exp)
{
    using ::framework::math::step;
    return vector<4, T>(step(value.x, exp), step(value.y, exp), step(value.z, exp), step(value.w, exp));
}

template <typename T>
inline constexpr vector<3, T> step(const vector<3, T>& value, const int exp)
{
    using ::framework::math::step;
    return vector<3, T>(step(value.x, exp), step(value.y, exp), step(value.z, exp));
}

template <typename T>
inline constexpr vector<2, T> step(const vector<2, T>& value, const int exp)
{
    using ::framework::math::step;
    return vector<2, T>(step(value.x, exp), step(value.y, exp));
}

template <typename T>
inline vector<4, T> ldexp(const vector<4, T>& value, vector<4, int>& exp)
{
    return vector<4, T>(ldexp(value.x, exp.x), ldexp(value.y, exp.y), ldexp(value.z, exp.z), ldexp(value.w, exp.w));
}

template <typename T>
inline vector<3, T> ldexp(const vector<3, T>& value, vector<3, int>& exp)
{
    return vector<3, T>(ldexp(value.x, exp.x), ldexp(value.y, exp.y), ldexp(value.z, exp.z));
}

template <typename T>
inline vector<2, T> ldexp(const vector<2, T>& value, vector<2, int>& exp)
{
    return vector<2, T>(ldexp(value.x, exp.x), ldexp(value.y, exp.y));
}

// the machine epsilon has to be scaled to the magnitude of the values used
// and multiplied by the desired precision in ULPs (units in the last place)
// unless the result is subnormal
template <typename T, typename std::enable_if<std::is_floating_point<T>::value, void>::type* = nullptr>
inline bool almost_equal(T x, T y, int ulp = 0)
{
    return abs(x - y) < std::numeric_limits<T>::epsilon() * abs(x + y) * static_cast<T>(ulp) ||
           abs(x - y) < std::numeric_limits<T>::min();
}

template <typename T, typename std::enable_if<std::is_integral<T>::value, void>::type* = nullptr>
inline bool almost_equal(T x, T y, int)
{
    return x == y;
}

template <typename T>
inline bool almost_equal(const vector<4, T>& lhs, const vector<4, T>& rhs, int ulp = 0)
{
    return almost_equal(lhs.x, rhs.x, ulp) && almost_equal(lhs.y, rhs.y, ulp) && almost_equal(lhs.z, rhs.z, ulp) &&
           almost_equal(lhs.w, rhs.w, ulp);
}

template <typename T>
inline bool almost_equal(const vector<3, T>& lhs, const vector<3, T>& rhs, int ulp = 0)
{
    return almost_equal(lhs.x, rhs.x, ulp) && almost_equal(lhs.y, rhs.y, ulp) && almost_equal(lhs.z, rhs.z, ulp);
}

template <typename T>
inline bool almost_equal(const vector<2, T>& lhs, const vector<2, T>& rhs, int ulp = 0)
{
    return almost_equal(lhs.x, rhs.x, ulp) && almost_equal(lhs.y, rhs.y, ulp);
}

template <unsigned int R, typename T, template <unsigned int, unsigned int, typename> class TMat>
inline bool almost_equal(const TMat<4, R, T>& m, const TMat<4, R, T>& m1, int ulp = 0)
{
    return almost_equal(m[0], m1[0], ulp) && almost_equal(m[1], m1[1], ulp) && almost_equal(m[2], m1[2], ulp) &&
           almost_equal(m[3], m1[3], ulp);
}

template <unsigned int R, typename T, template <unsigned int, unsigned int, typename> class TMat>
inline bool almost_equal(const TMat<3, R, T>& m, const TMat<3, R, T>& m1, int ulp = 0)
{
    return almost_equal(m[0], m1[0], ulp) && almost_equal(m[1], m1[1], ulp) && almost_equal(m[2], m1[2], ulp);
}

template <unsigned int R, typename T, template <unsigned int, unsigned int, typename> class TMat>
inline bool almost_equal(const TMat<2, R, T>& m, const TMat<2, R, T>& m1, int ulp = 0)
{
    return almost_equal(m[0], m1[0], ulp) && almost_equal(m[1], m1[1], ulp);
}

} // namespace math

} // namespace framework

#endif
