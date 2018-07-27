/// @file
/// @brief Contains geometric math functions.
/// @author Fedorov Alexey
/// @date 05.07.2017

#ifndef FRAMEWORK_MATH_DETAILS
#error You should include math/math.hpp instead of geometric_functions_details.hpp
#endif

#ifndef FRAMEWORK_MATH_GEOMETRIC_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_GEOMETRIC_FUNCTIONS_DETAILS_HPP

#include <math/details/vector_type.hpp>

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
