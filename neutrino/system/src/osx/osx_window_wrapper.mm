/// @file
/// @brief Window implementation for OSX.
/// @author Fedorov Alexey
/// @date 20.12.2017

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

#include <common/types.hpp>
#include <common/utils.hpp>

#include <system/src/osx/osx_window.hpp>
#include <system/src/osx/osx_window_wrapper.hpp>

namespace framework::system::details
{
osx_window_wrapper::osx_window_wrapper(window_size /*size*/,
                                       const std::string& /*title*/,
                                       const context_settings& /*settings*/)
    : self(nullptr)
{
    self = [[osx_window alloc] init];
}

osx_window_wrapper::~osx_window_wrapper()
{
    [reinterpret_cast<osx_window*>(self) dealloc];
}

#pragma region actions

void osx_window_wrapper::show()
{
    [reinterpret_cast<osx_window*>(self) show];
}

void osx_window_wrapper::hide()
{
    [reinterpret_cast<osx_window*>(self) hide];
}

void osx_window_wrapper::focus()
{
    [reinterpret_cast<osx_window*>(self) focus];
}

void osx_window_wrapper::process_events()
{
    [reinterpret_cast<osx_window*>(self) process_events];
}

void osx_window_wrapper::iconify()
{}

void osx_window_wrapper::maximize()
{}

void osx_window_wrapper::switch_to_fullscreen()
{}

void osx_window_wrapper::restore()
{}

void osx_window_wrapper::make_current()
{}

void osx_window_wrapper::swap_buffers()
{}

#pragma endregion

#pragma region setters

void osx_window_wrapper::set_size(window_size /*size*/)
{}

void osx_window_wrapper::set_position(window_position /*position*/)
{}

void osx_window_wrapper::set_max_size(window_size /*max_size*/)
{}

void osx_window_wrapper::set_min_size(window_size /*min_size*/)
{}

void osx_window_wrapper::set_resizable(bool /*value*/)
{}

void osx_window_wrapper::set_title(const std::string& /*title*/)
{}

#pragma endregion

#pragma region getters

window_position osx_window_wrapper::position() const
{
    return {0, 0};
}

window_size osx_window_wrapper::size() const
{
    return {0, 0};
}

window_size osx_window_wrapper::max_size() const
{
    return {0, 0};
}

window_size osx_window_wrapper::min_size() const
{
    return {0, 0};
}

std::string osx_window_wrapper::title() const
{
    return "";
}

#pragma endregion

#pragma region state

bool osx_window_wrapper::fullscreen() const
{
    return false;
}

bool osx_window_wrapper::iconified() const
{
    return false;
}

bool osx_window_wrapper::maximized() const
{
    return false;
}

bool osx_window_wrapper::resizable() const
{
    return false;
}

bool osx_window_wrapper::visible() const
{
    return false;
}

bool osx_window_wrapper::focused() const
{
    return false;
}

#pragma endregion
} // namespace framework::system::details
