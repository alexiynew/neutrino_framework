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
@property(retain, nonatomic) NSResponder* owner;
@property(retain, nonatomic) NSTrackingArea* tracking_area;

@end

@implementation OsxContentView

@synthesize update_context;
@synthesize owner;
@synthesize tracking_area;

- (instancetype)initWithOwner:(NSResponder*)owner
{
    self = [super init];
    if (self != nil)
    {
        self.owner = owner;
        self.update_context = nil;
        self.tracking_area = nil;
        [self updateTrackingAreas];
    }

    return self;
}

- (void)dealloc
{
   [tracking_area release];
   [super dealloc];
}

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

- (void)updateTrackingAreas
{
    if (self.tracking_area != nil) {
        [self removeTrackingArea:self.tracking_area];
        [self.tracking_area release];
    }

    const NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited | NSTrackingActiveInKeyWindow |
                                          NSTrackingEnabledDuringMouseDrag | NSTrackingCursorUpdate |
                                          NSTrackingInVisibleRect | NSTrackingAssumeInside;

    self.tracking_area = [[NSTrackingArea alloc] initWithRect:[self bounds] options:options owner:self.owner userInfo:nil];

    [self addTrackingArea:self.tracking_area];
    [super updateTrackingAreas];
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

@property(assign, nonatomic) std::function<void()> mouse_entered;
@property(assign, nonatomic) std::function<void()> mouse_exited;
@property(assign, nonatomic) std::function<void(framework::system::CursorPosition)> mouse_moved;
@property(assign, nonatomic) std::function<void()> cursor_update;

@property(assign, nonatomic) BOOL isFullscreen;

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

@synthesize mouse_entered;
@synthesize mouse_exited;
@synthesize mouse_moved;
@synthesize cursor_update;

@synthesize isFullscreen;

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

    [self setIsFullscreen:true];
}

- (void)windowDidExitFullScreen:(NSNotification*)notification
{
    if (self.window_did_exit_full_screen) {
        self.window_did_exit_full_screen();
    }

    [self setIsFullscreen:false];
}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification
{}

- (void)mouseEntered:(NSEvent*)event
{
    if (self.mouse_entered) {
        self.mouse_entered();
    }
}

- (void)mouseExited:(NSEvent*)event
{
    if (self.mouse_exited) {
        self.mouse_exited();
    }
}

- (void)mouseMoved:(NSEvent*)event
{
    if (self.mouse_moved) {
        NSPoint pos = [event locationInWindow];
        self.mouse_moved({static_cast<int>(pos.x), static_cast<int>(pos.y)});
    }
}

- (void)cursorUpdate:(NSEvent*)event
{
    // Override this method to set the cursor image.
}

- (BOOL)hasFullscreenStyle
{
    return (([self styleMask] & NSWindowStyleMaskFullScreen) != 0);
}

- (void)enterFullscreen
{
    if ([self hasFullscreenStyle]) {
        return;
    }

    const auto callback = [self window_did_resize];
    [self setWindow_did_resize:nil];

    [self toggleFullScreen:nil];

    [self setWindow_did_resize:callback];
}

- (void)exitFullscreen
{
    if (![self hasFullscreenStyle]) {
        return;
    }

    const auto callback = [self window_did_resize];
    [self setWindow_did_resize:nil];

    [self toggleFullScreen:nil];

    [self setWindow_did_resize:callback];
}

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
    using namespace std::placeholders;
    
    AutoreleasePool pool;

    if ([NSThread currentThread] != [NSThread mainThread]) {
        throw std::runtime_error("Cannot create a window from a non-main thread");
    }

    [OsxApplication setup];

    NSWindowStyleMask ns_style = NSWindowStyleMaskBorderless;
    // Title bar
    ns_style |= NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable;
    // Resize
    ns_style |= NSWindowStyleMaskResizable;
    // Close button
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

    m_window->get().mouse_entered = std::bind(&OsxWindow::mouse_entered, this);
    m_window->get().mouse_exited  = std::bind(&OsxWindow::mouse_exited, this);
    m_window->get().mouse_moved   = std::bind(&OsxWindow::mouse_moved, this, _1);

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
    m_view = std::make_unique<NSViewWrapper>([[OsxContentView alloc] initWithOwner:m_window->get()]);
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

    [m_window->get() setDelegate:nil];
    [m_window->get() close];
}

#pragma region actions

void OsxWindow::show()
{
    if (is_visible()) {
        return;
    }

    AutoreleasePool pool;

    // Turn off on_focus callback to call it in order we want
    m_window->get().window_did_becomekey = nullptr;

    [m_window->get() makeKeyAndOrderFront:m_window->get()];

    do {
        process_events();
    } while (!is_visible());

    if (m_state == Window::State::iconified) {
        m_state = Window::State::normal;
    } else {
        switch_state(m_state);
    }

    // Turn on on_focus callback
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
    if (!is_visible() && ![m_window->get() isMiniaturized]) {
        return;
    }

    AutoreleasePool pool;

    if (m_state == Window::State::fullscreen) {
        [m_window->get() exitFullscreen];
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
    } while (is_visible() && ![m_window->get() isMiniaturized]);

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

void OsxWindow::grab_cursor()
{
    m_cursor_grabbed = true;
    enable_raw_input();
}

void OsxWindow::release_cursor()
{
    m_cursor_grabbed = false;
    disable_raw_input();
}

void OsxWindow::process_events()
{
    AutoreleasePool pool;

    [OsxApplication process_events];
}

#pragma endregion

#pragma region setters

void OsxWindow::set_state(Window::State state)
{
    if (!is_visible()) {
        m_state = state;
        return;
    }

    const Window::State old_state = get_actual_state();

    if (state == old_state) {
        return;
    }

    // Turn off on_move and on resize callbacks
    m_window->get().window_did_resize = nullptr;
    m_window->get().window_did_move   = nullptr;

    switch_state(state);

    // Turn on on_move and on resize callbacks
    m_window->get().window_did_resize = std::bind(&OsxWindow::window_did_resize, this);
    m_window->get().window_did_move   = std::bind(&OsxWindow::window_did_move, this);

    if (state != Window::State::iconified) {
        on_move(position());
        on_resize(size());
    }
}

void OsxWindow::set_size(Size new_size)
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

void OsxWindow::set_position(Position position)
{
    AutoreleasePool pool;

    const NSRect rect  = [m_view->get() frame];
    const NSRect dummy = NSMakeRect(position.x, transform_y(position.y + rect.size.height - 1.0), 0.0, 0.0);
    const NSRect frame = [m_window->get() frameRectForContentRect:dummy];

    [m_window->get() setFrameOrigin:frame.origin];

    process_events();
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

void OsxWindow::set_cursor_visibility(bool visible)
{
    if (m_cursor_visible == visible) {
        return;
    }
    
    m_cursor_visible = visible;
    update_cursor_visibility();
}

#pragma endregion

#pragma region getters

bool OsxWindow::is_visible() const
{
    AutoreleasePool pool;

    // Miniaturized window is still visible
    return [m_window->get() isVisible] || [m_window->get() isMiniaturized];
}

bool OsxWindow::should_close() const
{
    return m_should_close;
}

bool OsxWindow::has_input_focus() const
{
    AutoreleasePool pool;

    return is_visible() && [m_window->get() isKeyWindow];
}

bool OsxWindow::is_cursor_grabbed() const
{
    return m_cursor_grabbed;
}

bool OsxWindow::is_cursor_visible() const
{
    return m_cursor_visible;
}

Window::State OsxWindow::state() const
{
    return m_state;
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

bool OsxWindow::is_resizable() const
{
    return false;
}

Position OsxWindow::position() const
{
    AutoreleasePool pool;

    Position position;

    const NSRect contentRect = [m_window->get() contentRectForFrameRect:[m_window->get() frame]];

    position.x = static_cast<int>(contentRect.origin.x);
    position.y = static_cast<int>(transform_y(contentRect.origin.y + contentRect.size.height - 1));

    return position;
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
        on_resize(size());
    }
}

void OsxWindow::window_did_move()
{
    if (is_visible()) {
        update_context();
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

        if (m_cursor_grabbed) {
            enable_raw_input();
        }
    }
}

void OsxWindow::window_did_resignkey()
{
    if (is_visible()) {
        on_lost_focus();

        if (!m_cursor_grabbed) {
            disable_raw_input();
        }
    }
}

void OsxWindow::window_did_enter_full_screen()
{
    update_context();
}

void OsxWindow::window_did_exit_full_screen()
{
    update_context();
}

void OsxWindow::mouse_entered()
{
    m_mouse_hover = true;
    on_mouse_enter();
}

void OsxWindow::mouse_exited()
{
    on_mouse_leave();
    m_mouse_hover = false;
}

void OsxWindow::mouse_moved(CursorPosition cursor_position)
{
    AutoreleasePool pool;
    
    if (m_cursor_grabbed) {
        int dx = 0;
        int dy = 0;
        CGGetLastMouseDelta(&dx, &dy);
        on_mouse_move({dx,dy});
        center_cursor_inside_window();
    } else if (m_mouse_hover) {
        const NSRect contentRect = [m_view->get() frame];
        on_mouse_move({cursor_position.x + 1, static_cast<int>(contentRect.size.height - cursor_position.y)});
    }
    
    update_cursor_visibility();
}

#pragma endregion

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

void OsxWindow::switch_state(Window::State state)
{
    const Window::State old_state = get_actual_state();

    if (state == old_state) {
        return;
    }

    AutoreleasePool pool;

    // Drop fullscreen state
    if (old_state == Window::State::fullscreen) {
        [m_window->get() exitFullscreen];

        do {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            process_events();
        } while ([m_window->get() isFullscreen]);

        const Window::State after_fullscreen_state = get_actual_state();
        if (state == after_fullscreen_state) {
            m_state = after_fullscreen_state;
            return;
        }
    }

    // Switch to new state
    switch (state) {
        case Window::State::iconified: [m_window->get() miniaturize:m_window->get()]; break;
        case Window::State::maximized:
            if (old_state == Window::State::iconified) {
                [m_window->get() deminiaturize:m_window->get()];
            } else {
                [m_window->get() zoom:m_window->get()];
            }
            break;
        case Window::State::fullscreen:
            [m_window->get() enterFullscreen];

            do {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                process_events();
            } while (![m_window->get() isFullscreen]);
            break;
        case Window::State::normal:
            if (old_state == Window::State::iconified) {
                [m_window->get() deminiaturize:m_window->get()];
            } else if (old_state == Window::State::maximized) {
                [m_window->get() zoom:m_window->get()];
            }
            break;
    }

    m_state = get_actual_state();
}

Window::State OsxWindow::get_actual_state() const
{
    if ([m_window->get() isFullscreen]) {
        return Window::State::fullscreen;
    } else if ([m_window->get() isMiniaturized]) {
        return Window::State::iconified;
    } else if ([m_window->get() isZoomed]) {
        return Window::State::maximized;
    } else {
        return Window::State::normal;
    }
}

void OsxWindow::center_cursor_inside_window()
{
    AutoreleasePool pool;
    
    if (m_cursor_grabbed) {
        const auto p = position();
        const auto s = size();
        CGPoint point{p.x + s.width / 2.0f, p.y + s.height / 2.0f};
        CGWarpMouseCursorPosition(point);
    }
}

void OsxWindow::update_cursor_visibility()
{
    if (m_mouse_hover) {
        if (m_cursor_visible) {
            show_cursor();
        } else {
            hide_cursor();
        }
    } else {
        show_cursor();
    }
}

void OsxWindow::show_cursor()
{
    if (m_cursor_actualy_visible) {
        return;
    }
    
    AutoreleasePool pool;

    m_cursor_actualy_visible = true;
    [NSCursor unhide];
}

void OsxWindow::hide_cursor()
{
    if (!m_cursor_actualy_visible) {
        return;
    }
    
    AutoreleasePool pool;

    m_cursor_actualy_visible = false;
    [NSCursor hide];
}

void OsxWindow::enable_raw_input()
{
    AutoreleasePool pool;

    m_grabbed_cursor_diff = {0, 0};

    NSPoint pos = [m_window->get() mouseLocationOutsideOfEventStream];
    m_cursor_position.x = pos.x;
    m_cursor_position.y = pos.y;

    center_cursor_inside_window();
    mouse_moved(m_grabbed_cursor_diff);

    CGAssociateMouseAndMouseCursorPosition(YES);
}

void OsxWindow::disable_raw_input()
{
    AutoreleasePool pool;

    // restore cursor previous position
    CGPoint point;
    point.x = m_cursor_position.x;
    point.y = m_cursor_position.y;
    CGWarpMouseCursorPosition(point);

    CGAssociateMouseAndMouseCursorPosition(NO);
}

} // namespace framework::system::details
