/// @file
/// @brief The realisation details of the logging system.
/// @author Fedorov Alexey
/// @date 03.03.2018

#ifndef FRAMEWORK_LOG_LOG_DETAILS_HPP
#define FRAMEWORK_LOG_LOG_DETAILS_HPP

#include <memory>
#include <ostream>
#include <vector>

namespace framework {

/// @addtogroup log_module
/// @{

namespace log {

enum class severity_level;

namespace log_details {

/// @brief Custom stream buffer
class log_buffer : public std::streambuf
{
public:
    log_buffer(::framework::log::severity_level level, std::string tag);

    ~log_buffer() override;

protected:
    int overflow(int character) override;
    int sync() override;

private:
    const severity_level m_level;
    const std::string m_tag;
    std::vector<char_type> m_buffer;

    void reset_pointers();
    void clear_buffer();
};

/// @brief Custom output stream
class log_ostream : public std::ostream
{
public:
    log_ostream() = delete;

    ~log_ostream() override;

    log_ostream(const log_ostream&) = delete;
    log_ostream& operator=(const log_ostream&) = delete;

    log_ostream(log_ostream&&) noexcept;
    log_ostream& operator=(log_ostream&&) noexcept;

    explicit log_ostream(std::unique_ptr<std::streambuf> buffer);

private:
    std::unique_ptr<std::streambuf> m_buffer;
};

} // namespace log_details

} // namespace log

} // namespace framework

/// @}

#endif
