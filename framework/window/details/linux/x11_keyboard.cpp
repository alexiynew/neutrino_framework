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

#include <window/details/linux/x11_keyboard.hpp>

namespace
{
constexpr framework::int32 key_codes_count = 256;

using framework::window::key_code;

key_code key_codes[key_codes_count] = {key_code::key_unknown};

Display* d;

struct key_name_pair
{
    std::string name;
    framework::window::key_code code;
};

key_name_pair key_name_map[] = {
{"SPCE", key_code::key_space},
{"AC11", key_code::key_apostrophe},
{"AB08", key_code::key_comma},
{"AE11", key_code::key_minus},
{"AB09", key_code::key_period},
{"AB10", key_code::key_slash},
{"AE10", key_code::key_0},
{"AE01", key_code::key_1},
{"AE02", key_code::key_2},
{"AE03", key_code::key_3},
{"AE04", key_code::key_4},
{"AE05", key_code::key_5},
{"AE06", key_code::key_6},
{"AE07", key_code::key_7},
{"AE08", key_code::key_8},
{"AE09", key_code::key_9},
{"AC10", key_code::key_semicolon},
{"AE12", key_code::key_equal},
{"AC01", key_code::key_a},
{"AB05", key_code::key_b},
{"AB03", key_code::key_c},
{"AC03", key_code::key_d},
{"AD03", key_code::key_e},
{"AC04", key_code::key_f},
{"AC05", key_code::key_g},
{"AC06", key_code::key_h},
{"AD08", key_code::key_i},
{"AC07", key_code::key_j},
{"AC08", key_code::key_k},
{"AC09", key_code::key_l},
{"AB07", key_code::key_m},
{"AB06", key_code::key_n},
{"AD09", key_code::key_o},
{"AD10", key_code::key_p},
{"AD01", key_code::key_q},
{"AD04", key_code::key_r},
{"AC02", key_code::key_s},
{"AD05", key_code::key_t},
{"AD07", key_code::key_u},
{"AB04", key_code::key_v},
{"AD02", key_code::key_w},
{"AB02", key_code::key_x},
{"AD06", key_code::key_y},
{"AB01", key_code::key_z},
{"AD11", key_code::key_left_bracket},
{"BKSL", key_code::key_backslash},
{"AD12", key_code::key_right_bracket},
{"TLDE", key_code::key_grave_accent},

// navigation
{"ESC", key_code::key_escape},
{"RTRN", key_code::key_enter},
{"TAB", key_code::key_tab},
{"BKSP", key_code::key_backspace},
{"INS", key_code::key_insert},
{"DELE", key_code::key_delete},
{"RGHT", key_code::key_right},
{"LEFT", key_code::key_left},
{"DOWN", key_code::key_down},
{"UP", key_code::key_up},
{"PGUP", key_code::key_page_up},
{"PGDN", key_code::key_page_down},
{"HOME", key_code::key_home},
{"END", key_code::key_end},
{"CAPS", key_code::key_caps_lock},
{"SCLK", key_code::key_scroll_lock},
{"NMLK", key_code::key_num_lock},
{"PRSK", key_code::key_print_screen},
{"PAUS", key_code::key_pause},

// Function keys
{"FK01", key_code::key_f1},
{"FK02", key_code::key_f2},
{"FK03", key_code::key_f3},
{"FK04", key_code::key_f4},
{"FK05", key_code::key_f5},
{"FK06", key_code::key_f6},
{"FK07", key_code::key_f7},
{"FK08", key_code::key_f8},
{"FK09", key_code::key_f9},
{"FK10", key_code::key_f10},
{"FK11", key_code::key_f11},
{"FK12", key_code::key_f12},
{"FK13", key_code::key_f13},
{"FK14", key_code::key_f14},
{"FK15", key_code::key_f15},
{"FK16", key_code::key_f16},
{"FK17", key_code::key_f17},
{"FK18", key_code::key_f18},
{"FK19", key_code::key_f19},
{"FK20", key_code::key_f20},
{"FK21", key_code::key_f21},
{"FK22", key_code::key_f22},
{"FK23", key_code::key_f23},
{"FK24", key_code::key_f24},

// numpad
{"KP0", key_code::key_num_0},
{"KP1", key_code::key_num_1},
{"KP2", key_code::key_num_2},
{"KP3", key_code::key_num_3},
{"KP4", key_code::key_num_4},
{"KP5", key_code::key_num_5},
{"KP6", key_code::key_num_6},
{"KP7", key_code::key_num_7},
{"KP8", key_code::key_num_8},
{"KP9", key_code::key_num_9},
{"KPDL", key_code::key_num_decimal},
{"KPDV", key_code::key_num_divide},
{"KPMU", key_code::key_num_multiply},
{"KPSU", key_code::key_num_subtract},
{"KPAD", key_code::key_num_add},
{"KPEN", key_code::key_enter},
{"", key_code::key_num_separator}, // TODO detect this key

// modifiers
{"LFSH", key_code::key_left_shift},
{"LCTL", key_code::key_left_control},
{"LALT", key_code::key_left_alt},
{"LWIN", key_code::key_left_super},

{"RTSH", key_code::key_right_shift},
{"RCTL", key_code::key_right_control},
{"RALT", key_code::key_right_alt},
{"RWIN", key_code::key_right_super},
};

} // namespace

namespace framework::window::details
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
    return key_codes[key];
}

modifiers_state get_modifiers_state(uint32 state)
{
    int32 mods = 0;

    if (state & ShiftMask)
        mods |= modifiers_state::mod_shift;
    if (state & ControlMask)
        mods |= modifiers_state::mod_control;
    if (state & Mod1Mask)
        mods |= modifiers_state::mod_menu;
    if (state & Mod4Mask)
        mods |= modifiers_state::mod_super;
    if (state & LockMask)
        mods |= modifiers_state::mod_caps_lock;
    if (state & Mod2Mask)
        mods |= modifiers_state::mod_num_lock;

    return static_cast<modifiers_state>(mods);
}

} // namespace framework::window::details
