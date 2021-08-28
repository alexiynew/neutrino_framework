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

#ifndef FRAMEWORK_LOG_STREAM_LOGGER_HPP
#define FRAMEWORK_LOG_STREAM_LOGGER_HPP

#include <mutex>
#include <ostream>

#include <log/logger.hpp>

namespace framework::log
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup log_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints all messages to provided stream.
////////////////////////////////////////////////////////////////////////////////
class StreamLogger : public Logger
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates stream logger.
    ///
    /// @param stream Output stream.
    ////////////////////////////////////////////////////////////////////////////
    explicit StreamLogger(std::ostream& stream);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Prints message to the stream.
    ///
    /// @param level The message @ref SeverityLevel
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    ////////////////////////////////////////////////////////////////////////////
    void add_message(SeverityLevel level, const std::string& tag, const std::string& message) override;

private:
    std::ostream& m_output;
    std::mutex m_output_mutex;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::log

#endif
