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
#include <utility>

namespace framework::utils::crc_details
{
/// @brief Helper class to get correct type for crc::value_type.
template <usize BitsCount>
struct get_crc_value_type;

/// @brief Helper class to get correct type for crc::value_type.
template <>
struct get_crc_value_type<8>
{
    using type = uint8;
};

/// @brief Helper class to get correct type for crc::value_type.
template <>
struct get_crc_value_type<16>
{
    using type = uint16;
};

/// @brief Helper class to get correct type for crc::value_type.
template <>
struct get_crc_value_type<32>
{
    using type = uint32;
};

/// @brief Valuie type short cut.
template<usize BitsCount>
using value_t = typename get_crc_value_type<BitsCount>::type;

/// @brieaf crc table type
template <usize BitsCount>
using crc_table_t = std::array<value_t<BitsCount>, 256>;

template <usize BitsCount, value_t<BitsCount> Polynome>
constexpr value_t<BitsCount> generate_value(usize dividend) noexcept
{
    constexpr value_t<BitsCount> topbit = static_cast<value_t<BitsCount>>(1u << (BitsCount - 1));
    
    value_t<BitsCount> value = static_cast<value_t<BitsCount>>(dividend << (BitsCount - 8));
    for (uint8 bit = 8; bit > 0; --bit) {
        value = static_cast<value_t<BitsCount>>((value & topbit) ? (value << 1) ^ Polynome : value << 1);
    }
    
    return value;
}

template<usize BitsCount, value_t<BitsCount> Polynome, usize... I>
constexpr inline crc_table_t<BitsCount> gen_table(std::index_sequence<I...>)
{
    return crc_table_t<BitsCount>{generate_value<BitsCount, Polynome>(I)...};
}

/// @brief Geneates crc table at compile time.
template <usize BitsCount, value_t<BitsCount> Polynome>
constexpr inline crc_table_t<BitsCount> fill_table() noexcept
{
    return gen_table<BitsCount, Polynome>(std::make_index_sequence<256>());
}

/// @brief Reflects bits in value.
template <usize BitsCount>
value_t<BitsCount> reflect(value_t<BitsCount> value)
{
    value_t<BitsCount> ref = 0;

    for (usize bit = 0; bit < BitsCount; ++bit) {
        if (value & 1) {
            ref |= 1;
        }
        value >>= 1;
        ref <<= 1;
    }

    return ref;
}

} // namespace framework::utils::crc_details

#endif
