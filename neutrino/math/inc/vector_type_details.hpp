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

template <typename T>
struct cast_to
{
    /// @brief Casts value to a specified type. ////////////////////////////////////////////////////////////////////////////
    template <typename U, typename R = typename std::enable_if<std::is_arithmetic<U>::value, T>::type>
    inline static constexpr R from(const U& value) noexcept
    {
        return static_cast<R>(value);
    }
};

template <>
struct cast_to<bool>
{
    template <typename U, typename R = typename std::enable_if<std::is_arithmetic<U>::value, bool>::type>
    inline static constexpr R from(const U& value) noexcept
    {
        return !equals(value, U{0});
    }
};

template <typename T, typename... Args>
struct are_all_arithmetic
{
    static constexpr bool value = std::is_arithmetic_v<T> && are_all_arithmetic<Args...>::value;
};

template <typename T>
struct are_all_arithmetic<T>
{
    static constexpr bool value = std::is_arithmetic_v<T>;
};
template <typename T, typename... Args>
struct common_type_details
{
    using type = typename std::common_type<T, typename common_type_details<Args...>::type>::type;
};

template <typename T>
struct common_type_details<T>
{
    using type = T;
};

template <typename... Args>
using common_type = typename std::enable_if<are_all_arithmetic<Args...>::value, common_type_details<Args...>>::type;

template <std::size_t N>
struct transform_details;

template <>
struct transform_details<4>
{
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value) noexcept
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...),
                 std::forward<F>(function)(std::forward<Args>(value).z...),
                 std::forward<F>(function)(std::forward<Args>(value).w...));
    }
};

template <>
struct transform_details<3>
{
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value) noexcept
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...),
                 std::forward<F>(function)(std::forward<Args>(value).z...));
    }
};

template <>
struct transform_details<2>
{
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value) noexcept
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...));
    }
};

} // namespace framework::math::vector_type_details

#endif
