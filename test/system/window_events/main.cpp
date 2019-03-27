
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <iostream>

#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <unit_test/suite.hpp>
#include <window/window.hpp>

namespace
{
using ::framework::system::key_code;
using ::framework::system::modifiers_state;
using ::framework::system::mouse_button;

std::string key_name(key_code key)
{
    switch (key) {
        case key_code::key_unknown: return "key_unknown";

        // Printable
        case key_code::key_space: return "key_space";
        case key_code::key_apostrophe: return "key_apostrophe";
        case key_code::key_comma: return "key_comma";
        case key_code::key_minus: return "key_minus";
        case key_code::key_period: return "key_period";
        case key_code::key_slash: return "key_slash";
        case key_code::key_0: return "key_0";
        case key_code::key_1: return "key_1";
        case key_code::key_2: return "key_2";
        case key_code::key_3: return "key_3";
        case key_code::key_4: return "key_4";
        case key_code::key_5: return "key_5";
        case key_code::key_6: return "key_6";
        case key_code::key_7: return "key_7";
        case key_code::key_8: return "key_8";
        case key_code::key_9: return "key_9";
        case key_code::key_semicolon: return "key_semicolon";
        case key_code::key_equal: return "key_equal";
        case key_code::key_a: return "key_a";
        case key_code::key_b: return "key_b";
        case key_code::key_c: return "key_c";
        case key_code::key_d: return "key_d";
        case key_code::key_e: return "key_e";
        case key_code::key_f: return "key_f";
        case key_code::key_g: return "key_g";
        case key_code::key_h: return "key_h";
        case key_code::key_i: return "key_i";
        case key_code::key_j: return "key_j";
        case key_code::key_k: return "key_k";
        case key_code::key_l: return "key_l";
        case key_code::key_m: return "key_m";
        case key_code::key_n: return "key_n";
        case key_code::key_o: return "key_o";
        case key_code::key_p: return "key_p";
        case key_code::key_q: return "key_q";
        case key_code::key_r: return "key_r";
        case key_code::key_s: return "key_s";
        case key_code::key_t: return "key_t";
        case key_code::key_u: return "key_u";
        case key_code::key_v: return "key_v";
        case key_code::key_w: return "key_w";
        case key_code::key_x: return "key_x";
        case key_code::key_y: return "key_y";
        case key_code::key_z: return "key_z";
        case key_code::key_left_bracket: return "key_left_bracket";
        case key_code::key_backslash: return "key_backslash";
        case key_code::key_right_bracket: return "key_right_bracket";
        case key_code::key_grave_accent: return "key_grave_accent";

        // navigation
        case key_code::key_escape: return "key_escape";
        case key_code::key_enter: return "key_enter";
        case key_code::key_tab: return "key_tab";
        case key_code::key_backspace: return "key_backspace";
        case key_code::key_insert: return "key_insert";
        case key_code::key_delete: return "key_delete";
        case key_code::key_right: return "key_right";
        case key_code::key_left: return "key_left";
        case key_code::key_down: return "key_down";
        case key_code::key_up: return "key_up";
        case key_code::key_page_up: return "key_page_up";
        case key_code::key_page_down: return "key_page_down";
        case key_code::key_home: return "key_home";
        case key_code::key_end: return "key_end";
        case key_code::key_caps_lock: return "key_caps_lock";
        case key_code::key_scroll_lock: return "key_scroll_lock";
        case key_code::key_num_lock: return "key_num_lock";
        case key_code::key_print_screen: return "key_print_screen";
        case key_code::key_pause: return "key_pause";

        // Function keys
        case key_code::key_f1: return "key_f1";
        case key_code::key_f2: return "key_f2";
        case key_code::key_f3: return "key_f3";
        case key_code::key_f4: return "key_f4";
        case key_code::key_f5: return "key_f5";
        case key_code::key_f6: return "key_f6";
        case key_code::key_f7: return "key_f7";
        case key_code::key_f8: return "key_f8";
        case key_code::key_f9: return "key_f9";
        case key_code::key_f10: return "key_f10";
        case key_code::key_f11: return "key_f11";
        case key_code::key_f12: return "key_f12";
        case key_code::key_f13: return "key_f13";
        case key_code::key_f14: return "key_f14";
        case key_code::key_f15: return "key_f15";
        case key_code::key_f16: return "key_f16";
        case key_code::key_f17: return "key_f17";
        case key_code::key_f18: return "key_f18";
        case key_code::key_f19: return "key_f19";
        case key_code::key_f20: return "key_f20";
        case key_code::key_f21: return "key_f21";
        case key_code::key_f22: return "key_f22";
        case key_code::key_f23: return "key_f23";
        case key_code::key_f24: return "key_f24";

        // numpad
        case key_code::key_num_0: return "key_num_0";
        case key_code::key_num_1: return "key_num_1";
        case key_code::key_num_2: return "key_num_2";
        case key_code::key_num_3: return "key_num_3";
        case key_code::key_num_4: return "key_num_4";
        case key_code::key_num_5: return "key_num_5";
        case key_code::key_num_6: return "key_num_6";
        case key_code::key_num_7: return "key_num_7";
        case key_code::key_num_8: return "key_num_8";
        case key_code::key_num_9: return "key_num_9";
        case key_code::key_num_decimal: return "key_num_decimal";
        case key_code::key_num_divide: return "key_num_divide";
        case key_code::key_num_multiply: return "key_num_multiply";
        case key_code::key_num_subtract: return "key_num_subtract";
        case key_code::key_num_add: return "key_num_add";
        case key_code::key_num_separator: return "key_num_separator";

        // modifiers
        case key_code::key_left_shift: return "key_left_shift";
        case key_code::key_left_control: return "key_left_control";
        case key_code::key_left_alt: return "key_left_alt";
        case key_code::key_left_super: return "key_left_super";

        case key_code::key_right_shift: return "key_right_shift";
        case key_code::key_right_control: return "key_right_control";
        case key_code::key_right_alt: return "key_right_alt";
        case key_code::key_right_super: return "key_right_super";
    }

    return "undefined";
}

std::string print_state(const modifiers_state state)
{
    std::string s;

    if (state & modifiers_state::mod_shift) {
        s += "S";
    }

    if (state & modifiers_state::mod_control) {
        s += "C";
    }

    if (state & modifiers_state::mod_menu) {
        s += "M";
    }

    if (state & modifiers_state::mod_super) {
        s += "W";
    }

    if (state & modifiers_state::mod_caps_lock) {
        s += "L";
    }

    if (state & modifiers_state::mod_num_lock) {
        s += "N";
    }

    return s;
}

std::string button_name(mouse_button button)
{
    switch (button) {
        case mouse_button::button_left: return "button_left";
        case mouse_button::button_right: return "button_right";
        case mouse_button::button_middle: return "button_middle";
        case mouse_button::button_4: return "button_4";
        case mouse_button::button_5: return "button_5";
        case mouse_button::button_6: return "button_6";
        case mouse_button::button_7: return "button_7";
        case mouse_button::button_8: return "button_8";

        case mouse_button::button_unknown: return "button_unknown";
    }

    return "undefined";
}

} // namespace

class window_events_test : public framework::unit_test::suite
{
public:
    window_events_test() : suite("window_events_test")
    {
        add_test([this]() { run(); }, "run");
    }

private:
    void run()
    {
        using namespace framework;
        using ::framework::system::window;
        using ::framework::system::window_position;
        using ::framework::system::window_size;

        ::framework::log::set_logger(std::make_unique<::framework::log::stream_logger>(std::cout));

        const window_size size640{640, 480};

        window w(size640, "Test");

        bool should_close = false;

        w.set_on_show_callback([](const window&) { log::info("test") << "on_show" << std::endl; });

        w.set_on_hide_callback([](const window&) { log::info("test") << "on_hide" << std::endl; });

        w.set_on_close_callback([&should_close](const window&) {
            log::info("test") << "on_close" << std::endl;
            should_close = true;
        });

        w.set_on_focus_callback([](const window&) { log::info("test") << "on_focus" << std::endl; });

        w.set_on_focus_lost_callback([](const window&) { log::info("test") << "on_focus_lost" << std::endl; });

        w.set_on_size_callback(
        [](const window&, window_size size) { log::info("test") << "on_size: " << size << std::endl; });

        w.set_on_position_callback(
        [](const window&, window_position position) { log::info("test") << "on_position: " << position << std::endl; });

        w.set_on_key_press_callback([](const window&, system::key_code key, system::modifiers_state state) {
            log::info("test")
            << "on_key_press key: " << (int)key << " " << key_name(key) << " " << print_state(state) << std::endl;
        });

        w.set_on_key_release_callback([](const window&, system::key_code key, system::modifiers_state state) {
            log::info("test")
            << "on_key_release key: " << (int)key << " " << key_name(key) << " " << print_state(state) << std::endl;
        });

        w.set_on_mouse_enter_callback([](const window&) { log::info("test") << "on_mouse_enter" << std::endl; });

        w.set_on_mouse_leave_callback([](const window&) { log::info("test") << "on_mouse_leave" << std::endl; });

        w.set_on_mouse_move_callback([](const window&, system::cursor_position p) {
            log::info("test") << "on_mouse_move {" << p.x << ", " << p.y << "}" << std::endl;
        });

        w.set_on_mouse_button_press_callback(
        [](const window&, system::mouse_button button, system::cursor_position position, system::modifiers_state state) {
            log::info("test") << "on_mouse_press: " << button_name(button) << " {" << position.x << ", " << position.y
                              << "} " << print_state(state) << std::endl;
        });

        w.set_on_mouse_button_release_callback(
        [](const window&, system::mouse_button button, system::cursor_position position, system::modifiers_state state) {
            log::info("test") << "on_mouse_release: " << button_name(button) << " {" << position.x << ", " << position.y
                              << "} " << print_state(state) << std::endl;
        });

        w.set_on_character_callback(
        [](const window&, std::string s) { log::info("test") << "on_character: " << s << std::endl; });

        w.show();

        while (w.visible() && !should_close) {
            w.process_events();
        }
    }
};

int main()
{
    return run_tests(window_events_test());
}
