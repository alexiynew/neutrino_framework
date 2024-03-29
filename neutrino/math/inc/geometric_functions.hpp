#ifndef MATH_INC_GEOMETRIC_FUNCTIONS_HPP
#define MATH_INC_GEOMETRIC_FUNCTIONS_HPP

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
/// @name squared length
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the squared length of the vector.
///
/// @param value Vector of floating-point or integral type.
///
/// @return The squared length of the vector, i.e., `dot(value, value)`.
template <std::size_t N, typename T>
inline T squared_length(const Vector<N, T>& value)
{
    return static_cast<T>(geometric_functions_details::dot(value, value));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
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
    return static_cast<T>(framework::math::sqrt(squared_length(value)));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name squared distance
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the squared distance between two vectors.
///
/// @param a Vector of floating-point or integral type.
/// @param b Vector of floating-point or integral type.
///
/// @return The squared distance between two vectors, i.e., `squared_length(b - a)`.
template <std::size_t N, typename T>
inline T squared_distance(const Vector<N, T>& a, const Vector<N, T>& b)
{
    return squared_length(b - a);
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
/// If result is 0, vectors are collinear.
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
/// @name line and segment
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Check if point is on a line.
///
/// @param point Point to test.
/// @param line_start First line point.
/// @param line_end Second line point.
///
/// @return `true` if point is on a line.
template <typename T>
inline bool on_line(const Vector<2, T>& point, const Vector<2, T>& line_start, const Vector<2, T>& line_end)
{
    return cross(line_start - point, line_end - point) == 0.0f;
}

/// @brief Check if point is on a segment.
///
/// The ends of the segment are taken into account.
///
/// @param point Point to test.
/// @param segment_start Segment start point.
/// @param segment_end Segment end point.
///
/// @return `true` if point is on a segment.
template <typename T>
inline bool on_segment(const Vector<2, T>& point, const Vector<2, T>& segment_start, const Vector<2, T>& segment_end)
{
    const auto v1 = segment_start - point;
    const auto v2 = segment_end - point;
    return cross(v1, v2) == 0.0f && dot(v1, v2) <= 0.0f;
}

/// @brief Check if iine intersects a segment.
///
/// The ends of the segment are taken into account in the intersection.
///
/// @param line_start First line point.
/// @param line_end Second line point.
/// @param segment_start Segment start point.
/// @param segment_end Segment end point.
///
/// @return `true` if line intersects a segment.
template <typename T>
inline bool is_line_intersects_segment(const Vector<2, T>& line_start,
                                       const Vector<2, T>& line_end,
                                       const Vector<2, T>& segment_start,
                                       const Vector<2, T>& segment_end)
{
    const Vector<2, T> line_direction = line_end - line_start;

    // Line equation
    const T a1 = -line_direction.y;
    const T b1 = line_direction.x;
    const T d1 = -(a1 * line_start.x + b1 * line_start.y);

    // Substitute the ends of the segments, to find out in which half-planes they are
    const T e1 = a1 * segment_start.x + b1 * segment_start.y + d1;
    const T e2 = a1 * segment_end.x + b1 * segment_end.y + d1;

    // If the ends of segment have the same sign, then it is in the same half-plane and there is no intersection.
    return e1 * e2 <= 0.0f;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name triangle
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Check if a point is inside a triangle on a 2D plane.
///
/// Points lying on edges or at one of the vertices are included in the triangle.
///
/// @param point 2d point.
/// @param v1 Vertex of a triangle.
/// @param v2 Vertex of a triangle.
/// @param v3 Vertex of a triangle.
///
/// @return `true`if a point is inside a triangle.
template <typename T>
inline bool is_point_in_triangle(const Vector<2, T>& point,
                                 const Vector<2, T>& v1,
                                 const Vector<2, T>& v2,
                                 const Vector<2, T>& v3)
{
    const auto c1 = cross(point - v2, v1 - v2);
    const auto c2 = cross(point - v3, v2 - v3);
    const auto c3 = cross(point - v1, v3 - v1);

    // If all vector magnitudes has the same sign, the point is inside a triangle.
    const bool neg1 = c1 < 0.0f;
    const bool neg2 = c2 < 0.0f;
    const bool neg3 = c3 < 0.0f;

    const bool inside    = (neg1 == neg2) && (neg2 == neg3);
    const bool on_edge   = (c1 == 0.0f && neg2 == neg3) || (c2 == 0.0f && neg1 == neg3) || (c3 == 0.0f && neg1 == neg2);
    const bool on_vertex = (c1 == 0 && c2 == 0 && c3 != 0) || (c1 == 0 && c2 != 0 && c3 == 0) ||
                           (c1 != 0 && c2 == 0 && c3 == 0);

    return inside || on_edge || on_vertex;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
