/// @file
/// @brief Declaration of logger interface and basic implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#ifndef FRAMEWORK_LOG_LOG_HPP
#define FRAMEWORK_LOG_LOG_HPP

#include <memory>
#include <string>

#include <log/log_details.hpp>

namespace framework {

/// @defgroup log_module Logging
/// @{

/// @brief Contains classes related to logging.
namespace log {

using log_details::log_ostream;

/// @brief Severity level of log message.
enum class severity_level
{
    debug,   ///< Low-level information for developers.
    info,    ///< Generic information about system operation.
    warning, ///< A warning.
    error,   ///< A handleable error condition.
    fatal    ///< An unhandleable error that results in a program crash.
};

/// @brief Base class for logger implementations.
///
/// Describes logger implementation methods.
class logger_base
{
public:
    virtual ~logger_base() = default;

    /// @brief Add message to the log.
    ///
    /// In base implementation, does nothing
    ///
    /// @param level The message @ref severity_level
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    virtual void add_message(const severity_level level, const std::string& tag, const std::string& message) = 0;
};

/// @brief Logs messages for debugging purposes.
///
/// @param tag Message tag.
///
/// @return Output stream to log debug messages.
///
/// @see logger_base::add_message
log_ostream debug(const std::string& tag);

/// @brief Logs information messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log info messages.
///
/// @see logger_base::add_message
log_ostream info(const std::string& tag);

/// @brief Logs warning messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log warning messages.
///
/// @see logger_base::add_message
log_ostream warning(const std::string& tag);

/// @brief Logs error messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log error messages.
///
/// @see logger_base::add_message
log_ostream error(const std::string& tag);

/// @brief Logs fatal error messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log fatal error messages.
///
/// @see logger_base::add_message
log_ostream fatal(const std::string& tag);

/// @brief Sets new logger.
///
/// @param implementation Pointer to a new logger.
void set_logger(std::unique_ptr<logger_base> implementation);

/// @brief Returns current logger instance.
///
/// @return Pointer to current logger instance or base logger if no logger is set.
std::unique_ptr<logger_base>& logger();

/// @brief Helper function to print severity level name into the stream.
///
/// @param os Output stream.
/// @param level Severity level to print.
///
/// @return Standard output stream.
std::ostream& operator<<(std::ostream& os, const severity_level level);

} // namespace log

/// @}

} // namespace framework

#endif
