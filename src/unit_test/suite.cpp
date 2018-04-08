/// @file suite.cpp
/// @brief Base class for tests.
/// @author Fedorov Alexey
/// @date 04.03.2017

#include <iomanip>
#include <iostream>

#include <unit_test/suite.hpp>

namespace framework {

namespace unit_test {

suite::suite(const std::string& name) : m_name{name}, m_tests{}, m_current_test{m_tests.end()}, m_success{true}
{}

void suite::run()
{
    std::cout << m_name << std::endl;

    m_success      = true;
    m_current_test = m_tests.end();

    for (auto iterator = m_tests.begin(); iterator != m_tests.end(); iterator++) {
        m_current_test = iterator;

        try {
            m_current_test->function();
        } catch (const std::exception& e) {
            test_failed("Exception", 0, e.what());
            throw;
        } catch (...) {
            test_failed("Exception", 0, "Unknown exception.");
            throw;
        }

        if (m_current_test->success) {
            output_success(*m_current_test);
        }
    }
}

bool suite::is_succeeded() const
{
    return m_success;
}

std::string suite::name() const
{
    return m_name;
}

void suite::add_test(function_type&& function, const std::string& name)
{
    m_tests.emplace_back(std::forward<function_type>(function), name);
}

void suite::test_failed(const std::string& file, int32 line, const std::string& message)
{
    m_success = false;
    if (m_current_test != m_tests.end()) {
        m_current_test->success = false;
        m_current_test->status  = {message, file, line};
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
    : status{"", "", -1}, name{test_name}, function{std::forward<function_type>(function_to_call)}, success{true}
{}

} // namespace unit_test

} // namespace framework
