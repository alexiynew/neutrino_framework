/// @file
/// @brief Window position.
/// @author Fedorov Alexey
/// @date 01.03.2019

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

#ifndef FRAMEWORK_SYSTEM_DETAILS_WINDOW_POSITION_HPP
#define FRAMEWORK_SYSTEM_DETAILS_WINDOW_POSITION_HPP

#include <common/types.hpp>

namespace framework::system
{
/// @addtogroup window_class
/// @{

/// @brief Window position.
struct window_position
{
    int32 x; ///< X coordiante.
    int32 y; ///< Y coordinate.
};

/// @brief Equality operator for window position.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
bool operator==(const window_position& lhs, const window_position& rhs);

/// @brief Inequality operator for window position.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const window_position& lhs, const window_position& rhs);

/// @brief Helper function to print window position.
///
/// @param ostream Output stream.
/// @param position Window position.
///
/// @return Reference to output stream.
template <typename T>
T& operator<<(T& ostream, const window_position& position)
{
    ostream << "{" << position.x << ", " << position.y << "}";
    return ostream;
}

/// @}

} // namespace framework::system

#endif
