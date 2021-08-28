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

#include <common/types.hpp>
#include <common/utils.hpp>

#include <system/src/osx/osx_window.hpp>

#import <Foundation/Foundation.h>

@implementation OSXWindow

#pragma region actions

- (void)show
{
    NSLog(@"Show");
}

- (void)hide
{
    NSLog(@"Hide");
}

- (void)focus
{
    NSLog(@"focus");
}

- (void)process_events
{
    NSLog(@"process_events");
}

@end

// void osx_window::iconify()
//{}
//
// void osx_window::maximize()
//{}
//
// void osx_window::switch_to_fullscreen()
//{}
//
// void osx_window::restore()
//{}
//
// void osx_window::make_current()
//{}
//
// void osx_window::swap_buffers()
//{}
//
//#pragma endregion
//
//#pragma region setters
//
// void osx_window::set_size(window_size /*size*/)
//{}
//
// void osx_window::set_position(window_position /*position*/)
//{}
//
// void osx_window::set_max_size(window_size /*max_size*/)
//{}
//
// void osx_window::set_min_size(window_size /*min_size*/)
//{}
//
// void osx_window::set_resizable(bool /*value*/)
//{}
//
// void osx_window::set_title(const std::string& /*title*/)
//{}
//
//#pragma endregion
//
//#pragma region getters
//
// window_position osx_window::position() const
//{
//    return {0, 0};
//}
//
// window_size osx_window::size() const
//{
//    return {0, 0};
//}
//
// window_size osx_window::max_size() const
//{
//    return {0, 0};
//}
//
// window_size osx_window::min_size() const
//{
//    return {0, 0};
//}
//
// std::string osx_window::title() const
//{
//    return "";
//}
//
//#pragma endregion
//
//#pragma region state
//
// bool osx_window::fullscreen() const
//{
//    return false;
//}
//
// bool osx_window::iconified() const
//{
//    return false;
//}
//
// bool osx_window::maximized() const
//{
//    return false;
//}
//
// bool osx_window::resizable() const
//{
//    return false;
//}
//
// bool osx_window::visible() const
//{
//    return false;
//}
//
// bool osx_window::focused() const
//{
//    return false;
//}
//
//#pragma endregion
//} // namespace framework::system::details
//
