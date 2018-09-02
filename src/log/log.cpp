/// @file
/// @brief Logging interface implementation.
/// @author Fedorov Alexey
/// @date 08.03.2017

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

#include <common/utils.hpp>
#include <log/log.hpp>

namespace
{
using ::framework::log::logger_base;
using ::framework::log::log_details::log_buffer;
using ::framework::log::log_details::log_ostream;

class dummy_logger : public logger_base
{
    void add_message(::framework::log::severity_level /*level*/,
                     const std::string& /*tag*/,
                     const std::string& /*message*/) override
    {
        // nothing to do.
    }
};

std::unique_ptr<logger_base>& logger_instance()
{
    static std::unique_ptr<logger_base> instance;

    if (!instance) {
        instance = std::make_unique<dummy_logger>();
    }

    return instance;
}

} // namespace

namespace framework
{
namespace log
{
#pragma region log functions

log_ostream debug(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::debug, tag));
}

log_ostream info(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::info, tag));
}

log_ostream warning(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::warning, tag));
}

log_ostream error(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::error, tag));
}

log_ostream fatal(const std::string& tag)
{
    return log_ostream(std::make_unique<log_buffer>(severity_level::fatal, tag));
}

#pragma endregion

void set_logger(std::unique_ptr<logger_base> implementation)
{
    ::logger_instance() = std::move(implementation);
}

logger_base* logger()
{
    return ::logger_instance().get();
}

} // namespace log

} // namespace framework
