#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{
    // vector default constructors
    {
        constexpr Vector4D v4d;
        constexpr Vector3F v3f;
        constexpr Vector2I v2i;

        constexpr Vector2B v2b;
        constexpr Vector3B v3b;
        constexpr Vector4B v4b;

        static_assert(sizeof(v4d) == sizeof(double) * 4 && v4d.size() == 4, "size check");
        static_assert(sizeof(v3f) == sizeof(float) * 3 && v3f.size() == 3, "size check");
        static_assert(sizeof(v2i) == sizeof(int) * 2 && v2i.size() == 2, "size check");

        static_assert(sizeof(v2b) == sizeof(bool) * 2 && v2b.size() == 2, "size check");
        static_assert(sizeof(v3b) == sizeof(bool) * 3 && v3b.size() == 3, "size check");
        static_assert(sizeof(v4b) == sizeof(bool) * 4 && v4b.size() == 4, "size check");

        static_assert(v4d == Vector4D(0, 0, 0, 1), "default constructor");
        static_assert(v3f == Vector3F(0, 0, 0), "default constructor");
        static_assert(v2i == Vector2I(0, 0), "default constructor");

        static_assert(v2b == Vector2B(false, false), "default constructor");
        static_assert(v3b == Vector3B(false, false, false), "default constructor");
        static_assert(v4b == Vector4B(false, false, false, false), "default constructor");
    }

    // vector one arg constuctor
    {
        constexpr Vector4D v4d = Vector4D(1.4);
        constexpr Vector3F v3f = Vector3F(2.4f);
        constexpr Vector2I v2i = Vector2I(3);

        static_assert(v4d == Vector4D(1.4, 1.4, 1.4, 1.4), "one arg constructor");
        static_assert(v3f == Vector3F(2.4, 2.4, 2.4), "one arg constructor");
        static_assert(v2i == Vector2I(3, 3), "one arg constructor");
    }

    // vector bool one arg constructor
    {
        constexpr Vector2B v2b = Vector2B(false);
        constexpr Vector3B v3b = Vector3B(true);
        constexpr Vector4B v4b = Vector4B(false);

        static_assert(v4b == Vector4B(false, false, false, false), "one arg constructor");
        static_assert(v3b == Vector3B(true, true, true), "one arg constructor");
        static_assert(v2b == Vector2B(false, false), "one arg constructor");
    }

    // vector non-def & copy constructor
    {
        constexpr Vector4D v4d = {1.1, 2.2, 3.3, 4};
        constexpr Vector3F v3f = {5.5f, 6.6f, 7.7f};
        constexpr Vector2I v2i = {1, 2};
        constexpr Vector4B v4b = Vector4B(false, true, false, true);

        constexpr Vector4D v4d2 = v4d;
        constexpr Vector3F v3f2 = v3f;
        constexpr Vector2I v2i2 = v2i;
        constexpr Vector4B v4b2 = v4b;

        constexpr Vector4I v4i = Vector4I(v4d);
        constexpr Vector3D v3d = Vector3D(v3f);
        constexpr Vector2F v2f = Vector2F(v2i);

        static_assert(v4i == Vector4I(1, 2, 3, 4) && v4d == v4d2 && v4d == Vector4D(1.1, 2.2, 3.3, 4), "non-def & copy "
                                                                                                 "constructor");
        static_assert(v3d == Vector3D(5.5f, 6.6f, 7.7f) && v3f == v3f2 && v3f == Vector3F(5.5, 6.6, 7.7), "non-def & copy "
                                                                                                    "constructor");
        static_assert(v2f == Vector2F(1, 2) && v2i == v2i2 && v2i == Vector2I(1, 2), "non-def & copy constructor");
        static_assert(v4b == Vector4B(false, true, false, true) && v4b == v4b2, "non-def & copy constructor");
    }

    // vector type pointer constructor
    {
        double data_d[4] = {1.0, 2.0, 3.0, 4.0};
        float data_f[4]  = {1.0f, 2.0f, 3.0f, 4.0f};

        Vector4D v4d(data_d);
        Vector4F v4f(data_f);
        Vector2I v2i(0);
        Vector2U v2u(0);

        double* p = v4d.data();

        assert_msg(v4d == Vector4D(1.0, 2.0, 3.0, 4.0), "Vector4D pointer constructor");
        assert_msg(v4f == Vector4F(1.0f, 2.0f, 3.0f, 4.0f), "Vector4F pointer constructor");
        assert_msg(v2i == Vector2I(0, 0), "Vector2I zero constructor");
        assert_msg(v2u == Vector2U(0, 0), "Vector2U zero constructor");

        assert_msg(p[0] == 1.0 && p[1] == 2.0 && p[2] == 3.0 && p[3] == 4.0, "pointer data access");
        // TODO: add vector bool pointer access
    }

    // vector to vector bool cast
    {
        constexpr Vector2B v2b = Vector2B(Vector2F(0.4f, -1.6f));
        constexpr Vector3B v3b = Vector3B(Vector3D(0, -1.1, 0.1));
        constexpr Vector4B v4b = Vector4B(Vector4I(0, -1, 0, 1));

        static_assert(v4b == Vector4B(false, true, false, true), "bool cast assert");
        static_assert(v3b == Vector3B(false, true, true), "bool cast assert");
        static_assert(v2b == Vector2B(true, true), "bool cast assert");

        constexpr Vector4D v4d = Vector4D(v4b);
        constexpr Vector3F v3f = Vector3F(v3b);
        constexpr Vector2I v2i = Vector2I(v2b);

        static_assert(v4d == Vector4D(0.0, 1.0, 0.0, 1.0), "bool cast assert");
        static_assert(v3f == Vector3F(0.0f, 1.0f, 1.0f), "bool cast assert");
        static_assert(v2i == Vector2I(1, 1), "bool cast assert");
    }

    // vector different size constructor"
    {
        constexpr Vector4D v4d = {1.1, 2.2, 3.3, 4};
        constexpr Vector3F v3f = {5.5f, 6.6f, 7.7f};
        constexpr Vector2I v2i = {1, 2};

        constexpr Vector3D v3d = Vector3D(v4d);
        constexpr Vector2D v2d = Vector2D(v3d);

        constexpr Vector4F v4f = Vector4F(v3f);
        constexpr Vector2F v2f = Vector2F(v4f);

        constexpr Vector3I v3i = Vector3I(v2i);
        constexpr Vector4I v4i = Vector4I(v2i);

        assert_msg(almost_equal(v4d.x, v3d.x) && almost_equal(v3d.x, v2d.x) && almost_equal(v2d.x, 1.1) &&
                   almost_equal(v4d.y, v3d.y) && almost_equal(v3d.y, v2d.y) && almost_equal(v2d.y, 2.2) &&
                   almost_equal(v4d.z, v3d.z) && almost_equal(v3d.z, 3.3),
                   "different size constructor");

        assert_msg(almost_equal(v4f.x, v3f.x) && almost_equal(v4f.x, v2f.x) && almost_equal(v2f.x, 5.5f) &&
                   almost_equal(v4f.y, v3f.y) && almost_equal(v4f.y, v2f.y) && almost_equal(v2f.y, 6.6f) &&
                   almost_equal(v4f.z, v3f.z) && almost_equal(v4f.z, 7.7f) && almost_equal(v4f.w, 1.0f),
                   "different size constructor");

        assert_msg((v4i.x == v3i.x) && (v3i.x == v2i.x) && (v3i.x == 1) && (v4i.y == v3i.y) && (v3i.y == v2i.y) && (v3i.y == 2) &&
                   (v4i.z == v3i.z) && (v3i.z == 0) && (v4i.w == 1),
                   "different size constructor");
    }

    // vector different size constructor with addition scalar
    {
        constexpr Vector3F v3f = {5.5f, 6.6f, 7.7f};
        constexpr Vector2I v2i = {1, 2};

        constexpr Vector4D v4d1(v3f, 0.2);
        constexpr Vector4D v4d2(0.2, v3f);
        constexpr Vector4D v4d3(v2i, v2i);
        constexpr Vector4D v4d4(3, 0.2, v2i);
        constexpr Vector4D v4d5(3, v2i, 0.2);
        constexpr Vector4D v4d6(v2i, 3, 0.2);

        constexpr Vector3F v3f1(v2i, 3);
        constexpr Vector3F v3f2(3, v2i);

        static_assert(v4d1 == Vector4D(5.5f, 6.6f, 7.7f, 0.2) && v4d2 == Vector4D(0.2, 5.5f, 6.6f, 7.7f) && v4d3 == Vector4D(1, 2, 1, 2) && v4d4 == Vector4D(3, 0.2, 1, 2) && v4d5 == Vector4D(3, 1, 2, 0.2) && v4d6 == Vector4D(1, 2, 3, 0.2), "different size constructor with addition scalar");

        static_assert(v3f1 == Vector3F(1, 2, 3) && v3f2 == Vector3F(3, 1, 2), "different size constructor with addition "
                                                                        "scalar");
    }

    return 0;
}
