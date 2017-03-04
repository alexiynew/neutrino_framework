#include <math/math.hpp>
#include <unit_test/suite.hpp>

using namespace framework::math;

class vector_operators_test : public test::suite
{
public:
    vector_operators_test()
        : suite("vector_operators_test")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
        add_test([this]() { access_operator(); }, "access_operator");
        add_test([this]() { data_function(); }, "data_function");
        add_test([this]() { unary_minus_operator(); }, "unary_minus_operator");
        add_test([this]() { unary_plus_operator(); }, "unary_plus_operator");
        add_test([this]() { add_assign_operator(); }, "add_assign_operator");
        add_test([this]() { subtract_assign_operator(); }, "subtract_assign_operator");
        add_test([this]() { multiplies_assign_operator(); }, "multiplies_assign_operator");
        add_test([this]() { divides_assign_operator(); }, "divides_assign_operator");
        add_test([this]() { add_operator(); }, "add_operator");
        add_test([this]() { subtract_operator(); }, "subtract_operator");
        add_test([this]() { multiply_operator(); }, "multiply_operator");
        add_test([this]() { divide_operator(); }, "divide_operator");
        add_test([this]() { equality_operator(); }, "equality_operator");
        add_test([this]() { inequality_operator(); }, "inequality_operator");
    }

private:
    void assign_operator()
    {
        const Vector4D v4d(1.1, 2.2, 3.3, 4);
        const Vector3F v3f(5.5f, 6.6f, 7.7f);
        const Vector2I v2i(1, 2);

        Vector4D v4d_result;
        Vector3F v3f_result;
        Vector2I v2i_result;

        Vector4I v4i_result;
        Vector3D v3d_result;
        Vector2F v2f_result;

        v4d_result = v4d;
        v3f_result = v3f;
        v2i_result = v2i;

        v4i_result = v4d;
        v3d_result = v3f;
        v2f_result = v2i;

        TEST_ASSERT(v4i_result == Vector4I(1, 2, 3, 4), "Assign to vector4i failed.");
        TEST_ASSERT(v4d_result == Vector4D(1.1, 2.2, 3.3, 4), "Assign to vector4d failed.");

        TEST_ASSERT(v3d_result == Vector3D(double(5.5f), double(6.6f), double(7.7f)), "Assign to vector3d failed.");
        TEST_ASSERT(v3f_result == Vector3F(5.5f, 6.6f, 7.7f), "Assign to vector3f failed.");

        TEST_ASSERT(v2f_result == Vector2F(1, 2), "Assign to vector2f failed.");
        TEST_ASSERT(v2i_result == Vector2I(1, 2), "Assign to vector2i failed.");
    }

    void access_operator()
    {
        const Vector4D v4d(1.1, 2.2, 3.3, 4.4);
        const Vector3F v3f(5.5f, 6.6f, 7.7f);
        const Vector2I v2i(1, 2);

        // clang-format off
        TEST_ASSERT(almost_equal(v4d[0], 1.1) &&
                    almost_equal(v4d[1], 2.2) &&
                    almost_equal(v4d[2], 3.3) &&
                    almost_equal(v4d[3], 4.4),
                    "Access to vector4d filed.");

        TEST_ASSERT(almost_equal(v3f[0], 5.5f) &&
                    almost_equal(v3f[1], 6.6f) &&
                    almost_equal(v3f[2], 7.7f),
                    "Access to vector3f failed.");

        TEST_ASSERT(v2i[0] == 1 && v2i[1] == 2, "Access to vector2i failed.");
        // clang-format on
    }

    void data_function()
    {
        const Vector4D v4d(1.1, 2.2, 3.3, 4.4);
        const Vector3F v3f(5.5f, 6.6f, 7.7f);
        const Vector2I v2i(1, 2);

        const double* double_pointer = v4d.data();
        const float* float_pointer   = v3f.data();
        const int* int_pointer       = v2i.data();

        // clang-format off
        TEST_ASSERT(almost_equal(double_pointer[0], 1.1) &&
                    almost_equal(double_pointer[1], 2.2) &&
                    almost_equal(double_pointer[2], 3.3) &&
                    almost_equal(double_pointer[3], 4.4),
                    "Access to data of vector4d filed.");

        TEST_ASSERT(almost_equal(float_pointer[0], 5.5f) &&
                    almost_equal(float_pointer[1], 6.6f) &&
                    almost_equal(float_pointer[2], 7.7f),
                    "Access to data of vector3f failed.");

        TEST_ASSERT(int_pointer[0] == 1 && int_pointer[1] == 2, "Access to data of vector2i failed.");
        // clang-format on
    }

    void unary_minus_operator()
    {
        const Vector4D v4d(1.4);
        const Vector3F v3f(2.4f);
        const Vector2I v2i(3);

        TEST_ASSERT(-v4d == Vector4D(-1.4, -1.4, -1.4, -1.4), "Inverse of vector4d failed.");
        TEST_ASSERT(-v3f == Vector3F(-2.4f, -2.4f, -2.4f), "Inverse of vector3f failed.");
        TEST_ASSERT(-v2i == Vector2I(-3, -3), "Inverse of vector2i failed.");
    }

    void unary_plus_operator()
    {
        const Vector4D v4d(1.4);
        const Vector3F v3f(2.4f);
        const Vector2I v2i(3);

        TEST_ASSERT(+v4d == Vector4D(1.4, 1.4, 1.4, 1.4), "Unary add of vector4d failed.");
        TEST_ASSERT(+v3f == Vector3F(2.4f, 2.4f, 2.4f), "Unary add of vector3f failed.");
        TEST_ASSERT(+v2i == Vector2I(3, 3), "Unary add of vector2i failed.");
    }

    void add_assign_operator()
    {
        Vector4D v4d(1.0);
        Vector3F v3f(1.0f);
        Vector2I v2i(1);

        TEST_ASSERT((v4d += Vector4D(1.0)) == Vector4D(2.0), "Add_assign operator failed.");
        TEST_ASSERT((v4d += 1.0) == Vector4D(3.0), "Add_assign operator failed.");

        TEST_ASSERT((v3f += Vector3F(1.0f)) == Vector3F(2.0f), "Add_assign operator failed.");
        TEST_ASSERT((v3f += 1.0f) == Vector3F(3.0f), "Add_assign operator failed.");

        TEST_ASSERT((v2i += Vector2I(1)) == Vector2I(2), "Add_assign operator failed.");
        TEST_ASSERT((v2i += 1) == Vector2I(3), "Add_assign operator failed.");
    }

    void subtract_assign_operator()
    {
        Vector4D v4d(3.0);
        Vector3F v3f(3.0f);
        Vector2I v2i(3);

        TEST_ASSERT((v4d -= Vector4D(1.0)) == Vector4D(2.0), "Subtract_assign operator failed.");
        TEST_ASSERT((v4d -= 1.0) == Vector4D(1.0), "Subtract_assign operator failed.");

        TEST_ASSERT((v3f -= Vector3F(1.0f)) == Vector3F(2.0f), "Subtract_assign operator failed.");
        TEST_ASSERT((v3f -= 1.0f) == Vector3F(1.0f), "Subtract_assign operator failed.");

        TEST_ASSERT((v2i -= Vector2I(1)) == Vector2I(2), "Subtract_assign operator failed.");
        TEST_ASSERT((v2i -= 1) == Vector2I(1), "Subtract_assign operator failed.");
    }

    void multiplies_assign_operator()
    {
        Vector4D v4d(1.0);
        Vector3F v3f(1.0f);
        Vector2I v2i(1);

        TEST_ASSERT((v4d *= Vector4D(2.0)) == Vector4D(2.0), "Multiplies_assign operator failed.");
        TEST_ASSERT((v4d *= 2.0) == Vector4D(4.0), "Multiplies_assign operator failed.");

        TEST_ASSERT((v3f *= Vector3F(2.0f)) == Vector3F(2.0f), "Multiplies_assign operator failed.");
        TEST_ASSERT((v3f *= 2.0f) == Vector3F(4.0f), "Multiplies_assign operator failed.");

        TEST_ASSERT((v2i *= Vector2I(2)) == Vector2I(2), "Multiplies_assign operator failed.");
        TEST_ASSERT((v2i *= 2) == Vector2I(4), "Multiplies_assign operator failed.");
    }

    void divides_assign_operator()
    {
        Vector4D v4d(4.0);
        Vector3F v3f(4.0f);
        Vector2I v2i(4);

        TEST_ASSERT((v4d /= Vector4D(2.0)) == Vector4D(2.0), "Divides_assign operator failed.");
        TEST_ASSERT((v4d /= 2.0) == Vector4D(1.0), "Divides_assign operator failed.");

        TEST_ASSERT((v3f /= Vector3F(2.0f)) == Vector3F(2.0f), "Divides_assign operator failed.");
        TEST_ASSERT((v3f /= 2.0f) == Vector3F(1.0f), "Divides_assign operator failed.");

        TEST_ASSERT((v2i /= Vector2I(2)) == Vector2I(2), "Divides_assign operator failed.");
        TEST_ASSERT((v2i /= 2) == Vector2I(1), "Divides_assign operator failed.");
    }

    void add_operator()
    {
        const Vector4D v4d(1.0);
        const Vector3F v3f(1.0f);
        const Vector2I v2i(1);

        TEST_ASSERT(v4d + v4d == Vector4D(2.0), "Add operator failed.");
        TEST_ASSERT(v4d + 1.0 == Vector4D(2.0), "Add operator failed.");
        TEST_ASSERT(1.0 + v4d == Vector4D(2.0), "Add operator failed.");

        TEST_ASSERT(v3f + v3f == Vector3F(2.0f), "Add operator failed.");
        TEST_ASSERT(v3f + 1.0f == Vector3F(2.0f), "Add operator failed.");
        TEST_ASSERT(1.0f + v3f == Vector3F(2.0f), "Add operator failed.");

        TEST_ASSERT(v2i + v2i == Vector2I(2), "Add operator failed.");
        TEST_ASSERT(v2i + 1 == Vector2I(2), "Add operator failed.");
        TEST_ASSERT(1 + v2i == Vector2I(2), "Add operator failed.");
    }

    void subtract_operator()
    {
        const Vector4D v4d(1.0);
        const Vector3F v3f(1.0f);
        const Vector2I v2i(1);

        TEST_ASSERT(v4d - v4d == Vector4D(0.0), "Subtract operator failed.");
        TEST_ASSERT(v4d - 1.0 == Vector4D(0.0), "Subtract operator failed.");
        TEST_ASSERT(1.0 - v4d == Vector4D(0.0), "Subtract operator failed.");

        TEST_ASSERT(v3f - v3f == Vector3F(0.0f), "Subtract operator failed.");
        TEST_ASSERT(v3f - 1.0f == Vector3F(0.0f), "Subtract operator failed.");
        TEST_ASSERT(1.0f - v3f == Vector3F(0.0f), "Subtract operator failed.");

        TEST_ASSERT(v2i - v2i == Vector2I(0), "Subtract operator failed.");
        TEST_ASSERT(v2i - 1 == Vector2I(0), "Subtract operator failed.");
        TEST_ASSERT(1 - v2i == Vector2I(0), "Subtract operator failed.");
    }

    void multiply_operator()
    {
        const Vector4D v4d(2.0);
        const Vector3F v3f(2.0f);
        const Vector2I v2i(2);

        TEST_ASSERT(v4d * v4d == Vector4D(4.0), "Multiply operator failed.");
        TEST_ASSERT(v4d * 2.0 == Vector4D(4.0), "Multiply operator failed.");
        TEST_ASSERT(2.0 * v4d == Vector4D(4.0), "Multiply operator failed.");

        TEST_ASSERT(v3f * v3f == Vector3F(4.0f), "Multiply operator failed.");
        TEST_ASSERT(v3f * 2.0f == Vector3F(4.0f), "Multiply operator failed.");
        TEST_ASSERT(2.0f * v3f == Vector3F(4.0f), "Multiply operator failed.");

        TEST_ASSERT(v2i * v2i == Vector2I(4), "Multiply operator failed.");
        TEST_ASSERT(v2i * 2 == Vector2I(4), "Multiply operator failed.");
        TEST_ASSERT(2 * v2i == Vector2I(4), "Multiply operator failed.");
    }

    void divide_operator()
    {
        const Vector4D v4d(2.0);
        const Vector3F v3f(2.0f);
        const Vector2I v2i(2);

        TEST_ASSERT(v4d / v4d == Vector4D(1.0), "Divide operator failed.");
        TEST_ASSERT(v4d / 2.0 == Vector4D(1.0), "Divide operator failed.");
        TEST_ASSERT(2.0 / v4d == Vector4D(1.0), "Divide operator failed.");

        TEST_ASSERT(v3f / v3f == Vector3F(1.0f), "Divide operator failed.");
        TEST_ASSERT(v3f / 2.0f == Vector3F(1.0f), "Divide operator failed.");
        TEST_ASSERT(2.0f / v3f == Vector3F(1.0f), "Divide operator failed.");

        TEST_ASSERT(v2i / v2i == Vector2I(1), "Divide operator failed.");
        TEST_ASSERT(v2i / 2 == Vector2I(1), "Divide operator failed.");
        TEST_ASSERT(2 / v2i == Vector2I(1), "Divide operator failed.");
    }

    void equality_operator()
    {
        const Vector4D v4d(1.1, 2.2, 3.3, 4);
        const Vector3F v3f(5.5f, 6.6f, 7.7f);
        const Vector2I v2i(1, -2);
        const Vector2U v2u(1, 2);

        TEST_ASSERT(v4d == v4d, "Equality operator for Vector4D failed.");
        TEST_ASSERT(v3f == v3f, "Equality operator for Vector3F failed.");
        TEST_ASSERT(v2i == v2i, "Equality operator for Vector2I failed.");
        TEST_ASSERT(v2u == v2u, "Equality operator for Vector2U failed.");
    }

    void inequality_operator()
    {
        const Vector4D v4d(1.1, 2.2, 3.3, 4);
        const Vector3F v3f(5.5f, 6.6f, 7.7f);
        const Vector2I v2i(1, -2);
        const Vector2U v2u(1, 2);

        TEST_ASSERT(Vector4D() != v4d, "Equality operator for Vector4D failed.");
        TEST_ASSERT(Vector3F() != v3f, "Equality operator for Vector3F failed.");
        TEST_ASSERT(Vector2I() != v2i, "Equality operator for Vector2I failed.");
        TEST_ASSERT(Vector2U() != v2u, "Equality operator for Vector2U failed.");
    }
};

class bool_vector_operators_test : public test::suite
{
public:
    bool_vector_operators_test()
        : suite("bool_vector_operators_test")
    {
        add_test([this]() { assign_operator(); }, "assign_operator");
        add_test([this]() { access_operator(); }, "access_operator");
        add_test([this]() { data_access(); }, "data_access");
    }

private:
    void assign_operator()
    {
        const Vector4B v4b(true, false, true, false);
        const Vector3B v3b(true, false, true);
        const Vector2B v2b(true, false);

        const Vector4D v4d(-1.1, 0.0, 3.3, 0.0);
        const Vector3F v3f(5.5f, 0.0, -7.7f);
        const Vector2I v2i(1, 0);

        Vector4B v4b_result;
        Vector3B v3b_result;
        Vector2B v2b_result;

        v4b_result = v4b;
        v3b_result = v3b;
        v2b_result = v2b;

        TEST_ASSERT(v4b_result == v4b, "Assign to vector4b failed.");
        TEST_ASSERT(v3b_result == v3b, "Assign to vector3b failed.");
        TEST_ASSERT(v2b_result == v2b, "Assign to vector2b failed.");

        v4b_result = v4d;
        v3b_result = v3f;
        v2b_result = v2i;

        TEST_ASSERT(v4b_result == v4b, "Assign to vector4b failed.");
        TEST_ASSERT(v3b_result == v3b, "Assign to vector3b failed.");
        TEST_ASSERT(v2b_result == v2b, "Assign to vector2b failed.");
    }

    void access_operator()
    {
        const Vector4B v4b(true, false, true, false);
        const Vector3B v3b(true, false, true);
        const Vector2B v2b(true, false);

        TEST_ASSERT(v4b[0] && !v4b[1] && v4b[2] && !v4b[3], "Access to vector4b failed.");
        TEST_ASSERT(v3b[0] && !v3b[1] && v3b[2], "Access to vector3b failed.");
        TEST_ASSERT(v2b[0] && !v2b[1], "Access to vector2b failed.");
    }

    void data_access()
    {
        const Vector4B v4b(true, false, true, false);
        const Vector3B v3b(true, false, true);
        const Vector2B v2b(true, false);

        const bool* bool4 = v4b.data();
        const bool* bool3 = v3b.data();
        const bool* bool2 = v2b.data();

        TEST_ASSERT(bool4[0] && !bool4[1] && bool4[2] && !bool4[3], "Access to data of vector4b failed.");
        TEST_ASSERT(bool3[0] && !bool3[1] && bool3[2], "Access to data of vector3b failed.");
        TEST_ASSERT(bool2[0] && !bool2[1], "Access to data of vector2b failed.");
    }
};

int main()
{
    return run_tests(vector_operators_test(), bool_vector_operators_test());
}
