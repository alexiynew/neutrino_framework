#include "data_context.hpp"

void DataContext::set_window_state(WindowState state)
{
    m_window_state = state;
}

void DataContext::add_callback_event(const std::string& event)
{
    static constexpr size_t max_events = 100;

    m_callbacks_events.insert(m_callbacks_events.begin(), event);
    if (m_callbacks_events.size() > max_events) {
        m_callbacks_events.pop_back();
    }
}

DataContext::WindowState DataContext::window_state() const
{
    return m_window_state;
}

const std::vector<std::string>& DataContext::last_callback_events() const
{
    return m_callbacks_events;
}
