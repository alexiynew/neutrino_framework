/// @file
/// @brief Contains trigonometric math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017

#ifndef FRAMEWORK_MATH_TRIGONOMETRIC_FUNC_HPP
#define FRAMEWORK_MATH_TRIGONOMETRIC_FUNC_HPP

#include <cmath>
#include <math/constants.hpp>
#include <math/vector_type.hpp>

namespace framework {

namespace math {

/// @brief Contains implementation details of some functions.
namespace trigonometric_functions_details {

/// @brief Shortcut to get the common type.
template <typename... Args>
using common_type = vector_details::common_type<Args...>;

}

/// @brief Defines trigonometric math functions.
///
/// @defgroup trigonometric_functions Trigonometric functions
/// @ingroup math_module
/// @{

/// @name radians
/// @{

/// @brief Converts degrees to radians.
///
/// @param degrees Value of floating-point or integral type.
///
/// @return The value in radians.
template <typename T, typename R = typename trigonometric_functions_details::common_type<decltype(DEGTORAD), T>::type>
inline T radians(const T& degrees)
{
    return static_cast<T>(static_cast<R>(DEGTORAD) * static_cast<R>(degrees));
}

/// @brief Perform a component-wise conversion degrees to radians.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector of values in radians.
template <unsigned int N, typename T>
inline vector<N, T> radians(const vector<N, T>& value)
{
    return transform(value, ::framework::math::radians<T>);
}
/// @}

/// @name degrees
/// @{

/// @brief Converts radians to degrees.
///
/// @param radians Value of floating-point or integral type.
///
/// @return The value in degrees.
template <typename T, typename R = typename trigonometric_functions_details::common_type<decltype(RADTODEG), T>::type>
inline T degrees(const T& radians)
{
    return  static_cast<T>(static_cast<R>(RADTODEG) * static_cast<R>(radians));
}

/// @brief Perform a component-wise conversion radians to degrees.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector of values in degrees.
template <unsigned int N, typename T>
inline vector<N, T> degrees(const vector<N, T>& value)
{
    return transform(value, ::framework::math::degrees<T>);
}
/// @}

/// @name sin
/// @{

/// @brief Computes the sine of value (measured in radians).
///
/// @param value Value representing angle in radians, of a floating-point or integral type.
///
/// @return The sine of value `sin(value)` in the range [-1; +1], is returned.
template <typename T, typename R = decltype(::std::sin(std::declval<T>()))>
inline R sin(const T& value)
{
    return ::std::sin(value);
}

/// @brief Applies the sin function to every component of the vector.
///
/// @param value Vector of angles in radians, of a floating-point or integral type.
///
/// @return The vector of sine values.
///
/// @see sin
template <unsigned int N, typename T, typename R = decltype(::framework::math::sin(std::declval<T>()))>
inline vector<N, R> sin(vector<N, T> const& value)
{
    return transform(value, ::framework::math::sin<T>);
}
/// @}

/// @name cos
/// @{

/// @brief Computes the cosine of value (measured in radians).
///
/// @param value Value representing angle in radians, of a floating-point or integral type.
///
/// @return The cosine of value `cos(value)` in the range [-1; +1], is returned.
template <typename T, typename R = decltype(::std::cos(std::declval<T>()))>
inline R cos(const T& value)
{
    return ::std::cos(value);
}

/// @brief Applies the cos function to every component of the vector.
///
/// @param value Vector of angles in radians, of a floating-point or integral type.
///
/// @return The vector of cosine values.
///
/// @see cos
template <unsigned int N, typename T, typename R = decltype(::framework::math::cos(std::declval<T>()))>
inline vector<N, R> cos(vector<N, T> const& value)
{
    return transform(value, ::framework::math::cos<T>);
}
/// @}

/// @name tan
/// @{

/// @brief Computes the tangent of value (measured in radians).
///
/// @param value Value representing angle in radians, of a floating-point or integral type.
///
/// @return The tangent of value `tan(value)` is returned.
template <typename T, typename R = decltype(::std::tan(std::declval<T>()))>
inline R tan(const T& value)
{
    return ::std::tan(value);
}

/// @brief Applies the tan function to every component of the vector.
///
/// @param value Vector of angles in radians, of a floating-point or integral type.
///
/// @return The vector of tangent values.
///
/// @see tan
template <unsigned int N, typename T, typename R = decltype(::framework::math::tan(std::declval<T>()))>
inline vector<N, R> tan(vector<N, T> const& value)
{
    return transform(value, ::framework::math::tan<T>);
}
/// @}

/// @name asin
/// @{

/// @brief Computes the principal value of the arcsine of value.
///
/// Returns an angle whose sine is `value`.
/// The range of values returned by this function is [-PI/2, PI/2].
/// Results are undefined if `|x| > 1`.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The angle in radians in the range [-PI/2, PI/2].
template <typename T, typename R = decltype(::std::asin(std::declval<T>()))>
inline R asin(const T& value)
{
    return ::std::asin(value);
}

/// @brief Applies the asin function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of angles in radians in the range [-PI/2, PI/2].
///
/// @see asin
template <unsigned int N, typename T, typename R = decltype(::framework::math::asin(std::declval<T>()))>
inline vector<N, R> asin(vector<N, T> const& value)
{
    return transform(value, ::framework::math::asin<T>);
}
/// @}

/// @name acos
/// @{

/// @brief Computes the principal value of the arccosine of value.
///
/// Returns an angle whose cosine is `value`.
/// The range of values returned by this function is [0, PI].
/// Results are undefined if `|x| > 1`.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The angle in radians in the range [0, PI].
template <typename T, typename R = decltype(::std::acos(std::declval<T>()))>
inline R acos(const T& value)
{
    return ::std::acos(value);
}

/// @brief Applies the acos function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of angles in radians in the range [0, PI].
///
/// @see acos
template <unsigned int N, typename T, typename R = decltype(::framework::math::acos(std::declval<T>()))>
inline vector<N, R> acos(vector<N, T> const& value)
{
    return transform(value, ::framework::math::acos<T>);
}
/// @}


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


/// @}

} // namespace math

} // namespace framework

#endif
