#include <system/keyboard.hpp>

namespace neutrino::system
{
Modifiers::operator bool()
{
    return m_state != none;
}

Modifiers& Modifiers::operator&=(int mask)
{
    m_state = static_cast<decltype(m_state)>(static_cast<int>(m_state) & mask);
    return *this;
}

Modifiers& Modifiers::operator|=(int mask)
{
    m_state = static_cast<decltype(m_state)>(static_cast<int>(m_state) | mask);
    return *this;
}

Modifiers operator&(Modifiers modifiers, int mask)
{
    modifiers &= mask;
    return modifiers;
}

Modifiers operator|(Modifiers modifiers, int mask)
{
    modifiers |= mask;
    return modifiers;
}

Modifiers operator&(int mask, Modifiers modifiers)
{
    return modifiers & mask;
}

Modifiers operator|(int mask, Modifiers modifiers)
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

} // namespace neutrino::system
