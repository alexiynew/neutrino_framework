#include <algorithm>
#include <array>
#include <string>

#include <system/src/linux/x11_keyboard.hpp>

#include "X11/XKBlib.h"
#include <X11/keysym.h>

namespace
{
using framework::system::KeyCode;

constexpr int key_codes_count = 256;

KeyCode key_codes[key_codes_count] = {KeyCode::unknown};

Display* d;

struct KeyNamePair
{
    std::string name;
    KeyCode code;
};

KeyNamePair key_name_map[] = {
{"SPCE", KeyCode::key_space},
{"AC11", KeyCode::key_apostrophe},
{"AB08", KeyCode::key_comma},
{"AE11", KeyCode::key_minus},
{"AB09", KeyCode::key_period},
{"AB10", KeyCode::key_slash},
{"AE10", KeyCode::key_0},
{"AE01", KeyCode::key_1},
{"AE02", KeyCode::key_2},
{"AE03", KeyCode::key_3},
{"AE04", KeyCode::key_4},
{"AE05", KeyCode::key_5},
{"AE06", KeyCode::key_6},
{"AE07", KeyCode::key_7},
{"AE08", KeyCode::key_8},
{"AE09", KeyCode::key_9},
{"AC10", KeyCode::key_semicolon},
{"AE12", KeyCode::key_equal},
{"AC01", KeyCode::key_a},
{"AB05", KeyCode::key_b},
{"AB03", KeyCode::key_c},
{"AC03", KeyCode::key_d},
{"AD03", KeyCode::key_e},
{"AC04", KeyCode::key_f},
{"AC05", KeyCode::key_g},
{"AC06", KeyCode::key_h},
{"AD08", KeyCode::key_i},
{"AC07", KeyCode::key_j},
{"AC08", KeyCode::key_k},
{"AC09", KeyCode::key_l},
{"AB07", KeyCode::key_m},
{"AB06", KeyCode::key_n},
{"AD09", KeyCode::key_o},
{"AD10", KeyCode::key_p},
{"AD01", KeyCode::key_q},
{"AD04", KeyCode::key_r},
{"AC02", KeyCode::key_s},
{"AD05", KeyCode::key_t},
{"AD07", KeyCode::key_u},
{"AB04", KeyCode::key_v},
{"AD02", KeyCode::key_w},
{"AB02", KeyCode::key_x},
{"AD06", KeyCode::key_y},
{"AB01", KeyCode::key_z},
{"AD11", KeyCode::key_left_bracket},
{"BKSL", KeyCode::key_backslash},
{"AD12", KeyCode::key_right_bracket},
{"TLDE", KeyCode::key_grave_accent},

// navigation
{"ESC", KeyCode::key_escape},
{"RTRN", KeyCode::key_enter},
{"TAB", KeyCode::key_tab},
{"BKSP", KeyCode::key_backspace},
{"INS", KeyCode::key_insert},
{"DELE", KeyCode::key_delete},
{"RGHT", KeyCode::key_right},
{"LEFT", KeyCode::key_left},
{"DOWN", KeyCode::key_down},
{"UP", KeyCode::key_up},
{"PGUP", KeyCode::key_page_up},
{"PGDN", KeyCode::key_page_down},
{"HOME", KeyCode::key_home},
{"END", KeyCode::key_end},
{"CAPS", KeyCode::key_caps_lock},
{"SCLK", KeyCode::key_scroll_lock},
{"NMLK", KeyCode::key_num_lock},
{"PRSK", KeyCode::key_print_screen},
{"PAUS", KeyCode::key_pause},

// Function keys
{"FK01", KeyCode::key_f1},
{"FK02", KeyCode::key_f2},
{"FK03", KeyCode::key_f3},
{"FK04", KeyCode::key_f4},
{"FK05", KeyCode::key_f5},
{"FK06", KeyCode::key_f6},
{"FK07", KeyCode::key_f7},
{"FK08", KeyCode::key_f8},
{"FK09", KeyCode::key_f9},
{"FK10", KeyCode::key_f10},
{"FK11", KeyCode::key_f11},
{"FK12", KeyCode::key_f12},
{"FK13", KeyCode::key_f13},
{"FK14", KeyCode::key_f14},
{"FK15", KeyCode::key_f15},
{"FK16", KeyCode::key_f16},
{"FK17", KeyCode::key_f17},
{"FK18", KeyCode::key_f18},
{"FK19", KeyCode::key_f19},
{"FK20", KeyCode::key_f20},
{"FK21", KeyCode::key_f21},
{"FK22", KeyCode::key_f22},
{"FK23", KeyCode::key_f23},
{"FK24", KeyCode::key_f24},

// numpad
{"KP0", KeyCode::key_num_0},
{"KP1", KeyCode::key_num_1},
{"KP2", KeyCode::key_num_2},
{"KP3", KeyCode::key_num_3},
{"KP4", KeyCode::key_num_4},
{"KP5", KeyCode::key_num_5},
{"KP6", KeyCode::key_num_6},
{"KP7", KeyCode::key_num_7},
{"KP8", KeyCode::key_num_8},
{"KP9", KeyCode::key_num_9},
{"KPDL", KeyCode::key_num_decimal},
{"KPDV", KeyCode::key_num_divide},
{"KPMU", KeyCode::key_num_multiply},
{"KPSU", KeyCode::key_num_subtract},
{"KPAD", KeyCode::key_num_add},
{"KPEN", KeyCode::key_enter},
{"", KeyCode::key_num_separator}, // TODO detect this key

// modifiers
{"LFSH", KeyCode::key_left_shift},
{"LCTL", KeyCode::key_left_control},
{"LALT", KeyCode::key_left_alt},
{"LWIN", KeyCode::key_left_super},

{"RTSH", KeyCode::key_right_shift},
{"RCTL", KeyCode::key_right_control},
{"RALT", KeyCode::key_right_alt},
{"RWIN", KeyCode::key_right_super},
};

} // namespace

namespace framework::system::details
{
void init_key_code_map(const X11Server* server)
{
    d = server->display();

    XkbDescPtr desc = XkbGetMap(server->display(), 0, XkbUseCoreKbd);
    XkbGetNames(server->display(), XkbKeyNamesMask, desc);

    for (int key = desc->min_key_code; key <= desc->max_key_code; ++key) {
        char name[XkbKeyNameLength + 1] = {0};
        std::copy(desc->names->keys[key].name, desc->names->keys[key].name + XkbKeyNameLength, name);

        auto iterator = std::find_if(std::begin(key_name_map), std::end(key_name_map), [&name](const KeyNamePair& k) {
            return k.name == name;
        });

        if (iterator != std::end(key_name_map)) {
            key_codes[key] = iterator->code;
        }
    }
}

KeyCode map_system_key(std::uint32_t key)
{
    return key_codes[key];
}

Modifiers get_modifiers_state(std::uint32_t state)
{
    Modifiers mods;

    if (state & ShiftMask)
        mods |= Modifiers::shift;
    if (state & ControlMask)
        mods |= Modifiers::control;
    if (state & Mod1Mask)
        mods |= Modifiers::alt;
    if (state & Mod4Mask)
        mods |= Modifiers::super;
    if (state & LockMask)
        mods |= Modifiers::caps_lock;
    if (state & Mod2Mask)
        mods |= Modifiers::num_lock;

    return mods;
}

} // namespace framework::system::details
