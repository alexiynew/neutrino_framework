/**
 * @file cocoa_window.cpp
 * @brief Window implementation for osx.
 * @author Fedorov Alexey
 * @date 19.04.2017
 */

#include <memory>
#include <window/osx/cocoa_window.hpp>
#include <iostream>

namespace framework {

std::unique_ptr<window_implementation> get_implementation()
{
    return std::make_unique<cocoa_window>();
}

cocoa_window::cocoa_window()
{   
    // Create a shared app instance.
    // This will initialize the global variable
    // 'NSApp' with the application instance.
    [NSApplication sharedApplication];

    // Autorelease Pool:
    // Objects declared in this scope will be automatically
    // released at the end of it, when the pool is "drained".
    pool = [[NSAutoreleasePool alloc] init];
}

cocoa_window::~cocoa_window()
{
	std::cout << "~cocoa_window" << std::endl;
    [pool drain];
    [NSApp stop:nil];
}

void cocoa_window::show()
{
    // Style flags:
    NSUInteger windowStyle = NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask;

    // Window bounds (x, y, width, height).
    NSRect windowRect = NSMakeRect(100, 100, 400, 400);
    window = [[NSWindow alloc] initWithContentRect:windowRect
                                          styleMask:windowStyle
                                          backing:NSBackingStoreBuffered
                                          defer:NO];
    [window autorelease];

    // Window controller:
    NSWindowController * windowController = [[NSWindowController alloc] initWithWindow:window];
    [windowController autorelease];

    // TODO: Create app delegate to handle system events.

    // Show window and run event loop.
    [window orderFrontRegardless];
    [NSApp run];
}

void cocoa_window::hide()
{
	std::cout << "cocoa_window::hide" << std::endl;
	[window orderOut:nil];
}
}
