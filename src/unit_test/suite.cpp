#include <iomanip>
#include <iostream>

#include <unit_test/suite.h>

namespace test {

suite::suite(const std::string& name)
    : m_success{true}
    , m_name{name}
    , m_tests{}
    , m_current_test{m_tests.end()}
{
}

void suite::run()
{
    std::cout << m_name << std::endl;

    m_success      = true;
    m_current_test = m_tests.end();

    for (auto iterator = m_tests.begin(); iterator != m_tests.end(); iterator++) {
        m_current_test = iterator;

        m_current_test->function();

        if (m_current_test->success) {
            output_success(*m_current_test);
        }
    }
}

bool suite::is_succeeded()
{
    return m_success;
}

void suite::add_test(function_type&& function, const std::string& name)
{
    m_tests.emplace_back(std::forward<function_type>(function), name);
}

void suite::test_failed(const std::string& file, int line, const std::string& message)
{
    m_success = false;
    if (m_current_test != m_tests.end()) {
        m_current_test->success = false;
        m_current_test->status  = {file, message, line};
        output_fail(*m_current_test);
    }
}

void suite::output_fail(const test_data& test)
{
    std::cout << "    " << std::setw(40) << std::left << test.name << " FAIL" << std::endl;
    std::cout << "        " << test.status.file << ":" << test.status.line << " " << test.status.message << std::endl;
}

void suite::output_success(const test_data& test)
{
    std::cout << "    " << std::setw(40) << std::left << test.name << " OK" << std::endl;
}

suite::test_data::test_data(function_type&& function_to_call, const std::string& test_name)
    : status{"", "", -1}
    , name(test_name)
    , function(std::forward<function_type>(function_to_call))
    , success(true)
{
}

} // namespace test
