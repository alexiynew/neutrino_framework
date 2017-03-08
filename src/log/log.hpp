/**
 * @file log.hpp
 * @brief Declaration of logger interface and basic implementation.
 * @author Fedorov Alexey
 * @date 08.03.2017
 */

#ifndef FRAMEWORK_LOG_HPP
#define FRAMEWORK_LOG_HPP
// TODO realize logger interface
#include <iostream>
#include <memory>
#include <string>

namespace framework {

/**
 * @defgroup logger_module Logger module
 * @{
 */

/**
 * @brief Contains classes related to logger.
 */
namespace logger {

class logger_implementation;

#pragma mark - log class

/**
 * @brief Logger functions.
 *
 * Class holds logger implementation. And uses it.
 */
class log
{
public:
    /*
     * @brief Logs messages for debugging purposes.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     *
     * @note Works only in debug mode.
     */
    static void debug(const std::string& tag, const std::string& message);

    /*
     * @brief Logs information messages.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     */
    static void info(const std::string& tag, const std::string& message);

    /*
     * @brief Logs warning messages.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     */
    static void warning(const std::string& tag, const std::string& message);

    /*
     * @brief Logs error messages.
     *
     * @param tag Message tag.
     * @param message Message for logging.
     */
    static void error(const std::string& tag, const std::string& message);

    static void set_logger(std::unique_ptr<logger_implementation> implementation);
    static logger_implementation* get_logger();

private:
    static std::unique_ptr<logger_implementation> m_logger;
};

#pragma mark - base logger_implementation class

class logger_implementation
{
public:
    virtual void add_message(const std::string& tag, const std::string& message);
};

#pragma mark - implementation of logger_implementation class

inline void logger_implementation::add_message(const std::string&, const std::string&)
{
}

#pragma mark - implementation of log class

inline void log::debug(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(tag, message);
}

inline void log::info(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(tag, message);
}

inline void log::warning(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(tag, message);
}

inline void log::error(const std::string& tag, const std::string& message)
{
    get_logger()->add_message(tag, message);
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

#define ASSERT(EXPR) \
    ((EXPR) || (log::error("ASSERTION", __FILE__ ":" STRINGIZE(__LINE__) ": " STRINGIZE(EXPR)))

#define ASSERT_MSG(EXPR, MESSAGE) \
    ((EXPR) || (log::error("ASSERTION", __FILE__ ":" STRINGIZE(__LINE__) ": " STRINGIZE(MESSAGE)))

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
