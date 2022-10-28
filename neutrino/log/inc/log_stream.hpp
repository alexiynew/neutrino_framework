#ifndef LOG_INC_LOG_STREAM_HPP
#define LOG_INC_LOG_STREAM_HPP

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

class LogBuffer : public std::streambuf
{
public:
    LogBuffer(SeverityLevel level, std::string tag);

    ~LogBuffer() override;

    LogBuffer(const LogBuffer&)            = delete;
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

class LogStream : public std::ostream
{
public:
    explicit LogStream(std::unique_ptr<std::streambuf> buffer);

    ~LogStream() override;

    LogStream(const LogStream&)            = delete;
    LogStream& operator=(const LogStream&) = delete;

    LogStream(LogStream&& other) noexcept;
    LogStream& operator=(LogStream&& other) noexcept;

private:
    std::unique_ptr<std::streambuf> m_buffer;
};

} // namespace framework::log::log_details

#endif
