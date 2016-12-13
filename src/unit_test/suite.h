#ifndef FRAMEWORK_UNIT_TEST_SUITE_H
#define FRAMEWORK_UNIT_TEST_SUITE_H

#include <functional>
#include <string>
#include <vector>

namespace test {

class suite
{
public:
    suite(const std::string& name);

    void run();

    bool is_succeeded();

protected:
    using function_type = std::function<void()>;

    void add_test(function_type&& function, const std::string& name);

    void test_failed(const std::string& file, int line, const std::string& message);

private:
    struct test_data
    {
        struct Status
        {
            std::string file;
            std::string message;
            int line;
        };

        Status status;
        std::string name;
        function_type function;
        bool success;

        test_data(function_type&& function, const std::string& name);
    };

    void output_fail(const test_data& test);

    void output_success(const test_data& test);

    bool m_success;
    std::string m_name;
    std::vector<test_data> m_tests;
    std::vector<test_data>::iterator m_current_test;
};


template <typename... Arguments>
int run_tests(Arguments&&... tests)
{
    int count  = sizeof...(tests);
    int passed = 0;

    std::vector<test::suite*> tests_container{&tests...};

    for (auto* test : tests_container) {
        test->run();
        passed += test->is_succeeded() ? 1 : 0;
    }

    return count - passed;
}

} // namespace test

#endif
