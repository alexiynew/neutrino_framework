#include <logger/log.hpp>
#include <logger/stream_logger.hpp>
#include <sstream>
#include <string>
#include <unit_test/suite.hpp>

using framework::logger::log;
using framework::logger::stream_logger;

std::string to_string(const framework::logger::severity_level level)
{
    using severity_level = framework::logger::severity_level;
    switch (level) {
        case severity_level::debug: return "debug";
        case severity_level::info: return "info";
        case severity_level::warning: return "warning";
        case severity_level::error: return "error";
        case severity_level::fatal: return "fatal";
        default: return "UNKNOWN";
    }
}

class logger_interface_test : public framework::unit_test::suite
{
public:
    logger_interface_test()
        : suite(suite_name)
    {
        add_test([this]() { stream_logger_test(); }, "stream_logger_test");
    }

private:
    void stream_logger_test()
    {
        std::stringstream log_stream;
        log::set_logger(std::make_unique<stream_logger>(log_stream));

        log::debug(suite_name, "message_1");
        log::info(suite_name, "message_2");
        log::warning(suite_name, "message_3");
        log::error(suite_name, "message_4");
        log::fatal(suite_name, "message_5");

        using level = framework::logger::severity_level;

        std::stringstream log_test;
        log_test << "[" << to_string(level::debug) << "] " << suite_name << ": message_1" << std::endl;
        log_test << "[" << to_string(level::info) << "] " << suite_name << ": message_2" << std::endl;
        log_test << "[" << to_string(level::warning) << "] " << suite_name << ": message_3" << std::endl;
        log_test << "[" << to_string(level::error) << "] " << suite_name << ": message_4" << std::endl;
        log_test << "[" << to_string(level::fatal) << "] " << suite_name << ": message_5" << std::endl;

        TEST_ASSERT(log_test.str() == log_stream.str(), "Log messages are not correct.");
    }

    static const char* suite_name;
};

const char* logger_interface_test::suite_name = "logger_test";

int main()
{
    return run_tests(logger_interface_test());
}
