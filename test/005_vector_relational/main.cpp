#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // vector relational functions
    {
        Vector2I v2i1(1, 5);
        Vector2I v2i2(2, 5);

        assert_msg(less(v2i1, v2i2) == Vector2B(true, false), "less failed");
        assert_msg(less(v2i2, v2i1) == Vector2B(false, false), "less failed");

        assert_msg(less_equal(v2i1, v2i2) == Vector2B(true, true), "less_equal failed");
        assert_msg(less_equal(v2i2, v2i1) == Vector2B(false, true), "less_equal failed");

        assert_msg(greater(v2i1, v2i2) == Vector2B(false, false), "greater failed");
        assert_msg(greater(v2i2, v2i1) == Vector2B(true, false), "greater failed");

        assert_msg(greater_equal(v2i1, v2i2) == Vector2B(false, true), "greater_equal failed");
        assert_msg(greater_equal(v2i2, v2i1) == Vector2B(true, true), "greater_equal failed");

        assert_msg(equal(v2i1, v2i2) == Vector2B(false, true), "equal_to failed");

        assert_msg(not_equal(v2i2, v2i1) == Vector2B(true, false), "not_equal_to failed");
    }

    // vector bool logic aperations
    {
        assert_msg(logical_not(Vector2B(false, true)) == Vector2B(true, false), "bool inverse");

        assert_msg(logical_and(Vector2B(true, true), Vector2B(true, false)) == Vector2B(true, false), "bool and");

        assert_msg(logical_or(Vector2B(true, true), Vector2B(true, false)) == Vector2B(true, true), "bool or");

        assert_msg(all(Vector2B(true, true)), "bool all");
        assert_msg(all(Vector2B(true, false)) == false, "bool all false");

        assert_msg(any(Vector2B(true, false)), "bool any");
        assert_msg(any(Vector2B(false, false)) == false, "bool any false");
    }

    return 0;
}
