/// @file
/// @brief Version number abstraction
/// @author Fedorov Alexey
/// @date 13.09.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#ifndef FRAMEWORK_COMMON_VERSION_HPP
#define FRAMEWORK_COMMON_VERSION_HPP

#include <string>

#include <common/types.hpp>

namespace framework
{
namespace utils
{
/// @addtogroup version_abstraction
/// @{

struct version
{
public:
    version(int32 major, int32 minor, int32 patch = 0, int32 build = 0) noexcept;
    explicit version(const std::string& version_string);

    version(const version&) = default;
    version(version&&)      = default;

    version& operator=(const version&) = default;
    version& operator=(version&&) = default;

    ~version() = default;

    std::string as_string() const;

    int32 major = 0;
    int32 minor = 0;
    int32 patch = 0;
    int32 build = 0;
};

inline constexpr bool operator==(const version& lhs, const version& rhs) noexcept
{
    return lhs.major == rhs.major && lhs.minor == rhs.minor && lhs.patch == rhs.patch && lhs.build == rhs.build;
}

inline constexpr bool operator!=(const version& lhs, const version& rhs) noexcept
{
    return !(lhs == rhs);
}

inline constexpr bool operator<(const version& lhs, const version& rhs) noexcept
{
    return (lhs.major != rhs.major
            ? lhs.major < rhs.major
            : (lhs.minor != rhs.minor ? lhs.minor < rhs.minor
                                      : (lhs.patch != rhs.patch ? lhs.patch < rhs.patch : lhs.build < rhs.build)));
}

inline constexpr bool operator>(const version& lhs, const version& rhs) noexcept
{
    return !(lhs < rhs) && lhs != rhs;
}

inline constexpr bool operator<=(const version& lhs, const version& rhs) noexcept
{
    return lhs < rhs || lhs == rhs;
}

inline constexpr bool operator>=(const version& lhs, const version& rhs) noexcept
{
    return lhs > rhs || lhs == rhs;
}

/// @}

} // namespace utils

} // namespace framework

#endif
