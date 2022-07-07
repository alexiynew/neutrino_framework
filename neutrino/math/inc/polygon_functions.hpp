#ifndef FRAMEWORK_MATH_INC_POLYGON_FUNCTIONS_HPP
#define FRAMEWORK_MATH_INC_POLYGON_FUNCTIONS_HPP

#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of polygon_functions.hpp
#endif

#include <vector>

#include <math/inc/vector_type.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_polygon_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Alias for the polygon type, it's just a collection of 2d points.
using Polygon = std::vector<Vector<2, float>>;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name polygon
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Computes the area of a polygon.
///
/// In a coordinate system where the y-axis is up and the x-axis is to the right,
/// the area of the polygon is positive when points winding order is clockwise
/// and negative when points winding order is counterclockwise.
///
/// @param polygon Polygon to get the area.
///
/// @return Area of the polygon.
float polygon_area(const Polygon& polygon);

/// @brief Check if point is inside a polygon.
///
/// Points lying on edges or at one of the vertices are included in the polygon.
///
/// @param point Point to check.
/// @param polygon Polygon to check.
///
/// @return `true` if a point is inside a polygon.
bool is_point_in_polygon(const Vector<2, float>& point, const Polygon& polygon);

/// @brief Generates triangulation of a polygon.
///
/// Uses the ear cut algorithm.
/// Assuming the polygon has no holes or edge intersections.
/// Creates polygon point indexes that represent the triangles in the resulting triangulation. Every 3 indices is 1
/// triangle. The points in the triangle are arranged counterclockwise.
///
/// @param polygon Polygon to build triangulation.
///
/// @return Indices of polygon points that form triangles in the triangulation.
std::vector<std::uint32_t> generate_ear_cut_triangulation(const Polygon& polygon);

// DelaunayTriangulation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif