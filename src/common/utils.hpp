/// @file
/// @brief Different helper functions
/// @author Fedorov Alexey
/// @date 03.03.2018

#ifndef FRAMEWORK_COMMON_UTILS_HPP
#define FRAMEWORK_COMMON_UTILS_HPP

#include <random>
#include <vector>

#include <common/utils_details.hpp>

namespace framework
{
/// @details
///
/// Different helper functions.
///
/// @defgroup common_utils_module Common utils
/// @{

namespace utils
{
/// @addtogroup common_utils_module
/// @{

/// @brief Determines if it is the debug build.
///
/// @return `true` in debug mode, `false` otherwise.
inline constexpr bool is_debug() noexcept
{
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
}

/// @brief Genertes bunch of random numbers.
///
/// @param min Minimum of the range.
/// @param max Maximum of the range.
/// @param count How much numbers to generate.
///
/// @return Vector of the `count` size of random numbers in range [min, max].
template <typename T>
std::vector<T> random_numbers(T min, T max, size_t count)
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    if (count == 0) {
        return std::vector<T>();
    }

    if (min > max) {
        std::swap(min, max);
    }

    auto get_distribution = [](T min_value, T max_value) {
        if constexpr (std::is_integral<T>::value == true) {
            return std::uniform_int_distribution<T>(min_value, max_value);
        } else {
            return std::uniform_real_distribution<T>(min_value, max_value);
        }
    };

    auto get_generator = []() {
        std::random_device rd;
        return std::mt19937(rd());
    };

    std::vector<T> result;
    result.reserve(count);

    static auto generator = get_generator();
    auto distribution     = get_distribution(min, max);
    for (size_t i = 0; i < count; ++i) {
        result.push_back(distribution(generator));
    }

    return result;
}

template <typename... Args>
std::string format(const std::string& str, Args&&... args)
{
    std::unique_ptr<format_details::value_base> values[sizeof...(args)] = {
    (format_details::make_value_holder_ptr(args))...,
    };
    return format_details::make_string_impl(str, values, sizeof...(args));
}

/// @}

} // namespace utils

/// @}

} // namespace framework

#endif
