/// @file
/// @brief The realisation details of the logging system.
/// @author Fedorov Alexey
/// @date 03.03.2018

#ifndef FRAMEWORK_LOG_LOG_DETAILS_HPP
#define FRAMEWORK_LOG_LOG_DETAILS_HPP

#include <memory>
#include <ostream>

namespace framework {

/// @addtogroup log_module
/// @{

namespace log {

enum class severity_level;

namespace log_details {

class log_buffer;

/// @brief Custom output stream
class log_ostream : public std::ostream
{
public:
    log_ostream() = delete;

    ~log_ostream();

    log_ostream(const log_ostream&) = delete;
    log_ostream& operator=(const log_ostream&) = delete;

    log_ostream(log_ostream&&);
    log_ostream& operator=(log_ostream&&);

    log_ostream(severity_level level, const std::string& tag);

private:
    std::unique_ptr<log_buffer> m_buffer;
};

} // namespace log_details

} // namespace log

} // namespace framework

/// @}

#endif
