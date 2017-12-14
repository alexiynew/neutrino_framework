/// @file
/// @brief Implementation of logger that prints all messages to stream.
/// @author Fedorov Alexey
/// @date 24.08.2017

#ifndef FRAMEWORK_LOG_COUT_LOGGER_HPP
#define FRAMEWORK_LOG_COUT_LOGGER_HPP

#include <logger/log.hpp>
#include <ostream>

namespace framework {

namespace logger {

/// @brief Prints all messages to provided stream.
class stream_logger : public default_logger
{
public:
    /// @brief Creates stream logger.
    ///
    /// @param stream Output stream.
    stream_logger(std::ostream& stream);

    /// @brief Prints message to the stream.
    ///
    /// @param level The message @ref level
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    void add_message(const severity_level level, const std::string& tag, const std::string& message) override;

private:
    std::ostream& m_output;
};
} // namespace logger

} // namespace framework

#endif
