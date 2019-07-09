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
#error You should include math/math.hpp instead of geometric_functions.hpp
#endif

#ifndef FRAMEWORK_MATH_DETAILS_GEOMETRIC_FUNCTIONS_HPP
#define FRAMEWORK_MATH_DETAILS_GEOMETRIC_FUNCTIONS_HPP

#include <math/inc/exponential_functions.hpp>
#include <math/inc/geometric_functions_details.hpp>
#include <math/inc/vector_type.hpp>

namespace framework
{
namespace math
{
///
/// @addtogroup math_geometric_functions
/// @{

/// @name length
/// @{

/// @brief Computes the length of the vector.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The length of the vector, i.e., `sqrt(value * value)`.
template <uint32 N, typename T>
inline T length(const vector<N, T>& value)
{
    return static_cast<T>(::framework::math::sqrt(geometric_functions_details::dot(value, value)));
}
/// @}

/// @name distance
/// @{

/// @brief Computes the distance between two vectors.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The distance between two vectors, i.e., `length(b - a)`.
template <uint32 N, typename T>
inline T distance(const vector<N, T>& a, const vector<N, T>& b)
{
    return length(b - a);
}
/// @}

/// @name dot
/// @{

/// @brief Computes the dot product of two vectors.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The dot product of two vectors.
template <uint32 N, typename T>
inline T dot(const vector<N, T>& a, const vector<N, T>& b)
{
    return geometric_functions_details::dot(a, b);
}
/// @}

/// @name cross
/// @{

/// @brief Computes the cross product of two vectors.
///
/// The result is a vector that is perpendicular to both a and b and thus normal to the plane containing them.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The cross product of two vectors.
template <typename T>
inline vector<3, T> cross(const vector<3, T>& a, const vector<3, T>& b)
{
    return vector<3, T>(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}
/// @}

/// @name normalize
/// @{

/// @brief Computes a vector in the same direction as value but with length of 1.
///
/// If `length(value) == 0` then result is undefined and generate an error.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector in the same direction as value but with length of 1.
template <uint32 N, typename T>
inline vector<N, T> normalize(const vector<N, T>& value)
{
    return value * ::framework::math::invsqrt(dot(value, value));
}
/// @}

/// @name faceforward
/// @{

/// @brief Orients a vector to point away from a surface as defined by its normal.
///
/// If `dot(normal, incident) < 0` returns `value`, otherwise it returns `-value`.
///
/// @param value Vector of floating-point or integral type to orient.
/// @param incident Specifies the incident vector.
/// @param normal Specifies the normal vector.
///
/// @return A vector pointing in the same direction as another.
template <uint32 N, typename T>
inline vector<N, T> faceforward(const vector<N, T>& value, const vector<N, T>& incident, const vector<N, T>& normal)
{
    return dot(normal, incident) < T{0} ? value : -value;
}
/// @}

/// @name reflect
/// @{

/// @brief Calculate the reflection direction for an incident vector.
///
/// For a given incident vector and surface normal returns the reflection direction
/// calculated as `incident - 2.0 * dot(normal, incident) * normal`.
///
/// Normal should be normalized in order to achieve the desired result.
///
/// @param incident Specifies the incident value.
/// @param normal Specifies the normal value.
///
/// @return The reflection direction for an incident vector.
template <uint32 N, typename T>
inline vector<N, T> reflect(const vector<N, T>& incident, const vector<N, T>& normal)
{
    return incident - T{2} * dot(normal, incident) * normal;
}
/// @}

/// @name refract
/// @{

/// @brief Calculate the refraction direction for an incident vector.
///
/// For a given incident vector I, surface normal N and ratio of indices of refraction, eta,
/// returns the refraction vector, R.
///
/// R is calculated as:
/// @code
///     k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
///     if (k < 0.0)
///         R = vector(0.0);
///     else
///         R = eta * I - (eta * dot(N, I) + sqrt(k)) * N;
/// @endcode
///
/// The input parameters I and N should be normalized in order to achieve the desired result
///
/// @param incident Specifies the incident value.
/// @param normal Specifies the normal value.
/// @param eta Specifies the ratio of indices of refraction..
///
/// @return The refraction direction for an incident vector.
template <uint32 N, typename T>
inline vector<N, T> refract(const vector<N, T>& incident, const vector<N, T>& normal, const T& eta)
{
    const T dot_value   = dot(normal, incident);
    const T coefficient = T{1} - eta * eta * (T{1} - dot_value * dot_value);
    return coefficient < T{0} ? vector<N, T>(0)
                              : eta * incident - (eta * dot_value + ::framework::math::sqrt(coefficient)) * normal;
}
/// @}

/// @}

} // namespace math

} // namespace framework

#endif
