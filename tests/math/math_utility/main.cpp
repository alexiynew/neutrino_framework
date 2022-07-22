#include <math/math.hpp>
#include <unit_test/suite.hpp>

class UtilityHashTest : public framework::unit_test::Suite
{
public:
    UtilityHashTest()
        : Suite("UtilityHashTest")
    {
        add_test([this]() { vector_hash_function(); }, "vector_hash_function");
        add_test([this]() { matrix_hash_function(); }, "matrix_hash_function");
    }

private:
    void vector_hash_function()
    {
        {
            using framework::math::Vector2f;

            auto h1 = std::hash<Vector2f>{}({9.0f, 1.0f});
            auto h2 = std::hash<Vector2f>{}({9.0f, 1.0f});
            auto h3 = std::hash<Vector2f>{}({1.0f, 9.0f});

            TEST_ASSERT(h1 == h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
        }

        {
            using framework::math::Vector3i;

            auto h1 = std::hash<Vector3i>{}({});
            auto h2 = std::hash<Vector3i>{}({1, 0, 0});
            auto h3 = std::hash<Vector3i>{}({0, 0, 1});
            auto h4 = std::hash<Vector3i>{}({0, 0, 0});

            TEST_ASSERT(h1 == h4, "Hash function not working");
            TEST_ASSERT(h1 != h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
            TEST_ASSERT(h2 != h3, "Hash function not working");
        }

        {
            using framework::math::Vector4b;

            auto h1 = std::hash<Vector4b>{}({true, false, false, true});
            auto h2 = std::hash<Vector4b>{}({true, false, false, true});
            auto h3 = std::hash<Vector4b>{}({false, true, true, false});

            TEST_ASSERT(h1 == h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
        }

        {
            using framework::math::Vector4d;

            auto h1 = std::hash<Vector4d>{}({9, 1, 0, 0});
            auto h2 = std::hash<Vector4d>{}({9, 1, 0, 0});
            auto h3 = std::hash<Vector4d>{}({0, 0, 1, 9});

            TEST_ASSERT(h1 == h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
        }
    }

    void matrix_hash_function()
    {
        {
            using framework::math::Matrix2f;

            auto h1 = std::hash<Matrix2f>{}({1, 0, 0, 1});
            auto h2 = std::hash<Matrix2f>{}({1, 0, 0, 1});
            auto h3 = std::hash<Matrix2f>{}({1, 0, 2, 1});

            TEST_ASSERT(h1 == h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
        }

        {
            using framework::math::Matrix3d;

            auto h1 = std::hash<Matrix3d>{}({1, 0, 0, 1, 0, 0, 1, 0, 4});
            auto h2 = std::hash<Matrix3d>{}({1, 0, 0, 1, 0, 0, 1, 0, 4});
            auto h3 = std::hash<Matrix3d>{}({4, 0, 0, 1, 0, 0, 1, 0, 1});

            TEST_ASSERT(h1 == h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
        }

        {
            using framework::math::Matrix4f;

            auto h1 = std::hash<Matrix4f>{}({1, 0, 0, 1, 0, 0, 1, 0, 4, 0, 5, 2, 3, 5, 6, 0});
            auto h2 = std::hash<Matrix4f>{}({1, 0, 0, 1, 0, 0, 1, 0, 4, 0, 5, 2, 3, 5, 6, 0});
            auto h3 = std::hash<Matrix4f>{}({1, 0, 0, 1, 0, 0, 1, 0, 4, 9, 5, 2, 3, 5, 6, 0});

            TEST_ASSERT(h1 == h2, "Hash function not working");
            TEST_ASSERT(h1 != h3, "Hash function not working");
        }
    }
};

int main()
{
    return run_tests(UtilityHashTest());
}
