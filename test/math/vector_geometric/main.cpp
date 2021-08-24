
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

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
        add_test([this]() { length_function(); }, "length_function");
        add_test([this]() { distance_function(); }, "distance_function");
        add_test([this]() { dot_function(); }, "dot_function");
        add_test([this]() { cross_function(); }, "cross_function");
        add_test([this]() { normalize_function(); }, "normalize_function");
        add_test([this]() { faceforward_function(); }, "faceforward_function");
        add_test([this]() { reflection_function(); }, "reflection_function");
        add_test([this]() { refraction_function(); }, "refraction_function");

        v3f = {1.0f, 2.0f, 3.0f};
    }

private:
    void length_function()
    {
        TEST_ASSERT(almost_equal(length(v3f), 3.7416574954986572f), "Length function failed.");
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

    Vector3f v3f;
};

int main()
{
    return run_tests(GeometricFunctionsTest());
}
