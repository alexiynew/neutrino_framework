#include <iomanip>
#include <iostream>

#include <unittest/suite.h>

namespace test {

Suite::Suite() : m_success{true}, m_name{}, m_tests{}, m_current_test{m_tests.end()}
{
}

void Suite::run()
{
    std::cout << m_name << std::endl;

    m_success      = true;
    m_current_test = m_tests.end();

    for (auto iter = m_tests.begin(); iter != m_tests.end(); iter++) {
        m_current_test = iter;
        setup();
        ((this)->*(m_current_test->function))();
        tearDown();

        if (m_current_test->success) {
            outputSuccess(*m_current_test);
        }
    }
}

bool Suite::isSuccessed()
{
    return m_success;
}

void Suite::setup()
{
}

void Suite::tearDown()
{
}

void Suite::addTest(TestFunction func, const std::string& name)
{
    std::size_t pos = name.find(':');

    std::string suite_name = name.substr(0, pos);
    std::string test_name  = name.substr(pos + 2);

    m_name = suite_name;

    m_tests.push_back({func, test_name, true});
}

void Suite::testFailed(const std::string& file, int line, const std::string& message)
{
    m_success = false;
    if (m_current_test != m_tests.end()) {
        m_current_test->success = false;
        outputFail({file, line, message, *m_current_test});
    }
}

void Suite::outputFail(const Status& status)
{
    std::cout << "    " << std::setw(40) << std::left << status.test.name << " FAIL" << std::endl;
    std::cout << "        " << status.file << ":" << status.line << " " << status.message << std::endl;
}

void Suite::outputSuccess(const TestData& test)
{
    std::cout << "    " << std::setw(40) << std::left << test.name << " OK" << std::endl;
}

} // namespace test
