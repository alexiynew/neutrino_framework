/// @file
/// @brief Stream logger implementation.
/// @author Fedorov Alexey
/// @date 24.08.2017

#include <log/stream_logger.hpp>

namespace {

std::string to_string(const framework::log::severity_level level)
{
    using severity_level = framework::log::severity_level;
    switch (level) {
        case severity_level::debug: return "debug";
        case severity_level::info: return "info";
        case severity_level::warning: return "warning";
        case severity_level::error: return "error";
        case severity_level::fatal: return "fatal";
        default: return "UNKNOWN";
    }
}
} // namespace

namespace framework {

namespace log {

stream_logger::stream_logger(std::ostream& stream)
    : m_output(stream)
{
}

void stream_logger::add_message(const severity_level level, const std::string& tag, const std::string& message)
{
    m_output << "[" << to_string(level) << "] " << tag << ": " << message << std::endl;
}

} // namespace log

} // namespace framework
