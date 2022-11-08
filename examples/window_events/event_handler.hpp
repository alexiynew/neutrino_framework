#ifndef WINDOW_EVENTS_EVENT_HANDLER_HPP
#define WINDOW_EVENTS_EVENT_HANDLER_HPP

#include <common/fps_counter.hpp>
#include <system/window.hpp>

#include "data_context.hpp"

class EventHandler
{
public:
    EventHandler(neutrino::system::Window& w);

    const DataContext& data_context() const;

    void on_show();
    void on_hide();
    void on_close();
    void on_focus();
    void on_lost_focus();
    void on_resize(neutrino::Size size);
    void on_move(neutrino::Position p);
    void on_key_down(neutrino::system::KeyCode key, neutrino::system::Modifiers state);
    void on_key_up(neutrino::system::KeyCode key, neutrino::system::Modifiers state);
    void on_mouse_enter();
    void on_mouse_leave();
    void on_mouse_move(neutrino::system::CursorPosition p);
    void on_mouse_button_down(neutrino::system::MouseButton button,
                              neutrino::system::CursorPosition position,
                              neutrino::system::Modifiers state);
    void on_mouse_button_up(neutrino::system::MouseButton button,
                            neutrino::system::CursorPosition position,
                            neutrino::system::Modifiers state);
    void on_mouse_scroll(neutrino::system::ScrollOffset offset);
    void on_character(const std::string& s);

    void on_update();

private:
    // actions handlers
    void close_window();
    void toggle_fullscreen();
    void toggle_maximize();
    void iconify();

    void move_to_zero();

    void toggle_resizable();

    void toggle_cursor_capture();
    void toggle_cursor_visible();

    neutrino::system::Window& m_window;
    neutrino::FpsCounter m_fps;

    DataContext m_data_context;
};

#endif
