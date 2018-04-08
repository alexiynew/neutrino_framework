/// @file log.cpp
/// @brief Logger implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#include <logger/log.hpp>

namespace framework {

namespace logger {

void default_logger::add_message(const severity_level, const std::string&, const std::string&)
{
    // nothing to do.
}

log::log() : m_logger(nullptr)
{}

log& log::instance()
{
    static log log_instance;
    return log_instance;
}

void log::debug(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(severity_level::debug, tag, message);
}

void log::info(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(severity_level::info, tag, message);
}

void log::warning(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(severity_level::warning, tag, message);
}

void log::error(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(severity_level::error, tag, message);
}

void log::fatal(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(severity_level::fatal, tag, message);
}

void log::set_logger(std::unique_ptr<default_logger> implementation)
{
    instance().m_logger = std::move(implementation);
}

default_logger* log::get_logger()
{
    if (!instance().m_logger) {
        instance().m_logger.reset(new default_logger());
    }

    return instance().m_logger.get();
}

} // namespace logger

} // namespace framework
