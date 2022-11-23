#include <algorithm>
#include <iterator>

#include <math/math.hpp>
#include <unit_test/suite.hpp>

using neutrino::math::Polygon;
using neutrino::math::Vector2f;

class PolygonFunctionsTest : public neutrino::unit_test::Suite
{
public:
    PolygonFunctionsTest()
        : Suite("PolygonFunctionsTest")
    {
        add_test([this]() { polygon_area_function(); }, "polygon_area_function");
        add_test([this]() { is_point_in_polygon_function(); }, "is_point_in_polygon_function");
        add_test([this]() { generate_ear_cut_triangulation_function(); }, "generate_ear_cut_triangulation_function");
    }

private:
    void polygon_area_function()
    {
        const Polygon p1{{1, 1}, {4, 1}, {4, 3}, {1, 3}}; // ccw order
        Polygon p2;                                       // cw order
        std::reverse_copy(p1.begin(), p1.end(), std::back_inserter(p2));

        const float a1 = polygon_area(p1);
        const float a2 = polygon_area(p2);

        TEST_ASSERT(a1 == -a2, "Sign of the polygon areas must be different for different winding order.");
        TEST_ASSERT(a1 == -6, "Wrong area of a polygon.");
        TEST_ASSERT(a2 == 6, "Wrong area of a polygon.");

        const Polygon p3{{1, 1}, {1, -1}, {2, 2}, {-1, 2}, {-3, 1}, {2, -3}, {-1, 1}}; // ccw order
        Polygon p4;                                                                    // cw order
        std::reverse_copy(p3.begin(), p3.end(), std::back_inserter(p4));

        const float a3 = polygon_area(p3);
        const float a4 = polygon_area(p4);

        TEST_ASSERT(a3 == -a4, "Sign of the polygon areas must be different for different winding order.");
        TEST_ASSERT(a3 == -8.5, "Wrong area of a polygon.");
        TEST_ASSERT(a4 == 8.5, "Wrong area of a polygon.");
    }

    void is_point_in_polygon_function()
    {
        const Polygon poly1{{-1, -3}, {-1, 1}, {1, 1}, {1, -3}, {0, 0}};
        const Polygon poly2{{0, 0}, {1, -3}, {1, 1}, {-1, 1}, {-1, -3}};

        const Vector2f p1{0, 0};           // 1
        const Vector2f p2{0, 1};           // 1
        const Vector2f p3{1, 0};           // 1
        const Vector2f p4{0.5f, -1};       // 1
        const Vector2f p5{-0.5f, 0.9999f}; // 1
        const Vector2f p6{0, -2};          // 0
        const Vector2f p7{-3, 1};          // 0
        const Vector2f p8{-0.8f, -2};      // 1

        const bool r11 = is_point_in_polygon(p1, poly1);
        const bool r12 = is_point_in_polygon(p2, poly1);
        const bool r13 = is_point_in_polygon(p3, poly1);
        const bool r14 = is_point_in_polygon(p4, poly1);
        const bool r15 = is_point_in_polygon(p5, poly1);
        const bool r16 = is_point_in_polygon(p6, poly1);
        const bool r17 = is_point_in_polygon(p7, poly1);
        const bool r18 = is_point_in_polygon(p8, poly1);

        const bool r21 = is_point_in_polygon(p1, poly2);
        const bool r22 = is_point_in_polygon(p2, poly2);
        const bool r23 = is_point_in_polygon(p3, poly2);
        const bool r24 = is_point_in_polygon(p4, poly2);
        const bool r25 = is_point_in_polygon(p5, poly2);
        const bool r26 = is_point_in_polygon(p6, poly2);
        const bool r27 = is_point_in_polygon(p7, poly2);
        const bool r28 = is_point_in_polygon(p8, poly2);

        TEST_ASSERT(r11 == r21 && r11 == true, "Wrong point in polygon calculation.");
        TEST_ASSERT(r12 == r22 && r12 == true, "Wrong point in polygon calculation.");
        TEST_ASSERT(r13 == r23 && r13 == true, "Wrong point in polygon calculation.");
        TEST_ASSERT(r14 == r24 && r14 == true, "Wrong point in polygon calculation.");
        TEST_ASSERT(r15 == r25 && r15 == true, "Wrong point in polygon calculation.");
        TEST_ASSERT(r16 == r26 && r16 == false, "Wrong point in polygon calculation.");
        TEST_ASSERT(r17 == r27 && r17 == false, "Wrong point in polygon calculation.");
        TEST_ASSERT(r18 == r28 && r18 == true, "Wrong point in polygon calculation.");
    }

    void generate_ear_cut_triangulation_function()
    {
        const Polygon p1{{-2, 5}, {-2, 1}, {4, 1}, {-1, 2}};
        const Polygon p2{{-1, 2}, {4, 1}, {-2, 1}, {-2, 5}};

        const std::vector<std::uint32_t> t1_test = {2, 3, 1, 0, 1, 3};
        const std::vector<std::uint32_t> t2_test = {1, 0, 2, 0, 3, 2};

        const auto t1 = generate_ear_cut_triangulation(p1);
        const auto t2 = generate_ear_cut_triangulation(p2);

        TEST_ASSERT(t1 == t1_test, "Wrong triangulation result");
        TEST_ASSERT(t2 == t2_test, "Wrong triangulation result");
    }
};

int main()
{
    return run_tests(PolygonFunctionsTest());
}
