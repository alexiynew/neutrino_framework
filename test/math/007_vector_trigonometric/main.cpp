#include <math/math.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;

class trigonometric_function_tests : public framework::unit_test::suite
{
public:
    trigonometric_function_tests()
        : suite("trigonometric_function_tests")
    {
        add_test([this]() { radians_function(); }, "radians_function");
        add_test([this]() { degrees_function(); }, "degrees_function");
        add_test([this]() { sin_function(); }, "sin_function");
        add_test([this]() { cos_function(); }, "cos_function");
        add_test([this]() { tan_function(); }, "tan_function");
        add_test([this]() { asin_function(); }, "asin_function");
        add_test([this]() { acos_function(); }, "acos_function");
        add_test([this]() { atan_function(); }, "atan_function");
        add_test([this]() { sinh_function(); }, "sinh_function");
        add_test([this]() { cosh_function(); }, "cosh_function");
        add_test([this]() { tanh_function(); }, "tanh_function");
        add_test([this]() { asinh_function(); }, "asinh_function");
        add_test([this]() { acosh_function(); }, "acosh_function");
        add_test([this]() { atanh_function(); }, "atanh_function");

        v4d = {180.0, 360.0, 90.0, 45.0};
        v3d = {45.0, 60.0, 180.0};
    }

private:
    void radians_function()
    {
        TEST_ASSERT(radians(v4d) == vector4D(PI, TAU, PI / 2, PI / 4), "Radians function failed.");
    }

    void degrees_function()
    {
        TEST_ASSERT(degrees(radians(v4d)) == v4d, "Degrees function failed.");
    }

    void sin_function()
    {
        const vector4D sin_vector(sin(PI), sin(TAU), sin(PI / 2), sin(PI / 4));
        TEST_ASSERT(almost_equal(sin(radians(v4d)), sin_vector), "Sin function failed.");
    }

    void cos_function()
    {
        const vector4D cos_vector(cos(PI), cos(TAU), cos(PI / 2), cos(PI / 4));
        TEST_ASSERT(almost_equal(cos(radians(v4d)), cos_vector), "Cos function failed.");
    }

    void tan_function()
    {
        TEST_ASSERT(almost_equal(tan(radians(v3d)), sin(radians(v3d)) / cos(radians(v3d))), "Tan function failed.");
    }

    void asin_function()
    {
        const vector4D asin_vector(asin(sin(PI)), asin(sin(TAU)), PI / 2, PI / 4);
        TEST_ASSERT(almost_equal(asin(sin(radians(v4d))), asin_vector, 1), "Asin function failed.");
    }

    void acos_function()
    {
        TEST_ASSERT(almost_equal(acos(cos(radians(v4d))), vector4D(PI, 0, PI / 2, PI / 4)), "Acos function failed.");
    }

    void atan_function()
    {
        const vector3D result1 = atan(tan(radians(v3d)));
        const vector3D result2 = atan(sin(radians(v3d)), cos(radians(v3d)));

        TEST_ASSERT(almost_equal(result1, vector3D(QUARTER_PI, PI / 3, atan(tan(PI)))), "Atan from tan failed.");
        TEST_ASSERT(almost_equal(result2, vector3D(QUARTER_PI, PI / 3, PI), 1), "Atan from sin and cos failed.");
    }

    void sinh_function()
    {
        const vector3D sinh_vector(0.86867096148600953, 1.2493670505239751, 11.548739357257748);

        TEST_ASSERT(almost_equal(sinh(radians(v3d)), sinh_vector, 2), "Sinh function failed.");
    }

    void cosh_function()
    {
        const vector3D cosh_vector(1.3246090892520057, 1.6002868577023861, 11.591953275521519);
        TEST_ASSERT(almost_equal(cosh(radians(v3d)), cosh_vector), "Cosh function failed.");
    }

    void tanh_function()
    {
        const vector3D tanh_vector = sinh(radians(v3d)) / cosh(radians(v3d));
        TEST_ASSERT(almost_equal(tanh(radians(v3d)), tanh_vector, 1), "Tanh function failed.");
    }

    void asinh_function()
    {
        TEST_ASSERT(almost_equal(asinh(sinh(radians(v3d))), vector3D(PI / 4, PI / 3, PI), 1), "Asinh function failed.");
    }

    void acosh_function()
    {
        TEST_ASSERT(almost_equal(acosh(cosh(radians(v3d))), vector3D(PI / 4, PI / 3, PI), 1), "Acosh function failed.");
    }

    void atanh_function()
    {
        TEST_ASSERT(almost_equal(atanh(tanh(radians(v3d))), vector3D(PI / 4, PI / 3, PI), 4), "Atanh function failed.");
    }

    vector4D v4d;
    vector3D v3d;
};


int main()
{
    return run_tests(trigonometric_function_tests());
}
