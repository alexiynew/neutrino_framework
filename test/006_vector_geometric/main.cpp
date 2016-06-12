#include <debug.h>

#include <math/fmath.h>

using namespace framework::math;

int main()
{

    // vector geometric functions
    {
        vec3f v3f(1.0f, 2.0f, 3.0f);

        assert_msg(almost_equal(length(v3f), 3.7416574954986572f), "length failed");

        assert_msg(almost_equal(distance(vec3f(3.0f, 3.0f, 5.0f), vec3f(2.0f, 1.0f, 2.0f)), length(v3f)) && almost_equal(distance(vec3f(2.0f, 1.0f, 2.0f), vec3f(3.0f, 3.0f, 5.0f)), length(v3f)), "distance failed");

        assert_msg(almost_equal(dot(v3f, v3f), 14.0f), "dot failed");

        assert_msg(cross(vec3f(3.0f, 2.0f, 1.0f), v3f) == vec3f(4, -8, 4), "cross failed");

        assert_msg(almost_equal(length(normalize(v3f)), 1.0f, 1), "normalize failed");

        assert_msg(faceforward(v3f, v3f, vec3f(1.0f, 2.0f, -3.0f)) == v3f && faceforward(v3f, v3f, v3f) == -v3f,
                   "faceforward failed");

        assert_msg(almost_equal(reflection(v3f, normalize(v3f)), -v3f, 1), "reflection failed");

        assert_msg(almost_equal(refraction(v3f, normalize(v3f), 1.0f), reflection(v3f, normalize(v3f))), "refraction "
                                                                                                         "failed");
    }

    return 0;
}
