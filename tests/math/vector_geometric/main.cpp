#include <math/math.hpp>
#include <unit_test/suite.hpp>

using neutrino::math::Vector2f;
using neutrino::math::Vector3f;

using neutrino::math::almost_equal;

class GeometricFunctionsTest : public neutrino::unit_test::Suite
{
public:
    GeometricFunctionsTest()
        : Suite("GeometricFunctionsTest")
    {
        add_test([this]() { squared_length_function(); }, "squared_length_function");
        add_test([this]() { length_function(); }, "length_function");
        add_test([this]() { squared_distance_function(); }, "squared_distance_function");
        add_test([this]() { distance_function(); }, "distance_function");
        add_test([this]() { dot_function(); }, "dot_function");
        add_test([this]() { cross_function(); }, "cross_function");
        add_test([this]() { normalize_function(); }, "normalize_function");
        add_test([this]() { faceforward_function(); }, "faceforward_function");
        add_test([this]() { reflection_function(); }, "reflection_function");
        add_test([this]() { refraction_function(); }, "refraction_function");
        add_test([this]() { on_line_function(); }, "on_line_function");
        add_test([this]() { on_segment_function(); }, "on_segment_function");
        add_test([this]() { is_line_intersects_segment_function(); }, "is_line_intersects_segment_function");
        add_test([this]() { triangle_function(); }, "triangle_function");

        v3f = {1.0f, 2.0f, 3.0f};
    }

private:
    void squared_length_function()
    {
        TEST_ASSERT(squared_length(Vector3f(2, 2, 2)) == 12.0f, "Squared length function failed.");
    }

    void length_function()
    {
        TEST_ASSERT(almost_equal(length(v3f), 3.7416574954986572f), "Length function failed.");
    }

    void squared_distance_function()
    {
        const Vector3f v3f1 = {3.0f, 3.0f, 5.0f};
        const Vector3f v3f2 = {2.0f, 1.0f, 2.0f};

        TEST_ASSERT(squared_distance(v3f1, v3f2) == squared_length(v3f), "Squared distance function failed.");
        TEST_ASSERT(squared_distance(v3f1, v3f2) == squared_length(v3f), "Squared distance function failed.");
    }

    void distance_function()
    {
        const Vector3f v3f1 = {3.0f, 3.0f, 5.0f};
        const Vector3f v3f2 = {2.0f, 1.0f, 2.0f};

        TEST_ASSERT(almost_equal(distance(v3f1, v3f2), length(v3f)), "Distance function failed.");
        TEST_ASSERT(almost_equal(distance(v3f1, v3f2), length(v3f)), "Distance function failed.");
    }

    void dot_function()
    {
        TEST_ASSERT(almost_equal(dot(v3f, v3f), 14.0f), "Dot function failed.");
        TEST_ASSERT(almost_equal(dot(Vector2f{0.0f, 1.0f}, Vector2f{1.0f, 0.0f}), 0.0f), "Dot function failed.");
    }

    void cross_function()
    {
        TEST_ASSERT(cross(Vector3f(3.0f, 2.0f, 1.0f), v3f) == Vector3f(4, -8, 4), "Cross function failed.");
        TEST_ASSERT(cross(Vector2f(3.0f, 2.0f), Vector2f(1.0f, 4.0f)) == 10.f, "Cross function failed.");
    }

    void normalize_function()
    {
        TEST_ASSERT(almost_equal(length(normalize(v3f)), 1.0f, 1), "Normalize function failed.");
    }

    void faceforward_function()
    {
        TEST_ASSERT(faceforward(v3f, v3f, Vector3f(1.0f, 2.0f, -3.0f)) == v3f, "Faceforward function failed.");
        TEST_ASSERT(faceforward(v3f, v3f, v3f) == -v3f, "Faceforward function failed.");
    }

    void reflection_function()
    {
        TEST_ASSERT(almost_equal(reflect(v3f, normalize(v3f)), -v3f, 5), "Reflection function failed.");
    }

    void refraction_function()
    {
        const Vector3f result = refract(v3f, normalize(v3f), 1.0f);

        TEST_ASSERT(almost_equal(result, reflect(v3f, normalize(v3f))), "Refraction function failed.");
        TEST_ASSERT(almost_equal(refract(Vector2f{0.0f, 1.0f}, Vector2f{1.0f, 0.0f}, 2.0f), Vector2f{0.0f}),
                    "Refraction function failed.");
    }

    void on_line_function()
    {
        const Vector2f l_start{-1, -1};
        const Vector2f l_end{1, 1};

        const Vector2f p1{1, 1};       // 1
        const Vector2f p2{-1, -1};     // 1
        const Vector2f p3{0, 0};       // 1
        const Vector2f p4{1, 0};       // 0
        const Vector2f p5{0.5f, 0.5f}; // 1

        TEST_ASSERT(on_line(p1, l_start, l_end) == true, "Wrong point on line calculation.");
        TEST_ASSERT(on_line(p2, l_start, l_end) == true, "Wrong point on line calculation.");
        TEST_ASSERT(on_line(p3, l_start, l_end) == true, "Wrong point on line calculation.");
        TEST_ASSERT(on_line(p4, l_start, l_end) == false, "Wrong point on line calculation.");
        TEST_ASSERT(on_line(p5, l_start, l_end) == true, "Wrong point on line calculation.");
    }

    void on_segment_function()
    {
        const Vector2f s_start{-1, -1};
        const Vector2f s_end{1, 1};

        const Vector2f p1{1, 1};       // 1
        const Vector2f p2{-1, -1};     // 1
        const Vector2f p3{0, 0};       // 1
        const Vector2f p4{1, 0};       // 0
        const Vector2f p5{0.5f, 0.5f}; // 1

        TEST_ASSERT(on_segment(p1, s_start, s_end) == true, "Wrong point on segment calculation.");
        TEST_ASSERT(on_segment(p2, s_start, s_end) == true, "Wrong point on segment calculation.");
        TEST_ASSERT(on_segment(p3, s_start, s_end) == true, "Wrong point on segment calculation.");
        TEST_ASSERT(on_segment(p4, s_start, s_end) == false, "Wrong point on segment calculation.");
        TEST_ASSERT(on_segment(p5, s_start, s_end) == true, "Wrong point on segment calculation.");
    }

    void is_line_intersects_segment_function()
    {
        const Vector2f s1_start{-1, -1};
        const Vector2f s1_end{1, 1};

        // intersets
        const Vector2f l1_start{0, 0};
        const Vector2f l1_end{1, 0};

        const bool l1_intersets_1 = is_line_intersects_segment(l1_start, l1_end, s1_start, s1_end);
        const bool l1_intersets_2 = is_line_intersects_segment(l1_start, l1_end, s1_end, s1_start);
        const bool l1_intersets_3 = is_line_intersects_segment(l1_end, l1_start, s1_start, s1_end);
        const bool l1_intersets_4 = is_line_intersects_segment(l1_end, l1_start, s1_end, s1_start);

        const bool l1_the_same = l1_intersets_1 == l1_intersets_2 && l1_intersets_2 == l1_intersets_3 &&
                                 l1_intersets_3 == l1_intersets_4;

        TEST_ASSERT(l1_the_same && l1_intersets_1 == true, "Wrong line - segment intersection calculation.");

        // segment edge, intersection
        const Vector2f l2_start{1, 0};
        const Vector2f l2_end{-3, -2};

        const bool l2_intersets_1 = is_line_intersects_segment(l2_start, l2_end, s1_start, s1_end);
        const bool l2_intersets_2 = is_line_intersects_segment(l2_start, l2_end, s1_end, s1_start);
        const bool l2_intersets_3 = is_line_intersects_segment(l2_end, l2_start, s1_start, s1_end);
        const bool l2_intersets_4 = is_line_intersects_segment(l2_end, l2_start, s1_end, s1_start);

        const bool l2_the_same = l2_intersets_1 == l2_intersets_2 && l2_intersets_2 == l2_intersets_3 &&
                                 l2_intersets_3 == l2_intersets_4;

        TEST_ASSERT(l2_the_same && l2_intersets_1 == true, "Wrong line - segment intersection calculation.");

        // segment edge, intersection
        const Vector2f l3_start{1, 0};
        const Vector2f l3_end{1, 2};

        const bool l3_intersets_1 = is_line_intersects_segment(l3_start, l3_end, s1_start, s1_end);
        const bool l3_intersets_2 = is_line_intersects_segment(l3_start, l3_end, s1_end, s1_start);
        const bool l3_intersets_3 = is_line_intersects_segment(l3_end, l3_start, s1_start, s1_end);
        const bool l3_intersets_4 = is_line_intersects_segment(l3_end, l3_start, s1_end, s1_start);

        const bool l3_the_same = l3_intersets_1 == l3_intersets_2 && l3_intersets_2 == l3_intersets_3 &&
                                 l3_intersets_3 == l3_intersets_4;

        TEST_ASSERT(l3_the_same && l3_intersets_1 == true, "Wrong line - segment intersection calculation.");

        // no intersection
        const Vector2f l4_start{1, 0.5};
        const Vector2f l4_end{-0.5, -1};

        const bool l4_intersets_1 = is_line_intersects_segment(l4_start, l4_end, s1_start, s1_end);
        const bool l4_intersets_2 = is_line_intersects_segment(l4_start, l4_end, s1_end, s1_start);
        const bool l4_intersets_3 = is_line_intersects_segment(l4_end, l4_start, s1_start, s1_end);
        const bool l4_intersets_4 = is_line_intersects_segment(l4_end, l4_start, s1_end, s1_start);

        const bool l4_the_same = l4_intersets_1 == l4_intersets_2 && l4_intersets_2 == l4_intersets_3 &&
                                 l4_intersets_3 == l4_intersets_4;

        TEST_ASSERT(l4_the_same && l4_intersets_1 == false, "Wrong line - segment intersection calculation.");
    }

    void triangle_function()
    {
        const Vector2f p1{0, 0};          // 1
        const Vector2f p2{-0.5f, 0.5f};   // 0
        const Vector2f p3{0, 2};          // 0
        const Vector2f p4{0, -1};         // 1
        const Vector2f p5{0.5, 0};        // 1
        const Vector2f p6{-0.5, -0.99};   // 1
        const Vector2f p7{-0.5, -1.0001}; // 0
        const Vector2f p8{0.5, -1};       // 1
        const Vector2f p9{1.0001, -1};    // 0

        const Vector2f v1{-1, -1};
        const Vector2f v2{1, -1};
        const Vector2f v3{0, 1};

        const bool r1 = is_point_in_triangle(p1, v1, v2, v3);
        const bool r2 = is_point_in_triangle(p2, v1, v2, v3);
        const bool r3 = is_point_in_triangle(p3, v1, v2, v3);
        const bool r4 = is_point_in_triangle(p4, v1, v2, v3);
        const bool r5 = is_point_in_triangle(p5, v1, v2, v3);
        const bool r6 = is_point_in_triangle(p6, v1, v2, v3);
        const bool r7 = is_point_in_triangle(p7, v1, v2, v3);
        const bool r8 = is_point_in_triangle(p8, v1, v2, v3);
        const bool r9 = is_point_in_triangle(p9, v1, v2, v3);

        const bool r11 = is_point_in_triangle(p1, v1, v3, v2);
        const bool r12 = is_point_in_triangle(p2, v1, v3, v2);
        const bool r13 = is_point_in_triangle(p3, v1, v3, v2);
        const bool r14 = is_point_in_triangle(p4, v1, v3, v2);
        const bool r15 = is_point_in_triangle(p5, v1, v3, v2);
        const bool r16 = is_point_in_triangle(p6, v1, v3, v2);
        const bool r17 = is_point_in_triangle(p7, v1, v3, v2);
        const bool r18 = is_point_in_triangle(p8, v1, v3, v2);
        const bool r19 = is_point_in_triangle(p9, v1, v3, v2);

        const bool rv1 = is_point_in_triangle(v1, v1, v2, v3);
        const bool rv2 = is_point_in_triangle(v2, v1, v2, v3);
        const bool rv3 = is_point_in_triangle(v3, v1, v2, v3);
        const bool rv4 = is_point_in_triangle(v1, v1, v3, v2);
        const bool rv5 = is_point_in_triangle(v2, v1, v3, v2);
        const bool rv6 = is_point_in_triangle(v3, v1, v3, v2);

        TEST_ASSERT(r1 == r11 && r1 == true, "Invalid point calculation.");
        TEST_ASSERT(r2 == r12 && r2 == false, "Invalid point calculation.");
        TEST_ASSERT(r3 == r13 && r3 == false, "Invalid point calculation.");
        TEST_ASSERT(r4 == r14 && r4 == true, "Invalid point calculation.");
        TEST_ASSERT(r5 == r15 && r5 == true, "Invalid point calculation.");
        TEST_ASSERT(r6 == r16 && r6 == true, "Invalid point calculation.");
        TEST_ASSERT(r7 == r17 && r7 == false, "Invalid point calculation.");
        TEST_ASSERT(r8 == r18 && r8 == true, "Invalid point calculation.");
        TEST_ASSERT(r9 == r19 && r9 == false, "Invalid point calculation.");

        TEST_ASSERT(rv1 + rv2 + rv3 + rv4 + rv5 + rv6 == 6, "All vertices must be inside triangle.");
    }

    Vector3f v3f;
};

int main()
{
    return run_tests(GeometricFunctionsTest());
}
