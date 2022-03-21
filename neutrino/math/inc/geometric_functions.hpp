#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of geometric_functions.hpp
#endif

#ifndef FRAMEWORK_MATH_INC_GEOMETRIC_FUNCTIONS_HPP
    #define FRAMEWORK_MATH_INC_GEOMETRIC_FUNCTIONS_HPP

    #include <math/inc/exponential_functions.hpp>
    #include <math/inc/geometric_functions_details.hpp>
    #include <math/inc/vector_type.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_geometric_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name length
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the length of the vector.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The length of the vector, i.e., `sqrt(value * value)`.
template <std::size_t N, typename T>
inline T length(const Vector<N, T>& value)
{
    return static_cast<T>(framework::math::sqrt(geometric_functions_details::dot(value, value)));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name distance
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the distance between two vectors.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The distance between two vectors, i.e., `length(b - a)`.
template <std::size_t N, typename T>
inline T distance(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return length(b - a);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name dot
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the dot product of two vectors.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The dot product of two vectors.
template <std::size_t N, typename T>
inline T dot(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return geometric_functions_details::dot(a, b);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name cross
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the cross product of two vectors.
///
/// The result is a vector that is perpendicular to both a and b and thus normal
/// to the plane containing them.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The cross product of two vectors.
template <typename T>
inline Vector<3, T> cross(const Vector<3, T>& a, const Vector<3, T>& b)
{
    return Vector<3, T>(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}

/// @brief Computes the cross product of two vectors.
///
/// The result is a scalar value, the magnitude of the vector that would result from a regular 3D cross product of the
/// input vectors, taking their Z values implicitly as 0 (i.e. treating the 2D space as a plane in the 3D space). The 3D
/// cross product will be perpendicular to that plane, and thus have 0 X & Y components (thus the scalar returned is the
/// Z value of the 3D cross product vector).
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The cross product of two vectors.
template <typename T>
inline T cross(const Vector<2, T>& a, const Vector<2, T>& b)
{
    return a.x * b.y - b.x * a.y;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name normalize
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes a vector in the same direction as value but with length of 1.
///
/// If `length(value) == 0` then result is undefined and generate an error.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The vector in the same direction as value but with length of 1.
template <std::size_t N, typename T>
inline Vector<N, T> normalize(const Vector<N, T>& value)
{
    return value * framework::math::invsqrt(dot(value, value));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name faceforward
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Orients a vector to point away from a surface as defined by its normal.
///
/// If `dot(normal, incident) < 0` returns `value`, otherwise it
/// returns `-value`.
///
/// @param value Vector of floating-point or integral type to orient.
/// @param incident Specifies the incident vector.
/// @param normal Specifies the normal vector.
///
/// @return A vector pointing in the same direction as another.
template <std::size_t N, typename T>
inline Vector<N, T> faceforward(const Vector<N, T>& value, const Vector<N, T>& incident, const Vector<N, T>& normal)
{
    return dot(normal, incident) < T{0} ? value : -value;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name reflect
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Calculate the reflection direction for an incident vector.
///
/// For a given incident vector and surface normal returns the reflection
/// direction calculated as `incident - 2.0 * dot(normal, incident) * normal`.
///
/// Normal should be normalized in order to achieve the desired result.
///
/// @param incident Specifies the incident value.
/// @param normal Specifies the normal value.
///
/// @return The reflection direction for an incident vector.
template <std::size_t N, typename T>
inline Vector<N, T> reflect(const Vector<N, T>& incident, const Vector<N, T>& normal)
{
    return incident - T{2} * dot(normal, incident) * normal;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name refract
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Calculate the refraction direction for an incident vector.
///
/// For a given incident vector I, surface normal N and ratio of indices
/// of refraction, eta, returns the refraction vector, R.
///
/// R is calculated as:
/// @code
///     k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
///     if (k < 0.0)
///         R = Vector(0.0);
///     else
///         R = eta * I - (eta * dot(N, I) + sqrt(k)) * N;
/// @endcode
///
/// The input parameters I and N should be normalized in order
/// to achieve the desired result
///
/// @param incident Specifies the incident value.
/// @param normal Specifies the normal value.
/// @param eta Specifies the ratio of indices of refraction..
///
/// @return The refraction direction for an incident vector.
template <std::size_t N, typename T>
inline Vector<N, T> refract(const Vector<N, T>& incident, const Vector<N, T>& normal, const T& eta)
{
    const T dot_value   = dot(normal, incident);
    const T coefficient = T{1} - eta * eta * (T{1} - dot_value * dot_value);
    return coefficient < T{0} ? Vector<N, T>(0) :
                                eta * incident - (eta * dot_value + framework::math::sqrt(coefficient)) * normal;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
