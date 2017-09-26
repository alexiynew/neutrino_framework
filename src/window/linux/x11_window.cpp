/// @file x11_window.cpp
/// @brief Window implementation for linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#include <exception>
#include <log/log.hpp>
#include <string>
#include <window/linux/x11_window.hpp>

namespace {
const char* const log_tag = "x11_window";
}

namespace framework {

std::unique_ptr<window_implementation> get_implementation()
{
    return std::make_unique<x11_window>();
}

x11_window::x11_window()
    : m_width{640}
    , m_height{480}
    , m_display{nullptr}
    , m_window{0}
{}

x11_window::~x11_window()
{
    hide();
}

void x11_window::show()
{
    m_display = XOpenDisplay(nullptr);

    if (m_display == nullptr) {
        logging::log::error(log_tag, "XOpenDisplay returns nullptr, there is no display.");
        throw std::runtime_error("XOpenDisplay returns nullptr, there is no display.");
    }

    XID screen      = static_cast<XID>(DefaultScreen(m_display));
    XID root_window = static_cast<XID>(RootWindow(m_display, screen));
    XID color       = static_cast<XID>(WhitePixel(m_display, screen));

    m_window = XCreateSimpleWindow(m_display, root_window, 100, 100, m_width, m_height, 0, 0, color);

    XMapWindow(m_display, m_window);

    XFlush(m_display);
}

void x11_window::hide()
{
    // Уничтожаем окно
    if (m_display && m_window) {
        XDestroyWindow(m_display, m_window);
    }
    m_window = 0;

    // Закрываем соединение с сервером
    if (m_display) {
        XCloseDisplay(m_display);
    }
    m_display = nullptr;
}
} // namespace framework
