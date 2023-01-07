#include <dm3/core/logging.hpp>
#include <dm3/windowDrivers/windowDriverCocoa.hpp>

#ifdef USE_COCOA

#import <CoreFoundation/CoreFoundation.h>

namespace dm3 {

windowDriverCocoa::windowDriverCocoa() { DM3_INFO("creating Cocoa window driver"); }
windowDriverCocoa::~windowDriverCocoa() { DM3_INFO("deleting Cocoa window driver"); }

void windowDriverCocoa::createWindow(const int& t_width, const int& t_size, const std::string& t_title) {
    NSRect frame = NSMakeRect(100, 100, t_width, t_size);
    NSUInteger styleMake = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable; 

    m_window = [[NSWindow alloc] initWithContentRect: frame
            styleMask: styleMake
            backing: NSBackingStoreBuffered
            defer: NO];

    [m_window setTitle: [NSString stringWithUTF8String:t_title.c_str()]];
    
    WindowDelegate *delegate = [[[WindowDelegate alloc] init:&m_driverData isRunning: &m_running] autorelease];
    [m_window setDelegate:delegate];

    [m_window makeKeyAndOrderFront: nil];
}
void windowDriverCocoa::destroyWindow() {
    [m_window release];
}
void windowDriverCocoa::preRender() {
    CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.01, NO);
}
void windowDriverCocoa::postRender() {
    NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
        untilDate:[NSDate distantPast]
        inMode:NSEventTrackingRunLoopMode
        dequeue:YES
    ];
    if (event != nil) {
        [NSApp sendEvent:event];
    }
}
bool windowDriverCocoa::shouldCloseWindow() const {
    if (!m_running) {
        CFRunLoopStop(CFRunLoopGetCurrent());
        return true;
    }
    return false;
}
void windowDriverCocoa::setWindowSize(const glm::vec2& t_size) {}
void windowDriverCocoa::setWindowPos(const glm::vec2& t_pos) {}
void windowDriverCocoa::setWindowTitle(const std::string& t_title) {}
void windowDriverCocoa::setWindowIcon(const std::string& t_iconFile) {}
void windowDriverCocoa::setWindowSwapInterval(const int& t_swapInterval) {}
glm::vec2 windowDriverCocoa::getWindowSize() const { return {}; }
glm::vec2 windowDriverCocoa::getWindowPos() const { return {}; }
void windowDriverCocoa::minimizeWindow() {}
void windowDriverCocoa::maximizeWindow() {}
void windowDriverCocoa::restoreWindow() {}
void windowDriverCocoa::focusWindow() {}
int windowDriverCocoa::keyCodeToDM3(const int& t_keyCode) const { return t_keyCode; }
int windowDriverCocoa::mouseCodeToDM3(const int& t_mouseCode) const { return t_mouseCode; }

}

#endif
