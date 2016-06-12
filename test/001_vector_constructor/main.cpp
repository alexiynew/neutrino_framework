#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{
    // vector default constructors
    {
        constexpr vec4d v4d;
        constexpr vec3f v3f;
        constexpr vec2i v2i;

        constexpr vec2b v2b;
        constexpr vec3b v3b;
        constexpr vec4b v4b;

        static_assert(sizeof(v4d) == sizeof(double) * 4 && v4d.size() == 4, "size check");
        static_assert(sizeof(v3f) == sizeof(float) * 3 && v3f.size() == 3, "size check");
        static_assert(sizeof(v2i) == sizeof(int) * 2 && v2i.size() == 2, "size check");

        static_assert(sizeof(v2b) == sizeof(bool) * 2 && v2b.size() == 2, "size check");
        static_assert(sizeof(v3b) == sizeof(bool) * 3 && v3b.size() == 3, "size check");
        static_assert(sizeof(v4b) == sizeof(bool) * 4 && v4b.size() == 4, "size check");

        static_assert(v4d == vec4d(0, 0, 0, 1), "default constructor");
        static_assert(v3f == vec3f(0, 0, 0), "default constructor");
        static_assert(v2i == vec2i(0, 0), "default constructor");

        static_assert(v2b == vec2b(false, false), "default constructor");
        static_assert(v3b == vec3b(false, false, false), "default constructor");
        static_assert(v4b == vec4b(false, false, false, false), "default constructor");
    }

    // vector one arg constuctor
    {
        constexpr vec4d v4d = vec4d(1.4);
        constexpr vec3f v3f = vec3f(2.4f);
        constexpr vec2i v2i = vec2i(3);

        static_assert(v4d == vec4d(1.4, 1.4, 1.4, 1.4), "one arg constructor");
        static_assert(v3f == vec3f(2.4, 2.4, 2.4), "one arg constructor");
        static_assert(v2i == vec2i(3, 3), "one arg constructor");
    }

    // vector bool one arg constructor
    {
        constexpr vec2b v2b = vec2b(false);
        constexpr vec3b v3b = vec3b(true);
        constexpr vec4b v4b = vec4b(false);

        static_assert(v4b == vec4b(false, false, false, false), "one arg constructor");
        static_assert(v3b == vec3b(true, true, true), "one arg constructor");
        static_assert(v2b == vec2b(false, false), "one arg constructor");
    }

    // vector non-def & copy constructor
    {
        constexpr vec4d v4d = {1.1, 2.2, 3.3, 4};
        constexpr vec3f v3f = {5.5f, 6.6f, 7.7f};
        constexpr vec2i v2i = {1, 2};
        constexpr vec4b v4b = vec4b(false, true, false, true);

        constexpr vec4d v4d2 = v4d;
        constexpr vec3f v3f2 = v3f;
        constexpr vec2i v2i2 = v2i;
        constexpr vec4b v4b2 = v4b;

        constexpr vec4i v4i = vec4i(v4d);
        constexpr vec3d v3d = vec3d(v3f);
        constexpr vec2f v2f = vec2f(v2i);

        static_assert(v4i == vec4i(1, 2, 3, 4) && v4d == v4d2 && v4d == vec4d(1.1, 2.2, 3.3, 4), "non-def & copy "
                                                                                                 "constructor");
        static_assert(v3d == vec3d(5.5f, 6.6f, 7.7f) && v3f == v3f2 && v3f == vec3f(5.5, 6.6, 7.7), "non-def & copy "
                                                                                                    "constructor");
        static_assert(v2f == vec2f(1, 2) && v2i == v2i2 && v2i == vec2i(1, 2), "non-def & copy constructor");
        static_assert(v4b == vec4b(false, true, false, true) && v4b == v4b2, "non-def & copy constructor");
    }

    // vector type pointer constructor
    {
        double data_d[4] = {1.0, 2.0, 3.0, 4.0};
        float data_f[4]  = {1.0f, 2.0f, 3.0f, 4.0f};

        vec4d v4d(data_d);
        vec4f v4f(data_f);
        vec2i v2i(0);
        vec2u v2u(0);

        double* p = v4d.data();

        assert_msg(v4d == vec4d(1.0, 2.0, 3.0, 4.0), "vec4d pointer constructor");
        assert_msg(v4f == vec4f(1.0f, 2.0f, 3.0f, 4.0f), "vec4f pointer constructor");
        assert_msg(v2i == vec2i(0, 0), "vec2i zero constructor");
        assert_msg(v2u == vec2u(0, 0), "vec2u zero constructor");

        assert_msg(p[0] == 1.0 && p[1] == 2.0 && p[2] == 3.0 && p[3] == 4.0, "pointer data access");
// TODO: add vector bool pointer access
    }

    // vector to vector bool cast
    {
        constexpr vec2b v2b = vec2b(vec2f(0.4f, -1.6f));
        constexpr vec3b v3b = vec3b(vec3d(0, -1.1, 0.1));
        constexpr vec4b v4b = vec4b(vec4i(0, -1, 0, 1));

        static_assert(v4b == vec4b(false, true, false, true), "bool cast assert");
        static_assert(v3b == vec3b(false, true, true), "bool cast assert");
        static_assert(v2b == vec2b(true, true), "bool cast assert");

        constexpr vec4d v4d = vec4d(v4b);
        constexpr vec3f v3f = vec3f(v3b);
        constexpr vec2i v2i = vec2i(v2b);

        static_assert(v4d == vec4d(0.0, 1.0, 0.0, 1.0), "bool cast assert");
        static_assert(v3f == vec3f(0.0f, 1.0f, 1.0f), "bool cast assert");
        static_assert(v2i == vec2i(1, 1), "bool cast assert");
    }

    // vector different size constructor"
    {
        constexpr vec4d v4d = {1.1, 2.2, 3.3, 4};
        constexpr vec3f v3f = {5.5f, 6.6f, 7.7f};
        constexpr vec2i v2i = {1, 2};

        constexpr vec3d v3d = vec3d(v4d);
        constexpr vec2d v2d = vec2d(v3d);

        constexpr vec4f v4f = vec4f(v3f);
        constexpr vec2f v2f = vec2f(v4f);

        constexpr vec3i v3i = vec3i(v2i);
        constexpr vec4i v4i = vec4i(v2i);

        assert_msg(almost_equal(v4d.x, v3d.x) && almost_equal(v3d.x, v2d.x) && almost_equal(v2d.x, 1.1) && almost_equal(v4d.y, v3d.y) && almost_equal(v3d.y, v2d.y) && almost_equal(v2d.y, 2.2) && almost_equal(v4d.z, v3d.z) && almost_equal(v3d.z, 3.3), "different size constructor");

        assert_msg(almost_equal(v4f.x, v3f.x) && almost_equal(v4f.x, v2f.x) && almost_equal(v2f.x, 5.5f) && almost_equal(v4f.y, v3f.y) && almost_equal(v4f.y, v2f.y) && almost_equal(v2f.y, 6.6f) && almost_equal(v4f.z, v3f.z) && almost_equal(v4f.z, 7.7f) && almost_equal(v4f.w, 1.0f), "different size constructor");

        assert_msg((v4i.x == v3i.x) && (v3i.x == v2i.x) && (v3i.x == 1) && (v4i.y == v3i.y) && (v3i.y == v2i.y) && (v3i.y == 2) && (v4i.z == v3i.z) && (v3i.z == 0) && (v4i.w == 1), "different size constructor");
    }

    // vector different size constructor with addition scalar
    {
        constexpr vec3f v3f = {5.5f, 6.6f, 7.7f};
        constexpr vec2i v2i = {1, 2};

        constexpr vec4d v4d1(v3f, 0.2);
        constexpr vec4d v4d2(0.2, v3f);
        constexpr vec4d v4d3(v2i, v2i);
        constexpr vec4d v4d4(3, 0.2, v2i);
        constexpr vec4d v4d5(3, v2i, 0.2);
        constexpr vec4d v4d6(v2i, 3, 0.2);

        constexpr vec3f v3f1(v2i, 3);
        constexpr vec3f v3f2(3, v2i);

        static_assert(v4d1 == vec4d(5.5f, 6.6f, 7.7f, 0.2) && v4d2 == vec4d(0.2, 5.5f, 6.6f, 7.7f) && v4d3 == vec4d(1, 2, 1, 2) && v4d4 == vec4d(3, 0.2, 1, 2) && v4d5 == vec4d(3, 1, 2, 0.2) && v4d6 == vec4d(1, 2, 3, 0.2), "different size constructor with addition scalar");

        static_assert(v3f1 == vec3f(1, 2, 3) && v3f2 == vec3f(3, 1, 2), "different size constructor with addition "
                                                                        "scalar");
    }

    return 0;
}
