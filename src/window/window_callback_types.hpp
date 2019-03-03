/// @file
/// @brief Window event types.
/// @author Fedorov Alexey
/// @date 01.03.2019

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

#ifndef FRAMEWORK_WINDOW_WINDOW_EVENT_TYPES_HPP
#define FRAMEWORK_WINDOW_WINDOW_EVENT_TYPES_HPP

#include <functional>

#include <window/keyboard.hpp>
#include <window/window_position.hpp>
#include <window/window_size.hpp>

namespace framework::system
{
class window;

/// @addtogroup window_class
/// @{

using window_event_callback              = std::function<void(const window&)>;
using window_size_event_callback         = std::function<void(const window&, window_size)>;
using window_position_event_callback     = std::function<void(const window&, window_position)>;
using window_key_event_callback          = std::function<void(const window&, key_code, modifiers_state)>;
using window_character_event_callback    = std::function<void(const window&, std::string)>;
using window_mouse_button_event_callback = std::function<void(const window&, mouse_button, modifiers_state)>;
using window_mouse_button_event_callback = std::function<void(const window&, mouse_button, modifiers_state)>;

/// @}

} // namespace framework::system

#endif
