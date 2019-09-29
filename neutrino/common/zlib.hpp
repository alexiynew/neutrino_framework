/// @file
/// @brief ZLIB compression algorithm implementation
/// @author Fedorov Alexey
/// @date 17.09.2019

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

#ifndef FRAMEWORK_COMMON_ZLIB_HPP
#define FRAMEWORK_COMMON_ZLIB_HPP

#include <vector>

#include <common/types.hpp>

namespace framework::utils::zlib
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
/// @param compr Compression type
///
/// @return LZ77-compressed data
std::vector<uint8> deflate(const std::vector<uint8>& data);

/// @}

} // namespace framework::utils::zlib

#endif
