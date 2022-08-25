#ifndef WINDOW_EVENTS_DATA_CONTEXT_HPP
#define WINDOW_EVENTS_DATA_CONTEXT_HPP

#include <string>
#include <vector>

#include <common/position.hpp>
#include <common/size.hpp>

using framework::Position;
using framework::Size;

class DataContext
{
public:
    struct WindowState
    {
        int normal : 1;
        int fullscreen : 1;
        int maximized : 1;
        int iconified : 1;
    };

    void set_window_state(WindowState state);
    void set_window_size(Size size);
    void set_windos_position(Position position);
    void set_window_cursor_position(Position position);

    void add_callback_event(const std::string& event);

    WindowState window_state() const;
    Size window_size() const;
    Position window_position() const;
    Position window_cursor_position() const;

    const std::vector<std::string>& last_callback_events() const;

private:
    WindowState m_window_state;
    std::vector<std::string> m_callbacks_events;
    Size m_window_size;
    Position m_window_position;
    Position m_window_cursor_position;
};

#endif
