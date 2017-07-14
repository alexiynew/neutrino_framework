/// @file
/// @brief Declaration of logger interface and basic implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#ifndef FRAMEWORK_LOG_HPP
#define FRAMEWORK_LOG_HPP

#include <memory>
#include <string>

namespace framework {

/// @defgroup logging_module Logger module
/// @{

/// @brief Contains classes related to logging.
namespace logging {

class logger;

#pragma mark - log class

/// @brief Logger interface.
///
/// This is facade for @ref logger.
/// It holds current logger instance, and provides interface to use it.
class log
{
public:
    log(const log&) = delete;
    log(log&&)      = default;

    log& operator=(const log&) = delete;
    log& operator=(log&&) = default;

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

#pragma mark - base logger class

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

} // namespace logger

/// @def NEED_ASSERT
/// @brief Indicates that its need to define assert macros.

#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif

#ifdef NEED_ASSERT

/// @brief @ref STRINGIZE implementation details.
#define STRINGIZE_DETAIL(x) #x

/// @brief Turns parameter into string.
#define STRINGIZE(x) STRINGIZE_DETAIL(x)

/// @brief Generates error message.
#define ERROR_MESSAGE(MESSAGE) __FILE__ ":" STRINGIZE(__LINE__) ": " STRINGIZE(MESSAGE)

/// @brief Prints error message if EXPRESSION evaluates to @b false.
#define ASSERT(EXPRESSION) \
    ((EXPRESSION) || (::framework::logging::log::error("ASSERTION", ERROR_MESSAGE(EXPRESSION)), false))

/// @brief Prints provided MESSAGE as error if EXPRESSION evaluates to @b false.
#define ASSERT_MSG(EXPRESSION, MESSAGE) \
    ((EXPRESSION) || (::framework::logging::log::error("ASSERTION", ERROR_MESSAGE(MESSAGE)), false))

#else

#define ASSERT(EXPR)

#define ASSERT_MSG(EXPR, MSG)

#endif

#undef NEED_ASSERT

/// @}

} // namespace framework

#endif
