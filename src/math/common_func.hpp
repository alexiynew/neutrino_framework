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
template <typename T, bool B>
struct abs_details
{
};

template <typename T>
struct abs_details<T, true>
{
    constexpr T operator()(const T& v)
    {
        return (v < T{0}) ? -v : v;
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

/**
 * @}
 */

/**
 * @brief Realization of sign function.
 * @{
 */
template <typename T, bool B>
struct sign_details
{
};

template <typename T>
struct sign_details<T, true>
{
    constexpr T operator()(const T& v)
    {
        return static_cast<T>((T{0} < v) - (v < T{0}));
    }
};

template <typename T>
struct sign_details<T, false>
{
    constexpr T operator()(const T& v)
    {
        return static_cast<T>(T{0} < v);
    }
};

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
    return common_functions_details::abs_details<T, std::numeric_limits<T>::is_signed>()(value);
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
template <typename T>
inline constexpr vector<4, T> abs(const vector<4, T>& value)
{
    using ::framework::math::abs;
    return vector<4, T>(abs(value.x), abs(value.y), abs(value.z), abs(value.w));
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
template <typename T>
inline constexpr vector<3, T> abs(const vector<3, T>& value)
{
    using ::framework::math::abs;
    return vector<3, T>(abs(value.x), abs(value.y), abs(value.z));
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
template <typename T>
inline constexpr vector<2, T> abs(const vector<2, T>& value)
{

    using ::framework::math::abs;
    return vector<2, T>(abs(value.x), abs(value.y));
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
    return common_functions_details::sign_details<T, std::numeric_limits<T>::is_signed>()(value);
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
template <typename T>
inline constexpr vector<4, T> sign(const vector<4, T>& value)
{
    using ::framework::math::sign;
    return vector<4, T>(sign(value.x), sign(value.y), sign(value.z), sign(value.w));
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
template <typename T>
inline constexpr vector<3, T> sign(const vector<3, T>& value)
{
    using ::framework::math::sign;
    return vector<3, T>(sign(value.x), sign(value.y), sign(value.z));
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
template <typename T>
inline constexpr vector<2, T> sign(const vector<2, T>& value)
{
    using ::framework::math::sign;
    return vector<2, T>(sign(value.x), sign(value.y));
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

template <unsigned int N, typename T, typename R = decltype(::framework::math::floor<T>(std::declval<T>()))>
inline vector<N, R> floor(const vector<N, T>& value)
{
    return transform(value, ::framework::math::floor<T>);
}


//
// /**
//  * @brief Applies the floor function to every component of the vector.
//  *
//  * @param value Vector of floating-point or integral type values.
//  *
//  * @return A vector of values that are the largest integer value not greater than argument.
//  *
//  * @see floor
//  */
// template <typename T, typename R = decltype(::framework::math::floor(std::declval<T>()))>
// inline constexpr vector<4, R> floor(const vector<4, T>& value)
// {
//     using ::framework::math::floor;
//     return vector<4, R>(floor(value.x), floor(value.y), floor(value.z), floor(value.w));
// }
//
// /**
//  * @brief Applies the floor function to every component of the vector.
//  *
//  * @param value Vector of floating-point or integral type values.
//  *
//  * @return A vector of values that are the largest integer value not greater than argument.
//  *
//  * @see floor
//  */
// template <typename T, typename R = decltype(::framework::math::floor(std::declval<T>()))>
// inline constexpr vector<3, R> floor(const vector<3, T>& value)
// {
//     using ::framework::math::floor;
//     return vector<3, R>(floor(value.x), floor(value.y), floor(value.z));
// }
//
// /**
//  * @brief Applies the floor function to every component of the vector.
//  *
//  * @param value Vector of floating-point or integral type values.
//  *
//  * @return A vector of values that are the largest integer value not greater than argument.
//  *
//  * @see floor
//  */
// template <typename T, typename R = decltype(::framework::math::floor(std::declval<T>()))>
// inline constexpr vector<2, R> floor(const vector<2, T>& value)
// {
//     using ::framework::math::floor;
//     return vector<2, R>(floor(value.x), floor(value.y));
// }
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
using ::std::round;

/**
 * @brief Applies the round function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are equal to the nearest integer to the argument.
 *
 * @see std::round
 */
template <typename T>
inline constexpr vector<4, T> round(const vector<4, T>& value)
{
    using ::framework::math::round;
    return vector<4, T>(round(value.x), round(value.y), round(value.z), round(value.w));
}

/**
 * @brief Applies the round function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are equal to the nearest integer to the argument.
 *
 * @see std::round
 */
template <typename T>
inline constexpr vector<3, T> round(const vector<3, T>& value)
{
    using ::framework::math::round;
    return vector<3, T>(round(value.x), round(value.y), round(value.z));
}

/**
 * @brief Applies the round function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are equal to the nearest integer to the argument.
 *
 * @see std::round
 */
template <typename T>
inline constexpr vector<2, T> round(const vector<2, T>& value)
{
    using ::framework::math::round;
    return vector<2, T>(round(value.x), round(value.y));
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
using ::std::ceil;

/**
 * @brief Applies the ceil function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are greater than or equal to the argument.
 *
 * @see std::ceil
 */
template <typename T>
inline constexpr vector<4, T> ceil(const vector<4, T>& value)
{
    using ::framework::math::ceil;
    return vector<4, T>(ceil(value.x), ceil(value.y), ceil(value.z), ceil(value.w));
}

/**
 * @brief Applies the ceil function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are greater than or equal to the argument.
 *
 * @see std::ceil
 */
template <typename T>
inline constexpr vector<3, T> ceil(const vector<3, T>& value)
{
    using ::framework::math::ceil;
    return vector<3, T>(ceil(value.x), ceil(value.y), ceil(value.z));
}

/**
 * @brief Applies the ceil function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are greater than or equal to the argument.
 *
 * @see std::ceil
 */
template <typename T>
inline constexpr vector<2, T> ceil(const vector<2, T>& value)
{
    using ::framework::math::ceil;
    return vector<2, T>(ceil(value.x), ceil(value.y));
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
using ::std::trunc;

/**
 * @brief Applies the trunc function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are not greater in magnitude than argument.
 *
 * @see std::trunc
 */
template <typename T>
inline constexpr vector<4, T> trunc(const vector<4, T>& value)
{
    using ::framework::math::trunc;
    return vector<4, T>(trunc(value.x), trunc(value.y), trunc(value.z), trunc(value.w));
}

/**
 * @brief Applies the trunc function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are not greater in magnitude than argument.
 *
 * @see std::trunc
 */
template <typename T>
inline constexpr vector<3, T> trunc(const vector<3, T>& value)
{
    using ::framework::math::trunc;
    return vector<3, T>(trunc(value.x), trunc(value.y), trunc(value.z));
}

/**
 * @brief Applies the trunc function to every component of the vector.
 *
 * @param value Vector of floating-point or integral type values.
 *
 * @return A vector of values that are not greater in magnitude than argument.
 *
 * @see std::trunc
 */
template <typename T>
inline constexpr vector<2, T> trunc(const vector<2, T>& value)
{
    using ::framework::math::trunc;
    return vector<2, T>(trunc(value.x), trunc(value.y));
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
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline R fract(const T& value)
{
    return static_cast<R>(value - floor(value));
}

/**
 * @brief Creates a vector of the fractional parts of the argument.
 *
 * @param value Vector of floating-point values.
 *
 * @return A vector of the fractional parts.
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline constexpr vector<4, R> fract(const vector<4, T>& value)
{
    using ::framework::math::fract;
    return vector<4, R>(fract(value.x), fract(value.y), fract(value.z), fract(value.w));
}

/**
 * @brief Creates a vector of the fractional parts of the argument.
 *
 * @param value Vector of floating-point values.
 *
 * @return A vector of the fractional parts.
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline constexpr vector<3, R> fract(const vector<3, T>& value)
{
    using ::framework::math::fract;
    return vector<3, R>(fract(value.x), fract(value.y), fract(value.z));
}

/**
 * @brief Creates a vector of the fractional parts of the argument.
 *
 * @param value Vector of floating-point values.
 *
 * @return A vector of the fractional parts.
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline constexpr vector<2, R> fract(const vector<2, T>& value)
{
    using ::framework::math::fract;
    return vector<2, R>(fract(value.x), fract(value.y));
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
 * The floating-point remainder of the division operation is exactly the value:
 * @code a - b * floor(a / b) @endcode
 * The returned value has the same sign as a and is less than b in magnitude.
 *
 * @param a Value of floating-point or integral type.
 * @param b Value of floating-point or integral type.
 *
 * @return The floating-point remainder of the division operation.
 */
template <typename T>
inline T mod(const T& a, const T& b)
{
    return a - b * floor(a / b);
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
template <typename T>
inline constexpr vector<4, T> mod(const vector<4, T>& a, const T& b)
{
    using ::framework::math::mod;
    return vector<4, T>(mod(a.x, b), mod(a.y, b), mod(a.z, b), mod(a.w, b));
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
template <typename T>
inline constexpr vector<3, T> mod(const vector<3, T>& a, const T& b)
{
    using ::framework::math::mod;
    return vector<3, T>(mod(a.x, b), mod(a.y, b), mod(a.z, b));
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
template <typename T>
inline constexpr vector<2, T> mod(const vector<2, T>& a, const T& b)
{
    using ::framework::math::mod;
    return vector<2, T>(mod(a.x, b), mod(a.y, b));
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
template <typename T>
inline constexpr vector<4, T> mod(const vector<4, T>& a, const vector<4, T>& b)
{
    using ::framework::math::mod;
    return vector<4, T>(mod(a.x, b.x), mod(a.y, b.y), mod(a.z, b.z), mod(a.w, b.w));
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
template <typename T>
inline constexpr vector<3, T> mod(const vector<3, T>& a, const vector<3, T>& b)
{
    using ::framework::math::mod;
    return vector<3, T>(mod(a.x, b), mod(a.y, b), mod(a.z, b));
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
template <typename T>
inline constexpr vector<2, T> mod(const vector<2, T>& a, const vector<2, T>& b)
{
    using ::framework::math::mod;
    return vector<2, T>(mod(a.x, b.x), mod(a.y, b.y));
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
 *
 * @return A vector of the fractional parts.
 *
 * @see modf
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<4, R> modf(const vector<4, T>& value, vector<4, T>& integral)
{
    return vector<4, R>(
    modf(value.x, integral.x), modf(value.y, integral.y), modf(value.z, integral.z), modf(value.w, integral.w));
}

/**
 * @brief Decomposes given floating-point vector into integral and fractional parts.
 *
 * @param[in] value Vector of floating-point values.
 * @param[out] integral Vector of integral parts of the value.
 *
 * @return A vector of the fractional parts.
 *
 * @see modf
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<3, R> modf(const vector<3, T>& value, vector<3, T>& integral)
{
    return vector<3, R>(modf(value.x, integral.x), modf(value.y, integral.y), modf(value.z, integral.z));
}

/**
 * @brief Decomposes given floating-point vector into integral and fractional parts.
 *
 * @param[in] value Vector of floating-point values.
 * @param[out] integral Vector of integral parts of the value.
 *
 * @return A vector of the fractional parts.
 *
 * @see modf
 */
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<2, R> modf(const vector<2, T>& value, vector<2, T>& integral)
{
    return vector<2, R>(modf(value.x, integral.x), modf(value.y, integral.y));
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
 */
template <typename T>
inline constexpr vector<4, T> min(const vector<4, T>& a, const T& b)
{
    using ::framework::math::min;
    return vector<4, T>(min(a.x, b), min(a.y, b), min(a.z, b), min(a.w, b));
}

/**
 * @brief Compares vector with scalar value and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of smaller values.
 */
template <typename T>
inline constexpr vector<3, T> min(const vector<3, T>& a, const T& b)
{
    using ::framework::math::min;
    return vector<3, T>(min(a.x, b), min(a.y, b), min(a.z, b));
}


/**
 * @brief Compares vector with scalar value and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of smaller values.
 */
template <typename T>
inline constexpr vector<2, T> min(const vector<2, T>& a, const T& b)
{
    using ::framework::math::min;
    return vector<2, T>(min(a.x, b), min(a.y, b));
}

/**
 * @brief Compares two vectors by components and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of smaller values.
 */
template <typename T>
inline constexpr vector<4, T> min(const vector<4, T>& a, const vector<4, T>& b)
{
    using ::framework::math::min;
    return vector<4, T>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
}

/**
 * @brief Compares two vectors by components and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of smaller values.
 */
template <typename T>
inline constexpr vector<3, T> min(const vector<3, T>& a, const vector<3, T>& b)
{
    using ::framework::math::min;
    return vector<3, T>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}

/**
 * @brief Compares two vectors by components and return a vector of smaller values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of smaller values.
 */
template <typename T>
inline constexpr vector<2, T> min(const vector<2, T>& a, const vector<2, T>& b)
{
    using ::framework::math::min;
    return vector<2, T>(min(a.x, b.x), min(a.y, b.y));
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
 */
template <typename T>
inline constexpr vector<4, T> max(const vector<4, T>& a, const T& b)
{
    using ::framework::math::max;
    return vector<4, T>(max(a.x, b), max(a.y, b), max(a.z, b), max(a.w, b));
}

/**
 * @brief Compares vector with scalar value and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of greater values.
 */
template <typename T>
inline constexpr vector<3, T> max(const vector<3, T>& a, const T& b)
{
    using ::framework::math::max;
    return vector<3, T>(max(a.x, b), max(a.y, b), max(a.z, b));
}

/**
 * @brief Compares vector with scalar value and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Value of floating-point or integral type.
 *
 * @return A vector of greater values.
 */
template <typename T>
inline constexpr vector<2, T> max(const vector<2, T>& a, const T& b)
{
    using ::framework::math::max;
    return vector<2, T>(max(a.x, b), max(a.y, b));
}

/**
 * @brief Compares two vectors by components and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of greater values.
 */
template <typename T>
inline constexpr vector<4, T> max(const vector<4, T>& a, const vector<4, T>& b)
{
    using ::framework::math::max;
    return vector<4, T>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
}

/**
 * @brief Compares two vectors by components and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of greater values.
 */
template <typename T>
inline constexpr vector<3, T> max(const vector<3, T>& a, const vector<3, T>& b)
{
    using ::framework::math::max;
    return vector<3, T>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}

/**
 * @brief Compares two vectors by components and return a vector of greater values.
 *
 * @param a Vector of floating-point or integral type values.
 * @param b Vector of floating-point or integral type values.
 *
 * @return A vector of greater values.
 */
template <typename T>
inline constexpr vector<2, T> max(const vector<2, T>& a, const vector<2, T>& b)
{
    using ::framework::math::max;
    return vector<2, T>(max(a.x, b.x), max(a.y, b.y));
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
    using ::framework::math::min;
    using ::framework::math::max;
    return min(max(value, min_value), max_value);
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
    using ::framework::math::min;
    using ::framework::math::max;
    return min(max(value, min_value), max_value);
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
    using ::framework::math::min;
    using ::framework::math::max;
    return min(max(value, min_value), max_value);
}
/**
 * @}
 */

/**
 * @name mix
 * @{
 */

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
