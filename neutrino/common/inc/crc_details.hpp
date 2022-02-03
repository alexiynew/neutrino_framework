#ifndef FRAMEWORK_COMMON_INC_CRC_DETAILS_HPP
#define FRAMEWORK_COMMON_INC_CRC_DETAILS_HPP

#include <array>
#include <utility>

#include <common/types.hpp>

namespace framework::utils::crc_details
{
/// @brief Helper class to get correct type for Crc::value_type.
template <std::size_t BitsCount>
struct get_crc_value_type;

/// @brief Helper class to get correct type for Crc::value_type.
template <>
struct get_crc_value_type<8>
{
    using type = uint8;
};

/// @brief Helper class to get correct type for Crc::value_type.
template <>
struct get_crc_value_type<16>
{
    using type = uint16;
};

/// @brief Helper class to get correct type for Crc::value_type.
template <>
struct get_crc_value_type<32>
{
    using type = uint32;
};

/// @brief Value type short cut.
template <std::size_t BitsCount>
using value_t = typename get_crc_value_type<BitsCount>::type;

/// @brieaf crc table type
template <std::size_t BitsCount, std::size_t Size>
using crc_table_t = std::array<value_t<BitsCount>, Size>;

template <std::size_t BitsCount, value_t<BitsCount> Polynome>
constexpr value_t<BitsCount> generate_value(std::size_t dividend) noexcept
{
    constexpr value_t<BitsCount> topbit = (1u << (BitsCount - 1));

    value_t<BitsCount> value = static_cast<value_t<BitsCount>>(dividend << (BitsCount - 8));

    for (uint8 bit = 0; bit < 8; ++bit) {
        value = static_cast<value_t<BitsCount>>((value & topbit) ? ((value << 1) ^ Polynome) : (value << 1));
    }

    return static_cast<value_t<BitsCount>>(value);
}

template <std::size_t BitsCount, value_t<BitsCount> Polynome, std::size_t Size, std::size_t... I>
constexpr inline crc_table_t<BitsCount, Size> generate_table_impl(std::index_sequence<I...>) noexcept
{
    return {generate_value<BitsCount, Polynome>(I)...};
}

/// @brief Geneates crc table at compile time.
template <std::size_t BitsCount, value_t<BitsCount> Polynome, std::size_t Size>
constexpr inline crc_table_t<BitsCount, Size> generate_table() noexcept
{
    return generate_table_impl<BitsCount, Polynome, Size>(std::make_index_sequence<Size>());
}

/// @brief Reflects bits in value.
template <std::size_t BitsCount>
value_t<BitsCount> reflect(value_t<BitsCount> value)
{
    value_t<BitsCount> ref = 0;

    for (std::size_t bit = 0; bit < BitsCount; ++bit) {
        if (value & 1) {
            ref = static_cast<value_t<BitsCount>>(ref | 1 << (BitsCount - 1 - bit));
        }
        value = static_cast<value_t<BitsCount>>(value >> 1);
    }

    return ref;
}

} // namespace framework::utils::crc_details

#endif
