/// @file
/// @brief Declaration of logger interface and basic implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_LOG_LOG_HPP
#define FRAMEWORK_LOG_LOG_HPP

#include <memory>
#include <string>

#include <log/log_details.hpp>
#include <log/logger.hpp>

/// @details
///
/// The @ref log_module module provides a simple logging utility that you can use to output messages.@n
/// The messages have associated `::framework::log::severity_level` that indicate their importance@n
/// and @b tags that indicate their domain.
///
/// To log message use one of the @ref log_interface_functions.@n
/// This functions returns a temporary object that behaves just as the std::ostream.@n
/// @code
/// log::debug("log_tag") << "message_1" << std::endl;
/// log::info("log_tag") << "message_2" << std::endl;
/// log::warning("log_tag") << "message_3" << std::endl;
/// @endcode
///
/// By default there is no logger implementation, so no messages would be logged.@n
/// You need to set logger by calling `::framework::log::set_logger` function.@n
/// Provided logger should be derived from the `::framework::log::logger_base` class.@n
/// @code
/// class my_logger : public logger_base
/// {
///     void add_message(::framework::log::severity_level level,
///                      const std::string& tag,
///                      const std::string& message) override
///     {
///         // implementation
///     }
/// };
///
/// set_logger(std::make_unique<my_logger>());
/// @endcode
///
/// The @ref log_module module provides an implementation of logger: `::framework::log::stream_logger`@n
/// that can output messages to any output stream.@n
/// @code
/// std::stringstream log_stream;
/// set_logger(std::make_unique<stream_logger>(log_stream));
/// @endcode
///
/// @defgroup log_module Logging
/// @{

/// @defgroup log_interface_functions Interface functions

/// @defgroup log_logger Logger implementation

/// @brief Contains classes related to logging.
namespace framework::log
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

} // namespace framework::log

/// @}

#endif
