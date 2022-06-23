#include <numeric>
#include <stdexcept>

#define FRAMEWORK_MATH_DETAILS
#include <math/inc/geometric_functions.hpp>
#include <math/inc/polygon_functions.hpp>
#undef FRAMEWORK_MATH_DETAILS

namespace framework::math
{

bool is_point_in_triangle(const Vector<2, float>& point,
                          const Vector<2, float>& v1,
                          const Vector<2, float>& v2,
                          const Vector<2, float>& v3)
{
    const bool b1 = cross(point - v2, v1 - v2) < 0.0f;
    const bool b2 = cross(point - v3, v2 - v3) < 0.0f;
    const bool b3 = cross(point - v1, v3 - v1) < 0.0f;
    return ((b1 == b2) && (b2 == b3));
}

bool is_line_intersert_segment(Vector<2, float> line_start,
                               Vector<2, float> line_end,
                               Vector<2, float> segment_start,
                               Vector<2, float> segment_end)
{
    const Vector<2, float> line_direction = line_end - line_start;

    // Line equation
    const float a1 = -line_direction.y;
    const float b1 = line_direction.x;
    const float d1 = -(a1 * line_start.x + b1 * line_start.y);

    // Substitute the ends of the segments, to find out in which half-planes they are
    const float e1 = a1 * segment_start.x + b1 * segment_start.y + d1;
    const float e2 = a1 * segment_end.x + b1 * segment_end.y + d1;

    // If the ends of segment have the same sign, then it is in the same half-plane and there is no intersection.
    return e1 * e2 < 0.0f;
}

float polygon_area(const Polygon& polygon)
{
    if (polygon.size() < 3) {
        return 0.0f;
    }

    auto curr = polygon.begin();
    auto next = std::next(polygon.begin());

    float sum = 0;
    while (next != polygon.end()) {
        sum += (next->x - curr->x) * (next->y + curr->y);
        next++;
        curr++;
    }
    next = polygon.begin();
    sum += (next->x - curr->x) * (next->y + curr->y);

    return sum;
}

bool is_point_in_polygon(const Vector<2, float>& point, const Polygon& polygon)
{
    if (polygon.size() <= 1) {
        return false;
    }

    int intersections_num  = 0;
    std::size_t prev_index = polygon.size() - 1;
    bool prev_under        = polygon[prev_index].y < point.y;

    for (std::size_t i = 0; i < polygon.size(); ++i) {
        const bool curr_under = polygon[i].y < point.y;

        const Vector<2, float> a = polygon[prev_index] - point;
        const Vector<2, float> b = polygon[i] - point;

        // Determinant from x-coordinate of the intersection of the segment and the ray
        const float t = (a.x * (b.y - a.y) - a.y * (b.x - a.x));
        if (curr_under && !prev_under) {
            if (t > 0) {
                intersections_num += 1;
            }
        }
        if (!curr_under && prev_under) {
            if (t < 0) {
                intersections_num += 1;
            }
        }

        prev_index = i;
        prev_under = curr_under;
    }

    return intersections_num % 2 == 1;
}

std::vector<std::uint32_t> generate_ear_cut_triangulation(const Polygon& polygon)
{
    std::vector<std::uint32_t> indices(polygon.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::vector<std::uint32_t> triangles;
    triangles.reserve((polygon.size() - 2) * 3);

    while (indices.size() > 3) {
        std::vector<std::uint32_t> ears;

        for (size_t i = 0; i < indices.size(); ++i) {
            const std::uint32_t index_prev = i == 0 ? indices.back() : indices[i - 1];
            const std::uint32_t index_curr = indices[i];
            const std::uint32_t index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];

            const Vector<2, float> prev = polygon[index_prev];
            const Vector<2, float> curr = polygon[index_curr];
            const Vector<2, float> next = polygon[index_next];

            // angel is grater 180 degrees
            if (cross(prev - curr, next - curr) <= 0.0f) {
                continue;
            }

            bool is_ear = true;
            for (const auto& p : polygon) {
                if (p == prev || p == curr || p == next) {
                    continue;
                }

                if (is_point_in_triangle(p, prev, next, curr)) {
                    is_ear = false;
                    break;
                }
            }

            if (is_ear) {
                ears.push_back(index_curr);
            }
        }

        if (ears.empty()) {
            throw std::runtime_error("Ears are empty. It's bug in triangulation algorithm.");
        }

        size_t min_angle_index = ears[0];
        float max_dot          = -9999.0f;

        for (auto ear_index : ears) {
            auto it  = std::find(indices.begin(), indices.end(), ear_index);
            size_t i = static_cast<size_t>(std::distance(indices.begin(), it));

            const std::uint32_t index_prev = i == 0 ? indices.back() : indices[i - 1];
            const std::uint32_t index_curr = indices[i];
            const std::uint32_t index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];

            const Vector<2, float> prev = polygon[index_prev];
            const Vector<2, float> curr = polygon[index_curr];
            const Vector<2, float> next = polygon[index_next];

            auto d = dot(normalize(prev - curr), normalize(next - curr));
            if (d > max_dot) {
                max_dot         = d;
                min_angle_index = ear_index;
            }
        }

        {
            auto it  = std::find(indices.begin(), indices.end(), min_angle_index);
            size_t i = static_cast<size_t>(std::distance(indices.begin(), it));

            const std::uint32_t index_prev = i == 0 ? indices.back() : indices[i - 1];
            const std::uint32_t index_curr = indices[i];
            const std::uint32_t index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];
            triangles.push_back(index_curr);
            triangles.push_back(index_prev);
            triangles.push_back(index_next);
            indices.erase(it);
        }
    }

    // Add last triangle
    triangles.push_back(indices[0]);
    triangles.push_back(indices[2]);
    triangles.push_back(indices[1]);

    return triangles;
}
} // namespace framework::math
