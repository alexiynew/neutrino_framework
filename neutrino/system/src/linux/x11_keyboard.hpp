/// @file
/// @brief Helper functions for keyboard handling.
/// @author Fedorov Alexey
/// @date 11.03.2019

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

#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_X11_KEYBOARD_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_X11_KEYBOARD_HPP

#include <system/keyboard.hpp>

#include <system/src/linux/x11_server.hpp>

namespace framework::system::details
{
void init_key_code_map(const x11_server* server);

key_code map_system_key(uint32 key);
modifiers_state get_modifiers_state(uint32 state);

} // namespace framework::system::details

#endif
