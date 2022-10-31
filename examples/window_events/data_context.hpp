#ifndef WINDOW_EVENTS_DATA_CONTEXT_HPP
#define WINDOW_EVENTS_DATA_CONTEXT_HPP

#include <string>
#include <vector>

#include <common/position.hpp>
#include <common/size.hpp>
#include <system/window.hpp>

using neutrino::Position;
using neutrino::Size;

class DataContext
{
public:
    void set_window_state(neutrino::system::Window::State state);
    void set_window_size(Size size);
    void set_windos_position(Position position);
    void set_window_cursor_position(Position position);
    void set_window_resizable(bool value);
    void set_window_has_input_focus(bool value);

    void set_cursor_captured(bool value);
    void set_cursor_visible(bool value);
    void set_cursor_hover(bool value);

    void add_callback_event(const std::string& event);

    neutrino::system::Window::State window_state() const;
    Size window_size() const;
    Position window_position() const;
    Position window_cursor_position() const;
    bool window_resizable() const;
    bool window_has_input_focus() const;

    bool cursor_captured() const;
    bool cursor_visible() const;
    bool cursor_hover() const;

    const std::vector<std::string>& last_callback_events() const;

private:
    neutrino::system::Window::State m_window_state = neutrino::system::Window::State::normal;
    std::vector<std::string> m_callbacks_events;
    Size m_window_size;
    Position m_window_position;
    Position m_window_cursor_position;
    bool m_window_resizable;
    bool m_window_has_input_focus;

    bool m_cursor_captured;
    bool m_cursor_visible;
    bool m_cursor_hover;
};

#endif
