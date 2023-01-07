#include <dm3/windowDrivers/windowDelegate.h>
#include <dm3/core/logging.hpp>
#include <dm3/windowDrivers/windowDriver.hpp>
#include <dm3/events/windowEvent.hpp>
#include <dm3/events/keyEvents.hpp>

#ifdef USE_COCOA

@implementation WindowDelegate

- (id) init:(void*)t_windowData isRunning:(bool*)t_running{
    [super init];
    if (self) {
        [self setWindowData: t_windowData];
        [self setRunning:t_running];
    }
    return self;
}

- (BOOL) windowShouldClose:(NSWindow*)sender {
    *(_running) = false;
    dm3::windowClosedEvent e;
    dm3::windowDriver::driverData &data = *(dm3::windowDriver::driverData*)_windowData;
    data.m_eventFn(e);

    return YES;
}

- (void) keyDown:(NSEvent *)event {
    dm3::keyPressEvent e([event keyCode], 0);
    dm3::windowDriver::driverData &data = *(dm3::windowDriver::driverData*)_windowData;
    data.m_eventFn(e);
}

- (void) keyReleased:(NSEvent *)event {
    dm3::keyReleasedEvent e([event keyCode]);
    dm3::windowDriver::driverData &data = *(dm3::windowDriver::driverData*)_windowData;
    data.m_eventFn(e);
}

@end

#endif
