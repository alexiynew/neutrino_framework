/// @file
/// @brief Declaration of logger base class.
/// @author Fedorov Alexey
/// @date 31.07.2018

#ifndef FRAMEWORK_LOG_LOGGER_HPP
#define FRAMEWORK_LOG_LOGGER_HPP

#include <memory>
#include <string>

namespace framework
{
namespace log
{
/// @addtogroup log_logger
/// @{

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
    virtual void add_message(severity_level level, const std::string& tag, const std::string& message) = 0;
};

/// @brief Helper function to print severity level name into the stream.
///
/// @param os Output stream.
/// @param level Severity level to print.
///
/// @return Standard output stream.
template <typename T>
inline T& operator<<(T& os, severity_level level)
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
/// @}

} // namespace log

} // namespace framework

#endif
