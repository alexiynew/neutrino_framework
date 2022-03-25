#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>

#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <unit_test/suite.hpp>

namespace framework::unit_test
{

Suite::Suite(std::string name)
    : m_name{std::move(name)}
    , m_current_test{m_tests.end()}
{}

void Suite::run()
{
    std::cout << m_name << std::endl;

    m_success      = true;
    m_current_test = m_tests.end();

    for (auto iterator = m_tests.begin(); iterator != m_tests.end(); iterator++) {
        m_current_test = iterator;

        std::stringstream log_output;
        log::set_logger(std::make_unique<log::StreamLogger>(log_output));

        try {
            m_current_test->function();
        } catch (const std::exception& e) {
            test_failed("Exception", 0, e.what());
            m_current_test->reslut = TestData::Result::exception;
        } catch (...) {
            test_failed("Exception", 0, "Unknown exception.");
            m_current_test->reslut = TestData::Result::exception;
        }

        output(*m_current_test);
        std::cout << log_output.str();
    }
}

bool Suite::is_succeeded() const
{
    return m_success;
}

std::string Suite::name() const
{
    return m_name;
}

void Suite::add_test(FunctionType&& function, const std::string& name)
{
    m_tests.emplace_back(name, std::forward<FunctionType>(function));
}

void Suite::test_failed(const std::string& file, int32 line, const std::string& message)
{
    m_success = false;
    if (m_current_test != m_tests.end()) {
        m_current_test->reslut = TestData::Result::fail;
        m_current_test->status.push_back({message, file, line});
    }
}

void Suite::output(const TestData& test)
{
    std::string result;

    switch (test.reslut) {
        case TestData::Result::success: result = "OK"; break;
        case TestData::Result::exception: result = "EXCEPTION"; break;
        case TestData::Result::fail: result = "FAIL"; break;
    }

    std::cout << "    " << std::setw(40) << std::left << test.name << " [" << std::setw(10) << std::internal << result
              << "]" << std::endl;

    if (test.reslut == TestData::Result::fail) {
        for (const auto& item : test.status) {
            std::cout << "        " << item.file << ":" << item.line << " " << item.message << std::endl;
        }
    } else if (test.reslut == TestData::Result::exception) {
        for (const auto& item : test.status) {
            std::cout << "        " << item.message << std::endl;
        }
    }
}

Suite::TestData::TestData(std::string test_name, FunctionType&& function_to_call)
    : name{std::move(test_name)}
    , function{std::forward<FunctionType>(function_to_call)}
{}

} // namespace framework::unit_test
