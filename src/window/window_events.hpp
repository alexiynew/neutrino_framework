/// @file
/// @brief Window events.
/// @author Fedorov Alexey
/// @date 15.12.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#ifndef FRAMEWORK_WINDOW_WINDOW_HPP
#define FRAMEWORK_WINDOW_WINDOW_HPP

namespace framework::system::window_event
{
struct show
{};

struct hide
{};

struct focus
{};

struct focus_lost
{};

struct iconify
{};

struct fullscreen
{};

struct change_size
{};

struct change_position
{};

struct key_down
{};

struct key_up
{};

struct character
{};

struct mouse_button_down
{};

struct mouse_button_up
{};

struct mouse_enter
{};

struct mouse_leave
{};

struct mouse_move
{};

} // namespace framework::system::window_event

#endif
