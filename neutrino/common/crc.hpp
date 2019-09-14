/// @file
/// @brief CRC implementation.
/// @author Fedorov Alexey
/// @date 20.09.2018

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

#ifndef FRAMEWORK_COMMON_CRC_HPP
#define FRAMEWORK_COMMON_CRC_HPP

#include <common/types.hpp>

#include <common/inc/crc_details.hpp>

namespace framework::utils
{
/// @addtogroup common_crc_implementation
/// @{

/// @details
///
/// Cyclic redundancy check implementation
///
/// All parameters needed for computation passed as template parametrs,@n
/// so it can be configured to any algorithm.
///
/// There are predefined types for different `crc8`, `crc16` and `crc32` algorithms.
///
/// Code example:
/// @code
/// std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
///
/// // CRC-8/DARC
/// std::cout << "0x" << std::hex << static_cast<int>(crc8_darc::calculate(data.begin(), data.end())) << std::endl;
///
/// // CRC-16/BUYPAS
/// std::cout << "0x" << std::hex << crc16_buypas::calculate(data.begin(), data.end()) << std::endl;
///
/// // CRC-32
/// std::cout << "0x" << std::hex << crc32::calculate(data.begin(), data.end()) << std::endl;
/// @endcode

/// @brief CRC implementation.
///
/// @t_param BitsCount Bits count in result value.
/// @t_param Polynome Polynome to generate crc_table.
/// @t_param Init Initial vlaue.
/// @t_param ReflectIn Should reflect input bytes.
/// @t_param ReflectOut Should reflect output value.
/// @t_param XorOut Value to 'xor' with the result at the end.
template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
class crc
{
public:
    /// @brief Crc value type.
    using value_type                         = crc_details::value_t<BitsCount>;
    constexpr static value_type init_value   = Init;
    constexpr static bool reflect_in         = ReflectIn;
    constexpr static bool reflect_out        = ReflectOut;
    constexpr static value_type xorout_value = XorOut;

    /// @brief Calculates the crc value.
    ///
    /// @param begin Iterator that points to the begin of diapason.
    /// @param end Iterator that points to the end of diapason.
    ///
    /// @return The crc value.
    template <typename Iterator>
    static value_type calculate(Iterator begin, const Iterator end);

    /// @brief Resets crc value to the Init value.
    void reset() noexcept;

    /// @brief Updates crc value.
    ///
    /// @param byte Byte to update crc.
    void update(uint8 byte) noexcept;

    /// @brief Updates crc value.
    ///
    /// @param value Value to update crc.
    template <typename T>
    void update(T value) noexcept;

    /// @brief Updates crc value with range of values.
    ///
    /// @param begin Iterator that points to the begin of diapason.
    /// @param end Iterator that points to the end of diapason.
    template <typename Iterator>
    void update(Iterator begin, const Iterator end);

    /// @brief Returns crc value.
    ///
    /// @return The current crc value.
    value_type current_value() const noexcept;

private:
    constexpr static usize crc_table_size = 256;
    constexpr static crc_details::crc_table_t<BitsCount, crc_table_size>
    crc_table = crc_details::generate_table<BitsCount, Polynome, crc_table_size>();

    value_type m_current_value = init_value;
};

// clang-format off
using crc8          = crc<8, 0x07, 0x00, false, false, 0x00>; ///< Predefined CRC-8 algorithm.
using crc8_cdma2000 = crc<8, 0x9B, 0xFF, false, false, 0x00>; ///< Predefined CRC-8/CDMA2000 algorithm.
using crc8_darc     = crc<8, 0x39, 0x00, true,  true,  0x00>; ///< Predefined CRC-8/DARC algorithm.
using crc8_dvb_s2   = crc<8, 0xD5, 0x00, false, false, 0x00>; ///< Predefined CRC-8/DVB-S2 algorithm.
using crc8_ebu      = crc<8, 0x1D, 0xFF, true,  true,  0x00>; ///< Predefined CRC-8/EBU algorithm.
using crc8_i_code   = crc<8, 0x1D, 0xFD, false, false, 0x00>; ///< Predefined CRC-8/I-CODE algorithm.
using crc8_itu      = crc<8, 0x07, 0x00, false, false, 0x55>; ///< Predefined CRC-8/ITU algorithm.
using crc8_maxim    = crc<8, 0x31, 0x00, true,  true,  0x00>; ///< Predefined CRC-8/MAXIM algorithm.
using crc8_rohc     = crc<8, 0x07, 0xFF, true,  true,  0x00>; ///< Predefined CRC-8/ROHC algorithm.
using crc8_wcdma    = crc<8, 0x9B, 0x00, true,  true,  0x00>; ///< Predefined CRC-8/WCDMA algorithm.

using crc16_ccitt_false = crc<16, 0x1021, 0xFFFF, false, false, 0x0000>; ///< Predefined CRC-16/CCITT-FALSE algorithm.
using crc16_arc         = crc<16, 0x8005, 0x0000, true,  true,  0x0000>; ///< Predefined CRC-16/ARC algorithm.
using crc16_aug_ccitt   = crc<16, 0x1021, 0x1D0F, false, false, 0x0000>; ///< Predefined CRC-16/AUG-CCITT algorithm.
using crc16_buypas      = crc<16, 0x8005, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/BUYPAS algorithm.
using crc16_cdma2000    = crc<16, 0xC867, 0xFFFF, false, false, 0x0000>; ///< Predefined CRC-16/CDMA2000 algorithm.
using crc16_dds_110     = crc<16, 0x8005, 0x800D, false, false, 0x0000>; ///< Predefined CRC-16/DDS-110 algorithm.
using crc16_dect_r      = crc<16, 0x0589, 0x0000, false, false, 0x0001>; ///< Predefined CRC-16/DECT-R algorithm.
using crc16_dect_x      = crc<16, 0x0589, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/DECT-X algorithm.
using crc16_genibus     = crc<16, 0x1021, 0xFFFF, false, false, 0xFFFF>; ///< Predefined CRC-16/GENIBUS algorithm.
using crc16_maxim       = crc<16, 0x8005, 0x0000, true,  true,  0xFFFF>; ///< Predefined CRC-16/MAXIM algorithm.
using crc16_mcrf4xx     = crc<16, 0x1021, 0xFFFF, true,  true,  0x0000>; ///< Predefined CRC-16/MCRF4XX algorithm.
using crc16_riello      = crc<16, 0x1021, 0xB2AA, true,  true,  0x0000>; ///< Predefined CRC-16/RIELLO algorithm.
using crc16_t0_dif      = crc<16, 0x8BB7, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/T0-DIF algorithm.
using crc16_teledisk    = crc<16, 0xA097, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/TELEDISK algorithm.
using crc16_tms37157    = crc<16, 0x1021, 0x89EC, true,  true,  0x0000>; ///< Predefined CRC-16/TMS37157 algorithm.
using crc16_usb         = crc<16, 0x8005, 0xFFFF, true,  true,  0xFFFF>; ///< Predefined CRC-16/USB algorithm.
using crc16_a           = crc<16, 0x1021, 0xC6C6, true,  true,  0x0000>; ///< Predefined CRC-A algorithm.
using crc16_kermit      = crc<16, 0x1021, 0x0000, true,  true,  0x0000>; ///< Predefined CRC-16/KERMIT algorithm.
using crc16_modbus      = crc<16, 0x8005, 0xFFFF, true,  true,  0x0000>; ///< Predefined CRC-16/MODBUS algorithm.
using crc16_x_25        = crc<16, 0x1021, 0xFFFF, true,  true,  0xFFFF>; ///< Predefined CRC-16/X-25 algorithm.
using crc16_xmodem      = crc<16, 0x1021, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/XMODEM algorithm.

using crc32        = crc<32, 0x04C11DB7, 0xFFFFFFFF, true,  true,  0xFFFFFFFF>; ///< Predefined CRC-32 algorithm.
using crc32_bzip2  = crc<32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0xFFFFFFFF>; ///< Predefined CRC-32/BZIP2 algorithm.
using crc32c       = crc<32, 0x1EDC6F41, 0xFFFFFFFF, true,  true,  0xFFFFFFFF>; ///< Predefined CRC-32C algorithm.
using crc32d       = crc<32, 0xA833982B, 0xFFFFFFFF, true,  true,  0xFFFFFFFF>; ///< Predefined CRC-32D algorithm.
using crc32_mpeg_2 = crc<32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0x00000000>; ///< Predefined CRC-32/MPEG-2 algorithm.
using crc32_posix  = crc<32, 0x04C11DB7, 0x00000000, false, false, 0xFFFFFFFF>; ///< Predefined CRC-32/POSIX algorithm.
using crc32q       = crc<32, 0x814141AB, 0x00000000, false, false, 0x00000000>; ///< Predefined CRC-32Q algorithm.
using crc32_jamcrc = crc<32, 0x04C11DB7, 0xFFFFFFFF, true,  true,  0x00000000>; ///< Predefined CRC-32/JAMCRC algorithm.
using crc32_xfer   = crc<32, 0x000000AF, 0x00000000, false, false, 0x00000000>; ///< Predefined CRC-32/XFER algorithm.
// clang-format on

#pragma region definitions

template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
template <typename Iterator>
inline typename crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::value_type crc<
BitsCount,
Polynome,
Init,
ReflectIn,
ReflectOut,
XorOut>::calculate(Iterator begin, const Iterator end)
{
    crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut> calc;

    calc.reset();
    calc.update(std::forward<Iterator>(begin), std::forward<const Iterator>(end));
    return calc.current_value();
}

template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
inline void crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::reset() noexcept
{
    m_current_value = init_value;
}

template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
inline void crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(uint8 byte) noexcept
{
    byte = reflect_in ? crc_details::reflect<8>(byte) : byte;

    const uint8 index = static_cast<uint8>(byte ^ (m_current_value >> (BitsCount - 8)));
    m_current_value   = static_cast<value_type>(crc_table[index] ^ (m_current_value << 8));
}

template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
template <typename T>
inline void crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(T value) noexcept
{
    constexpr usize input_value_size = sizeof(T);

    for (usize i = 0; i < input_value_size; ++i) {
        const uint8 byte = static_cast<uint8>((value >> (i * 8)) & 0xFF);
        update(byte);
    }
}

template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
template <typename Iterator>
inline void crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(Iterator begin, const Iterator end)
{
    for (; begin != end; ++begin) {
        update(*begin);
    }
}

template <usize BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
inline typename crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::value_type crc<BitsCount,
                                                                                              Polynome,
                                                                                              Init,
                                                                                              ReflectIn,
                                                                                              ReflectOut,
                                                                                              XorOut>::current_value()
const noexcept
{
    value_type value = m_current_value;

    if (reflect_out) {
        value = crc_details::reflect<BitsCount>(value);
    }

    return (value ^ xorout_value);
}

#pragma endregion

/// @}

} // namespace framework::utils

#endif
