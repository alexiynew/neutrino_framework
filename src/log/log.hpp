/**
 * @file log.hpp
 * @brief Declaration of logger interface and basic implementation.
 * @author Fedorov Alexey
 * @date 08.03.2017
 */

#ifndef FRAMEWORK_LOG_HPP
#define FRAMEWORK_LOG_HPP

#include <iostream>
#include <memory>
#include <string>

namespace framework {

/**
 * @defgroup logger_module Logger module
 * @{
 */

/**
 * @brief Contains classes related to logging.
 */
namespace logger {

class logger_implementation;

#pragma mark - log class

/**
 * @brief Logger interface.
 *
 * This is facade for logger_implementation.
 * It holds current logger instance, and provides interface to use it.
 */
class log
{
public:
    /**
     * @brief Logs messages for debugging purposes.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     *
     * @note Works only in debug mode.
     *
     * @see logger_implementation::add_message
     */
    static void debug(const std::string& tag, const std::string& message);

    /**
     * @brief Logs information messages.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     *
     * @see logger_implementation::add_message
     */
    static void info(const std::string& tag, const std::string& message);

    /**
     * @brief Logs warning messages.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     *
     * @see logger_implementation::add_message
     */
    static void warning(const std::string& tag, const std::string& message);

    /**
     * @brief Logs error messages.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     *
     * @see logger_implementation::add_message
     */
    static void error(const std::string& tag, const std::string& message);

    /**
     * @brief Set provided class as logger.
     *
     * @param implementation Pointer to new logger.
     */
    static void set_logger(std::unique_ptr<logger_implementation> implementation);

    /**
     * @brief Returns current logger instance.
     *
     * @return Pointer to current logger instance or base logger_implementation if no logger is set.
     */
    static logger_implementation* get_logger();

private:
    static std::unique_ptr<logger_implementation> m_logger;
};

#pragma mark - base logger_implementation class

/**
 * @brief Base class for logger implementations.
 *
 * Describes logger implementation methods.
 */
class logger_implementation
{
public:
    /**
     * @brief Level of log message.
     */
    enum class level
    {
        debug,
        info,
        warning,
        error
    };

    virtual ~logger_implementation();

    /**
     * @brief Add message to the log.
     *
     * @param level The message @ref level
     * @param tag Message tag. Describes message domain.
     * @param message Message itself.
     */
    virtual void add_message(const logger_implementation::level level, const std::string& tag, const std::string& message);
};

#pragma mark - implementation of logger_implementation class

inline void logger_implementation::add_message(const logger_implementation::level, const std::string&, const std::string&)
{
    // nothing to do.
}

inline logger_implementation::~logger_implementation()
{
    // nothing to do.
}

#pragma mark - implementation of log class

inline void log::debug(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(logger_implementation::level::debug, tag, message);
}

inline void log::info(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(logger_implementation::level::info, tag, message);
}

inline void log::warning(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(logger_implementation::level::warning, tag, message);
}

inline void log::error(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(logger_implementation::level::error, tag, message);
}

inline void log::set_logger(std::unique_ptr<logger_implementation> implementation)
{
    m_logger = std::move(implementation);
}

inline logger_implementation* log::get_logger()
{
    if (!m_logger) {
        m_logger.reset(new logger_implementation());
    }

    return m_logger.get();
}

} // namespace logger

#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif

#ifdef NEED_ASSERT

#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)

/**
 * @brief Prints error message if EXPRESSION evaluates to @b false.
 */
#define ASSERT(EXPRESSION) \
    ((EXPRESSION) ||       \
     (::framework::logger::log::error("ASSERTION", __FILE__ ":" STRINGIZE(__LINE__) ": " STRINGIZE(EXPR)), false))

/**
 * @brief Prints provided MESSAGE as error if EXPRESSION evaluates to @b false.
 */
#define ASSERT_MSG(EXPRESSION, MESSAGE) \
    ((EXPRESSION) ||                    \
     (::framework::logger::log::error("ASSERTION", __FILE__ ":" STRINGIZE(__LINE__) ": " STRINGIZE(MESSAGE)), false))

#else

#define ASSERT(EXPR)

#define ASSERT_MSG(EXPR, MSG)

#endif

#undef NEED_ASSERT

/**
 * @}
 */

} // namespace framework

#endif
