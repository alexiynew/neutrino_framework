/// @file
/// @brief Implementation of geometric vector.
/// @author Fedorov Alexey
/// @date 12.03.2017

#ifndef FRAMEWORK_MATH_VECTOR_TYPE_DETAILS_HPP
#define FRAMEWORK_MATH_VECTOR_TYPE_DETAILS_HPP

#include <common/common_types.hpp>
#include <functional>

namespace framework {

namespace math {

/// @brief Contains vector type implementation details.
namespace vector_type_details {

/// @brief Workaround to cast float numbers to bool without warnings.
/// @{

/// Common template.
template <typename T>
struct cast_to
{
    /// @brief Casts value to a specified type.
    template <typename U, typename R = typename std::enable_if<std::is_arithmetic<U>::value, T>::type>
    inline static constexpr R from(const U& value) noexcept
    {
        return static_cast<R>(value);
    }
};

/// @brief Workaround to cast float numbers to bool without warnings.
/// Specialization for boolean type.
template <>
struct cast_to<bool>
{
    /// @brief Casts value to a specified type.
    template <typename U, typename R = typename std::enable_if<std::is_arithmetic<U>::value, bool>::type>
    inline static constexpr R from(const U& value) noexcept
    {
        return std::not_equal_to<U>()(value, U{0});
    }
};
/// @}

/// @brief Helper that checks if all presented types are arithmetic.
/// @{

/// Common template.
template <typename T, typename... Args>
struct are_all_arithmetic
{
    /// @brief `true` if all provided types are arithmetic.
    static constexpr bool value = std::is_arithmetic<T>::value && are_all_arithmetic<Args...>::value;
};

/// @brief Helper that checks if all presented types are arithmetic.
/// Specialization for one type.
template <typename T>
struct are_all_arithmetic<T>
{
    /// @brief `true` if provided type are arithmetic.
    static constexpr bool value = std::is_arithmetic<T>::value;
};
/// @}

/// @brief Helper that give common type for all presented types.
/// @{

/// Common template.
template <typename T, typename... Args>
struct common_type_details
{
    /// @brief Common type for all provided types.
    using type = typename std::common_type<T, typename common_type_details<Args...>::type>::type;
};

/// @brief Helper that give common type for all presented types.
/// Specialization for one type.
template <typename T>
struct common_type_details<T>
{
    /// @brief Common type is T.
    using type = T;
};

/// @brief Shortcut to get the common type.
/// Also used for SFINAE to get correct overload of vector operators.
template <typename... Args>
using common_type = typename std::enable_if<are_all_arithmetic<Args...>::value, common_type_details<Args...>>::type;
/// @}

/// @brief Implementation of transform function.
/// @{
template <uint32 N>
struct transform_details;

/// @brief Implementation of transform function.
/// Specialization for vector of 4 components.
template <>
struct transform_details<4>
{
    /// @brief Creates new vector of type R with provided function and arguments.
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value) noexcept
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...),
                 std::forward<F>(function)(std::forward<Args>(value).z...),
                 std::forward<F>(function)(std::forward<Args>(value).w...));
    }
};

/// @brief Implementation of transform function.
/// Specialization for vector of 3 components.
template <>
struct transform_details<3>
{
    /// @brief Creates new vector of type R with provided function and arguments.
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value) noexcept
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...),
                 std::forward<F>(function)(std::forward<Args>(value).z...));
    }
};

/// @brief Implementation of transform function.
/// Specialization for vector of 2 components.
template <>
struct transform_details<2>
{
    /// @brief Creates new vector of type R with provided function and arguments.
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value) noexcept
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...));
    }
};
/// @}

} // namespace vector_type_details

} // namespace math

} // namespace framework

#endif
