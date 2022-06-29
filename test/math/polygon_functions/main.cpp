#include <algorithm>
#include <iterator>

#include <math/math.hpp>
#include <unit_test/suite.hpp>

using framework::math::Polygon;
using framework::math::Vector2f;

class PolygonFunctionsTest : public framework::unit_test::Suite
{
public:
    PolygonFunctionsTest()
        : Suite("PolygonFunctionsTest")
    {
        add_test([this]() { polygon_area_function(); }, "polygon_area_function");
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
};

int main()
{
    return run_tests(PolygonFunctionsTest());
}
