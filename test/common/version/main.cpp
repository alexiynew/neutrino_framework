
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <common/version.hpp>
#include <unit_test/suite.hpp>

class version_test : public framework::unit_test::suite
{
public:
    version_test() : suite("version_test")
    {
        add_test([this]() { constructor(); }, "constructor");
        add_test([this]() { from_string(); }, "from_string");
        add_test([this]() { as_string(); }, "as_string");
        add_test([this]() { comparations(); }, "comparations");
    }

private:
    void constructor()
    {
        using framework::utils::version;

        version v1{1, 2, 3, 4};

        TEST_ASSERT(v1.major == 1, "Wrong major version number.");
        TEST_ASSERT(v1.minor == 2, "Wrong minor version number.");
        TEST_ASSERT(v1.patch == 3, "Wrong patch version number.");
        TEST_ASSERT(v1.build == 4, "Wrong build version number.");

        version v2{1, 2};

        TEST_ASSERT(v2.major == 1, "Wrong major version number.");
        TEST_ASSERT(v2.minor == 2, "Wrong minor version number.");
        TEST_ASSERT(v2.patch == 0, "Wrong patch version number.");
        TEST_ASSERT(v2.build == 0, "Wrong build version number.");
    }

    void from_string()
    {
        using framework::utils::version;

        version v1{"1.2.3.4"};

        TEST_ASSERT(v1.major == 1, "Wrong major version number.");
        TEST_ASSERT(v1.minor == 2, "Wrong minor version number.");
        TEST_ASSERT(v1.patch == 3, "Wrong patch version number.");
        TEST_ASSERT(v1.build == 4, "Wrong build version number.");

        version v2{".1.2.3.4"};

        TEST_ASSERT(v2.major == 0, "Wrong major version number.");
        TEST_ASSERT(v2.minor == 1, "Wrong minor version number.");
        TEST_ASSERT(v2.patch == 2, "Wrong patch version number.");
        TEST_ASSERT(v2.build == 3, "Wrong build version number.");

        version v3{"1.2."};

        TEST_ASSERT(v3.major == 1, "Wrong major version number.");
        TEST_ASSERT(v3.minor == 2, "Wrong minor version number.");
        TEST_ASSERT(v3.patch == 0, "Wrong patch version number.");
        TEST_ASSERT(v3.build == 0, "Wrong build version number.");

        version v4{"1.2.3"};

        TEST_ASSERT(v4.major == 1, "Wrong major version number.");
        TEST_ASSERT(v4.minor == 2, "Wrong minor version number.");
        TEST_ASSERT(v4.patch == 3, "Wrong patch version number.");
        TEST_ASSERT(v4.build == 0, "Wrong build version number.");
    }

    void as_string()
    {
        using framework::utils::version;

        version v1(1, 2, 3, 4);

        TEST_ASSERT(v1.as_string() == "1.2.3.4", "Worng version number string.");

        version v2(1, 2);

        TEST_ASSERT(v2.as_string() == "1.2.0.0", "Worng version number string.");
    }

    void comparations()
    {
        using framework::utils::version;

        version v1{1, 2, 3, 4};
        version v2{1, 2, 3, 4};

        TEST_ASSERT(v1 == v2, "Should be equal.");
        TEST_ASSERT(!(v1 != v2), "Should be equal.");

        version v3{100, 0};

        TEST_ASSERT(v3 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v3, "Operator < failed.");

        version v4{1, 200};

        TEST_ASSERT(v4 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v4, "Operator < failed.");

        version v5{1, 2, 300};

        TEST_ASSERT(v5 > v2, "Operator > failed.");
        TEST_ASSERT(v2 < v5, "Operator < failed.");

        version v6{1, 2, 3, 400};

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
    return run_tests(version_test());
}
