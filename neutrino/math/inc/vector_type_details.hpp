/// @file
/// @brief Implementation of geometric vector.
/// @author Fedorov Alexey
/// @date 12.03.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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
    #error You should include math/math.hpp instead of vector_type_details.hpp
#endif

#ifndef FRAMEWORK_MATH_INC_VECTOR_TYPE_DETAILS_HPP
    #define FRAMEWORK_MATH_INC_VECTOR_TYPE_DETAILS_HPP

    #include <functional>
    #include <type_traits>

    #include <common/types.hpp>

namespace framework::math::vector_type_details
{
/// @brief Workaround to compare float numbers without warnings.
/// @{
template <typename T>
inline constexpr bool equals(const T& a, const T& b, std::true_type /*unused*/)
{
    return std::equal_to<T>()(a, b);
}

template <typename T>
inline constexpr bool equals(const T& a, const T& b, std::false_type /*unused*/)
{
    return a == b;
}

template <typename T>
inline constexpr bool equals(const T& a, const T& b)
{
    return equals(a, b, std::is_floating_point<T>{});
}
/// @}

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
        return !equals(value, U{0});
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

} // namespace framework::math::vector_type_details

#endif
