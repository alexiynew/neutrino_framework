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
