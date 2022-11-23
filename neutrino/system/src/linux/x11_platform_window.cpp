#include <system/src/linux/x11_window.hpp>
#include <system/src/platform_window.hpp>

namespace neutrino::system::details
{
std::unique_ptr<PlatformWindow> create_platform_window(const std::string& title,
                                                       Size size,
                                                       const ContextSettings& settings)
{
    return std::make_unique<X11Window>(title, size, settings);
}

} // namespace neutrino::system::details
