#include <numeric>
#include <stdexcept>

#define FRAMEWORK_MATH_DETAILS
#include <math/inc/geometric_functions.hpp>
#include <math/inc/polygon_functions.hpp>
#undef FRAMEWORK_MATH_DETAILS

namespace framework::math
{

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
        std::advance(next, 1);
        std::advance(curr, 1);
    }
    next = polygon.begin();
    sum += (next->x - curr->x) * (next->y + curr->y);

    return sum / 2;
}

bool is_point_in_polygon(const Vector<2, float>& point, const Polygon& polygon)
{
    if (polygon.size() < 3) {
        return false;
    }

    int intersections_num = 0;

    auto curr       = std::prev(polygon.end());
    auto next       = polygon.begin();
    bool curr_under = curr->y < point.y;

    while (next != polygon.end()) {
        const Vector<2, float> a = *curr - point;
        const Vector<2, float> b = *next - point;

        const float c = cross(a, b);
        const float d = dot(a, b);

        // Point is on an edge or a vertex
        if (c == 0.0f && d <= 0.0f) {
            return false;
        }

        const bool next_under = next->y < point.y;

        if (!curr_under && next_under && c > 0) {
            intersections_num += 1;
        }
        if (curr_under && !next_under && c < 0) {
            intersections_num += 1;
        }

        curr_under = next_under;
        curr       = next;
        std::advance(next, 1);
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
