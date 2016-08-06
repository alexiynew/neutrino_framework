#include <memory>
#include <vector>

#include <math/fmath.h>
#include <unittest/test.h>

using namespace framework::math;

class Transform2DTest : public test::Suite
{
    public:
    Transform2DTest()
    {
        ADD_TEST(Transform2DTest::translate);
    }

    private:
    void translate()
    {
        Matrix3F m  = {1, 4, 7, 2, 5, 8, 3, 6, 9};
        Matrix3F m1 = {1, 4, 7, 2, 5, 8, 33, 96, 159};

        TEST_ASSERT(::translate(m, Vector2F(10, 10)) == m1, "Translate by (10, 10) failed.");
        TEST_ASSERT(::translate(m1, Vector2F(-10, -10)) == m, "Translate by (-10, -10) failed.");
        TEST_ASSERT(::translate(m, Vector2F(0, 0)) == m, "Translate by (0, 0) failed.");
    }
};

int main()
{

    std::vector<std::unique_ptr<test::Suite>> tests;

    tests.emplace_back(new Transform2DTest());

    bool all_successed = true;

    for (auto& test : tests) {
        test->run();
        all_successed &= test->isSuccessed();
    }

    return all_successed ? 0 : 1;
}
