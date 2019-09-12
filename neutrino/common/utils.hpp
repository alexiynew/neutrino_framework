/// @file
/// @brief Different helper functions
/// @author Fedorov Alexey
/// @date 03.03.2018

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

#ifndef FRAMEWORK_COMMON_UTILS_HPP
#define FRAMEWORK_COMMON_UTILS_HPP

#include <random>
#include <vector>

#include <common/inc/utils_details.hpp>

/// @brief Different helper functions
///
/// @details
/// Different helper functions
///
/// TODO: More detailed description
/// TODO: Code examples
///
/// @defgroup common_utils_module Utility functions
/// @{
/// @defgroup common_version_implementation Version
/// @defgroup common_crc_implementation Crc
/// @}

namespace framework::utils
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

template <class C>
constexpr inline auto size(const C& container) -> decltype(container.size())
{
    return container.size();
}

template <class T, std::size_t N>
constexpr inline std::size_t size(const T (&)[N]) noexcept
{
    return N;
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

/// @}

} // namespace framework

#endif
