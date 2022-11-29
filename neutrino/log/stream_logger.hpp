#ifndef LOG_STREAM_LOGGER_HPP
#define LOG_STREAM_LOGGER_HPP

#include <mutex>
#include <ostream>

#include <common/global_defines.hpp>
#include <log/logger.hpp>

namespace neutrino::log
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup log_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Prints all messages to provided stream.
class StreamLogger final : public Logger
{
public:
    /// @brief Creates stream logger.
    ///
    /// @param stream Output stream.
    LIBRARY_API explicit StreamLogger(std::ostream& stream);

    /// @brief Prints message to the stream.
    ///
    /// @param level The message @ref SeverityLevel
    /// @param tag Message tag. Describes message domain.
    /// @param message Message itself.
    LIBRARY_API void add_message(SeverityLevel level, const std::string& tag, const std::string& message) override;

private:
    std::ostream& m_output;
    std::mutex m_output_mutex;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::log

#endif
