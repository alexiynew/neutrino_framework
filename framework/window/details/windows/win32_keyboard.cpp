/// @file
/// @brief Window implementation for keyboard handling.
/// @author Fedorov Alexey
/// @date 03.03.2019

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

#include <window/details/windows/win32_keyboard.hpp>
#include <windows.h>

namespace
{
using framework::system::key_code;

constexpr key_code key_map[256] = {
//
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_backspace, // 0x08
key_code::key_tab,       // 0x09

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown, // clear key

key_code::key_enter, // 0x0d

key_code::key_unknown,
key_code::key_unknown,

key_code::key_unknown, // 0x10 key_shift
key_code::key_unknown, // 0x11 key_control
key_code::key_unknown, // 0x12 key_alt

key_code::key_pause,     // 0x13
key_code::key_caps_lock, // 0x14

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_escape, // 0x1B

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_space,     // 0x20
key_code::key_page_up,   // 0x21
key_code::key_page_down, // 0x22
key_code::key_end,       // 0x23
key_code::key_home,      // 0x24
key_code::key_left,      // 0x25
key_code::key_up,        // 0x26
key_code::key_right,     // 0x27
key_code::key_down,      // 0x28

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_print_screen, // 0x2c
key_code::key_insert,       // 0x2d
key_code::key_delete,       // 0x2e

key_code::key_unknown,

key_code::key_0, // 0x30
key_code::key_1, // 0x31
key_code::key_2, // 0x32
key_code::key_3, // 0x33
key_code::key_4, // 0x34
key_code::key_5, // 0x35
key_code::key_6, // 0x36
key_code::key_7, // 0x37
key_code::key_8, // 0x38
key_code::key_9, // 0x39

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_a, // 0x41
key_code::key_b, // 0x42
key_code::key_c, // 0x43
key_code::key_d, // 0x44
key_code::key_e, // 0x45
key_code::key_f, // 0x46
key_code::key_g, // 0x47
key_code::key_h, // 0x48
key_code::key_i, // 0x49
key_code::key_j, // 0x4a
key_code::key_k, // 0x4b
key_code::key_l, // 0x4c
key_code::key_m, // 0x4d
key_code::key_n, // 0x4e
key_code::key_o, // 0x4f
key_code::key_p, // 0x50
key_code::key_q, // 0x51
key_code::key_r, // 0x52
key_code::key_s, // 0x53
key_code::key_t, // 0x54
key_code::key_u, // 0x55
key_code::key_v, // 0x56
key_code::key_w, // 0x57
key_code::key_x, // 0x58
key_code::key_y, // 0x59
key_code::key_z, // 0x5a

key_code::key_left_super,  // 0x5b  left supper
key_code::key_right_super, // 0x5c  right supper

key_code::key_unknown, // 0x5d  application key
key_code::key_unknown,
key_code::key_unknown,

key_code::key_num_0,         // 0x60
key_code::key_num_1,         // 0x61
key_code::key_num_2,         // 0x62
key_code::key_num_3,         // 0x63
key_code::key_num_4,         // 0x64
key_code::key_num_5,         // 0x65
key_code::key_num_6,         // 0x66
key_code::key_num_7,         // 0x67
key_code::key_num_8,         // 0x68
key_code::key_num_9,         // 0x69
key_code::key_num_multiply,  // 0x6a
key_code::key_num_add,       // 0x6b
key_code::key_num_separator, // 0x6c
key_code::key_num_subtract,  // 0x6d
key_code::key_num_decimal,   // 0x6e
key_code::key_num_divide,    // 0x6f

key_code::key_f1,  // 0x70
key_code::key_f2,  // 0x71
key_code::key_f3,  // 0x72
key_code::key_f4,  // 0x73
key_code::key_f5,  // 0x74
key_code::key_f6,  // 0x75
key_code::key_f7,  // 0x76
key_code::key_f8,  // 0x77
key_code::key_f9,  // 0x78
key_code::key_f10, // 0x79
key_code::key_f11, // 0x7a
key_code::key_f12, // 0x7b
key_code::key_f13, // 0x7c
key_code::key_f14, // 0x7d
key_code::key_f15, // 0x7e
key_code::key_f16, // 0x7f
key_code::key_f17, // 0x80
key_code::key_f18, // 0x81
key_code::key_f19, // 0x82
key_code::key_f20, // 0x83
key_code::key_f21, // 0x84
key_code::key_f22, // 0x85
key_code::key_f23, // 0x86
key_code::key_f24, // 0x87

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_num_lock,    // 0x90
key_code::key_scroll_lock, // 0x91

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_left_shift,    // 0xa0
key_code::key_right_shift,   // 0xa1
key_code::key_left_control,  // 0xa2
key_code::key_right_control, // 0xa3
key_code::key_left_alt,      // 0xa4
key_code::key_right_alt,     // 0xa5

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_semicolon,    // 0xba
key_code::key_equal,        // 0xbb
key_code::key_comma,        // 0xbc
key_code::key_minus,        // 0xbd
key_code::key_period,       // 0xbe
key_code::key_slash,        // 0xbf
key_code::key_grave_accent, // 0xc0

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_left_bracket,  // 0xdb
key_code::key_backslash,     // 0xdc
key_code::key_right_bracket, // 0xdd
key_code::key_apostrophe,    // 0xde

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,

key_code::key_backslash, // 0xe2

key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
key_code::key_unknown,
};

} // namespace

namespace framework::system::details
{
key_code map_system_key(uint32 key)
{
    return key_map[key];
}

modifiers_state get_modifiers_state()
{
    int32 state = 0;

    if (GetKeyState(VK_SHIFT) & 0x8000) {
        state |= modifiers_state::mod_shift;
    }

    if (GetKeyState(VK_CONTROL) & 0x8000) {
        state |= modifiers_state::mod_control;
    }

    if (GetKeyState(VK_MENU) & 0x8000) {
        state |= modifiers_state::mod_menu;
    }

    if ((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & 0x8000) {
        state |= modifiers_state::mod_super;
    }

    if (GetKeyState(VK_CAPITAL) & 1) {
        state |= modifiers_state::mod_caps_lock;
    }

    if (GetKeyState(VK_NUMLOCK) & 1) {
        state |= modifiers_state::mod_num_lock;
    }

    return static_cast<modifiers_state>(state);
}

} // namespace framework::system::details
