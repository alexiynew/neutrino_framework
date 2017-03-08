#include <log/log.hpp>
#include <unit_test/suite.hpp>

#pragma mark - tests for logger

class basic_logger_test : public framework::unit_test::suite
{
public:
    basic_logger_test()
        : suite("basic_logger_test")
    {
        add_test([this]() { first_test(); }, "first_test");
    }

private:
    void first_test()
    {
        using framework::logger::log;

        log::set_logger(std::make_unique<framework::logger::logger_implementation>());

        log::debug("basic_logger_test", "debug message");
        log::info("basic_logger_test", "info message");
        log::warning("basic_logger_test", "warning message");
        log::error("basic_logger_test", "error message");

        TEST_FAIL("test");
    }
};

#pragma mark - main function

int main()
{
    return run_tests(basic_logger_test());
}
