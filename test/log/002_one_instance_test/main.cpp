#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <shared_lib/shared_lib.hpp>
#include <sstream>
#include <static_lib/static_lib.hpp>
#include <unit_test/suite.hpp>

using framework::logging::log;
using framework::logging::stream_logger;

class one_instance_test : public framework::unit_test::suite
{
public:
    one_instance_test()
        : suite("one_instance_test")
    {
        add_test([this]() { logger_test(); }, "logger_test");
    }

private:
    void logger_test()
    {
        const std::string test = "[info] one_instance: start\n[info] static_lib: do_log\n[info] shared_lib: do_log\n";

        std::stringstream output;

        log::set_logger(std::make_unique<stream_logger>(output));

        log::info("one_instance", "start");

        static_lib().do_log();

        shared_lib().do_log();

        TEST_ASSERT(output.str() == test, "Log is wrong.");
    }
};

int main()
{
    return run_tests(one_instance_test());
}
