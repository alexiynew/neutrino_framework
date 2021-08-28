// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#ifndef FRAMEWORK_COMMON_SIZE_HPP
#define FRAMEWORK_COMMON_SIZE_HPP

namespace framework
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup common_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Size of an object with width and height.
////////////////////////////////////////////////////////////////////////////////
struct Size
{
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates the Size object.
    ///
    /// @param w Width.
    /// @param h Height.
    ////////////////////////////////////////////////////////////////////////////
    Size(int w, int h);

    int width;  ///< Width.
    int height; ///< Height.
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator for Size values.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator==(const Size& lhs, const Size& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Inequality operator for Size values.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator!=(const Size& lhs, const Size& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Stream operator to print the Size value.
///
/// @param ostream Output stream.
/// @param size Value to print.
///
/// @return Reference to output stream.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
T& operator<<(T& ostream, const Size& size)
{
    ostream << "{" << size.width << ", " << size.height << "}";
    return ostream;
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework

#endif
