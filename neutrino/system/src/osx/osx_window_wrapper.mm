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
OsxWindowWrapper::OsxWindowWrapper(const Window& window_interface,
                                   Size /*size*/,
                                   const std::string& /*title*/,
                                   const context_settings& /*settings*/)
    : PlatformWindow(window_interface)
    , self(nullptr)
{
    self = [[OsxWindow alloc] init];
}

OsxWindowWrapper::~OsxWindowWrapper()
{
    [reinterpret_cast<OsxWindow*>(self) dealloc];
}

#pragma region actions

void OsxWindowWrapper::show()
{
    [reinterpret_cast<OsxWindow*>(self) show];
}

void OsxWindowWrapper::hide()
{
    [reinterpret_cast<OsxWindow*>(self) hide];
}

void OsxWindowWrapper::focus()
{
    [reinterpret_cast<OsxWindow*>(self) focus];
}

void OsxWindowWrapper::iconify()
{}

void OsxWindowWrapper::maximize()
{}

void OsxWindowWrapper::fullscreen()
{}

void OsxWindowWrapper::restore()
{}

void OsxWindowWrapper::resize(Size /*size*/)
{}

void OsxWindowWrapper::move(Position /*position*/)
{}

void OsxWindowWrapper::process_events()
{
    [reinterpret_cast<OsxWindow*>(self) process_events];
}

void OsxWindowWrapper::make_current()
{}

void OsxWindowWrapper::swap_buffers()
{}

#pragma endregion

#pragma region setters

void OsxWindowWrapper::set_max_size(Size /*size*/)
{}

void OsxWindowWrapper::set_min_size(Size /*size*/)
{}

void OsxWindowWrapper::set_resizable(bool /*value*/)
{}

void OsxWindowWrapper::set_title(const std::string& /*title*/)
{}

#pragma endregion

#pragma region getters

Position OsxWindowWrapper::position() const
{
    return {0, 0};
}

Size OsxWindowWrapper::size() const
{
    return {0, 0};
}

Size OsxWindowWrapper::max_size() const
{
    return {0, 0};
}

Size OsxWindowWrapper::min_size() const
{
    return {0, 0};
}

std::string OsxWindowWrapper::title() const
{
    return "";
}

#pragma endregion

#pragma region state
bool OsxWindowWrapper::should_close() const
{
    return true;
}

bool OsxWindowWrapper::is_fullscreen() const
{
    return false;
}

bool OsxWindowWrapper::is_iconified() const
{
    return false;
}

bool OsxWindowWrapper::is_maximized() const
{
    return false;
}

bool OsxWindowWrapper::is_resizable() const
{
    return false;
}

bool OsxWindowWrapper::is_visible() const
{
    return false;
}

bool OsxWindowWrapper::has_input_focus() const
{
    return false;
}

#pragma endregion

} // namespace framework::system::details
