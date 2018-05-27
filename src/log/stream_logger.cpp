/// @file
/// @brief Stream logger implementation.
/// @author Fedorov Alexey
/// @date 24.08.2017

#include <log/stream_logger.hpp>

namespace framework {

namespace log {

std::unique_ptr<logger_base>& logger_instance()
{
    static std::unique_ptr<logger_base> instance;
    return instance;
}

stream_logger::stream_logger(std::ostream& stream) : m_output(stream)
{}

void stream_logger::add_message(const severity_level level, const std::string& tag, const std::string& message)
{
    m_output << "[" << level << "] " << tag << ": " << message;
}

} // namespace log

} // namespace framework
