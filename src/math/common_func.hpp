/**
 * @file
 * @brief Contains common math functions.
 * @author Fedorov Alexey
 * @date 04.05.2017
 */

#ifndef FRAMEWORK_MATH_COMMON_FUNC_HPP
#define FRAMEWORK_MATH_COMMON_FUNC_HPP

#include <cmath>
#include <limits>
#include <math/vector_type.hpp>

namespace framework {

namespace math {

/**
 * @brief Contains implementation details of some functions.
 */
namespace common_functions_details {

/**
 * @brief Realization of abs function.
 * @{
 */
template <typename T>
inline constexpr T abs_details(const T& v, std::true_type)
{
    return (v < T{0}) ? -v : v;
}

template <typename T>
inline constexpr T abs_details(const T& v, std::false_type)
{
    return v;
}
/**
 * @}
 */

/**
 * @brief Realization of sign function.
 * @{
 */
template <typename T>
inline constexpr T sign_details(const T& v, std::true_type)
{
    return static_cast<T>((T{0} < v) - (v < T{0}));
}

template <typename T>
inline constexpr T sign_details(const T& v, std::false_type)
{
    return static_cast<T>(T{0} < v);
}
/**
 * @}
 */

/**
 * @brief Realization of modf function.
 * @{
 */
template <typename T>
inline constexpr vector<4, T> modf_details(const vector<4, T>& value, vector<4, T>& integral)
{
    return vector<4, T>(std::modf(value.x, &integral.x),
                        std::modf(value.y, &integral.y),
                        std::modf(value.z, &integral.z),
                        std::modf(value.w, &integral.w));
}

template <typename T>
inline constexpr vector<3, T> modf_details(const vector<3, T>& value, vector<3, T>& integral)
{
    return vector<3, T>(std::modf(value.x, &integral.x), std::modf(value.y, &integral.y), std::modf(value.z, &integral.z));
}

template <typename T>
inline constexpr vector<2, T> modf_details(const vector<2, T>& value, vector<2, T>& integral)
{
    return vector<2, T>(std::modf(value.x, &integral.x), std::modf(value.y, &integral.y));
}
/**
 * @}
 */

/**
 * @brief Realization of mix function.
 * @{
 */
template <typename T, typename U>
inline T mix_details(const T& a, const T& b, const U& t)
{
    return static_cast<T>(a + t * (b - a));
}

template <typename T>
inline T mix_details(const T& a, const T& b, const bool& t)
{
    return t ? b : a;
}

template <typename T, typename U>
inline constexpr vector<4, T> mix_details(const vector<4, T>& a, const vector<4, T>& b, const vector<4, U>& t)
{
    return vector<4, T>(
    mix_details(a.x, b.x, t.x), mix_details(a.y, b.y, t.y), mix_details(a.z, b.z, t.z), mix_details(a.w, b.w, t.w));
}

template <typename T, typename U>
inline constexpr vector<3, T> mix_details(const vector<3, T>& a, const vector<3, T>& b, const vector<3, U>& t)
{
    return vector<3, T>(mix_details(a.x, b.x, t.x), mix_details(a.y, b.y, t.y), mix_details(a.z, b.z, t.z));
}

template <typename T, typename U>
inline constexpr vector<2, T> mix_details(const vector<2, T>& a, const vector<2, T>& b, const vector<2, U>& t)
{
    return vector<2, T>(mix_details(a.x, b.x, t.x), mix_details(a.y, b.y, t.y));
}
/**
 * @}
 */

} // namespace common_functions_details

/**
 * @brief Defines common math functions.
 *
 * @defgroup common_functions Common functions
 * @ingroup math_module
 * @{
 */

/**
 * @name abs
 * @{
 */

/**
 * @brief Computes the absolute value of an argument.
 *
 * @param value Value of floating-point or integral type.
 *
 * @return Value if value >= 0, otherwise -value.
 */
template <typename T>
inline constexpr T abs(const T& value)
{
    return common_functions_details::abs_details(value, std::is_signed<T>{});
}

/**
 * @brief Creates a vector of the absolute values from the provided vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of the absolute values.
 *
 * @see abs
 */
template <unsigned int N, typename T>
inline constexpr vector<N, T> abs(const vector<N, T>& value)
{
    return transform(value, ::framework::math::abs<T>);
}
/**
 * @}
 */

/**
 * @name sign
 * @{
 */

/**
 * @brief Computes the sign of an argument.
 *
 * @param value Value of floating-point or integral type.
 *
 * @return 1.0 if value > 0, 0.0 if value == 0, or -1.0 if value < 0.
 */
template <typename T>
inline constexpr T sign(const T& value)
{
    return common_functions_details::sign_details(value, std::is_signed<T>{});
}

/**
 * @brief Creates a vector of the sign values from the provided vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of the sign values.
 *
 * @see sign
 */
template <unsigned int N, typename T>
inline constexpr vector<N, T> sign(const vector<N, T>& value)
{
    return transform(value, ::framework::math::sign<T>);
}
/**
 * @}
 */

/**
 * @name floor
 * @{
 */

/**
 * @brief Computes the largest integer value not greater than argument.
 *
 * @param value Value of floating-point or integral type.
 *
 * @return A value equal to the nearest integer that is less then or equal to the argument.
 */
template <typename T, typename R = decltype(::std::floor(std::declval<T>()))>
inline R floor(const T& value)
{
    return ::std::floor(value);
}

/**
 * @brief Applies the floor function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are the largest integer value not greater than argument.
 *
 * @see floor
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::floor(std::declval<T>()))>
inline vector<N, R> floor(const vector<N, T>& value)
{
    return transform(value, ::framework::math::floor<T>);
}
/**
 * @}
 */

/**
 * @name round
 * @{
 */

/**
 * @brief Computes the nearest integer value to the argument.
 *
 * @param value Value of floating-point or integral type.
 *
 * @return A value equal to the nearest integer to the argument.
 */
template <typename T, typename R = decltype(::std::round(std::declval<T>()))>
inline R round(const T& value)
{
    return ::std::round(value);
}

/**
 * @brief Applies the round function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are equal to the nearest integer to the argument.
 *
 * @see round
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::round(std::declval<T>()))>
inline vector<N, R> round(const vector<N, T>& value)
{
    return transform(value, ::framework::math::round<T>);
}
/**
 * @}
 */

/**
 * @name ceil
 * @{
 */

/**
 * @brief Computes the nearest integer that is greater than or equal to the argument.
 *
 * @param value Value of floating-point or integral type.
 *
 * @return A value that is greater than or equal to the argument.
 */
template <typename T, typename R = decltype(::std::ceil(std::declval<T>()))>
inline R ceil(const T& value)
{
    return ::std::ceil(value);
}

/**
 * @brief Applies the ceil function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are greater than or equal to the argument.
 *
 * @see ceil
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::ceil(std::declval<T>()))>
inline vector<N, R> ceil(const vector<N, T>& value)
{
    return transform(value, ::framework::math::ceil<T>);
}
/**
 * @}
 */

/**
 * @name trunc
 * @{
 */

/**
 * @brief Computes the nearest integer not greater in magnitude than argument.
 *
 * @param value Value of floating-point or integral type.
 *
 * @return A value that is not greater in magnitude than argument.
 */
template <typename T, typename R = decltype(::std::trunc(std::declval<T>()))>
inline R trunc(const T& value)
{
    return ::std::trunc(value);
}

/**
 * @brief Applies the trunc function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are not greater in magnitude than argument.
 *
 * @see trunc
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::trunc(std::declval<T>()))>
inline vector<N, R> trunc(const vector<N, T>& value)
{
    return transform(value, ::framework::math::trunc<T>);
}
/**
 * @}
 */

/**
 * @name fract
 * @{
 */

/**
 * @brief Computes the fractional part of a floating-point number.
 *
 * @param value Value of floating-point type.
 *
 * @return The fractional part of the argument.
 */
template <typename T, typename R = decltype(::framework::math::floor(std::declval<T>()))>
inline R fract(const T& value)
{
    return static_cast<R>(value) - ::framework::math::floor(value);
}

/**
 * @brief Creates a vector of the fractional parts of the argument.
 *
 * @param value Vector of floating-point values.
 *
 * @return A vector of the fractional parts.
 *
 * @see fract
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::fract(std::declval<T>()))>
inline vector<N, R> fract(const vector<N, T>& value)
{
    return transform(value, ::framework::math::fract<T>);
}
/**
 * @}
 */

/**
 * @name mod
 * @{
 */

/**
 * @brief Modulus. Computes the floating-point remainder of the division operation.
 *
 * The floating-point remainder of the division operation is exactly the value: `a - b * floor(a / b)`
 * The returned value has the same sign as a and is less than b in magnitude.
 *
 * @param a Value of floating-point or integral type.
 * @param b Value of floating-point or integral type.
 *
 * @return The floating-point remainder of the division operation.
 */
template <typename T, typename R = decltype(::framework::math::floor(std::declval<T>()))>
inline R mod(const T& a, const T& b)
{
    return static_cast<R>(a) - b * ::framework::math::floor(static_cast<R>(a) / b);
}

/**
 * @brief Modulus for vector and scalar. Applies the mod function to every component of the vector.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of the floating-point remainder of the division operation.
 *
 * @see mod
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::mod(std::declval<T>(), std::declval<T>()))>
inline vector<N, R> mod(const vector<N, T>& a, const T& b)
{
    return transform(a, vector<N, T>{b}, ::framework::math::mod<T>);
}

/**
 * @brief Modulus for vectors. Applies the mod function to every component of the vector.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of the floating-point remainder of the division operation.
 *
 * @see mod
 */
template <unsigned int N, typename T, typename R = decltype(::framework::math::mod(std::declval<T>(), std::declval<T>()))>
inline vector<N, R> mod(const vector<N, T>& a, const vector<N, T>& b)
{
    return transform(a, b, ::framework::math::mod<T>);
}
/**
 * @}
 */

/**
 * @name modf
 * @{
 */

/**
 * @brief Decomposes given floating-point value into integral and fractional parts.
 * Each having the same type and sign as value.
 * The integral part (in floating-point format) is stored in the integral parameter.
 *
 * @param[in] value Value of floating-point type.
 * @param[out] integral Integral part of the value.
 *
 * @return The fractional part of the argument.
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline R modf(const T& value, T& integral)
{
    return std::modf(value, &integral);
}

/**
 * @brief Decomposes given floating-point vector into integral and fractional parts.
 *
 * @param[in] value Vector of floating-point values.
 * @param[out] integral Vector of integral parts of the value.
 T
 * @return A vector of the fractional parts.
 *
 * @see modf
 */
template <unsigned int N, typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<N, R> modf(const vector<N, T>& value, vector<N, T>& integral)
{
    return common_functions_details::modf_details(value, integral);
}
/**
 * @}
 */

/**
 * @name min
 * @{
 */

/**
 * @brief Returns the smaller of the given values.
 *
 * @param a Value of floating-point or integral type.
 * @param b Value of floating-point or integral type.
 *
 * @return a if a < b; otherwise, it returns b.
 */
template <typename T>
inline T min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

/**
 * @brief Compares vector with scalar value and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of smaller values.
 *
 * @see min
 */
template <unsigned int N, typename T>
inline constexpr vector<N, T> min(const vector<N, T>& a, const T& b)
{
    return transform(a, vector<N, T>{b}, ::framework::math::min<T>);
}

/**
 * @brief Compares two vectors by components and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of smaller values.
 *
 * @see min
 */
template <unsigned int N, typename T>
inline constexpr vector<N, T> min(const vector<N, T>& a, const vector<N, T>& b)
{
    return transform(a, b, ::framework::math::min<T>);
}
/**
 * @}
 */

/**
 * @name max
 * @{
 */

/**
 * @brief Returns the greater of the given values.
 *
 * @param a Value of floating-point or integral type.
 * @param b Value of floating-point or integral type.
 *
 * @return a if a > b; otherwise, it returns b.
 */
template <typename T>
inline T max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Compares vector with scalar value and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of greater values.
 *
 * @see max
 */
template <unsigned int N, typename T>
inline constexpr vector<N, T> max(const vector<N, T>& a, const T& b)
{
    return transform(a, vector<N, T>{b}, ::framework::math::max<T>);
}

/**
 * @brief Compares two vectors by components and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of greater values.
 *
 * @see max
 */
template <unsigned int N, typename T>
inline constexpr vector<N, T> max(const vector<N, T>& a, const vector<N, T>& b)
{
    return transform(a, b, ::framework::math::max<T>);
}
/**
 * @}
 */

/**
 * @name clamp
 * @{
 */

/**
 * @brief Constrain a value to lie between two defined values.
 *
 * The returned value is computed as:
 * @code min(max(x, min_value), max_value) @endcode
 *
 * @param value Value of floating-point or integral type.
 * @param min_value Specify the lower end of the range into which to constrain value.
 * @param max_value Specify the upper end of the range into which to constrain value.
 *
 * @return A value constrained to the range from min_value to max_value.
 */
template <typename T>
inline T clamp(const T& value, const T& min_value, const T& max_value)
{
    return ::framework::math::min(::framework::math::max(value, min_value), max_value);
}

/**
 * @brief Constrain each component of the value to lie between two defined values.
 *
 * @param value Vector of floating-point or integral type values.
 * @param min_value Specify the lower end of the range into which to constrain value.
 * @param max_value Specify the upper end of the range into which to constrain value.
 *
 * @return A vector of values constrained to the range from min_value to max_value.
 *
 * @see clamp
 */
template <unsigned int N, typename T>
inline vector<N, T> clamp(const vector<N, T>& value, const T& min_value, const T& max_value)
{
    return ::framework::math::min(::framework::math::max(value, min_value), max_value);
}

/**
 * @brief Constrain each component of the value to lie between two defined values.
 *
 * @param value Vector of floating-point or integral type values.
 * @param min_value Specify the lower end of the range into which to constrain value.
 * @param max_value Specify the upper end of the range into which to constrain value.
 *
 * @return A vector of values constrained to the range from min_value to max_value.
 *
 * @see clamp
 */
template <unsigned int N, typename T>
inline vector<N, T> clamp(const vector<N, T>& value, const vector<N, T>& min_value, const vector<N, T>& max_value)
{
    return ::framework::math::min(::framework::math::max(value, min_value), max_value);
}
/**
 * @}
 */

/**
 * @name mix
 * @{
 */

/**
 * @brief Linearly interpolate between two values.
 *
 * Performs a linear interpolation between a and b using t to weight between them.
 * If t is floating-point or integer value, return value is computed as `a + t * (b - a)`
 * If t is boolean value, return value is computed as `t ? b : a`
 *
 * @param a Specify the start of the range in which to interpolate.
 * @param b Specify the end of the range in which to interpolate.
 * @param t Specify the value to use to interpolate between a and b.
 *
 * @return Linearly interpolated value.
 */
template <typename T, typename U>
inline T mix(const T& a, const T& b, const U& t)
{
    return common_functions_details::mix_details(a, b, t);
}

/**
 * @brief Linearly interpolate between two vectors.
 *
 * Performs a linear interpolation between a and b using t to weight between them.
 * If t is floating-point or integer value, return vector is computed as `a + t * (b - a)`
 * If t is boolean value, return vector is computed as `t ? b : a`
 *
 * @param a Specify the start vector to interpolate.
 * @param b Specify the end of vector to interpolate.
 * @param t Specify the value to use to interpolate between a and b.
 *
 * @return Linearly interpolated vector.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T> mix(const vector<N, T>& a, const vector<N, T>& b, const U& t)
{
    return common_functions_details::mix_details(a, b, t);
}

/**
 * @brief Linearly interpolate each component of vectors.
 *
 * Performs a linear interpolation between each component of a and b using corresponding component of t to weight
 * between them.
 * The component is computed as `a + t * (b - a)`
 *
 * @param a Specify the start values to interpolate.
 * @param b Specify the end values to interpolate.
 * @param t Specify the values to use to interpolate between a and b.
 *
 * @return Vector of linearly interpolated values.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T> mix(const vector<N, T>& a, const vector<N, T>& b, const vector<N, U>& t)
{
    return common_functions_details::mix_details(a, b, t);
}
/**
 * @}
 */

/**
 * @name step
 * @{
 */

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
    return vector<3, T>(step(value.x, edge.x), step(value.y, edge.y), step(value.z, edge.z));
}

template <typename T>
inline constexpr vector<2, T> step(const vector<2, T>& value, const vector<2, T>& edge)
{
    using ::framework::math::step;
    return vector<2, T>(step(value.x, edge.x), step(value.y, edge.y));
}
/**
 * @}
 */

/**
 * @name smooth_step
 * @{
 */

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
/**
 * @}
 */

/**
 * @name isnan
 * @{
 */

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
/**
 * @}
 */

/**
 * @name isinf
 * @{
 */

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
/**
 * @}
 */

/**
 * @name fma
 * @{
 */

/// Computes and returns a * b + c.
using ::std::fma;

template <unsigned int N, typename T>
inline vector<N, T> fma(const vector<N, T>& a, const vector<N, T>& b, const vector<N, T>& c)
{
    return a * b + c;
}
/**
 * @}
 */

/**
 * @name frexp
 * @{
 */

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
/**
 * @}
 */

/**
 * @name ldexp
 * @{
 */

/// Builds a floating-point number from x and the
/// corresponding integral exponent of two in exp, returning:
/// significand * exp(2, exponent)
using ::std::ldexp;

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
/**
 * @}
 */

/**
 * @name almost_equal
 * @{
 */

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
/**
 * @}
 */

/**
 * @}
 */

} // namespace math

} // namespace framework

#endif
