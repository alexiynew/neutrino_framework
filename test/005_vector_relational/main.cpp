#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // vector relational functions
    {
        vec2i v2i1(1, 5);
        vec2i v2i2(2, 5);

        assert_msg(less(v2i1, v2i2) == vec2b(true, false), "less failed");
        assert_msg(less(v2i2, v2i1) == vec2b(false, false), "less failed");

        assert_msg(less_equal(v2i1, v2i2) == vec2b(true, true), "less_equal failed");
        assert_msg(less_equal(v2i2, v2i1) == vec2b(false, true), "less_equal failed");

        assert_msg(greater(v2i1, v2i2) == vec2b(false, false), "greater failed");
        assert_msg(greater(v2i2, v2i1) == vec2b(true, false), "greater failed");

        assert_msg(greater_equal(v2i1, v2i2) == vec2b(false, true), "greater_equal failed");
        assert_msg(greater_equal(v2i2, v2i1) == vec2b(true, true), "greater_equal failed");

        assert_msg(equal(v2i1, v2i2) == vec2b(false, true), "equal_to failed");

        assert_msg(not_equal(v2i2, v2i1) == vec2b(true, false), "not_equal_to failed");

    }

    // vector bool logic aperations
    {
        assert_msg(logical_not(vec2b(false, true)) == vec2b(true, false), "bool inverse");

        assert_msg(logical_and(vec2b(true, true), vec2b(true, false)) == vec2b(true, false), "bool and");

        assert_msg(logical_or(vec2b(true, true), vec2b(true, false)) == vec2b(true, true), "bool or");

        assert_msg(all(vec2b(true, true)), "bool all");
        assert_msg(all(vec2b(true, false)) == false, "bool all false");

        assert_msg(any(vec2b(true, false)), "bool any");
        assert_msg(any(vec2b(false, false)) == false, "bool any false");
    }

    return 0;
}
