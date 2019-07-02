/// @file
/// @brief Window size.
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

#ifndef FRAMEWORK_GRAPHICS_WINDOW_WINDOW_SIZE_HPP
#define FRAMEWORK_GRAPHICS_WINDOW_WINDOW_SIZE_HPP

#include <common/types.hpp>

namespace framework::window
{
/// @addtogroup window_class
/// @{

/// @brief Window size.
struct window_size
{
    int32 width;  ///< Window width.
    int32 height; ///< Window height.
};

/// @brief Equality operator for window size.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
bool operator==(const window_size& lhs, const window_size& rhs);

/// @brief Inequality operator for window size.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const window_size& lhs, const window_size& rhs);

/// @brief Helper function to print window size.
///
/// @param ostream Output stream.
/// @param size Window size.
///
/// @return Reference to output stream.
template <typename T>
T& operator<<(T& ostream, const window_size& size)
{
    ostream << "{" << size.width << ", " << size.height << "}";
    return ostream;
}

/// @}

} // namespace framework::window

#endif
