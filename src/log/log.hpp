/// @file
/// @brief Declaration of logger interface and basic implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

#ifndef FRAMEWORK_LOG_LOG_HPP
#define FRAMEWORK_LOG_LOG_HPP

#include <memory>
#include <string>

#include <log/log_details.hpp>
#include <log/logger.hpp>

namespace framework
{
/// @details
///
/// Deatiled description.
///
/// @defgroup log_module Logging
/// @{

/// @defgroup log_interface_functions Interface functions

/// @defgroup log_logger Logger implementation

/// @brief Contains classes related to logging.
namespace log
{
/// @addtogroup log_interface_functions
/// @{

/// @brief Logs messages for debugging purposes.
///
/// @param tag Message tag.
///
/// @return Output stream to log debug messages.
///
/// @see logger_base::add_message
log_details::log_ostream debug(const std::string& tag);

/// @brief Logs information messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log info messages.
///
/// @see logger_base::add_message
log_details::log_ostream info(const std::string& tag);

/// @brief Logs warning messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log warning messages.
///
/// @see logger_base::add_message
log_details::log_ostream warning(const std::string& tag);

/// @brief Logs error messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log error messages.
///
/// @see logger_base::add_message
log_details::log_ostream error(const std::string& tag);

/// @brief Logs fatal error messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log fatal error messages.
///
/// @see logger_base::add_message
log_details::log_ostream fatal(const std::string& tag);

/// @brief Sets new logger.
///
/// @param implementation Pointer to a new logger.
///
/// @see logger_base
void set_logger(std::unique_ptr<logger_base> implementation);

/// @brief Returns current logger instance.
///
/// @return Pointer to current logger instance or base logger if no logger is set.
///
/// @see logger_base
logger_base* logger();

/// @}

/// @}

} // namespace log

/// @}

} // namespace framework

#endif
