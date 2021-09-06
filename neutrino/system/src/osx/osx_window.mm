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

#include <system/src/osx/osx_application.hpp>
#include <system/src/osx/osx_context.hpp>
#include <system/src/osx/osx_window.hpp>

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

#pragma region OSXWindowInternal

@interface OSXWindowInternal : NSWindow
{}
@end

@implementation OSXWindowInternal

- (BOOL)canBecomeKeyWindow
{
    // Required for NSWindowStyleMaskBorderless windows
    return YES;
}

- (BOOL)canBecomeMainWindow
{
    return YES;
}

@end

#pragma endregion

#pragma region OSXWindowDelegate

@interface OSXWindowDelegate : NSObject<NSWindowDelegate>
{}

@property(assign, nonatomic) std::function<void()> on_close;

@end

@implementation OSXWindowDelegate

@synthesize on_close;

- (BOOL)windowShouldClose:(id)sender
{
    self.on_close();
    return NO;
}

- (void)windowDidResize:(NSNotification*)notification
{}

- (void)windowDidMove:(NSNotification*)notification
{}

- (void)windowDidMiniaturize:(NSNotification*)notification
{}

- (void)windowDidDeminiaturize:(NSNotification*)notification
{}

- (void)windowDidBecomeKey:(NSNotification*)notification
{}

- (void)windowDidResignKey:(NSNotification*)notification
{}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification
{}

@end

#pragma endregion

#pragma region OSXContentView

@interface OSXContentView : NSView
{}
@end

@implementation OSXContentView
@end

#pragma endregion

namespace framework::system::details
{

class NSWindowWrapper
{
public:
    explicit NSWindowWrapper(NSWindow* window)
        : m_window(window)
    {}

    NSWindow* get() const
    {
        return m_window;
    }

private:
    NSWindow* m_window = nullptr;
};

OSXWindow::OSXWindow(const std::string& title, Size size, const ContextSettings& context_settings)
    : PlatformWindow()
{
    [OSXApplication setup];

    unsigned int nsStyle = NSWindowStyleMaskBorderless;
    // if (style & sf::Style::Titlebar)
    nsStyle |= NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable;
    // if (style & sf::Style::Resize)
    nsStyle |= NSWindowStyleMaskResizable;
    // if (style & sf::Style::Close)
    nsStyle |= NSWindowStyleMaskClosable;

    OSXWindowInternal* window = [[OSXWindowInternal alloc] initWithContentRect:NSMakeRect(0, 0, size.width, size.height)
                                                                     styleMask:nsStyle
                                                                       backing:NSBackingStoreBuffered
                                                                         defer:NO];

    m_window_wrapper = std::make_unique<NSWindowWrapper>(window);

    // Set the view to the window as its content view.
    OSXContentView* view = [OSXContentView alloc];
    [m_window_wrapper->get() setContentView:view];
    [m_window_wrapper->get() makeFirstResponder:view];

    // Set title
    NSString* ns_title = [NSString stringWithUTF8String:title.c_str()];
    if (ns_title != nil) {
        [m_window_wrapper->get() setTitle:ns_title];
    }

    // Setup delegate
    OSXWindowDelegate* delegate = [OSXWindowDelegate alloc];
    delegate.on_close           = std::bind(&OSXWindow::on_close, this);

    [m_window_wrapper->get() setDelegate:delegate];

    // Setup window
    [m_window_wrapper->get() setAcceptsMouseMovedEvents:YES];
    [m_window_wrapper->get() setIgnoresMouseEvents:NO];
    [m_window_wrapper->get() setRestorable:NO];

    [m_window_wrapper->get() center];
    [m_window_wrapper->get() setReleasedWhenClosed:NO]; // We own the class, not AppKit

    m_context = std::make_unique<OsxContext>(context_settings);
}

OSXWindow::~OSXWindow()
{
    [m_window_wrapper->get() setDelegate:nil];
    [m_window_wrapper->get() close];

    [OSXApplication drain_thread_pool];
}

#pragma region actions

void OSXWindow::show()
{
    [m_window_wrapper->get() makeKeyAndOrderFront:m_window_wrapper->get()];
    
    do {
        process_events();
    } while (!is_visible());
    
    on_show();
}

void OSXWindow::hide()
{
    [m_window_wrapper->get() orderOut:m_window_wrapper->get()];

    do {
        process_events();
    } while (is_visible());
    
    on_hide();
}

void OSXWindow::focus()
{}

void OSXWindow::iconify()
{}

void OSXWindow::maximize()
{}

void OSXWindow::fullscreen()
{}

void OSXWindow::restore()
{}

void OSXWindow::resize(Size /*size*/)
{}

void OSXWindow::move(Position /*position*/)
{}

void OSXWindow::grab_cursor()
{}

void OSXWindow::release_cursor()
{}

void OSXWindow::process_events()
{
    [OSXApplication process_events];
}

#pragma endregion

#pragma region setters

void OSXWindow::set_max_size(Size /*size*/)
{}

void OSXWindow::set_min_size(Size /*size*/)
{}

void OSXWindow::set_resizable(bool /*value*/)
{}

void OSXWindow::set_title(const std::string& /*title*/)
{}

void OSXWindow::set_cursor_visibility(bool /*visible*/)
{}

#pragma endregion

#pragma region getters

Position OSXWindow::position() const
{
    return {0, 0};
}

Size OSXWindow::size() const
{
    return {0, 0};
}

Size OSXWindow::max_size() const
{
    return {0, 0};
}

Size OSXWindow::min_size() const
{
    return {0, 0};
}

std::string OSXWindow::title() const
{
    return "";
}

const Context& OSXWindow::context() const
{
    return *m_context.get();
}

Context& OSXWindow::context()
{
    return *m_context.get();
}

#pragma endregion

#pragma region state
bool OSXWindow::should_close() const
{
    return true;
}

bool OSXWindow::is_fullscreen() const
{
    return false;
}

bool OSXWindow::is_iconified() const
{
    return false;
}

bool OSXWindow::is_maximized() const
{
    return false;
}

bool OSXWindow::is_resizable() const
{
    return false;
}

bool OSXWindow::is_visible() const
{
    return [m_window_wrapper->get() isVisible];
}

bool OSXWindow::has_input_focus() const
{
    return false;
}

bool OSXWindow::is_cursor_visible() const
{
    return false;
}

bool OSXWindow::is_cursor_grabbed() const
{
    return false;
}

#pragma endregion

} // namespace framework::system::details
