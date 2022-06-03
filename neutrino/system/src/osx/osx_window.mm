#include <chrono>
#include <functional>
#include <limits>
#include <thread>

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

@property(assign, nonatomic) std::function<void()> update_context;

@end

@implementation OsxContentView

@synthesize update_context;

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
    self.update_context();
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
@property(assign, nonatomic) std::function<void()> window_did_enter_full_screen;
@property(assign, nonatomic) std::function<void()> window_did_exit_full_screen;

@end

@implementation OsxWindowInternal

@synthesize window_should_close;
@synthesize window_did_resize;
@synthesize window_did_move;
@synthesize window_did_miniaturize;
@synthesize window_did_deminiaturize;
@synthesize window_did_becomekey;
@synthesize window_did_resignkey;
@synthesize window_did_enter_full_screen;
@synthesize window_did_exit_full_screen;

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
    if (self.window_should_close) {
        self.window_should_close();
    }
    return NO;
}

- (void)windowDidResize:(NSNotification*)notification
{
    if (self.window_did_resize) {
        self.window_did_resize();
    }
}

- (void)windowDidMove:(NSNotification*)notification
{
    if (self.window_did_move) {
        self.window_did_move();
    }
}

- (void)windowDidMiniaturize:(NSNotification*)notification
{
    if (self.window_did_miniaturize) {
        self.window_did_miniaturize();
    }
}

- (void)windowDidDeminiaturize:(NSNotification*)notification
{
    if (self.window_did_deminiaturize) {
        self.window_did_deminiaturize();
    }
}

- (void)windowDidBecomeKey:(NSNotification*)notification
{
    if (self.window_did_becomekey) {
        self.window_did_becomekey();
    }
}

- (void)windowDidResignKey:(NSNotification*)notification
{
    if (self.window_did_resignkey) {
        self.window_did_resignkey();
    }
}

- (void)windowDidEnterFullScreen:(NSNotification*)notification
{
    if (self.window_did_enter_full_screen) {
        self.window_did_enter_full_screen();
    }
}

- (void)windowDidExitFullScreen:(NSNotification*)notification
{
    if (self.window_did_exit_full_screen) {
        self.window_did_exit_full_screen();
    }
}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification
{}

@end // OsxWindowInternal

#pragma endregion

namespace
{

// TODO: figure out why we need this function
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
        AutoreleasePool pool;

        [m_value autorelease];
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

    NSWindowStyleMask ns_style = NSWindowStyleMaskBorderless;
    // if (style & sf::Style::Titlebar)
    ns_style |= NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable;
    // if (style & sf::Style::Resize)
    ns_style |= NSWindowStyleMaskResizable;
    // if (style & sf::Style::Close)
    ns_style |= NSWindowStyleMaskClosable;

    // Create window
    NSRect rect = NSMakeRect(0, 0, size.width, size.height);

    m_window = std::make_unique<NSWindowWrapper>([[OsxWindowInternal alloc] initWithContentRect:rect styleMask:ns_style
                                                                                        backing:NSBackingStoreBuffered
                                                                                          defer:NO]);
    if (!m_window) {
        throw std::runtime_error("Can't create NSWindow");
    }

    // Setup callbacks
    m_window->get().window_should_close          = std::bind(&OsxWindow::window_should_close, this);
    m_window->get().window_did_resize            = std::bind(&OsxWindow::window_did_resize, this);
    m_window->get().window_did_move              = std::bind(&OsxWindow::window_did_move, this);
    m_window->get().window_did_miniaturize       = std::bind(&OsxWindow::window_did_miniaturize, this);
    m_window->get().window_did_deminiaturize     = std::bind(&OsxWindow::window_did_deminiaturize, this);
    m_window->get().window_did_becomekey         = std::bind(&OsxWindow::window_did_becomekey, this);
    m_window->get().window_did_resignkey         = std::bind(&OsxWindow::window_did_resignkey, this);
    m_window->get().window_did_enter_full_screen = std::bind(&OsxWindow::window_did_enter_full_screen, this);
    m_window->get().window_did_exit_full_screen  = std::bind(&OsxWindow::window_did_exit_full_screen, this);

    // Setup window
    [m_window->get() setDelegate:m_window->get()];

    [m_window->get() setAcceptsMouseMovedEvents:YES];
    [m_window->get() setIgnoresMouseEvents:NO];
    [m_window->get() setRestorable:NO];

    [m_window->get() setReleasedWhenClosed:NO];

    const NSWindowCollectionBehavior behavior = NSWindowCollectionBehaviorFullScreenPrimary |
                                                NSWindowCollectionBehaviorManaged;
    [m_window->get() setCollectionBehavior:behavior];

    set_title(title);

    // Create view
    m_view = std::make_unique<NSViewWrapper>([OsxContentView alloc]);
    if (!m_view) {
        throw std::runtime_error("Can't create NSView");
    }

    [m_view->get() setWantsLayer:YES];
    [[m_view->get() layer] setContentsScale:[m_window->get() backingScaleFactor]];
    m_view->get().update_context = std::bind(&OsxWindow::update_context, this);

    [m_window->get() setContentView:m_view->get()];
    [m_window->get() makeFirstResponder:m_view->get()];

    // Create context
    m_context = std::make_unique<OsxContext>(m_view->get(), context_settings);
}

OsxWindow::~OsxWindow()
{
    AutoreleasePool pool;

    if (m_actually_fullscreen) {
        exit_fullscreen();
    }

    [m_window->get() setDelegate:nil];
    [m_window->get() close];
}

#pragma region actions

void OsxWindow::show()
{
    AutoreleasePool pool;

    if (is_visible()) {
        return;
    }

    // Turn off on_resize callback to call it in order we want
    m_window->get().window_did_becomekey = nullptr;

    [m_window->get() center];
    [m_window->get() makeKeyAndOrderFront:m_window->get()];

    do {
        process_events();
    } while (!is_visible());

    if (m_actually_fullscreen) {
        m_actually_fullscreen = false; // Unset flag here
        enter_fullscreen();            // The enter_fullscreen method gonna set it again
    }

    // Turn on on_resize callback
    m_window->get().window_did_becomekey = std::bind(&OsxWindow::window_did_becomekey, this);

    // Explicitly call on_show callback
    on_show();

    // Explicitly call on_move callback
    on_move(position());

    // Explicitly call on_resize callback
    on_resize(size());

    // This would call on_focus callback
    if (!has_input_focus()) {
        [m_window->get() makeKeyWindow];
    } else {
        // Or call the on_focus callback explicitly
        on_focus();
    }
}

void OsxWindow::hide()
{
    AutoreleasePool pool;

    if (!is_visible() && !is_iconified()) {
        return;
    }

    if (m_actually_fullscreen) {
        exit_fullscreen();

        // Set flag again for a window to be in fullscreen if it would show again.
        m_actually_fullscreen = true;
    }

    if (has_input_focus()) {
        // This would focus other window and call on_lost_focus callback for this window
        if (!switch_to_other_window()) {
            // Or call the on_lost_focus callback explicitly
            on_lost_focus();
        }
    }

    [m_window->get() orderOut:m_window->get()];

    do {
        process_events();
    } while (is_visible());

    [m_window->get() close];

    // Explicitly call on_hide callback
    on_hide();
}

void OsxWindow::focus()
{
    AutoreleasePool pool;

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

    if (!is_visible() || is_iconified()) {
        return;
    }

    if (m_actually_fullscreen) {
        exit_fullscreen();

        // Set flag again for a window to be in fullscreen if it would show again.
        m_actually_fullscreen = true;
    }

    // Explicitly call the on_lost_focus callback
    on_lost_focus();

    [m_window->get() miniaturize:m_window->get()];
}

void OsxWindow::maximize()
{
    AutoreleasePool pool;

    if (is_maximized()) {
        return;
    }

    [m_window->get() zoom:m_window->get()];

    if (is_visible()) {
        // Explicitly call the on_move callback
        on_move(position());
    }
}

void OsxWindow::fullscreen()
{
    if (m_actually_fullscreen) {
        return;
    }

    if (!is_visible()) {
        m_actually_fullscreen = true;
        return;
    }

    enter_fullscreen();

    // Explicitly call on_move callback
    on_move(position());

    // Explicitly call on_resize callback
    on_resize(size());
}

void OsxWindow::restore()
{
    AutoreleasePool pool;

    if (!is_visible() && !is_iconified()) {
        m_actually_fullscreen = false;
        return;
    }

    bool restored = false;

    if (is_iconified()) {
        [m_window->get() deminiaturize:m_window->get()];
        m_actually_fullscreen = false;
        restored              = true;
    }

    if (is_maximized()) {
        [m_window->get() zoom:m_window->get()];
        restored = true;
    }

    if (is_fullscreen()) {
        exit_fullscreen();
        restored = true;
    }

    if (restored) {
        // Explicitly call on_move callback
        on_move(position());

        // Explicitly call on_resize callback
        on_resize(size());
    }
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
    AutoreleasePool pool;

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
    return m_actually_fullscreen;
}

bool OsxWindow::is_iconified() const
{
    AutoreleasePool pool;

    return [m_window->get() isMiniaturized];
}

bool OsxWindow::is_maximized() const
{
    AutoreleasePool pool;

    return !m_actually_fullscreen && [m_window->get() isZoomed];
}

bool OsxWindow::is_resizable() const
{
    return false;
}

bool OsxWindow::is_visible() const
{
    AutoreleasePool pool;

    return [m_window->get() isVisible];
}

bool OsxWindow::has_input_focus() const
{
    AutoreleasePool pool;

    return is_visible() && [m_window->get() isKeyWindow];
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
    if (is_visible()) {
        update_context();

        // if (_glfw.ns.disabledCursorWindow == window)
        //    _glfwCenterCursorInContentArea(window);

        on_resize(size());
    }
}

void OsxWindow::window_did_move()
{
    if (is_visible()) {
        update_context();

        // if (_glfw.ns.disabledCursorWindow == window)
        //    _glfwCenterCursorInContentArea(window);

        on_move(position());
    }
}

void OsxWindow::window_did_miniaturize()
{}

void OsxWindow::window_did_deminiaturize()
{
    update_context();
}

void OsxWindow::window_did_becomekey()
{
    if (is_visible()) {
        on_focus();
    }
}

void OsxWindow::window_did_resignkey()
{
    if (is_visible()) {
        on_lost_focus();
    }
}

void OsxWindow::window_did_enter_full_screen()
{
    m_actually_fullscreen = true;
    update_context();
}

void OsxWindow::window_did_exit_full_screen()
{
    m_actually_fullscreen = false;
    update_context();
}

#pragma endregion

void OsxWindow::enter_fullscreen()
{
    AutoreleasePool pool;

    if (m_actually_fullscreen) {
        return;
    }

    // Turn off the on_resize callback
    m_window->get().window_did_resize = nullptr;

    [m_window->get() toggleFullScreen:m_window->get()];

    do {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        process_events();
    } while (!m_actually_fullscreen);

    // Turn on the on_resize callback
    m_window->get().window_did_resize = std::bind(&OsxWindow::window_did_resize, this);
}

void OsxWindow::exit_fullscreen()
{
    AutoreleasePool pool;

    if (!m_actually_fullscreen) {
        return;
    }

    // Turn off the on_resize callback
    m_window->get().window_did_resize = nullptr;

    [m_window->get() toggleFullScreen:m_window->get()];

    do {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        process_events();
    } while (m_actually_fullscreen);

    // Turn on the on_resize callback
    m_window->get().window_did_resize = std::bind(&OsxWindow::window_did_resize, this);
}

bool OsxWindow::switch_to_other_window()
{
    AutoreleasePool pool;

    for (NSWindow* window in [NSApp orderedWindows]) {
        if (window != m_window->get() && [window isVisible]) {
            [window orderFront:nil];
            [window makeKeyWindow];
            return true;
        }
    }

    return false;
}

void OsxWindow::update_context()
{
    m_context->update();
}

} // namespace framework::system::details
