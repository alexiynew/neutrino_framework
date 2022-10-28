#ifndef SYSTEM_MOUSE_HPP
#define SYSTEM_MOUSE_HPP

#include <common/position.hpp>

namespace framework::system
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup system_input_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Mouse buttons definition.
enum class MouseButton
{
    unknown = -1,

    button_1 = 0,
    button_2 = 1,
    button_3 = 2,
    button_4 = 3,
    button_5 = 4,
    button_6 = 5,

    button_left   = button_1,
    button_right  = button_2,
    button_middle = button_3,
};

/// @brief Represents cursor position in window. Zero is in top left corner.
using CursorPosition = Position;

/// @brief Represents scroll offset value.
///
/// The offset should be treated as fraction of some wheel delta which is 120 for Microsoft.
/// E.g. `offset / 120 == 1` scroll step on wheel with no notches.
/// Framework adjust system values on other platforms to that relation.
/// A positive Y value indicates that the wheel was rotated forward, away from the user.
/// A negative Y value indicates that the wheel was rotated backward, toward the user.
/// A positive X value indicates that the wheel was rotated to the right
/// A negative X value indicates that the wheel was rotated to the left.
///
///       ^ Y-
///  X+   |   X-
///  <---   --->
///       |
///       v Y+
///
using ScrollOffset = Position;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::system

#endif
