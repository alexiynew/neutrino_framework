#include <chrono>
#include <cmath>
#include <functional>
#include <limits>
#include <map>
#include <thread>

#include <common/utf.hpp>

#include <system/src/osx/osx_application.hpp>
#include <system/src/osx/osx_autorelease_pool.hpp>
#include <system/src/osx/osx_context.hpp>
#include <system/src/osx/osx_keyboard.hpp>
#include <system/src/osx/osx_window.hpp>

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

#pragma region OsxContentView

using framework::system::CursorPosition;
using framework::system::KeyCode;
using framework::system::Modifiers;
using framework::system::MouseButton;
using framework::system::ScrollOffset;

@interface OsxContentView : NSView<NSTextInputClient>
{
    std::function<void()> onUpdateContext;

    std::function<void(KeyCode, Modifiers)> onKeyDown;
    std::function<void(KeyCode, Modifiers)> onKeyUp;
    std::function<void(const std::string&)> onCharacter;

    std::function<void()> onMouseEntered;
    std::function<void()> onMouseExited;
    std::function<void(CursorPosition)> onMouseMoved;
    std::function<void(MouseButton, CursorPosition, Modifiers)> onMouseButtonDown;
    std::function<void(MouseButton, CursorPosition, Modifiers)> onMouseButtonUp;
    std::function<void(ScrollOffset)> onMouseScroll;

    NSTrackingArea* trackingArea;

    std::map<framework::system::KeyCode, bool> pressedModifierKeys;
}

@property(assign, nonatomic) std::function<void()> on_update_context;

@property(assign, nonatomic) std::function<void(KeyCode, Modifiers)> on_key_down;
@property(assign, nonatomic) std::function<void(KeyCode, Modifiers)> on_key_up;
@property(assign, nonatomic) std::function<void(const std::string&)> on_character;

@property(assign, nonatomic) std::function<void()> on_mouse_entered;
@property(assign, nonatomic) std::function<void()> on_mouse_exited;
@property(assign, nonatomic) std::function<void(CursorPosition)> on_mouse_moved;
@property(assign, nonatomic) std::function<void(MouseButton, CursorPosition, Modifiers)> on_mouse_button_down;
@property(assign, nonatomic) std::function<void(MouseButton, CursorPosition, Modifiers)> on_mouse_button_up;
@property(assign, nonatomic) std::function<void(ScrollOffset)> on_mouse_scroll;

@end

@implementation OsxContentView

@synthesize on_update_context = onUpdateContext;

@synthesize on_key_down  = onKeyDown;
@synthesize on_key_up    = onKeyUp;
@synthesize on_character = onCharacter;

@synthesize on_mouse_entered     = onMouseEntered;
@synthesize on_mouse_exited      = onMouseExited;
@synthesize on_mouse_moved       = onMouseMoved;
@synthesize on_mouse_button_down = onMouseButtonDown;
@synthesize on_mouse_button_up   = onMouseButtonUp;
@synthesize on_mouse_scroll      = onMouseScroll;

- (instancetype)init
{
    self = [super init];
    if (self != nil) {
        trackingArea = nullptr;
        [self updateTrackingAreas];
    }

    return self;
}

- (void)dealloc
{
    [trackingArea release];
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
    if (onUpdateContext) {
        onUpdateContext();
    }
}

- (BOOL)acceptsFirstMouse:(NSEvent*)event
{
    return YES;
}

- (void)updateTrackingAreas
{
    if (trackingArea != nil) {
        [self removeTrackingArea:trackingArea];
        [trackingArea release];
    }

    const NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited | NSTrackingActiveInKeyWindow |
                                          NSTrackingEnabledDuringMouseDrag | NSTrackingCursorUpdate |
                                          NSTrackingInVisibleRect | NSTrackingAssumeInside;

    trackingArea = [[NSTrackingArea alloc] initWithRect:[self bounds] options:options owner:self userInfo:nil];

    [self addTrackingArea:trackingArea];
    [super updateTrackingAreas];
}

// Keyboard events handling
- (void)keyDown:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onKeyDown) {
        const auto key   = map_system_key([event keyCode]);
        const auto state = get_modifiers_state([event modifierFlags]);
        onKeyDown(key, state);
    }
    [self interpretKeyEvents:[NSArray arrayWithObject:event]];
}

- (void)keyUp:(NSEvent*)event
{
    using namespace framework::system::details;
    if (onKeyUp) {
        const auto key   = map_system_key([event keyCode]);
        const auto state = get_modifiers_state([event modifierFlags]);
        onKeyUp(key, state);
    }
}

- (void)flagsChanged:(NSEvent*)event
{
    using namespace framework::system::details;

    const auto key   = map_system_key([event keyCode]);
    const auto state = get_modifiers_state([event modifierFlags]);

    const bool was_pressed = pressedModifierKeys[key];

    if (was_pressed) {
        if (onKeyUp) {
            onKeyUp(key, state);
            pressedModifierKeys[key] = false;
        }
    } else {
        if (onKeyDown) {
            onKeyDown(key, state);
            pressedModifierKeys[key] = true;
        }
    }
}

// Input text handling required by <NSTextInputClient>
- (void)insertText:(id)string replacementRange:(NSRange)replacementRange
{
    NSString* characters;

    if ([string isKindOfClass:[NSAttributedString class]])
        characters = [string string];
    else
        characters = (NSString*)string;

    onCharacter([characters UTF8String]);
}

- (void)doCommandBySelector:(SEL)selector
{}

- (void)setMarkedText:(id)string selectedRange:(NSRange)selectedRange replacementRange:(NSRange)replacementRange
{}

- (void)unmarkText
{}

- (NSRange)selectedRange
{
    return {NSNotFound, 0};
}

- (NSRange)markedRange
{
    return {NSNotFound, 0};
}

- (BOOL)hasMarkedText
{
    return false;
}

- (nullable NSAttributedString*)attributedSubstringForProposedRange:(NSRange)range
                                                        actualRange:(nullable NSRangePointer)actualRange
{
    return nil;
}

- (NSArray<NSAttributedStringKey>*)validAttributesForMarkedText
{
    return [NSArray array];
}

- (NSRect)firstRectForCharacterRange:(NSRange)range actualRange:(nullable NSRangePointer)actualRange
{
    const NSRect frame = [self frame];
    return NSMakeRect(frame.origin.x, frame.origin.y, 0.0, 0.0);
}

- (NSUInteger)characterIndexForPoint:(NSPoint)point
{
    return 0;
}

// Mouse events handling
- (void)mouseEntered:(NSEvent*)event
{
    if (onMouseEntered) {
        onMouseEntered();
    }
}

- (void)mouseExited:(NSEvent*)event
{
    if (onMouseExited) {
        onMouseExited();
    }
}

- (void)mouseMoved:(NSEvent*)event
{
    if (onMouseMoved) {
        const NSPoint pos = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        onMouseMoved(cursor_position);
    }
}

- (void)mouseDragged:(NSEvent*)event
{
    [self mouseMoved:event];
}

- (void)rightMouseDragged:(NSEvent*)event
{
    [self mouseMoved:event];
}

- (void)otherMouseDragged:(NSEvent*)event
{
    [self mouseMoved:event];
}

- (void)mouseDown:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onMouseButtonDown) {
        const NSPoint pos = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        const auto state = get_modifiers_state([event modifierFlags]);
        onMouseButtonDown(MouseButton::button_left, cursor_position, state);
    }
}

- (void)rightMouseDown:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onMouseButtonDown) {
        const NSPoint pos = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        const auto state = get_modifiers_state([event modifierFlags]);
        onMouseButtonDown(MouseButton::button_right, cursor_position, state);
    }
}

- (void)otherMouseDown:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onMouseButtonDown) {
        const MouseButton button = static_cast<MouseButton>([event buttonNumber]);
        const NSPoint pos        = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        const auto state = get_modifiers_state([event modifierFlags]);
        onMouseButtonDown(button, cursor_position, state);
    }
}

- (void)mouseUp:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onMouseButtonUp) {
        const NSPoint pos = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        const auto state = get_modifiers_state([event modifierFlags]);
        onMouseButtonUp(MouseButton::button_left, cursor_position, state);
    }
}

- (void)rightMouseUp:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onMouseButtonUp) {
        const NSPoint pos = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        const auto state = get_modifiers_state([event modifierFlags]);
        onMouseButtonUp(MouseButton::button_right, cursor_position, state);
    }
}

- (void)otherMouseUp:(NSEvent*)event
{
    using namespace framework::system::details;

    if (onMouseButtonUp) {
        const MouseButton button = static_cast<MouseButton>([event buttonNumber]);
        const NSPoint pos        = [event locationInWindow];
        const CursorPosition cursor_position{static_cast<int>(pos.x), static_cast<int>(pos.y)};
        const auto state = get_modifiers_state([event modifierFlags]);
        onMouseButtonUp(button, cursor_position, state);
    }
}

- (void)scrollWheel:(NSEvent*)event
{
    float dx = [event scrollingDeltaX];
    float dy = [event scrollingDeltaY];

    if ([event hasPreciseScrollingDeltas]) {
        dx *= 0.1;
        dy *= 0.1;
    }

    if (fabs(dx) > 0 && fabs(dy) > 0) {
        onMouseScroll(ScrollOffset(dx * 120, dy * 120));
    }
}

- (void)cursorUpdate:(NSEvent*)event
{
    // Override this method to set the cursor image.
}

@end // OsxContentView

#pragma endregion

#pragma region OsxWindowInternal

@interface OsxWindowInternal : NSWindow<NSWindowDelegate>
{
    std::function<void()> onWindowShouldClose;
    std::function<void()> onWindowDidResize;
    std::function<void()> onWindowDidMove;
    std::function<void()> onWindowDidMiniaturize;
    std::function<void()> onWindowDidDeminiaturize;
    std::function<void()> onWindowDidBecomekey;
    std::function<void()> onWindowDidResignkey;
    std::function<void()> onWindowDidEnterFullScreen;
    std::function<void()> onWindowDidExitFullScreen;
}

@property(assign, nonatomic) std::function<void()> on_window_should_close;
@property(assign, nonatomic) std::function<void()> on_window_did_resize;
@property(assign, nonatomic) std::function<void()> on_window_did_move;
@property(assign, nonatomic) std::function<void()> on_window_did_miniaturize;
@property(assign, nonatomic) std::function<void()> on_window_did_deminiaturize;
@property(assign, nonatomic) std::function<void()> on_window_did_become_key;
@property(assign, nonatomic) std::function<void()> on_window_did_resign_key;
@property(assign, nonatomic) std::function<void()> on_window_did_enter_full_screen;
@property(assign, nonatomic) std::function<void()> on_window_did_exit_full_screen;

@property(readonly, assign, nonatomic) BOOL isFullscreen;

@end

@implementation OsxWindowInternal

@synthesize on_window_should_close          = onWindowShouldClose;
@synthesize on_window_did_resize            = onWindowDidResize;
@synthesize on_window_did_move              = onWindowDidMove;
@synthesize on_window_did_miniaturize       = onWindowDidMiniaturize;
@synthesize on_window_did_deminiaturize     = onWindowDidDeminiaturize;
@synthesize on_window_did_become_key        = onWindowDidBecomeKey;
@synthesize on_window_did_resign_key        = onWindowDidResignKey;
@synthesize on_window_did_enter_full_screen = onWindowDidEnterFullScreen;
@synthesize on_window_did_exit_full_screen  = onWindowDidExitFullScreen;

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
    if (onWindowShouldClose) {
        onWindowShouldClose();
    }
    return NO;
}

- (void)windowDidResize:(NSNotification*)notification
{
    if (onWindowDidResize) {
        onWindowDidResize();
    }
}

- (void)windowDidMove:(NSNotification*)notification
{
    if (onWindowDidMove) {
        onWindowDidMove();
    }
}

- (void)windowDidMiniaturize:(NSNotification*)notification
{
    if (onWindowDidMiniaturize) {
        onWindowDidMiniaturize();
    }
}

- (void)windowDidDeminiaturize:(NSNotification*)notification
{
    if (onWindowDidDeminiaturize) {
        onWindowDidDeminiaturize();
    }
}

- (void)windowDidBecomeKey:(NSNotification*)notification
{
    if (onWindowDidBecomeKey) {
        onWindowDidBecomeKey();
    }
}

- (void)windowDidResignKey:(NSNotification*)notification
{
    if (onWindowDidResignKey) {
        onWindowDidResignKey();
    }
}

- (void)windowDidEnterFullScreen:(NSNotification*)notification
{
    if (onWindowDidEnterFullScreen) {
        onWindowDidEnterFullScreen();
    }

    isFullscreen = true;
}

- (void)windowDidExitFullScreen:(NSNotification*)notification
{
    if (onWindowDidExitFullScreen) {
        onWindowDidExitFullScreen();
    }

    isFullscreen = false;
}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification
{}

- (BOOL)hasFullscreenStyle
{
    return (([self styleMask] & NSWindowStyleMaskFullScreen) != 0);
}

- (void)enterFullscreen
{
    if ([self hasFullscreenStyle]) {
        return;
    }

    const auto callback = onWindowDidResize;
    onWindowDidResize   = nullptr;

    [self toggleFullScreen:nil];

    onWindowDidResize = callback;
}

- (void)exitFullscreen
{
    if (![self hasFullscreenStyle]) {
        return;
    }

    const auto callback = onWindowDidResize;
    onWindowDidResize   = nullptr;

    [self toggleFullScreen:nil];

    onWindowDidResize = callback;
}

- (BOOL)hasResizableStyle
{
    return (([self styleMask] & NSWindowStyleMaskResizable) != 0);
}

- (void)setResizable:(BOOL)value
{
    if (value) {
        self.styleMask |= NSWindowStyleMaskResizable;
    } else {
        self.styleMask &= ~NSWindowStyleMaskResizable;
    }
}

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
        AutoreleasePool pool;

        [m_value autorelease];
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
    m_window->get().on_window_should_close          = std::bind(&OsxWindow::window_should_close, this);
    m_window->get().on_window_did_resize            = std::bind(&OsxWindow::window_did_resize, this);
    m_window->get().on_window_did_move              = std::bind(&OsxWindow::window_did_move, this);
    m_window->get().on_window_did_miniaturize       = std::bind(&OsxWindow::window_did_miniaturize, this);
    m_window->get().on_window_did_deminiaturize     = std::bind(&OsxWindow::window_did_deminiaturize, this);
    m_window->get().on_window_did_become_key        = std::bind(&OsxWindow::window_did_become_key, this);
    m_window->get().on_window_did_resign_key        = std::bind(&OsxWindow::window_did_resign_key, this);
    m_window->get().on_window_did_enter_full_screen = std::bind(&OsxWindow::window_did_enter_full_screen, this);
    m_window->get().on_window_did_exit_full_screen  = std::bind(&OsxWindow::window_did_exit_full_screen, this);

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
    m_view = std::make_unique<NSViewWrapper>([[OsxContentView alloc] init]);
    if (!m_view) {
        throw std::runtime_error("Can't create NSView");
    }

    [m_view->get() setWantsLayer:YES];
    [[m_view->get() layer] setContentsScale:[m_window->get() backingScaleFactor]];

    // Setup view callbacks
    m_view->get().on_update_context = std::bind(&OsxWindow::update_context, this);

    m_view->get().on_key_down = std::bind(&OsxWindow::key_down, this, _1, _2);
    m_view->get().on_key_up   = std::bind(&OsxWindow::key_up, this, _1, _2);

    // bind the PlatformWindow::on_character callback directly
    m_view->get().on_character = std::bind(&OsxWindow::on_character, this, _1);

    m_view->get().on_mouse_entered     = std::bind(&OsxWindow::mouse_entered, this);
    m_view->get().on_mouse_exited      = std::bind(&OsxWindow::mouse_exited, this);
    m_view->get().on_mouse_moved       = std::bind(&OsxWindow::mouse_moved, this, _1);
    m_view->get().on_mouse_button_down = std::bind(&OsxWindow::mouse_button_down, this, _1, _2, _3);
    m_view->get().on_mouse_button_up   = std::bind(&OsxWindow::mouse_button_up, this, _1, _2, _3);
    m_view->get().on_mouse_scroll      = std::bind(&OsxWindow::mouse_scroll, this, _1);

    [m_window->get() setContentView:m_view->get()];
    [m_window->get() makeFirstResponder:m_view->get()];

    // Create context
    m_context = std::make_unique<OsxContext>(m_view->get(), context_settings);
}

OsxWindow::~OsxWindow()
{
    AutoreleasePool pool;

    [m_window->get() setDelegate:nil];
    [m_window->get() setContentView:nil];
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
    m_window->get().on_window_did_become_key = nullptr;

    if (!m_position_was_set_before_show) {
        [m_window->get() cascadeTopLeftFromPoint:NSMakePoint(20, 20)];
    }
    [m_window->get() makeKeyAndOrderFront:m_window->get()];

    m_position_was_set_before_show = false;

    do {
        process_events();
    } while (!is_visible());

    if (m_state == Window::State::iconified) {
        m_state = Window::State::normal;
    } else {
        switch_state(m_state);
    }

    if (m_cursor_grabbed) {
        enable_raw_input();
    }

    // Turn on on_focus callback
    m_window->get().on_window_did_become_key = std::bind(&OsxWindow::window_did_become_key, this);

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

        if (m_cursor_grabbed) {
            disable_raw_input();
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
    m_window->get().on_window_did_resize = nullptr;
    m_window->get().on_window_did_move   = nullptr;

    switch_state(state);

    // Turn on on_move and on resize callbacks
    m_window->get().on_window_did_resize = std::bind(&OsxWindow::window_did_resize, this);
    m_window->get().on_window_did_move   = std::bind(&OsxWindow::window_did_move, this);

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

void OsxWindow::set_resizable(bool value)
{
    AutoreleasePool pool;

    [m_window->get() setResizable:value];
}

void OsxWindow::set_position(Position position)
{
    AutoreleasePool pool;

    const NSRect rect  = [m_view->get() frame];
    const NSRect dummy = NSMakeRect(position.x, transform_y(position.y + rect.size.height - 1.0), 0.0, 0.0);
    const NSRect frame = [m_window->get() frameRectForContentRect:dummy];

    [m_window->get() setFrameOrigin:frame.origin];

    if (!is_visible()) {
        m_position_was_set_before_show = true;
    }

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
    return [m_window->get() hasResizableStyle];
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

void OsxWindow::window_did_become_key()
{
    if (is_visible()) {
        on_focus();

        if (m_cursor_grabbed) {
            enable_raw_input();
        }
    }
}

void OsxWindow::window_did_resign_key()
{
    if (is_visible()) {
        on_lost_focus();

        if (m_cursor_grabbed) {
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

void OsxWindow::key_down(KeyCode key, Modifiers state)
{
    on_key_down(key, state);
}

void OsxWindow::key_up(KeyCode key, Modifiers state)
{
    on_key_up(key, state);
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
        on_mouse_move({dx, dy});
        center_cursor_inside_window();
    } else if (m_mouse_hover) {
        on_mouse_move(convert_cursor_position(cursor_position));
    }

    update_cursor_visibility();
}

void OsxWindow::mouse_button_down(MouseButton button, CursorPosition position, Modifiers state)
{
    on_mouse_button_down(button, convert_cursor_position(position), state);
}

void OsxWindow::mouse_button_up(MouseButton button, CursorPosition position, Modifiers state)
{
    on_mouse_button_up(button, convert_cursor_position(position), state);
}

void OsxWindow::mouse_scroll(ScrollOffset scroll)
{
    on_mouse_scroll(scroll);
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

    const NSPoint pos = [m_window->get() mouseLocationOutsideOfEventStream];
    const auto p      = position();
    const auto s      = size();
    m_cursor_position = CursorPosition(pos.x + p.x, (p.y + s.height) - pos.y);

    center_cursor_inside_window();
    mouse_moved(m_grabbed_cursor_diff);

    if (!m_mouse_hover) {
        m_mouse_hover = true;
        on_mouse_enter();
    }

    CGAssociateMouseAndMouseCursorPosition(NO);

    process_events();
}

void OsxWindow::disable_raw_input()
{
    AutoreleasePool pool;

    // restore cursor previous position
    CGPoint point;
    point.x = m_cursor_position.x;
    point.y = m_cursor_position.y;
    CGWarpMouseCursorPosition(point);

    CGAssociateMouseAndMouseCursorPosition(YES);

    process_events();
}

CursorPosition OsxWindow::convert_cursor_position(CursorPosition position)
{
    const NSRect contentRect = [m_view->get() frame];
    return {position.x + 1, static_cast<int>(contentRect.size.height - position.y)};
}

} // namespace framework::system::details
