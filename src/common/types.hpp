/// @file
/// @brief Definition of basic primitive types.
/// @author Fedorov Alexey
/// @date 31.07.2017

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

#ifndef FRAMEWORK_COMMON_TYPES_HPP
#define FRAMEWORK_COMMON_TYPES_HPP

#include <cstddef>
#include <cstdint>

// undefine GNU GCC backward compatibility makros.
#undef major
#undef minor

namespace framework
{
/// @details
/// Base type definitions.
///
/// @defgroup common_types_module Common types
/// @{

using int8  = std::int8_t;  ///< Signed integer type with size of exactly 8 bits
using int16 = std::int16_t; ///< Signed integer type with size of exactly 16 bits
using int32 = std::int32_t; ///< Signed integer type with size of exactly 32 bits
using int64 = std::int64_t; ///< Signed integer type with size of exactly 64 bits

using ptrdiff = std::ptrdiff_t; ///< Signed integer type of the result of subtracting two pointers

using uint8  = std::uint8_t;  ///< Unsigned integer type with size of exactly 8 bits
using uint16 = std::uint16_t; ///< Unsigned integer type with size of exactly 16 bits
using uint32 = std::uint32_t; ///< Unsigned integer type with size of exactly 32 bits
using uint64 = std::uint64_t; ///< Unsigned integer type with size of exactly 64 bits

using usize = std::size_t; ///< Unsigled integer type, should be used for array indexing and loop counting

using float32 = float;  ///< Floating point type with size of exactly 32 bits
using float64 = double; ///< Floating point type with size of exactly 64 bits

/// @}

} // namespace framework

#endif
