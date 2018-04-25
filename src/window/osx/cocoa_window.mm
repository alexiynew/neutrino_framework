/// @file
/// @brief Window implementation for osx.
/// @author Fedorov Alexey
/// @date 19.04.2017

#include <iostream>
#include <memory>

#include <window/osx/cocoa_window.hpp>

namespace framework {

std::unique_ptr<window::implementation> window::implementation::get_implementation(window::size_t, const std::string&)
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
    [pool drain];
    [NSApp stop:nil];
}

void cocoa_window::show()
{
    // Style flags:
    NSUInteger windowStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

    // Window bounds (x, y, width, height).
    NSRect windowRect = NSMakeRect(100, 100, 400, 400);
    window            = [[NSWindow alloc] initWithContentRect:windowRect
                                         styleMask:windowStyle
                                           backing:NSBackingStoreBuffered
                                             defer:NO];
    [window autorelease];

    // Window controller:
    NSWindowController* windowController = [[NSWindowController alloc] initWithWindow:window];
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

void cocoa_window::focus()
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::process_events()
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::minimize()
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::maximize()
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::switch_to_fullscreen()
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::restore()
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::set_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::set_position(window::position_t)
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::set_max_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::set_min_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::set_resizable(bool)
{
    throw std::logic_error("Function is not implemented.");
}

void cocoa_window::set_title(const std::string&)
{
    throw std::logic_error("Function is not implemented.");
}

window::position_t cocoa_window::position() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t cocoa_window::size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t cocoa_window::max_size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t cocoa_window::min_size() const
{
    throw std::logic_error("Function is not implemented.");
}

std::string cocoa_window::title() const
{
    throw std::logic_error("Function is not implemented.");
}

bool cocoa_window::fullscreen() const
{
    throw std::logic_error("Function is not implemented.");
}

bool cocoa_window::minimized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool cocoa_window::maximized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool cocoa_window::resizable() const
{
    throw std::logic_error("Function is not implemented.");
}

bool cocoa_window::visible() const
{
    throw std::logic_error("Function is not implemented.");
}

bool cocoa_window::focused() const
{
    throw std::logic_error("Function is not implemented.");
}

} // namespace framework
