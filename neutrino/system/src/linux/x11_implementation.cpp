#include <system/src/linux/x11_window.hpp>
#include <system/src/window_implementation.hpp>

namespace framework::system::details
{
std::unique_ptr<window_implementation> create_implementation(window_size size,
                                                             const std::string& title,
                                                             const context_settings& settings)
{
    return std::make_unique<x11_window>(size, title, settings);
}

} // namespace framework::system::details
