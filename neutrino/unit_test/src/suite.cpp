////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Base class for tests.
/// @author Fedorov Alexey
/// @date 04.03.2017
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#include <iomanip>
#include <iostream>
#include <memory>

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

    log::set_logger(std::make_unique<log::StreamLogger>(std::cout));

    for (auto iterator = m_tests.begin(); iterator != m_tests.end(); iterator++) {
        m_current_test = iterator;

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
        m_current_test->status = {message, file, line};
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
        std::cout << "        " << test.status.file << ":" << test.status.line << " " << test.status.message
                  << std::endl;
    } else if (test.reslut == TestData::Result::exception) {
        std::cout << "        " << test.status.message << std::endl;
    }
}

Suite::TestData::TestData(std::string test_name, FunctionType&& function_to_call)
    : name{std::move(test_name)}
    , function{std::forward<FunctionType>(function_to_call)}
{}

} // namespace framework::unit_test
