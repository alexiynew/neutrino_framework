#ifndef FRAMEWORK_MATH_INC_COMMON_FUNCTIONS_HPP
#define FRAMEWORK_MATH_INC_COMMON_FUNCTIONS_HPP

#include <cmath>
#include <limits>

#include <math/inc/common_functions_details.hpp>
#include <math/inc/vector_type.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_common_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name abs
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the absolute value of an argument.
///
/// @param value Value of floating-point or integral type.
///
/// @return Value if value >= 0, otherwise -value.
template <typename T>
inline constexpr T abs(const T& value)
{
    return common_functions_details::abs(value, std::is_signed<T>{});
}

/// @brief Creates a vector of the absolute values from the provided vector.
///
/// @param value Vector of floating-point or integral type values.
///
/// @return A vector of the absolute values.
///
/// @see abs
template <std::size_t N, typename T>
inline constexpr Vector<N, T> abs(const Vector<N, T>& value)
{
    return transform(value, framework::math::abs<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name sign
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the sign of an argument.
///
/// @param value Value of floating-point or integral type.
///
/// @return 1.0 if value > 0, 0.0 if value == 0, or -1.0 if value < 0.
template <typename T>
inline constexpr T sign(const T& value)
{
    return common_functions_details::sign(value, std::is_signed<T>{});
}

/// @brief Creates a vector of the sign values from the provided vector.
///
/// @param value Vector of floating-point or integral type values.
///
/// @return A vector of the sign values.
///
/// @see sign
template <std::size_t N, typename T>
inline constexpr Vector<N, T> sign(const Vector<N, T>& value)
{
    return transform(value, framework::math::sign<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name floor
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Computes the largest integer value not greater than argument.
///
/// @param value Value of floating-point or integral type.
///
/// @return A value equal to the nearest integer that is less then or equal
///         to the argument.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename R = decltype(::std::floor(std::declval<T>()))>
inline R floor(const T& value)
{
    return ::std::floor(value);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Applies the floor function to every component of the vector.
///
/// @param value Vector of floating-point or integral type values.
///
/// @return A vector of values that are the largest integer value not greater
///         than argument.
///
/// @see floor
////////////////////////////////////////////////////////////////////////////////
template <std::size_t N, typename T, typename R = decltype(framework::math::floor(std::declval<T>()))>
inline Vector<N, R> floor(const Vector<N, T>& value)
{
    return transform(value, framework::math::floor<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name round
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the nearest integer value to the argument.
///
/// @param value Value of floating-point or integral type.
///
/// @return A value equal to the nearest integer to the argument.
template <typename T, typename R = decltype(::std::round(std::declval<T>()))>
inline R round(const T& value)
{
    return ::std::round(value);
}

/// @brief Applies the round function to every component of the vector.
///
/// @param value Vector of floating-point or integral type values.
///
/// @return A vector of values that are equal to the nearest integer
///         to the argument.
///
/// @see round
template <std::size_t N, typename T, typename R = decltype(framework::math::round(std::declval<T>()))>
inline Vector<N, R> round(const Vector<N, T>& value)
{
    return transform(value, framework::math::round<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name ceil
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the nearest integer that is greater than or equal
///        to the argument.
///
/// @param value Value of floating-point or integral type.
///
/// @return A value that is greater than or equal to the argument.
template <typename T, typename R = decltype(::std::ceil(std::declval<T>()))>
inline R ceil(const T& value)
{
    return ::std::ceil(value);
}

/// @brief Applies the ceil function to every component of the vector.
///
/// @param value Vector of floating-point or integral type values.
///
/// @return A vector of values that are greater than or equal to the argument.
///
/// @see ceil
template <std::size_t N, typename T, typename R = decltype(framework::math::ceil(std::declval<T>()))>
inline Vector<N, R> ceil(const Vector<N, T>& value)
{
    return transform(value, framework::math::ceil<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name trunc
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the nearest integer not greater in magnitude than argument.
///
/// @param value Value of floating-point or integral type.
///
/// @return A value that is not greater in magnitude than argument.
template <typename T, typename R = decltype(::std::trunc(std::declval<T>()))>
inline R trunc(const T& value)
{
    return ::std::trunc(value);
}

/// @brief Applies the trunc function to every component of the vector.
///
/// @param value Vector of floating-point or integral type values.
///
/// @return A vector of values that are not greater in magnitude than argument.
///
/// @see trunc
template <std::size_t N, typename T, typename R = decltype(framework::math::trunc(std::declval<T>()))>
inline Vector<N, R> trunc(const Vector<N, T>& value)
{
    return transform(value, framework::math::trunc<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name fract
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the fractional part of a floating-point number.
///
/// @param value Value of floating-point type.
///
/// @return The fractional part of the argument.
template <typename T, typename R = decltype(framework::math::floor(std::declval<T>()))>
inline R fract(const T& value)
{
    return static_cast<R>(value) - framework::math::floor(value);
}

/// @brief Creates a vector of the fractional parts of the argument.
///
/// @param value Vector of floating-point values.
///
/// @return A vector of the fractional parts.
///
/// @see fract
template <std::size_t N, typename T, typename R = decltype(framework::math::fract(std::declval<T>()))>
inline Vector<N, R> fract(const Vector<N, T>& value)
{
    return transform(value, framework::math::fract<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name mod
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Modulus. Computes the floating-point remainder of the division
///        operation.
///
/// The floating-point remainder of the division operation is exactly the value:
/// `a - b/// floor(a / b)`
/// The returned value has the same sign as a and is less than b in magnitude.
///
/// @param a Value of floating-point or integral type.
/// @param b Value of floating-point or integral type.
///
/// @return The floating-point remainder of the division operation.
template <typename T, typename R = decltype(framework::math::floor(std::declval<T>()))>
inline R mod(const T& a, const T& b)
{
    return static_cast<R>(a) - b * framework::math::floor(static_cast<R>(a) / b);
}

/// @brief Modulus for vector and scalar. Applies the mod function
///        to every component of the vector.
///
/// @param a Vector of floating-point or integral type values.
/// @param b Value of floating-point or integral type.
///
/// @return A vector of the floating-point remainder of the division operation.
///
/// @see mod
template <std::size_t N, typename T, typename R = decltype(framework::math::mod(std::declval<T>(), std::declval<T>()))>
inline Vector<N, R> mod(const Vector<N, T>& a, const T& b)
{
    return transform(a, Vector<N, T>{b}, framework::math::mod<T>);
}

/// @brief Modulus for vectors. Applies the mod function to every component
///        of the vector.
///
/// @param a Vector of floating-point or integral type values.
/// @param b Vector of floating-point or integral type values.
///
/// @return A vector of the floating-point remainder of the division operation.
///
/// @see mod
template <std::size_t N, typename T, typename R = decltype(framework::math::mod(std::declval<T>(), std::declval<T>()))>
inline Vector<N, R> mod(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return transform(a, b, framework::math::mod<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name modf
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Decomposes given floating-point value into integral
///        and fractional parts. Each having the same type and sign as value.
///        The integral part (in floating-point format) is stored
///        in the integral parameter.
///
/// @param[in] value Value of floating-point type.
/// @param[out] integral Integral part of the value.
///
/// @return The fractional part of the argument.
template <typename T, typename R = std::enable_if_t<std::is_floating_point_v<T>, T>>
inline R modf(const T& value, T& integral)
{
    return std::modf(value, &integral);
}

/// @brief Decomposes given floating-point vector into integral
///        and fractional parts.
///
/// @param[in] value Vector of floating-point values.
/// @param[out] integral Vector of integral parts of the value.
///
/// @return A vector of the fractional parts.
///
/// @see modf
template <std::size_t N, typename T, typename R = std::enable_if_t<std::is_floating_point_v<T>, T>>
inline Vector<N, R> modf(const Vector<N, T>& value, Vector<N, T>& integral)
{
    return common_functions_details::modf(value, integral);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name min
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Returns the smaller of the given values.
///
/// @param a Value of floating-point or integral type.
/// @param b Value of floating-point or integral type.
///
/// @return a if a < b; otherwise, it returns b.
template <typename T>
inline T min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

/// @brief Compares vector with scalar value and return a vector
///        of smaller values.
///
/// @param a Vector of floating-point or integral type values.
/// @param b Value of floating-point or integral type.
///
/// @return A vector of smaller values.
///
/// @see min
template <std::size_t N, typename T>
inline constexpr Vector<N, T> min(const Vector<N, T>& a, const T& b)
{
    return transform(a, Vector<N, T>{b}, framework::math::min<T>);
}

/// @brief Compares two vectors by components and return a vector
///        of smaller values.
///
/// @param a Vector of floating-point or integral type values.
/// @param b Vector of floating-point or integral type values.
///
/// @return A vector of smaller values.
///
/// @see min
template <std::size_t N, typename T>
inline constexpr Vector<N, T> min(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return transform(a, b, framework::math::min<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name max
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Returns the greater of the given values.
///
/// @param a Value of floating-point or integral type.
/// @param b Value of floating-point or integral type.
///
/// @return a if a > b; otherwise, it returns b.
template <typename T>
inline T max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

/// @brief Compares vector with scalar value and return a vector
///        of greater values.
///
/// @param a Vector of floating-point or integral type values.
/// @param b Value of floating-point or integral type.
///
/// @return A vector of greater values.
///
/// @see max
template <std::size_t N, typename T>
inline constexpr Vector<N, T> max(const Vector<N, T>& a, const T& b)
{
    return transform(a, Vector<N, T>{b}, framework::math::max<T>);
}

/// @brief Compares two vectors by components and return a vector
///        of greater values.
///
/// @param a Vector of floating-point or integral type values.
/// @param b Vector of floating-point or integral type values.
///
/// @return A vector of greater values.
///
/// @see max
template <std::size_t N, typename T>
inline constexpr Vector<N, T> max(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return transform(a, b, framework::math::max<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name clamp
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Constrain a value to lie between two defined values.
///
/// The returned value is computed as:
/// @code min(max(x, min_value), max_value) @endcode
///
/// @param value Value of floating-point or integral type.
/// @param min_value Specify the lower end of the range into which
///                  to constrain value.
/// @param max_value Specify the upper end of the range into which
///                  to constrain value.
///
/// @return A value constrained to the range from min_value to max_value.
template <typename T>
inline T clamp(const T& value, const T& min_value, const T& max_value)
{
    return framework::math::min(framework::math::max(value, min_value), max_value);
}

/// @brief Constrain each component of the value to lie between
///        two defined values.
///
/// @param value Vector of floating-point or integral type values.
/// @param min_value Specify the lower end of the range into which
///                  to constrain value.
/// @param max_value Specify the upper end of the range into which
///                  to constrain value.
///
/// @return A vector of values constrained to the range from min_value
///         to max_value.
///
/// @see clamp
template <std::size_t N, typename T>
inline Vector<N, T> clamp(const Vector<N, T>& value, const T& min_value, const T& max_value)
{
    return framework::math::min(framework::math::max(value, min_value), max_value);
}

/// @brief Constrain each component of the value to lie between
///        two defined values.
///
/// @param value Vector of floating-point or integral type values.
/// @param min_value Specify the lower end of the range into which
///                  to constrain value.
/// @param max_value Specify the upper end of the range into which
///                  to constrain value.
///
/// @return A vector of values constrained to the range from min_value
///         to max_value.
///
/// @see clamp
template <std::size_t N, typename T>
inline Vector<N, T> clamp(const Vector<N, T>& value, const Vector<N, T>& min_value, const Vector<N, T>& max_value)
{
    return framework::math::min(framework::math::max(value, min_value), max_value);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name mix
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Linearly interpolate between two values.
///
/// Performs a linear interpolation between a and b using t
/// to weight between them.
/// If t is floating-point or integer value, return value
/// is computed as `a + t * (b - a)`
/// If t is boolean value, return value is computed as `t ? b : a`
///
/// @param a Specify the start of the range in which to interpolate.
/// @param b Specify the end of the range in which to interpolate.
/// @param t Specify the value to use to interpolate between a and b.
///
/// @return Linearly interpolated value.
template <typename T, typename U>
inline T mix(const T& a, const T& b, const U& t)
{
    return common_functions_details::mix(a, b, t);
}

/// @brief Linearly interpolate between two vectors.
///
/// Performs a linear interpolation between a and b using t
/// to weight between them.
/// If t is floating-point or integer value, return vector
/// is computed as `a + t * (b - a)`
/// If t is boolean value, return vector is computed as `t ? b : a`
///
/// @param a Specify the start vector to interpolate.
/// @param b Specify the end of vector to interpolate.
/// @param t Specify the value to use to interpolate between a and b.
///
/// @return Linearly interpolated vector.
template <std::size_t N, typename T, typename U>
inline Vector<N, T> mix(const Vector<N, T>& a, const Vector<N, T>& b, const U& t)
{
    return common_functions_details::mix(a, b, t);
}

/// @brief Linearly interpolate each component of vectors.
///
/// Performs a linear interpolation between each component of a and b using
/// corresponding component of t to weight /// between them.
/// The component is computed as `a + t * (b - a)`
///
/// @param a Specify the start values to interpolate.
/// @param b Specify the end values to interpolate.
/// @param t Specify the values to use to interpolate between a and b.
///
/// @return Vector of linearly interpolated values.
template <std::size_t N, typename T, typename U>
inline Vector<N, T> mix(const Vector<N, T>& a, const Vector<N, T>& b, const Vector<N, U>& t)
{
    return common_functions_details::mix(a, b, t);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name step
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Generate a step function by comparing two values.
///
/// @param value Specify the value to be used to generate the step function.
/// @param edge Specifies the location of the edge of the step function.
///
/// @return 0 if value < edge, and 1 otherwise.
template <typename T>
inline T step(const T& value, const T& edge)
{
    return value < edge ? T(0) : T(1);
}

/// @brief Generate a step function by comparing two values.
///
/// @param value Specify the value to be used to generate the step function.
/// @param edge Specifies the location of the edge of the step function.
///
/// @return For each component in value return 0 if value < edge,
///         and 1 otherwise.
template <std::size_t N, typename T>
inline Vector<N, T> step(const Vector<N, T>& value, const T& edge)
{
    return transform(value, Vector<N, T>{edge}, framework::math::step<T>);
}

/// @brief Generate a step function by comparing two values.
///
/// @param value Specify the value to be used to generate the step function.
/// @param edge Specifies the location of the edge of the step function.
///
/// @return For each i return 0 if value[i] < edge[i], and 1 otherwise.
template <std::size_t N, typename T>
inline Vector<N, T> step(const Vector<N, T>& value, const Vector<N, T>& edge)
{
    return transform(value, edge, framework::math::step<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name smooth_step
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Performs Hermite interpolation between two values.
///
/// Performs smooth Hermite interpolation between 0 and 1 when edge0 < x < edge1.
/// This is useful in cases where a threshold function with
/// a smooth transition is desired.
///
/// Result is equivalent to:
/// @code
///     t = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
///     return t * t * (3.0 - 2.0 * t);
/// @endcode
/// Results are undefined if edge0
/// Р В Р’В Р вЂ™Р’В Р В РІР‚в„ўР вЂ™Р’В Р В Р’В Р вЂ™Р’В Р В Р вЂ Р В РІР‚С™Р вЂ™Р’В Р В Р’В Р вЂ™Р’В Р В Р’В Р Р†Р вЂљР’В Р В Р’В Р вЂ™Р’В Р В Р вЂ Р В РІР‚С™Р РЋРІвЂћСћР В Р’В Р Р†Р вЂљРІвЂћСћР В РІР‚в„ўР вЂ™Р’В°Р В Р’В Р вЂ™Р’В Р В Р Р‹Р РЋРІР‚С”Р В Р’В Р В Р вЂ№Р В Р вЂ Р В РІР‚С™Р Р†РІР‚С›РЎС›
/// edge1.
///
/// @param value Specifies the source value for interpolation.
/// @param edge0 Specifies the value of the lower edge of the Hermite function.
/// @param edge1 Specifies the value of the upper edge of the Hermite function.
///
/// @return Interpolated value.
template <typename T>
inline T smooth_step(const T& value, const T& edge0, const T& edge1)
{
    T temp = clamp((value - edge0) / (edge1 - edge0), T{0}, T{1});
    return temp * temp * (T{3} - T{2} * temp);
}

/// @brief Performs Hermite interpolation between two values.
///
/// @param value Specifies the source value for interpolation.
/// @param edge0 Specifies the value of the lower edge of the Hermite function.
/// @param edge1 Specifies the value of the upper edge of the Hermite function.
///
/// @return Interpolated value.
///
/// @see smooth_step
template <std::size_t N, typename T>
inline Vector<N, T> smooth_step(const Vector<N, T>& value, const T& edge0, const T& edge1)
{
    Vector<N, T> temp = clamp((value - edge0) / (edge1 - edge0), T{0}, T{1});
    return temp * temp * (T{3} - T{2} * temp);
}

/// @brief Performs Hermite interpolation between two values.
///
/// @param value Specifies the source value for interpolation.
/// @param edge0 Specifies the value of the lower edge of the Hermite function.
/// @param edge1 Specifies the value of the upper edge of the Hermite function.
///
/// @return Interpolated value.
///
/// @see smooth_step
template <std::size_t N, typename T>
inline Vector<N, T> smooth_step(const Vector<N, T>& value, const Vector<N, T>& edge0, const Vector<N, T>& edge1)
{
    Vector<N, T> temp = clamp((value - edge0) / (edge1 - edge0), T{0}, T{1});
    return temp * temp * (T{3} - T{2} * temp);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name isnan
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Determines if the given floating-point number
///        is a not-a-number (NaN) value.
///
/// @param value The floating-point value.
///
/// @return `true` if value is a NaN, `false` otherwise.
template <typename T>
inline bool isnan(const T& value)
{
    return ::std::isnan(value);
}

/// @brief Determines if components of given vector
///        is a not-a-number (NaN) value.
///
/// @param value Vector of floating-point values.
///
/// @return For each component return `true` if it is a NaN, `false` otherwise.
template <std::size_t N, typename T>
inline Vector<N, bool> isnan(const Vector<N, T>& value)
{
    return transform(value, framework::math::isnan<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name isinf
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Determines if the given floating-point number
///        is a positive or negative infinity.
///
/// @param value The floating-point value.
///
/// @return `true` if value is infinite, `false` otherwise.
template <typename T>
inline bool isinf(const T& value)
{
    return ::std::isinf(value);
}

/// @brief Determines if components of given vector
///        is a positive or negative infinity.
///
/// @param value Vector of floating-point values.
///
/// @return For each component return `true` if it is infinite,
///         `false` otherwise.
template <std::size_t N, typename T>
inline constexpr Vector<N, bool> isinf(const Vector<N, T>& value)
{
    return transform(value, framework::math::isinf<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name fma
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes `(a * b) + z` as if to infinite precision and rounded
///        only once to fit the result type.
///
/// @param a Value of floating-point or integral type.
/// @param b Value of floating-point or integral type.
/// @param c Value of floating-point or integral type.
///
/// @return Value which is equivalent to `(a * b) + c`.
template <typename T>
inline T fma(const T& a, const T& b, const T& c)
{
    return ::std::fma(a, b, c);
}

/// @brief Computes `(a * b) + z` for each component of the vector.
///
/// @param a Vector of floating-point or integral values.
/// @param b Vector of floating-point or integral values.
/// @param c Vector of floating-point or integral values.
///
/// @return Vector which is equivalent to `(a * b) + c`.
template <std::size_t N, typename T>
inline Vector<N, T> fma(const Vector<N, T>& a, const Vector<N, T>& b, const Vector<N, T>& c)
{
    return a * b + c;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name frexp
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Decomposes given floating-point value into a normalized fraction
///        and an integral power of two.
///
/// @param value Floating-point value.
/// @param exp Poiner to integer value to store the exponent to.
///
/// @return If value is zero, returns zero and stores zero in exp.
///         Otherwise, returns the value x in the range (-1;-0.5], [0.5; 1)
///         and stores an integer value in exp such that `x * 2 ^ exp = value`.
template <typename T, typename R = decltype(::std::frexp(std::declval<T>(), std::declval<std::int32_t*>()))>
inline R frexp(const T& value, std::int32_t* exp)
{
    return ::std::frexp(value, exp);
}

/// @brief Decomposes each component of given vector into a normalized fraction
///        and an integral power of two.
///
/// @param value Vector of floating-point values.
/// @param exp Pointer to integer vector to store the exponent to.
///
/// @return For each component of value, if it is zero, returns zero
///         and stores zero in exp.
///         Otherwise, returns the value x in the range (-1;-0.5], [0.5; 1)
///         and stores an integer value in exp such that `x * 2 ^ exp = value`.
template <std::size_t N,
          typename T,
          typename R = decltype(::std::frexp(std::declval<T>(), std::declval<std::int32_t*>()))>
inline Vector<N, R> frexp(const Vector<N, T>& value, Vector<N, std::int32_t>* exp)
{
    return common_functions_details::frexp<T, R>(value, exp);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name ldexp
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Multiplies a given value by the number 2 raised to the exp power.
///
/// @param value Floating-point value.
/// @param exp Integer value.
///
/// @return Value which is equivalent to value multiplied by 2 to the power
///         of exp: `value * 2 ^ exp`.
template <typename T, typename R = decltype(::std::ldexp(std::declval<T>(), std::declval<std::int32_t>()))>
inline R ldexp(const T& value, const std::int32_t exp)
{
    return ::std::ldexp(value, exp);
}

/// @brief Multiplies each component of a given vector by the number 2 raised
///        to the exp component power.
///
/// @param value Vector of floating-point values.
/// @param exp Vector of integer values.
///
/// @return Vector which components are equivalent to value multiplied
///         by 2 to the power of exp: `value * 2 ^ exp`.
template <std::size_t N, typename T, typename R = decltype(::std::ldexp(std::declval<T>(), std::declval<std::int32_t>()))>
inline Vector<N, R> ldexp(const Vector<N, T>& value, const Vector<N, std::int32_t>& exp)
{
    return transform(value, exp, framework::math::ldexp<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
