#ifndef MATH_INC_VECTOR_TYPE_DETAILS_HPP
#define MATH_INC_VECTOR_TYPE_DETAILS_HPP

#include <functional>
#include <type_traits>

namespace neutrino::math::vector_type_details
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
    /// @brief Casts value to a specified type.
    template <typename U, typename R = std::enable_if_t<std::is_arithmetic_v<U>, T>>
    inline static constexpr R from(const U& value) noexcept
    {
        return static_cast<R>(value);
    }
};

template <>
struct cast_to<bool>
{
    template <typename U, typename R = std::enable_if_t<std::is_arithmetic_v<U>, bool>>
    inline static constexpr R from(const U& value) noexcept
    {
        return !equals(value, U{0});
    }
};

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

} // namespace neutrino::math::vector_type_details

#endif
