#include <system/src/windows/win32_keyboard.hpp>

#include <Windows.h>

namespace
{
using framework::system::KeyCode;

constexpr KeyCode key_map[256] = {
//
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_backspace, // 0x08
KeyCode::key_tab,       // 0x09

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown, // clear key

KeyCode::key_enter, // 0x0d

KeyCode::unknown,
KeyCode::unknown,

KeyCode::unknown, // 0x10 key_shift
KeyCode::unknown, // 0x11 key_control
KeyCode::unknown, // 0x12 key_alt

KeyCode::key_pause,     // 0x13
KeyCode::key_caps_lock, // 0x14

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_escape, // 0x1B

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_space,     // 0x20
KeyCode::key_page_up,   // 0x21
KeyCode::key_page_down, // 0x22
KeyCode::key_end,       // 0x23
KeyCode::key_home,      // 0x24
KeyCode::key_left,      // 0x25
KeyCode::key_up,        // 0x26
KeyCode::key_right,     // 0x27
KeyCode::key_down,      // 0x28

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_print_screen, // 0x2c
KeyCode::key_insert,       // 0x2d
KeyCode::key_delete,       // 0x2e

KeyCode::unknown,

KeyCode::key_0, // 0x30
KeyCode::key_1, // 0x31
KeyCode::key_2, // 0x32
KeyCode::key_3, // 0x33
KeyCode::key_4, // 0x34
KeyCode::key_5, // 0x35
KeyCode::key_6, // 0x36
KeyCode::key_7, // 0x37
KeyCode::key_8, // 0x38
KeyCode::key_9, // 0x39

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_a, // 0x41
KeyCode::key_b, // 0x42
KeyCode::key_c, // 0x43
KeyCode::key_d, // 0x44
KeyCode::key_e, // 0x45
KeyCode::key_f, // 0x46
KeyCode::key_g, // 0x47
KeyCode::key_h, // 0x48
KeyCode::key_i, // 0x49
KeyCode::key_j, // 0x4a
KeyCode::key_k, // 0x4b
KeyCode::key_l, // 0x4c
KeyCode::key_m, // 0x4d
KeyCode::key_n, // 0x4e
KeyCode::key_o, // 0x4f
KeyCode::key_p, // 0x50
KeyCode::key_q, // 0x51
KeyCode::key_r, // 0x52
KeyCode::key_s, // 0x53
KeyCode::key_t, // 0x54
KeyCode::key_u, // 0x55
KeyCode::key_v, // 0x56
KeyCode::key_w, // 0x57
KeyCode::key_x, // 0x58
KeyCode::key_y, // 0x59
KeyCode::key_z, // 0x5a

KeyCode::key_left_super,  // 0x5b  left supper
KeyCode::key_right_super, // 0x5c  right supper

KeyCode::unknown, // 0x5d  application key
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_num_0,         // 0x60
KeyCode::key_num_1,         // 0x61
KeyCode::key_num_2,         // 0x62
KeyCode::key_num_3,         // 0x63
KeyCode::key_num_4,         // 0x64
KeyCode::key_num_5,         // 0x65
KeyCode::key_num_6,         // 0x66
KeyCode::key_num_7,         // 0x67
KeyCode::key_num_8,         // 0x68
KeyCode::key_num_9,         // 0x69
KeyCode::key_num_multiply,  // 0x6a
KeyCode::key_num_add,       // 0x6b
KeyCode::key_num_separator, // 0x6c
KeyCode::key_num_subtract,  // 0x6d
KeyCode::key_num_decimal,   // 0x6e
KeyCode::key_num_divide,    // 0x6f

KeyCode::key_f1,  // 0x70
KeyCode::key_f2,  // 0x71
KeyCode::key_f3,  // 0x72
KeyCode::key_f4,  // 0x73
KeyCode::key_f5,  // 0x74
KeyCode::key_f6,  // 0x75
KeyCode::key_f7,  // 0x76
KeyCode::key_f8,  // 0x77
KeyCode::key_f9,  // 0x78
KeyCode::key_f10, // 0x79
KeyCode::key_f11, // 0x7a
KeyCode::key_f12, // 0x7b
KeyCode::key_f13, // 0x7c
KeyCode::key_f14, // 0x7d
KeyCode::key_f15, // 0x7e
KeyCode::key_f16, // 0x7f
KeyCode::key_f17, // 0x80
KeyCode::key_f18, // 0x81
KeyCode::key_f19, // 0x82
KeyCode::key_f20, // 0x83
KeyCode::key_f21, // 0x84
KeyCode::key_f22, // 0x85
KeyCode::key_f23, // 0x86
KeyCode::key_f24, // 0x87

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_num_lock,    // 0x90
KeyCode::key_scroll_lock, // 0x91

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_left_shift,    // 0xa0
KeyCode::key_right_shift,   // 0xa1
KeyCode::key_left_control,  // 0xa2
KeyCode::key_right_control, // 0xa3
KeyCode::key_left_alt,      // 0xa4
KeyCode::key_right_alt,     // 0xa5

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_semicolon,    // 0xba
KeyCode::key_equal,        // 0xbb
KeyCode::key_comma,        // 0xbc
KeyCode::key_minus,        // 0xbd
KeyCode::key_period,       // 0xbe
KeyCode::key_slash,        // 0xbf
KeyCode::key_grave_accent, // 0xc0

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_left_bracket,  // 0xdb
KeyCode::key_backslash,     // 0xdc
KeyCode::key_right_bracket, // 0xdd
KeyCode::key_apostrophe,    // 0xde

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,

KeyCode::key_backslash, // 0xe2

KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
KeyCode::unknown,
};

} // namespace

namespace framework::system::details
{
KeyCode map_system_key(uint32 key)
{
    return key_map[key];
}

Modifiers get_modifiers_state()
{
    Modifiers state;

    if (GetKeyState(VK_SHIFT) & 0x8000) {
        state |= Modifiers::shift;
    }

    if (GetKeyState(VK_CONTROL) & 0x8000) {
        state |= Modifiers::control;
    }

    if (GetKeyState(VK_MENU) & 0x8000) {
        state |= Modifiers::alt;
    }

    if ((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & 0x8000) {
        state |= Modifiers::super;
    }

    if (GetKeyState(VK_CAPITAL) & 1) {
        state |= Modifiers::caps_lock;
    }

    if (GetKeyState(VK_NUMLOCK) & 1) {
        state |= Modifiers::num_lock;
    }

    return state;
}

} // namespace framework::system::details
