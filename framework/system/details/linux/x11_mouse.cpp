/// @file
/// @brief Types and functions for mouse support.
/// @author Fedorov Alexey
/// @date 29.03.2019

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

#include <X11/Xlib.h>

#include <system/details/linux/x11_mouse.hpp>

namespace framework::system::details
{
mouse_button map_mouse_button(uint32 button)
{
    switch (button) {
        case Button1: return mouse_button::button_left;
        case Button2: return mouse_button::button_middle;
        case Button3: return mouse_button::button_right;
        case Button4: return mouse_button::button_unknown; // whell up
        case Button5: return mouse_button::button_unknown; // whell down
    }

    return mouse_button::button_unknown;
}

} // namespace framework::system::details
