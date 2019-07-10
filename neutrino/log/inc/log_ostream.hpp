/// @file
/// @brief The realisation details of the logging system.
/// @author Fedorov Alexey
/// @date 03.03.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#ifndef FRAMEWORK_LOG_DETAILS_LOG_OSTREAM_HPP
#define FRAMEWORK_LOG_DETAILS_LOG_OSTREAM_HPP

#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace framework::log
{
enum class severity_level;
}

namespace framework::log::log_details
{
/// @brief Custom stream buffer
class log_buffer : public std::streambuf
{
public:
    log_buffer(severity_level level, std::string tag);

    ~log_buffer() override;

    log_buffer(const log_buffer&) = delete;
    log_buffer& operator=(const log_buffer&) = delete;

    log_buffer(log_buffer&& other) noexcept;
    log_buffer& operator=(log_buffer&& other) noexcept;

protected:
    int overflow(int character) override;
    int sync() override;

private:
    severity_level m_level;
    std::string m_tag;
    std::vector<char_type> m_buffer;

    void reset_pointers();
    void flush_buffer();
};

/// @brief Custom output stream
class log_ostream : public std::ostream
{
public:
    explicit log_ostream(std::unique_ptr<std::streambuf> buffer);

    ~log_ostream() override;

    log_ostream(const log_ostream&) = delete;
    log_ostream& operator=(const log_ostream&) = delete;

    log_ostream(log_ostream&& other) noexcept;
    log_ostream& operator=(log_ostream&& other) noexcept;

private:
    std::unique_ptr<std::streambuf> m_buffer;
};

} // namespace framework::log::log_details

#endif
