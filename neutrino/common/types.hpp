#ifndef FRAMEWORK_COMMON_TYPES_HPP
#define FRAMEWORK_COMMON_TYPES_HPP

#include <cstddef>
#include <cstdint>

#include <common/instance_id.hpp>
#include <common/position.hpp>
#include <common/size.hpp>

namespace framework
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup common_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////

using int8  = std::int8_t;  ///< Signed integer type with size of exactly 8 bits
using int16 = std::int16_t; ///< Signed integer type with size of exactly 16 bits
using int32 = std::int32_t; ///< Signed integer type with size of exactly 32 bits
using int64 = std::int64_t; ///< Signed integer type with size of exactly 64 bits

using uint8  = std::uint8_t;  ///< Unsigned integer type with size of exactly 8 bits
using uint16 = std::uint16_t; ///< Unsigned integer type with size of exactly 16 bits
using uint32 = std::uint32_t; ///< Unsigned integer type with size of exactly 32 bits
using uint64 = std::uint64_t; ///< Unsigned integer type with size of exactly 64 bits

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework

#endif
