#include <iomanip>
#include <iostream>

#include <unittest/suite.h>

namespace test {

Suite::Suite(const std::string& name)
    : m_success{true}
    , m_name{name}
    , m_tests{}
    , m_current_test{m_tests.end()}
{
}

void Suite::run()
{
    std::cout << m_name << std::endl;

    m_success      = true;
    m_current_test = m_tests.end();

    for (auto iter = m_tests.begin(); iter != m_tests.end(); iter++) {
        m_current_test = iter;

        m_current_test->function();

        if (m_current_test->success) {
            output_success(*m_current_test);
        }
    }
}

bool Suite::is_successed()
{
    return m_success;
}

void Suite::add_test(TestFunction&& function, const std::string& name)
{
    m_tests.emplace_back(std::forward<TestFunction>(function), name);
}

void Suite::test_failed(const std::string& file, int line, const std::string& message)
{
    m_success = false;
    if (m_current_test != m_tests.end()) {
        m_current_test->success = false;
        m_current_test->status  = {file, message, line};
        output_fail(*m_current_test);
    }
}

void Suite::output_fail(const TestData& test)
{
    std::cout << "    " << std::setw(40) << std::left << test.name << " FAIL" << std::endl;
    std::cout << "        " << test.status.file << ":" << test.status.line << " " << test.status.message << std::endl;
}

void Suite::output_success(const TestData& test)
{
    std::cout << "    " << std::setw(40) << std::left << test.name << " OK" << std::endl;
}

Suite::TestData::TestData(TestFunction&& function_to_call, const std::string& test_name)
    : status{"", "", -1}
    , name(test_name)
    , function(std::forward<TestFunction>(function_to_call))
    , success(true)
{
}

} // namespace test
