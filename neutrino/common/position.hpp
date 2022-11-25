#ifndef COMMON_POSITION_HPP
#define COMMON_POSITION_HPP

#include <common/global_defines.hpp>

namespace neutrino
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Position of an object in 2d space.
struct Position
{
    Position() = default;

    /// @brief Creates the Position object.
    ///
    /// @param x_value X coordinate.
    /// @param y_value Y coordinate.
    LIBRARY_API constexpr Position(int x_value, int y_value) noexcept
        : x(x_value)
        , y(y_value)
    {}

    int x = 0; ///< X coordiante.
    int y = 0; ///< Y coordinate.
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Position operators
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Equality operator for Position values.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
inline constexpr bool operator==(const Position& lhs, const Position& rhs) noexcept
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

/// @brief Inequality operator for Position values.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
inline constexpr bool operator!=(const Position& lhs, const Position& rhs) noexcept
{
    return !(lhs == rhs);
}

/// @brief Stream operator to print the Position value.
///
/// @param ostream Output stream.
/// @param position Value to print.
///
/// @return Reference to output stream.
template <typename T>
inline T& operator<<(T& ostream, const Position& position)
{
    ostream << "{" << position.x << ", " << position.y << "}";
    return ostream;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino

#endif
