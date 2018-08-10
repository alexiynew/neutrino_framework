/// @file
/// @brief Implementation of matrix type.
/// @author Fedorov Alexey
/// @date 11.07.2017

#ifndef FRAMEWORK_MATH_DETAILS
#error You should include math/math.hpp instead of matrix_type_details.hpp
#endif

#ifndef FRAMEWORK_MATH_MATRIX_TYPE_DETAILS_HPP
#define FRAMEWORK_MATH_MATRIX_TYPE_DETAILS_HPP

#include <common/types.hpp>
#include <math/details/vector_type.hpp>

namespace framework
{
namespace math
{
/// @brief Contains matrix type implementation details.
namespace matrix_type_details
{
/// @brief Helper functions to implement matrix constructors.
/// @{
template <typename T, typename U>
inline constexpr T combine(const U& first, const T& /*unused*/) noexcept
{
    return static_cast<T>(first);
}

template <typename T, typename U>
inline constexpr vector<4, T> combine(const vector<3, U>& first, const vector<4, T>& second) noexcept
{
    return vector<4, T>(first, second.w);
}

template <typename T, typename U>
inline constexpr vector<4, T> combine(const vector<2, U>& first, const vector<4, T>& second) noexcept
{
    return vector<4, T>(first, second.z, second.w);
}

template <typename T, typename U>
inline constexpr vector<3, T> combine(const vector<2, U>& first, const vector<3, T>& second) noexcept
{
    return vector<3, T>(first, second.z);
}

template <uint32 N, typename M, typename V>
inline constexpr V get_column_implementation(M&& matrix, V&& vector, std::true_type /*unused*/) noexcept
{
    return combine(std::forward<M>(matrix)[N], std::forward<V>(vector));
}

template <uint32 N, typename M, typename V>
inline constexpr V get_column_implementation(M&& /*unused*/, V&& vector, std::false_type /*unused*/) noexcept
{
    return std::forward<V>(vector);
}

template <uint32 N, uint32 C, typename M, typename V>
inline constexpr V get_column(M&& matrix, V&& vector) noexcept
{
    return get_column_implementation<N>(std::forward<M>(matrix),
                                        std::forward<V>(vector),
                                        std::integral_constant<bool, (N < C)>{});
}
/// @}

/// @brief Shortcut to get the common type.
/// Also used for SFINAE to get correct overload of vector operators.
template <typename... Args>
using common_type = vector_type_details::common_type<Args...>;

} // namespace matrix_type_details

} // namespace math

} // namespace framework

#endif
