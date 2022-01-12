#ifndef FRAMEWORK_GRAPHICS_COLOR_HPP
#define FRAMEWORK_GRAPHICS_COLOR_HPP

#include <cstdint>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Color template declaration.
///
/// @see ColorTemlate<std::uint8_t>, ColorTemplate<float>
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct ColorTemplate;

////////////////////////////////////////////////////////////////////////////////
/// @brief Color with 4 unsigned bytes values.
////////////////////////////////////////////////////////////////////////////////
template <>
struct ColorTemplate<std::uint8_t>
{
    using ValueType = std::uint8_t; ///< Value type

    static constexpr ValueType default_value = ValueType{0};
    static constexpr ValueType default_alpha = ValueType{255};

    ValueType r = default_value; ///< Red channel.
    ValueType g = default_value; ///< Green channel.
    ValueType b = default_value; ///< Blue channel.
    ValueType a = default_alpha; ///< Alpha channel.

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Initializes color as {0, 0, 0, 255}.
    ////////////////////////////////////////////////////////////////////////////
    constexpr ColorTemplate() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided values.
    ///
    /// @param r_value Value for red channel.
    /// @param g_value Value for green channel.
    /// @param b_value Value for blue channel.
    /// @param a_value Value for alpha channel.
    ////////////////////////////////////////////////////////////////////////////
    constexpr ColorTemplate(ValueType r_value,
                            ValueType g_value,
                            ValueType b_value,
                            ValueType a_value = default_alpha) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided values.
    ///
    /// @param r_value Value for red channel.
    /// @param g_value Value for green channel.
    /// @param b_value Value for blue channel.
    /// @param a_value Value for alpha channel.
    ////////////////////////////////////////////////////////////////////////////
    constexpr ColorTemplate(float r_value, float g_value, float b_value, float a_value = 1.0f) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided 16 bit value.
    ///
    /// Color channels stored in 565 format e.g. 5 bits for the red channel,
    /// 6 bits for green channel and 5 bits for the blue channel.
    /// Alpha channel is defaulted.
    ///
    /// @param value Value for red, green and blue channels.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr ColorTemplate(std::uint16_t value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided 32 bit value.
    ///
    /// Color channels stored in 8888 format e.g. 8 bits for the red channel,
    /// 8 bits for green channel, 8 bits for the blue channel
    /// and 8 bits for alpha channel.
    ///
    /// @param value Value for red, green, blue and alpha channels.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr ColorTemplate(std::uint32_t value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color from color with float value type.
    ///
    /// @param other Color to initialize from.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr ColorTemplate(const ColorTemplate<float>& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the red channel.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the red channel.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Color with 4 float values.
////////////////////////////////////////////////////////////////////////////////
template <>
struct ColorTemplate<float>
{
    using ValueType = float; ///< Value type

    static constexpr ValueType default_value = ValueType{0.0f};
    static constexpr ValueType default_alpha = ValueType{1.0f};

    ValueType r = default_value; ///< Red channel.
    ValueType g = default_value; ///< Green channel.
    ValueType b = default_value; ///< Blue channel.
    ValueType a = default_alpha; ///< Alpha channel.

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Initializes color as {0.0, 0.0, 0.0, 1.0}.
    ////////////////////////////////////////////////////////////////////////////
    constexpr ColorTemplate() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided values.
    ///
    /// @param r Value for red channel.
    /// @param g Value for green channel.
    /// @param b Value for blue channel.
    /// @param a Value for alpha channel.
    ////////////////////////////////////////////////////////////////////////////
    constexpr ColorTemplate(ValueType r, ValueType g, ValueType b, ValueType a = default_alpha) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided 16 bit value.
    ///
    /// Color channels stored in 565 format e.g. 5 bits for the red channel,
    /// 6 bits for green channel and 5 bits for the blue channel.
    /// Alpha channel is defaulted.
    ///
    /// @param value Value for red, green and blue channels.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr ColorTemplate(std::uint16_t value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color with provided 32 bit value.
    ///
    /// Color channels stored in 8888 format e.g. 8 bits for the red channel,
    /// 8 bits for green channel, 8 bits for the blue channel
    /// and 8 bits for alpha channel.
    ///
    /// @param value Value for red, green, blue and alpha channels.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr ColorTemplate(std::uint32_t value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes color from color with unsignet byte value type.
    ///
    /// @param other Color to initialize from.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr ColorTemplate(const ColorTemplate<std::uint8_t>& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the red channel.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the red channel.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;
};

using Color  = ColorTemplate<std::uint8_t>;
using Colorf = ColorTemplate<float>;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name ColorTemplate<std::uint8_t> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////

inline constexpr Color::ColorTemplate() noexcept = default;

inline constexpr Color::ColorTemplate(ValueType r_value,
                                      ValueType g_value,
                                      ValueType b_value,
                                      ValueType a_value) noexcept
    : r(r_value)
    , g(g_value)
    , b(b_value)
    , a(a_value)
{}

inline constexpr Color::ColorTemplate(float r_value, float g_value, float b_value, float a_value) noexcept
    : r(static_cast<ValueType>(r_value * 255))
    , g(static_cast<ValueType>(g_value * 255))
    , b(static_cast<ValueType>(b_value * 255))
    , a(static_cast<ValueType>(a_value * 255))
{}

inline constexpr Color::ColorTemplate(std::uint16_t value) noexcept
    : r(static_cast<ValueType>((value & 0xF800) >> 11))
    , g(static_cast<ValueType>((value & 0x7E0) >> 5))
    , b(static_cast<ValueType>(value & 0x1F))
    , a(default_alpha)
{}

inline constexpr Color::ColorTemplate(std::uint32_t value) noexcept
    : r(static_cast<ValueType>((value & 0xFF000000) >> 24))
    , g(static_cast<ValueType>((value & 0xFF0000) >> 16))
    , b(static_cast<ValueType>((value & 0xFF00) >> 8))
    , a(static_cast<ValueType>(value & 0xFF))
{}

inline constexpr Color::ColorTemplate(const ColorTemplate<float>& other) noexcept
    : r(static_cast<ValueType>(other.r * 255))
    , g(static_cast<ValueType>(other.g * 255))
    , b(static_cast<ValueType>(other.b * 255))
    , a(static_cast<ValueType>(other.a * 255))
{}

inline Color::ValueType* Color::data() noexcept
{
    return &r;
}

inline const Color::ValueType* Color::data() const noexcept
{
    return &r;
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name ColorTemplate<float> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////

inline constexpr Colorf::ColorTemplate() noexcept = default;

inline constexpr Colorf::ColorTemplate(ValueType r_value,
                                       ValueType g_value,
                                       ValueType b_value,
                                       ValueType a_value) noexcept
    : r(r_value)
    , g(g_value)
    , b(b_value)
    , a(a_value)
{}

inline constexpr Colorf::ColorTemplate(std::uint16_t value) noexcept
    : r(((value & 0xF800) >> 11) / 255.0f)
    , g(((value & 0x7E0) >> 5) / 255.0f)
    , b((value & 0x1F) / 255.0f)
    , a(default_alpha)
{}

inline constexpr Colorf::ColorTemplate(std::uint32_t value) noexcept
    : r(((value & 0xFF000000) >> 24) / 255.0f)
    , g(((value & 0xFF0000) >> 16) / 255.0f)
    , b(((value & 0xFF00) >> 8) / 255.0f)
    , a((value & 0xFF) / 255.0f)
{}

inline constexpr Colorf::ColorTemplate(const ColorTemplate<std::uint8_t>& other) noexcept
    : r(static_cast<ValueType>(other.r / 255.0f))
    , g(static_cast<ValueType>(other.g / 255.0f))
    , b(static_cast<ValueType>(other.b / 255.0f))
    , a(static_cast<ValueType>(other.a / 255.0f))
{}

inline Colorf::ValueType* Colorf::data() noexcept
{
    return &r;
}

inline const Colorf::ValueType* Colorf::data() const noexcept
{
    return &r;
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
