/// @file
/// @brief Contains relational math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017

#ifndef FRAMEWORK_MATH_RELATIONAL_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_RELATIONAL_FUNCTIONS_DETAILS_HPP

#include <common/common_types.hpp>
#include <functional>
#include <math/common_functions.hpp>
#include <math/matrix_type.hpp>
#include <math/vector_type.hpp>

namespace framework {

namespace math {

/// @brief Contains implementation details of some functions.
namespace relational_functions_details {

/// @brief Realization of almost_equal function.
/// @{
template <typename T>
inline bool almost_equal_implementation(const T& a, const T& b, int32 ulp, std::true_type)
{
    const auto scaled_epsilon = std::numeric_limits<T>::epsilon() * ::framework::math::abs(a + b) * static_cast<T>(ulp);
    const auto difference     = ::framework::math::abs(a - b);
    return difference < scaled_epsilon || difference < std::numeric_limits<T>::min();
}

template <typename T>
inline bool almost_equal_implementation(const T& a, const T& b, int32, std::false_type)
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

} // namespace relational_functions_details

} // namespace math

} // namespace framework

#endif
