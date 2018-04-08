#include <shared_lib/shared_lib.hpp>

#include <log/log.hpp>

void shared_lib::do_log()
{
    ::framework::log::info("shared_lib") << "do_log" << std::endl;
}
