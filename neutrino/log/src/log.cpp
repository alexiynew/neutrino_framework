// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#include <common/utils.hpp>
#include <log/log.hpp>

namespace
{
using framework::log::Logger;
using framework::log::log_details::LogBuffer;
using framework::log::log_details::LogStream;

class DummyLogger : public Logger
{
    void add_message(framework::log::SeverityLevel /*level*/,
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
        instance = std::make_unique<DummyLogger>();
    }

    return instance;
}

} // namespace

namespace framework::log
{
#pragma region log functions

LogStream debug(const std::string& tag)
{
    return LogStream(std::make_unique<LogBuffer>(SeverityLevel::debug, tag));
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

} // namespace framework::log
