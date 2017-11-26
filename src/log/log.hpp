/// @file
/// @brief Declaration of logger interface and basic implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#ifndef FRAMEWORK_LOG_LOG_HPP
#define FRAMEWORK_LOG_LOG_HPP

#include <memory>
#include <string>

namespace framework {

/// @defgroup logging_module Logger module
/// @{

/// @brief Contains classes related to logging.
namespace logging {

class logger;

/// @brief Logger interface.
///
/// This is facade for @ref logger.
/// It holds current logger instance, and provides interface to use it.
class log
{
public:
    log(const log&) = delete;  ///< No copy constructor.
    log(log&&)      = default; ///< Default move constructor.

    log& operator=(const log&) = delete; ///< No copy assignment.
    log& operator=(log&&) = default;     ///< Default move assignment.

    ~log() = default;

    /// @brief Logs messages for debugging purposes.
    ///
    /// @param tag Message tag.
    /// @param message Message for logging.
    ///
    /// @note Works only in debug mode.
    ///
    /// @see logger::add_message
    static void debug(const std::string& tag, const std::string& message);

    /// @brief Logs information messages.
    ///
    /// @param tag Message tag.
    /// @param message Message for logging.
    ///
    /// @see logger::add_message
    static void info(const std::string& tag, const std::string& message);

    /// @brief Logs warning messages.
    ///
    /// @param tag Message tag.
    /// @param message Message for logging.
    ///
    /// @see logger::add_message
    static void warning(const std::string& tag, const std::string& message);

    /// @brief Logs error messages.
    ///
    /// @param tag Message tag.
    /// @param message Message for logging.
    ///
    /// @see logger::add_message
    static void error(const std::string& tag, const std::string& message);

    /// @brief Logs fatal error messages.
    ///
    /// @param tag Message tag.
    /// @param message Message for logging.
    ///
    /// @see logger::add_message
    static void fatal(const std::string& tag, const std::string& message);

    /// @brief Set provided class as logger.
    ///
    /// @param implementation Pointer to new logger.
    static void set_logger(std::unique_ptr<logger> implementation);

    /// @brief Returns current logger instance.
    ///
    /// @return Pointer to current logger instance or base logger implementation if no logger is set.
    static logger* get_logger();

private:
    log();

    static log& instance();

    std::unique_ptr<logger> m_logger;
};

/// @brief Base class for logger implementations.
///
/// Describes logger implementation methods.
class logger
{
public:
    /// @brief Level of log message.
    enum class level
    {
        debug,   ///< Low-level information for developers.
        info,    ///< Generic information about system operation.
        warning, ///< A warning.
        error,   ///< A handleable error condition.
        fatal    ///< An unhandleable error that results in a program crash.
    };

    virtual ~logger() = default;

    /// @brief Add message to the log.
    ///
    /// In base implementation, does nothing
    ///
    /// @param level The message @ref level
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    virtual void add_message(const logger::level level, const std::string& tag, const std::string& message);
};

} // namespace logging

/// @}

} // namespace framework

#endif
