/// @file
/// @brief Contains geometric math functions.
/// @author Fedorov Alexey
/// @date 05.07.2017

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

#ifndef FRAMEWORK_MATH_DETAILS
#error You should include math/math.hpp instead of geometric_functions_details.hpp
#endif

#ifndef FRAMEWORK_MATH_DETAILS_GEOMETRIC_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_DETAILS_GEOMETRIC_FUNCTIONS_DETAILS_HPP

#include <math/inc/vector_type.hpp>

namespace framework
{
namespace math
{
namespace geometric_functions_details
{
/// @brief Realization of dot function.
/// @{
template <typename T>
inline constexpr T dot(const vector<4, T>& a, const vector<4, T>& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

template <typename T>
inline constexpr T dot(const vector<3, T>& a, const vector<3, T>& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

template <typename T>
inline constexpr T dot(const vector<2, T>& a, const vector<2, T>& b)
{
    return (a.x * b.x) + (a.y * b.y);
}
/// @}

} // namespace geometric_functions_details

} // namespace math

} // namespace framework

#endif
