/// @file
/// @brief Logger implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#include <common/utils.hpp>
#include <log/log.hpp>

using namespace framework::log;
using namespace framework::log::log_details;

namespace framework
{
namespace log
{
class dummy_logger : public logger_base
{
    void add_message(const severity_level, const std::string&, const std::string&) override
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
    ::logger() = std::move(implementation);
}

std::unique_ptr<logger_base>& logger()
{
    static std::unique_ptr<logger_base> instance;

    if (!instance) {
        instance.reset(new dummy_logger());
    }

    return instance;
}

std::ostream& operator<<(std::ostream& os, const severity_level level)
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
