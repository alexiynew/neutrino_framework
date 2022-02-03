#include <system/src/platform_window.hpp>
#include <system/src/windows/win32_window.hpp>

namespace framework::system::details
{
std::unique_ptr<PlatformWindow> create_platform_window(const std::string& title,
                                                       Size size,
                                                       const ContextSettings& settings)
{
    return std::make_unique<Win32Window>(title, size, settings);
}

} // namespace framework::system::details
