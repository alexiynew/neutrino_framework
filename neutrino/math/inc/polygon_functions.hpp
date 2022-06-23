
#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of polygon_functions.hpp
#endif

#ifndef FRAMEWORK_MATH_INC_POLYGON_FUNCTIONS_HPP
    #define FRAMEWORK_MATH_INC_POLYGON_FUNCTIONS_HPP

    #include <vector>

    #include <math/inc/vector_type.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_polygon_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using Polygon = std::vector<Vector<2, float>>;

bool is_point_in_triangle(const Vector<2, float>& point,
                          const Vector<2, float>& v1,
                          const Vector<2, float>& v2,
                          const Vector<2, float>& v3);

bool is_line_intersert_segment(Vector<2, float> line_start,
                               Vector<2, float> line_end,
                               Vector<2, float> segment_start,
                               Vector<2, float> segment_end);

float polygon_area(const Polygon& polygon);

bool is_point_in_polygon(const Vector<2, float>& point, const Polygon& polygon);

std::vector<std::uint32_t> generate_ear_cut_triangulation(const Polygon& polygon);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif