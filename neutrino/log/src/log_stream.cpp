#include <log/log.hpp>

#include <log/inc/log_stream.hpp>

namespace
{
constexpr size_t log_buffer_size = 64;
} // namespace

namespace framework::log::log_details
{
#pragma region LogBuffer

LogBuffer::LogBuffer(SeverityLevel level, std::string tag)
    : m_level(level)
    , m_tag(std::move(tag))
    , m_buffer(log_buffer_size)
{
    reset_pointers();
}

LogBuffer::~LogBuffer()
{
    flush_buffer();
}

LogBuffer::LogBuffer(LogBuffer&& other) noexcept
    : std::streambuf(other)
    , m_level(other.m_level)
    , m_tag(std::move(other.m_tag))
    , m_buffer(std::move(other.m_buffer))
{}

LogBuffer& LogBuffer::operator=(LogBuffer&& other) noexcept
{
    std::streambuf::operator=(other);

    m_level  = other.m_level;
    m_tag    = std::move(other.m_tag);
    m_buffer = std::move(other.m_buffer);

    return *this;
}

int LogBuffer::overflow(int character)
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

int LogBuffer::sync()
{
    flush_buffer();

    reset_pointers();

    return 0;
}

void LogBuffer::reset_pointers()
{
    setp(m_buffer.data(), m_buffer.data() + m_buffer.size());
}

void LogBuffer::flush_buffer()
{
    if (pptr() == pbase()) {
        return;
    }

    const auto size = static_cast<size_t>(pptr() - pbase());
    std::string str(m_buffer.data(), size);

    if (str.back() != '\n') {
        str += '\n';
    }

    framework::log::logger()->add_message(m_level, m_tag, str);
}

#pragma endregion

LogStream::LogStream(std::unique_ptr<std::streambuf> buffer)
    : std::ostream(buffer.get())
    , m_buffer(std::move(buffer))
{}

LogStream::~LogStream() = default;

LogStream::LogStream(LogStream&& other) noexcept
    : std::ostream(other.m_buffer.get())
    , m_buffer(std::move(other.m_buffer))
{
    rdbuf(m_buffer.get());
}

LogStream& LogStream::operator=(LogStream&& other) noexcept
{
    m_buffer = std::move(other.m_buffer);

    std::ostream::operator=(std::move(other));

    return *this;
}

} // namespace framework::log::log_details
