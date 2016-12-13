#include <debug.hpp>

#include <math/math.hpp>

using namespace framework::math;

int main()
{

    // vector geometric functions
    {
        Vector3F v3f(1.0f, 2.0f, 3.0f);

        ASSERT_MSG(almostEqual(length(v3f), 3.7416574954986572f), "length failed");

        ASSERT_MSG(almostEqual(distance(Vector3F(3.0f, 3.0f, 5.0f), Vector3F(2.0f, 1.0f, 2.0f)), length(v3f)) &&
                   almostEqual(distance(Vector3F(2.0f, 1.0f, 2.0f), Vector3F(3.0f, 3.0f, 5.0f)), length(v3f)),
                   "distance failed");

        ASSERT_MSG(almostEqual(dot(v3f, v3f), 14.0f), "dot failed");

        ASSERT_MSG(cross(Vector3F(3.0f, 2.0f, 1.0f), v3f) == Vector3F(4, -8, 4), "cross failed");

        ASSERT_MSG(almostEqual(length(normalize(v3f)), 1.0f, 1), "normalize failed");

        ASSERT_MSG(faceforward(v3f, v3f, Vector3F(1.0f, 2.0f, -3.0f)) == v3f && faceforward(v3f, v3f, v3f) == -v3f,
                   "faceforward failed");

        ASSERT_MSG(almostEqual(reflection(v3f, normalize(v3f)), -v3f, 1), "reflection failed");

        ASSERT_MSG(almostEqual(refraction(v3f, normalize(v3f), 1.0f), reflection(v3f, normalize(v3f))),
                   "refraction "
                   "failed");
    }

    return 0;
}
