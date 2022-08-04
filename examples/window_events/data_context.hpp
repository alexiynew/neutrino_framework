#ifndef WINDOW_EVENTS_DATA_CONTEXT_HPP
#define WINDOW_EVENTS_DATA_CONTEXT_HPP

#include <string>
#include <vector>

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
    void add_callback_event(const std::string& event);

    WindowState window_state() const;
    const std::vector<std::string>& last_callback_events() const;

private:
    WindowState m_window_state;
    std::vector<std::string> m_callbacks_events;
};

#endif
