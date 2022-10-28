#ifndef LOG_LOGGER_HPP
#define LOG_LOGGER_HPP

#include <memory>
#include <string>

namespace framework::log
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup log_module
/// @{
///
/// @name Logger implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Severity level of log message.
enum class SeverityLevel
{
    debug,   ///< Low-level information for developers.
    info,    ///< Generic information about system operation.
    warning, ///< A warning.
    error,   ///< A handleable error condition.
    fatal,   ///< An unhandleable error that results in a program crash.
};

/// @brief Base class for logger implementations.
///
/// Describes logger implementation methods.
class Logger
{
public:
    /// @brief Deafault constructor.
    Logger() = default;

    /// @brief Deafault copy constructor.
    Logger(const Logger&) = default;

    /// @brief Deafault move constructor.
    Logger(Logger&&) = default;

    /// @brief Deafault copy assignment operator.
    ///
    /// @return Reference to copied object.
    Logger& operator=(const Logger&) = default;

    /// @brief Deafault move assignment operator.
    ///
    /// @return Reference to moved object.
    Logger& operator=(Logger&&) = default;

    virtual ~Logger() = default;

    /// @brief Add message to the log.
    ///
    /// In base implementation, does nothing
    ///
    /// @param level The message @ref SeverityLevel
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    virtual void add_message(SeverityLevel level, const std::string& tag, const std::string& message) = 0;
};

/// @brief Helper function to print severity level name into the stream.
///
/// @param ostream Output stream.
/// @param level Severity level to print.
///
/// @return Standard output stream.
template <typename T>
inline T& operator<<(T& ostream, SeverityLevel level)
{
    switch (level) {
        case SeverityLevel::debug: ostream << "debug"; break;
        case SeverityLevel::info: ostream << "info"; break;
        case SeverityLevel::warning: ostream << "warning"; break;
        case SeverityLevel::error: ostream << "error"; break;
        case SeverityLevel::fatal: ostream << "fatal"; break;
    }

    return ostream;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
///
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::log

#endif
