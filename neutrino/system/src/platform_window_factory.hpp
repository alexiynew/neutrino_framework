#ifndef SYSTEM_SRC_PLATFORM_WINDOW_FACTORY_HPP
#define SYSTEM_SRC_PLATFORM_WINDOW_FACTORY_HPP

#include <memory>
#include <string>

#include <common/size.hpp>
#include <system/context_settings.hpp>

#include <system/src/platform_window.hpp>

namespace framework::system::details
{
std::unique_ptr<PlatformWindow> create_platform_window(const std::string& title,
                                                       Size size,
                                                       const ContextSettings& settings);

} // namespace framework::system::details

#endif
