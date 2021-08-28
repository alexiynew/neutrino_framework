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

#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include <common/utils.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <unit_test/suite.hpp>

using framework::log::debug;
using framework::log::error;
using framework::log::fatal;
using framework::log::info;
using framework::log::warning;

using framework::log::set_logger;
using framework::log::SeverityLevel;
using framework::log::StreamLogger;

class LoggerInterfaceTest : public framework::unit_test::Suite
{
public:
    LoggerInterfaceTest()
        : Suite("LoggerInterfaceTest")
    {
        add_test([this]() { stream_logger_test(); }, "stream_logger_test");
        add_test([this]() { long_log_string(); }, "long_log_string");
        add_test([this]() { thread_safety(); }, "thread_safety");
    }

private:
    void stream_logger_test()
    {
        std::stringstream log_stream;
        set_logger(std::make_unique<StreamLogger>(log_stream));

        debug(name()) << "message_1" << std::endl;
        info(name()) << "message_2" << std::endl;
        warning(name()) << "message_3" << std::endl;
        error(name()) << "message_4" << std::endl;
        fatal(name()) << "message_5" << std::endl;

        std::stringstream log_test;

        if (framework::utils::is_debug()) {
            log_test << "[" << SeverityLevel::debug << "] " << name() << ": message_1" << std::endl;
        }

        log_test << "[" << SeverityLevel::info << "] " << name() << ": message_2" << std::endl;
        log_test << "[" << SeverityLevel::warning << "] " << name() << ": message_3" << std::endl;
        log_test << "[" << SeverityLevel::error << "] " << name() << ": message_4" << std::endl;
        log_test << "[" << SeverityLevel::fatal << "] " << name() << ": message_5" << std::endl;

        TEST_ASSERT(log_test.str() == log_stream.str(), "Log messages are not correct.");
    }

    void long_log_string()
    {
        std::stringstream log_stream;
        set_logger(std::make_unique<StreamLogger>(log_stream));

        info(name()) << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << "long string long string long string long string long string long string long string long "
                        "string long"
                     << std::endl;

        std::stringstream log_test;

        log_test << "[" << SeverityLevel::info << "] " << name() << ": "
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << "long string long string long string long string long string long string long string long string "
                    "long"
                 << std::endl;

        TEST_ASSERT(log_test.str() == log_stream.str(), "Log messages are not correct.");
    }

    void thread_safety()
    {
        std::stringstream log_stream;
        set_logger(std::make_unique<StreamLogger>(log_stream));

        std::thread t1([this]() {
            for (int i = 0; i < 100; ++i) {
                info(name()) << "thread 1 [" << i << "]" << std::endl;
                std::this_thread::yield();
            }
        });

        std::thread t2([this]() {
            for (int i = 0; i < 100; ++i) {
                info(name()) << "thread 2 [" << i << "]" << std::endl;
            }
        });

        t1.join();
        t2.join();

        // We can't check the output. Just check, that the test would not crash.
        TEST_ASSERT(!log_stream.str().empty(), "Log messages are not correct.");
    }
};

int main()
{
    return run_tests(LoggerInterfaceTest());
}
