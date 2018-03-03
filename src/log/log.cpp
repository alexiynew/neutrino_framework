/// @file
/// @brief Logger implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#include <log/log.hpp>

namespace {

/// @brief Instance of current logger.
std::unique_ptr<::framework::log::default_logger> logger_instance;

} // namespace

namespace framework {

namespace log {

void default_logger::add_message(const severity_level, const std::string&, const std::string&)
{
    // nothing to do.
}

#pragma region log functions

log_ostream debug(const std::string& tag)
{
    return log_ostream(severity_level::debug, tag);
}

log_ostream info(const std::string& tag)
{
    return log_ostream(severity_level::info, tag);
}

log_ostream warning(const std::string& tag)
{
    return log_ostream(severity_level::warning, tag);
}

log_ostream error(const std::string& tag)
{
    return log_ostream(severity_level::error, tag);
}

log_ostream fatal(const std::string& tag)
{
    return log_ostream(severity_level::fatal, tag);
}

#pragma endregion

void set_logger(std::unique_ptr<default_logger> implementation)
{
    ::logger_instance = std::move(implementation);
}

default_logger* logger()
{
    if (!::logger_instance) {
        ::logger_instance.reset(new default_logger());
    }

    return ::logger_instance.get();
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
