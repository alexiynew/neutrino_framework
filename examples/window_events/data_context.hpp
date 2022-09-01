#ifndef WINDOW_EVENTS_DATA_CONTEXT_HPP
#define WINDOW_EVENTS_DATA_CONTEXT_HPP

#include <string>
#include <vector>

#include <common/position.hpp>
#include <common/size.hpp>
#include <system/window.hpp>

using framework::Position;
using framework::Size;

class DataContext
{
public:
    void set_window_state(framework::system::Window::State state);
    void set_window_size(Size size);
    void set_windos_position(Position position);
    void set_window_cursor_position(Position position);

    void add_callback_event(const std::string& event);

    framework::system::Window::State window_state() const;
    Size window_size() const;
    Position window_position() const;
    Position window_cursor_position() const;

    const std::vector<std::string>& last_callback_events() const;

private:
    framework::system::Window::State m_window_state = framework::system::Window::State::normal;
    std::vector<std::string> m_callbacks_events;
    Size m_window_size;
    Position m_window_position;
    Position m_window_cursor_position;
};

#endif
