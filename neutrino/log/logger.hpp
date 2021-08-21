/// @file
/// @brief Declaration of logger base class.
/// @author Fedorov Alexey
/// @date 31.07.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#ifndef FRAMEWORK_LOG_LOGGER_HPP
#define FRAMEWORK_LOG_LOGGER_HPP

#include <memory>
#include <string>

namespace framework::log
{
/// @addtogroup log_module
/// @{

/// @name Logger implementation
/// @{

/// @brief Severity level of log message.
///
/// @detail
/// TODO: How to extend logger.
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
    /// @brief Deafault constructor.
    logger_base() = default;

    /// @brief Deafault copy constructor.
    logger_base(const logger_base&) = default;

    /// @brief Deafault move constructor.
    logger_base(logger_base&&) = default;

    /// @brief Deafault copy assignment operator.
    ///
    /// @return Reference to copied object.
    logger_base& operator=(const logger_base&) = default;

    /// @brief Deafault move assignment operator.
    ///
    /// @return Reference to moved object.
    logger_base& operator=(logger_base&&) = default;

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
/// @param ostream Output stream.
/// @param level Severity level to print.
///
/// @return Standard output stream.
template <typename T>
inline T& operator<<(T& ostream, severity_level level)
{
    switch (level) {
        case severity_level::debug: ostream << "debug"; break;
        case severity_level::info: ostream << "info"; break;
        case severity_level::warning: ostream << "warning"; break;
        case severity_level::error: ostream << "error"; break;
        case severity_level::fatal: ostream << "fatal"; break;
    }

    return ostream;
}
/// @}

/// @}

} // namespace framework::log

#endif
