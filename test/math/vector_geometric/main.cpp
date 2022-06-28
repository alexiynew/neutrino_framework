#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::math::Vector2f;
using framework::math::Vector3f;

using framework::math::almost_equal;

class GeometricFunctionsTest : public framework::unit_test::Suite
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

    void triangle_function()
    {
        const Vector2f p1{0, 0};          // 1
        const Vector2f p2{-0.5f, 0.5f};   // 0
        const Vector2f p3{0, 2};          // 0
        const Vector2f p4{0, -1};         // 0
        const Vector2f p5{0.5, 0};        // 0
        const Vector2f p6{-0.5, -0.99};   // 1
        const Vector2f p7{-0.5, -1.0001}; // 0

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

        const bool r11 = is_point_in_triangle(p1, v1, v3, v2);
        const bool r12 = is_point_in_triangle(p2, v1, v3, v2);
        const bool r13 = is_point_in_triangle(p3, v1, v3, v2);
        const bool r14 = is_point_in_triangle(p4, v1, v3, v2);
        const bool r15 = is_point_in_triangle(p5, v1, v3, v2);
        const bool r16 = is_point_in_triangle(p6, v1, v3, v2);
        const bool r17 = is_point_in_triangle(p7, v1, v3, v2);

        TEST_ASSERT(r1 == r11 && r1 == true, "Invalid point calculation.");
        TEST_ASSERT(r2 == r12 && r2 == false, "Invalid point calculation.");
        TEST_ASSERT(r3 == r13 && r3 == false, "Invalid point calculation.");
        TEST_ASSERT(r4 == r14 && r4 == false, "Invalid point calculation.");
        TEST_ASSERT(r5 == r15 && r5 == false, "Invalid point calculation.");
        TEST_ASSERT(r6 == r16 && r6 == true, "Invalid point calculation.");
        TEST_ASSERT(r7 == r17 && r7 == false, "Invalid point calculation.");
    }

    Vector3f v3f;
};

int main()
{
    return run_tests(GeometricFunctionsTest());
}
