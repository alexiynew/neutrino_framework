#include <log/log.hpp>
#include <string>
#include <unit_test/suite.hpp>
#include <vector>

// TODO Add test for assertions

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

class simple_logger : public framework::logging::logger
{
public:
    void add_message(const logger::level message_level, const std::string& tag, const std::string& message) override
    {
        m_messages.push_back(to_string(message_level) + "_" + tag + "_" + message);
    }

    bool are_messages_equal_to(const std::vector<std::string>& example) const
    {
        return m_messages == example;
    }

private:
    std::vector<std::string> m_messages;
};

class logger_interface_test : public framework::unit_test::suite
{
public:
    logger_interface_test()
        : suite(suite_name)
    {
        add_test([this]() { simple_logger_test(); }, "simple_logger_test");
    }

private:
    void simple_logger_test()
    {
        using framework::logging::log;

        log::set_logger(std::make_unique<simple_logger>());

        log::debug(suite_name, "message_1");
        log::info(suite_name, "message_2");
        log::warning(suite_name, "message_3");
        log::error(suite_name, "message_4");
        log::fatal(suite_name, "message_5");

        using level = framework::logging::logger::level;

        const std::vector<std::string> example{
        to_string(level::debug) + "_" + suite_name + "_message_1",
        to_string(level::info) + "_" + suite_name + "_message_2",
        to_string(level::warning) + "_" + suite_name + "_message_3",
        to_string(level::error) + "_" + suite_name + "_message_4",
        to_string(level::fatal) + "_" + suite_name + "_message_5",
        };

        const simple_logger* logger = static_cast<simple_logger*>(log::get_logger());

        TEST_ASSERT(logger->are_messages_equal_to(example), "Log messages are not correct.");
    }

    static const char* suite_name;
};

const char* logger_interface_test::suite_name = "logger_interface_test";

int main()
{
    return run_tests(logger_interface_test());
}
