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

using int8  = std::int8_t;
using int16 = std::int16_t;
using int32 = std::int32_t;
using int64 = std::int64_t;

using uint8  = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;

using real32 = float;
using real64 = double;

/// @}

} // namespace framework


#endif
