#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // vector relational functions
    {
        Vector2I v2i1(1, 5);
        Vector2I v2i2(2, 5);

        ASSERT_MSG(less(v2i1, v2i2) == Vector2B(true, false), "less failed");
        ASSERT_MSG(less(v2i2, v2i1) == Vector2B(false, false), "less failed");

        ASSERT_MSG(less_equal(v2i1, v2i2) == Vector2B(true, true), "less_equal failed");
        ASSERT_MSG(less_equal(v2i2, v2i1) == Vector2B(false, true), "less_equal failed");

        ASSERT_MSG(greater(v2i1, v2i2) == Vector2B(false, false), "greater failed");
        ASSERT_MSG(greater(v2i2, v2i1) == Vector2B(true, false), "greater failed");

        ASSERT_MSG(greater_equal(v2i1, v2i2) == Vector2B(false, true), "greater_equal failed");
        ASSERT_MSG(greater_equal(v2i2, v2i1) == Vector2B(true, true), "greater_equal failed");

        ASSERT_MSG(equal(v2i1, v2i2) == Vector2B(false, true), "equal_to failed");

        ASSERT_MSG(not_equal(v2i2, v2i1) == Vector2B(true, false), "not_equal_to failed");
    }

    // vector bool logic aperations
    {
        ASSERT_MSG(logical_not(Vector2B(false, true)) == Vector2B(true, false), "bool inverse");

        ASSERT_MSG(logical_and(Vector2B(true, true), Vector2B(true, false)) == Vector2B(true, false), "bool and");

        ASSERT_MSG(logical_or(Vector2B(true, true), Vector2B(true, false)) == Vector2B(true, true), "bool or");

        ASSERT_MSG(all(Vector2B(true, true)), "bool all");
        ASSERT_MSG(all(Vector2B(true, false)) == false, "bool all false");

        ASSERT_MSG(any(Vector2B(true, false)), "bool any");
        ASSERT_MSG(any(Vector2B(false, false)) == false, "bool any false");
    }

    return 0;
}
