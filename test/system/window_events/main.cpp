#include <chrono>
#include <iostream>
#include <thread>

#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

namespace
{
using framework::system::KeyCode;
using framework::system::Modifiers;
using framework::system::MouseButton;

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
    }

    return "undefined";
}

std::string print_state(const Modifiers state)
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

    return s;
}

std::string button_name(MouseButton button)
{
    switch (button) {
        case MouseButton::button_left: return "button_left";
        case MouseButton::button_right: return "button_right";
        case MouseButton::button_middle: return "button_middle";
        case MouseButton::button_4: return "button_4";
        case MouseButton::button_5: return "button_5";
        case MouseButton::button_6: return "button_6";

        case MouseButton::unknown: return "unknown";
    }

    return "undefined";
}

} // namespace

class WindowEventTest : public framework::unit_test::Suite
{
public:
    WindowEventTest()
        : Suite("WindowEventTest")
    {
        add_test([this]() { run(); }, "run");
    }

private:
    void run()
    {
        using namespace framework;
        using namespace framework::system;

        framework::log::set_logger(std::make_unique<framework::log::StreamLogger>(std::cout));

        const Size size640{640, 480};

        Window w(name(), size640);

        bool should_close = false;

        w.on_show.connect([](const Window&) { log::info("test") << "on_show" << std::endl; });

        w.on_hide.connect([](const Window&) { log::info("test") << "on_hide" << std::endl; });

        w.on_close.connect([&should_close](const Window&) {
            log::info("test") << "on_close" << std::endl;
            should_close = true;
        });

        w.on_focus.connect([](const Window&) { log::info("test") << "on_focus" << std::endl; });

        w.on_lost_focus.connect([](const Window&) { log::info("test") << "on_focus_lost" << std::endl; });

        w.on_resize.connect([](const Window&, Size size) { log::info("test") << "on_size: " << size << std::endl; });

        w.on_move.connect(
        [](const Window&, Position position) { log::info("test") << "on_position: " << position << std::endl; });

        w.on_key_down.connect([](const Window&, system::KeyCode key, system::Modifiers state) {
            log::info("test") << "on_key_press key: " << static_cast<std::int32_t>(key) << " " << key_name(key) << " "
                              << print_state(state) << std::endl;
        });

        w.on_key_up.connect([](const Window&, system::KeyCode key, system::Modifiers state) {
            log::info("test") << "on_key_release key: " << static_cast<std::int32_t>(key) << " " << key_name(key) << " "
                              << print_state(state) << std::endl;
        });

        w.on_mouse_enter.connect([](const Window&) { log::info("test") << "on_mouse_enter" << std::endl; });

        w.on_mouse_leave.connect([](const Window&) { log::info("test") << "on_mouse_leave" << std::endl; });

        w.on_mouse_move.connect(
        [](const Window&, system::CursorPosition p) { log::info("test") << "on_mouse_move " << p << std::endl; });

        w.on_mouse_button_down.connect(
        [](const Window&, system::MouseButton button, system::CursorPosition position, system::Modifiers state) {
            log::info("test") << "on_mouse_press: " << button_name(button) << " " << position << " "
                              << print_state(state) << std::endl;
        });

        w.on_mouse_button_up.connect(
        [](const Window&, system::MouseButton button, system::CursorPosition position, system::Modifiers state) {
            log::info("test") << "on_mouse_release: " << button_name(button) << " " << position << " "
                              << print_state(state) << std::endl;
        });

        w.on_mouse_scroll.connect([](const Window&, system::ScrollOffset offset) {
            log::info("test") << "on_mouse_scroll: " << offset << std::endl;
        });

        w.on_character.connect(
        [](const Window&, std::string s) { log::info("test") << "on_character: " << s << std::endl; });

        w.show();

        const float max_total_time = 10000;
        float total_time           = 0;

        while (w.is_visible() && !should_close && total_time < max_total_time) {
            w.process_events();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            total_time += 16;
        }
    }
};

int main()
{
    return run_tests(WindowEventTest());
}
