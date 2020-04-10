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

#include <system/src/osx/osx_application.hpp>
#include <system/src/osx/osx_application_delegate.hpp>
#include <system/src/osx/osx_window.hpp>
#include <system/src/osx/osx_window_wrapper.hpp>

namespace framework::system::details
{
void OSXWindowWrapper::setup_application()
{
    static bool isTheProcessSetAsApplication = false;

    if (!isTheProcessSetAsApplication) {
        isTheProcessSetAsApplication = true;

        [OSXApplication sharedApplication];

        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        [NSApp activateIgnoringOtherApps:YES];

        if (![[OSXApplication sharedApplication] delegate])
            [[NSApplication sharedApplication] setDelegate:[[OSXApplicationDelegate alloc] init]];

        [OSXApplication setup_menu_bar];

        [[OSXApplication sharedApplication] finishLaunching];
    }
}

static NSAutoreleasePool* pool;

void OSXWindowWrapper::ensureThreadHasPool()
{
    pool = [[NSAutoreleasePool alloc] init];
}

void OSXWindowWrapper::drainThreadPool()
{
    [pool drain];
    ensureThreadHasPool();
}

OSXWindowWrapper::OSXWindowWrapper(const Window& window_interface,
                                   Size size,
                                   const std::string& /*title*/,
                                   const context_settings& /*settings*/)
    : PlatformWindow(window_interface)
    , m_window(nullptr)
{
    setup_application();

    // Ask for a pool.
    ensureThreadHasPool();

    unsigned int nsStyle = NSWindowStyleMaskBorderless;
    // if (style & sf::Style::Titlebar)
    nsStyle |= NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable;
    // if (style & sf::Style::Resize)
    nsStyle |= NSWindowStyleMaskResizable;
    // if (style & sf::Style::Close)
    nsStyle |= NSWindowStyleMaskClosable;

    OSXWindow* window = [[OSXWindow alloc] initWithContentRect:NSMakeRect(0, 0, size.width, size.height)
                                                     styleMask:nsStyle
                                                       backing:NSBackingStoreBuffered
                                                         defer:NO];

    //[m_delegate changeTitle:sfStringToNSString(title)];
    //[m_delegate setRequesterTo:this];

    // Set the view to the window as its content view.
    // [m_window setContentView:m_oglView];

    // Register for event.
    //  [window setDelegate:window];
    [window setAcceptsMouseMovedEvents:YES];
    [window setIgnoresMouseEvents:NO];

    // And some other things...
    [window center];
    //  [window setAutodisplay:YES];
    [window setReleasedWhenClosed:NO]; // We own the class, not AppKit

    m_window = window;
}

OSXWindowWrapper::~OSXWindowWrapper()
{
    OSXWindow* window = reinterpret_cast<OSXWindow*>(m_window);

    [window close];
    [window setDelegate:nil];

    // Put the next window in front, if any.
    //  NSArray* windows = [NSApp orderedWindows];
    // if ([windows count] > 0)
    //   [[windows objectAtIndex:0] makeKeyAndOrderFront:nil];

    drainThreadPool();
}

#pragma region actions

void OSXWindowWrapper::show()
{
    OSXWindow* window = reinterpret_cast<OSXWindow*>(m_window);
    [window makeKeyAndOrderFront:window];
}

void OSXWindowWrapper::hide()
{
    [reinterpret_cast<OSXWindow*>(m_window) hide];
}

void OSXWindowWrapper::focus()
{
    [reinterpret_cast<OSXWindow*>(m_window) focus];
}

void OSXWindowWrapper::iconify()
{}

void OSXWindowWrapper::maximize()
{}

void OSXWindowWrapper::fullscreen()
{}

void OSXWindowWrapper::restore()
{}

void OSXWindowWrapper::resize(Size /*size*/)
{}

void OSXWindowWrapper::move(Position /*position*/)
{}

void OSXWindowWrapper::process_events()
{
    [OSXApplication process_events];
    drainThreadPool(); // Reduce memory footprint
}

void OSXWindowWrapper::make_current()
{}

void OSXWindowWrapper::swap_buffers()
{}

#pragma endregion

#pragma region setters

void OSXWindowWrapper::set_max_size(Size /*size*/)
{}

void OSXWindowWrapper::set_min_size(Size /*size*/)
{}

void OSXWindowWrapper::set_resizable(bool /*value*/)
{}

void OSXWindowWrapper::set_title(const std::string& /*title*/)
{}

#pragma endregion

#pragma region getters

Position OSXWindowWrapper::position() const
{
    return {0, 0};
}

Size OSXWindowWrapper::size() const
{
    return {0, 0};
}

Size OSXWindowWrapper::max_size() const
{
    return {0, 0};
}

Size OSXWindowWrapper::min_size() const
{
    return {0, 0};
}

std::string OSXWindowWrapper::title() const
{
    return "";
}

#pragma endregion

#pragma region state
bool OSXWindowWrapper::should_close() const
{
    return true;
}

bool OSXWindowWrapper::is_fullscreen() const
{
    return false;
}

bool OSXWindowWrapper::is_iconified() const
{
    return false;
}

bool OSXWindowWrapper::is_maximized() const
{
    return false;
}

bool OSXWindowWrapper::is_resizable() const
{
    return false;
}

bool OSXWindowWrapper::is_visible() const
{
    return [reinterpret_cast<OSXWindow*>(m_window) isVisible];
}

bool OSXWindowWrapper::has_input_focus() const
{
    return false;
}

#pragma endregion

} // namespace framework::system::details
