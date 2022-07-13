#include <numeric>
#include <stdexcept>

#define FRAMEWORK_MATH_DETAILS
#include <math/inc/geometric_functions.hpp>
#include <math/inc/polygon_functions.hpp>
#undef FRAMEWORK_MATH_DETAILS

#include <profiler/profiler.hpp>

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

struct PointInfo
{
    std::uint32_t prev_index = 0;
    std::uint32_t curr_index = 0;
    std::uint32_t next_index = 0;
    bool is_ear              = false;
    float dot                = 0;
};

std::vector<std::uint32_t> generate_ear_cut_triangulation(const Polygon& polygon)
{
    [[maybe_unused]] const auto& p1 = profiler::count_scope("generation");

    const bool is_ccw = polygon_area(polygon) < 0;

    std::vector<PointInfo> indices(polygon.size());
    std::generate(indices.begin(), indices.end(), [n = 0]() mutable {
        return PointInfo{0, static_cast<std::uint32_t>(n++), 0, true};
    });

    auto update_info = [&](std::size_t index_in_indices) {
        const auto prev_index_in_indices = (index_in_indices + indices.size() - 1) % indices.size();
        const auto next_index_in_indices = (index_in_indices + 1) % indices.size();

        const std::uint32_t prev_point_index = indices[prev_index_in_indices].curr_index;
        const std::uint32_t curr_point_index = indices[index_in_indices].curr_index;
        const std::uint32_t next_point_index = indices[next_index_in_indices].curr_index;

        const Vector<2, float>& prev = polygon[prev_point_index];
        const Vector<2, float>& curr = polygon[curr_point_index];
        const Vector<2, float>& next = polygon[next_point_index];

        // update point neighbors indices
        indices[index_in_indices].next_index = next_point_index;
        indices[index_in_indices].prev_index = prev_point_index;

        // update dot
        indices[index_in_indices].dot = dot(normalize(prev - curr), normalize(next - curr));

        // update is ear
        const auto c           = cross(prev - curr, next - curr);
        const bool valid_angle = !((!is_ccw && c <= 0.0f) || (is_ccw && c >= 0.0f));

        if (valid_angle) {
            indices[index_in_indices].is_ear = [&]() {
                for (const auto& pi : indices) {
                    const auto& p = polygon[pi.curr_index];
                    if (p == prev || p == curr || p == next) {
                        continue;
                    }

                    if (is_point_in_triangle(p, prev, next, curr)) {
                        return false;
                    }
                }
                return true;
            }();
        } else {
            indices[index_in_indices].is_ear = false;
        }
    };

    {
        [[maybe_unused]] const auto& p2 = profiler::count_scope("precalc");

        for (size_t i = 0; i < indices.size(); ++i) {
            update_info(i);
        }
    }

    std::vector<std::uint32_t> triangles;
    triangles.reserve((polygon.size() - 2) * 3);

    while (indices.size() > 3) {

        [[maybe_unused]] const auto& p2 = profiler::count_scope("loop");
        std::vector<std::size_t> ears;
        ears.reserve(indices.size());

        {
            [[maybe_unused]] const auto& p3 = profiler::count_scope("ears");
            for (std::size_t i = 0; i < indices.size(); ++i) {
                if (indices[i].is_ear) {
                    ears.push_back(i);
                }
            }
        }

        if (ears.empty()) {
            throw std::runtime_error("Ears are empty. It's bug in triangulation algorithm.");
        }

        size_t min_angle_index = ears[0];
        {
            [[maybe_unused]] const auto& p3 = profiler::count_scope("best");
            min_angle_index = *(std::max_element(ears.begin(), ears.end(), [&indices](std::size_t a, std::size_t b) {
                return indices[a].dot < indices[b].dot;
            }));
        }

        {
            [[maybe_unused]] const auto& p4 = profiler::count_scope("add");

            const auto& point_info = indices[min_angle_index];

            // Add triangle
            triangles.push_back(point_info.curr_index);
            if (is_ccw) {
                triangles.push_back(point_info.next_index);
                triangles.push_back(point_info.prev_index);
            } else {
                triangles.push_back(point_info.prev_index);
                triangles.push_back(point_info.next_index);
            }

            indices.erase(std::next(indices.begin(), min_angle_index));

            const auto prev_index_in_indices = (min_angle_index + indices.size() - 1) % indices.size();
            const auto next_index_in_indices = min_angle_index % indices.size();

            // update neighbors point infos
            update_info(prev_index_in_indices);
            update_info(next_index_in_indices);
        }
    }

    // Add last triangle
    triangles.push_back(indices[0].curr_index);
    if (is_ccw) {
        triangles.push_back(indices[1].curr_index);
        triangles.push_back(indices[2].curr_index);
    } else {
        triangles.push_back(indices[2].curr_index);
        triangles.push_back(indices[1].curr_index);
    }

    return triangles;
}

} // namespace framework::math
