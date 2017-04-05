/**
 * @file linux_canvas.cpp
 * @brief Canvas implementation for linux.
 * @author Fedorov Alexey
 * @date 05.04.2017
 */

#include <canvas/linux/linux_canvas.hpp>

namespace framework {

linux_canvas::linux_canvas(unsigned int width, unsigned int height)
    : m_width{width}
    , m_height{height}
    , m_display{nullptr}
    , m_window{0}
{
}

linux_canvas::~linux_canvas()
{
    hide();
}

void linux_canvas::show()
{
    m_display = XOpenDisplay(nullptr);

    if (!m_display) {

        // TODO throw error
        // return 1;
    }

    /* Получим предварительные сведения */
    XID screen      = DefaultScreen(m_display);
    XID root_window = RootWindow(m_display, screen);
    XID color       = WhitePixel(m_display, screen);

    /* Открываем окно */
    m_window = XCreateSimpleWindow(m_display, root_window, 100, 100, m_width, m_height, 0, 0, color);

    /* Делаем окно видимым */
    XMapWindow(m_display, m_window);

    /* Все сформированные команды принудительно сбрасываем на сервер */
    XFlush(m_display);
}

void linux_canvas::hide()
{
    /* Уничтожаем окно */
    if (m_display && m_window) {
        XDestroyWindow(m_display, m_window);
    }
    m_window = 0;

    /* Закрываем соединение с сервером */
    if (m_display) {
        XCloseDisplay(m_display);
    }
    m_display = nullptr;
}
}
