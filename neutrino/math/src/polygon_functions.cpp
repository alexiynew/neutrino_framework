#include <algorithm>
#include <numeric>
#include <stdexcept>

#define FRAMEWORK_MATH_DETAILS
#include <math/inc/geometric_functions.hpp>
#include <math/inc/polygon_functions.hpp>
#undef FRAMEWORK_MATH_DETAILS

namespace
{
using namespace framework::math;

struct PointInfo
{
    std::uint32_t prev_index = 0;
    std::uint32_t curr_index = 0;
    std::uint32_t next_index = 0;
    float dot                = 0;
    bool is_ear              = false;
};

void update_info(std::vector<PointInfo>& indices,
                 std::size_t index_in_indices,
                 const Polygon& polygon,
                 const bool is_ccw)
{
    const auto prev_index_in_indices = (index_in_indices + indices.size() - 1) % indices.size();
    const auto next_index_in_indices = (index_in_indices + 1) % indices.size();

    const std::uint32_t prev_point_index = indices[prev_index_in_indices].curr_index;
    const std::uint32_t curr_point_index = indices[index_in_indices].curr_index;
    const std::uint32_t next_point_index = indices[next_index_in_indices].curr_index;

    const auto& prev = polygon[prev_point_index];
    const auto& curr = polygon[curr_point_index];
    const auto& next = polygon[next_point_index];

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

std::size_t next_ear_index(const std::vector<PointInfo>& indices)
{
    std::vector<std::size_t> ears;
    ears.reserve(indices.size());

    // find all ears
    for (std::size_t i = 0; i < indices.size(); ++i) {
        if (indices[i].is_ear) {
            ears.push_back(i);
        }
    }

    if (ears.empty()) {
        throw std::runtime_error("Ears are empty. It's bug in triangulation algorithm.");
    }

    // get best ear
    const auto it = std::max_element(ears.begin(), ears.end(), [&indices](std::size_t a, std::size_t b) {
        return indices[a].dot < indices[b].dot;
    });

    return *it;
}

} // namespace

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

std::vector<std::uint32_t> generate_ear_cut_triangulation(const Polygon& polygon)
{
    const bool is_ccw = polygon_area(polygon) < 0;

    // fill initial indices
    std::vector<PointInfo> indices(polygon.size());
    for (std::uint32_t i = 0; i < indices.size(); ++i) {
        indices[i].curr_index = i;
    }

    // precalculate point infos
    for (size_t i = 0; i < indices.size(); ++i) {
        update_info(indices, i, polygon, is_ccw);
    }

    // triangles for triangulation result
    std::vector<std::uint32_t> triangles;
    triangles.reserve((polygon.size() - 2) * 3);

    while (indices.size() > 3) {
        const auto ear_index   = next_ear_index(indices);
        const auto& point_info = indices[ear_index];

        // Add triangle
        triangles.push_back(point_info.curr_index);
        if (is_ccw) {
            triangles.push_back(point_info.next_index);
            triangles.push_back(point_info.prev_index);
        } else {
            triangles.push_back(point_info.prev_index);
            triangles.push_back(point_info.next_index);
        }

        indices.erase(std::next(indices.begin(), ear_index));

        const auto prev_index_in_indices = (ear_index + indices.size() - 1) % indices.size();
        const auto next_index_in_indices = ear_index % indices.size();

        // update neighbors point infos
        update_info(indices, prev_index_in_indices, polygon, is_ccw);
        update_info(indices, next_index_in_indices, polygon, is_ccw);
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
