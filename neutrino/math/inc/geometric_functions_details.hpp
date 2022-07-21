#ifndef FRAMEWORK_MATH_INC_GEOMETRIC_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_INC_GEOMETRIC_FUNCTIONS_DETAILS_HPP

#include <math/inc/vector_type.hpp>

namespace framework::math::geometric_functions_details
{
template <typename T>
inline constexpr T dot(const Vector<4, T>& a, const Vector<4, T>& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

template <typename T>
inline constexpr T dot(const Vector<3, T>& a, const Vector<3, T>& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

template <typename T>
inline constexpr T dot(const Vector<2, T>& a, const Vector<2, T>& b)
{
    return (a.x * b.x) + (a.y * b.y);
}

} // namespace framework::math::geometric_functions_details

#endif
