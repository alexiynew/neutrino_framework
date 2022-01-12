#include <utility>

#include <system/keyboard.hpp>

namespace framework::system
{
Modifiers::operator bool()
{
    return m_state != none;
}

Modifiers& Modifiers::operator&=(int32 mask)
{
    m_state = static_cast<decltype(m_state)>(static_cast<int32>(m_state) & mask);
    return *this;
}

Modifiers& Modifiers::operator|=(int32 mask)
{
    m_state = static_cast<decltype(m_state)>(static_cast<int32>(m_state) | mask);
    return *this;
}

Modifiers operator&(Modifiers modifiers, int32 mask)
{
    modifiers &= mask;
    return modifiers;
}

Modifiers operator|(Modifiers modifiers, int32 mask)
{
    modifiers |= mask;
    return modifiers;
}

Modifiers operator&(int32 mask, Modifiers modifiers)
{
    return modifiers & mask;
}

Modifiers operator|(int32 mask, Modifiers modifiers)
{
    return modifiers | mask;
}

bool Modifiers::operator==(Modifiers rhs)
{
    return m_state == rhs.m_state;
}

bool Modifiers::operator!=(Modifiers rhs)
{
    return !(*this == rhs);
}

} // namespace framework::system
