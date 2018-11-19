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
///
/// @t_param BitsCount Bits count in result value.
/// @t_param Polynome Polynome to generate crc_table.
/// @t_param Init Initial vlaue.
/// @t_param ReflectIn Should reflect input bytes.
/// @t_param ReflectOut Should reflect output value.
/// @t_param XorOut Value to 'xor' with the result at the end.
template <usize BitsCount, 
          value_t<BitsCount> Polynome, 
          value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut, 
          value_t<BitsCount> XorOut>
class crc
{
public:
    /// @brief Crc value type.
    using value_type = crc_details::value_t<BitsCount>;

    /// @brief Calculates the crc value.
    ///
    /// @param begin Iterator that points to the begin of diapason.
    /// @param end Iterator that points to the end of diapason.
    ///
    /// @return The crc value.
    template <typename Iterator>
    static value_type calculate(Iterator begin, Iterator end);

    /// @brief Updates crc value.
    ///
    /// @param byte Byte to update crc.
    /// @param crc Old crc value.
    ///
    /// @return New crc value.
    ///
    /// @note This functions uses only the Polynome parameter. All other parameters does not counted in value computation.
    static value_type update(uint8 byte, value_type crc) noexcept;

private:
    constexpr static crc_details::crc_table_t<BitsCount> crc_table = crc_details::fill_table<BitsCount, Polynome>();
};

using crc8  = crc<8>;  ///< Predefined class for crc8 algorithms.
using crc16 = crc<16>; ///< Predefined class for crc16 algorithms.
using crc32 = crc<32>; ///< Predefined class for crc32 algorithms.

/// @}

#pragma region definitions

template <usize BitsCount, 
          value_t<BitsCount> Polynome, 
          value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut, 
          value_t<BitsCount> XorOut>
template <typename Iterator>
inline typename crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::value_type 
crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::calculate(Iterator begin, Iterator end)
{
    value_type value = Init;

    for (; begin != end; ++begin) {
        value = update(ReflectIn ? crc_details::reflect(*begin) : *begin, value);
    }

    if (ReflectOut) {
        value = crc_details::reflect(value);
    }

    return (value ^ XorOut);
}

template <usize BitsCount, 
          value_t<BitsCount> Polynome, 
          value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut, 
          value_t<BitsCount> XorOut>
inline typename crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::value_type 
crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(uint8 byte, value_type value) noexcept
{
    const uint8 index = static_cast<uint8>(byte ^ (value >> (BitsCount - 8)));
    return static_cast<value_type>(crc_table[index] ^ (value << 8));
}
#pragma endregion

} // namespace framework::utils

#endif
