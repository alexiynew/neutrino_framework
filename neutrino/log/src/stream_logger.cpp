#include <log/stream_logger.hpp>

namespace neutrino::log
{
StreamLogger::StreamLogger(std::ostream& stream)
    : m_output(stream)
{}

void StreamLogger::add_message(SeverityLevel level, const std::string& tag, const std::string& message)
{
    std::lock_guard<std::mutex> lock(m_output_mutex);

    m_output << "[" << level << "] " << tag << ": " << message;
    m_output.flush();
}

} // namespace neutrino::log
