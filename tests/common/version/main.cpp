#include <common/version.hpp>
#include <unit_test/suite.hpp>

class VersionTest : public framework::unit_test::Suite
{
public:
    VersionTest()
        : Suite("VersionTest")
    {
        add_test([this]() { constructor(); }, "constructor");
        add_test([this]() { from_string(); }, "from_string");
        add_test([this]() { as_string(); }, "as_string");
        add_test([this]() { comparations(); }, "comparations");
    }

private:
    void constructor()
    {
        using framework::Version;

        Version v1{1, 2, 3, 4};

        TEST_ASSERT(v1.major() == 1, "Wrong major version number.");
        TEST_ASSERT(v1.minor() == 2, "Wrong minor version number.");
        TEST_ASSERT(v1.patch() == 3, "Wrong patch version number.");
        TEST_ASSERT(v1.build_number() == 4, "Wrong build version number.");

        Version v2{1, 2};

        TEST_ASSERT(v2.major() == 1, "Wrong major version number.");
        TEST_ASSERT(v2.minor() == 2, "Wrong minor version number.");
        TEST_ASSERT(v2.patch() == 0, "Wrong patch version number.");
        TEST_ASSERT(v2.build_number() == 0, "Wrong build version number.");
    }

    void from_string()
    {
        using framework::Version;

        Version v1{"1.2.3.4"};

        TEST_ASSERT(v1.major() == 1, "Wrong major version number.");
        TEST_ASSERT(v1.minor() == 2, "Wrong minor version number.");
        TEST_ASSERT(v1.patch() == 3, "Wrong patch version number.");
        TEST_ASSERT(v1.build_number() == 4, "Wrong build version number.");

        Version v2{".1.2.3.4"};

        TEST_ASSERT(v2.major() == 0, "Wrong major version number.");
        TEST_ASSERT(v2.minor() == 1, "Wrong minor version number.");
        TEST_ASSERT(v2.patch() == 2, "Wrong patch version number.");
        TEST_ASSERT(v2.build_number() == 3, "Wrong build version number.");

        Version v3{"1.2."};

        TEST_ASSERT(v3.major() == 1, "Wrong major version number.");
        TEST_ASSERT(v3.minor() == 2, "Wrong minor version number.");
        TEST_ASSERT(v3.patch() == 0, "Wrong patch version number.");
        TEST_ASSERT(v3.build_number() == 0, "Wrong build version number.");

        Version v4{"1.2.3"};

        TEST_ASSERT(v4.major() == 1, "Wrong major version number.");
        TEST_ASSERT(v4.minor() == 2, "Wrong minor version number.");
        TEST_ASSERT(v4.patch() == 3, "Wrong patch version number.");
        TEST_ASSERT(v4.build_number() == 0, "Wrong build version number.");
    }

    void as_string()
    {
        using framework::Version;

        Version v1(1, 2, 3, 4);

        TEST_ASSERT(v1.as_string() == "1.2.3.4", "Worng version number string.");

        Version v2(1, 2);

        TEST_ASSERT(v2.as_string() == "1.2.0.0", "Worng version number string.");
    }

    void comparations()
    {
        using framework::Version;

        Version v1{1, 2, 3, 4};
        Version v2{1, 2, 3, 4};

        TEST_ASSERT(v1 == v2, "Should be equal.");
        TEST_ASSERT(!(v1 != v2), "Should be equal.");

        Version v3{100, 0};

        TEST_ASSERT(v3 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v3, "Operator < failed.");

        Version v4{1, 200};

        TEST_ASSERT(v4 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v4, "Operator < failed.");

        Version v5{1, 2, 300};

        TEST_ASSERT(v5 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v5, "Operator < failed.");

        Version v6{1, 2, 3, 400};

        TEST_ASSERT(v6 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v6, "Operator < failed.");

        TEST_ASSERT(!(v2 >= v6), "Operator >= failed.");
        TEST_ASSERT(!(v6 <= v2), "Operator <= failed.");

        TEST_ASSERT(v1 >= v2, "Operator >= failed.");
        TEST_ASSERT(v2 <= v1, "Operator <= failed.");
    }
};

int main()
{
    return run_tests(VersionTest());
}
