#include <system/src/platform_window.hpp>

namespace neutrino::system::details
{
PlatformWindow::PlatformWindow()
{}

PlatformWindow::~PlatformWindow() = default;

void PlatformWindow::set_window_interface(Window* window)
{
    m_window_interface = window;
}

const CallbacksHolder& PlatformWindow::callbacks() const
{
    if (m_window_interface && m_window_interface->m_callbacks) {
        return *(m_window_interface->m_callbacks.get());
    } else {
        throw std::runtime_error("Window interface not set or window callbacks not initilized.");
    }
}

const StateData& PlatformWindow::state_data() const
{
    if (m_window_interface && m_window_interface->m_state_data) {
        return *(m_window_interface->m_state_data.get());
    } else {
        throw std::runtime_error("Window interface not set or window state data not initilized.");
    }
}

void PlatformWindow::on_close()
{
    if (m_window_interface) {
        m_window_interface->on_close();
    }
}

void PlatformWindow::on_resize(Size size)
{
    if (m_window_interface) {
        m_window_interface->on_resize(size);
    }
}

void PlatformWindow::on_move(Position position)
{
    if (m_window_interface) {
        m_window_interface->on_move(position);
    }
}

void PlatformWindow::on_focus()
{
    if (m_window_interface) {
        m_window_interface->on_focus();
    }
}

void PlatformWindow::on_lost_focus()
{
    if (m_window_interface) {
        m_window_interface->on_lost_focus();
    }
}

void PlatformWindow::on_mouse_enter()
{
    if (m_window_interface) {
        m_window_interface->on_mouse_enter();
    }
}

void PlatformWindow::on_mouse_leave()
{
    if (m_window_interface) {
        m_window_interface->on_mouse_leave();
    }
}

void PlatformWindow::on_mouse_move(CursorPosition position)
{
    if (m_window_interface) {
        m_window_interface->on_mouse_move(position);
    }
}

} // namespace neutrino::system::details
