/// @file
/// @brief Definition of basic primitive types.
/// @author Fedorov Alexey
/// @date 31.07.2017

#ifndef FRAMEWORK_COMMON_COMMON_TYPES_HPP
#define FRAMEWORK_COMMON_COMMON_TYPES_HPP

#include <cstdint>

namespace framework {

/// @brief Contains definition of primitive types.
///
/// @defgroup common_types_module Common types
/// @{

using int8  = std::int8_t;  ///< Signed integer type with width of exactly 8 bits
using int16 = std::int16_t; ///< Signed integer type with width of exactly 16 bits
using int32 = std::int32_t; ///< Signed integer type with width of exactly 32 bits
using int64 = std::int64_t; ///< Signed integer type with width of exactly 64 bits

using uint8  = std::uint8_t;  ///< Unsigned integer type with width of exactly 8 bits
using uint16 = std::uint16_t; ///< Unsigned integer type with width of exactly 16 bits
using uint32 = std::uint32_t; ///< Unsigned integer type with width of exactly 32 bits
using uint64 = std::uint64_t; ///< Unsigned integer type with width of exactly 64 bits

using float32 = float;  ///< Floating point type with width of exactly 32 bits
using float64 = double; ///< Floating point type with width of exactly 64 bits

/// @}

} // namespace framework


#endif
