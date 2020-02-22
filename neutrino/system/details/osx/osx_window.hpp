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

#ifndef FRAMEWORK_WINDOW_DETAILS_OSX_OSX_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_OSX_OSX_WINDOW_HPP

#import <Foundation/NSObject.h>

#include <system/details/osx/osx_window.hpp>

@interface osx_window : NSObject
{}

    /// @name actions
    /// @{
    -(void) show;
    -(void) hide;
    -(void) focus;
    -(void) process_events;

@end

//    // On window managers without the ewmh support, proper work is not tested, nor granted.
//    void iconify();
//    void maximize();
//    void switch_to_fullscreen();
//    void restore();
//    void make_current();
//    void swap_buffers();
//    /// @}
//
//    /// @name setters
//    /// @{
//
//    // The size() value will be updated after next event processing
//    void set_size(window_size size);
//    void set_position(window_position position);
//
//    void set_max_size(window_size max_size);
//    void set_min_size(window_size min_size);
//
//    void set_resizable(bool value);
//
//    void set_title(const std::string& title);
//    /// @}
//
//    /// @name getters
//    /// @{
//    window_position position() const;
//    window_size size() const;
//
//    window_size max_size() const;
//    window_size min_size() const;
//
//    std::string title() const;
//    /// @}
//
//    /// @name state
//    /// @{
//    bool fullscreen() const;
//    bool iconified() const;
//    bool maximized() const;
//    bool resizable() const;
//    bool visible() const;
//    bool focused() const;
//    /// @}

#endif
