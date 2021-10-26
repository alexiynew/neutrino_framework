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

#include <functional>
#include <limits>

#include <common/types.hpp>
#include <common/utils.hpp>
#include <log/log.hpp>

#include <system/src/osx/osx_application.hpp>
#include <system/src/osx/osx_autorelease_pool.hpp>
#include <system/src/osx/osx_context.hpp>
#include <system/src/osx/osx_window.hpp>

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

#pragma region OsxContentView

@interface OsxContentView : NSView
{}
@end

@implementation OsxContentView

- (BOOL)isOpaque
{
    return YES;
}

- (BOOL)canBecomeKeyView
{
    return YES;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (BOOL)wantsUpdateLayer
{
    return YES;
}

- (void)updateLayer
{
    // if (window->context.source == GLFW_NATIVE_CONTEXT_API)
    //    [window->context.nsgl.object update];

    //_glfwInputWindowDamage(window);
}

- (BOOL)acceptsFirstMouse:(NSEvent*)event
{
    return YES;
}

@end // OsxContentView

#pragma endregion

#pragma region OsxWindowInternal

@interface OsxWindowInternal : NSWindow<NSWindowDelegate>

@property(assign, nonatomic) std::function<void()> window_should_close;
@property(assign, nonatomic) std::function<void()> window_did_resize;
@property(assign, nonatomic) std::function<void()> window_did_move;
@property(assign, nonatomic) std::function<void()> window_did_miniaturize;
@property(assign, nonatomic) std::function<void()> window_did_deminiaturize;
@property(assign, nonatomic) std::function<void()> window_did_becomekey;
@property(assign, nonatomic) std::function<void()> window_did_resignkey;

@end

@implementation OsxWindowInternal

@synthesize window_should_close;
@synthesize window_did_resize;
@synthesize window_did_move;
@synthesize window_did_miniaturize;
@synthesize window_did_deminiaturize;
@synthesize window_did_becomekey;
@synthesize window_did_resignkey;

- (BOOL)acceptsFirstResponder
{
    // Supprt cursor grabbing
    return YES;
}

- (BOOL)canBecomeKeyWindow
{
    // Supprt cursor grabbing
    return YES;
}

- (BOOL)canBecomeMainWindow
{
    // Allow fullscreen windows to become the main window
    return YES;
}

- (BOOL)windowShouldClose:(id)sender
{
    self.window_should_close();
    return NO;
}

- (void)windowDidResize:(NSNotification*)notification
{
    self.window_did_resize();
}

- (void)windowDidMove:(NSNotification*)notification
{
    self.window_did_move();
}

- (void)windowDidMiniaturize:(NSNotification*)notification
{
    self.window_did_miniaturize();
}

- (void)windowDidDeminiaturize:(NSNotification*)notification
{
    self.window_did_deminiaturize();
}

- (void)windowDidBecomeKey:(NSNotification*)notification
{
    self.window_did_becomekey();
}

- (void)windowDidResignKey:(NSNotification*)notification
{
    self.window_did_resignkey();
}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification
{}

@end // OsxWindowInternal

#pragma endregion

namespace
{

// Transforms a y-coordinate between the CG display and NS screen spaces
CGFloat transform_y(CGFloat y)
{
    const CGFloat h = CGDisplayBounds(CGMainDisplayID()).size.height;
    return h - y - 1;
}

} // namespace

namespace framework::system::details
{

template <typename T>
class Wrapper
{
public:
    Wrapper(T* value)
        : m_value(value)
    {}

    ~Wrapper()
    {
        [m_value release];
    }

    operator T*()
    {
        return m_value;
    }

    T* get()
    {
        return m_value;
    }

private:
    T* m_value = nullptr;
};

class NSWindowWrapper : public Wrapper<OsxWindowInternal>
{
    using Wrapper::Wrapper;
};

class NSViewWrapper : public Wrapper<OsxContentView>
{
    using Wrapper::Wrapper;
};

OsxWindow::OsxWindow(const std::string& title, Size size, const ContextSettings& context_settings)
    : PlatformWindow()
{
    AutoreleasePool pool;

    if ([NSThread currentThread] != [NSThread mainThread]) {
        throw std::runtime_error("Cannot create a window from a non-main thread");
    }

    [OsxApplication setup];

    unsigned int nsStyle = NSWindowStyleMaskBorderless;
    // if (style & sf::Style::Titlebar)
    nsStyle |= NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable;
    // if (style & sf::Style::Resize)
    nsStyle |= NSWindowStyleMaskResizable;
    // if (style & sf::Style::Close)
    nsStyle |= NSWindowStyleMaskClosable;

    // Create window
    NSRect rect = NSMakeRect(0, 0, size.width, size.height);

    m_window = std::make_unique<NSWindowWrapper>([[OsxWindowInternal alloc] initWithContentRect:rect styleMask:nsStyle
                                                                                        backing:NSBackingStoreBuffered
                                                                                          defer:NO]);
    if (!m_window) {
        throw std::runtime_error("Can't create NSWindow");
    }

    // Setup callbacks
    m_window->get().window_should_close      = std::bind(&OsxWindow::window_should_close, this);
    m_window->get().window_did_resize        = std::bind(&OsxWindow::window_did_resize, this);
    m_window->get().window_did_move          = std::bind(&OsxWindow::window_did_move, this);
    m_window->get().window_did_miniaturize   = std::bind(&OsxWindow::window_did_miniaturize, this);
    m_window->get().window_did_deminiaturize = std::bind(&OsxWindow::window_did_deminiaturize, this);
    m_window->get().window_did_becomekey     = std::bind(&OsxWindow::window_did_becomekey, this);
    m_window->get().window_did_resignkey     = std::bind(&OsxWindow::window_did_resignkey, this);

    // Setup window
    [m_window->get() setDelegate:m_window->get()];

    [m_window->get() setAcceptsMouseMovedEvents:YES];
    [m_window->get() setIgnoresMouseEvents:NO];
    [m_window->get() setRestorable:NO];

    [m_window->get() setReleasedWhenClosed:NO];

    set_title(title);

    // Create view
    m_view = std::make_unique<NSViewWrapper>([OsxContentView alloc]);
    if (!m_view) {
        throw std::runtime_error("Can't create NSView");
    }

    [m_window->get() setContentView:m_view->get()];
    [m_window->get() makeFirstResponder:m_view->get()];

    // Create context
    m_context = std::make_unique<OsxContext>(m_view->get(), context_settings);
}

OsxWindow::~OsxWindow()
{
    [m_window->get() setDelegate:nil];
    [m_window->get() close];
}

#pragma region actions

void OsxWindow::show()
{
    AutoreleasePool pool;

    log::info(title()) << __FUNCTION__ << ":" << __LINE__;

    if (is_visible()) {
        return;
    }

    [m_window->get() orderFront:m_window->get()];
    do {
        process_events();
    } while (!is_visible());
    // explicitly call on_show callback
    on_show();

    [m_window->get() center];

    // explicitly call on_resize callback
    on_resize(size());

    [m_window->get() makeKeyWindow];
    do {
        process_events();
    } while (!has_input_focus());
}

void OsxWindow::hide()
{
    AutoreleasePool pool;

    log::info(title()) << __FUNCTION__ << ":" << __LINE__;

    if (!is_visible()) {
        return;
    }

    [m_window->get() orderOut:m_window->get()];

    for (NSWindow* window in [NSApp orderedWindows]) {
        if (window != m_window->get()) {
            [window orderFrontRegardless];
            [window makeKeyWindow];
            break;
        }
    }

    do {
        process_events();
    } while (is_visible());

    on_hide();
}

void OsxWindow::focus()
{
    AutoreleasePool pool;

    log::info(title()) << __FUNCTION__ << ":" << __LINE__;

    if (!is_visible()) {
        return;
    }

    [m_window->get() orderFrontRegardless];
    [m_window->get() makeKeyWindow];

    do {
        process_events();
    } while (!has_input_focus());
}

void OsxWindow::iconify()
{
    AutoreleasePool pool;
}

void OsxWindow::maximize()
{
    AutoreleasePool pool;
}

void OsxWindow::fullscreen()
{
    AutoreleasePool pool;
}

void OsxWindow::restore()
{
    AutoreleasePool pool;
}

void OsxWindow::resize(Size new_size)
{
    AutoreleasePool pool;

    if (new_size.width <= 0 || new_size.height <= 0) {
        return;
    }

    if (m_min_size.width > 0) {
        new_size.width = std::max(new_size.width, m_min_size.width);
    }

    if (m_min_size.height > 0) {
        new_size.height = std::max(new_size.height, m_min_size.height);
    }

    if (m_max_size.width > 0) {
        new_size.width = std::min(new_size.width, m_max_size.width);
    }

    if (m_max_size.height > 0) {
        new_size.height = std::min(new_size.height, m_max_size.height);
    }

    NSRect rect = [m_window->get() contentRectForFrameRect:[m_window->get() frame]];
    rect.origin.y += rect.size.height - new_size.height;
    rect.size = NSMakeSize(new_size.width, new_size.height);
    [m_window->get() setFrame:[m_window->get() frameRectForContentRect:rect] display:YES];

    process_events();
}

void OsxWindow::move(Position position)
{
    AutoreleasePool pool;

    const NSRect rect  = [m_view->get() frame];
    const NSRect dummy = NSMakeRect(position.x, transform_y(position.y + rect.size.height - 1.0), 0.0, 0.0);
    const NSRect frame = [m_window->get() frameRectForContentRect:dummy];

    [m_window->get() setFrameOrigin:frame.origin];

    process_events();
}

void OsxWindow::grab_cursor()
{
    AutoreleasePool pool;
}

void OsxWindow::release_cursor()
{
    AutoreleasePool pool;
}

void OsxWindow::process_events()
{
    [OsxApplication process_events];
}

#pragma endregion

#pragma region setters

void OsxWindow::set_max_size(Size max_size)
{
    AutoreleasePool pool;

    if (max_size.width >= 0) {
        m_max_size.width = max_size.width;
    }
    if (max_size.height >= 0) {
        m_max_size.height = max_size.height;
    }

    NSSize ns_size = [m_window->get() contentMaxSize];

    if (m_max_size.width > 0) {
        ns_size.width = m_max_size.width;
    } else if (m_max_size.width == 0) {
        ns_size.width = std::numeric_limits<float>::max();
    }

    if (m_max_size.height > 0) {
        ns_size.height = max_size.height;
    } else if (max_size.height == 0) {
        ns_size.height = std::numeric_limits<float>::max();
    }

    [m_window->get() setContentMaxSize:ns_size];
}

void OsxWindow::set_min_size(Size min_size)
{
    AutoreleasePool pool;

    if (min_size.width >= 0) {
        m_min_size.width = min_size.width;
    }
    if (min_size.height >= 0) {
        m_min_size.height = min_size.height;
    }

    NSSize ns_size = [m_window->get() contentMinSize];

    if (min_size.width >= 0) {
        ns_size.width = min_size.width;
    }

    if (min_size.height >= 0) {
        ns_size.height = min_size.height;
    }

    [m_window->get() setContentMinSize:ns_size];
}

void OsxWindow::set_resizable(bool /*value*/)
{
    AutoreleasePool pool;
}

void OsxWindow::set_title(const std::string& new_title)
{
    AutoreleasePool pool;

    NSString* ns_title = [NSString stringWithUTF8String:new_title.c_str()];
    if (ns_title != nil) {
        [m_window->get() setTitle:ns_title];
    }

    process_events();
}

void OsxWindow::set_cursor_visibility(bool /*visible*/)
{
    AutoreleasePool pool;
}

#pragma endregion

#pragma region getters

Position OsxWindow::position() const
{
    AutoreleasePool pool;

    Position position;

    const NSRect contentRect = [m_window->get() contentRectForFrameRect:[m_window->get() frame]];

    position.x = static_cast<int>(contentRect.origin.x);
    position.y = static_cast<int>(transform_y(contentRect.origin.y + contentRect.size.height - 1));

    return position;
}

Size OsxWindow::size() const
{
    AutoreleasePool pool;

    Size size;

    const NSRect contentRect = [m_view->get() frame];

    size.width  = static_cast<int>(contentRect.size.width);
    size.height = static_cast<int>(contentRect.size.height);

    return size;
}

Size OsxWindow::max_size() const
{
    AutoreleasePool pool;

    Size size;
    NSSize ns_size = [m_window->get() contentMaxSize];

    size.width  = std::equal_to<double>()(ns_size.width, std::numeric_limits<float>::max()) ?
                  0 :
                  static_cast<int>(ns_size.width);
    size.height = std::equal_to<double>()(ns_size.height, std::numeric_limits<float>::max()) ?
                  0 :
                  static_cast<int>(ns_size.height);

    return size;
}

Size OsxWindow::min_size() const
{
    AutoreleasePool pool;

    Size size;
    NSSize ns_size = [m_window->get() contentMinSize];

    size.width  = static_cast<int>(ns_size.width);
    size.height = static_cast<int>(ns_size.height);

    return size;
}

std::string OsxWindow::title() const
{
    AutoreleasePool pool;

    return std::string([[m_window->get() title] UTF8String]);
}

const Context& OsxWindow::context() const
{
    return *m_context;
}

Context& OsxWindow::context()
{
    return *m_context;
}

#pragma endregion

#pragma region state
bool OsxWindow::should_close() const
{
    return m_should_close;
}

bool OsxWindow::is_fullscreen() const
{
    return false;
}

bool OsxWindow::is_iconified() const
{
    return false;
}

bool OsxWindow::is_maximized() const
{
    return false;
}

bool OsxWindow::is_resizable() const
{
    return false;
}

bool OsxWindow::is_visible() const
{
    return [m_window->get() isVisible];
}

bool OsxWindow::has_input_focus() const
{
    return [m_window->get() isKeyWindow];
}

bool OsxWindow::is_cursor_visible() const
{
    return false;
}

bool OsxWindow::is_cursor_grabbed() const
{
    return false;
}

#pragma endregion

#pragma region NSWindowDelegate callbacks

void OsxWindow::window_should_close()
{
    m_should_close = true;
    on_close();
}

void OsxWindow::window_did_resize()
{
    AutoreleasePool pool;

    if (is_visible()) {
        m_context->update();

        // if (_glfw.ns.disabledCursorWindow == window)
        //    _glfwCenterCursorInContentArea(window);

        on_resize(size());
    }
}

void OsxWindow::window_did_move()
{
    AutoreleasePool pool;

    if (is_visible()) {
        m_context->update();

        // if (_glfw.ns.disabledCursorWindow == window)
        //    _glfwCenterCursorInContentArea(window);

        on_move(position());
    }
}

void OsxWindow::window_did_miniaturize()
{
    AutoreleasePool pool;
    log::info(title()) << __FUNCTION__ << ":" << __LINE__;
}

void OsxWindow::window_did_deminiaturize()
{
    AutoreleasePool pool;
    log::info(title()) << __FUNCTION__ << ":" << __LINE__;
}

void OsxWindow::window_did_becomekey()
{
    on_focus();
}

void OsxWindow::window_did_resignkey()
{
    on_lost_focus();
}

#pragma endregion

} // namespace framework::system::details
