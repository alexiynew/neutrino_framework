/// @file
/// @brief Logger implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#include <common/utils.hpp>
#include <log/log.hpp>

using log_ostream = framework::log::log_details::log_ostream;
using log_buffer  = framework::log::log_details::log_buffer;

namespace framework
{
namespace log
{
class dummy_logger : public logger_base
{
    void add_message(severity_level /*level*/, const std::string& /*tag*/, const std::string& /*message*/) override
    {
        // nothing to do.
    }
};

#pragma region log functions

log_ostream debug(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::debug, tag));
}

log_ostream info(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::info, tag));
}

log_ostream warning(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::warning, tag));
}

log_ostream error(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::error, tag));
}

log_ostream fatal(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::fatal, tag));
}

#pragma endregion

void set_logger(std::unique_ptr<logger_base> implementation)
{
    ::framework::log::logger() = std::move(implementation);
}

std::unique_ptr<logger_base>& logger()
{
    static std::unique_ptr<logger_base> instance;

    if (!instance) {
        instance = std::make_unique<dummy_logger>();
    }

    return instance;
}

std::ostream& operator<<(std::ostream& os, severity_level level)
{
    switch (level) {
        case severity_level::debug: os << "debug"; break;
        case severity_level::info: os << "info"; break;
        case severity_level::warning: os << "warning"; break;
        case severity_level::error: os << "error"; break;
        case severity_level::fatal: os << "fatal"; break;
    }

    return os;
}

} // namespace log

} // namespace framework
