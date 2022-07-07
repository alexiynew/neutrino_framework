#include <chrono>
#include <fstream>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>

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

#define TS std::to_string((std::chrono::high_resolution_clock::now() - start).count())

#define BEGIN(name) \
    events.push_back("{\"name\": " #name ", \"ph\": \"B\", \"pid\": 123, \"tid\": 456, \"ts\":" + TS + "},\n");

#define END(name) \
    events.push_back("{\"name\": " #name ", \"ph\": \"E\", \"pid\": 123, \"tid\": 456, \"ts\":" + TS + "},\n");

#define LAST(name) \
    events.push_back("{\"name\": " #name ", \"ph\": \"E\", \"pid\": 123, \"tid\": 456, \"ts\":" + TS + "}\n");

std::vector<std::uint32_t> generate_ear_cut_triangulation(const Polygon& polygon)
{
    const auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> events;
    events.reserve(10000);

    events.push_back("{\n\"traceEvents\": [\n");
    BEGIN("generation")

    const bool is_ccw = polygon_area(polygon) < 0;

    std::vector<std::uint32_t> indices(polygon.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::vector<std::uint32_t> triangles;
    triangles.reserve((polygon.size() - 2) * 3);

    while (indices.size() > 3) {

        BEGIN("loop")
        std::vector<std::uint32_t> ears;

        BEGIN("ears")
        for (size_t i = 0; i < indices.size(); ++i) {
            const std::uint32_t index_prev = i == 0 ? indices.back() : indices[i - 1];
            const std::uint32_t index_curr = indices[i];
            const std::uint32_t index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];

            const Vector<2, float> prev = polygon[index_prev];
            const Vector<2, float> curr = polygon[index_curr];
            const Vector<2, float> next = polygon[index_next];

            // angel is grater 180 degrees
            const auto c = cross(prev - curr, next - curr);
            if ((!is_ccw && c <= 0.0f) || (is_ccw && c >= 0.0f)) {
                continue;
            }

            bool is_ear = true;
            for (const auto& index : indices) {
                const auto& p = polygon[index];
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
        END("ears")

        if (ears.empty()) {
            throw std::runtime_error("Ears are empty. It's bug in triangulation algorithm.");
        }

        size_t min_angle_index = ears[0];
        float max_dot          = -9999.0f;

        BEGIN("best")
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
        END("best")

        {
            BEGIN("add")
            auto it  = std::find(indices.begin(), indices.end(), min_angle_index);
            size_t i = static_cast<size_t>(std::distance(indices.begin(), it));

            const std::uint32_t index_prev = i == 0 ? indices.back() : indices[i - 1];
            const std::uint32_t index_curr = indices[i];
            const std::uint32_t index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];

            // Add triangle
            triangles.push_back(index_curr);
            if (is_ccw) {
                triangles.push_back(index_next);
                triangles.push_back(index_prev);
            } else {
                triangles.push_back(index_prev);
                triangles.push_back(index_next);
            }
            indices.erase(it);
            END("add")
        }

        END("loop")
    }

    BEGIN("last")
    // Add last triangle
    triangles.push_back(indices[0]);
    if (is_ccw) {
        triangles.push_back(indices[1]);
        triangles.push_back(indices[2]);
    } else {
        triangles.push_back(indices[2]);
        triangles.push_back(indices[1]);
    }
    END("last")

    LAST("generation")

    events.push_back("],\n\"displayTimeUnit\": \"ns\"\n }\n\n");

    std::ofstream out("test.json", std::ios_base::out);
    for (const auto& s : events) {
        out << s;
    }

    return triangles;
}
} // namespace framework::math
