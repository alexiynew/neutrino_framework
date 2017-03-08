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

class log
{
public:
    static void debug(const std::string& tag, const std::string& message);
    static void info(const std::string& tag, const std::string& message);
    static void warning(const std::string& tag, const std::string& message);
    static void error(const std::string& tag, const std::string& message);

    static void set_logger(std::unique_ptr<logger_implementation> impl);
    static logger_implementation* get_logger();

private:

    static std::unique_ptr<logger_implementation> m_impl;
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

inline void log::set_logger(std::unique_ptr<logger_implementation> impl)
{
    m_impl = std::move(impl);
}

inline logger_implementation* log::get_logger()
{
    if (!m_impl) {
        m_impl.reset(new logger_implementation());
    }

    return m_impl.get();
}


} // namespace logger

/**
 * @}
 */

} // namespace framework



#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif

#ifdef NEED_ASSERT

#define ASSERT(EXPR) \
    ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (#EXPR) << std::endl))

#define ASSERT_MSG(EXPR, MSG) \
    ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl))

#else

#define ASSERT(EXPR)

#define ASSERT_MSG(EXPR, MSG)

#endif

#undef NEED_ASSERT

#endif
