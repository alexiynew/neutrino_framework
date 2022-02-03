#include <common/size.hpp>

namespace framework
{
Size::Size(int w, int h)
    : width(w)
    , height(h)
{}

bool operator==(const Size& lhs, const Size& rhs) noexcept
{
    return lhs.width == rhs.width && lhs.height == rhs.height;
}

bool operator!=(const Size& lhs, const Size& rhs) noexcept
{
    return !(lhs == rhs);
}

} // namespace framework
