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
#include <array>

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

template<usize BitsCount>
using value_t = typename get_crc_value_type<BitsCount>::type;

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

template <usize BitsCount>
using crc_table_t std::array<value_t<BitsCount>, 256>;

template <usize BitsCount, value_t<BitsCount> Polynome>
constexpr crc_table_t<BitsCount> fill_table() noexcept
{
    crc_table_t<BitsCount> table{0};
    constexpr value_t<BitsCount> topbit = static_cast<value_t<BitsCount>>(1u << (BitsCount - 1));

    for (usize dividend = 0; dividend < table.size(); ++dividend) {
        value_t<BitsCount> value = static_cast<value_t<BitsCount>>(dividend << (BitsCount - 8));
        for (uint8 bit = 8; bit > 0; --bit) {
            value = static_cast<value_t<BitsCount>>((value & topbit) ? (value << 1) ^ Polynome : value << 1);
        }

        table[dividend] = value;
    }

    return table;
}

} // namespace framework::utils::crc_details

#endif
