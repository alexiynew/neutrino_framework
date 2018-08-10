/// @file
/// @brief Different helper functions
/// @author Fedorov Alexey
/// @date 03.03.2018

#ifndef FRAMEWORK_COMMON_UTILS_HPP
#define FRAMEWORK_COMMON_UTILS_HPP

#include <random>
#include <vector>

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

    auto get_distribution = [](auto min_value, auto max_value) {
        if constexpr (std::is_integral<T>::value) {
            return std::uniform_int_distribution<T>(min_value, max_value);
        }

        return std::uniform_real_distribution<T>(min_value, max_value);
    };

    std::vector<T> result;
    result.reserve(count);

    std::random_device rd;
    std::mt19937 mt(rd());
    auto dist = get_distribution(min, max);
    for (size_t i = 0; i < count; ++i) {
        result.push_back(dist(mt));
    }

    return result;
}
/// @}

} // namespace utils

/// @}

} // namespace framework

#endif
