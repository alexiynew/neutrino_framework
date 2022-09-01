#ifndef WINDOW_EVENTS_EVENT_HANDLER_HPP
#define WINDOW_EVENTS_EVENT_HANDLER_HPP

#include <system/window.hpp>

#include "data_context.hpp"

class EventHandler
{
public:
    EventHandler(framework::system::Window& w);

    const DataContext& data_context() const;

    void on_show();
    void on_hide();
    void on_close();
    void on_focus();
    void on_lost_focus();
    void on_resize(framework::Size size);
    void on_move(framework::Position p);
    void on_key_down(framework::system::KeyCode key, framework::system::Modifiers state);
    void on_key_up(framework::system::KeyCode key, framework::system::Modifiers state);
    void on_mouse_enter();
    void on_mouse_leave();
    void on_mouse_move(framework::system::CursorPosition p);
    void on_mouse_button_down(framework::system::MouseButton button,
                              framework::system::CursorPosition position,
                              framework::system::Modifiers state);
    void on_mouse_button_up(framework::system::MouseButton button,
                            framework::system::CursorPosition position,
                            framework::system::Modifiers state);
    void on_mouse_scroll(framework::system::ScrollOffset offset);
    void on_character(const std::string& s);

    void on_update();

private:
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
