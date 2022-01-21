#ifndef FRAMEWORK_COMMON_UTILS_HPP
#define FRAMEWORK_COMMON_UTILS_HPP

#include <algorithm>
#include <array>
#include <istream>
#include <string>
#include <tuple>
#include <vector>

#include <common/types.hpp>

#include <common/inc/utils_details.hpp>

#include <random>

///////////////////////////////////////////////////////////////////////////////
/// @brief Different helper functions and classes.
///
/// @details
/// The @ref common_utils_module module consist of functions and classes not
/// related to any particular module. Or used all over the framework.
///
/// @defgroup common_utils_module Utility
/// @{
/// @defgroup common_version_implementation Version
/// @defgroup common_crc_implementation Crc
/// @defgroup common_zlib_implementation ZLIB compression algorithm
/// @}
///////////////////////////////////////////////////////////////////////////////

namespace framework::utils
{
///////////////////////////////////////////////////////////////////////////////
/// @addtogroup common_utils_module
/// @{
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// @brief Determines if it is the debug build.
///
/// @return `true` in debug mode, `false` otherwise.
///////////////////////////////////////////////////////////////////////////////
inline constexpr bool is_debug() noexcept
{
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Generates bunch of random numbers.
///
/// @param min Minimum of the generated numbers.
/// @param max Maximum of the generated numbers.
/// @param count How much numbers to generate.
///
/// @return Vector of the `count` size of random numbers in range [min, max].
///////////////////////////////////////////////////////////////////////////////
template <typename T>
std::vector<T> random_numbers(T min, T max, size_t count)
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    if (count == 0) {
        return std::vector<T>();
    }

    if (min > max) {
        std::swap(min, max);
    }

    auto get_generator = []() {
        std::random_device rd;
        return std::mt19937(rd());
    };

    std::vector<T> result;
    result.reserve(count);

    static auto generator = get_generator();
    auto distribution     = details::get_distribution(min, max);
    for (size_t i = 0; i < count; ++i) {
        result.push_back(distribution(generator));
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns elements count in container.
///
/// @param container To get size
///
/// @return Elements count in container.
///////////////////////////////////////////////////////////////////////////////
template <typename C>
constexpr inline std::size_t size(const C& container) noexcept
{
    return container.size();
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns elements count in array.
///
/// @return Elements count in array.
///////////////////////////////////////////////////////////////////////////////
template <typename T, std::size_t N>
constexpr inline std::size_t size(const T (&)[N]) noexcept
{
    return N;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Interprets range [begin, end) as value of type T in big endian byte order.
///
/// @param begin Range to read value from.
/// @param end Range to read value from.
///
/// @return Value of type T.
///////////////////////////////////////////////////////////////////////////////
template <typename T, typename Iterator>
inline T big_endian_value(const Iterator begin, const Iterator end)
{
    constexpr bool supported_buffer_type = sizeof(typename std::iterator_traits<Iterator>::value_type) == 1;
    static_assert(supported_buffer_type, "Usupported buffer type");

    constexpr bool supported_return_type = sizeof(T) <= 8;
    static_assert(supported_return_type, "Usupported return type");

    constexpr bool
    is_forward_iterator = std::is_convertible_v<typename std::iterator_traits<Iterator>::iterator_category,
                                                std::forward_iterator_tag>;
    static_assert(is_forward_iterator, "Iterator is not forward iterator");

    constexpr bool can_read_from_buffer = std::disjunction_v<std::is_fundamental<T>, std::is_enum<T>>;
    static_assert(can_read_from_buffer, "Can't read value of type T from buffer");

    constexpr int size = sizeof(T);

    const auto dist = std::distance(begin, end);
    if (dist < size) {
        throw std::range_error("Not enough bytes to read value of size " + std::to_string(size));
    }

    typename std::iterator_traits<Iterator>::value_type buffer[size] = {};

    for (int i = 0; i < size; ++i) {
        buffer[i] = *(begin + ((size - i) - 1));
    }

    return *reinterpret_cast<T*>(buffer);
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Interprets range [begin, end) as value of type T in little endian byte order.
///
/// @param begin Range to read value from.
/// @param end Range to read value from.
///
/// @return Value of type T.
///////////////////////////////////////////////////////////////////////////////
template <typename T, typename Iterator>
inline T little_endian_value(const Iterator begin, const Iterator end)
{
    constexpr bool supported_buffer_type = sizeof(typename std::iterator_traits<Iterator>::value_type) == 1;
    static_assert(supported_buffer_type, "Usupported buffer type");

    constexpr bool supported_return_type = sizeof(T) <= 8;
    static_assert(supported_return_type, "Usupported return type");

    constexpr bool
    is_forward_iterator = std::is_convertible_v<typename std::iterator_traits<Iterator>::iterator_category,
                                                std::forward_iterator_tag>;
    static_assert(is_forward_iterator, "Iterator is not forward iterator");

    constexpr bool can_read_from_buffer = std::disjunction_v<std::is_fundamental<T>, std::is_enum<T>>;
    static_assert(can_read_from_buffer, "Can't read value of type T from buffer");

    constexpr int size = sizeof(T);

    const auto dist = std::distance(begin, end);
    if (dist < size) {
        throw std::range_error("Not enough bytes to read value of size " + std::to_string(size));
    }

    typename std::iterator_traits<Iterator>::value_type buffer[size] = {};

    for (int i = 0; i < size; ++i) {
        buffer[i] = *(begin + i);
    }

    return *reinterpret_cast<T*>(buffer);
}

/*
template <typename... Args>
std::string format(const std::string& str, Args&&... args)
{
    std::unique_ptr<format_details::value_base> values[sizeof...(args)] = {
    (format_details::make_value_holder_ptr(args))...,
    };
    return format_details::make_string_impl(str, values, sizeof...(args));
}
*/

///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////

} // namespace framework::utils

#endif
