#include <system/src/platform_window.hpp>

namespace framework::system::details
{
PlatformWindow::PlatformWindow()
{}

PlatformWindow::~PlatformWindow() = default;

void PlatformWindow::set_callbacks_holder(const CallbacksHolder* callbacks)
{
    m_callbacks = callbacks;
}

} // namespace framework::system::details
