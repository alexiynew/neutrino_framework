/// @file
/// @brief Contains relational math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017

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
    #error You should include math/math.hpp instead of relational_functions_details.hpp
#endif

#ifndef FRAMEWORK_MATH_INC_RELATIONAL_FUNCTIONS_DETAILS_HPP
    #define FRAMEWORK_MATH_INC_RELATIONAL_FUNCTIONS_DETAILS_HPP

    #include <functional>

    #include <common/types.hpp>

    #include <math/inc/common_functions.hpp>
    #include <math/inc/matrix_type.hpp>
    #include <math/inc/vector_type.hpp>

namespace framework::math::relational_functions_details
{
/// @brief Realization of almost_equal function.
/// @{
template <typename T>
inline bool almost_equal_implementation(const T& a, const T& b, int32 ulp, std::true_type /*unused*/)
{
    const auto scaled_epsilon = std::numeric_limits<T>::epsilon() * static_cast<T>(ulp);
    const auto difference     = framework::math::abs(a - b);
    return difference < scaled_epsilon || difference < std::numeric_limits<T>::min();
}

template <typename T>
inline bool almost_equal_implementation(const T& a, const T& b, int32 /*unused*/, std::false_type /*unused*/)
{
    return a == b;
}

template <uint32 N, typename T>
inline bool almost_equal_implementation(const vector<N, T>& a, const vector<N, T>& b, int32 ulp = 0)
{
    constexpr vector<N, bool> true_vector{true};
    return true_vector == transform(a, b, [ulp](const T& component_a, const T& component_b) {
               return almost_equal_implementation(component_a, component_b, ulp, std::is_floating_point<T>{});
           });
}

template <uint32 C, uint32 R, typename T>
inline bool almost_equal_implementation(const matrix<C, R, T>& a, const matrix<C, R, T>& b, int32 ulp = 0)
{
    for (uint32 i = 0; i < C; ++i) {
        if (!almost_equal_implementation(a[i], b[i], ulp)) {
            return false;
        }
    }
    return true;
}
/// @}

/// @brief Realization of any function.
/// @{
inline bool any_implementation(const vector<4, bool>& v)
{
    return v.x || v.y || v.z || v.w;
}

inline bool any_implementation(const vector<3, bool>& v)
{
    return v.x || v.y || v.z;
}

inline bool any_implementation(const vector<2, bool>& v)
{
    return v.x || v.y;
}
/// @}

/// @brief Realization of all function.
/// @{
inline bool all_implementation(const vector<4, bool>& v)
{
    return v.x && v.y && v.z && v.w;
}

inline bool all_implementation(const vector<3, bool>& v)
{
    return v.x && v.y && v.z;
}

inline bool all_implementation(const vector<2, bool>& v)
{
    return v.x && v.y;
}
/// @}

} // namespace framework::math::relational_functions_details

#endif
