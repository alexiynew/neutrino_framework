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

        ASSERT_MSG(lessEqual(v2i1, v2i2) == Vector2B(true, true), "lessEqual failed");
        ASSERT_MSG(lessEqual(v2i2, v2i1) == Vector2B(false, true), "lessEqual failed");

        ASSERT_MSG(greater(v2i1, v2i2) == Vector2B(false, false), "greater failed");
        ASSERT_MSG(greater(v2i2, v2i1) == Vector2B(true, false), "greater failed");

        ASSERT_MSG(greaterEqual(v2i1, v2i2) == Vector2B(false, true), "greaterEqual failed");
        ASSERT_MSG(greaterEqual(v2i2, v2i1) == Vector2B(true, true), "greaterEqual failed");

        ASSERT_MSG(equal(v2i1, v2i2) == Vector2B(false, true), "equal_to failed");

        ASSERT_MSG(notEqual(v2i2, v2i1) == Vector2B(true, false), "notEqual_to failed");
    }

    // vector bool logic aperations
    {
        ASSERT_MSG(logicalNot(Vector2B(false, true)) == Vector2B(true, false), "bool inverse");

        ASSERT_MSG(logicalAnd(Vector2B(true, true), Vector2B(true, false)) == Vector2B(true, false), "bool and");

        ASSERT_MSG(logicalOr(Vector2B(true, true), Vector2B(true, false)) == Vector2B(true, true), "bool or");

        ASSERT_MSG(all(Vector2B(true, true)), "bool all");
        ASSERT_MSG(all(Vector2B(true, false)) == false, "bool all false");

        ASSERT_MSG(any(Vector2B(true, false)), "bool any");
        ASSERT_MSG(any(Vector2B(false, false)) == false, "bool any false");
    }

    return 0;
}
