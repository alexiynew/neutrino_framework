#include "event_handler.hpp"

#include <sstream>

#include "data_context.hpp"

using namespace framework;
using namespace framework::system;

namespace
{

std::string key_name(KeyCode key)
{
    switch (key) {
        case KeyCode::unknown: return "unknown";

        // Printable
        case KeyCode::key_space: return "key_space";
        case KeyCode::key_apostrophe: return "key_apostrophe";
        case KeyCode::key_comma: return "key_comma";
        case KeyCode::key_minus: return "key_minus";
        case KeyCode::key_period: return "key_period";
        case KeyCode::key_slash: return "key_slash";
        case KeyCode::key_0: return "key_0";
        case KeyCode::key_1: return "key_1";
        case KeyCode::key_2: return "key_2";
        case KeyCode::key_3: return "key_3";
        case KeyCode::key_4: return "key_4";
        case KeyCode::key_5: return "key_5";
        case KeyCode::key_6: return "key_6";
        case KeyCode::key_7: return "key_7";
        case KeyCode::key_8: return "key_8";
        case KeyCode::key_9: return "key_9";
        case KeyCode::key_semicolon: return "key_semicolon";
        case KeyCode::key_equal: return "key_equal";
        case KeyCode::key_a: return "key_a";
        case KeyCode::key_b: return "key_b";
        case KeyCode::key_c: return "key_c";
        case KeyCode::key_d: return "key_d";
        case KeyCode::key_e: return "key_e";
        case KeyCode::key_f: return "key_f";
        case KeyCode::key_g: return "key_g";
        case KeyCode::key_h: return "key_h";
        case KeyCode::key_i: return "key_i";
        case KeyCode::key_j: return "key_j";
        case KeyCode::key_k: return "key_k";
        case KeyCode::key_l: return "key_l";
        case KeyCode::key_m: return "key_m";
        case KeyCode::key_n: return "key_n";
        case KeyCode::key_o: return "key_o";
        case KeyCode::key_p: return "key_p";
        case KeyCode::key_q: return "key_q";
        case KeyCode::key_r: return "key_r";
        case KeyCode::key_s: return "key_s";
        case KeyCode::key_t: return "key_t";
        case KeyCode::key_u: return "key_u";
        case KeyCode::key_v: return "key_v";
        case KeyCode::key_w: return "key_w";
        case KeyCode::key_x: return "key_x";
        case KeyCode::key_y: return "key_y";
        case KeyCode::key_z: return "key_z";
        case KeyCode::key_left_bracket: return "key_left_bracket";
        case KeyCode::key_backslash: return "key_backslash";
        case KeyCode::key_right_bracket: return "key_right_bracket";
        case KeyCode::key_grave_accent: return "key_grave_accent";
        case KeyCode::key_section: return "key_section";

        // navigation
        case KeyCode::key_escape: return "key_escape";
        case KeyCode::key_enter: return "key_enter";
        case KeyCode::key_tab: return "key_tab";
        case KeyCode::key_backspace: return "key_backspace";
        case KeyCode::key_insert: return "key_insert";
        case KeyCode::key_delete: return "key_delete";
        case KeyCode::key_right: return "key_right";
        case KeyCode::key_left: return "key_left";
        case KeyCode::key_down: return "key_down";
        case KeyCode::key_up: return "key_up";
        case KeyCode::key_page_up: return "key_page_up";
        case KeyCode::key_page_down: return "key_page_down";
        case KeyCode::key_home: return "key_home";
        case KeyCode::key_end: return "key_end";
        case KeyCode::key_caps_lock: return "key_caps_lock";
        case KeyCode::key_scroll_lock: return "key_scroll_lock";
        case KeyCode::key_num_lock: return "key_num_lock";
        case KeyCode::key_print_screen: return "key_print_screen";
        case KeyCode::key_pause: return "key_pause";

        // Function keys
        case KeyCode::key_f1: return "key_f1";
        case KeyCode::key_f2: return "key_f2";
        case KeyCode::key_f3: return "key_f3";
        case KeyCode::key_f4: return "key_f4";
        case KeyCode::key_f5: return "key_f5";
        case KeyCode::key_f6: return "key_f6";
        case KeyCode::key_f7: return "key_f7";
        case KeyCode::key_f8: return "key_f8";
        case KeyCode::key_f9: return "key_f9";
        case KeyCode::key_f10: return "key_f10";
        case KeyCode::key_f11: return "key_f11";
        case KeyCode::key_f12: return "key_f12";
        case KeyCode::key_f13: return "key_f13";
        case KeyCode::key_f14: return "key_f14";
        case KeyCode::key_f15: return "key_f15";
        case KeyCode::key_f16: return "key_f16";
        case KeyCode::key_f17: return "key_f17";
        case KeyCode::key_f18: return "key_f18";
        case KeyCode::key_f19: return "key_f19";
        case KeyCode::key_f20: return "key_f20";
        case KeyCode::key_f21: return "key_f21";
        case KeyCode::key_f22: return "key_f22";
        case KeyCode::key_f23: return "key_f23";
        case KeyCode::key_f24: return "key_f24";

        // numpad
        case KeyCode::key_num_0: return "key_num_0";
        case KeyCode::key_num_1: return "key_num_1";
        case KeyCode::key_num_2: return "key_num_2";
        case KeyCode::key_num_3: return "key_num_3";
        case KeyCode::key_num_4: return "key_num_4";
        case KeyCode::key_num_5: return "key_num_5";
        case KeyCode::key_num_6: return "key_num_6";
        case KeyCode::key_num_7: return "key_num_7";
        case KeyCode::key_num_8: return "key_num_8";
        case KeyCode::key_num_9: return "key_num_9";
        case KeyCode::key_num_decimal: return "key_num_decimal";
        case KeyCode::key_num_divide: return "key_num_divide";
        case KeyCode::key_num_multiply: return "key_num_multiply";
        case KeyCode::key_num_subtract: return "key_num_subtract";
        case KeyCode::key_num_add: return "key_num_add";
        case KeyCode::key_num_separator: return "key_num_separator";

        // modifiers
        case KeyCode::key_left_shift: return "key_left_shift";
        case KeyCode::key_left_control: return "key_left_control";
        case KeyCode::key_left_alt: return "key_left_alt";
        case KeyCode::key_left_super: return "key_left_super";

        case KeyCode::key_right_shift: return "key_right_shift";
        case KeyCode::key_right_control: return "key_right_control";
        case KeyCode::key_right_alt: return "key_right_alt";
        case KeyCode::key_right_super: return "key_right_super";

        case KeyCode::key_function: return "key_function";
    }

    return "undefined";
}

std::string button_name(MouseButton button)
{
    switch (button) {
        case MouseButton::button_left: return "Left";
        case MouseButton::button_right: return "Right";
        case MouseButton::button_middle: return "Middle";
        case MouseButton::button_4: return "Button_4";
        case MouseButton::button_5: return "Button_5";
        case MouseButton::button_6: return "Button_6";

        case MouseButton::unknown: return "Unknown";
    }

    return "undefined";
}

std::string to_string(const Modifiers state)
{
    std::string s;

    if (state & Modifiers::shift) {
        s += "S";
    }

    if (state & Modifiers::control) {
        s += "C";
    }

    if (state & Modifiers::alt) {
        s += "M";
    }

    if (state & Modifiers::super) {
        s += "W";
    }

    if (state & Modifiers::caps_lock) {
        s += "L";
    }

    if (state & Modifiers::num_lock) {
        s += "N";
    }

    if (state & Modifiers::function) {
        s += "F";
    }

    return s;
}

std::string to_string(const Position& p)
{
    std::stringstream ss;
    ss << p;
    return ss.str();
}

std::string to_string(const Size& s)
{
    std::stringstream ss;
    ss << s;
    return ss.str();
}

std::string to_string(const KeyCode& k)
{
    std::stringstream ss;
    return std::to_string(static_cast<int>(k));
}

} // namespace

EventHandler::EventHandler(Window& w)
    : m_window(w)
{
    m_data_context.set_window_state(m_window.state());
}

const DataContext& EventHandler::data_context() const
{
    return m_data_context;
}

void EventHandler::on_show()
{
    m_data_context.add_callback_event("on_show");
}

void EventHandler::on_hide()
{
    m_data_context.add_callback_event("on_hide");
}

void EventHandler::on_close()
{
    m_data_context.add_callback_event("on_close");
}

void EventHandler::on_focus()
{
    m_data_context.add_callback_event("on_focus");
}

void EventHandler::on_lost_focus()
{
    m_data_context.add_callback_event("on_focus_lost");
}

void EventHandler::on_resize(Size size)
{
    m_data_context.add_callback_event("on_size: " + to_string(size));
    m_data_context.set_window_size(size);
}

void EventHandler::on_move(Position p)
{
    m_data_context.add_callback_event("on_position: " + to_string(p));
    m_data_context.set_windos_position(p);
}

void EventHandler::on_key_down(KeyCode key, Modifiers state)
{
    m_data_context.add_callback_event("on_key_down key: " + to_string(key) + " " + key_name(key) + " " +
                                      to_string(state));
}

void EventHandler::on_key_up(KeyCode key, Modifiers state)
{
    m_data_context.add_callback_event("on_key_up key: " + to_string(key) + " " + key_name(key) + " " +
                                      to_string(state));

    switch (key) {
        case KeyCode::key_q: close_window(); break;
        case KeyCode::key_f: toggle_fullscreen(); break;
        case KeyCode::key_m: toggle_maximize(); break;
        case KeyCode::key_i: iconify(); break;
        case KeyCode::key_0: move_to_zero(); break;
        default: break;
    }
}

void EventHandler::on_mouse_enter()
{
    m_data_context.add_callback_event("on_mouse_enter");
}

void EventHandler::on_mouse_leave()
{
    m_data_context.add_callback_event("on_mouse_leave");
}

void EventHandler::on_mouse_move(CursorPosition p)
{
    m_data_context.add_callback_event("on_mouse_move " + to_string(p));
    m_data_context.set_window_cursor_position(p);
}

void EventHandler::on_mouse_button_down(MouseButton button, CursorPosition position, Modifiers state)
{
    m_data_context.add_callback_event("on_mouse_down: " + button_name(button) + " " + to_string(position) + " " +
                                      to_string(state));
}

void EventHandler::on_mouse_button_up(MouseButton button, CursorPosition position, Modifiers state)
{
    m_data_context.add_callback_event("on_mouse_up: " + button_name(button) + " " + to_string(position) + " " +
                                      to_string(state));
}

void EventHandler::on_mouse_scroll(ScrollOffset offset)
{
    m_data_context.add_callback_event("on_mouse_scroll: " + to_string(offset));
}

void EventHandler::on_character(const std::string& s)
{
    m_data_context.add_callback_event("on_character: " + s);
}

void EventHandler::on_update()
{
    m_data_context.set_window_state(m_window.state());
}

#pragma region actions handlers

void EventHandler::close_window()
{
    m_window.close();
}

void EventHandler::toggle_fullscreen()
{
    if (m_window.state() == Window::State::fullscreen) {
        m_window.set_state(Window::State::normal);
    } else {
        m_window.set_state(Window::State::fullscreen);
    }
}

void EventHandler::toggle_maximize()
{
    if (m_window.state() == Window::State::maximized) {
        m_window.set_state(Window::State::normal);
    } else {
        m_window.set_state(Window::State::maximized);
    }
}

void EventHandler::iconify()
{
    // TODO: window restoring by click on icon or Alt+Tab should reset iconified state
    if (m_window.state() != Window::State::iconified) {
        m_window.set_state(Window::State::iconified);
    }
}

void EventHandler::move_to_zero()
{
    m_window.set_position({0, 0});
}

#pragma endregion
