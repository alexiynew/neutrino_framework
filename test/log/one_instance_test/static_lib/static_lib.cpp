#include <logger/log.hpp>
#include <static_lib/static_lib.hpp>

void static_lib::do_log()
{
    ::framework::logger::log::info("static_lib", "do_log");
}
