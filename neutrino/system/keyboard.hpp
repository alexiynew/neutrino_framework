// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#ifndef FRAMEWORK_SYSTEM_KEYBOARD_HPP
#define FRAMEWORK_SYSTEM_KEYBOARD_HPP

#include <common/types.hpp>

namespace framework::system
{
enum class KeyCode
{
    unknown = -1,

    // Printable
    key_space         = 32,
    key_apostrophe    = 39, // '
    key_comma         = 44, // ,
    key_minus         = 45, // -
    key_period        = 46, // .
    key_slash         = 47, // /
    key_0             = 48,
    key_1             = 49,
    key_2             = 50,
    key_3             = 51,
    key_4             = 52,
    key_5             = 53,
    key_6             = 54,
    key_7             = 55,
    key_8             = 56,
    key_9             = 57,
    key_semicolon     = 59, // ;
    key_equal         = 61, // =
    key_a             = 65,
    key_b             = 66,
    key_c             = 67,
    key_d             = 68,
    key_e             = 69,
    key_f             = 70,
    key_g             = 71,
    key_h             = 72,
    key_i             = 73,
    key_j             = 74,
    key_k             = 75,
    key_l             = 76,
    key_m             = 77,
    key_n             = 78,
    key_o             = 79,
    key_p             = 80,
    key_q             = 81,
    key_r             = 82,
    key_s             = 83,
    key_t             = 84,
    key_u             = 85,
    key_v             = 86,
    key_w             = 87,
    key_x             = 88,
    key_y             = 89,
    key_z             = 90,
    key_left_bracket  = 91, // [
    key_backslash     = 92, /* \  */
    key_right_bracket = 93, // ]
    key_grave_accent  = 96, // `

    // navigation
    key_escape       = 256,
    key_enter        = 257,
    key_tab          = 258,
    key_backspace    = 259,
    key_insert       = 260,
    key_delete       = 261,
    key_right        = 262,
    key_left         = 263,
    key_down         = 264,
    key_up           = 265,
    key_page_up      = 266,
    key_page_down    = 267,
    key_home         = 268,
    key_end          = 269,
    key_caps_lock    = 280,
    key_scroll_lock  = 281,
    key_num_lock     = 282,
    key_print_screen = 283,
    key_pause        = 284,

    // Function keys
    key_f1  = 290,
    key_f2  = 291,
    key_f3  = 292,
    key_f4  = 293,
    key_f5  = 294,
    key_f6  = 295,
    key_f7  = 296,
    key_f8  = 297,
    key_f9  = 298,
    key_f10 = 299,
    key_f11 = 300,
    key_f12 = 301,
    key_f13 = 302,
    key_f14 = 303,
    key_f15 = 304,
    key_f16 = 305,
    key_f17 = 306,
    key_f18 = 307,
    key_f19 = 308,
    key_f20 = 309,
    key_f21 = 310,
    key_f22 = 311,
    key_f23 = 312,
    key_f24 = 313,

    // numpad
    key_num_0         = 320,
    key_num_1         = 321,
    key_num_2         = 322,
    key_num_3         = 323,
    key_num_4         = 324,
    key_num_5         = 325,
    key_num_6         = 326,
    key_num_7         = 327,
    key_num_8         = 328,
    key_num_9         = 329,
    key_num_decimal   = 330,
    key_num_divide    = 331,
    key_num_multiply  = 332,
    key_num_subtract  = 333,
    key_num_add       = 334,
    key_num_separator = 335,

    // modifiers
    key_left_shift   = 340,
    key_left_control = 341,
    key_left_alt     = 342,
    key_left_super   = 343,

    key_right_shift   = 344,
    key_right_control = 345,
    key_right_alt     = 346,
    key_right_super   = 347,
};

class Modifiers
{
public:
    enum ModifiersState : int32
    {
        none      = 0,
        shift     = 0x0001,
        control   = 0x0002,
        alt       = 0x0004,
        super     = 0x0008,
        caps_lock = 0x0010,
        num_lock  = 0x0020,
    };

    operator bool();

    Modifiers& operator&=(int32 mask);
    Modifiers& operator|=(int32 mask);

    bool operator==(Modifiers rhs);
    bool operator!=(Modifiers rhs);

private:
    ModifiersState m_state = none;
};

Modifiers operator&(Modifiers modifiers, int32 mask);
Modifiers operator|(Modifiers modifiers, int32 mask);

Modifiers operator&(int32 mask, Modifiers modifiers);
Modifiers operator|(int32 mask, Modifiers modifiers);
} // namespace framework::system

#endif
