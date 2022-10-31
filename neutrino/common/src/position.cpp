#include <common/position.hpp>

namespace neutrino
{
Position::Position(int x_value, int y_value)
    : x(x_value)
    , y(y_value)
{}

bool operator==(const Position& lhs, const Position& rhs) noexcept
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Position& lhs, const Position& rhs) noexcept
{
    return !(lhs == rhs);
}

} // namespace neutrino
