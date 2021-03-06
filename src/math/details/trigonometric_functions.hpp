/// @file
/// @brief Contains trigonometric math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_MATH_DETAILS
#error You should include math/math.hpp instead of trigonometric_functions.hpp
#endif

#ifndef FRAMEWORK_MATH_DETAILS_TRIGONOMETRIC_FUNCTIONS_HPP
#define FRAMEWORK_MATH_DETAILS_TRIGONOMETRIC_FUNCTIONS_HPP

#include <cmath>

#include <common/types.hpp>
#include <math/details/constants.hpp>
#include <math/details/vector_type.hpp>

namespace framework
{
namespace math
{
/// @addtogroup math_trigonometric_functions
/// @{

/// @name radians
/// @{

/// @brief Converts degrees to radians.
///
/// @param degrees Value of floating-point or integral type.
///
/// @return The value in radians.
template <typename T, typename R = typename vector_type_details::common_type<decltype(deg_to_rad), T>::type>
inline T radians(const T& degrees)
{
    return static_cast<T>(static_cast<R>(deg_to_rad) * static_cast<R>(degrees));
}

/// @brief Perform a component-wise conversion degrees to radians.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector of values in radians.
template <uint32 N, typename T>
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
template <typename T, typename R = typename vector_type_details::common_type<decltype(rad_to_deg), T>::type>
inline T degrees(const T& radians)
{
    return static_cast<T>(static_cast<R>(rad_to_deg) * static_cast<R>(radians));
}

/// @brief Perform a component-wise conversion radians to degrees.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector of values in degrees.
template <uint32 N, typename T>
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
template <uint32 N, typename T, typename R = decltype(::framework::math::sin(std::declval<T>()))>
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
template <uint32 N, typename T, typename R = decltype(::framework::math::cos(std::declval<T>()))>
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
template <uint32 N, typename T, typename R = decltype(::framework::math::tan(std::declval<T>()))>
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
template <uint32 N, typename T, typename R = decltype(::framework::math::asin(std::declval<T>()))>
inline vector<N, R> asin(vector<N, T> const& value)
{
    return transform(value, ::framework::math::asin<T>);
}
/// @}

/// @name acos
/// @{

/// @brief Computes the principal value of the arc-cosine of value.
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
template <uint32 N, typename T, typename R = decltype(::framework::math::acos(std::declval<T>()))>
inline vector<N, R> acos(vector<N, T> const& value)
{
    return transform(value, ::framework::math::acos<T>);
}
/// @}

/// @name atan
/// @{

/// @brief Computes the arc tangent of `a / b`.
///
/// The signs of x and y are used to determine what quadrant the angle is in.
/// Results are undefined if a and b are both 0.
///
/// @param a Value of a floating-point or integral type.
/// @param b Value of a floating-point or integral type.
///
/// @return The angle in radians in the range [-PI, PI].
template <typename T, typename R = decltype(::std::atan2(std::declval<T>(), std::declval<T>()))>
inline R atan(const T& a, const T& b)
{
    return ::std::atan2(a, b);
}

/// @brief Computes the arc tangent of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The angle in radians in the range [-PI/2, PI/2].
template <typename T, typename R = decltype(::std::atan(std::declval<T>()))>
inline R atan(const T& value)
{
    return ::std::atan(value);
}

/// @brief Applies the atan function to every component of the vectors.
///
/// @param a Vector of a floating-point or integral type.
/// @param b Vector of a floating-point or integral type.
///
/// @return The vector of angles in radians in the range [-PI, PI].
///
/// @see atan
template <uint32 N, typename T, typename R = decltype(::framework::math::atan(std::declval<T>(), std::declval<T>()))>
inline vector<N, R> atan(vector<N, T> const& a, vector<N, T> const& b)
{
    return transform(a, b, [](const T& a_component, const T& b_component) {
        return ::framework::math::atan(a_component, b_component);
    });
}

/// @brief Applies the atan function to every component of the vectors.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of angles in radians in the range [-PI/2, PI/2].
///
/// @see atan
template <uint32 N, typename T, typename R = decltype(::framework::math::atan(std::declval<T>()))>
inline vector<N, R> atan(vector<N, T> const& value)
{
    return transform(value, [](const T& value_component) { return ::framework::math::atan(value_component); });
}
/// @}

/// @name sinh
/// @{

/// @brief Computes the hyperbolic sine of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The hyperbolic sine of value, `(e ^ value - e ^ value) / 2`.
template <typename T, typename R = decltype(::std::sinh(std::declval<T>()))>
inline R sinh(const T& value)
{
    return ::std::sinh(value);
}

/// @brief Applies the sinh function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of hyperbolic sines.
///
/// @see sinh
template <uint32 N, typename T, typename R = decltype(::framework::math::sinh(std::declval<T>()))>
inline vector<N, R> sinh(vector<N, T> const& value)
{
    return transform(value, ::framework::math::sinh<T>);
}
/// @}

/// @name cosh
/// @{

/// @brief Computes the hyperbolic cosine of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The hyperbolic cosine of value, `(e ^ value + e ^(-value)) / 2`.
template <typename T, typename R = decltype(::std::cosh(std::declval<T>()))>
inline R cosh(const T& value)
{
    return ::std::cosh(value);
}

/// @brief Applies the cosh function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of hyperbolic cosines.
///
/// @see cosh
template <uint32 N, typename T, typename R = decltype(::framework::math::cosh(std::declval<T>()))>
inline vector<N, R> cosh(vector<N, T> const& value)
{
    return transform(value, ::framework::math::cosh<T>);
}
/// @}

/// @name tanh
/// @{

/// @brief Computes the hyperbolic tangent of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The hyperbolic tangent of value.
template <typename T, typename R = decltype(::std::tanh(std::declval<T>()))>
inline R tanh(const T& value)
{
    return ::std::tanh(value);
}

/// @brief Applies the tanh function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of hyperbolic tangents.
///
/// @see tanh
template <uint32 N, typename T, typename R = decltype(::framework::math::tanh(std::declval<T>()))>
inline vector<N, R> tanh(vector<N, T> const& value)
{
    return transform(value, ::framework::math::tanh<T>);
}
/// @}

/// @name asinh
/// @{

/// @brief Computes the inverse hyperbolic sine of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The hyperbolic sine of value.
template <typename T, typename R = decltype(::std::asinh(std::declval<T>()))>
inline R asinh(const T& value)
{
    return ::std::asinh(value);
}

/// @brief Applies the asinh function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of hyperbolic sines.
///
/// @see asinh
template <uint32 N, typename T, typename R = decltype(::framework::math::asinh(std::declval<T>()))>
inline vector<N, R> asinh(vector<N, T> const& value)
{
    return transform(value, ::framework::math::asinh<T>);
}
/// @}

/// @name acosh
/// @{

/// @brief Computes the inverse hyperbolic cosine of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The hyperbolic cosine of value.
template <typename T, typename R = decltype(::std::acosh(std::declval<T>()))>
inline R acosh(const T& value)
{
    return ::std::acosh(value);
}

/// @brief Applies the acosh function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of hyperbolic cosines.
///
/// @see acosh
template <uint32 N, typename T, typename R = decltype(::framework::math::acosh(std::declval<T>()))>
inline vector<N, R> acosh(vector<N, T> const& value)
{
    return transform(value, ::framework::math::acosh<T>);
}
/// @}

/// @name atanh
/// @{

/// @brief Computes the inverse hyperbolic tangent of value.
///
/// @param value Value of a floating-point or integral type.
///
/// @return The hyperbolic tangent of value.
template <typename T, typename R = decltype(::std::atanh(std::declval<T>()))>
inline R atanh(const T& value)
{
    return ::std::atanh(value);
}

/// @brief Applies the atanh function to every component of the vector.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of hyperbolic tangents.
///
/// @see atanh
template <uint32 N, typename T, typename R = decltype(::framework::math::atanh(std::declval<T>()))>
inline vector<N, R> atanh(vector<N, T> const& value)
{
    return transform(value, ::framework::math::atanh<T>);
}
/// @}

/// @}

} // namespace math

} // namespace framework

#endif
