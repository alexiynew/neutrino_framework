/// @file
/// @brief CRC implementation detais.
/// @author Fedorov Alexey
/// @date 20.09.2018

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

#ifndef FRAMEWORK_COMMON_CRC_DETAILS_HPP
#define FRAMEWORK_COMMON_CRC_DETAILS_HPP

#include <common/types.hpp>

namespace framework::utils::crc_details
{
/// @brief Helper class to get correct type for crc::value_type.
template <usize BitsCount>
struct get_crc_value_type;

/// @brief Helper class to get correct type for crc::value_type.
template <>
struct get_crc_value_type<8>
{
    using type = uint8; ///< crc::value_type
};

/// @brief Helper class to get correct type for crc::value_type.
template <>
struct get_crc_value_type<16>
{
    using type = uint16; ///< crc::value_type
};

/// @brief Helper class to get correct type for crc::value_type.
template <>
struct get_crc_value_type<32>
{
    using type = uint32; ///< crc::value_type
};

template <typename T>
T reflect(T data)
{
    constexpr uint8 bitsCount = sizeof(T) * 8;

    T ref = 0;

    for (uint8 bit = 0; bit < bitsCount; ++bit) {
        if (data & 0x01) {
            ref = static_cast<T>(ref | (1 << ((bitsCount - 1) - bit)));
        }
        data = static_cast<T>(data >> 1);
    }

    return static_cast<T>(ref);
}

} // namespace framework::utils::crc_details

#endif
