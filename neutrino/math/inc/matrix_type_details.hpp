#ifndef MATH_INC_MATRIX_TYPE_DETAILS_HPP
#define MATH_INC_MATRIX_TYPE_DETAILS_HPP

#include <math/inc/vector_type.hpp>

namespace neutrino::math::matrix_type_details
{

template <typename T, typename U>
inline constexpr T combine(const U& first, const T& /*unused*/) noexcept
{
    return static_cast<T>(first);
}

template <typename T, typename U>
inline constexpr Vector<4, T> combine(const Vector<3, U>& first, const Vector<4, T>& second) noexcept
{
    return Vector<4, T>(first, second.w);
}

template <typename T, typename U>
inline constexpr Vector<4, T> combine(const Vector<2, U>& first, const Vector<4, T>& second) noexcept
{
    return Vector<4, T>(first, second.z, second.w);
}

template <typename T, typename U>
inline constexpr Vector<3, T> combine(const Vector<2, U>& first, const Vector<3, T>& second) noexcept
{
    return Vector<3, T>(first, second.z);
}

template <std::size_t N, typename M, typename V>
inline constexpr V get_column_implementation(M&& Matrix, V&& vector, std::true_type /*unused*/) noexcept
{
    return combine(std::forward<M>(Matrix)[N], std::forward<V>(vector));
}

template <std::size_t N, typename M, typename V>
inline constexpr V get_column_implementation(M&& /*unused*/, V&& vector, std::false_type /*unused*/) noexcept
{
    return std::forward<V>(vector);
}

template <std::size_t N, std::size_t C, typename M, typename V>
inline constexpr V get_column(M&& Matrix, V&& vector) noexcept
{
    return get_column_implementation<N>(std::forward<M>(Matrix),
                                        std::forward<V>(vector),
                                        std::integral_constant<bool, (N < C)>{});
}

} // namespace neutrino::math::matrix_type_details

#endif
