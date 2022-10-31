#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <system/window.hpp>

#include "event_handler.hpp"
#include "view.hpp"

using namespace neutrino;
using namespace neutrino::system;
using neutrino::log::StreamLogger;

class App
{
public:
    App()
        : m_window("Window Events", {800, 600})
        , m_view(m_window)
        , m_event_handler(m_window)
    {
        setup_callbacks();
    }

    void run()
    {
        m_window.show();
        while (!m_window.should_close()) {
            m_window.process_events();
            m_event_handler.on_update();
            m_view.render(m_event_handler.data_context());
        }
    }

private:
    void setup_callbacks()
    {
        m_window.set_on_show_callback([this]() { m_event_handler.on_show(); });
        m_window.set_on_hide_callback([this]() { m_event_handler.on_hide(); });
        m_window.set_on_close_callback([this]() { m_event_handler.on_close(); });
        m_window.set_on_focus_callback([this]() { m_event_handler.on_focus(); });
        m_window.set_on_lost_focus_callback([this]() { m_event_handler.on_lost_focus(); });
        m_window.set_on_resize_callback([this](Size size) {
            m_view.on_resize(size);
            m_event_handler.on_resize(size);
        });
        m_window.set_on_move_callback([this](Position p) { m_event_handler.on_move(p); });
        m_window.set_on_key_down_callback(
        [this](KeyCode key, Modifiers state) { m_event_handler.on_key_down(key, state); });
        m_window.set_on_key_up_callback(
        [this](KeyCode key, Modifiers state) { m_event_handler.on_key_up(key, state); });
        m_window.set_on_mouse_enter_callback([this]() { m_event_handler.on_mouse_enter(); });
        m_window.set_on_mouse_leave_callback([this]() { m_event_handler.on_mouse_leave(); });
        m_window.set_on_mouse_move_callback([this](CursorPosition p) { m_event_handler.on_mouse_move(p); });
        m_window.set_on_mouse_button_down_callback(
        [this](MouseButton b, CursorPosition p, Modifiers s) { m_event_handler.on_mouse_button_down(b, p, s); });
        m_window.set_on_mouse_button_up_callback(
        [this](MouseButton b, CursorPosition p, Modifiers s) { m_event_handler.on_mouse_button_up(b, p, s); });
        m_window.set_on_mouse_scroll_callback([this](ScrollOffset offset) { m_event_handler.on_mouse_scroll(offset); });
        m_window.set_on_character_callback([this](const std::string& s) { m_event_handler.on_character(s); });
    }

    Window m_window;
    View m_view;
    EventHandler m_event_handler;
};

int main()
{
    neutrino::log::set_logger(std::make_unique<StreamLogger>(std::cout));
    log::info("Main") << "RUN";

    App app;
    app.run();
}
