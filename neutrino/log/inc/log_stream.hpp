#ifndef LOG_INC_LOG_STREAM_HPP
#define LOG_INC_LOG_STREAM_HPP

#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include <common/global_defines.hpp>

namespace neutrino::log
{
enum class SeverityLevel;
}

namespace neutrino::log::log_details
{

class LogBuffer final : public std::streambuf
{
public:
    LIBRARY_API LogBuffer(SeverityLevel level, std::string tag);

    LIBRARY_API ~LogBuffer() override;

    LogBuffer(const LogBuffer&)            = delete;
    LogBuffer& operator=(const LogBuffer&) = delete;

    LIBRARY_API LogBuffer(LogBuffer&& other) noexcept;
    LIBRARY_API LogBuffer& operator=(LogBuffer&& other) noexcept;

private:
    int overflow(int character) override;
    int sync() override;

    void reset_pointers();
    void flush_buffer();

    SeverityLevel m_level;
    std::string m_tag;
    std::vector<char_type> m_buffer;
};

class LogStream final : public std::ostream
{
public:
    LIBRARY_API explicit LogStream(std::unique_ptr<std::streambuf> buffer);

    LIBRARY_API ~LogStream() override;

    LogStream(const LogStream&)            = delete;
    LogStream& operator=(const LogStream&) = delete;

    LIBRARY_API LogStream(LogStream&& other) noexcept;
    LIBRARY_API LogStream& operator=(LogStream&& other) noexcept;

private:
    std::unique_ptr<std::streambuf> m_buffer;
};

} // namespace neutrino::log::log_details

#endif
