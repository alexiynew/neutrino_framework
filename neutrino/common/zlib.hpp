#ifndef FRAMEWORK_COMMON_ZLIB_HPP
#define FRAMEWORK_COMMON_ZLIB_HPP

#include <vector>

#include <common/types.hpp>

namespace framework::zlib
{
/// @addtogroup common_zlib_implementation
/// @{

/// @brief Decompress byte sequence
///
/// For details on the compression algorithm see the deflate specification [RFC-1951]
///
/// @param data LZ77-compressed data
///
/// @return Raw (uncompressed) data
std::vector<uint8> inflate(const std::vector<uint8>& data);

/// @brief Compress byte sequence
///
/// For details on the compression algorithm see the deflate specification [RFC-1951]
///
/// @param data Data to compress
///
/// @return LZ77-compressed data
std::vector<uint8> deflate(const std::vector<uint8>& data);

/// @}

} // namespace framework::zlib

#endif
