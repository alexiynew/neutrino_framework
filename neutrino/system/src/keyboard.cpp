/// @file
/// @brief Keyboard.
/// @author Fedorov Alexey
/// @date 18.03.20

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

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
