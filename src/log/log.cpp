/**
 * @file log.cpp
 * @brief Logger implementation.
 * @author Fedorov Alexey
 * @date 08.03.2017
 */

#include <log/log.hpp>

namespace framework {

namespace logging {

#pragma mark - implementation of logger class

void logger::add_message(const logger::level, const std::string&, const std::string&)
{
    // nothing to do.
}

} // namespace logging

} // namespace framework

using framework::logging::logger;
using framework::logging::log;

std::unique_ptr<logger> log::m_logger = std::unique_ptr<logger>();
