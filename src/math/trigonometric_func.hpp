#ifndef FRAMEWORK_MATH_TRIGONOMETRIC_FUNC_HPP
#define FRAMEWORK_MATH_TRIGONOMETRIC_FUNC_HPP

#include <cmath>

#include <math/constants.hpp>
#include <math/vector_type.hpp>

namespace framework {

namespace math {

// TODO: make like in std lib:: A set of overloads or a function template id:2
// accepting an argument of any integral type.
// Equivalent to 2) (the argument is cast to double).

/// Converts degrees to radians and returns the result.
template <typename T>
inline T radians(const T& degrees)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return static_cast<T>(DEGTORAD) * degrees;
}

template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, T> radians(const TVec<N, T>& a)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, [](const T& degrees) { return static_cast<T>(DEGTORAD * degrees); });
}

/// Converts radians to degrees and returns the result.
template <typename T>
inline T degrees(const T& radians)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return static_cast<T>(RADTODEG) * radians;
}

template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
inline TVec<N, T> degrees(const TVec<N, T>& a)
{
    static_assert(utils::is_floating_point_or_integer<T>::value, "Expected floating-point or integer type.");
    return utils::createVector(a, [](const T& radians) { return static_cast<T>(RADTODEG * radians); });
}

/// The standard trigonometric sine function.
/// The values returned by this function will range from [-1, 1].
using ::std::sin;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> sin(TVec<4, T> const& a)
{
    return TVec<4, T>(sin(a.x), sin(a.y), sin(a.z), sin(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> sin(TVec<3, T> const& a)
{
    return TVec<3, T>(sin(a.x), sin(a.y), sin(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> sin(TVec<2, T> const& a)
{
    return TVec<2, T>(sin(a.x), sin(a.y));
}

/// The standard trigonometric cosine function.
/// The values returned by this function will range from [-1, 1].
using ::std::cos;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> cos(TVec<4, T> const& a)
{
    return TVec<4, T>(cos(a.x), cos(a.y), cos(a.z), cos(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> cos(TVec<3, T> const& a)
{
    return TVec<3, T>(cos(a.x), cos(a.y), cos(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> cos(TVec<2, T> const& a)
{
    return TVec<2, T>(cos(a.x), cos(a.y));
}

/// The standard trigonometric tangent function.
using ::std::tan;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> tan(TVec<4, T> const& a)
{
    return TVec<4, T>(tan(a.x), tan(a.y), tan(a.z), tan(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> tan(TVec<3, T> const& a)
{
    return TVec<3, T>(tan(a.x), tan(a.y), tan(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> tan(TVec<2, T> const& a)
{
    return TVec<2, T>(tan(a.x), tan(a.y));
}

/// Arc sine. Returns an angle whose sine is x.
/// The range of values returned by this function is [-PI/2, PI/2].
/// Results are undefined if |x| > 1.
using ::std::asin;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> asin(TVec<4, T> const& a)
{
    return TVec<4, T>(asin(a.x), asin(a.y), asin(a.z), asin(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> asin(TVec<3, T> const& a)
{
    return TVec<3, T>(asin(a.x), asin(a.y), asin(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> asin(TVec<2, T> const& a)
{
    return TVec<2, T>(asin(a.x), asin(a.y));
}

/// Arc cosine. Returns an angle whose sine is x.
/// The range of values returned by this function is [0, PI].
/// Results are undefined if |x| > 1.
using ::std::acos;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> acos(TVec<4, T> const& a)
{
    return TVec<4, T>(acos(a.x), acos(a.y), acos(a.z), acos(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> acos(TVec<3, T> const& a)
{
    return TVec<3, T>(acos(a.x), acos(a.y), acos(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> acos(TVec<2, T> const& a)
{
    return TVec<2, T>(acos(a.x), acos(a.y));
}

/// Arc tangent. Returns an angle whose tangent is y/x.
/// The signs of x and y are used to determine what
/// quadrant the angle is in. The range of values returned
/// by this function is [-PI, PI]. Results are undefined
/// if x and y are both 0.
template <typename T>
inline T atan(const T& a, const T& b)
{
    return std::atan2(a, b);
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> atan(TVec<4, T> const& a, TVec<4, T> const& b)
{
    return TVec<4, T>(atan(a.x, b.x), atan(a.y, b.y), atan(a.z, b.z), atan(a.w, b.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> atan(TVec<3, T> const& a, TVec<3, T> const& b)
{
    return TVec<3, T>(atan(a.x, b.x), atan(a.y, b.y), atan(a.z, b.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> atan(TVec<2, T> const& a, TVec<2, T> const& b)
{
    return TVec<2, T>(atan(a.x, b.x), atan(a.y, b.y));
}

/// Arc tangent. Returns an angle whose tangent is y_over_x.
/// The range of values returned by this function is [-PI/2, PI/2].
using ::std::atan;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> atan(TVec<4, T> const& a)
{
    return TVec<4, T>(atan(a.x), atan(a.y), atan(a.z), atan(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> atan(TVec<3, T> const& a)
{
    return TVec<3, T>(atan(a.x), atan(a.y), atan(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> atan(TVec<2, T> const& a)
{
    return TVec<2, T>(atan(a.x), atan(a.y));
}

/// Returns the hyperbolic sine function, (exp(x) - exp(-x)) / 2
using std::sinh;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> sinh(TVec<4, T> const& a)
{
    return TVec<4, T>(sinh(a.x), sinh(a.y), sinh(a.z), sinh(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> sinh(TVec<3, T> const& a)
{
    return TVec<3, T>(sinh(a.x), sinh(a.y), sinh(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> sinh(TVec<2, T> const& a)
{
    return TVec<2, T>(sinh(a.x), sinh(a.y));
}

/// Returns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2
using std::cosh;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> cosh(TVec<4, T> const& a)
{
    return TVec<4, T>(cosh(a.x), cosh(a.y), cosh(a.z), cosh(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> cosh(TVec<3, T> const& a)
{
    return TVec<3, T>(cosh(a.x), cosh(a.y), cosh(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> cosh(TVec<2, T> const& a)
{
    return TVec<2, T>(cosh(a.x), cosh(a.y));
}

/// Returns the hyperbolic tangent function, sinh(angle) / cosh(angle)
using std::tanh;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> tanh(TVec<4, T> const& a)
{
    return TVec<4, T>(tanh(a.x), tanh(a.y), tanh(a.z), tanh(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> tanh(TVec<3, T> const& a)
{
    return TVec<3, T>(tanh(a.x), tanh(a.y), tanh(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> tanh(TVec<2, T> const& a)
{
    return TVec<2, T>(tanh(a.x), tanh(a.y));
}

/// Arc hyperbolic sine; returns the inverse of sinh.
using std::asinh;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> asinh(TVec<4, T> const& a)
{
    return TVec<4, T>(asinh(a.x), asinh(a.y), asinh(a.z), asinh(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> asinh(TVec<3, T> const& a)
{
    return TVec<3, T>(asinh(a.x), asinh(a.y), asinh(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> asinh(TVec<2, T> const& a)
{
    return TVec<2, T>(asinh(a.x), asinh(a.y));
}

/// Arc hyperbolic cosine; returns the non-negative inverse
/// of cosh. Results are undefined if x < 1.
using std::acosh;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> acosh(TVec<4, T> const& a)
{
    return TVec<4, T>(acosh(a.x), acosh(a.y), acosh(a.z), acosh(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> acosh(TVec<3, T> const& a)
{
    return TVec<3, T>(acosh(a.x), acosh(a.y), acosh(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> acosh(TVec<2, T> const& a)
{
    return TVec<2, T>(acosh(a.x), acosh(a.y));
}

/// Arc hyperbolic tangent; returns the inverse of tanh.
/// Results are undefined if abs(x) >= 1.
using std::atanh;

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<4, T> atanh(TVec<4, T> const& a)
{
    return TVec<4, T>(atanh(a.x), atanh(a.y), atanh(a.z), atanh(a.w));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<3, T> atanh(TVec<3, T> const& a)
{
    return TVec<3, T>(atanh(a.x), atanh(a.y), atanh(a.z));
}

template <typename T, template <unsigned int, typename> class TVec>
inline TVec<2, T> atanh(TVec<2, T> const& a)
{
    return TVec<2, T>(atanh(a.x), atanh(a.y));
}

} // namespace math

} // namespace framework

#endif
