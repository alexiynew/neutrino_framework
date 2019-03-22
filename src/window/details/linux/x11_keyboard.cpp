/// @file
/// @brief Linux implementation for keyboard handling.
/// @author Fedorov Alexey
/// @date 11.03.2019

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

#include "X11/XKBlib.h"
#include <X11/keysym.h>
#include <algorithm>
#include <array>
#include <string>

#include <log/log.hpp>
#include <window/details/linux/x11_keyboard.hpp>

namespace
{
constexpr framework::int32 key_codes_count = 256;

framework::system::key_code key_codes[key_codes_count] = {framework::system::key_code::key_unknown};

Display* d;

struct key_name_pair
{
    std::string name;
    framework::system::key_code code;
};

key_name_pair key_name_map[] = {
{"SPCE", framework::system::key_code::key_space},
{"AC11", framework::system::key_code::key_apostrophe},
{"AB08", framework::system::key_code::key_comma},
{"AE11", framework::system::key_code::key_minus},
{"AB09", framework::system::key_code::key_period},
{"AB10", framework::system::key_code::key_slash},
{"AE10", framework::system::key_code::key_0},
{"AE01", framework::system::key_code::key_1},
{"AE02", framework::system::key_code::key_2},
{"AE03", framework::system::key_code::key_3},
{"AE04", framework::system::key_code::key_4},
{"AE05", framework::system::key_code::key_5},
{"AE06", framework::system::key_code::key_6},
{"AE07", framework::system::key_code::key_7},
{"AE08", framework::system::key_code::key_8},
{"AE09", framework::system::key_code::key_9},
{"AC10", framework::system::key_code::key_semicolon},
{"AE12", framework::system::key_code::key_equal},
{"AC01", framework::system::key_code::key_a},
{"AB05", framework::system::key_code::key_b},
{"AB03", framework::system::key_code::key_c},
{"AC03", framework::system::key_code::key_d},
{"AD03", framework::system::key_code::key_e},
{"AC04", framework::system::key_code::key_f},
{"AC05", framework::system::key_code::key_g},
{"AC06", framework::system::key_code::key_h},
{"AD08", framework::system::key_code::key_i},
{"AC07", framework::system::key_code::key_j},
{"AC08", framework::system::key_code::key_k},
{"AC09", framework::system::key_code::key_l},
{"AB07", framework::system::key_code::key_m},
{"AB06", framework::system::key_code::key_n},
{"AD09", framework::system::key_code::key_o},
{"AD10", framework::system::key_code::key_p},
{"AD01", framework::system::key_code::key_q},
{"AD04", framework::system::key_code::key_r},
{"AC02", framework::system::key_code::key_s},
{"AD05", framework::system::key_code::key_t},
{"AD07", framework::system::key_code::key_u},
{"AB04", framework::system::key_code::key_v},
{"AD02", framework::system::key_code::key_w},
{"AB02", framework::system::key_code::key_x},
{"AD06", framework::system::key_code::key_y},
{"AB01", framework::system::key_code::key_z},
{"AD11", framework::system::key_code::key_left_bracket},
{"BKSL", framework::system::key_code::key_backslash},
{"AD12", framework::system::key_code::key_right_bracket},
{"TLDE", framework::system::key_code::key_grave_accent},
//{"", framework::system::key_code::key_world_1},
//{"", framework::system::key_code::key_world_2},

// navigation
{"ESC", framework::system::key_code::key_escape},
{"RTRN", framework::system::key_code::key_enter},
{"TAB", framework::system::key_code::key_tab},
{"BKSP", framework::system::key_code::key_backspace},
{"INS", framework::system::key_code::key_insert},
{"DELE", framework::system::key_code::key_delete},
{"RGHT", framework::system::key_code::key_right},
{"LEFT", framework::system::key_code::key_left},
{"DOWN", framework::system::key_code::key_down},
{"UP", framework::system::key_code::key_up},
{"PGUP", framework::system::key_code::key_page_up},
{"PGDN", framework::system::key_code::key_page_down},
{"HOME", framework::system::key_code::key_home},
{"END", framework::system::key_code::key_end},
{"CAPS", framework::system::key_code::key_caps_lock},
{"SCLK", framework::system::key_code::key_scroll_lock},
{"NMLK", framework::system::key_code::key_num_lock},
{"", framework::system::key_code::key_print_screen}, // TODO detect this key
{"PAUS", framework::system::key_code::key_pause},

// Function keys
{"FK01", framework::system::key_code::key_f1},
{"FK02", framework::system::key_code::key_f2},
{"FK03", framework::system::key_code::key_f3},
{"FK04", framework::system::key_code::key_f4},
{"FK05", framework::system::key_code::key_f5},
{"FK06", framework::system::key_code::key_f6},
{"FK07", framework::system::key_code::key_f7},
{"FK08", framework::system::key_code::key_f8},
{"FK09", framework::system::key_code::key_f9},
{"FK10", framework::system::key_code::key_f10},
{"FK11", framework::system::key_code::key_f11},
{"FK12", framework::system::key_code::key_f12},
{"FK13", framework::system::key_code::key_f13},
{"FK14", framework::system::key_code::key_f14},
{"FK15", framework::system::key_code::key_f15},
{"FK16", framework::system::key_code::key_f16},
{"FK17", framework::system::key_code::key_f17},
{"FK18", framework::system::key_code::key_f18},
{"FK19", framework::system::key_code::key_f19},
{"FK20", framework::system::key_code::key_f20},
{"FK21", framework::system::key_code::key_f21},
{"FK22", framework::system::key_code::key_f22},
{"FK23", framework::system::key_code::key_f23},
{"FK24", framework::system::key_code::key_f24},
{"FK25", framework::system::key_code::key_f25},

// numpad
{"KP0", framework::system::key_code::key_num_0},
{"KP1", framework::system::key_code::key_num_1},
{"KP2", framework::system::key_code::key_num_2},
{"KP3", framework::system::key_code::key_num_3},
{"KP4", framework::system::key_code::key_num_4},
{"KP5", framework::system::key_code::key_num_5},
{"KP6", framework::system::key_code::key_num_6},
{"KP7", framework::system::key_code::key_num_7},
{"KP8", framework::system::key_code::key_num_8},
{"KP9", framework::system::key_code::key_num_9},
{"KPDL", framework::system::key_code::key_num_decimal},
{"KPDV", framework::system::key_code::key_num_divide},
{"KPMU", framework::system::key_code::key_num_multiply},
{"KPSU", framework::system::key_code::key_num_subtract},
{"KPAD", framework::system::key_code::key_num_add},
{"KPEN", framework::system::key_code::key_enter},
{"", framework::system::key_code::key_num_separator}, // TODO detect this key

// modifiers
{"", framework::system::key_code::key_super}, // TODO detect this key

{"LFSH", framework::system::key_code::key_left_shift},
{"LCTL", framework::system::key_code::key_left_control},
{"LALT", framework::system::key_code::key_left_alt},
{"", framework::system::key_code::key_left_super},

{"RTSH", framework::system::key_code::key_right_shift},
{"RCTL", framework::system::key_code::key_right_control},
{"RALT", framework::system::key_code::key_right_alt},
{"", framework::system::key_code::key_right_super},
};

} // namespace

namespace framework::system::details
{
void init_key_code_map(const x11_server* server)
{
    d = server->display();

    XkbDescPtr desc = XkbGetMap(server->display(), 0, XkbUseCoreKbd);
    XkbGetNames(server->display(), XkbKeyNamesMask, desc);

    for (int32 key = desc->min_key_code; key <= desc->max_key_code; ++key) {
        char name[XkbKeyNameLength + 1] = {0};
        std::copy(desc->names->keys[key].name, desc->names->keys[key].name + XkbKeyNameLength, name);

        auto iterator = std::find_if(std::begin(key_name_map), std::end(key_name_map), [&name](const key_name_pair& k) {
            return k.name == name;
        });

        if (iterator != std::end(key_name_map)) {
            key_codes[key] = iterator->code;
        }
    }
}

key_code map_system_key(uint32 key)
{
    XkbDescPtr desc = XkbGetMap(d, 0, XkbUseCoreKbd);
    XkbGetNames(d, XkbKeyNamesMask, desc);

    std::string name(desc->names->keys[key].name, XkbKeyNameLength);

    log::debug("keyboard") << '[' << name << ']' << std::endl;

    return key_codes[key];
}

modifiers_state get_modifiers_state()
{
    return {};
}

} // namespace framework::system::details
