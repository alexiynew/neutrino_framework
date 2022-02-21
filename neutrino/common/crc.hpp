#ifndef FRAMEWORK_COMMON_CRC_HPP
#define FRAMEWORK_COMMON_CRC_HPP

#include <common/types.hpp>

#include <common/inc/crc_details.hpp>

namespace framework::utils
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_crc_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief CRC implementation.
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
///
/// @t_param BitsCount Bits count in result value.
/// @t_param Polynome Polynome to generate crc_table.
/// @t_param Init Initial vlaue.
/// @t_param ReflectIn Should reflect input bytes.
/// @t_param ReflectOut Should reflect output value.
/// @t_param XorOut Value to 'xor' with the result at the end.
template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
class Crc
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
    constexpr static std::size_t crc_table_size = 256;
    constexpr static crc_details::crc_table_t<BitsCount, crc_table_size>
    crc_table = crc_details::generate_table<BitsCount, Polynome, crc_table_size>();

    value_type m_current_value = init_value;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Crc algorithms definition
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using Crc8         = Crc<8, 0x07, 0x00, false, false, 0x00>; ///< Predefined CRC-8 algorithm.
using Crc8Cdma2000 = Crc<8, 0x9B, 0xFF, false, false, 0x00>; ///< Predefined CRC-8/CDMA2000 algorithm.
using Crc8Darc     = Crc<8, 0x39, 0x00, true, true, 0x00>;   ///< Predefined CRC-8/DARC algorithm.
using Crc8DvbS2    = Crc<8, 0xD5, 0x00, false, false, 0x00>; ///< Predefined CRC-8/DVB-S2 algorithm.
using Crc8Ebu      = Crc<8, 0x1D, 0xFF, true, true, 0x00>;   ///< Predefined CRC-8/EBU algorithm.
using Crc8ICode    = Crc<8, 0x1D, 0xFD, false, false, 0x00>; ///< Predefined CRC-8/I-CODE algorithm.
using Crc8Itu      = Crc<8, 0x07, 0x00, false, false, 0x55>; ///< Predefined CRC-8/ITU algorithm.
using Crc8Maxim    = Crc<8, 0x31, 0x00, true, true, 0x00>;   ///< Predefined CRC-8/MAXIM algorithm.
using Crc8Rohc     = Crc<8, 0x07, 0xFF, true, true, 0x00>;   ///< Predefined CRC-8/ROHC algorithm.
using Crc8Wcdma    = Crc<8, 0x9B, 0x00, true, true, 0x00>;   ///< Predefined CRC-8/WCDMA algorithm.

using Crc16CcittFalse = Crc<16, 0x1021, 0xFFFF, false, false, 0x0000>; ///< Predefined CRC-16/CCITT-FALSE algorithm.
using Crc16Arc        = Crc<16, 0x8005, 0x0000, true, true, 0x0000>;   ///< Predefined CRC-16/ARC algorithm.
using Crc16AugCcitt   = Crc<16, 0x1021, 0x1D0F, false, false, 0x0000>; ///< Predefined CRC-16/AUG-CCITT algorithm.
using Crc16Buypas     = Crc<16, 0x8005, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/BUYPAS algorithm.
using Crc16Cdma2000   = Crc<16, 0xC867, 0xFFFF, false, false, 0x0000>; ///< Predefined CRC-16/CDMA2000 algorithm.
using Crc16Dds110     = Crc<16, 0x8005, 0x800D, false, false, 0x0000>; ///< Predefined CRC-16/DDS-110 algorithm.
using Crc16DectR      = Crc<16, 0x0589, 0x0000, false, false, 0x0001>; ///< Predefined CRC-16/DECT-R algorithm.
using Crc16DectX      = Crc<16, 0x0589, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/DECT-X algorithm.
using Crc16Genibus    = Crc<16, 0x1021, 0xFFFF, false, false, 0xFFFF>; ///< Predefined CRC-16/GENIBUS algorithm.
using Crc16Maxim      = Crc<16, 0x8005, 0x0000, true, true, 0xFFFF>;   ///< Predefined CRC-16/MAXIM algorithm.
using Crc16Mcrf4xx    = Crc<16, 0x1021, 0xFFFF, true, true, 0x0000>;   ///< Predefined CRC-16/MCRF4XX algorithm.
using Crc16Riello     = Crc<16, 0x1021, 0xB2AA, true, true, 0x0000>;   ///< Predefined CRC-16/RIELLO algorithm.
using Crc16T0Dif      = Crc<16, 0x8BB7, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/T0-DIF algorithm.
using Crc16Teledisk   = Crc<16, 0xA097, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/TELEDISK algorithm.
using Crc16Tms37157   = Crc<16, 0x1021, 0x89EC, true, true, 0x0000>;   ///< Predefined CRC-16/TMS37157 algorithm.
using Crc16Usb        = Crc<16, 0x8005, 0xFFFF, true, true, 0xFFFF>;   ///< Predefined CRC-16/USB algorithm.
using Crc16A          = Crc<16, 0x1021, 0xC6C6, true, true, 0x0000>;   ///< Predefined CRC-A algorithm.
using Crc16Kermit     = Crc<16, 0x1021, 0x0000, true, true, 0x0000>;   ///< Predefined CRC-16/KERMIT algorithm.
using Crc16Modbus     = Crc<16, 0x8005, 0xFFFF, true, true, 0x0000>;   ///< Predefined CRC-16/MODBUS algorithm.
using Crc16X25        = Crc<16, 0x1021, 0xFFFF, true, true, 0xFFFF>;   ///< Predefined CRC-16/X-25 algorithm.
using Crc16Xmodem     = Crc<16, 0x1021, 0x0000, false, false, 0x0000>; ///< Predefined CRC-16/XMODEM algorithm.

using Crc32       = Crc<32, 0x04C11DB7, 0xFFFFFFFF, true, true, 0xFFFFFFFF>;   ///< Predefined CRC-32 algorithm.
using Crc32Bzip2  = Crc<32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0xFFFFFFFF>; ///< Predefined CRC-32/BZIP2 algorithm.
using Crc32c      = Crc<32, 0x1EDC6F41, 0xFFFFFFFF, true, true, 0xFFFFFFFF>;   ///< Predefined CRC-32C algorithm.
using Crc32d      = Crc<32, 0xA833982B, 0xFFFFFFFF, true, true, 0xFFFFFFFF>;   ///< Predefined CRC-32D algorithm.
using Crc32Mpeg2  = Crc<32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0x00000000>; ///< Predefined CRC-32/MPEG-2 algorithm.
using Crc32Posix  = Crc<32, 0x04C11DB7, 0x00000000, false, false, 0xFFFFFFFF>; ///< Predefined CRC-32/POSIX algorithm.
using Crc32q      = Crc<32, 0x814141AB, 0x00000000, false, false, 0x00000000>; ///< Predefined CRC-32Q algorithm.
using Crc32Jamcrc = Crc<32, 0x04C11DB7, 0xFFFFFFFF, true, true, 0x00000000>;   ///< Predefined CRC-32/JAMCRC algorithm.
using Crc32Xfer   = Crc<32, 0x000000AF, 0x00000000, false, false, 0x00000000>; ///< Predefined CRC-32/XFER algorithm.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region definitions

template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
template <typename Iterator>
inline typename Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::value_type Crc<
BitsCount,
Polynome,
Init,
ReflectIn,
ReflectOut,
XorOut>::calculate(Iterator begin, const Iterator end)
{
    Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut> calc;

    calc.reset();
    calc.update(std::forward<Iterator>(begin), std::forward<const Iterator>(end));
    return calc.current_value();
}

template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
inline void Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::reset() noexcept
{
    m_current_value = init_value;
}

template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
inline void Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(uint8 byte) noexcept
{
    byte = reflect_in ? crc_details::reflect<8>(byte) : byte;

    const uint8 index = static_cast<uint8>(byte ^ (m_current_value >> (BitsCount - 8)));
    m_current_value   = static_cast<value_type>(crc_table[index] ^ (m_current_value << 8));
}

template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
template <typename T>
inline void Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(T value) noexcept
{
    constexpr std::size_t input_value_size = sizeof(T);

    for (std::size_t i = 0; i < input_value_size; ++i) {
        const uint8 byte = static_cast<uint8>((value >> (i * 8)) & 0xFF);
        update(byte);
    }
}

template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
template <typename Iterator>
inline void Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::update(Iterator begin, const Iterator end)
{
    for (; begin != end; ++begin) {
        update(*begin);
    }
}

template <std::size_t BitsCount,
          crc_details::value_t<BitsCount> Polynome,
          crc_details::value_t<BitsCount> Init,
          bool ReflectIn,
          bool ReflectOut,
          crc_details::value_t<BitsCount> XorOut>
inline typename Crc<BitsCount, Polynome, Init, ReflectIn, ReflectOut, XorOut>::value_type Crc<BitsCount,
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

} // namespace framework::utils

#endif
