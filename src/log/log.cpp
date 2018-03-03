/// @file
/// @brief Logger implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#include <log/log.hpp>

namespace {
std::unique_ptr<::framework::log::default_logger> logger_instance;
}

namespace framework {

namespace log {

void default_logger::add_message(const severity_level, const std::string&, const std::string&)
{
    // nothing to do.
}

void debug(const std::string& tag, const std::string& message)
{
    logger()->add_message(severity_level::debug, tag, message);
}

void info(const std::string& tag, const std::string& message)
{
    logger()->add_message(severity_level::info, tag, message);
}

void warning(const std::string& tag, const std::string& message)
{
    logger()->add_message(severity_level::warning, tag, message);
}

void error(const std::string& tag, const std::string& message)
{
    logger()->add_message(severity_level::error, tag, message);
}

void fatal(const std::string& tag, const std::string& message)
{
    logger()->add_message(severity_level::fatal, tag, message);
}

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

} // namespace log

} // namespace framework
