/// @file
/// @brief Window implementation for OSX.
/// @author Fedorov Alexey
/// @date 06.03.2020

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

#ifndef FRAMEWORK_SYSTEM_SRC_OSX_OSX_APPLICATION_DELEGATE_HPP
#define FRAMEWORK_SYSTEM_SRC_OSX_OSX_APPLICATION_DELEGATE_HPP

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

@interface OSXApplicationDelegate : NSObject<NSApplicationDelegate>

/// @brief React to a termination notification
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)app;

/// @brief Exit the app when all windows are closed
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)app;

@end

#endif
