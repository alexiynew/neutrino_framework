#include <static_lib/static_lib.hpp>

#include <log/log.hpp>

void static_lib::do_log()
{
    ::framework::log::info("static_lib") << "do_log" << std::endl;
}
