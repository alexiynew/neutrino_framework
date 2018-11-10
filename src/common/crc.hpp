/// @file
/// @brief CRC implementation.
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

#ifndef FRAMEWORK_COMMON_CRC_HPP
#define FRAMEWORK_COMMON_CRC_HPP

#include <common/crc_details.hpp>
#include <common/types.hpp>

namespace framework::utils
{
/// @details
///
/// Cyclic redundancy check implementation
///
/// All parameters needed for computation passed to constructor,@n
/// so it can be configured to any algorithm you want.
///
/// As template parameter it accepts the number of bits in result value e.g. 8, 16, or 32.@n
/// There are predefined types for `crc8`, `crc16` and `crc32` algorithms.
///
/// At construction time @ref crc class generates the crc value table.@n
///
/// Code example:
/// @code
/// std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
///
/// std::cout << "0x" << std::hex
///           << static_cast<int>(crc8(0x39, 0x00, true, true, 0x00).calculate(data.begin(), data.end()))
///           << std::endl; // CRC-8/DARC
///
/// std::cout << "0x" << std::hex << crc16(0x8005).calculate(data.begin(), data.end())
///           << std::endl; // CRC-16/BUYPAS
///
/// std::cout << "0x" << std::hex
///           << crc32(0x04C11DB7, 0xFFFFFFFF, true, true, 0xFFFFFFFF).calculate(data.begin(), data.end())
///           << std::endl; // CRC-32
/// @endcode

/// @addtogroup crc_implementation
/// @{

/// @brief CRC implementation.
template <usize BitsCount>
class crc
{
public:
    /// @brief Crc value type.
    using value_type = typename crc_details::get_crc_value_type<BitsCount>::type;

    /// @brief Creates crc algorithm instance.
    ///
    /// @param poly Polynome.
    /// @param init Initial vlaue.
    /// @param reflect_in Should reflect input bytes.
    /// @param reflect_out Should reflect output value.
    /// @param xor_out Value to 'xor' the result at the end.
    explicit crc(value_type poly,
                 value_type init    = 0,
                 bool reflect_in    = false,
                 bool reflect_out   = false,
                 value_type xor_out = 0) noexcept;

    /// @brief Calculates the crc value.
    ///
    /// @param begin Iterator that points to the begin of diapason.
    /// @param end Iterator that points to the end of diapason.
    ///
    /// @return The crc value.
    template <typename Iterator>
    value_type calculate(Iterator begin, Iterator end) const;

    /// @brief Updates crc value.
    ///
    /// @param byte Byte to update crc.
    /// @param crc Old crc value.
    ///
    /// @return New crc value.
    ///
    /// @note This functions uses only the poly parameter. All other parameters does not counted in value computation.
    value_type update(uint8 byte, value_type crc) const noexcept;

private:
    const value_type m_poly    = 0;
    const value_type m_init    = 0;
    const value_type m_xor_out = 0;
    const bool m_reflect_in    = false;
    const bool m_reflect_out   = false;

    value_type crc_table[256] = {0};
};

using crc8  = crc<8>;  ///< Predefined class for crc8 algorithms.
using crc16 = crc<16>; ///< Predefined class for crc16 algorithms.
using crc32 = crc<32>; ///< Predefined class for crc32 algorithms.

/// @}

#pragma region definitions

template <usize BitsCount>
inline crc<BitsCount>::crc(value_type poly,
                           value_type init,
                           bool reflect_in,
                           bool reflect_out,
                           value_type xor_out) noexcept
    : m_poly(poly), m_init(init), m_xor_out(xor_out), m_reflect_in(reflect_in), m_reflect_out(reflect_out)
{
    constexpr value_type topbit = static_cast<value_type>(1u << (BitsCount - 1));

    for (uint32 dividend = 0; dividend < 256; ++dividend) {
        value_type value = static_cast<value_type>(dividend << (BitsCount - 8));
        for (uint8 bit = 8; bit > 0; --bit) {
            value = static_cast<value_type>((value & topbit) ? (value << 1) ^ m_poly : value << 1);
        }

        crc_table[dividend] = value;
    }
}

template <usize BitsCount>
template <typename Iterator>
inline typename crc<BitsCount>::value_type crc<BitsCount>::calculate(Iterator begin, Iterator end) const
{
    value_type value = m_init;

    for (; begin != end; ++begin) {
        value = update(m_reflect_in ? crc_details::reflect(*begin) : *begin, value);
    }

    if (m_reflect_out) {
        value = crc_details::reflect(value);
    }

    return (value ^ m_xor_out);
}

template <usize BitsCount>
inline typename crc<BitsCount>::value_type crc<BitsCount>::update(uint8 byte, value_type value) const noexcept
{
    const uint8 index = static_cast<uint8>(byte ^ (value >> (BitsCount - 8)));
    return static_cast<value_type>(crc_table[index] ^ (value << 8));
}

#pragma endregion

} // namespace framework::utils

#endif
