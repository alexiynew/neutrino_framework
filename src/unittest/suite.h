#ifndef FRAMEWORK_UNITTEST_SUITE_H
#define FRAMEWORK_UNITTEST_SUITE_H

#include <functional>
#include <string>
#include <vector>

namespace test {

class Suite
{
public:
    Suite(const std::string& name);

    void run();

    bool is_successed();

protected:
    using TestFunction = std::function<void()>;

    void add_test(TestFunction&& function, const std::string& name);

    void test_failed(const std::string& file, int line, const std::string& message);

private:
    struct TestData
    {
        struct Status
        {
            std::string file;
            std::string message;
            int line;
        };

        Status status;
        std::string name;
        TestFunction function;
        bool success;

        TestData(TestFunction&& function, const std::string& name);
    };

    void output_fail(const TestData& test);

    void output_success(const TestData& test);

    bool m_success;
    std::string m_name;
    std::vector<TestData> m_tests;
    std::vector<TestData>::iterator m_current_test;
};


template <typename... Args>
int run_tests(Args&&... tests)
{
    int count  = sizeof...(tests);
    int passed = 0;

    std::vector<test::Suite*> tests_container{&tests...};

    for (auto* test : tests_container) {
        test->run();
        passed += test->is_successed() ? 1 : 0;
    }

    return count - passed;
}

} // namspace test

#endif
