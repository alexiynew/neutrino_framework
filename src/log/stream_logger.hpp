/// @file
/// @brief Implementation of logger that prints all messages to stream.
/// @author Fedorov Alexey
/// @date 24.08.2017

#ifndef FRAMEWORK_LOG_STREAM_LOGGER_HPP
#define FRAMEWORK_LOG_STREAM_LOGGER_HPP

#include <mutex>
#include <ostream>

#include <log/log.hpp>

namespace framework {

/// @addtogroup log_module
/// @{

namespace log {

std::unique_ptr<logger_base>& logger_instance();

/// @brief Prints all messages to provided stream.
class stream_logger : public logger_base
{
public:
    /// @brief Creates stream logger.
    ///
    /// @param stream Output stream.
    explicit stream_logger(std::ostream& stream);

    /// @brief Prints message to the stream.
    ///
    /// @param level The message @ref severity_level
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    void add_message(severity_level level, const std::string& tag, const std::string& message) override;

private:
    std::ostream& m_output;
    std::mutex m_output_mutex;
};

/// @}

} // namespace log

} // namespace framework

#endif
