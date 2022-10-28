#ifndef SYSTEM_SRC_OSX_OSX_APPLICATION_HPP
#define SYSTEM_SRC_OSX_OSX_APPLICATION_HPP

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

@interface OsxApplication : NSApplication<NSApplicationDelegate>

+ (void)setup;
+ (void)setup_menu_bar;

+ (void)process_events;

- (void)sendEvent:(NSEvent*)event;

#pragma region NSApplicationDelegate

// React to a termination notification
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)app;
// Do not exit the app when all windows are closed
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)app;
- (void)applicationDidChangeScreenParameters:(NSNotification*)notification;
- (void)applicationWillFinishLaunching:(NSNotification*)notification;
- (void)applicationDidFinishLaunching:(NSNotification*)notification;

#pragma endregion

@end

#endif
