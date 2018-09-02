/// @file
/// @brief The realisation details of the logging system.
/// @author Fedorov Alexey
/// @date 03.03.2018

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

#include <log/log.hpp>
#include <log/log_details.hpp>

namespace
{
constexpr size_t log_buffer_size = 64;

} // namespace

namespace framework
{
namespace log
{
namespace log_details
{
#pragma region log_buffer

log_buffer::log_buffer(severity_level level, std::string tag)
    : m_level(level), m_tag(std::move(tag)), m_buffer(log_buffer_size)
{
    reset_pointers();
}

log_buffer::~log_buffer()
{
    flush_buffer();
}

log_buffer::log_buffer(log_buffer&& other) noexcept
    : std::streambuf(other), m_level(other.m_level), m_tag(std::move(other.m_tag)), m_buffer(std::move(other.m_buffer))
{}

log_buffer& log_buffer::operator=(log_buffer&& other) noexcept
{
    std::streambuf::operator=(other);

    m_level  = other.m_level;
    m_tag    = std::move(other.m_tag);
    m_buffer = std::move(other.m_buffer);

    return *this;
}

int log_buffer::overflow(int character)
{
    if (character == traits_type::eof()) {
        return traits_type::eof();
    }

    const size_t size = m_buffer.size();
    m_buffer.resize(size * 2);
    reset_pointers();
    pbump(static_cast<int>(size));

    return sputc(static_cast<char>(character));
}

int log_buffer::sync()
{
    flush_buffer();

    reset_pointers();

    return 0;
}

void log_buffer::reset_pointers()
{
    setp(m_buffer.data(), m_buffer.data() + m_buffer.size());
}

void log_buffer::flush_buffer()
{
    if (pptr() == pbase()) {
        return;
    }

    const auto size = static_cast<size_t>(pptr() - pbase());
    ::framework::log::logger()->add_message(m_level, m_tag, std::string(m_buffer.data(), size));
}

#pragma endregion

log_ostream::log_ostream(std::unique_ptr<std::streambuf> buffer)
    : std::ostream(buffer.get()), m_buffer(std::move(buffer))
{}

log_ostream::~log_ostream() = default;

log_ostream::log_ostream(log_ostream&& other) noexcept
    : std::ostream(other.m_buffer.get()), m_buffer(std::move(other.m_buffer))
{
    rdbuf(m_buffer.get());
}

log_ostream& log_ostream::operator=(log_ostream&& other) noexcept
{
    m_buffer = std::move(other.m_buffer);

    std::ostream::operator=(std::move(other));

    return *this;
}

} // namespace log_details

} // namespace log

} // namespace framework
