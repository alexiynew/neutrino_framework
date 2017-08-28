#include <log/log.hpp>
#include <shared_lib/shared_lib.hpp>

void shared_lib::do_log()
{
    ::framework::logging::log::info("shared_lib", "do_log");
}
