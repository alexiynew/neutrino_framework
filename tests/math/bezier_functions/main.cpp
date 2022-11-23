#include <math/math.hpp>
#include <unit_test/suite.hpp>

class BezierFunctionsTest : public neutrino::unit_test::Suite
{
public:
    BezierFunctionsTest()
        : Suite("BezierFunctionsTest")
    {
        add_test([this]() { quadratic_bezier_function(); }, "quadratic_bezier_function");
        add_test([this]() { cubic_bezier_function(); }, "cubic_bezier_function");
    }

private:
    void quadratic_bezier_function()
    {
        using neutrino::math::mix;
        using neutrino::math::quadratic_bezier;
        using neutrino::math::Vector2f;

        Vector2f p1{0.0f, 0.0f};
        Vector2f p2{0.0f, 0.8f};
        Vector2f p3{0.8f, 0.8f};

        auto t1 = mix(p1, p2, 0.5f);
        auto t2 = mix(p2, p3, 0.5f);
        auto t3 = mix(t1, t2, 0.5f);

        TEST_ASSERT(quadratic_bezier(p1, p2, p3, 0.0f) == p1, "Quadratic bezier function error.");
        TEST_ASSERT(quadratic_bezier(p1, p2, p3, 1.0f) == p3, "Quadratic bezier function error.");
        TEST_ASSERT(quadratic_bezier(p1, p2, p3, 0.5f) == t3, "Quadratic bezier function error.");
    }

    void cubic_bezier_function()
    {
        using neutrino::math::almost_equal;
        using neutrino::math::cubic_bezier;
        using neutrino::math::quadratic_bezier;
        using neutrino::math::Vector2f;

        Vector2f p1{0.0f, 0.0f};
        Vector2f p2{0.0f, 0.8f};
        Vector2f p3{0.8f, 0.8f};
        Vector2f p4{0.8f, 0.0f};

        auto t1 = quadratic_bezier(p1, p2, p3, 0.5f);
        auto t2 = quadratic_bezier(p2, p3, p4, 0.5f);
        auto t3 = mix(t1, t2, 0.5f);

        TEST_ASSERT(cubic_bezier(p1, p2, p3, p4, 0.0f) == p1, "Cubic bezier function error.");
        TEST_ASSERT(cubic_bezier(p1, p2, p3, p4, 1.0f) == p4, "Cubic bezier function error.");
        TEST_ASSERT(almost_equal(cubic_bezier(p1, p2, p3, p4, 0.5f), t3, 2), "Cubic bezier function error.");
    }
};

int main()
{
    return run_tests(BezierFunctionsTest());
}
