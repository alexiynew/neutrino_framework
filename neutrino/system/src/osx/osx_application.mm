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

#import <system/src/osx/osx_application.hpp>

@implementation OsxApplication

+ (void)setup
{
    @autoreleasepool {
        static bool isTheProcessSetAsApplication = false;

        if (!isTheProcessSetAsApplication) {
            isTheProcessSetAsApplication = true;

            [OsxApplication sharedApplication];

            [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
            [NSApp activateIgnoringOtherApps:YES];

            if (![NSApp delegate])
                [NSApp setDelegate:static_cast<OsxApplication*>(NSApp)];

            [OsxApplication setup_menu_bar];

            [NSApp finishLaunching];
        }
    }
}

+ (void)setup_menu_bar
{
    @autoreleasepool {
        NSMenu* mainMenu = [NSApp mainMenu];
        if (mainMenu != nil) {
            return;
        }

        mainMenu = [[[NSMenu alloc] initWithTitle:@""] autorelease];
    }
}

+ (void)process_events
{
    @autoreleasepool {
        NSEvent* event = nil;

        while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast]
                                              inMode:NSDefaultRunLoopMode
                                             dequeue:YES])) {
            [NSApp sendEvent:event];
        }
    }
}

- (void)sendEvent:(NSEvent*)event
{
    @autoreleasepool {
        [super sendEvent:event];
    }
}

#pragma region NSApplicationDelegate

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)app
{
    // send close window event to all windows
    return NSTerminateCancel;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)app
{
    return NO;
}

- (void)applicationDidChangeScreenParameters:(NSNotification*)notification
{}

- (void)applicationWillFinishLaunching:(NSNotification*)notification
{
    // Menu bar setup must go between sharedApplication and finishLaunching
    // in order to properly emulate the behavior of NSApplicationMain
    // createMenuBar();
}

- (void)applicationDidFinishLaunching:(NSNotification*)notification
{
    [NSApp stop:nil];
}

#pragma endregion

@end
