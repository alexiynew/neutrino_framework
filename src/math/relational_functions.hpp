/// @file
/// @brief Contains relational math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017

#ifndef FRAMEWORK_MATH_RELATIONAL_FUNCTIONS_HPP
#define FRAMEWORK_MATH_RELATIONAL_FUNCTIONS_HPP

#include <functional>

#include <common/types.hpp>
#include <math/common_functions.hpp>
#include <math/matrix_type.hpp>
#include <math/relational_functions_details.hpp>
#include <math/vector_type.hpp>

namespace framework
{
namespace math
{
/// @addtogroup relational_functions
/// @{

/// @name less
/// @{

/// @brief Perform a component-wise less-than comparison of two vectors.
///
/// @param lhs Specifies the first vector to be used in the comparison operation.
/// @param rhs Specifies the second vector to be used in the comparison operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] < rhs[i]`.
template <uint32 N, typename T>
inline vector<N, bool> less(const vector<N, T>& lhs, const vector<N, T>& rhs)
{
    return transform(lhs, rhs, [](const T& a, const T& b) { return a < b; });
}
/// @}

/// @name less_equal
/// @{

/// @brief Perform a component-wise less-than-or-equal comparison of two vectors.
///
/// @param lhs Specifies the first vector to be used in the comparison operation.
/// @param rhs Specifies the second vector to be used in the comparison operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] <= rhs[i]`.
template <uint32 N, typename T>
inline vector<N, bool> less_equal(const vector<N, T>& lhs, const vector<N, T>& rhs)
{
    return transform(lhs, rhs, [](const T& a, const T& b) { return a <= b; });
}
/// @}

/// @name greater
/// @{

/// @brief Perform a component-wise greater-than comparison of two vectors.
///
/// @param lhs Specifies the first vector to be used in the comparison operation.
/// @param rhs Specifies the second vector to be used in the comparison operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] < rhs[i]`.
template <uint32 N, typename T>
inline vector<N, bool> greater(const vector<N, T>& lhs, const vector<N, T>& rhs)
{
    return transform(lhs, rhs, [](const T& a, const T& b) { return a > b; });
}
/// @}

/// @name greater_equal
/// @{

/// @brief Perform a component-wise greater-than-or-equal comparison of two vectors.
///
/// @param lhs Specifies the first vector to be used in the comparison operation.
/// @param rhs Specifies the second vector to be used in the comparison operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] <= rhs[i]`.
template <uint32 N, typename T>
inline vector<N, bool> greater_equal(const vector<N, T>& lhs, const vector<N, T>& rhs)
{
    return transform(lhs, rhs, [](const T& a, const T& b) { return a >= b; });
}
/// @}

/// @name equal
/// @{

/// @brief Perform a component-wise equal comparison of two vectors.
///
/// @param lhs Specifies the first vector to be used in the comparison operation.
/// @param rhs Specifies the second vector to be used in the comparison operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] == rhs[i]`.
template <uint32 N, typename T>
inline vector<N, bool> equal(const vector<N, T>& lhs, const vector<N, T>& rhs)
{
    return transform(lhs, rhs, std::equal_to<T>{});
}
/// @}

/// @name not_equal
/// @{

/// @brief Perform a component-wise not-equal-to comparison of two vectors.
///
/// @param lhs Specifies the first vector to be used in the comparison operation.
/// @param rhs Specifies the second vector to be used in the comparison operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] != rhs[i]`.
template <uint32 N, typename T>
inline vector<N, bool> not_equal(const vector<N, T>& lhs, const vector<N, T>& rhs)
{
    return transform(lhs, rhs, std::not_equal_to<T>{});
}
/// @}

/// @name almost_equal
/// @{

/// @brief Compares two values with desired precision.
///
/// The machine epsilon scaled to the magnitude of the values used and
/// multiplied by the desired precision in ULPs (units in the last place) unless the result is subnormal.
///
/// @param a Floating-point or integral value.
/// @param b Floating-point or integral value.
/// @param ulp Units in the last place.
///
/// @return `true` if provided values are equal, `false` otherwise.
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int32>::type = 0>
inline bool almost_equal(const T& a, const T& b, int32 ulp = 0)
{
    return relational_functions_details::almost_equal_implementation(a, b, ulp, std::is_floating_point<T>{});
}

/// @brief Compares elements of two vectors with desired precision.
///
/// The machine epsilon scaled to the magnitude of the values used and
/// multiplied by the desired precision in ULPs (units in the last place) unless the result is subnormal.
///
/// @param a Floating-point or integral vector.
/// @param b Floating-point or integral vector.
/// @param ulp Units in the last place.
///
/// @return `true` if provided vectors are equal, `false` otherwise.
template <uint32 N, typename T>
inline bool almost_equal(const vector<N, T>& a, const vector<N, T>& b, int32 ulp = 0)
{
    return relational_functions_details::almost_equal_implementation(a, b, ulp);
}

/// @brief Compares elements of two matrices with desired precision.
///
/// The machine epsilon scaled to the magnitude of the values used and
/// multiplied by the desired precision in ULPs (units in the last place) unless the result is subnormal.
///
/// @param a Floating-point or integral matrix.
/// @param b Floating-point or integral matrix.
/// @param ulp Units in the last place.
///
/// @return `true` if provided matrices are equal, `false` otherwise.
template <uint32 C, uint32 R, typename T>
inline bool almost_equal(const matrix<C, R, T>& a, const matrix<C, R, T>& b, int32 ulp = 0)
{
    return relational_functions_details::almost_equal_implementation(a, b, ulp);
}
/// @}

/// @name logical_not
/// @{

/// @brief Perform a component-wise the logical-not operation on a vector.
///
/// @param value Specifies the vector to be used in the operation.
///
/// @return The boolean vector in which each element i is computed as `!value[i]`.
template <uint32 N>
inline vector<N, bool> logical_not(const vector<N, bool>& value)
{
    return transform(value, [](const bool a) { return !a; });
}
/// @}

/// @name logical_and
/// @{

/// @brief Perform a component-wise logical-and operation on two vectors.
///
/// @param lhs Specifies the first vector to be used in the operation.
/// @param rhs Specifies the second vector to be used in the operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] && rhs[i]`.
template <uint32 N>
inline vector<N, bool> logical_and(const vector<N, bool>& lhs, const vector<N, bool>& rhs)
{
    return transform(lhs, rhs, [](const bool a, const bool b) { return a && b; });
}
/// @}

/// @name logical_or
/// @{

/// @brief Perform a component-wise logical-or operation on two vectors.
///
/// @param lhs Specifies the first vector to be used in the operation.
/// @param rhs Specifies the second vector to be used in the operation.
///
/// @return The boolean vector in which each element i is computed as `lhs[i] || rhs[i]`.
template <uint32 N>
inline vector<N, bool> logical_or(const vector<N, bool>& lhs, const vector<N, bool>& rhs)
{
    return transform(lhs, rhs, [](const bool a, const bool b) { return a || b; });
}
/// @}

/// @name any
/// @{

/// @brief Check whether any element of a boolean vector is true.
///
/// @param value Specifies the vector to be tested for truth.
///
/// @return `true` if any component of value are true.
template <uint32 N>
inline bool any(const vector<N, bool>& value)
{
    return relational_functions_details::any_implementation(value);
}
/// @}

/// @name all
/// @{

/// @brief Check whether all elements of a boolean vector are true.
///
/// @param value Specifies the vector to be tested for truth.
///
/// @return `true` if all components of value are true.
template <uint32 N>
inline bool all(const vector<N, bool>& value)
{
    return relational_functions_details::all_implementation(value);
}
/// @}

/// @}

} // namespace math

} // namespace framework

#endif
