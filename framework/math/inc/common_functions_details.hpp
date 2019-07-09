/// @file
/// @brief Realization details of common math functions.
/// @author Fedorov Alexey
/// @date 10.11.2017

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
#error You should include math/math.hpp instead of common_functions_details.hpp
#endif

#ifndef FRAMEWORK_MATH_DETAILS_COMMON_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_DETAILS_COMMON_FUNCTIONS_DETAILS_HPP

#include <cmath>

#include <math/inc/vector_type.hpp>

namespace framework
{
namespace math
{
/// @brief Contains implementation details of some functions.
namespace common_functions_details
{
/// @brief Realization of abs function.
/// @{
template <typename T>
inline constexpr T abs(const T& v, std::true_type /*unused*/)
{
    return (v < T{0}) ? -v : v;
}

template <typename T>
inline constexpr T abs(const T& v, std::false_type /*unused*/)
{
    return v;
}
/// @}

/// @brief Realization of sign function.
/// @{
template <typename T>
inline constexpr T sign(const T& v, std::true_type /*unused*/)
{
    return static_cast<T>((T{0} < v) - (v < T{0}));
}

template <typename T>
inline constexpr T sign(const T& v, std::false_type /*unused*/)
{
    return static_cast<T>(T{0} < v);
}
/// @}

/// @brief Realization of modf function.
/// @{
template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<4, R> modf(const vector<4, T>& value, vector<4, T>& integral)
{
    return vector<4, R>(::std::modf(value.x, &integral.x),
                        ::std::modf(value.y, &integral.y),
                        ::std::modf(value.z, &integral.z),
                        ::std::modf(value.w, &integral.w));
}

template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<3, R> modf(const vector<3, T>& value, vector<3, T>& integral)
{
    return vector<3, R>(::std::modf(value.x, &integral.x),
                        ::std::modf(value.y, &integral.y),
                        ::std::modf(value.z, &integral.z));
}

template <typename T, typename R = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline vector<2, R> modf(const vector<2, T>& value, vector<2, T>& integral)
{
    return vector<2, R>(::std::modf(value.x, &integral.x), ::std::modf(value.y, &integral.y));
}
/// @}

/// @brief Realization of mix function.
/// @{
template <typename T, typename U>
inline T mix(const T& a, const T& b, const U& t)
{
    return static_cast<T>(a + t * (b - a));
}

template <typename T>
inline T mix(const T& a, const T& b, const bool& t)
{
    return t ? b : a;
}

template <typename T, typename U>
inline constexpr vector<4, T> mix(const vector<4, T>& a, const vector<4, T>& b, const vector<4, U>& t)
{
    return vector<4, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y), mix(a.z, b.z, t.z), mix(a.w, b.w, t.w));
}

template <typename T, typename U>
inline constexpr vector<3, T> mix(const vector<3, T>& a, const vector<3, T>& b, const vector<3, U>& t)
{
    return vector<3, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y), mix(a.z, b.z, t.z));
}

template <typename T, typename U>
inline constexpr vector<2, T> mix(const vector<2, T>& a, const vector<2, T>& b, const vector<2, U>& t)
{
    return vector<2, T>(mix(a.x, b.x, t.x), mix(a.y, b.y, t.y));
}
/// @}

/// @brief Realization of frexp function.
/// @{
template <typename T, typename R>
inline vector<4, R> frexp(const vector<4, T>& value, vector<4, int32>* exp)
{
    vector<4, int32> temp;

    if (exp == nullptr) {
        exp = &temp;
    }

    return vector<4, R>(::std::frexp(value.x, &(exp->x)),
                        ::std::frexp(value.y, &(exp->y)),
                        ::std::frexp(value.z, &(exp->z)),
                        ::std::frexp(value.w, &(exp->w)));
}

template <typename T, typename R>
inline vector<3, R> frexp(const vector<3, T>& value, vector<3, int32>* exp)
{
    vector<3, int32> temp;

    if (exp == nullptr) {
        exp = &temp;
    }

    return vector<3, R>(::std::frexp(value.x, &(exp->x)),
                        ::std::frexp(value.y, &(exp->y)),
                        ::std::frexp(value.z, &(exp->z)));
}

template <typename T, typename R>
inline vector<2, R> frexp(const vector<2, T>& value, vector<2, int32>* exp)
{
    vector<2, int32> temp;

    if (exp == nullptr) {
        exp = &temp;
    }

    return vector<2, R>(::std::frexp(value.x, &(exp->x)), ::std::frexp(value.y, &(exp->y)));
}
/// @}

} // namespace common_functions_details

} // namespace math

} // namespace framework

#endif
