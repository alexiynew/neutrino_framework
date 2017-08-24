/// @file log.cpp
/// @brief Stream logger implementation.
/// @author Fedorov Alexey
/// @date 24.08.2017

#include <log/stream_logger.hpp>

namespace {

std::string to_string(const framework::logging::logger::level level)
{
    using framework::logging::logger;
    switch (level) {
        case logger::level::debug: return "debug";
        case logger::level::info: return "info";
        case logger::level::warning: return "warning";
        case logger::level::error: return "error";
        case logger::level::fatal: return "fatal";
        default: return "UNKNOWN";
    }
}
}

namespace framework {

namespace logging {

stream_logger::stream_logger(std::ostream& stream)
    : m_output(stream)
{
}

void stream_logger::add_message(const logger::level error_level, const std::string& tag, const std::string& message)
{
    m_output << "[" << to_string(error_level) << "] " << tag << ": " << message << std::endl;
}

} // namespace logging
} // namespace framework
