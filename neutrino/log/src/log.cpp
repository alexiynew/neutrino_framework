#include <common/utils.hpp>
#include <log/log.hpp>

namespace
{
using neutrino::log::Logger;
using neutrino::log::log_details::LogBuffer;
using neutrino::log::log_details::LogStream;

class LoggerStub final : public Logger
{
    void add_message(neutrino::log::SeverityLevel /*level*/,
                     const std::string& /*tag*/,
                     const std::string& /*message*/) override
    {
        // nothing to do.
    }
};

std::unique_ptr<Logger>& logger_instance()
{
    static std::unique_ptr<Logger> instance;

    if (!instance) {
        instance = std::make_unique<LoggerStub>();
    }

    return instance;
}

} // namespace

namespace neutrino::log
{
#pragma region log functions

LogStream debug(const std::string& tag)
{
    if (utils::is_debug()) {
        return LogStream(std::make_unique<LogBuffer>(SeverityLevel::debug, tag));
    }
    return LogStream(nullptr);
}

LogStream info(const std::string& tag)
{
    return LogStream(std::make_unique<LogBuffer>(SeverityLevel::info, tag));
}

LogStream warning(const std::string& tag)
{
    return LogStream(std::make_unique<LogBuffer>(SeverityLevel::warning, tag));
}

LogStream error(const std::string& tag)
{
    return LogStream(std::make_unique<LogBuffer>(SeverityLevel::error, tag));
}

LogStream fatal(const std::string& tag)
{
    return LogStream(std::make_unique<LogBuffer>(SeverityLevel::fatal, tag));
}

#pragma endregion

void set_logger(std::unique_ptr<Logger> implementation)
{
    ::logger_instance() = std::move(implementation);
}

Logger* logger()
{
    return ::logger_instance().get();
}

} // namespace neutrino::log
