#ifndef COMMON_SIZE_HPP
#define COMMON_SIZE_HPP

#include <common/global_defines.hpp>

namespace neutrino
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Size of an object with width and height.
struct Size
{
    Size() = default;

    /// @brief Creates the Size object.
    ///
    /// @param w Width.
    /// @param h Height.
    LIBRARY_API constexpr Size(int w, int h) noexcept
        : width(w)
        , height(h)
    {}

    int width  = 0; ///< Width.
    int height = 0; ///< Height.
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Size operators
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Equality operator for Size values.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
inline constexpr bool operator==(const Size& lhs, const Size& rhs) noexcept
{
    return lhs.width == rhs.width && lhs.height == rhs.height;
}

/// @brief Inequality operator for Size values.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
inline constexpr bool operator!=(const Size& lhs, const Size& rhs) noexcept
{
    return !(lhs == rhs);
}

/// @brief Stream operator to print the Size value.
///
/// @param ostream Output stream.
/// @param size Value to print.
///
/// @return Reference to output stream.
template <typename T>
inline T& operator<<(T& ostream, const Size& size)
{
    ostream << "{" << size.width << ", " << size.height << "}";
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
