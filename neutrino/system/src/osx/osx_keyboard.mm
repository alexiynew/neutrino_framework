#include <array>

#include <system/src/osx/osx_keyboard.hpp>

#import <AppKit/AppKit.h>

namespace
{
using neutrino::system::KeyCode;

// Virtual keycodes
//
// These constants are the virtual keycodes defined originally in
// Inside Mac Volume V, pg. V-191. They identify physical keys on a
// keyboard. Those constants with "ANSI" in the name are labeled
// according to the key position on an ANSI-standard US keyboard.
// For example, kVK_ANSI_A indicates the virtual keycode for the key
// with the letter 'A' in the US keyboard layout. Other keyboard
// layouts may have the 'A' key label on a different physical key;
// in this case, pressing 'A' will generate a different virtual
// keycode.

constexpr static std::array<KeyCode, 127> key_map = {
KeyCode::key_a,             // 0x00
KeyCode::key_s,             // 0x01
KeyCode::key_d,             // 0x02
KeyCode::key_f,             // 0x03
KeyCode::key_h,             // 0x04
KeyCode::key_g,             // 0x05
KeyCode::key_z,             // 0x06
KeyCode::key_x,             // 0x07
KeyCode::key_c,             // 0x08
KeyCode::key_v,             // 0x09
KeyCode::key_section,       // 0x0A  ISO_Section
KeyCode::key_b,             // 0x0B
KeyCode::key_q,             // 0x0C
KeyCode::key_w,             // 0x0D
KeyCode::key_e,             // 0x0E
KeyCode::key_r,             // 0x0F
KeyCode::key_y,             // 0x10
KeyCode::key_t,             // 0x11
KeyCode::key_1,             // 0x12
KeyCode::key_2,             // 0x13
KeyCode::key_3,             // 0x14
KeyCode::key_4,             // 0x15
KeyCode::key_6,             // 0x16
KeyCode::key_5,             // 0x17
KeyCode::key_equal,         // 0x18
KeyCode::key_9,             // 0x19
KeyCode::key_7,             // 0x1A
KeyCode::key_minus,         // 0x1B
KeyCode::key_8,             // 0x1C
KeyCode::key_0,             // 0x1D
KeyCode::key_right_bracket, // 0x1E
KeyCode::key_o,             // 0x1F
KeyCode::key_u,             // 0x20
KeyCode::key_left_bracket,  // 0x21
KeyCode::key_i,             // 0x22
KeyCode::key_p,             // 0x23
KeyCode::key_enter,         // 0x24
KeyCode::key_l,             // 0x25
KeyCode::key_j,             // 0x26
KeyCode::key_apostrophe,    // 0x27
KeyCode::key_k,             // 0x28
KeyCode::key_semicolon,     // 0x29
KeyCode::key_backslash,     // 0x2A
KeyCode::key_comma,         // 0x2B
KeyCode::key_slash,         // 0x2C
KeyCode::key_n,             // 0x2D
KeyCode::key_m,             // 0x2E
KeyCode::key_period,        // 0x2F
KeyCode::key_tab,           // 0x30
KeyCode::key_space,         // 0x31
KeyCode::key_grave_accent,  // 0x32
KeyCode::key_backspace,     // 0x33
KeyCode::unknown,
KeyCode::key_escape,        // 0x35
KeyCode::key_right_super,   // 0x36  command
KeyCode::key_left_super,    // 0x37  command
KeyCode::key_left_shift,    // 0x38
KeyCode::key_caps_lock,     // 0x39
KeyCode::key_left_alt,      // 0x3A  option
KeyCode::key_left_control,  // 0x3B
KeyCode::key_right_shift,   // 0x3C
KeyCode::key_right_alt,     // 0x3D  option
KeyCode::key_right_control, // 0x3E
KeyCode::key_function,      // 0x3F
KeyCode::key_f17,           // 0x40  function key
KeyCode::key_num_decimal,   // 0x41
KeyCode::unknown,
KeyCode::key_num_multiply, // 0x43
KeyCode::unknown,
KeyCode::key_num_add, // 0x45
KeyCode::unknown,
KeyCode::key_num_lock,   // 0x47
KeyCode::unknown,        // 0x48  VolumeUp
KeyCode::unknown,        // 0x49  VolumeDown
KeyCode::unknown,        // 0x4A  Mute
KeyCode::key_num_divide, // 0x4B
KeyCode::key_enter,      // 0x4C  It's a keypad enter key.
KeyCode::unknown,
KeyCode::key_num_subtract, // 0x4E
KeyCode::key_f18,          // 0x4F
KeyCode::key_f19,          // 0x50
KeyCode::key_equal,        // 0x51
KeyCode::key_num_0,        // 0x52
KeyCode::key_num_1,        // 0x53
KeyCode::key_num_2,        // 0x54
KeyCode::key_num_3,        // 0x55
KeyCode::key_num_4,        // 0x56
KeyCode::key_num_5,        // 0x57
KeyCode::key_num_6,        // 0x58
KeyCode::key_num_7,        // 0x59
KeyCode::key_f20,          // 0x5A
KeyCode::key_num_8,        // 0x5B
KeyCode::key_num_9,        // 0x5C
KeyCode::unknown,          // 0x5D  JIS_Yen
KeyCode::unknown,          // 0x5E  JIS_Underscore
KeyCode::unknown,          // 0x5F  JIS_KeypadComma
KeyCode::key_f5,           // 0x60
KeyCode::key_f6,           // 0x61
KeyCode::key_f7,           // 0x62
KeyCode::key_f3,           // 0x63
KeyCode::key_f8,           // 0x64
KeyCode::key_f9,           // 0x65
KeyCode::unknown,          // 0x66  JIS_Eisu
KeyCode::key_f11,          // 0x67
KeyCode::unknown,          // 0x68  JIS_Kana
KeyCode::key_f13,          // 0x69
KeyCode::key_f16,          // 0x6A
KeyCode::key_f14,          // 0x6B
KeyCode::unknown,
KeyCode::key_f10, // 0x6D
KeyCode::unknown,
KeyCode::key_f12, // 0x6F
KeyCode::unknown,
KeyCode::key_f15,       // 0x71
KeyCode::key_insert,    // 0x72  help
KeyCode::key_home,      // 0x73
KeyCode::key_page_up,   // 0x74
KeyCode::key_delete,    // 0x75
KeyCode::key_f4,        // 0x76
KeyCode::key_end,       // 0x77
KeyCode::key_f2,        // 0x78
KeyCode::key_page_down, // 0x79
KeyCode::key_f1,        // 0x7A
KeyCode::key_left,      // 0x7B
KeyCode::key_right,     // 0x7C
KeyCode::key_down,      // 0x7D
KeyCode::key_up,        // 0x7E
};

} // namespace

namespace neutrino::system::details
{
KeyCode map_system_key(std::uint32_t key)
{
    if (key < key_map.size()) {
        return key_map[key];
    }

    return KeyCode::unknown;
}

Modifiers get_modifiers_state(std::uint32_t flags)
{
    Modifiers state;

    if (flags & NSEventModifierFlagCapsLock) {
        state |= Modifiers::ModifiersState::caps_lock;
    }

    if (flags & NSEventModifierFlagShift) {
        state |= Modifiers::ModifiersState::shift;
    }

    if (flags & NSEventModifierFlagControl) {
        state |= Modifiers::ModifiersState::control;
    }

    if (flags & NSEventModifierFlagOption) {
        state |= Modifiers::ModifiersState::alt;
    }

    if (flags & NSEventModifierFlagCommand) {
        state |= Modifiers::ModifiersState::super;
    }

    // Set if any key in the numeric keypad is pressed.
    if (flags & NSEventModifierFlagNumericPad) {
        state |= Modifiers::ModifiersState::num_lock;
    }

    // Set if the Help key is pressed.
    if (flags & NSEventModifierFlagHelp) {
        // state |= ???
    }

    // Set if any function key is pressed.
    if (flags & NSEventModifierFlagFunction) {
        state |= Modifiers::ModifiersState::function;
    }

    return state;
}

} // namespace neutrino::system::details
