#ifndef WINDOW_EVENTS_EVENT_HANDLER_HPP
#define WINDOW_EVENTS_EVENT_HANDLER_HPP

#include <system/window.hpp>

#include "data_context.hpp"

class EventHandler
{
public:
    EventHandler(framework::system::Window& w);
    void update();

    const DataContext& data_context() const;

private:
    void attach_logs();
    void attach_actions();

    // actions handlers
    void close_window();
    void toggle_fullscreen();
    void toggle_maximize();
    void iconify();

    void move_to_zero();

    framework::system::Window& m_window;

    DataContext m_data_context;
};

#endif