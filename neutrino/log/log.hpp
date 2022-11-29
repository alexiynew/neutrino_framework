#ifndef LOG_LOG_HPP
#define LOG_LOG_HPP

#include <memory>
#include <string>

#include <common/global_defines.hpp>
#include <log/logger.hpp>

#include <log/inc/log_stream.hpp>

namespace neutrino::log
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup log_module
/// @{
///
/// @name Interface functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Logs messages for debugging purposes.
///
/// @param tag Message tag.
///
/// @return Output stream to log debug messages.
///
/// @see Logger::add_message
LIBRARY_API log_details::LogStream debug(const std::string& tag);

/// @brief Logs information messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log info messages.
///
/// @see Logger::add_message
LIBRARY_API log_details::LogStream info(const std::string& tag);

/// @brief Logs warning messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log warning messages.
///
/// @see Logger::add_message
LIBRARY_API log_details::LogStream warning(const std::string& tag);

/// @brief Logs error messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log error messages.
///
/// @see Logger::add_message
LIBRARY_API log_details::LogStream error(const std::string& tag);

/// @brief Logs fatal error messages.
///
/// @param tag Message tag.
///
/// @return Output stream to log fatal error messages.
///
/// @see Logger::add_message
LIBRARY_API log_details::LogStream fatal(const std::string& tag);

/// @brief Sets new logger.
///
/// @param implementation Pointer to a new logger.
///
/// @see Logger
LIBRARY_API void set_logger(std::unique_ptr<Logger> implementation);

/// @brief Returns current logger instance.
///
/// @return Pointer to current logger instance.
///
/// @see Logger
LIBRARY_API Logger* logger();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
///
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::log

#endif
