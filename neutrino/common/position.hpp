////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Position.
/// @author Fedorov Alexey
/// @date 01.03.2019
////////////////////////////////////////////////////////////////////////////////

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

#ifndef FRAMEWORK_COMMON_POSITION_HPP
#define FRAMEWORK_COMMON_POSITION_HPP

namespace framework
{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup common_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Position of an object in 2d space.
////////////////////////////////////////////////////////////////////////////////
struct Position
{
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates the Position object.
    ///
    /// @param x_value X coordinate.
    /// @param y_value Y coordinate.
    ////////////////////////////////////////////////////////////////////////////
    Position(int x_value, int y_value);

    int x; ///< X coordiante.
    int y; ///< Y coordinate.
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator for Position values.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator==(const Position& lhs, const Position& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Inequality operator for Position values.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator!=(const Position& lhs, const Position& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Stream operator to print the Position value.
///
/// @param ostream Output stream.
/// @param position Value to print.
///
/// @return Reference to output stream.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
T& operator<<(T& ostream, const Position& position)
{
    ostream << "{" << position.x << ", " << position.y << "}";
    return ostream;
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework

#endif
