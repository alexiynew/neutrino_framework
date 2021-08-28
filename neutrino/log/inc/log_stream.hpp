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

#ifndef FRAMEWORK_LOG_INC_LOG_STREAM_HPP
#define FRAMEWORK_LOG_INC_LOG_STREAM_HPP

#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace framework::log
{
enum class SeverityLevel;
}

namespace framework::log::log_details
{

////////////////////////////////////////////////////////////////////////////////
/// @brief Custom stream buffer
////////////////////////////////////////////////////////////////////////////////
class LogBuffer : public std::streambuf
{
public:
    LogBuffer(SeverityLevel level, std::string tag);

    ~LogBuffer() override;

    LogBuffer(const LogBuffer&) = delete;
    LogBuffer& operator=(const LogBuffer&) = delete;

    LogBuffer(LogBuffer&& other) noexcept;
    LogBuffer& operator=(LogBuffer&& other) noexcept;

protected:
    int overflow(int character) override;
    int sync() override;

private:
    SeverityLevel m_level;
    std::string m_tag;
    std::vector<char_type> m_buffer;

    void reset_pointers();
    void flush_buffer();
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Custom output stream
////////////////////////////////////////////////////////////////////////////////
class LogStream : public std::ostream
{
public:
    explicit LogStream(std::unique_ptr<std::streambuf> buffer);

    ~LogStream() override;

    LogStream(const LogStream&) = delete;
    LogStream& operator=(const LogStream&) = delete;

    LogStream(LogStream&& other) noexcept;
    LogStream& operator=(LogStream&& other) noexcept;

private:
    std::unique_ptr<std::streambuf> m_buffer;
};

} // namespace framework::log::log_details

#endif
