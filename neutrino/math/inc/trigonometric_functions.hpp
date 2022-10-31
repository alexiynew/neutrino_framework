#ifndef MATH_INC_TRIGONOMETRIC_FUNCTIONS_HPP
#define MATH_INC_TRIGONOMETRIC_FUNCTIONS_HPP

#include <cmath>
#include <type_traits>

#include <math/inc/constants.hpp>
#include <math/inc/vector_type.hpp>

namespace neutrino::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_trigonometric_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name radians
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Converts degrees to radians.
///
/// @param degrees Value of floating-point or integral type.
///
/// @return The value in radians.
template <typename T, typename R = std::common_type_t<double, T>>
inline R radians(const T& degrees)
{
    return deg_to_rad<R> * static_cast<R>(degrees);
}

/// @brief Perform a component-wise conversion degrees to radians.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector of values in radians.
template <std::size_t N, typename T>
inline Vector<N, T> radians(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::radians<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name degrees
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Converts radians to degrees.
///
/// @param radians Value of floating-point or integral type.
///
/// @return The value in degrees.
template <typename T, typename R = std::common_type_t<double, T>>
inline R degrees(const T& radians)
{
    return rad_to_deg<R> * static_cast<R>(radians);
}

/// @brief Perform a component-wise conversion radians to degrees.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector of values in degrees.
template <std::size_t N, typename T>
inline Vector<N, T> degrees(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::degrees<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name sin
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::sin(std::declval<T>()))>
inline Vector<N, R> sin(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::sin<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name cos
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::cos(std::declval<T>()))>
inline Vector<N, R> cos(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::cos<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name tan
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::tan(std::declval<T>()))>
inline Vector<N, R> tan(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::tan<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name asin
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::asin(std::declval<T>()))>
inline Vector<N, R> asin(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::asin<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name acos
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::acos(std::declval<T>()))>
inline Vector<N, R> acos(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::acos<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name atan
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::atan(std::declval<T>(), std::declval<T>()))>
inline Vector<N, R> atan(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return transform(a, b, [](const T& a_component, const T& b_component) {
        return neutrino::math::atan(a_component, b_component);
    });
}

/// @brief Applies the atan function to every component of the vectors.
///
/// @param value Vector of a floating-point or integral type.
///
/// @return The vector of angles in radians in the range [-PI/2, PI/2].
///
/// @see atan
template <std::size_t N, typename T, typename R = decltype(neutrino::math::atan(std::declval<T>()))>
inline Vector<N, R> atan(const Vector<N, T>& value)
{
    return transform(value, [](const T& value_component) { return neutrino::math::atan(value_component); });
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name sinh
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::sinh(std::declval<T>()))>
inline Vector<N, R> sinh(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::sinh<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name cosh
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::cosh(std::declval<T>()))>
inline Vector<N, R> cosh(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::cosh<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name tanh
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::tanh(std::declval<T>()))>
inline Vector<N, R> tanh(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::tanh<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name asinh
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::asinh(std::declval<T>()))>
inline Vector<N, R> asinh(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::asinh<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name acosh
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::acosh(std::declval<T>()))>
inline Vector<N, R> acosh(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::acosh<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name atanh
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
template <std::size_t N, typename T, typename R = decltype(neutrino::math::atanh(std::declval<T>()))>
inline Vector<N, R> atanh(const Vector<N, T>& value)
{
    return transform(value, neutrino::math::atanh<T>);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::math

#endif
