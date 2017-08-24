#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <sstream>
#include <string>
#include <unit_test/suite.hpp>

using framework::logging::log;
using framework::logging::stream_logger;

std::string to_string(const framework::logging::logger::level level)
{
    using framework::logging::logger;
    switch (level) {
        case logger::level::debug: return "debug";
        case logger::level::info: return "info";
        case logger::level::warning: return "warning";
        case logger::level::error: return "error";
        case logger::level::fatal: return "fatal";
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
        add_test([this]() { assertion_test(); }, "assertion_test");
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

        using level = framework::logging::logger::level;

        std::stringstream log_test;
        log_test << "[" << to_string(level::debug) << "] " << suite_name << ": message_1" << std::endl;
        log_test << "[" << to_string(level::info) << "] " << suite_name << ": message_2" << std::endl;
        log_test << "[" << to_string(level::warning) << "] " << suite_name << ": message_3" << std::endl;
        log_test << "[" << to_string(level::error) << "] " << suite_name << ": message_4" << std::endl;
        log_test << "[" << to_string(level::fatal) << "] " << suite_name << ": message_5" << std::endl;

        TEST_ASSERT(log_test.str() == log_stream.str(), "Log messages are not correct.");
    }

    void assertion_test()
    {
        std::stringstream log_stream;
        log::set_logger(std::make_unique<stream_logger>(log_stream));

        ASSERT(0 != false);
        ASSERT_MSG(0 != false, "Test assert message.");

        using level = framework::logging::logger::level;

        std::stringstream log_test;
        log_test << "[" << to_string(level::error) << "] "
                 << "ASSERTION: " << __FILE__ << ":62: 0 != false" << std::endl;
        log_test << "[" << to_string(level::error) << "] "
                 << "ASSERTION: " << __FILE__ << ":63: \"Test assert message.\"" << std::endl;

        TEST_ASSERT(log_test.str() == log_stream.str(), "Log messages are not correct.");
    }

    static const char* suite_name;
};

const char* logger_interface_test::suite_name = "logger_test";

int main()
{
    return run_tests(logger_interface_test());
}
