#include "data_context.hpp"

using namespace framework;
using namespace system;

void DataContext::set_window_state(Window::State state)
{
    m_window_state = state;
}

void DataContext::set_window_size(Size size)
{
    m_window_size = size;
}

void DataContext::set_windos_position(Position position)
{
    m_window_position = position;
}

void DataContext::set_window_cursor_position(Position position)
{
    m_window_cursor_position = position;
}

void DataContext::add_callback_event(const std::string& event)
{
    static constexpr size_t max_events = 100;

    m_callbacks_events.insert(m_callbacks_events.begin(), event);
    if (m_callbacks_events.size() > max_events) {
        m_callbacks_events.pop_back();
    }
}

Window::State DataContext::window_state() const
{
    return m_window_state;
}

Size DataContext::window_size() const
{
    return m_window_size;
}

Position DataContext::window_position() const
{
    return m_window_position;
}

Position DataContext::window_cursor_position() const
{
    return m_window_cursor_position;
}

const std::vector<std::string>& DataContext::last_callback_events() const
{
    return m_callbacks_events;
}
