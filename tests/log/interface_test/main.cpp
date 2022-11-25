#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include <common/utils.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <unit_test/suite.hpp>

using neutrino::log::debug;
using neutrino::log::error;
using neutrino::log::fatal;
using neutrino::log::info;
using neutrino::log::warning;

using neutrino::log::set_logger;
using neutrino::log::SeverityLevel;
using neutrino::log::StreamLogger;

class LoggerInterfaceTest : public neutrino::unit_test::Suite
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

        if (neutrino::is_debug()) {
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
