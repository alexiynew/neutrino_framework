#ifndef COMMON_ZLIB_HPP
#define COMMON_ZLIB_HPP

#include <cstdint>
#include <vector>

#include <common/global_defines.hpp>

namespace neutrino::zlib
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_zlib_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Decompress byte sequence
///
/// For details on the compression algorithm see the deflate specification [RFC-1951]
///
/// @param data LZ77-compressed data
///
/// @return Raw (uncompressed) data
LIBRARY_API std::vector<std::uint8_t> inflate(const std::vector<std::uint8_t>& data);

/// @brief Compress byte sequence
///
/// For details on the compression algorithm see the deflate specification [RFC-1951]
///
/// @param data Data to compress
///
/// @return LZ77-compressed data
LIBRARY_API std::vector<std::uint8_t> deflate(const std::vector<std::uint8_t>& data);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::zlib

#endif
