#include <common/utils.hpp>
#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <sstream>
#include <string>
#include <unit_test/suite.hpp>

using namespace framework::log;

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
        set_logger(std::make_unique<stream_logger>(log_stream));

        debug(suite_name) << "message_1" << std::endl;
        info(suite_name) << "message_2" << std::endl;
        warning(suite_name) << "message_3" << std::endl;
        error(suite_name) << "message_4" << std::endl;
        fatal(suite_name) << "message_5" << std::endl;

        std::stringstream log_test;

        if (framework::utils::is_debug()) {
            log_test << "[" << severity_level::debug << "] " << suite_name << ": message_1" << std::endl;
        }

        log_test << "[" << severity_level::info << "] " << suite_name << ": message_2" << std::endl;
        log_test << "[" << severity_level::warning << "] " << suite_name << ": message_3" << std::endl;
        log_test << "[" << severity_level::error << "] " << suite_name << ": message_4" << std::endl;
        log_test << "[" << severity_level::fatal << "] " << suite_name << ": message_5" << std::endl;

        TEST_ASSERT(log_test.str() == log_stream.str(), "Log messages are not correct.");
    }

    static const char* suite_name;
};

const char* logger_interface_test::suite_name = "logger_test";

int main()
{
    return run_tests(logger_interface_test());
}
